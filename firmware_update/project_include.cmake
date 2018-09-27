execute_process(
  COMMAND cat "${PROJECT_PATH}/VERSION"
  OUTPUT_VARIABLE VERSION_FILE_CONTENTS
)

string(STRIP "${VERSION_FILE_CONTENTS}" FIRMWARE_UPDATE_CURRENT_VERSION)

add_definitions(
  -DFIRMWARE_UPDATE_ACTOR_TASK_STACK_SIZE=4096
  -DFIRMWARE_UPDATE_ACTOR_MAILBOX_SIZE=8192
  -DFIRMWARE_UPDATE_CURRENT_VERSION=${FIRMWARE_UPDATE_CURRENT_VERSION}
)