#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 9
#define STATE_COUNT 20
#define SYMBOL_COUNT 24
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 0

enum {
  sym__newline = 1,
  sym__indent = 2,
  sym__dedent = 3,
  sym__string_start = 4,
  sym__string_content = 5,
  sym__string_end = 6,
  aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH = 7,
  sym_escape_sequence = 8,
  sym_integer = 9,
  sym_float = 10,
  sym_identifier = 11,
  sym_true = 12,
  sym_false = 13,
  sym_none = 14,
  sym_module = 15,
  sym_doc_section = 16,
  sym_section_title = 17,
  sym_section_body = 18,
  sym_string = 19,
  aux_sym_module_repeat1 = 20,
  aux_sym_doc_section_repeat1 = 21,
  aux_sym_section_title_repeat1 = 22,
  aux_sym_string_repeat1 = 23,
};

static const char *ts_symbol_names[] = {
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__string_start] = "\"",
  [sym__string_content] = "_string_content",
  [sym__string_end] = "\"",
  [ts_builtin_sym_end] = "END",
  [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = "/[\\^]{5}[\\^o]*/",
  [sym_escape_sequence] = "escape_sequence",
  [sym_integer] = "integer",
  [sym_float] = "float",
  [sym_identifier] = "identifier",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_none] = "none",
  [sym_module] = "module",
  [sym_doc_section] = "doc_section",
  [sym_section_title] = "section_title",
  [sym_section_body] = "section_body",
  [sym_string] = "string",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_doc_section_repeat1] = "doc_section_repeat1",
  [aux_sym_section_title_repeat1] = "section_title_repeat1",
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
  [aux_sym_doc_section_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_section_title_repeat1] = {
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
        SKIP(32);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(31);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == '\n')
        SKIP(31);
      if (lookahead == '\r')
        SKIP(33);
      END_STATE();
    case 33:
      if (lookahead == '\n')
        SKIP(31);
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
        ADVANCE(2);
      if (lookahead == '0')
        ADVANCE(10);
      if (lookahead == '\\')
        SKIP(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(37);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (913 <= lookahead && lookahead <= 937) ||
          (945 <= lookahead && lookahead <= 969))
        ADVANCE(30);
      END_STATE();
    case 38:
      if (lookahead == '\n')
        SKIP(37);
      if (lookahead == '\r')
        SKIP(39);
      END_STATE();
    case 39:
      if (lookahead == '\n')
        SKIP(37);
      END_STATE();
    case 40:
      if (lookahead == '\\')
        ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(40);
      END_STATE();
    case 41:
      if (lookahead == '\n')
        ADVANCE(42);
      if (lookahead == '\r')
        ADVANCE(43);
      if (lookahead == 'U')
        ADVANCE(44);
      if (lookahead == 'o')
        ADVANCE(52);
      if (lookahead == 'u')
        ADVANCE(48);
      if (lookahead == 'x')
        ADVANCE(50);
      if (lookahead != 0)
        ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n')
        ADVANCE(42);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(45);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(46);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(47);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(48);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(49);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(50);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(51);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f'))
        ADVANCE(42);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(53);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(54);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(42);
      END_STATE();
    case 55:
      if (lookahead == '\\')
        SKIP(56);
      if (lookahead == '^')
        ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279)
        SKIP(55);
      END_STATE();
    case 56:
      if (lookahead == '\n')
        SKIP(55);
      if (lookahead == '\r')
        SKIP(57);
      END_STATE();
    case 57:
      if (lookahead == '\n')
        SKIP(55);
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
  [2] = {.lex_state = 34},
  [3] = {.lex_state = 37, .external_lex_state = 2},
  [4] = {.lex_state = 31},
  [5] = {.lex_state = 31, .external_lex_state = 3},
  [6] = {.lex_state = 40, .external_lex_state = 4},
  [7] = {.lex_state = 34, .external_lex_state = 3},
  [8] = {.lex_state = 37, .external_lex_state = 2},
  [9] = {.lex_state = 31},
  [10] = {.lex_state = 55},
  [11] = {.lex_state = 31, .external_lex_state = 3},
  [12] = {.lex_state = 34, .external_lex_state = 3},
  [13] = {.lex_state = 40, .external_lex_state = 4},
  [14] = {.lex_state = 37, .external_lex_state = 2},
  [15] = {.lex_state = 37, .external_lex_state = 2},
  [16] = {.lex_state = 34, .external_lex_state = 3},
  [17] = {.lex_state = 34, .external_lex_state = 3},
  [18] = {.lex_state = 40, .external_lex_state = 4},
  [19] = {.lex_state = 37, .external_lex_state = 2},
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
    [ts_external_token__string_start] = true,
  },
  [3] = {
    [ts_external_token__newline] = true,
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
    [sym_module] = STATE(2),
    [sym_doc_section] = STATE(4),
    [sym_section_title] = STATE(3),
    [aux_sym_module_repeat1] = STATE(4),
    [aux_sym_section_title_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(6),
    [sym_identifier] = ACTIONS(8),
  },
  [2] = {
    [ts_builtin_sym_end] = ACTIONS(10),
  },
  [3] = {
    [sym_section_body] = STATE(8),
    [sym_string] = STATE(7),
    [aux_sym_doc_section_repeat1] = STATE(8),
    [sym__string_start] = ACTIONS(12),
    [sym_integer] = ACTIONS(14),
    [sym_float] = ACTIONS(16),
    [sym_identifier] = ACTIONS(16),
  },
  [4] = {
    [sym_doc_section] = STATE(9),
    [sym_section_title] = STATE(3),
    [aux_sym_module_repeat1] = STATE(9),
    [aux_sym_section_title_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(18),
    [sym_identifier] = ACTIONS(8),
  },
  [5] = {
    [aux_sym_section_title_repeat1] = STATE(11),
    [sym__newline] = ACTIONS(20),
    [sym_identifier] = ACTIONS(22),
  },
  [6] = {
    [aux_sym_string_repeat1] = STATE(13),
    [sym__string_content] = ACTIONS(24),
    [sym__string_end] = ACTIONS(26),
    [sym_escape_sequence] = ACTIONS(24),
  },
  [7] = {
    [sym__newline] = ACTIONS(28),
  },
  [8] = {
    [sym_section_body] = STATE(15),
    [sym_string] = STATE(7),
    [aux_sym_doc_section_repeat1] = STATE(15),
    [sym__string_start] = ACTIONS(12),
    [ts_builtin_sym_end] = ACTIONS(30),
    [sym_integer] = ACTIONS(14),
    [sym_float] = ACTIONS(16),
    [sym_identifier] = ACTIONS(30),
  },
  [9] = {
    [sym_doc_section] = STATE(9),
    [sym_section_title] = STATE(3),
    [aux_sym_module_repeat1] = STATE(9),
    [aux_sym_section_title_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(32),
    [sym_identifier] = ACTIONS(34),
  },
  [10] = {
    [aux_sym_SLASH_LBRACK_BSLASH_CARET_RBRACK_LBRACE5_RBRACE_LBRACK_BSLASH_CARETo_RBRACK_STAR_SLASH] = ACTIONS(37),
  },
  [11] = {
    [aux_sym_section_title_repeat1] = STATE(11),
    [sym__newline] = ACTIONS(39),
    [sym_identifier] = ACTIONS(41),
  },
  [12] = {
    [sym__newline] = ACTIONS(44),
  },
  [13] = {
    [aux_sym_string_repeat1] = STATE(18),
    [sym__string_content] = ACTIONS(46),
    [sym__string_end] = ACTIONS(48),
    [sym_escape_sequence] = ACTIONS(46),
  },
  [14] = {
    [sym__string_start] = ACTIONS(50),
    [ts_builtin_sym_end] = ACTIONS(50),
    [sym_integer] = ACTIONS(52),
    [sym_float] = ACTIONS(50),
    [sym_identifier] = ACTIONS(50),
  },
  [15] = {
    [sym_section_body] = STATE(15),
    [sym_string] = STATE(7),
    [aux_sym_doc_section_repeat1] = STATE(15),
    [sym__string_start] = ACTIONS(54),
    [ts_builtin_sym_end] = ACTIONS(57),
    [sym_integer] = ACTIONS(59),
    [sym_float] = ACTIONS(62),
    [sym_identifier] = ACTIONS(62),
  },
  [16] = {
    [sym__newline] = ACTIONS(65),
  },
  [17] = {
    [sym__newline] = ACTIONS(67),
  },
  [18] = {
    [aux_sym_string_repeat1] = STATE(18),
    [sym__string_content] = ACTIONS(69),
    [sym__string_end] = ACTIONS(72),
    [sym_escape_sequence] = ACTIONS(69),
  },
  [19] = {
    [sym__string_start] = ACTIONS(74),
    [sym_integer] = ACTIONS(76),
    [sym_float] = ACTIONS(74),
    [sym_identifier] = ACTIONS(74),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 0, .reusable = false},
  [2] = {.count = 1, .reusable = true}, RECOVER(),
  [4] = {.count = 1, .reusable = false}, RECOVER(),
  [6] = {.count = 1, .reusable = true}, REDUCE(sym_module, 0),
  [8] = {.count = 1, .reusable = true}, SHIFT(5),
  [10] = {.count = 1, .reusable = true}, ACCEPT_INPUT(),
  [12] = {.count = 1, .reusable = true}, SHIFT(6),
  [14] = {.count = 1, .reusable = false}, SHIFT(7),
  [16] = {.count = 1, .reusable = true}, SHIFT(7),
  [18] = {.count = 1, .reusable = true}, REDUCE(sym_module, 1),
  [20] = {.count = 1, .reusable = true}, SHIFT(10),
  [22] = {.count = 1, .reusable = true}, SHIFT(11),
  [24] = {.count = 1, .reusable = true}, SHIFT(13),
  [26] = {.count = 1, .reusable = true}, SHIFT(12),
  [28] = {.count = 1, .reusable = true}, SHIFT(14),
  [30] = {.count = 1, .reusable = true}, REDUCE(sym_doc_section, 2),
  [32] = {.count = 1, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2),
  [34] = {.count = 2, .reusable = true}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(5),
  [37] = {.count = 1, .reusable = true}, SHIFT(16),
  [39] = {.count = 1, .reusable = true}, REDUCE(aux_sym_section_title_repeat1, 2),
  [41] = {.count = 2, .reusable = true}, REDUCE(aux_sym_section_title_repeat1, 2), SHIFT_REPEAT(11),
  [44] = {.count = 1, .reusable = true}, REDUCE(sym_string, 2),
  [46] = {.count = 1, .reusable = true}, SHIFT(18),
  [48] = {.count = 1, .reusable = true}, SHIFT(17),
  [50] = {.count = 1, .reusable = true}, REDUCE(sym_section_body, 2),
  [52] = {.count = 1, .reusable = false}, REDUCE(sym_section_body, 2),
  [54] = {.count = 2, .reusable = true}, REDUCE(aux_sym_doc_section_repeat1, 2), SHIFT_REPEAT(6),
  [57] = {.count = 1, .reusable = true}, REDUCE(aux_sym_doc_section_repeat1, 2),
  [59] = {.count = 2, .reusable = false}, REDUCE(aux_sym_doc_section_repeat1, 2), SHIFT_REPEAT(7),
  [62] = {.count = 2, .reusable = true}, REDUCE(aux_sym_doc_section_repeat1, 2), SHIFT_REPEAT(7),
  [65] = {.count = 1, .reusable = true}, SHIFT(19),
  [67] = {.count = 1, .reusable = true}, REDUCE(sym_string, 3),
  [69] = {.count = 2, .reusable = true}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(18),
  [72] = {.count = 1, .reusable = true}, REDUCE(aux_sym_string_repeat1, 2),
  [74] = {.count = 1, .reusable = true}, REDUCE(sym_section_title, 4),
  [76] = {.count = 1, .reusable = false}, REDUCE(sym_section_title, 4),
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
