module.exports = grammar({
    name: 'mal',

  extras: $ => [
    //$.comment,
    /[\s\uFEFF\u2060\u200B]|\\\r?\n/
  ],

  externals: $ => [
    $._newline,
    $._indent,
    $._dedent,
    $._string_start,
    $._string_content,
    $._string_end,
  ],

  word: $ => $.identifier,

  rules: {

    // Document      ::= (Header?,Preamble?,Section*)
    module: $ => seq(
      optional($.doc_header),
      repeat($.doc_section)
    ),

    // Header        ::= (Title,(AuthorInfo,RevisionInfo?)?)
    // AuthorInfo    ::= (FirstName,(MiddleName?,LastName)?,EmailAddress?)
    // RevisionInfo  ::= (RevisionNumber?,RevisionDate,RevisionRemark?)
    // example:
    //   Writing Documentation using AsciiDoc
    //   ====================================
    //   Joe Bloggs <jbloggs@mymail.com>
    //   v2.0, February 2003:
    //   Rewritten for version 2 release.
    doc_header: $ => seq(
        $.section_title
    ),

    // Section       ::= (Title,SectionBody?,(Section)*)
    // SectionBody   ::= ((BlockTitle?,Block)|BlockMacro)+
    // Block         ::= (Paragraph|DelimitedBlock|List|Table)
    doc_section: $ => seq(
       $.section_title,
       $.section_body
    ),

    // Title ::= word+ , "^^^[\^o]*"
    // example:
    // Level One Section Title
    // ^^^^^^^^^^^^^^^^^^^^^^^^
    section_title: $ => seq(
      /[^\r\n]+/,$._newline,
      /[\^]{5}[\^o]*/,$._newline
    ),

    section_body: $ => repeat1(
        seq(
          choice(
            $.identifier,
            $.string,
            $.integer,
            $.float
          ),
          $._newline
        )
    ),

    // Literals
    // string, number, id

    string: $ => seq(
      alias($._string_start, '"'),
      repeat(choice(/*$.interpolation,*/ $.escape_sequence, $._string_content)),
      alias($._string_end, '"')
    ),

    escape_sequence: $ => token(seq(
      '\\',
      choice(
        /u[a-fA-F\d]{4}/,
        /U[a-fA-F\d]{8}/,
        /x[a-fA-F\d]{2}/,
        /o\d{3}/,
        /\r\n/,
        /[^uxo]/
      )
    )),
    integer: $ => token(choice(
      seq(
        choice('0x', '0X'),
        repeat1(/_?[A-Fa-f0-9]+/),
        optional(/[Ll]/)
      ),
      seq(
        choice('0o', '0O'),
        repeat1(/_?[0-7]+/),
        optional(/[Ll]/)
      ),
      seq(
        choice('0b', '0B'),
        repeat1(/_?[0-1]+/),
        optional(/[Ll]/)
      ),
      seq(
        repeat1(/[0-9]+_?/),
        choice(
          optional(/[Ll]/), // long numbers
          optional(/[jJ]/) // complex numbers
        )
      )
    )),

    float: $ => {
      const digits = repeat1(/[0-9]+_?/);
      const exponent = seq(/[eE][\+-]?/, digits)

      return token(seq(
        choice(
          seq(digits, '.', optional(digits), optional(exponent)),
          seq(optional(digits), '.', digits, optional(exponent)),
          seq(digits, exponent)
        ),
        optional(choice(/[Ll]/, /[jJ]/))
      ))
    },

    identifier: $ => /[a-zA-Zα-ωΑ-Ω_][a-zA-Zα-ωΑ-Ω_0-9]*/,

    //keyword_identifier: $ => alias(choice('print', 'exec'), $.identifier),

    true: $ => 'True',
    false: $ => 'False',
    none: $ => 'None',

  }
});
