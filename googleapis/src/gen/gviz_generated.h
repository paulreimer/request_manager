// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GVIZ_GVIZ_H_
#define FLATBUFFERS_GENERATED_GVIZ_GVIZ_H_

#include "flatbuffers/flatbuffers.h"

namespace GViz {

struct DatatableCell;

struct DatatableRow;

struct DatatableColumn;

struct Datatable;

struct DatatableResponse;

struct WhereClause;

struct Query;

inline const flatbuffers::TypeTable *DatatableCellTypeTable();

inline const flatbuffers::TypeTable *DatatableRowTypeTable();

inline const flatbuffers::TypeTable *DatatableColumnTypeTable();

inline const flatbuffers::TypeTable *DatatableTypeTable();

inline const flatbuffers::TypeTable *DatatableResponseTypeTable();

inline const flatbuffers::TypeTable *WhereClauseTypeTable();

inline const flatbuffers::TypeTable *QueryTypeTable();

enum class DatatableColumnType : int8_t {
  boolean = 0,
  number = 1,
  string = 2,
  date = 3,
  datetime = 4,
  timeofday = 5,
  unknown = 6,
  MIN = boolean,
  MAX = unknown
};

inline const DatatableColumnType (&EnumValuesDatatableColumnType())[7] {
  static const DatatableColumnType values[] = {
    DatatableColumnType::boolean,
    DatatableColumnType::number,
    DatatableColumnType::string,
    DatatableColumnType::date,
    DatatableColumnType::datetime,
    DatatableColumnType::timeofday,
    DatatableColumnType::unknown
  };
  return values;
}

inline const char * const *EnumNamesDatatableColumnType() {
  static const char * const names[] = {
    "boolean",
    "number",
    "string",
    "date",
    "datetime",
    "timeofday",
    "unknown",
    nullptr
  };
  return names;
}

inline const char *EnumNameDatatableColumnType(DatatableColumnType e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesDatatableColumnType()[index];
}

enum class QueryOption : int8_t {
  defaults = 0,
  no_format = 1,
  no_values = 2,
  MIN = defaults,
  MAX = no_values
};

inline const QueryOption (&EnumValuesQueryOption())[3] {
  static const QueryOption values[] = {
    QueryOption::defaults,
    QueryOption::no_format,
    QueryOption::no_values
  };
  return values;
}

inline const char * const *EnumNamesQueryOption() {
  static const char * const names[] = {
    "defaults",
    "no_format",
    "no_values",
    nullptr
  };
  return names;
}

inline const char *EnumNameQueryOption(QueryOption e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesQueryOption()[index];
}

enum class WhereClauseOp : int8_t {
  Equals = 0,
  NotEquals = 1,
  GreaterThan = 2,
  GreaterThanOrEqualTo = 3,
  LessThan = 4,
  LessThanOrEqualTo = 5,
  IsNull = 6,
  IsNotNull = 7,
  Contains = 8,
  StartsWith = 9,
  EndsWith = 10,
  Matches = 11,
  Like = 12,
  MIN = Equals,
  MAX = Like
};

inline const WhereClauseOp (&EnumValuesWhereClauseOp())[13] {
  static const WhereClauseOp values[] = {
    WhereClauseOp::Equals,
    WhereClauseOp::NotEquals,
    WhereClauseOp::GreaterThan,
    WhereClauseOp::GreaterThanOrEqualTo,
    WhereClauseOp::LessThan,
    WhereClauseOp::LessThanOrEqualTo,
    WhereClauseOp::IsNull,
    WhereClauseOp::IsNotNull,
    WhereClauseOp::Contains,
    WhereClauseOp::StartsWith,
    WhereClauseOp::EndsWith,
    WhereClauseOp::Matches,
    WhereClauseOp::Like
  };
  return values;
}

inline const char * const *EnumNamesWhereClauseOp() {
  static const char * const names[] = {
    "Equals",
    "NotEquals",
    "GreaterThan",
    "GreaterThanOrEqualTo",
    "LessThan",
    "LessThanOrEqualTo",
    "IsNull",
    "IsNotNull",
    "Contains",
    "StartsWith",
    "EndsWith",
    "Matches",
    "Like",
    nullptr
  };
  return names;
}

inline const char *EnumNameWhereClauseOp(WhereClauseOp e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesWhereClauseOp()[index];
}

enum class WhereClauseJoinOp : int8_t {
  And = 0,
  Or = 1,
  Not = 2,
  MIN = And,
  MAX = Not
};

inline const WhereClauseJoinOp (&EnumValuesWhereClauseJoinOp())[3] {
  static const WhereClauseJoinOp values[] = {
    WhereClauseJoinOp::And,
    WhereClauseJoinOp::Or,
    WhereClauseJoinOp::Not
  };
  return values;
}

inline const char * const *EnumNamesWhereClauseJoinOp() {
  static const char * const names[] = {
    "And",
    "Or",
    "Not",
    nullptr
  };
  return names;
}

inline const char *EnumNameWhereClauseJoinOp(WhereClauseJoinOp e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesWhereClauseJoinOp()[index];
}

struct DatatableCell FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DatatableCellTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.DatatableCell";
  }
  enum {
    VT_V = 4
  };
  const flatbuffers::String *v() const {
    return GetPointer<const flatbuffers::String *>(VT_V);
  }
  flatbuffers::String *mutable_v() {
    return GetPointer<flatbuffers::String *>(VT_V);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_V) &&
           verifier.Verify(v()) &&
           verifier.EndTable();
  }
};

