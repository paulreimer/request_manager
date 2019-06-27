if(CONFIG_AWS_IOT_SDK)
  function(MQTT_EMBED_CLIENT_CONFIG mqtt_client_config)
    set(GENERATED_OUTPUTS)

    configure_file(
      "templates/${mqtt_client_config}.mqtt.json.tpl"
      "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.json"
      @ONLY
    )
    set_source_files_properties(
      "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.json"
      PROPERTIES
      GENERATED TRUE
    )
    add_custom_target(
      ${mqtt_client_config}_JSON_TARGET
      DEPENDS
        "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.json"
    )
    list(
      APPEND GENERATED_OUTPUTS
        "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.json"
    )

    add_custom_command(
      OUTPUT "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.fb"
      COMMAND flatc --binary
        -o "secrets/gen"
        --root-type MQTT.MQTTClientConfiguration
        -I "${IDF_PROJECT_PATH}/esp32-network-lib/uuid"
        "${IDF_PROJECT_PATH}/esp32-network-lib/mqtt_client/mqtt.fbs"
        --force-defaults
        "secrets/gen/${mqtt_client_config}.mqtt.json"
      DEPENDS
        ${mqtt_client_config}_JSON_TARGET
        "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.json"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      VERBATIM
    )
    set_source_files_properties(
      "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.fb"
      PROPERTIES
      GENERATED TRUE
    )
    add_custom_target(
      ${mqtt_client_config}_FB_TARGET
      DEPENDS "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.fb"
    )
    list(
      APPEND GENERATED_OUTPUTS
        "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.fb"
    )

    add_custom_command(
      OUTPUT "${PROJECT_BINARY_DIR}/fs/${mqtt_client_config}.mqtt.fb"
      COMMAND
        cp
          "secrets/gen/${mqtt_client_config}.mqtt.fb"
          "fs/${mqtt_client_config}.mqtt.fb"
      DEPENDS
        ${mqtt_client_config}_FB_TARGET
        "${PROJECT_BINARY_DIR}/secrets/gen/${mqtt_client_config}.mqtt.fb"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      VERBATIM
    )
    set_source_files_properties(
      "${PROJECT_BINARY_DIR}/fs/${mqtt_client_config}.mqtt.fb"
      PROPERTIES
      GENERATED TRUE
    )
    list(
      APPEND GENERATED_OUTPUTS
        "${PROJECT_BINARY_DIR}/fs/${mqtt_client_config}.mqtt.fb"
    )

    set(${mqtt_client_config}_OUTPUTS ${GENERATED_OUTPUTS} PARENT_SCOPE)
    add_custom_target(${mqtt_client_config}_TARGET DEPENDS ${GENERATED_OUTPUTS})
  endfunction()

  function(MQTT_EMBED_MQTT_CERTIFICATE mqtt_cert)
    set(GENERATED_OUTPUTS)
    add_custom_command(
      OUTPUT "${PROJECT_BINARY_DIR}/fs/${mqtt_cert}.pem"
      COMMAND sh -c "\
        cp \"secrets/${mqtt_cert}.pem\" \"fs/${mqtt_cert}.pem\" \
        && truncate -s +1 \"fs/${mqtt_cert}.pem\""
      DEPENDS "secrets/${mqtt_cert}.pem"
      WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
      VERBATIM
    )
    set_source_files_properties(
      "${PROJECT_BINARY_DIR}/fs/${mqtt_cert}.pem"
      PROPERTIES
      GENERATED TRUE
    )
    list(APPEND GENERATED_OUTPUTS "${PROJECT_BINARY_DIR}/fs/${mqtt_cert}.pem")

    set_property(
      DIRECTORY "${PROJECT_BINARY_DIR}"
      APPEND PROPERTY
      ADDITIONAL_MAKE_CLEAN_FILES "${GENERATED_OUTPUTS}"
    )

    set(${mqtt_cert}_OUTPUTS ${GENERATED_OUTPUTS} PARENT_SCOPE)
    add_custom_target(${mqtt_cert}_TARGET DEPENDS ${GENERATED_OUTPUTS})
  endfunction()
endif(CONFIG_AWS_IOT_SDK)
