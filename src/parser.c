#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 9
#define STATE_COUNT 27
#define SYMBOL_COUNT 25
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 0

enum {
  sym__newline = 1,
  sym__indent = 2,
  sym__dedent = 3,
  sym__string_start = 4,
  sym__string_content = 5,
  sym__string_end = 6,
  aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH = 7,
  aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH = 8,
  sym_escape_sequence = 9,
  sym_integer = 10,
  sym_float = 11,
  sym_identifier = 12,
  sym_true = 13,
  sym_false = 14,
  sym_none = 15,
  sym_module = 16,
  sym_doc_header = 17,
  sym_doc_section = 18,
  sym_section_title = 19,
  sym_section_body = 20,
  sym_string = 21,
  aux_sym_module_repeat1 = 22,
  aux_sym_section_body_repeat1 = 23,
  aux_sym_string_repeat1 = 24,
};

static const char *ts_symbol_names[] = {
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__string_start] = "\"",
  [sym__string_content] = "_string_content",
  [sym__string_end] = "\"",
  [ts_builtin_sym_end] = "END",
  [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = "/[^\\r\\n]+/",
  [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = "/[\\^]{5}[\\^o]*/",
  [sym_escape_sequence] = "escape_sequence",
  [sym_integer] = "integer",
  [sym_float] = "float",
  [sym_identifier] = "identifier",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_none] = "none",
  [sym_module] = "module",
  [sym_doc_header] = "doc_header",
  [sym_doc_section] = "doc_section",
  [sym_section_title] = "section_title",
  [sym_section_body] = "section_body",
  [sym_string] = "string",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_section_body_repeat1] = "section_body_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym__string_start] = {
    .visible = true,
    .named = false,
  },
  [sym__string_content] = {
    .visible = false,
    .named = true,
  },
  [sym__string_end] = {
    .visible = true,
    .named = false,
  },
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = {
    .visible = false,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_true] = {
    .visible = true,
    .named = true,
  },
  [sym_false] = {
    .visible = true,
    .named = true,
  },
  [sym_none] = {
    .visible = true,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_doc_header] = {
    .visible = true,
    .named = true,
  },
  [sym_doc_section] = {
    .visible = true,
    .named = true,
  },
  [sym_section_title] = {
    .visible = true,
    .named = true,
  },
  [sym_section_body] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_section_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '.')
        ADVANCE(2);
      if (lookahead == '0')
        ADVANCE(10);
      if (lookahead == '\\')
        SKIP(23);
      if (lookahead == '^')
        ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(0);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(30);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(3);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == '_')
        ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(5);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(9);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(3);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(5);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(9);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '+' ||
          lookahead == '-')
        ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(7);
      END_STATE();
    case 6:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(7);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == '_')
        ADVANCE(8);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(9);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_float);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(9);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(7);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_float);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.')
        ADVANCE(4);
      if (lookahead == 'B')
        ADVANCE(11);
      if (lookahead == 'O')
        ADVANCE(15);
      if (lookahead == 'X')
        ADVANCE(18);
      if (lookahead == '_')
        ADVANCE(21);
      if (lookahead == 'b')
        ADVANCE(11);
      if (lookahead == 'o')
        ADVANCE(15);
      if (lookahead == 'x')
        ADVANCE(18);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(5);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(14);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 11:
      if (lookahead == '_')
        ADVANCE(12);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(13);
      END_STATE();
    case 12:
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_')
        ADVANCE(12);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(13);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_integer);
      END_STATE();
    case 15:
      if (lookahead == '_')
        ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(17);
      END_STATE();
    case 16:
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(17);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_')
        ADVANCE(16);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == '_')
        ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(20);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(20);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '_')
        ADVANCE(19);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.')
        ADVANCE(4);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(5);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(14);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == '.')
        ADVANCE(4);
      if (lookahead == '_')
        ADVANCE(21);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(5);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(14);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '\n')
        SKIP(0);
      if (lookahead == '\r')
        SKIP(24);
      END_STATE();
    case 24:
      if (lookahead == '\n')
        SKIP(0);
      END_STATE();
    case 25:
      if (lookahead == '^')
        ADVANCE(26);
      END_STATE();
    case 26:
      if (lookahead == '^')
        ADVANCE(27);
      END_STATE();
    case 27:
      if (lookahead == '^')
        ADVANCE(28);
      END_STATE();
    case 28:
      if (lookahead == '^')
        ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH);
      if (lookahead == '^' ||
          lookahead == 'o')
        ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '\\')
        ADVANCE(32);
      if (lookahead == '\n' ||
          lookahead == '\r')
        SKIP(31);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        ADVANCE(33);
      ADVANCE(32);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '\\')
        ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 34:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '\\')
        SKIP(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(34);
      END_STATE();
    case 35:
      if (lookahead == '\n')
        SKIP(34);
      if (lookahead == '\r')
        SKIP(36);
      END_STATE();
    case 36:
      if (lookahead == '\n')
        SKIP(34);
      END_STATE();
    case 37:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '.')
        ADVANCE(38);
      if (lookahead == '0')
        ADVANCE(45);
      if (lookahead == '\\')
        ADVANCE(32);
      if (lookahead == '\n' ||
          lookahead == '\r')
        SKIP(37);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        ADVANCE(57);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(58);
      ADVANCE(32);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(40);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(41);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(41);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '+' ||
          lookahead == '-')
        ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(44);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '.')
        ADVANCE(40);
      if (lookahead == 'B')
        ADVANCE(46);
      if (lookahead == 'O')
        ADVANCE(49);
      if (lookahead == 'X')
        ADVANCE(52);
      if (lookahead == '_')
        ADVANCE(55);
      if (lookahead == 'b')
        ADVANCE(46);
      if (lookahead == 'o')
        ADVANCE(49);
      if (lookahead == 'x')
        ADVANCE(52);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(41);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(47);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(47);
      if (lookahead == '0' ||
          lookahead == '1')
        ADVANCE(48);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(50);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '7'))
        ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '_')
        ADVANCE(53);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '.')
        ADVANCE(40);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(41);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '.')
        ADVANCE(40);
      if (lookahead == '_')
        ADVANCE(55);
      if (lookahead == 'E' ||
          lookahead == 'e')
        ADVANCE(41);
      if (lookahead == 'J' ||
          lookahead == 'j')
        ADVANCE(32);
      if (lookahead == 'L' ||
          lookahead == 'l')
        ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (lookahead == '.')
        ADVANCE(38);
      if (lookahead == '0')
        ADVANCE(45);
      if (lookahead == '\\')
        ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        ADVANCE(57);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r')
        ADVANCE(32);
      END_STATE();
    case 59:
      if (lookahead == '\\')
        SKIP(60);
      if (lookahead == '^')
        ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(59);
      END_STATE();
    case 60:
      if (lookahead == '\n')
        SKIP(59);
      if (lookahead == '\r')
        SKIP(61);
      END_STATE();
    case 61:
      if (lookahead == '\n')
        SKIP(59);
      END_STATE();
    case 62:
      if (lookahead == '.')
        ADVANCE(2);
      if (lookahead == '0')
        ADVANCE(10);
      if (lookahead == '\\')
        SKIP(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(62);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(30);
      END_STATE();
    case 63:
      if (lookahead == '\n')
        SKIP(62);
      if (lookahead == '\r')
        SKIP(64);
      END_STATE();
    case 64:
      if (lookahead == '\n')
        SKIP(62);
      END_STATE();
    case 65:
      if (lookahead == '\\')
        ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(65);
      END_STATE();
    case 66:
      if (lookahead == '\n')
        ADVANCE(67);
      if (lookahead == '\r')
        ADVANCE(68);
      if (lookahead == 'U')
        ADVANCE(69);
      if (lookahead == 'o')
        ADVANCE(77);
      if (lookahead == 'u')
        ADVANCE(73);
      if (lookahead == 'x')
        ADVANCE(75);
      if (lookahead != 0)
        ADVANCE(67);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n')
        ADVANCE(67);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(70);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(71);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(72);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(73);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(74);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(75);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(76);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(67);
      END_STATE();
    case 77:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(78);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(79);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(67);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 'F')
        ADVANCE(1);
      if (lookahead == 'N')
        ADVANCE(6);
      if (lookahead == 'T')
        ADVANCE(10);
      END_STATE();
    case 1:
      if (lookahead == 'a')
        ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'l')
        ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == 's')
        ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == 'e')
        ADVANCE(5);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 6:
      if (lookahead == 'o')
        ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == 'n')
        ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == 'e')
        ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_none);
      END_STATE();
    case 10:
      if (lookahead == 'r')
        ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == 'u')
        ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == 'e')
        ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 31},
  [2] = {.lex_state = 34, .external_lex_state = 2},
  [3] = {.lex_state = 34},
  [4] = {.lex_state = 31},
  [5] = {.lex_state = 37, .external_lex_state = 3},
  [6] = {.lex_state = 31},
  [7] = {.lex_state = 59},
  [8] = {.lex_state = 34, .external_lex_state = 2},
  [9] = {.lex_state = 62, .external_lex_state = 3},
  [10] = {.lex_state = 31},
  [11] = {.lex_state = 65, .external_lex_state = 4},
  [12] = {.lex_state = 34, .external_lex_state = 2},
  [13] = {.lex_state = 31},
  [14] = {.lex_state = 37, .external_lex_state = 3},
  [15] = {.lex_state = 31},
  [16] = {.lex_state = 34, .external_lex_state = 2},
  [17] = {.lex_state = 59},
  [18] = {.lex_state = 34, .external_lex_state = 2},
  [19] = {.lex_state = 65, .external_lex_state = 4},
  [20] = {.lex_state = 37, .external_lex_state = 3},
  [21] = {.lex_state = 37, .external_lex_state = 3},
  [22] = {.lex_state = 37, .external_lex_state = 3},
  [23] = {.lex_state = 34, .external_lex_state = 2},
  [24] = {.lex_state = 34, .external_lex_state = 2},
  [25] = {.lex_state = 65, .external_lex_state = 4},
  [26] = {.lex_state = 62, .external_lex_state = 3},
};