struct DatatableCellBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_v(flatbuffers::Offset<flatbuffers::String> v) {
    fbb_.AddOffset(DatatableCell::VT_V, v);
  }
  explicit DatatableCellBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DatatableCellBuilder &operator=(const DatatableCellBuilder &);
  flatbuffers::Offset<DatatableCell> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DatatableCell>(end);
    return o;
  }
};

inline flatbuffers::Offset<DatatableCell> CreateDatatableCell(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> v = 0) {
  DatatableCellBuilder builder_(_fbb);
  builder_.add_v(v);
  return builder_.Finish();
}

inline flatbuffers::Offset<DatatableCell> CreateDatatableCellDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *v = nullptr) {
  return GViz::CreateDatatableCell(
      _fbb,
      v ? _fbb.CreateString(v) : 0);
}

struct DatatableRow FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DatatableRowTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.DatatableRow";
  }
  enum {
    VT_C = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<DatatableCell>> *c() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableCell>> *>(VT_C);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableCell>> *mutable_c() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableCell>> *>(VT_C);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_C) &&
           verifier.Verify(c()) &&
           verifier.VerifyVectorOfTables(c()) &&
           verifier.EndTable();
  }
};

struct DatatableRowBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_c(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableCell>>> c) {
    fbb_.AddOffset(DatatableRow::VT_C, c);
  }
  explicit DatatableRowBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DatatableRowBuilder &operator=(const DatatableRowBuilder &);
  flatbuffers::Offset<DatatableRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DatatableRow>(end);
    return o;
  }
};

inline flatbuffers::Offset<DatatableRow> CreateDatatableRow(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableCell>>> c = 0) {
  DatatableRowBuilder builder_(_fbb);
  builder_.add_c(c);
  return builder_.Finish();
}

inline flatbuffers::Offset<DatatableRow> CreateDatatableRowDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<DatatableCell>> *c = nullptr) {
  return GViz::CreateDatatableRow(
      _fbb,
      c ? _fbb.CreateVector<flatbuffers::Offset<DatatableCell>>(*c) : 0);
}

struct DatatableColumn FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DatatableColumnTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.DatatableColumn";
  }
  enum {
    VT_ID = 4,
    VT_LABEL = 6,
    VT_PATTERN = 8,
    VT_TYPE = 10,
    VT_PREFIX = 12
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  flatbuffers::String *mutable_id() {
    return GetPointer<flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *label() const {
    return GetPointer<const flatbuffers::String *>(VT_LABEL);
  }
  flatbuffers::String *mutable_label() {
    return GetPointer<flatbuffers::String *>(VT_LABEL);
  }
  bool KeyCompareLessThan(const DatatableColumn *o) const {
    return *label() < *o->label();
  }
  int KeyCompareWithValue(const char *val) const {
    return strcmp(label()->c_str(), val);
  }
  const flatbuffers::String *pattern() const {
    return GetPointer<const flatbuffers::String *>(VT_PATTERN);
  }
  flatbuffers::String *mutable_pattern() {
    return GetPointer<flatbuffers::String *>(VT_PATTERN);
  }
  DatatableColumnType type() const {
    return static_cast<DatatableColumnType>(GetField<int8_t>(VT_TYPE, 0));
  }
  bool mutate_type(DatatableColumnType _type) {
    return SetField<int8_t>(VT_TYPE, static_cast<int8_t>(_type), 0);
  }
  const flatbuffers::String *prefix() const {
    return GetPointer<const flatbuffers::String *>(VT_PREFIX);
  }
  flatbuffers::String *mutable_prefix() {
    return GetPointer<flatbuffers::String *>(VT_PREFIX);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.Verify(id()) &&
           VerifyOffsetRequired(verifier, VT_LABEL) &&
           verifier.Verify(label()) &&
           VerifyOffset(verifier, VT_PATTERN) &&
           verifier.Verify(pattern()) &&
           VerifyField<int8_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_PREFIX) &&
           verifier.Verify(prefix()) &&
           verifier.EndTable();
  }
};

