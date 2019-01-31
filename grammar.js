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
    module: $ => //seq(
      //optional($.doc_header),
      repeat($.doc_section)
      //)
      ,

    // Header        ::= (Title,(AuthorInfo,RevisionInfo?)?)
    // AuthorInfo    ::= (FirstName,(MiddleName?,LastName)?,EmailAddress?)
    // RevisionInfo  ::= (RevisionNumber?,RevisionDate,RevisionRemark?)
    // example:
    //   Writing Documentation using AsciiDoc
    //   ====================================
    //   Joe Bloggs <jbloggs@mymail.com>
    //   v2.0, February 2003:
    //   Rewritten for version 2 release.
    //doc_header: $ => seq(
    //    $.section_title
    //),

    // Section       ::= (Title,SectionBody?,(Section)*)
    // SectionBody   ::= ((BlockTitle?,Block)|BlockMacro)+
    // Block         ::= (Paragraph|DelimitedBlock|List|Table)
    doc_section: $ => seq(
      prec.left(2, $.section_title),
      prec.left(1, repeat1($.section_body))
    ),

    // Title ::= word+ , "^^^[\^o]*"
    // example:
    // Level One Section Title
    // ^^^^^^^^^^^^^^^^^^^^^^^^
    section_title: $ => prec(2, seq(
      repeat1($.identifier),
      $._newline,
      /[\^]{5}[\^o]*/,
      $._newline
    )),

    //

    section_body: $ =>
      repeat(body_item),

    body_item: $ =>
      choice(paragraph,
        delim_block
      ),

    // Transitions separate other body elements.
    // A transition should not begin or end a section or document, nor should two transitions be immediately adjacent.
    // The syntax for a transition marker is a horizontal line of 4 or more repeated punctuation characters.
    // The syntax is the same as section title underlines without title text. Transition markers require blank lines before and after
    // Unlike section title underlines, no hierarchy of transition markers is enforced, nor do differences in transition markers accomplish anything.
    // It is recommended that a single consistent style be used.
    transition: $ => /[-]{4,}/ ,

    // Paragraphs consist of blocks of left-aligned text with no markup indicating any other body element.
    // Blank lines separate paragraphs from each other and from other body elements.
    // Paragraphs may contain inline markup.
    paragraph: $ => ,

    delim_block: $ =>
      choice(
        //sidebar_block ,
        //comment_block,
        fenced_block,
        example_block,
        listing_block,
        //literal_block,
        //pass_block,
        //verse_block,
        //table_block,
        //anon_block
      ),

    fenced_block: $ =>

      ,

    example_block: $ =>

      ,

    // A text block which begins with a "*", "+", "-", "•", "‣", or "⁃", followed by whitespace, is a bullet list item (a.k.a. "unordered" list item).
    // List item bodies must be left-aligned and indented relative to the bullet;
    // the text immediately after the bullet determines the indentation.

    listing_block: $ =>

      ,

    // Enumerated lists (a.k.a. "ordered" lists) are similar to bullet lists, but use enumerators instead of bullets.
    // An enumerator consists of an enumeration sequence member and formatting, followed by whitespace.
    // The following enumeration sequences are recognized:
    //   - arabic numerals: 1, 2, 3, ... (no upper limit).
    //   - uppercase alphabet characters: A, B, C, ..., Z.
    //   - lower-case alphabet characters: a, b, c, ..., z.
    //   - uppercase Roman numerals: I, II, III, IV, ..., MMMMCMXCIX (4999).
    //   - lowercase Roman numerals: i, ii, iii, iv, ..., mmmmcmxcix (4999).
    // In addition, the auto-enumerator, "#", may be used to automatically enumerate a list.
    // Auto-enumerated lists may begin with explicit enumeration, which sets the sequence.
    // Fully auto-enumerated lists use arabic numerals and begin with 1. (Auto-enumerated lists are new in Docutils 0.3.8.)
    //
    // The following formatting types are recognized:
    //   - suffixed with a period: "1.", "A.", "a.", "I.", "i.".
    //   - surrounded by parentheses: "(1)", "(A)", "(a)", "(I)", "(i)".
    //   - suffixed with a right-parenthesis: "1)", "A)", "a)", "I)", "i)".
    //   - While parsing an enumerated list, a new list will be started whenever:
    //
    // An enumerator is encountered which does not have the same format and sequence type as the current list (e.g. "1.", "(a)" produces two separate lists).
    // The enumerators are not in sequence (e.g., "1.", "3." produces two separate lists).
    // It is recommended that the enumerator of the first list item be ordinal-1 ("1", "A", "a", "I", or "i").
    // Although other start-values will be recognized, they may not be supported by the output format.
    // A level-1 [info] system message will be generated for any list beginning with a non-ordinal-1 enumerator.
    //
    // Lists using Roman numerals must begin with "I"/"i" or a multi-character value, such as "II" or "XV".
    // Any other single-character Roman numeral ("V", "X", "L", "C", "D", "M") will be interpreted as a letter of the alphabet, not as a Roman numeral.
    // Likewise, lists using letters of the alphabet may not begin with "I"/"i", since these are recognized as Roman numeral 1.
    //
    // The second line of each enumerated list item is checked for validity.
    // This is to prevent ordinary paragraphs from being mistakenly interpreted as list items, when they happen to begin with text identical to enumerators.
    //
    // However, ambiguity cannot be avoided if the paragraph consists of only one line.
    // If a single-line paragraph begins with text identical to an enumerator ("A.", "1.", "(b)", "I)", etc.),
    // the first character will have to be escaped in order to have the line parsed as an ordinary paragraph

    // Directives have the following syntax:
    //
    // +-------+-------------------------------+
    // | ".. " | directive type "::" directive |
    // +-------+ block                         |
    //         |                               |
    //         +-------------------------------+
    // Directives begin with an explicit markup start (two periods and a space), followed by the directive type and two colons (collectively, the "directive marker").
    // The directive block begins immediately after the directive marker, and includes all subsequent indented lines.
    // The directive block is divided into arguments, options (a field list), and content (in that order), any of which may appear.
    
    indented_block: $ =>
       choice(
    ,

    // Admonitions are specially marked "topics" that can appear anywhere an ordinary body element can. They contain arbitrary body elements.
    // Directive Types:	"attention", "caution", "danger", "error", "hint", "important", "note", "tip", "warning", "admonition"
    // Any text immediately following the directive indicator (on the same line and/or indented on following lines) is interpreted as a directive block and is parsed for normal body elements.
    // .. note:: This is a note admonition.
    //    This is the second line of the first paragraph.
    //
    //    - The note contains all indented body elements
    //      following.
    //    - It includes this bullet list.

    // This is a generic, titled admonition. The title may be anything the author desires.
    //
    // The author-supplied title is also used as a "classes" attribute value after being converted into a valid identifier form (down-cased; non-alphanumeric characters converted to single hyphens; "admonition-" prefixed). For example, this admonition:
    //
    // .. admonition:: And, by the way...
    //
    //    You can make up your own admonition too.

    // Image Directive
    //
    // .. image:: picture.png
    // Inline images can be defined with an "image" directive in a substitution definition
    //
    // The URI for the image source file is specified in the directive argument. As with hyperlink targets, the image URI may begin on the same line as the explicit markup start and target name, or it may begin in an indented text block immediately following, with no intervening blank lines. If there are multiple lines in the link block, they are stripped of leading and trailing whitespace and joined together.
    //
    // Optionally, the image link block may contain a flat field list, the image options.

    // figure Directive
    // A "figure" consists of image data (including image options), an optional caption (a single paragraph), and an optional legend (arbitrary body elements).
    //
    // .. figure:: picture.png
    // :scale: 50 %
    // :alt: map to buried treasure
    //
    // This is the caption of the figure (a simple paragraph).
    //
    // The legend consists of all elements after the caption.  In this
    // case, the legend consists of this paragraph and the following
    // table:
    //
    // +-----------------------+-----------------------+
    // | Symbol                | Meaning               |
    // +=======================+=======================+
    // | .. image:: tent.png   | Campground            |
    // +-----------------------+-----------------------+
    // | .. image:: waves.png  | Lake                  |
    // +-----------------------+-----------------------+
    // | .. image:: peak.png   | Mountain              |
    // +-----------------------+-----------------------+

   // The "code" directive constructs a literal block.
   // For inline code, use the "code" role.
   // Example::
   // The content of the following directive
   //
   // .. code:: python
   //
   //   def my_function():
   //       "just a test"
   //       print 8/2
   // is parsed and marked up as Python source code.

   // The "math" directive inserts blocks with mathematical content (display formulas, equations) into the document. The input format is LaTeX math syntax[1] with support for Unicode symbols, for example:
   //
   // .. math::
   //
   //   α_t(i) = P(O_1, O_2, … O_t, q_t = S_i λ)
   //
   // For inline formulas, use the "math" role.

    // The "table" directive is used to associate a title with a table or specify options, e.g.:
    //
    // .. table:: Truth table for "not"
    //    :widths: auto
    //
    //    =====  =====
    //      A    not A
    //    =====  =====
    //    False  True
    //    True   False
    //    =====  =====

    // The "csv-table" directive is used to create a table from CSV (comma-separated values) data. CSV is a common data format generated by spreadsheet applications and commercial databases. The data may be internal (an integral part of the document) or external (a separate file).
    //
    // Example:
    //
    // .. csv-table:: Frozen Delights!
    //    :header: "Treat", "Quantity", "Description"
    //    :widths: 15, 10, 30
    //
    //    "Albatross", 2.99, "On a stick!"
    //    "Crunchy Frog", 1.49, "If we took the bones out, it wouldn't be
    //    crunchy, now would it?"
    //    "Gannet Ripple", 1.99, "On a stick!"
    // Block markup and inline markup within cells is supported. Line ends are recognized within cells.
    //

    // The "list-table" directive is used to create a table from data in a uniform two-level bullet list. "Uniform" means that each sublist (second-level list) must contain the same number of list items.
    //
    // Example:
    //
    // .. list-table:: Frozen Delights!
    //    :widths: 15 10 30
    //    :header-rows: 1
    //
    //    * - Treat
    //      - Quantity
    //      - Description
    //    * - Albatross
    //      - 2.99
    //      - On a stick!
    //    * - Crunchy Frog
    //      - 1.49
    //      - If we took the bones out, it wouldn't be
    //        crunchy, now would it?
    //    * - Gannet Ripple
    //      - 1.99
    //      - On a stick!

    

    //  seq(
    //    choice(
    //      $.identifier,
    //      $.string,
    //      $.integer,
    //      $.float
    //    ),
    //    $._newline
    //  ),

    // Literals
    // string, number, id

    string: $ => seq(
      alias($._string_start, '"'),
      repeat(choice( /*$.interpolation,*/ $.escape_sequence, $._string_content)),
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

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)))
}

function commaSep(rule) {
  return optional(commaSep1(rule))
}