enum {
  ts_external_token__newline,
  ts_external_token__indent,
  ts_external_token__dedent,
  ts_external_token__string_start,
  ts_external_token__string_content,
  ts_external_token__string_end,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token__string_start] = sym__string_start,
  [ts_external_token__string_content] = sym__string_content,
  [ts_external_token__string_end] = sym__string_end,
};

static bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__string_start] = true,
    [ts_external_token__string_content] = true,
    [ts_external_token__string_end] = true,
  },
  [2] = {
    [ts_external_token__newline] = true,
  },
  [3] = {
    [ts_external_token__string_start] = true,
  },
  [4] = {
    [ts_external_token__string_content] = true,
    [ts_external_token__string_end] = true,
  },
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym__newline] = ACTIONS(2),
    [sym__indent] = ACTIONS(2),
    [sym__dedent] = ACTIONS(2),
    [sym__string_start] = ACTIONS(2),
    [sym__string_content] = ACTIONS(2),
    [sym__string_end] = ACTIONS(2),
    [ts_builtin_sym_end] = ACTIONS(2),
    [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = ACTIONS(2),
    [sym_integer] = ACTIONS(4),
    [sym_float] = ACTIONS(2),
    [sym_identifier] = ACTIONS(4),
    [sym_true] = ACTIONS(4),
    [sym_false] = ACTIONS(4),
    [sym_none] = ACTIONS(4),
  },
  [1] = {
    [sym_module] = STATE(3),
    [sym_doc_header] = STATE(4),
    [sym_doc_section] = STATE(6),
    [sym_section_title] = STATE(5),
    [aux_sym_module_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(6),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(8),
  },
  [2] = {
    [sym__newline] = ACTIONS(10),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(12),
  },
  [4] = {
    [sym_doc_section] = STATE(10),
    [sym_section_title] = STATE(9),
    [aux_sym_module_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(14),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(16),
  },
  [5] = {
    [sym_section_body] = STATE(13),
    [sym_string] = STATE(12),
    [aux_sym_section_body_repeat1] = STATE(14),
    [sym__string_start] = ACTIONS(18),
    [ts_builtin_sym_end] = ACTIONS(20),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(20),
    [sym_integer] = ACTIONS(22),
    [sym_float] = ACTIONS(22),
    [sym_identifier] = ACTIONS(22),
  },
  [6] = {
    [sym_doc_section] = STATE(15),
    [sym_section_title] = STATE(9),
    [aux_sym_module_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(14),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(16),
  },
  [7] = {
    [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = ACTIONS(24),
  },
  [8] = {
    [sym__newline] = ACTIONS(26),
  },
  [9] = {
    [sym_section_body] = STATE(13),
    [sym_string] = STATE(12),
    [aux_sym_section_body_repeat1] = STATE(14),
    [sym__string_start] = ACTIONS(18),
    [sym_integer] = ACTIONS(22),
    [sym_float] = ACTIONS(28),
    [sym_identifier] = ACTIONS(28),
  },
  [10] = {
    [sym_doc_section] = STATE(15),
    [sym_section_title] = STATE(9),
    [aux_sym_module_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(30),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(16),
  },
  [11] = {
    [aux_sym_string_repeat1] = STATE(19),
    [sym__string_content] = ACTIONS(32),
    [sym__string_end] = ACTIONS(34),
    [sym_escape_sequence] = ACTIONS(32),
  },
  [12] = {
    [sym__newline] = ACTIONS(36),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(38),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(38),
  },
  [14] = {
    [sym_string] = STATE(12),
    [aux_sym_section_body_repeat1] = STATE(21),
    [sym__string_start] = ACTIONS(18),
    [ts_builtin_sym_end] = ACTIONS(40),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(40),
    [sym_integer] = ACTIONS(22),
    [sym_float] = ACTIONS(22),
    [sym_identifier] = ACTIONS(22),
  },
  [15] = {
    [sym_doc_section] = STATE(15),
    [sym_section_title] = STATE(9),
    [aux_sym_module_repeat1] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(42),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(44),
  },
  [16] = {
    [sym__newline] = ACTIONS(47),
  },
  [17] = {
    [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = ACTIONS(49),
  },
  [18] = {
    [sym__newline] = ACTIONS(51),
  },
  [19] = {
    [aux_sym_string_repeat1] = STATE(25),
    [sym__string_content] = ACTIONS(53),
    [sym__string_end] = ACTIONS(55),
    [sym_escape_sequence] = ACTIONS(53),
  },
  [20] = {
    [sym__string_start] = ACTIONS(57),
    [ts_builtin_sym_end] = ACTIONS(57),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(57),
    [sym_integer] = ACTIONS(59),
    [sym_float] = ACTIONS(59),
    [sym_identifier] = ACTIONS(59),
  },
  [21] = {
    [sym_string] = STATE(12),
    [aux_sym_section_body_repeat1] = STATE(21),
    [sym__string_start] = ACTIONS(61),
    [ts_builtin_sym_end] = ACTIONS(57),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(57),
    [sym_integer] = ACTIONS(64),
    [sym_float] = ACTIONS(64),
    [sym_identifier] = ACTIONS(64),
  },
  [22] = {
    [sym__string_start] = ACTIONS(67),
    [ts_builtin_sym_end] = ACTIONS(67),
    [aux_sym_SLASH_LBRACK_CARET_BSLASHr_BSLASHn_RBRACK_PLUS_SLASH] = ACTIONS(67),
    [sym_integer] = ACTIONS(69),
    [sym_float] = ACTIONS(69),
    [sym_identifier] = ACTIONS(69),
  },
  [23] = {
    [sym__newline] = ACTIONS(71),
  },
  [24] = {
    [sym__newline] = ACTIONS(73),
  },
  [25] = {
    [aux_sym_string_repeat1] = STATE(25),
    [sym__string_content] = ACTIONS(75),
    [sym__string_end] = ACTIONS(78),
    [sym_escape_sequence] = ACTIONS(75),
  },
  [26] = {
    [sym__string_start] = ACTIONS(67),
    [sym_integer] = ACTIONS(69),
    [sym_float] = ACTIONS(67),
    [sym_identifier] = ACTIONS(67),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 0, .reusable = false},
  [2] = {.count = 1, .reusable = true}, RECOVER(),
  [4] = {.count = 1, .reusable = false}, RECOVER(),
  [6] = {.count = 1, .reusable = true}, REDUCE(sym_module, 0),
  [8] = {.count = 1, .reusable = true}, SHIFT(2),
  [10] = {.count = 1, .reusable = true}, SHIFT(7),
  [12] = {.count = 1, .reusable = true}, ACCEPT_INPUT(),
  [14] = {.count = 1, .reusable = true}, REDUCE(sym_module, 1),
  [16] = {.count = 1, .reusable = true}, SHIFT(8),
  [18] = {.count = 1, .reusable = true}, SHIFT(11),
  [20] = {.count = 1, .reusable = true}, REDUCE(sym_doc_header, 1),
  [22] = {.count = 1, .reusable = false}, SHIFT(12),
  [24] = {.count = 1, .reusable = true}, SHIFT(16),
  [26] = {.count = 1, .reusable = true}, SHIFT(17),
  [28] = {.count = 1, .reusable = true}, SHIFT(12),
  [30] = {.count = 1, .reusable = true}, REDUCE(sym_module, 2),
  [32] = {.count = 1, .reusable = true}, SHIFT(19),
  [34] = {.count = 1, .reusable = true}, SHIFT(18),
  [36] = {.count = 1, .reusable = true}, SHIFT(20),
  [38] = {.count = 1, .reusable = true}, REDUCE(sym_doc_section, 2),
  [40] = {.count = 1, .reusable = true}, REDUCE(sym_section_body, 1),
  [42] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [44] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(8),
  [47] = {.count = 1, .reusable = true}, SHIFT(22),
  [49] = {.count = 1, .reusable = true}, SHIFT(23),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym_string, 2),
  [53] = {.count = 1, .reusable = true}, SHIFT(25),
  [55] = {.count = 1, .reusable = true}, SHIFT(24),
  [57] = {.count = 1, .reusable = true}, REDUCE(aux_sym_section_body_repeat1, 2),
  [59] = {.count = 1, .reusable = false}, REDUCE(aux_sym_section_body_repeat1, 2),
  [61] = {.count = 2, .reusable = true}, REDUCE(aux_sym_section_body_repeat1, 2), SHIFT_REPEAT(11),
  [64] = {.count = 2, .reusable = false}, REDUCE(aux_sym_section_body_repeat1, 2), SHIFT_REPEAT(12),
  [67] = {.count = 1, .reusable = true}, REDUCE(sym_section_title, 4),
  [69] = {.count = 1, .reusable = false}, REDUCE(sym_section_title, 4),
  [71] = {.count = 1, .reusable = true}, SHIFT(26),
  [73] = {.count = 1, .reusable = true}, REDUCE(sym_string, 3),
  [75] = {.count = 2, .reusable = true}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(25),
  [78] = {.count = 1, .reusable = true}, REDUCE(aux_sym_string_repeat1, 2),
};

void *tree_sitter_mal_external_scanner_create();
void tree_sitter_mal_external_scanner_destroy(void *);
bool tree_sitter_mal_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_mal_external_scanner_serialize(void *, char *);
void tree_sitter_mal_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_mal() {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
      ts_external_scanner_symbol_map,
      tree_sitter_mal_external_scanner_create,
      tree_sitter_mal_external_scanner_destroy,
      tree_sitter_mal_external_scanner_scan,
      tree_sitter_mal_external_scanner_serialize,
      tree_sitter_mal_external_scanner_deserialize,
    },
  };
  return &language;
}