struct DatatableColumnBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(DatatableColumn::VT_ID, id);
  }
  void add_label(flatbuffers::Offset<flatbuffers::String> label) {
    fbb_.AddOffset(DatatableColumn::VT_LABEL, label);
  }
  void add_pattern(flatbuffers::Offset<flatbuffers::String> pattern) {
    fbb_.AddOffset(DatatableColumn::VT_PATTERN, pattern);
  }
  void add_type(DatatableColumnType type) {
    fbb_.AddElement<int8_t>(DatatableColumn::VT_TYPE, static_cast<int8_t>(type), 0);
  }
  void add_prefix(flatbuffers::Offset<flatbuffers::String> prefix) {
    fbb_.AddOffset(DatatableColumn::VT_PREFIX, prefix);
  }
  explicit DatatableColumnBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DatatableColumnBuilder &operator=(const DatatableColumnBuilder &);
  flatbuffers::Offset<DatatableColumn> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DatatableColumn>(end);
    fbb_.Required(o, DatatableColumn::VT_LABEL);
    return o;
  }
};

inline flatbuffers::Offset<DatatableColumn> CreateDatatableColumn(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> label = 0,
    flatbuffers::Offset<flatbuffers::String> pattern = 0,
    DatatableColumnType type = DatatableColumnType::boolean,
    flatbuffers::Offset<flatbuffers::String> prefix = 0) {
  DatatableColumnBuilder builder_(_fbb);
  builder_.add_prefix(prefix);
  builder_.add_pattern(pattern);
  builder_.add_label(label);
  builder_.add_id(id);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<DatatableColumn> CreateDatatableColumnDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *label = nullptr,
    const char *pattern = nullptr,
    DatatableColumnType type = DatatableColumnType::boolean,
    const char *prefix = nullptr) {
  return GViz::CreateDatatableColumn(
      _fbb,
      id ? _fbb.CreateString(id) : 0,
      label ? _fbb.CreateString(label) : 0,
      pattern ? _fbb.CreateString(pattern) : 0,
      type,
      prefix ? _fbb.CreateString(prefix) : 0);
}

struct Datatable FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DatatableTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.Datatable";
  }
  enum {
    VT_ROWS = 4,
    VT_COLS = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<DatatableRow>> *rows() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableRow>> *>(VT_ROWS);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableRow>> *mutable_rows() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableRow>> *>(VT_ROWS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *cols() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_COLS);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *mutable_cols() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_COLS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ROWS) &&
           verifier.Verify(rows()) &&
           verifier.VerifyVectorOfTables(rows()) &&
           VerifyOffset(verifier, VT_COLS) &&
           verifier.Verify(cols()) &&
           verifier.VerifyVectorOfTables(cols()) &&
           verifier.EndTable();
  }
};

struct DatatableBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_rows(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableRow>>> rows) {
    fbb_.AddOffset(Datatable::VT_ROWS, rows);
  }
  void add_cols(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> cols) {
    fbb_.AddOffset(Datatable::VT_COLS, cols);
  }
  explicit DatatableBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DatatableBuilder &operator=(const DatatableBuilder &);
  flatbuffers::Offset<Datatable> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Datatable>(end);
    return o;
  }
};

inline flatbuffers::Offset<Datatable> CreateDatatable(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableRow>>> rows = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> cols = 0) {
  DatatableBuilder builder_(_fbb);
  builder_.add_cols(cols);
  builder_.add_rows(rows);
  return builder_.Finish();
}

inline flatbuffers::Offset<Datatable> CreateDatatableDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<DatatableRow>> *rows = nullptr,
    const std::vector<flatbuffers::Offset<DatatableColumn>> *cols = nullptr) {
  return GViz::CreateDatatable(
      _fbb,
      rows ? _fbb.CreateVector<flatbuffers::Offset<DatatableRow>>(*rows) : 0,
      cols ? _fbb.CreateVector<flatbuffers::Offset<DatatableColumn>>(*cols) : 0);
}

struct DatatableResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DatatableResponseTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.DatatableResponse";
  }
  enum {
    VT_VERSION = 4,
    VT_REQID = 6,
    VT_STATUS = 8,
    VT_SIG = 10,
    VT_TABLE = 12
  };
  const flatbuffers::String *version() const {
    return GetPointer<const flatbuffers::String *>(VT_VERSION);
  }
  flatbuffers::String *mutable_version() {
    return GetPointer<flatbuffers::String *>(VT_VERSION);
  }
  const flatbuffers::String *reqId() const {
    return GetPointer<const flatbuffers::String *>(VT_REQID);
  }
  flatbuffers::String *mutable_reqId() {
    return GetPointer<flatbuffers::String *>(VT_REQID);
  }
  const flatbuffers::String *status() const {
    return GetPointer<const flatbuffers::String *>(VT_STATUS);
  }
  flatbuffers::String *mutable_status() {
    return GetPointer<flatbuffers::String *>(VT_STATUS);
  }
  const flatbuffers::String *sig() const {
    return GetPointer<const flatbuffers::String *>(VT_SIG);
  }
  flatbuffers::String *mutable_sig() {
    return GetPointer<flatbuffers::String *>(VT_SIG);
  }
  const Datatable *table() const {
    return GetPointer<const Datatable *>(VT_TABLE);
  }
  Datatable *mutable_table() {
    return GetPointer<Datatable *>(VT_TABLE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VERSION) &&
           verifier.Verify(version()) &&
           VerifyOffset(verifier, VT_REQID) &&
           verifier.Verify(reqId()) &&
           VerifyOffset(verifier, VT_STATUS) &&
           verifier.Verify(status()) &&
           VerifyOffset(verifier, VT_SIG) &&
           verifier.Verify(sig()) &&
           VerifyOffset(verifier, VT_TABLE) &&
           verifier.VerifyTable(table()) &&
           verifier.EndTable();
  }
};

struct DatatableResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_version(flatbuffers::Offset<flatbuffers::String> version) {
    fbb_.AddOffset(DatatableResponse::VT_VERSION, version);
  }
  void add_reqId(flatbuffers::Offset<flatbuffers::String> reqId) {
    fbb_.AddOffset(DatatableResponse::VT_REQID, reqId);
  }
  void add_status(flatbuffers::Offset<flatbuffers::String> status) {
    fbb_.AddOffset(DatatableResponse::VT_STATUS, status);
  }
  void add_sig(flatbuffers::Offset<flatbuffers::String> sig) {
    fbb_.AddOffset(DatatableResponse::VT_SIG, sig);
  }
  void add_table(flatbuffers::Offset<Datatable> table) {
    fbb_.AddOffset(DatatableResponse::VT_TABLE, table);
  }
  explicit DatatableResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DatatableResponseBuilder &operator=(const DatatableResponseBuilder &);
  flatbuffers::Offset<DatatableResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DatatableResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<DatatableResponse> CreateDatatableResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> version = 0,
    flatbuffers::Offset<flatbuffers::String> reqId = 0,
    flatbuffers::Offset<flatbuffers::String> status = 0,
    flatbuffers::Offset<flatbuffers::String> sig = 0,
    flatbuffers::Offset<Datatable> table = 0) {
  DatatableResponseBuilder builder_(_fbb);
  builder_.add_table(table);
  builder_.add_sig(sig);
  builder_.add_status(status);
  builder_.add_reqId(reqId);
  builder_.add_version(version);
  return builder_.Finish();
}

inline flatbuffers::Offset<DatatableResponse> CreateDatatableResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *version = nullptr,
    const char *reqId = nullptr,
    const char *status = nullptr,
    const char *sig = nullptr,
    flatbuffers::Offset<Datatable> table = 0) {
  return GViz::CreateDatatableResponse(
      _fbb,
      version ? _fbb.CreateString(version) : 0,
      reqId ? _fbb.CreateString(reqId) : 0,
      status ? _fbb.CreateString(status) : 0,
      sig ? _fbb.CreateString(sig) : 0,
      table);
}

struct WhereClause FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return WhereClauseTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.WhereClause";
  }
  enum {
    VT_JOIN_OP = 4,
    VT_COLUMN = 6,
    VT_OP = 8,
    VT_VALUE = 10
  };
  WhereClauseJoinOp join_op() const {
    return static_cast<WhereClauseJoinOp>(GetField<int8_t>(VT_JOIN_OP, 0));
  }
  bool mutate_join_op(WhereClauseJoinOp _join_op) {
    return SetField<int8_t>(VT_JOIN_OP, static_cast<int8_t>(_join_op), 0);
  }
  const DatatableColumn *column() const {
    return GetPointer<const DatatableColumn *>(VT_COLUMN);
  }
  DatatableColumn *mutable_column() {
    return GetPointer<DatatableColumn *>(VT_COLUMN);
  }
  WhereClauseOp op() const {
    return static_cast<WhereClauseOp>(GetField<int8_t>(VT_OP, 0));
  }
  bool mutate_op(WhereClauseOp _op) {
    return SetField<int8_t>(VT_OP, static_cast<int8_t>(_op), 0);
  }
  const flatbuffers::String *value() const {
    return GetPointer<const flatbuffers::String *>(VT_VALUE);
  }
  flatbuffers::String *mutable_value() {
    return GetPointer<flatbuffers::String *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_JOIN_OP) &&
           VerifyOffset(verifier, VT_COLUMN) &&
           verifier.VerifyTable(column()) &&
           VerifyField<int8_t>(verifier, VT_OP) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.Verify(value()) &&
           verifier.EndTable();
  }
};

struct WhereClauseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_join_op(WhereClauseJoinOp join_op) {
    fbb_.AddElement<int8_t>(WhereClause::VT_JOIN_OP, static_cast<int8_t>(join_op), 0);
  }
  void add_column(flatbuffers::Offset<DatatableColumn> column) {
    fbb_.AddOffset(WhereClause::VT_COLUMN, column);
  }
  void add_op(WhereClauseOp op) {
    fbb_.AddElement<int8_t>(WhereClause::VT_OP, static_cast<int8_t>(op), 0);
  }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) {
    fbb_.AddOffset(WhereClause::VT_VALUE, value);
  }
  explicit WhereClauseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WhereClauseBuilder &operator=(const WhereClauseBuilder &);
  flatbuffers::Offset<WhereClause> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<WhereClause>(end);
    return o;
  }
};

inline flatbuffers::Offset<WhereClause> CreateWhereClause(
    flatbuffers::FlatBufferBuilder &_fbb,
    WhereClauseJoinOp join_op = WhereClauseJoinOp::And,
    flatbuffers::Offset<DatatableColumn> column = 0,
    WhereClauseOp op = WhereClauseOp::Equals,
    flatbuffers::Offset<flatbuffers::String> value = 0) {
  WhereClauseBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_column(column);
  builder_.add_op(op);
  builder_.add_join_op(join_op);
  return builder_.Finish();
}

inline flatbuffers::Offset<WhereClause> CreateWhereClauseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    WhereClauseJoinOp join_op = WhereClauseJoinOp::And,
    flatbuffers::Offset<DatatableColumn> column = 0,
    WhereClauseOp op = WhereClauseOp::Equals,
    const char *value = nullptr) {
  return GViz::CreateWhereClause(
      _fbb,
      join_op,
      column,
      op,
      value ? _fbb.CreateString(value) : 0);
}

struct Query FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return QueryTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "GViz.Query";
  }
  enum {
    VT_SELECT = 4,
    VT_WHERE = 6,
    VT_GROUP_BY = 8,
    VT_PIVOT = 10,
    VT_ORDER_BY = 12,
    VT_LIMIT = 14,
    VT_OFFSET = 16,
    VT_OPTIONS = 18
  };
  const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *select() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_SELECT);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *mutable_select() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_SELECT);
  }
  const flatbuffers::Vector<flatbuffers::Offset<WhereClause>> *where() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<WhereClause>> *>(VT_WHERE);
  }
  flatbuffers::Vector<flatbuffers::Offset<WhereClause>> *mutable_where() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<WhereClause>> *>(VT_WHERE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *group_by() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_GROUP_BY);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *mutable_group_by() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_GROUP_BY);
  }
  const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *pivot() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_PIVOT);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *mutable_pivot() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_PIVOT);
  }
  const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *order_by() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_ORDER_BY);
  }
  flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *mutable_order_by() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>> *>(VT_ORDER_BY);
  }
  uint32_t limit() const {
    return GetField<uint32_t>(VT_LIMIT, 0);
  }
  bool mutate_limit(uint32_t _limit) {
    return SetField<uint32_t>(VT_LIMIT, _limit, 0);
  }
  uint32_t offset() const {
    return GetField<uint32_t>(VT_OFFSET, 0);
  }
  bool mutate_offset(uint32_t _offset) {
    return SetField<uint32_t>(VT_OFFSET, _offset, 0);
  }
  QueryOption options() const {
    return static_cast<QueryOption>(GetField<int8_t>(VT_OPTIONS, 0));
  }
  bool mutate_options(QueryOption _options) {
    return SetField<int8_t>(VT_OPTIONS, static_cast<int8_t>(_options), 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_SELECT) &&
           verifier.Verify(select()) &&
           verifier.VerifyVectorOfTables(select()) &&
           VerifyOffset(verifier, VT_WHERE) &&
           verifier.Verify(where()) &&
           verifier.VerifyVectorOfTables(where()) &&
           VerifyOffset(verifier, VT_GROUP_BY) &&
           verifier.Verify(group_by()) &&
           verifier.VerifyVectorOfTables(group_by()) &&
           VerifyOffset(verifier, VT_PIVOT) &&
           verifier.Verify(pivot()) &&
           verifier.VerifyVectorOfTables(pivot()) &&
           VerifyOffset(verifier, VT_ORDER_BY) &&
           verifier.Verify(order_by()) &&
           verifier.VerifyVectorOfTables(order_by()) &&
           VerifyField<uint32_t>(verifier, VT_LIMIT) &&
           VerifyField<uint32_t>(verifier, VT_OFFSET) &&
           VerifyField<int8_t>(verifier, VT_OPTIONS) &&
           verifier.EndTable();
  }
};

struct QueryBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_select(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> select) {
    fbb_.AddOffset(Query::VT_SELECT, select);
  }
  void add_where(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<WhereClause>>> where) {
    fbb_.AddOffset(Query::VT_WHERE, where);
  }
  void add_group_by(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> group_by) {
    fbb_.AddOffset(Query::VT_GROUP_BY, group_by);
  }
  void add_pivot(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> pivot) {
    fbb_.AddOffset(Query::VT_PIVOT, pivot);
  }
  void add_order_by(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> order_by) {
    fbb_.AddOffset(Query::VT_ORDER_BY, order_by);
  }
  void add_limit(uint32_t limit) {
    fbb_.AddElement<uint32_t>(Query::VT_LIMIT, limit, 0);
  }
  void add_offset(uint32_t offset) {
    fbb_.AddElement<uint32_t>(Query::VT_OFFSET, offset, 0);
  }
  void add_options(QueryOption options) {
    fbb_.AddElement<int8_t>(Query::VT_OPTIONS, static_cast<int8_t>(options), 0);
  }
  explicit QueryBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  QueryBuilder &operator=(const QueryBuilder &);
  flatbuffers::Offset<Query> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Query>(end);
    return o;
  }
};

inline flatbuffers::Offset<Query> CreateQuery(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> select = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<WhereClause>>> where = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> group_by = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> pivot = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DatatableColumn>>> order_by = 0,
    uint32_t limit = 0,
    uint32_t offset = 0,
    QueryOption options = QueryOption::defaults) {
  QueryBuilder builder_(_fbb);
  builder_.add_offset(offset);
  builder_.add_limit(limit);
  builder_.add_order_by(order_by);
  builder_.add_pivot(pivot);
  builder_.add_group_by(group_by);
  builder_.add_where(where);
  builder_.add_select(select);
  builder_.add_options(options);
  return builder_.Finish();
}

inline flatbuffers::Offset<Query> CreateQueryDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<DatatableColumn>> *select = nullptr,
    const std::vector<flatbuffers::Offset<WhereClause>> *where = nullptr,
    const std::vector<flatbuffers::Offset<DatatableColumn>> *group_by = nullptr,
    const std::vector<flatbuffers::Offset<DatatableColumn>> *pivot = nullptr,
    const std::vector<flatbuffers::Offset<DatatableColumn>> *order_by = nullptr,
    uint32_t limit = 0,
    uint32_t offset = 0,
    QueryOption options = QueryOption::defaults) {
  return GViz::CreateQuery(
      _fbb,
      select ? _fbb.CreateVector<flatbuffers::Offset<DatatableColumn>>(*select) : 0,
      where ? _fbb.CreateVector<flatbuffers::Offset<WhereClause>>(*where) : 0,
      group_by ? _fbb.CreateVector<flatbuffers::Offset<DatatableColumn>>(*group_by) : 0,
      pivot ? _fbb.CreateVector<flatbuffers::Offset<DatatableColumn>>(*pivot) : 0,
      order_by ? _fbb.CreateVector<flatbuffers::Offset<DatatableColumn>>(*order_by) : 0,
      limit,
      offset,
      options);
}

inline const flatbuffers::TypeTable *DatatableColumnTypeTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableColumnTypeTypeTable
  };
  static const char * const names[] = {
    "boolean",
    "number",
    "string",
    "date",
    "datetime",
    "timeofday",
    "unknown"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 7, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *QueryOptionTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    QueryOptionTypeTable
  };
  static const char * const names[] = {
    "defaults",
    "no_format",
    "no_values"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 3, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *WhereClauseOpTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    WhereClauseOpTypeTable
  };
  static const char * const names[] = {
    "Equals",
    "NotEquals",
    "GreaterThan",
    "GreaterThanOrEqualTo",
    "LessThan",
    "LessThanOrEqualTo",
    "IsNull",
    "IsNotNull",
    "Contains",
    "StartsWith",
    "EndsWith",
    "Matches",
    "Like"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 13, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *WhereClauseJoinOpTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    WhereClauseJoinOpTypeTable
  };
  static const char * const names[] = {
    "And",
    "Or",
    "Not"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 3, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DatatableCellTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 }
  };
  static const char * const names[] = {
    "v"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 1, type_codes, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DatatableRowTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_SEQUENCE, 1, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableCellTypeTable
  };
  static const char * const names[] = {
    "c"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 1, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DatatableColumnTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_STRING, 0, -1 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableColumnTypeTypeTable
  };
  static const char * const names[] = {
    "id",
    "label",
    "pattern",
    "type",
    "prefix"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 5, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DatatableTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 1 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableRowTypeTable,
    DatatableColumnTypeTable
  };
  static const char * const names[] = {
    "rows",
    "cols"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DatatableResponseTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableTypeTable
  };
  static const char * const names[] = {
    "version",
    "reqId",
    "status",
    "sig",
    "table"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 5, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *WhereClauseTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_SEQUENCE, 0, 1 },
    { flatbuffers::ET_CHAR, 0, 2 },
    { flatbuffers::ET_STRING, 0, -1 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    WhereClauseJoinOpTypeTable,
    DatatableColumnTypeTable,
    WhereClauseOpTypeTable
  };
  static const char * const names[] = {
    "join_op",
    "column",
    "op",
    "value"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 4, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *QueryTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 1 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_UINT, 0, -1 },
    { flatbuffers::ET_UINT, 0, -1 },
    { flatbuffers::ET_CHAR, 0, 2 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DatatableColumnTypeTable,
    WhereClauseTypeTable,
    QueryOptionTypeTable
  };
  static const char * const names[] = {
    "select",
    "where",
    "group_by",
    "pivot",
    "order_by",
    "limit",
    "offset",
    "options"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 8, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const GViz::Query *GetQuery(const void *buf) {
  return flatbuffers::GetRoot<GViz::Query>(buf);
}

inline const GViz::Query *GetSizePrefixedQuery(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<GViz::Query>(buf);
}

inline Query *GetMutableQuery(void *buf) {
  return flatbuffers::GetMutableRoot<Query>(buf);
}

inline const char *QueryIdentifier() {
  return "gviz";
}

inline bool QueryBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, QueryIdentifier());
}

inline bool VerifyQueryBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<GViz::Query>(QueryIdentifier());
}

inline bool VerifySizePrefixedQueryBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<GViz::Query>(QueryIdentifier());
}

inline const char *QueryExtension() {
  return "fb";
}

inline void FinishQueryBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GViz::Query> root) {
  fbb.Finish(root, QueryIdentifier());
}

inline void FinishSizePrefixedQueryBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GViz::Query> root) {
  fbb.FinishSizePrefixed(root, QueryIdentifier());
}

}  // namespace GViz

#endif  // FLATBUFFERS_GENERATED_GVIZ_GVIZ_H_
