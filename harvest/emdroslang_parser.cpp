/*
** 2000-05-29
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** Driver template for the LEMON parser generator.
**
** The "lemon" program processes an LALR(1) input grammar file, then uses
** this template to construct a parser.  The "lemon" program inserts text
** at each "%%" line.  Also, any "P-a-r-s-e" identifer prefix (without the
** interstitial "-" characters) contained in this template is changed into
** the value of the %name directive from the grammar.  Otherwise, the content
** of this template is copied straight through into the generate parser
** source file.
**
** The following is the concatenation of all %include directives from the
** input grammar file:
*/
#include <stdio.h>
#include <assert.h>
/************ Begin %include sections from the grammar ************************/
#line 1 "./emdroslang.yxx"


/*
 * emdroslang.yxx
 *
 * Emdros language parser
 *
 * Ulrik Sandborg-Petersen
 * Created: 11/11-2016
 * Last update: 5/22-2017
 *
 */

/*
 * Copyright (C) 2001-2018     Ulrik Sandborg-Petersen
 * Copyright (C) 2018-present  Sandborg-Petersen Holding ApS, Denmark
 *
 * Licensed under the MIT License.
 *
 * Please see the file COPYING in the root of the sources for more details.
 *
 */



#include "emdroslang_classes.h"
#include "json_classes.h"
#include "mql_enums.h"
#include "mql_yylex.h"

#include <cstdlib>
#include <string>
#include <cassert>

#undef TOKEN

#line 66 "./emdroslang.c"
/**************** End of %include directives **********************************/
/* These constants specify the various numeric values for terminal symbols
** in a format understandable to "makeheaders".  This section is blank unless
** "lemon" is run with the "-m" command-line option.
***************** Begin makeheaders token definitions *************************/
/**************** End makeheaders token definitions ***************************/

/* The next sections is a series of control #defines.
** various aspects of the generated parser.
**    TMPLGYYCODETYPE         is the data type used to store the integer codes
**                       that represent terminal and non-terminal symbols.
**                       "unsigned char" is used if there are fewer than
**                       256 symbols.  Larger types otherwise.
**    TMPLGYYNOCODE           is a number of type TMPLGYYCODETYPE that is not used for
**                       any terminal or nonterminal symbol.
**    TMPLGYYFALLBACK         If defined, this indicates that one or more tokens
**                       (also known as: "terminal symbols") have fall-back
**                       values which should be used if the original symbol
**                       would not parse.  This permits keywords to sometimes
**                       be used as identifiers, for example.
**    TMPLGYYACTIONTYPE       is the data type used for "action codes" - numbers
**                       that indicate what to do in response to the next
**                       token.
**    EmdroslangParserTOKENTYPE     is the data type used for minor type for terminal
**                       symbols.  Background: A "minor type" is a semantic
**                       value associated with a terminal or non-terminal
**                       symbols.  For example, for an "ID" terminal symbol,
**                       the minor type might be the name of the identifier.
**                       Each non-terminal can have a different minor type.
**                       Terminal symbols all have the same minor type, though.
**                       This macros defines the minor type for terminal 
**                       symbols.
**    TMPLGYYMINORTYPE        is the data type used for all minor types.
**                       This is typically a union of many types, one of
**                       which is EmdroslangParserTOKENTYPE.  The entry in the union
**                       for terminal symbols is called "tmplgyy0".
**    TMPLGYYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    EmdroslangParserARG_SDECL     A static variable declaration for the %extra_argument
**    EmdroslangParserARG_PDECL     A parameter declaration for the %extra_argument
**    EmdroslangParserARG_PARAM     Code to pass %extra_argument as a subroutine parameter
**    EmdroslangParserARG_STORE     Code to store %extra_argument into tmplgyypParser
**    EmdroslangParserARG_FETCH     Code to extract %extra_argument from tmplgyypParser
**    EmdroslangParserCTX_*         As EmdroslangParserARG_ except for %extra_context
**    TMPLGYYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
**    TMPLGYYNSTATE           the combined number of states.
**    TMPLGYYNRULE            the number of rules in the grammar
**    TMPLGYYNTOKEN           Number of terminal symbols
**    TMPLGYY_MAX_SHIFT       Maximum value for shift actions
**    TMPLGYY_MIN_SHIFTREDUCE Minimum value for shift-reduce actions
**    TMPLGYY_MAX_SHIFTREDUCE Maximum value for shift-reduce actions
**    TMPLGYY_ERROR_ACTION    The tmplgyy_action[] code for syntax error
**    TMPLGYY_ACCEPT_ACTION   The tmplgyy_action[] code for accept
**    TMPLGYY_NO_ACTION       The tmplgyy_action[] code for no-op
**    TMPLGYY_MIN_REDUCE      Minimum value for reduce actions
**    TMPLGYY_MAX_REDUCE      Maximum value for reduce actions
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/************* Begin control #defines *****************************************/
#define TMPLGYYCODETYPE unsigned char
#define TMPLGYYNOCODE 102
#define TMPLGYYACTIONTYPE unsigned short int
#define EmdroslangParserTOKENTYPE Token*
typedef union {
  int tmplgyyinit;
  EmdroslangParserTOKENTYPE tmplgyy0;
  ELCompilationUnitPart* tmplgyy70;
  ELStylesheet* tmplgyy78;
  JSONValue* tmplgyy90;
  ELStatement* tmplgyy137;
  ELFunctionSignature* tmplgyy148;
  eELOperation tmplgyy149;
  ELParameterName* tmplgyy154;
  ELExpression* tmplgyy156;
  JSONListElement* tmplgyy159;
  JSONKeyValuePair* tmplgyy163;
  ELFullyQualifiedFunctionName* tmplgyy167;
  ELFunctionDef* tmplgyy169;
} TMPLGYYMINORTYPE;
#ifndef TMPLGYYSTACKDEPTH
#define TMPLGYYSTACKDEPTH 100
#endif
#define EmdroslangParserARG_SDECL EmdroslangExecEnv *pEE;
#define EmdroslangParserARG_PDECL ,EmdroslangExecEnv *pEE
#define EmdroslangParserARG_PARAM ,pEE
#define EmdroslangParserARG_FETCH EmdroslangExecEnv *pEE=tmplgyypParser->pEE;
#define EmdroslangParserARG_STORE tmplgyypParser->pEE=pEE;
#define EmdroslangParserCTX_SDECL
#define EmdroslangParserCTX_PDECL
#define EmdroslangParserCTX_PARAM
#define EmdroslangParserCTX_FETCH
#define EmdroslangParserCTX_STORE
#define TMPLGYYNSTATE             103
#define TMPLGYYNRULE              108
#define TMPLGYYNRULE_WITH_ACTION  107
#define TMPLGYYNTOKEN             46
#define TMPLGYY_MAX_SHIFT         102
#define TMPLGYY_MIN_SHIFTREDUCE   183
#define TMPLGYY_MAX_SHIFTREDUCE   290
#define TMPLGYY_ERROR_ACTION      291
#define TMPLGYY_ACCEPT_ACTION     292
#define TMPLGYY_NO_ACTION         293
#define TMPLGYY_MIN_REDUCE        294
#define TMPLGYY_MAX_REDUCE        401
/************* End control #defines *******************************************/
#define TMPLGYY_NLOOKAHEAD ((int)(sizeof(tmplgyy_lookahead)/sizeof(tmplgyy_lookahead[0])))

/* Define the tmplgyytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define tmplgyytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the tmplgyytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef tmplgyytestcase
# define tmplgyytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N <= TMPLGYY_MAX_SHIFT             Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   N between TMPLGYY_MIN_SHIFTREDUCE       Shift to an arbitrary state then
**     and TMPLGYY_MAX_SHIFTREDUCE           reduce by rule N-TMPLGYY_MIN_SHIFTREDUCE.
**
**   N == TMPLGYY_ERROR_ACTION               A syntax error has occurred.
**
**   N == TMPLGYY_ACCEPT_ACTION              The parser accepts its input.
**
**   N == TMPLGYY_NO_ACTION                  No such action.  Denotes unused
**                                      slots in the tmplgyy_action[] table.
**
**   N between TMPLGYY_MIN_REDUCE            Reduce by rule N-TMPLGYY_MIN_REDUCE
**     and TMPLGYY_MAX_REDUCE
**
** The action table is constructed as a single large table named tmplgyy_action[].
** Given state S and lookahead X, the action is computed as either:
**
**    (A)   N = tmplgyy_action[ tmplgyy_shift_ofst[S] + X ]
**    (B)   N = tmplgyy_default[S]
**
** The (A) formula is preferred.  The B formula is used instead if
** tmplgyy_lookahead[tmplgyy_shift_ofst[S]+X] is not equal to X.
**
** The formulas above are for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the tmplgyy_reduce_ofst[] array is used in place of
** the tmplgyy_shift_ofst[] array.
**
** The following are the tables generated in this section:
**
**  tmplgyy_action[]        A single table containing all actions.
**  tmplgyy_lookahead[]     A table containing the lookahead for each entry in
**                     tmplgyy_action.  Used to detect hash collisions.
**  tmplgyy_shift_ofst[]    For each state, the offset into tmplgyy_action for
**                     shifting terminals.
**  tmplgyy_reduce_ofst[]   For each state, the offset into tmplgyy_action for
**                     shifting non-terminals after a reduce.
**  tmplgyy_default[]       Default action for each state.
**
*********** Begin parsing tables **********************************************/
#define TMPLGYY_ACTTAB_COUNT (488)
static const TMPLGYYACTIONTYPE tmplgyy_action[] = {
 /*     0 */   310,  369,  311,   75,  217,  188,  189,   92,  331,    6,
 /*    10 */   334,  335,  253,  339,  340,  341,  342,  343,  344,  345,
 /*    20 */   346,   44,  360,   84,   36,   83,  310,  369,  311,   57,
 /*    30 */   310,  315,  311,   68,  365,  366,  367,   89,   87,   41,
 /*    40 */    65,    5,   53,  380,  384,   73,   74,  398,  310,  369,
 /*    50 */   311,   32,  243,   68,   66,   57,   53,  380,  384,   99,
 /*    60 */   365,  366,  367,   89,   87,   41,   65,   29,   53,  380,
 /*    70 */   384,   32,  243,  400,   82,   17,   79,   63,   77,   54,
 /*    80 */   380,  384,  365,  366,  367,   89,   87,   41,   65,   75,
 /*    90 */    53,  380,  384,   85,   76,    6,  334,  335,   30,  339,
 /*   100 */   340,  341,  342,  343,  344,  345,  346,   75,   45,   84,
 /*   110 */    36,   83,  333,    6,  334,  335,   27,  339,  340,  341,
 /*   120 */   342,  343,  344,  345,  346,  383,  384,   84,   75,   83,
 /*   130 */   382,  384,  310,  369,  311,  336,  327,  361,  339,  340,
 /*   140 */   341,  342,  349,   91,  310,  369,  311,    3,   84,    4,
 /*   150 */    83,  295,  296,  297,  102,    4,  310,  369,  311,  381,
 /*   160 */   384,   56,  241,   48,   14,   69,  365,  366,  367,   89,
 /*   170 */    87,   41,   65,   58,   53,  380,  384,   72,  365,  366,
 /*   180 */   367,   89,   87,   41,   65,   59,   53,  380,  384,   47,
 /*   190 */   365,  366,  367,   89,   87,   41,   65,   75,   53,  380,
 /*   200 */   384,  310,  369,  311,  336,   20,  363,  339,  340,  341,
 /*   210 */   342,   75,    4,  310,  369,  311,   19,   84,  336,   83,
 /*   220 */    37,  339,  340,  341,  342,  310,  369,  311,    4,  358,
 /*   230 */    60,   84,   21,   83,   78,  365,  366,  367,   89,   87,
 /*   240 */    41,   65,   61,   53,  380,  384,   14,  365,  366,  367,
 /*   250 */    89,   87,   41,   65,   62,   53,  380,  384,  385,  365,
 /*   260 */   366,  367,   89,   87,   41,   65,    2,   53,  380,  384,
 /*   270 */   310,  369,  311,   13,    4,  193,  194,  195,   98,  197,
 /*   280 */   198,   40,  310,  369,  311,   26,  319,  292,   23,  294,
 /*   290 */   296,  297,  102,    4,  310,  369,  311,   16,  190,   86,
 /*   300 */   303,   48,  314,  100,  365,  366,  367,   89,   87,   41,
 /*   310 */    65,   64,   53,  380,  384,   40,  365,  366,  367,   89,
 /*   320 */    87,   41,   65,   90,   53,  380,  384,   49,  365,  366,
 /*   330 */   367,   89,   87,   41,   65,   75,   53,  380,  384,  101,
 /*   340 */   100,  357,  334,  335,   38,  339,  340,  341,  342,  343,
 /*   350 */   344,  345,  346,  236,  298,   84,    4,   83,   75,  401,
 /*   360 */   245,  188,  189,    4,   81,  334,  335,   18,  339,  340,
 /*   370 */   341,  342,  343,  344,  345,  346,   75,   44,   84,   50,
 /*   380 */    83,    4,  355,  334,  335,  275,  339,  340,  341,  342,
 /*   390 */   343,  344,  345,  346,   51,   95,   84,  259,   83,  193,
 /*   400 */   194,  195,   98,  197,  198,   40,   68,   95,   43,   26,
 /*   410 */   364,  209,   14,    9,   31,  226,   88,   41,   65,  285,
 /*   420 */    53,  380,  384,  227,   32,  243,    7,   82,   17,   79,
 /*   430 */     1,   77,   55,  380,  384,    8,   46,   47,  276,  277,
 /*   440 */   280,  281,  278,  279,   42,   65,   10,   53,  380,  384,
 /*   450 */    80,  310,   96,  311,   11,  242,  318,  310,   96,  311,
 /*   460 */    12,    4,   97,   71,   70,  326,  282,   67,  348,   91,
 /*   470 */    35,   34,   33,   24,   22,   15,  218,  210,   93,   94,
 /*   480 */    25,  205,  196,   28,   39,   52,  293,  201,
};
static const TMPLGYYCODETYPE tmplgyy_lookahead[] = {
 /*     0 */    54,   55,   56,   62,    4,    2,    3,   66,   67,   68,
 /*    10 */    69,   70,    4,   72,   73,   74,   75,   76,   77,   78,
 /*    20 */    79,   18,   85,   82,   87,   84,   54,   55,   56,   83,
 /*    30 */    54,   55,   56,    4,   88,   89,   90,   91,   92,   93,
 /*    40 */    94,   12,   96,   97,   98,   30,  100,  101,   54,   55,
 /*    50 */    56,   22,   23,    4,   94,   83,   96,   97,   98,   11,
 /*    60 */    88,   89,   90,   91,   92,   93,   94,    9,   96,   97,
 /*    70 */    98,   22,   23,  101,   25,   26,   27,   83,   29,   96,
 /*    80 */    97,   98,   88,   89,   90,   91,   92,   93,   94,   62,
 /*    90 */    96,   97,   98,   99,   67,   68,   69,   70,   40,   72,
 /*   100 */    73,   74,   75,   76,   77,   78,   79,   62,   85,   82,
 /*   110 */    87,   84,   67,   68,   69,   70,   95,   72,   73,   74,
 /*   120 */    75,   76,   77,   78,   79,   97,   98,   82,   62,   84,
 /*   130 */    97,   98,   54,   55,   56,   69,   65,   71,   72,   73,
 /*   140 */    74,   75,   81,   82,   54,   55,   56,   14,   82,   16,
 /*   150 */    84,   48,   49,   50,   51,   16,   54,   55,   56,   97,
 /*   160 */    98,   83,   23,   60,   19,    4,   88,   89,   90,   91,
 /*   170 */    92,   93,   94,   83,   96,   97,   98,   62,   88,   89,
 /*   180 */    90,   91,   92,   93,   94,   83,   96,   97,   98,   44,
 /*   190 */    88,   89,   90,   91,   92,   93,   94,   62,   96,   97,
 /*   200 */    98,   54,   55,   56,   69,   31,   71,   72,   73,   74,
 /*   210 */    75,   62,   16,   54,   55,   56,   20,   82,   69,   84,
 /*   220 */    71,   72,   73,   74,   75,   54,   55,   56,   16,   86,
 /*   230 */    83,   82,   20,   84,   82,   88,   89,   90,   91,   92,
 /*   240 */    93,   94,   83,   96,   97,   98,   19,   88,   89,   90,
 /*   250 */    91,   92,   93,   94,   83,   96,   97,   98,   98,   88,
 /*   260 */    89,   90,   91,   92,   93,   94,   12,   96,   97,   98,
 /*   270 */    54,   55,   56,   15,   16,    6,    7,    8,    9,   10,
 /*   280 */    11,   12,   54,   55,   56,   16,   61,   46,   47,   48,
 /*   290 */    49,   50,   51,   16,   54,   55,   56,   20,    4,   83,
 /*   300 */    52,   60,   57,   58,   88,   89,   90,   91,   92,   93,
 /*   310 */    94,   83,   96,   97,   98,   12,   88,   89,   90,   91,
 /*   320 */    92,   93,   94,   83,   96,   97,   98,    5,   88,   89,
 /*   330 */    90,   91,   92,   93,   94,   62,   96,   97,   98,   57,
 /*   340 */    58,   68,   69,   70,   14,   72,   73,   74,   75,   76,
 /*   350 */    77,   78,   79,   23,   54,   82,   16,   84,   62,    0,
 /*   360 */    20,    2,    3,   16,   68,   69,   70,   20,   72,   73,
 /*   370 */    74,   75,   76,   77,   78,   79,   62,   18,   82,   53,
 /*   380 */    84,   16,   68,   69,   70,   20,   72,   73,   74,   75,
 /*   390 */    76,   77,   78,   79,   52,   21,   82,    4,   84,    6,
 /*   400 */     7,    8,    9,   10,   11,   12,    4,   21,   14,   16,
 /*   410 */    24,   20,   19,   28,   19,   13,   92,   93,   94,   20,
 /*   420 */    96,   97,   98,   13,   22,   23,   19,   25,   26,   27,
 /*   430 */    19,   29,   96,   97,   98,   19,   19,   44,   34,   35,
 /*   440 */    36,   37,   38,   39,   93,   94,   19,   96,   97,   98,
 /*   450 */    25,   54,   55,   56,   19,   23,   59,   54,   55,   56,
 /*   460 */    24,   16,   59,   63,   64,   65,   45,   80,   81,   82,
 /*   470 */    41,   42,   43,   33,   32,   24,   13,    4,   21,    4,
 /*   480 */    14,   17,   10,   15,   14,    1,  102,   13,  102,  102,
 /*   490 */   102,  102,  102,  102,  102,  102,  102,  102,  102,  102,
 /*   500 */   102,  102,  102,  102,  102,  102,  102,  102,  102,  102,
 /*   510 */   102,  102,  102,  102,  102,  102,  102,  102,  102,  102,
 /*   520 */   102,  102,  102,  102,  102,  102,  102,  102,  102,  102,
 /*   530 */   102,  102,  102,  102,
};
#define TMPLGYY_SHIFT_COUNT    (102)
#define TMPLGYY_SHIFT_MIN      (0)
#define TMPLGYY_SHIFT_MAX      (484)
static const unsigned short int tmplgyy_shift_ofst[] = {
 /*     0 */     3,  393,   49,  393,  393,  402,   49,  393,  393,  393,
 /*    10 */   393,  393,  393,  393,  393,  393,   49,   49,   49,   29,
 /*    20 */    29,   29,  145,  359,  145,  269,  269,  145,  269,  145,
 /*    30 */   145,    0,    8,  145,  145,  145,   15,   15,    8,   48,
 /*    40 */    48,  404,  404,    0,  161,  174,    8,  227,  254,  294,
 /*    50 */   303,  322,  294,  429,  429,  429,  196,  133,  212,  277,
 /*    60 */   340,  347,  139,  258,  365,   58,   58,  330,  386,  374,
 /*    70 */   394,  391,  395,  407,  399,  411,  410,  416,  385,  417,
 /*    80 */   427,  425,  435,  432,  436,  421,  445,  440,  440,  442,
 /*    90 */   445,  451,  463,  473,  457,  475,  466,  464,  472,  468,
 /*   100 */   470,  474,  484,
};
#define TMPLGYY_REDUCE_COUNT (52)
#define TMPLGYY_REDUCE_MIN   (-63)
#define TMPLGYY_REDUCE_MAX   (403)
static const short tmplgyy_reduce_ofst[] = {
 /*     0 */   241,  -54,  -59,  -28,   -6,   27,   45,   78,   90,  102,
 /*    10 */   147,  159,  171,  216,  228,  240,  273,  296,  314,   66,
 /*    20 */   135,  149,  324,  103,  351,  397,  403,  -40,  -24,  -17,
 /*    30 */   336,  400,  387,   28,   33,   62,  -63,   23,   61,  245,
 /*    40 */   282,   21,   21,   71,  115,  143,  152,  160,  225,  248,
 /*    50 */   300,  326,  342,
};
static const TMPLGYYACTIONTYPE tmplgyy_default[] = {
 /*     0 */   291,  397,  330,  291,  291,  291,  332,  291,  291,  291,
 /*    10 */   291,  291,  291,  291,  291,  291,  291,  291,  291,  291,
 /*    20 */   291,  291,  291,  291,  291,  291,  291,  291,  291,  291,
 /*    30 */   291,  324,  291,  291,  291,  291,  359,  359,  291,  291,
 /*    40 */   291,  373,  374,  291,  291,  362,  291,  291,  291,  291,
 /*    50 */   291,  302,  291,  377,  379,  378,  291,  399,  291,  291,
 /*    60 */   291,  291,  291,  394,  291,  375,  376,  291,  323,  323,
 /*    70 */   325,  291,  291,  291,  291,  291,  291,  291,  291,  291,
 /*    80 */   291,  291,  291,  291,  291,  291,  395,  371,  372,  368,
 /*    90 */   351,  350,  291,  291,  322,  291,  317,  291,  291,  291,
 /*   100 */   313,  291,  291,
};
/********** End of lemon-generated parsing tables *****************************/

/* The next table maps tokens (terminal symbols) into fallback tokens.  
** If a construct like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
**
** This feature can be used, for example, to cause some keywords in a language
** to revert to identifiers if they keyword does not apply in the context where
** it appears.
*/
#ifdef TMPLGYYFALLBACK
static const TMPLGYYCODETYPE tmplgyyFallback[] = {
};
#endif /* TMPLGYYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
**
** After the "shift" half of a SHIFTREDUCE action, the stateno field
** actually contains the reduce action for the second half of the
** SHIFTREDUCE.
*/
struct tmplgyyStackEntry {
  TMPLGYYACTIONTYPE stateno;  /* The state-number, or reduce action in SHIFTREDUCE */
  TMPLGYYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  TMPLGYYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct tmplgyyStackEntry tmplgyyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct tmplgyyParser {
  tmplgyyStackEntry *tmplgyytos;          /* Pointer to top element of the stack */
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
  int tmplgyyhwm;                    /* High-water mark of the stack */
#endif
#ifndef TMPLGYYNOERRORRECOVERY
  int tmplgyyerrcnt;                 /* Shifts left before out of the error */
#endif
  EmdroslangParserARG_SDECL                /* A place to hold %extra_argument */
  EmdroslangParserCTX_SDECL                /* A place to hold %extra_context */
#if TMPLGYYSTACKDEPTH<=0
  int tmplgyystksz;                  /* Current side of the stack */
  tmplgyyStackEntry *tmplgyystack;        /* The parser's stack */
  tmplgyyStackEntry tmplgyystk0;          /* First stack entry */
#else
  tmplgyyStackEntry tmplgyystack[TMPLGYYSTACKDEPTH];  /* The parser's stack */
  tmplgyyStackEntry *tmplgyystackEnd;            /* Last entry in the stack */
#endif
};
typedef struct tmplgyyParser tmplgyyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *tmplgyyTraceFILE = 0;
static char *tmplgyyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void EmdroslangParserTrace(FILE *TraceFILE, char *zTracePrompt){
  tmplgyyTraceFILE = TraceFILE;
  tmplgyyTracePrompt = zTracePrompt;
  if( tmplgyyTraceFILE==0 ) tmplgyyTracePrompt = 0;
  else if( tmplgyyTracePrompt==0 ) tmplgyyTraceFILE = 0;
}
#endif /* NDEBUG */

#if defined(TMPLGYYCOVERAGE) || !defined(NDEBUG)
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const tmplgyyTokenName[] = { 
  /*    0 */ "$",
  /*    1 */ "KEY_STYLESHEET",
  /*    2 */ "KEY_FETCHINFO",
  /*    3 */ "KEY_XMLRENDERINFO",
  /*    4 */ "IDENTIFIER",
  /*    5 */ "KEY_EXTENDS",
  /*    6 */ "KEY_NULL",
  /*    7 */ "KEY_FALSE",
  /*    8 */ "KEY_TRUE",
  /*    9 */ "KEY_MINUS",
  /*   10 */ "INTEGER",
  /*   11 */ "STRING",
  /*   12 */ "KEY_LBRACE",
  /*   13 */ "KEY_RBRACE",
  /*   14 */ "KEY_COMMA",
  /*   15 */ "KEY_COLON",
  /*   16 */ "KEY_LSQUARE_BRACKET",
  /*   17 */ "KEY_RSQARE_BRACKET",
  /*   18 */ "KEY_FUNCTION",
  /*   19 */ "KEY_LPAREN",
  /*   20 */ "KEY_RPAREN",
  /*   21 */ "KEY_COLON_COLON",
  /*   22 */ "KEY_VAR",
  /*   23 */ "KEY_SEMICOLON",
  /*   24 */ "KEY_ASSIGN",
  /*   25 */ "KEY_WHILE",
  /*   26 */ "KEY_DO",
  /*   27 */ "KEY_FOR",
  /*   28 */ "KEY_IN",
  /*   29 */ "KEY_IF",
  /*   30 */ "KEY_ELIF",
  /*   31 */ "KEY_ELSE",
  /*   32 */ "KEY_AND_AND",
  /*   33 */ "KEY_PIPE_PIPE",
  /*   34 */ "KEY_EQEQ",
  /*   35 */ "KEY_NEQ",
  /*   36 */ "KEY_GT",
  /*   37 */ "KEY_GEQ",
  /*   38 */ "KEY_LT",
  /*   39 */ "KEY_LEQ",
  /*   40 */ "KEY_PLUS",
  /*   41 */ "KEY_STAR",
  /*   42 */ "KEY_SLASH",
  /*   43 */ "KEY_PERCENT",
  /*   44 */ "KEY_NOT",
  /*   45 */ "KEY_RSQUARE_BRACKET",
  /*   46 */ "top_value",
  /*   47 */ "compilation_unit",
  /*   48 */ "compilation_unit_part",
  /*   49 */ "stylesheet",
  /*   50 */ "function_def",
  /*   51 */ "stylesheet_kind",
  /*   52 */ "stylesheet_name",
  /*   53 */ "opt_extends",
  /*   54 */ "json_object",
  /*   55 */ "json_value",
  /*   56 */ "json_list",
  /*   57 */ "json_object_key_value_list",
  /*   58 */ "json_object_key_value_pair",
  /*   59 */ "json_value_list",
  /*   60 */ "function_signature",
  /*   61 */ "function_body",
  /*   62 */ "fully_qualified_function_name",
  /*   63 */ "opt_formal_parameter_list",
  /*   64 */ "formal_parameter_list",
  /*   65 */ "formal_parameter_name",
  /*   66 */ "opt_statement_list",
  /*   67 */ "statement_list",
  /*   68 */ "statement",
  /*   69 */ "simple_statement",
  /*   70 */ "compound_statement",
  /*   71 */ "suite",
  /*   72 */ "var_decl_statement",
  /*   73 */ "assignment_statement",
  /*   74 */ "function_call_statement",
  /*   75 */ "noop_statement",
  /*   76 */ "while_statement",
  /*   77 */ "do_while_statement",
  /*   78 */ "for_statement",
  /*   79 */ "if_statement",
  /*   80 */ "var_decl_list",
  /*   81 */ "var_decl",
  /*   82 */ "var_name",
  /*   83 */ "expression",
  /*   84 */ "function_call_expression",
  /*   85 */ "opt_elif_list",
  /*   86 */ "opt_else_part",
  /*   87 */ "elif_part",
  /*   88 */ "literal_expression",
  /*   89 */ "varname_expression",
  /*   90 */ "lookup_expression",
  /*   91 */ "expression1",
  /*   92 */ "expression2",
  /*   93 */ "expression3",
  /*   94 */ "expression4",
  /*   95 */ "comparison_op",
  /*   96 */ "expression5",
  /*   97 */ "expression6",
  /*   98 */ "expression7",
  /*   99 */ "lookup_index",
  /*  100 */ "opt_actual_parameter_list",
  /*  101 */ "actual_parameter_list",
};
#endif /* defined(TMPLGYYCOVERAGE) || !defined(NDEBUG) */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const tmplgyyRuleName[] = {
 /*   0 */ "compilation_unit ::= compilation_unit_part",
 /*   1 */ "compilation_unit ::= compilation_unit compilation_unit_part",
 /*   2 */ "compilation_unit_part ::= stylesheet",
 /*   3 */ "compilation_unit_part ::= function_def",
 /*   4 */ "stylesheet ::= stylesheet_kind KEY_STYLESHEET stylesheet_name opt_extends json_object",
 /*   5 */ "stylesheet_kind ::= KEY_FETCHINFO",
 /*   6 */ "stylesheet_kind ::= KEY_XMLRENDERINFO",
 /*   7 */ "stylesheet_name ::= IDENTIFIER",
 /*   8 */ "opt_extends ::=",
 /*   9 */ "opt_extends ::= KEY_EXTENDS stylesheet_name",
 /*  10 */ "json_value ::= KEY_NULL",
 /*  11 */ "json_value ::= KEY_FALSE",
 /*  12 */ "json_value ::= KEY_TRUE",
 /*  13 */ "json_value ::= KEY_MINUS INTEGER",
 /*  14 */ "json_value ::= INTEGER",
 /*  15 */ "json_value ::= STRING",
 /*  16 */ "json_value ::= json_object",
 /*  17 */ "json_value ::= json_list",
 /*  18 */ "json_object ::= KEY_LBRACE json_object_key_value_list KEY_RBRACE",
 /*  19 */ "json_object_key_value_list ::= json_object_key_value_pair",
 /*  20 */ "json_object_key_value_list ::= json_object_key_value_pair KEY_COMMA json_object_key_value_list",
 /*  21 */ "json_object_key_value_pair ::= STRING KEY_COLON json_value",
 /*  22 */ "json_list ::= KEY_LSQUARE_BRACKET json_value_list KEY_RSQARE_BRACKET",
 /*  23 */ "json_value_list ::= json_value",
 /*  24 */ "json_value_list ::= json_value KEY_COMMA json_value_list",
 /*  25 */ "function_def ::= function_signature function_body",
 /*  26 */ "function_signature ::= KEY_FUNCTION fully_qualified_function_name KEY_LPAREN opt_formal_parameter_list KEY_RPAREN",
 /*  27 */ "fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER KEY_COLON_COLON IDENTIFIER",
 /*  28 */ "fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER",
 /*  29 */ "fully_qualified_function_name ::= IDENTIFIER",
 /*  30 */ "opt_formal_parameter_list ::=",
 /*  31 */ "opt_formal_parameter_list ::= formal_parameter_list",
 /*  32 */ "formal_parameter_list ::= formal_parameter_name",
 /*  33 */ "formal_parameter_list ::= formal_parameter_list KEY_COMMA formal_parameter_name",
 /*  34 */ "formal_parameter_name ::= IDENTIFIER",
 /*  35 */ "function_body ::= KEY_LBRACE opt_statement_list KEY_RBRACE",
 /*  36 */ "opt_statement_list ::=",
 /*  37 */ "opt_statement_list ::= statement_list",
 /*  38 */ "statement_list ::= statement",
 /*  39 */ "statement_list ::= statement statement_list",
 /*  40 */ "statement ::= simple_statement",
 /*  41 */ "statement ::= compound_statement",
 /*  42 */ "suite ::= simple_statement",
 /*  43 */ "suite ::= KEY_LBRACE KEY_RBRACE",
 /*  44 */ "suite ::= KEY_LBRACE statement_list KEY_RBRACE",
 /*  45 */ "simple_statement ::= var_decl_statement",
 /*  46 */ "simple_statement ::= assignment_statement",
 /*  47 */ "simple_statement ::= function_call_statement",
 /*  48 */ "simple_statement ::= noop_statement",
 /*  49 */ "compound_statement ::= while_statement",
 /*  50 */ "compound_statement ::= do_while_statement",
 /*  51 */ "compound_statement ::= for_statement",
 /*  52 */ "compound_statement ::= if_statement",
 /*  53 */ "var_decl_statement ::= KEY_VAR var_decl_list KEY_SEMICOLON",
 /*  54 */ "var_decl_list ::= var_decl",
 /*  55 */ "var_decl_list ::= var_decl_list KEY_COMMA var_decl",
 /*  56 */ "var_decl ::= var_name",
 /*  57 */ "var_decl ::= var_name KEY_ASSIGN expression",
 /*  58 */ "assignment_statement ::= var_name KEY_ASSIGN expression KEY_SEMICOLON",
 /*  59 */ "function_call_statement ::= function_call_expression KEY_SEMICOLON",
 /*  60 */ "noop_statement ::= KEY_SEMICOLON",
 /*  61 */ "while_statement ::= KEY_WHILE KEY_LPAREN expression KEY_RPAREN statement",
 /*  62 */ "do_while_statement ::= KEY_DO statement KEY_WHILE KEY_LPAREN expression KEY_RPAREN",
 /*  63 */ "for_statement ::= KEY_FOR KEY_LPAREN var_name KEY_IN expression KEY_RPAREN statement",
 /*  64 */ "if_statement ::= KEY_IF KEY_LPAREN expression KEY_RPAREN suite opt_elif_list opt_else_part",
 /*  65 */ "opt_elif_list ::=",
 /*  66 */ "opt_elif_list ::= elif_part opt_elif_list",
 /*  67 */ "elif_part ::= KEY_ELIF KEY_LPAREN expression KEY_RPAREN suite",
 /*  68 */ "opt_else_part ::=",
 /*  69 */ "opt_else_part ::= KEY_ELSE suite",
 /*  70 */ "var_name ::= IDENTIFIER",
 /*  71 */ "expression ::= literal_expression",
 /*  72 */ "expression ::= varname_expression",
 /*  73 */ "expression ::= lookup_expression",
 /*  74 */ "expression ::= expression1",
 /*  75 */ "literal_expression ::= json_value",
 /*  76 */ "varname_expression ::= IDENTIFIER",
 /*  77 */ "expression1 ::= expression2",
 /*  78 */ "expression1 ::= expression1 KEY_AND_AND expression2",
 /*  79 */ "expression2 ::= expression3",
 /*  80 */ "expression2 ::= expression2 KEY_PIPE_PIPE expression3",
 /*  81 */ "expression3 ::= expression4",
 /*  82 */ "expression3 ::= expression3 comparison_op expression4",
 /*  83 */ "expression4 ::= expression5",
 /*  84 */ "expression4 ::= expression4 KEY_PLUS expression5",
 /*  85 */ "expression4 ::= expression4 KEY_MINUS expression5",
 /*  86 */ "expression5 ::= expression6",
 /*  87 */ "expression5 ::= expression5 KEY_STAR expression6",
 /*  88 */ "expression5 ::= expression5 KEY_SLASH expression6",
 /*  89 */ "expression5 ::= expression5 KEY_PERCENT expression6",
 /*  90 */ "expression6 ::= expression7",
 /*  91 */ "expression6 ::= KEY_NOT expression7",
 /*  92 */ "expression7 ::= KEY_LPAREN expression KEY_RPAREN",
 /*  93 */ "comparison_op ::= KEY_EQEQ",
 /*  94 */ "comparison_op ::= KEY_NEQ",
 /*  95 */ "comparison_op ::= KEY_LT",
 /*  96 */ "comparison_op ::= KEY_LEQ",
 /*  97 */ "comparison_op ::= KEY_GT",
 /*  98 */ "comparison_op ::= KEY_GEQ",
 /*  99 */ "lookup_expression ::= expression KEY_LSQUARE_BRACKET lookup_index KEY_RSQUARE_BRACKET",
 /* 100 */ "lookup_index ::= expression",
 /* 101 */ "lookup_index ::= expression KEY_COLON expression",
 /* 102 */ "function_call_expression ::= fully_qualified_function_name KEY_LPAREN opt_actual_parameter_list KEY_RPAREN",
 /* 103 */ "opt_actual_parameter_list ::=",
 /* 104 */ "opt_actual_parameter_list ::= actual_parameter_list",
 /* 105 */ "actual_parameter_list ::= expression",
 /* 106 */ "actual_parameter_list ::= expression KEY_COMMA actual_parameter_list",
 /* 107 */ "top_value ::= compilation_unit",
};
#endif /* NDEBUG */


#if TMPLGYYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.  Return the number
** of errors.  Return 0 on success.
*/
static int tmplgyyGrowStack(tmplgyyParser *p){
  int newSize;
  int idx;
  tmplgyyStackEntry *pNew;

  newSize = p->tmplgyystksz*2 + 100;
  idx = p->tmplgyytos ? (int)(p->tmplgyytos - p->tmplgyystack) : 0;
  if( p->tmplgyystack==&p->tmplgyystk0 ){
    pNew = malloc(newSize*sizeof(pNew[0]));
    if( pNew ) pNew[0] = p->tmplgyystk0;
  }else{
    pNew = realloc(p->tmplgyystack, newSize*sizeof(pNew[0]));
  }
  if( pNew ){
    p->tmplgyystack = pNew;
    p->tmplgyytos = &p->tmplgyystack[idx];
#ifndef NDEBUG
    if( tmplgyyTraceFILE ){
      fprintf(tmplgyyTraceFILE,"%sStack grows from %d to %d entries.\n",
              tmplgyyTracePrompt, p->tmplgyystksz, newSize);
    }
#endif
    p->tmplgyystksz = newSize;
  }
  return pNew==0; 
}
#endif

/* Datatype of the argument to the memory allocated passed as the
** second argument to EmdroslangParserAlloc() below.  This can be changed by
** putting an appropriate #define in the %include section of the input
** grammar.
*/
#ifndef TMPLGYYMALLOCARGTYPE
# define TMPLGYYMALLOCARGTYPE size_t
#endif

/* Initialize a new parser that has already been allocated.
*/
void EmdroslangParserInit(void *tmplgyypRawParser EmdroslangParserCTX_PDECL){
  tmplgyyParser *tmplgyypParser = (tmplgyyParser*)tmplgyypRawParser;
  EmdroslangParserCTX_STORE
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
  tmplgyypParser->tmplgyyhwm = 0;
#endif
#if TMPLGYYSTACKDEPTH<=0
  tmplgyypParser->tmplgyytos = NULL;
  tmplgyypParser->tmplgyystack = NULL;
  tmplgyypParser->tmplgyystksz = 0;
  if( tmplgyyGrowStack(tmplgyypParser) ){
    tmplgyypParser->tmplgyystack = &tmplgyypParser->tmplgyystk0;
    tmplgyypParser->tmplgyystksz = 1;
  }
#endif
#ifndef TMPLGYYNOERRORRECOVERY
  tmplgyypParser->tmplgyyerrcnt = -1;
#endif
  tmplgyypParser->tmplgyytos = tmplgyypParser->tmplgyystack;
  tmplgyypParser->tmplgyystack[0].stateno = 0;
  tmplgyypParser->tmplgyystack[0].major = 0;
#if TMPLGYYSTACKDEPTH>0
  tmplgyypParser->tmplgyystackEnd = &tmplgyypParser->tmplgyystack[TMPLGYYSTACKDEPTH-1];
#endif
}

#ifndef EmdroslangParser_ENGINEALWAYSONSTACK
/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to EmdroslangParser and EmdroslangParserFree.
*/
void *EmdroslangParserAlloc(void *(*mallocProc)(TMPLGYYMALLOCARGTYPE) EmdroslangParserCTX_PDECL){
  tmplgyyParser *tmplgyypParser;
  tmplgyypParser = (tmplgyyParser*)(*mallocProc)( (TMPLGYYMALLOCARGTYPE)sizeof(tmplgyyParser) );
  if( tmplgyypParser ){
    EmdroslangParserCTX_STORE
    EmdroslangParserInit(tmplgyypParser EmdroslangParserCTX_PARAM);
  }
  return (void*)tmplgyypParser;
}
#endif /* EmdroslangParser_ENGINEALWAYSONSTACK */


/* The following function deletes the "minor type" or semantic value
** associated with a symbol.  The symbol can be either a terminal
** or nonterminal. "tmplgyymajor" is the symbol code, and "tmplgyypminor" is
** a pointer to the value to be deleted.  The code used to do the 
** deletions is derived from the %destructor and/or %token_destructor
** directives of the input grammar.
*/
static void tmplgyy_destructor(
  tmplgyyParser *tmplgyypParser,    /* The parser */
  TMPLGYYCODETYPE tmplgyymajor,     /* Type code for object to destroy */
  TMPLGYYMINORTYPE *tmplgyypminor   /* The object to be destroyed */
){
  EmdroslangParserARG_FETCH
  EmdroslangParserCTX_FETCH
  switch( tmplgyymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are *not* used
    ** inside the C code.
    */
/********* Begin destructor definitions ***************************************/
      /* TERMINAL Destructor */
    case 1: /* KEY_STYLESHEET */
    case 2: /* KEY_FETCHINFO */
    case 3: /* KEY_XMLRENDERINFO */
    case 4: /* IDENTIFIER */
    case 5: /* KEY_EXTENDS */
    case 6: /* KEY_NULL */
    case 7: /* KEY_FALSE */
    case 8: /* KEY_TRUE */
    case 9: /* KEY_MINUS */
    case 10: /* INTEGER */
    case 11: /* STRING */
    case 12: /* KEY_LBRACE */
    case 13: /* KEY_RBRACE */
    case 14: /* KEY_COMMA */
    case 15: /* KEY_COLON */
    case 16: /* KEY_LSQUARE_BRACKET */
    case 17: /* KEY_RSQARE_BRACKET */
    case 18: /* KEY_FUNCTION */
    case 19: /* KEY_LPAREN */
    case 20: /* KEY_RPAREN */
    case 21: /* KEY_COLON_COLON */
    case 22: /* KEY_VAR */
    case 23: /* KEY_SEMICOLON */
    case 24: /* KEY_ASSIGN */
    case 25: /* KEY_WHILE */
    case 26: /* KEY_DO */
    case 27: /* KEY_FOR */
    case 28: /* KEY_IN */
    case 29: /* KEY_IF */
    case 30: /* KEY_ELIF */
    case 31: /* KEY_ELSE */
    case 32: /* KEY_AND_AND */
    case 33: /* KEY_PIPE_PIPE */
    case 34: /* KEY_EQEQ */
    case 35: /* KEY_NEQ */
    case 36: /* KEY_GT */
    case 37: /* KEY_GEQ */
    case 38: /* KEY_LT */
    case 39: /* KEY_LEQ */
    case 40: /* KEY_PLUS */
    case 41: /* KEY_STAR */
    case 42: /* KEY_SLASH */
    case 43: /* KEY_PERCENT */
    case 44: /* KEY_NOT */
    case 45: /* KEY_RSQUARE_BRACKET */
{
#line 40 "./emdroslang.yxx"
 (tmplgyypminor->tmplgyy0)->clear(); delete((tmplgyypminor->tmplgyy0)); 
#line 884 "./emdroslang.c"
}
      break;
    case 46: /* top_value */
    case 47: /* compilation_unit */
    case 48: /* compilation_unit_part */
{
#line 56 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy70)); 
#line 893 "./emdroslang.c"
}
      break;
    case 49: /* stylesheet */
{
#line 74 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy78)); 
#line 900 "./emdroslang.c"
}
      break;
    case 50: /* function_def */
{
#line 150 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy169));
#line 907 "./emdroslang.c"
}
      break;
    case 51: /* stylesheet_kind */
    case 52: /* stylesheet_name */
    case 53: /* opt_extends */
    case 82: /* var_name */
{
#line 82 "./emdroslang.yxx"
 deleteToken((tmplgyypminor->tmplgyy0)); 
#line 917 "./emdroslang.c"
}
      break;
    case 54: /* json_object */
    case 55: /* json_value */
    case 56: /* json_list */
{
#line 121 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy90)); 
#line 926 "./emdroslang.c"
}
      break;
    case 57: /* json_object_key_value_list */
    case 58: /* json_object_key_value_pair */
{
#line 126 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy163)); 
#line 934 "./emdroslang.c"
}
      break;
    case 59: /* json_value_list */
{
#line 143 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy159)); 
#line 941 "./emdroslang.c"
}
      break;
    case 60: /* function_signature */
{
#line 155 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy148));
#line 948 "./emdroslang.c"
}
      break;
    case 61: /* function_body */
    case 66: /* opt_statement_list */
    case 67: /* statement_list */
    case 68: /* statement */
    case 70: /* compound_statement */
    case 71: /* suite */
    case 73: /* assignment_statement */
    case 74: /* function_call_statement */
    case 75: /* noop_statement */
    case 76: /* while_statement */
    case 77: /* do_while_statement */
    case 78: /* for_statement */
    case 79: /* if_statement */
    case 80: /* var_decl_list */
    case 81: /* var_decl */
    case 85: /* opt_elif_list */
    case 86: /* opt_else_part */
    case 87: /* elif_part */
{
#line 199 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy137));
#line 972 "./emdroslang.c"
}
      break;
    case 62: /* fully_qualified_function_name */
{
#line 160 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy167));
#line 979 "./emdroslang.c"
}
      break;
    case 63: /* opt_formal_parameter_list */
    case 64: /* formal_parameter_list */
    case 65: /* formal_parameter_name */
{
#line 180 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy154));
#line 988 "./emdroslang.c"
}
      break;
    case 69: /* simple_statement */
{
#line 234 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy137));
#line 256 "./emdroslang.yxx"
delete((tmplgyypminor->tmplgyy137));
#line 997 "./emdroslang.c"
}
      break;
    case 83: /* expression */
    case 84: /* function_call_expression */
    case 88: /* literal_expression */
    case 89: /* varname_expression */
    case 90: /* lookup_expression */
    case 91: /* expression1 */
    case 93: /* expression3 */
    case 94: /* expression4 */
    case 96: /* expression5 */
    case 97: /* expression6 */
    case 98: /* expression7 */
    case 99: /* lookup_index */
    case 100: /* opt_actual_parameter_list */
    case 101: /* actual_parameter_list */
{
#line 353 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy156)); 
#line 1017 "./emdroslang.c"
}
      break;
    case 92: /* expression2 */
{
#line 390 "./emdroslang.yxx"
 delete((tmplgyypminor->tmplgyy156)); 
#line 437 "./emdroslang.yxx"

#line 1026 "./emdroslang.c"
}
      break;
/********* End destructor definitions *****************************************/
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
*/
static void tmplgyy_pop_parser_stack(tmplgyyParser *pParser){
  tmplgyyStackEntry *tmplgyytos;
  assert( pParser->tmplgyytos!=0 );
  assert( pParser->tmplgyytos > pParser->tmplgyystack );
  tmplgyytos = pParser->tmplgyytos--;
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    fprintf(tmplgyyTraceFILE,"%sPopping %s\n",
      tmplgyyTracePrompt,
      tmplgyyTokenName[tmplgyytos->major]);
  }
#endif
  tmplgyy_destructor(pParser, tmplgyytos->major, &tmplgyytos->minor);
}

/*
** Clear all secondary memory allocations from the parser
*/
void EmdroslangParserFinalize(void *p){
  tmplgyyParser *pParser = (tmplgyyParser*)p;
  while( pParser->tmplgyytos>pParser->tmplgyystack ) tmplgyy_pop_parser_stack(pParser);
#if TMPLGYYSTACKDEPTH<=0
  if( pParser->tmplgyystack!=&pParser->tmplgyystk0 ) free(pParser->tmplgyystack);
#endif
}

#ifndef EmdroslangParser_ENGINEALWAYSONSTACK
/* 
** Deallocate and destroy a parser.  Destructors are called for
** all stack elements before shutting the parser down.
**
** If the TMPLGYYPARSEFREENEVERNULL macro exists (for example because it
** is defined in a %include section of the input grammar) then it is
** assumed that the input pointer is never NULL.
*/
void EmdroslangParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
#ifndef TMPLGYYPARSEFREENEVERNULL
  if( p==0 ) return;
#endif
  EmdroslangParserFinalize(p);
  (*freeProc)(p);
}
#endif /* EmdroslangParser_ENGINEALWAYSONSTACK */

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
int EmdroslangParserStackPeak(void *p){
  tmplgyyParser *pParser = (tmplgyyParser*)p;
  return pParser->tmplgyyhwm;
}
#endif

/* This array of booleans keeps track of the parser statement
** coverage.  The element tmplgyycoverage[X][Y] is set when the parser
** is in state X and has a lookahead token Y.  In a well-tested
** systems, every element of this matrix should end up being set.
*/
#if defined(TMPLGYYCOVERAGE)
static unsigned char tmplgyycoverage[TMPLGYYNSTATE][TMPLGYYNTOKEN];
#endif

/*
** Write into out a description of every state/lookahead combination that
**
**   (1)  has not been used by the parser, and
**   (2)  is not a syntax error.
**
** Return the number of missed state/lookahead combinations.
*/
#if defined(TMPLGYYCOVERAGE)
int EmdroslangParserCoverage(FILE *out){
  int stateno, iLookAhead, i;
  int nMissed = 0;
  for(stateno=0; stateno<TMPLGYYNSTATE; stateno++){
    i = tmplgyy_shift_ofst[stateno];
    for(iLookAhead=0; iLookAhead<TMPLGYYNTOKEN; iLookAhead++){
      if( tmplgyy_lookahead[i+iLookAhead]!=iLookAhead ) continue;
      if( tmplgyycoverage[stateno][iLookAhead]==0 ) nMissed++;
      if( out ){
        fprintf(out,"State %d lookahead %s %s\n", stateno,
                tmplgyyTokenName[iLookAhead],
                tmplgyycoverage[stateno][iLookAhead] ? "ok" : "missed");
      }
    }
  }
  return nMissed;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
*/
static TMPLGYYACTIONTYPE tmplgyy_find_shift_action(
  TMPLGYYCODETYPE iLookAhead,    /* The look-ahead token */
  TMPLGYYACTIONTYPE stateno      /* Current state number */
){
  int i;

  if( stateno>TMPLGYY_MAX_SHIFT ) return stateno;
  assert( stateno <= TMPLGYY_SHIFT_COUNT );
#if defined(TMPLGYYCOVERAGE)
  tmplgyycoverage[stateno][iLookAhead] = 1;
#endif
  do{
    i = tmplgyy_shift_ofst[stateno];
    assert( i>=0 );
    assert( i<=TMPLGYY_ACTTAB_COUNT );
    assert( i+TMPLGYYNTOKEN<=(int)TMPLGYY_NLOOKAHEAD );
    assert( iLookAhead!=TMPLGYYNOCODE );
    assert( iLookAhead < TMPLGYYNTOKEN );
    i += iLookAhead;
    assert( i<(int)TMPLGYY_NLOOKAHEAD );
    if( tmplgyy_lookahead[i]!=iLookAhead ){
#ifdef TMPLGYYFALLBACK
      TMPLGYYCODETYPE iFallback;            /* Fallback token */
      assert( iLookAhead<sizeof(tmplgyyFallback)/sizeof(tmplgyyFallback[0]) );
      iFallback = tmplgyyFallback[iLookAhead];
      if( iFallback!=0 ){
#ifndef NDEBUG
        if( tmplgyyTraceFILE ){
          fprintf(tmplgyyTraceFILE, "%sFALLBACK %s => %s\n",
             tmplgyyTracePrompt, tmplgyyTokenName[iLookAhead], tmplgyyTokenName[iFallback]);
        }
#endif
        assert( tmplgyyFallback[iFallback]==0 ); /* Fallback loop must terminate */
        iLookAhead = iFallback;
        continue;
      }
#endif
#ifdef TMPLGYYWILDCARD
      {
        int j = i - iLookAhead + TMPLGYYWILDCARD;
        assert( j<(int)(sizeof(tmplgyy_lookahead)/sizeof(tmplgyy_lookahead[0])) );
        if( tmplgyy_lookahead[j]==TMPLGYYWILDCARD && iLookAhead>0 ){
#ifndef NDEBUG
          if( tmplgyyTraceFILE ){
            fprintf(tmplgyyTraceFILE, "%sWILDCARD %s => %s\n",
               tmplgyyTracePrompt, tmplgyyTokenName[iLookAhead],
               tmplgyyTokenName[TMPLGYYWILDCARD]);
          }
#endif /* NDEBUG */
          return tmplgyy_action[j];
        }
      }
#endif /* TMPLGYYWILDCARD */
      return tmplgyy_default[stateno];
    }else{
      assert( i>=0 && i<sizeof(tmplgyy_action)/sizeof(tmplgyy_action[0]) );
      return tmplgyy_action[i];
    }
  }while(1);
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
*/
static TMPLGYYACTIONTYPE tmplgyy_find_reduce_action(
  TMPLGYYACTIONTYPE stateno,     /* Current state number */
  TMPLGYYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef TMPLGYYERRORSYMBOL
  if( stateno>TMPLGYY_REDUCE_COUNT ){
    return tmplgyy_default[stateno];
  }
#else
  assert( stateno<=TMPLGYY_REDUCE_COUNT );
#endif
  i = tmplgyy_reduce_ofst[stateno];
  assert( iLookAhead!=TMPLGYYNOCODE );
  i += iLookAhead;
#ifdef TMPLGYYERRORSYMBOL
  if( i<0 || i>=TMPLGYY_ACTTAB_COUNT || tmplgyy_lookahead[i]!=iLookAhead ){
    return tmplgyy_default[stateno];
  }
#else
  assert( i>=0 && i<TMPLGYY_ACTTAB_COUNT );
  assert( tmplgyy_lookahead[i]==iLookAhead );
#endif
  return tmplgyy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void tmplgyyStackOverflow(tmplgyyParser *tmplgyypParser){
   EmdroslangParserARG_FETCH
   EmdroslangParserCTX_FETCH
#ifndef NDEBUG
   if( tmplgyyTraceFILE ){
     fprintf(tmplgyyTraceFILE,"%sStack Overflow!\n",tmplgyyTracePrompt);
   }
#endif
   while( tmplgyypParser->tmplgyytos>tmplgyypParser->tmplgyystack ) tmplgyy_pop_parser_stack(tmplgyypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
/******** Begin %stack_overflow code ******************************************/
/******** End %stack_overflow code ********************************************/
   EmdroslangParserARG_STORE /* Suppress warning about unused %extra_argument var */
   EmdroslangParserCTX_STORE
}

/*
** Print tracing information for a SHIFT action
*/
#ifndef NDEBUG
static void tmplgyyTraceShift(tmplgyyParser *tmplgyypParser, int tmplgyyNewState, const char *zTag){
  if( tmplgyyTraceFILE ){
    if( tmplgyyNewState<TMPLGYYNSTATE ){
      fprintf(tmplgyyTraceFILE,"%s%s '%s', go to state %d\n",
         tmplgyyTracePrompt, zTag, tmplgyyTokenName[tmplgyypParser->tmplgyytos->major],
         tmplgyyNewState);
    }else{
      fprintf(tmplgyyTraceFILE,"%s%s '%s', pending reduce %d\n",
         tmplgyyTracePrompt, zTag, tmplgyyTokenName[tmplgyypParser->tmplgyytos->major],
         tmplgyyNewState - TMPLGYY_MIN_REDUCE);
    }
  }
}
#else
# define tmplgyyTraceShift(X,Y,Z)
#endif

/*
** Perform a shift action.
*/
static void tmplgyy_shift(
  tmplgyyParser *tmplgyypParser,          /* The parser to be shifted */
  TMPLGYYACTIONTYPE tmplgyyNewState,      /* The new state to shift in */
  TMPLGYYCODETYPE tmplgyyMajor,           /* The major token to shift in */
  EmdroslangParserTOKENTYPE tmplgyyMinor        /* The minor token to shift in */
){
  tmplgyyStackEntry *tmplgyytos;
  tmplgyypParser->tmplgyytos++;
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
  if( (int)(tmplgyypParser->tmplgyytos - tmplgyypParser->tmplgyystack)>tmplgyypParser->tmplgyyhwm ){
    tmplgyypParser->tmplgyyhwm++;
    assert( tmplgyypParser->tmplgyyhwm == (int)(tmplgyypParser->tmplgyytos - tmplgyypParser->tmplgyystack) );
  }
#endif
#if TMPLGYYSTACKDEPTH>0 
  if( tmplgyypParser->tmplgyytos>tmplgyypParser->tmplgyystackEnd ){
    tmplgyypParser->tmplgyytos--;
    tmplgyyStackOverflow(tmplgyypParser);
    return;
  }
#else
  if( tmplgyypParser->tmplgyytos>=&tmplgyypParser->tmplgyystack[tmplgyypParser->tmplgyystksz] ){
    if( tmplgyyGrowStack(tmplgyypParser) ){
      tmplgyypParser->tmplgyytos--;
      tmplgyyStackOverflow(tmplgyypParser);
      return;
    }
  }
#endif
  if( tmplgyyNewState > TMPLGYY_MAX_SHIFT ){
    tmplgyyNewState += TMPLGYY_MIN_REDUCE - TMPLGYY_MIN_SHIFTREDUCE;
  }
  tmplgyytos = tmplgyypParser->tmplgyytos;
  tmplgyytos->stateno = tmplgyyNewState;
  tmplgyytos->major = tmplgyyMajor;
  tmplgyytos->minor.tmplgyy0 = tmplgyyMinor;
  tmplgyyTraceShift(tmplgyypParser, tmplgyyNewState, "Shift");
}

/* For rule J, tmplgyyRuleInfoLhs[J] contains the symbol on the left-hand side
** of that rule */
static const TMPLGYYCODETYPE tmplgyyRuleInfoLhs[] = {
    47,  /* (0) compilation_unit ::= compilation_unit_part */
    47,  /* (1) compilation_unit ::= compilation_unit compilation_unit_part */
    48,  /* (2) compilation_unit_part ::= stylesheet */
    48,  /* (3) compilation_unit_part ::= function_def */
    49,  /* (4) stylesheet ::= stylesheet_kind KEY_STYLESHEET stylesheet_name opt_extends json_object */
    51,  /* (5) stylesheet_kind ::= KEY_FETCHINFO */
    51,  /* (6) stylesheet_kind ::= KEY_XMLRENDERINFO */
    52,  /* (7) stylesheet_name ::= IDENTIFIER */
    53,  /* (8) opt_extends ::= */
    53,  /* (9) opt_extends ::= KEY_EXTENDS stylesheet_name */
    55,  /* (10) json_value ::= KEY_NULL */
    55,  /* (11) json_value ::= KEY_FALSE */
    55,  /* (12) json_value ::= KEY_TRUE */
    55,  /* (13) json_value ::= KEY_MINUS INTEGER */
    55,  /* (14) json_value ::= INTEGER */
    55,  /* (15) json_value ::= STRING */
    55,  /* (16) json_value ::= json_object */
    55,  /* (17) json_value ::= json_list */
    54,  /* (18) json_object ::= KEY_LBRACE json_object_key_value_list KEY_RBRACE */
    57,  /* (19) json_object_key_value_list ::= json_object_key_value_pair */
    57,  /* (20) json_object_key_value_list ::= json_object_key_value_pair KEY_COMMA json_object_key_value_list */
    58,  /* (21) json_object_key_value_pair ::= STRING KEY_COLON json_value */
    56,  /* (22) json_list ::= KEY_LSQUARE_BRACKET json_value_list KEY_RSQARE_BRACKET */
    59,  /* (23) json_value_list ::= json_value */
    59,  /* (24) json_value_list ::= json_value KEY_COMMA json_value_list */
    50,  /* (25) function_def ::= function_signature function_body */
    60,  /* (26) function_signature ::= KEY_FUNCTION fully_qualified_function_name KEY_LPAREN opt_formal_parameter_list KEY_RPAREN */
    62,  /* (27) fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER KEY_COLON_COLON IDENTIFIER */
    62,  /* (28) fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER */
    62,  /* (29) fully_qualified_function_name ::= IDENTIFIER */
    63,  /* (30) opt_formal_parameter_list ::= */
    63,  /* (31) opt_formal_parameter_list ::= formal_parameter_list */
    64,  /* (32) formal_parameter_list ::= formal_parameter_name */
    64,  /* (33) formal_parameter_list ::= formal_parameter_list KEY_COMMA formal_parameter_name */
    65,  /* (34) formal_parameter_name ::= IDENTIFIER */
    61,  /* (35) function_body ::= KEY_LBRACE opt_statement_list KEY_RBRACE */
    66,  /* (36) opt_statement_list ::= */
    66,  /* (37) opt_statement_list ::= statement_list */
    67,  /* (38) statement_list ::= statement */
    67,  /* (39) statement_list ::= statement statement_list */
    68,  /* (40) statement ::= simple_statement */
    68,  /* (41) statement ::= compound_statement */
    71,  /* (42) suite ::= simple_statement */
    71,  /* (43) suite ::= KEY_LBRACE KEY_RBRACE */
    71,  /* (44) suite ::= KEY_LBRACE statement_list KEY_RBRACE */
    69,  /* (45) simple_statement ::= var_decl_statement */
    69,  /* (46) simple_statement ::= assignment_statement */
    69,  /* (47) simple_statement ::= function_call_statement */
    69,  /* (48) simple_statement ::= noop_statement */
    70,  /* (49) compound_statement ::= while_statement */
    70,  /* (50) compound_statement ::= do_while_statement */
    70,  /* (51) compound_statement ::= for_statement */
    70,  /* (52) compound_statement ::= if_statement */
    72,  /* (53) var_decl_statement ::= KEY_VAR var_decl_list KEY_SEMICOLON */
    80,  /* (54) var_decl_list ::= var_decl */
    80,  /* (55) var_decl_list ::= var_decl_list KEY_COMMA var_decl */
    81,  /* (56) var_decl ::= var_name */
    81,  /* (57) var_decl ::= var_name KEY_ASSIGN expression */
    73,  /* (58) assignment_statement ::= var_name KEY_ASSIGN expression KEY_SEMICOLON */
    74,  /* (59) function_call_statement ::= function_call_expression KEY_SEMICOLON */
    75,  /* (60) noop_statement ::= KEY_SEMICOLON */
    76,  /* (61) while_statement ::= KEY_WHILE KEY_LPAREN expression KEY_RPAREN statement */
    77,  /* (62) do_while_statement ::= KEY_DO statement KEY_WHILE KEY_LPAREN expression KEY_RPAREN */
    78,  /* (63) for_statement ::= KEY_FOR KEY_LPAREN var_name KEY_IN expression KEY_RPAREN statement */
    79,  /* (64) if_statement ::= KEY_IF KEY_LPAREN expression KEY_RPAREN suite opt_elif_list opt_else_part */
    85,  /* (65) opt_elif_list ::= */
    85,  /* (66) opt_elif_list ::= elif_part opt_elif_list */
    87,  /* (67) elif_part ::= KEY_ELIF KEY_LPAREN expression KEY_RPAREN suite */
    86,  /* (68) opt_else_part ::= */
    86,  /* (69) opt_else_part ::= KEY_ELSE suite */
    82,  /* (70) var_name ::= IDENTIFIER */
    83,  /* (71) expression ::= literal_expression */
    83,  /* (72) expression ::= varname_expression */
    83,  /* (73) expression ::= lookup_expression */
    83,  /* (74) expression ::= expression1 */
    88,  /* (75) literal_expression ::= json_value */
    89,  /* (76) varname_expression ::= IDENTIFIER */
    91,  /* (77) expression1 ::= expression2 */
    91,  /* (78) expression1 ::= expression1 KEY_AND_AND expression2 */
    92,  /* (79) expression2 ::= expression3 */
    92,  /* (80) expression2 ::= expression2 KEY_PIPE_PIPE expression3 */
    93,  /* (81) expression3 ::= expression4 */
    93,  /* (82) expression3 ::= expression3 comparison_op expression4 */
    94,  /* (83) expression4 ::= expression5 */
    94,  /* (84) expression4 ::= expression4 KEY_PLUS expression5 */
    94,  /* (85) expression4 ::= expression4 KEY_MINUS expression5 */
    96,  /* (86) expression5 ::= expression6 */
    96,  /* (87) expression5 ::= expression5 KEY_STAR expression6 */
    96,  /* (88) expression5 ::= expression5 KEY_SLASH expression6 */
    96,  /* (89) expression5 ::= expression5 KEY_PERCENT expression6 */
    97,  /* (90) expression6 ::= expression7 */
    97,  /* (91) expression6 ::= KEY_NOT expression7 */
    98,  /* (92) expression7 ::= KEY_LPAREN expression KEY_RPAREN */
    95,  /* (93) comparison_op ::= KEY_EQEQ */
    95,  /* (94) comparison_op ::= KEY_NEQ */
    95,  /* (95) comparison_op ::= KEY_LT */
    95,  /* (96) comparison_op ::= KEY_LEQ */
    95,  /* (97) comparison_op ::= KEY_GT */
    95,  /* (98) comparison_op ::= KEY_GEQ */
    90,  /* (99) lookup_expression ::= expression KEY_LSQUARE_BRACKET lookup_index KEY_RSQUARE_BRACKET */
    99,  /* (100) lookup_index ::= expression */
    99,  /* (101) lookup_index ::= expression KEY_COLON expression */
    84,  /* (102) function_call_expression ::= fully_qualified_function_name KEY_LPAREN opt_actual_parameter_list KEY_RPAREN */
   100,  /* (103) opt_actual_parameter_list ::= */
   100,  /* (104) opt_actual_parameter_list ::= actual_parameter_list */
   101,  /* (105) actual_parameter_list ::= expression */
   101,  /* (106) actual_parameter_list ::= expression KEY_COMMA actual_parameter_list */
    46,  /* (107) top_value ::= compilation_unit */
};

/* For rule J, tmplgyyRuleInfoNRhs[J] contains the negative of the number
** of symbols on the right-hand side of that rule. */
static const signed char tmplgyyRuleInfoNRhs[] = {
   -1,  /* (0) compilation_unit ::= compilation_unit_part */
   -2,  /* (1) compilation_unit ::= compilation_unit compilation_unit_part */
   -1,  /* (2) compilation_unit_part ::= stylesheet */
   -1,  /* (3) compilation_unit_part ::= function_def */
   -5,  /* (4) stylesheet ::= stylesheet_kind KEY_STYLESHEET stylesheet_name opt_extends json_object */
   -1,  /* (5) stylesheet_kind ::= KEY_FETCHINFO */
   -1,  /* (6) stylesheet_kind ::= KEY_XMLRENDERINFO */
   -1,  /* (7) stylesheet_name ::= IDENTIFIER */
    0,  /* (8) opt_extends ::= */
   -2,  /* (9) opt_extends ::= KEY_EXTENDS stylesheet_name */
   -1,  /* (10) json_value ::= KEY_NULL */
   -1,  /* (11) json_value ::= KEY_FALSE */
   -1,  /* (12) json_value ::= KEY_TRUE */
   -2,  /* (13) json_value ::= KEY_MINUS INTEGER */
   -1,  /* (14) json_value ::= INTEGER */
   -1,  /* (15) json_value ::= STRING */
   -1,  /* (16) json_value ::= json_object */
   -1,  /* (17) json_value ::= json_list */
   -3,  /* (18) json_object ::= KEY_LBRACE json_object_key_value_list KEY_RBRACE */
   -1,  /* (19) json_object_key_value_list ::= json_object_key_value_pair */
   -3,  /* (20) json_object_key_value_list ::= json_object_key_value_pair KEY_COMMA json_object_key_value_list */
   -3,  /* (21) json_object_key_value_pair ::= STRING KEY_COLON json_value */
   -3,  /* (22) json_list ::= KEY_LSQUARE_BRACKET json_value_list KEY_RSQARE_BRACKET */
   -1,  /* (23) json_value_list ::= json_value */
   -3,  /* (24) json_value_list ::= json_value KEY_COMMA json_value_list */
   -2,  /* (25) function_def ::= function_signature function_body */
   -5,  /* (26) function_signature ::= KEY_FUNCTION fully_qualified_function_name KEY_LPAREN opt_formal_parameter_list KEY_RPAREN */
   -5,  /* (27) fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER KEY_COLON_COLON IDENTIFIER */
   -3,  /* (28) fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER */
   -1,  /* (29) fully_qualified_function_name ::= IDENTIFIER */
    0,  /* (30) opt_formal_parameter_list ::= */
   -1,  /* (31) opt_formal_parameter_list ::= formal_parameter_list */
   -1,  /* (32) formal_parameter_list ::= formal_parameter_name */
   -3,  /* (33) formal_parameter_list ::= formal_parameter_list KEY_COMMA formal_parameter_name */
   -1,  /* (34) formal_parameter_name ::= IDENTIFIER */
   -3,  /* (35) function_body ::= KEY_LBRACE opt_statement_list KEY_RBRACE */
    0,  /* (36) opt_statement_list ::= */
   -1,  /* (37) opt_statement_list ::= statement_list */
   -1,  /* (38) statement_list ::= statement */
   -2,  /* (39) statement_list ::= statement statement_list */
   -1,  /* (40) statement ::= simple_statement */
   -1,  /* (41) statement ::= compound_statement */
   -1,  /* (42) suite ::= simple_statement */
   -2,  /* (43) suite ::= KEY_LBRACE KEY_RBRACE */
   -3,  /* (44) suite ::= KEY_LBRACE statement_list KEY_RBRACE */
   -1,  /* (45) simple_statement ::= var_decl_statement */
   -1,  /* (46) simple_statement ::= assignment_statement */
   -1,  /* (47) simple_statement ::= function_call_statement */
   -1,  /* (48) simple_statement ::= noop_statement */
   -1,  /* (49) compound_statement ::= while_statement */
   -1,  /* (50) compound_statement ::= do_while_statement */
   -1,  /* (51) compound_statement ::= for_statement */
   -1,  /* (52) compound_statement ::= if_statement */
   -3,  /* (53) var_decl_statement ::= KEY_VAR var_decl_list KEY_SEMICOLON */
   -1,  /* (54) var_decl_list ::= var_decl */
   -3,  /* (55) var_decl_list ::= var_decl_list KEY_COMMA var_decl */
   -1,  /* (56) var_decl ::= var_name */
   -3,  /* (57) var_decl ::= var_name KEY_ASSIGN expression */
   -4,  /* (58) assignment_statement ::= var_name KEY_ASSIGN expression KEY_SEMICOLON */
   -2,  /* (59) function_call_statement ::= function_call_expression KEY_SEMICOLON */
   -1,  /* (60) noop_statement ::= KEY_SEMICOLON */
   -5,  /* (61) while_statement ::= KEY_WHILE KEY_LPAREN expression KEY_RPAREN statement */
   -6,  /* (62) do_while_statement ::= KEY_DO statement KEY_WHILE KEY_LPAREN expression KEY_RPAREN */
   -7,  /* (63) for_statement ::= KEY_FOR KEY_LPAREN var_name KEY_IN expression KEY_RPAREN statement */
   -7,  /* (64) if_statement ::= KEY_IF KEY_LPAREN expression KEY_RPAREN suite opt_elif_list opt_else_part */
    0,  /* (65) opt_elif_list ::= */
   -2,  /* (66) opt_elif_list ::= elif_part opt_elif_list */
   -5,  /* (67) elif_part ::= KEY_ELIF KEY_LPAREN expression KEY_RPAREN suite */
    0,  /* (68) opt_else_part ::= */
   -2,  /* (69) opt_else_part ::= KEY_ELSE suite */
   -1,  /* (70) var_name ::= IDENTIFIER */
   -1,  /* (71) expression ::= literal_expression */
   -1,  /* (72) expression ::= varname_expression */
   -1,  /* (73) expression ::= lookup_expression */
   -1,  /* (74) expression ::= expression1 */
   -1,  /* (75) literal_expression ::= json_value */
   -1,  /* (76) varname_expression ::= IDENTIFIER */
   -1,  /* (77) expression1 ::= expression2 */
   -3,  /* (78) expression1 ::= expression1 KEY_AND_AND expression2 */
   -1,  /* (79) expression2 ::= expression3 */
   -3,  /* (80) expression2 ::= expression2 KEY_PIPE_PIPE expression3 */
   -1,  /* (81) expression3 ::= expression4 */
   -3,  /* (82) expression3 ::= expression3 comparison_op expression4 */
   -1,  /* (83) expression4 ::= expression5 */
   -3,  /* (84) expression4 ::= expression4 KEY_PLUS expression5 */
   -3,  /* (85) expression4 ::= expression4 KEY_MINUS expression5 */
   -1,  /* (86) expression5 ::= expression6 */
   -3,  /* (87) expression5 ::= expression5 KEY_STAR expression6 */
   -3,  /* (88) expression5 ::= expression5 KEY_SLASH expression6 */
   -3,  /* (89) expression5 ::= expression5 KEY_PERCENT expression6 */
   -1,  /* (90) expression6 ::= expression7 */
   -2,  /* (91) expression6 ::= KEY_NOT expression7 */
   -3,  /* (92) expression7 ::= KEY_LPAREN expression KEY_RPAREN */
   -1,  /* (93) comparison_op ::= KEY_EQEQ */
   -1,  /* (94) comparison_op ::= KEY_NEQ */
   -1,  /* (95) comparison_op ::= KEY_LT */
   -1,  /* (96) comparison_op ::= KEY_LEQ */
   -1,  /* (97) comparison_op ::= KEY_GT */
   -1,  /* (98) comparison_op ::= KEY_GEQ */
   -4,  /* (99) lookup_expression ::= expression KEY_LSQUARE_BRACKET lookup_index KEY_RSQUARE_BRACKET */
   -1,  /* (100) lookup_index ::= expression */
   -3,  /* (101) lookup_index ::= expression KEY_COLON expression */
   -4,  /* (102) function_call_expression ::= fully_qualified_function_name KEY_LPAREN opt_actual_parameter_list KEY_RPAREN */
    0,  /* (103) opt_actual_parameter_list ::= */
   -1,  /* (104) opt_actual_parameter_list ::= actual_parameter_list */
   -1,  /* (105) actual_parameter_list ::= expression */
   -3,  /* (106) actual_parameter_list ::= expression KEY_COMMA actual_parameter_list */
   -1,  /* (107) top_value ::= compilation_unit */
};

static void tmplgyy_accept(tmplgyyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
**
** The tmplgyyLookahead and tmplgyyLookaheadToken parameters provide reduce actions
** access to the lookahead token (if any).  The tmplgyyLookahead will be TMPLGYYNOCODE
** if the lookahead token has already been consumed.  As this procedure is
** only called from one place, optimizing compilers will in-line it, which
** means that the extra parameters have no performance impact.
*/
static TMPLGYYACTIONTYPE tmplgyy_reduce(
  tmplgyyParser *tmplgyypParser,         /* The parser */
  unsigned int tmplgyyruleno,       /* Number of the rule by which to reduce */
  int tmplgyyLookahead,             /* Lookahead token, or TMPLGYYNOCODE if none */
  EmdroslangParserTOKENTYPE tmplgyyLookaheadToken  /* Value of the lookahead token */
  EmdroslangParserCTX_PDECL                   /* %extra_context */
){
  int tmplgyygoto;                     /* The next state */
  TMPLGYYACTIONTYPE tmplgyyact;             /* The next action */
  tmplgyyStackEntry *tmplgyymsp;            /* The top of the parser's stack */
  int tmplgyysize;                     /* Amount to pop the stack */
  EmdroslangParserARG_FETCH
  (void)tmplgyyLookahead;
  (void)tmplgyyLookaheadToken;
  tmplgyymsp = tmplgyypParser->tmplgyytos;
#ifndef NDEBUG
  if( tmplgyyTraceFILE && tmplgyyruleno<(int)(sizeof(tmplgyyRuleName)/sizeof(tmplgyyRuleName[0])) ){
    tmplgyysize = tmplgyyRuleInfoNRhs[tmplgyyruleno];
    if( tmplgyysize ){
      fprintf(tmplgyyTraceFILE, "%sReduce %d [%s]%s, pop back to state %d.\n",
        tmplgyyTracePrompt,
        tmplgyyruleno, tmplgyyRuleName[tmplgyyruleno],
        tmplgyyruleno<TMPLGYYNRULE_WITH_ACTION ? "" : " without external action",
        tmplgyymsp[tmplgyysize].stateno);
    }else{
      fprintf(tmplgyyTraceFILE, "%sReduce %d [%s]%s.\n",
        tmplgyyTracePrompt, tmplgyyruleno, tmplgyyRuleName[tmplgyyruleno],
        tmplgyyruleno<TMPLGYYNRULE_WITH_ACTION ? "" : " without external action");
    }
  }
#endif /* NDEBUG */

  /* Check that the stack is large enough to grow by a single entry
  ** if the RHS of the rule is empty.  This ensures that there is room
  ** enough on the stack to push the LHS value */
  if( tmplgyyRuleInfoNRhs[tmplgyyruleno]==0 ){
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
    if( (int)(tmplgyypParser->tmplgyytos - tmplgyypParser->tmplgyystack)>tmplgyypParser->tmplgyyhwm ){
      tmplgyypParser->tmplgyyhwm++;
      assert( tmplgyypParser->tmplgyyhwm == (int)(tmplgyypParser->tmplgyytos - tmplgyypParser->tmplgyystack));
    }
#endif
#if TMPLGYYSTACKDEPTH>0 
    if( tmplgyypParser->tmplgyytos>=tmplgyypParser->tmplgyystackEnd ){
      tmplgyyStackOverflow(tmplgyypParser);
      /* The call to tmplgyyStackOverflow() above pops the stack until it is
      ** empty, causing the main parser loop to exit.  So the return value
      ** is never used and does not matter. */
      return 0;
    }
#else
    if( tmplgyypParser->tmplgyytos>=&tmplgyypParser->tmplgyystack[tmplgyypParser->tmplgyystksz-1] ){
      if( tmplgyyGrowStack(tmplgyypParser) ){
        tmplgyyStackOverflow(tmplgyypParser);
        /* The call to tmplgyyStackOverflow() above pops the stack until it is
        ** empty, causing the main parser loop to exit.  So the return value
        ** is never used and does not matter. */
        return 0;
      }
      tmplgyymsp = tmplgyypParser->tmplgyytos;
    }
#endif
  }

  switch( tmplgyyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
/********** Begin reduce actions **********************************************/
        TMPLGYYMINORTYPE tmplgyylhsminor;
      case 0: /* compilation_unit ::= compilation_unit_part */
#line 62 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy70 = tmplgyymsp[0].minor.tmplgyy70; }
#line 1628 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy70 = tmplgyylhsminor.tmplgyy70;
        break;
      case 1: /* compilation_unit ::= compilation_unit compilation_unit_part */
#line 64 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy70 = tmplgyymsp[-1].minor.tmplgyy70; tmplgyylhsminor.tmplgyy70->setNext(tmplgyymsp[0].minor.tmplgyy70); }
#line 1634 "./emdroslang.c"
  tmplgyymsp[-1].minor.tmplgyy70 = tmplgyylhsminor.tmplgyy70;
        break;
      case 2: /* compilation_unit_part ::= stylesheet */
#line 69 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy70 = tmplgyymsp[0].minor.tmplgyy78; }
#line 1640 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy70 = tmplgyylhsminor.tmplgyy70;
        break;
      case 3: /* compilation_unit_part ::= function_def */
#line 71 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy70 = tmplgyymsp[0].minor.tmplgyy169; }
#line 1646 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy70 = tmplgyylhsminor.tmplgyy70;
        break;
      case 4: /* stylesheet ::= stylesheet_kind KEY_STYLESHEET stylesheet_name opt_extends json_object */
#line 76 "./emdroslang.yxx"
{
   tmplgyylhsminor.tmplgyy78 = new ELStylesheet(*(tmplgyymsp[-4].minor.tmplgyy0->pString), *(tmplgyymsp[-2].minor.tmplgyy0->pString), *(tmplgyymsp[-1].minor.tmplgyy0->pString), tmplgyymsp[0].minor.tmplgyy90);
   delete tmplgyymsp[-4].minor.tmplgyy0; delete tmplgyymsp[-2].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 1655 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,1,&tmplgyymsp[-3].minor);
  tmplgyymsp[-4].minor.tmplgyy78 = tmplgyylhsminor.tmplgyy78;
        break;
      case 5: /* stylesheet_kind ::= KEY_FETCHINFO */
{  tmplgyy_destructor(tmplgyypParser,2,&tmplgyymsp[0].minor);
#line 84 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy0 = newToken(); tmplgyymsp[0].minor.tmplgyy0->setString(new std::string("fetchinfo")); }
#line 1663 "./emdroslang.c"
}
        break;
      case 6: /* stylesheet_kind ::= KEY_XMLRENDERINFO */
{  tmplgyy_destructor(tmplgyypParser,3,&tmplgyymsp[0].minor);
#line 86 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy0 = newToken(); tmplgyymsp[0].minor.tmplgyy0->setString(new std::string("renderxml")); }
#line 1670 "./emdroslang.c"
}
        break;
      case 7: /* stylesheet_name ::= IDENTIFIER */
      case 70: /* var_name ::= IDENTIFIER */ tmplgyytestcase(tmplgyyruleno==70);
#line 91 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy0 = tmplgyymsp[0].minor.tmplgyy0; }
#line 1677 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy0 = tmplgyylhsminor.tmplgyy0;
        break;
      case 8: /* opt_extends ::= */
#line 96 "./emdroslang.yxx"
{ tmplgyymsp[1].minor.tmplgyy0 = newToken(); tmplgyymsp[1].minor.tmplgyy0->setString(new std::string("")); }
#line 1683 "./emdroslang.c"
        break;
      case 9: /* opt_extends ::= KEY_EXTENDS stylesheet_name */
{  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-1].minor);
#line 98 "./emdroslang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy0 = tmplgyymsp[0].minor.tmplgyy0; }
#line 1689 "./emdroslang.c"
}
        break;
      case 10: /* json_value ::= KEY_NULL */
{  tmplgyy_destructor(tmplgyypParser,6,&tmplgyymsp[0].minor);
#line 104 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy90 = new JSONValue(); }
#line 1696 "./emdroslang.c"
}
        break;
      case 11: /* json_value ::= KEY_FALSE */
{  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
#line 106 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy90 = new JSONValue(false); }
#line 1703 "./emdroslang.c"
}
        break;
      case 12: /* json_value ::= KEY_TRUE */
{  tmplgyy_destructor(tmplgyypParser,8,&tmplgyymsp[0].minor);
#line 108 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy90 = new JSONValue(true); }
#line 1710 "./emdroslang.c"
}
        break;
      case 13: /* json_value ::= KEY_MINUS INTEGER */
{  tmplgyy_destructor(tmplgyypParser,9,&tmplgyymsp[-1].minor);
#line 110 "./emdroslang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy90 = new JSONValue(-(tmplgyymsp[0].minor.tmplgyy0->integer)); }
#line 1717 "./emdroslang.c"
}
        break;
      case 14: /* json_value ::= INTEGER */
#line 112 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy90 = new JSONValue(tmplgyymsp[0].minor.tmplgyy0->integer); }
#line 1723 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy90 = tmplgyylhsminor.tmplgyy90;
        break;
      case 15: /* json_value ::= STRING */
#line 114 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy90 = new JSONValue(tmplgyymsp[0].minor.tmplgyy0->extractString()); deleteToken(tmplgyymsp[0].minor.tmplgyy0); }
#line 1729 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy90 = tmplgyylhsminor.tmplgyy90;
        break;
      case 16: /* json_value ::= json_object */
      case 17: /* json_value ::= json_list */ tmplgyytestcase(tmplgyyruleno==17);
#line 116 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy90 = tmplgyymsp[0].minor.tmplgyy90; }
#line 1736 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy90 = tmplgyylhsminor.tmplgyy90;
        break;
      case 18: /* json_object ::= KEY_LBRACE json_object_key_value_list KEY_RBRACE */
{  tmplgyy_destructor(tmplgyypParser,12,&tmplgyymsp[-2].minor);
#line 123 "./emdroslang.yxx"
{ tmplgyymsp[-2].minor.tmplgyy90 = new JSONValue(tmplgyymsp[-1].minor.tmplgyy163); }
#line 1743 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,13,&tmplgyymsp[0].minor);
}
        break;
      case 19: /* json_object_key_value_list ::= json_object_key_value_pair */
#line 128 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy163 = tmplgyymsp[0].minor.tmplgyy163; }
#line 1750 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy163 = tmplgyylhsminor.tmplgyy163;
        break;
      case 20: /* json_object_key_value_list ::= json_object_key_value_pair KEY_COMMA json_object_key_value_list */
#line 130 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy163 = tmplgyymsp[-2].minor.tmplgyy163; tmplgyymsp[-2].minor.tmplgyy163->setNext(tmplgyymsp[0].minor.tmplgyy163); }
#line 1756 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy163 = tmplgyylhsminor.tmplgyy163;
        break;
      case 21: /* json_object_key_value_pair ::= STRING KEY_COLON json_value */
#line 135 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy163 = new JSONKeyValuePair(tmplgyymsp[-2].minor.tmplgyy0->extractString(), tmplgyymsp[0].minor.tmplgyy90, NULL); deleteToken(tmplgyymsp[-2].minor.tmplgyy0); }
#line 1763 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,15,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy163 = tmplgyylhsminor.tmplgyy163;
        break;
      case 22: /* json_list ::= KEY_LSQUARE_BRACKET json_value_list KEY_RSQARE_BRACKET */
{  tmplgyy_destructor(tmplgyypParser,16,&tmplgyymsp[-2].minor);
#line 140 "./emdroslang.yxx"
{ tmplgyymsp[-2].minor.tmplgyy90 = new JSONValue(tmplgyymsp[-1].minor.tmplgyy159); }
#line 1771 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,17,&tmplgyymsp[0].minor);
}
        break;
      case 23: /* json_value_list ::= json_value */
#line 145 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy159 = new JSONListElement(tmplgyymsp[0].minor.tmplgyy90); }
#line 1778 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy159 = tmplgyylhsminor.tmplgyy159;
        break;
      case 24: /* json_value_list ::= json_value KEY_COMMA json_value_list */
#line 147 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy159 = new JSONListElement(tmplgyymsp[-2].minor.tmplgyy90); tmplgyylhsminor.tmplgyy159->setNext(tmplgyymsp[0].minor.tmplgyy159); }
#line 1784 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy159 = tmplgyylhsminor.tmplgyy159;
        break;
      case 25: /* function_def ::= function_signature function_body */
#line 152 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy169 = new ELFunctionDef(tmplgyymsp[-1].minor.tmplgyy148, tmplgyymsp[0].minor.tmplgyy137); }
#line 1791 "./emdroslang.c"
  tmplgyymsp[-1].minor.tmplgyy169 = tmplgyylhsminor.tmplgyy169;
        break;
      case 26: /* function_signature ::= KEY_FUNCTION fully_qualified_function_name KEY_LPAREN opt_formal_parameter_list KEY_RPAREN */
{  tmplgyy_destructor(tmplgyypParser,18,&tmplgyymsp[-4].minor);
#line 157 "./emdroslang.yxx"
{ tmplgyymsp[-4].minor.tmplgyy148 = new ELFunctionSignature(tmplgyymsp[-3].minor.tmplgyy167, tmplgyymsp[-1].minor.tmplgyy154); }
#line 1798 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[0].minor);
}
        break;
      case 27: /* fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER KEY_COLON_COLON IDENTIFIER */
#line 162 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy167 = new ELFullyQualifiedFunctionName(*(tmplgyymsp[-4].minor.tmplgyy0->pString), *(tmplgyymsp[-2].minor.tmplgyy0->pString), *(tmplgyymsp[0].minor.tmplgyy0->pString));
  deleteToken(tmplgyymsp[-4].minor.tmplgyy0);
  deleteToken(tmplgyymsp[-2].minor.tmplgyy0);
  deleteToken(tmplgyymsp[0].minor.tmplgyy0);
}
#line 1810 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-1].minor);
  tmplgyymsp[-4].minor.tmplgyy167 = tmplgyylhsminor.tmplgyy167;
        break;
      case 28: /* fully_qualified_function_name ::= IDENTIFIER KEY_COLON_COLON IDENTIFIER */
#line 168 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy167 = new ELFullyQualifiedFunctionName(*(tmplgyymsp[-2].minor.tmplgyy0->pString), "", *(tmplgyymsp[0].minor.tmplgyy0->pString));
  deleteToken(tmplgyymsp[-2].minor.tmplgyy0);
  deleteToken(tmplgyymsp[0].minor.tmplgyy0);
}
#line 1821 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy167 = tmplgyylhsminor.tmplgyy167;
        break;
      case 29: /* fully_qualified_function_name ::= IDENTIFIER */
#line 174 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy167 = new ELFullyQualifiedFunctionName("", "", *(tmplgyymsp[0].minor.tmplgyy0->pString));
  deleteToken(tmplgyymsp[0].minor.tmplgyy0);
}
#line 1830 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy167 = tmplgyylhsminor.tmplgyy167;
        break;
      case 30: /* opt_formal_parameter_list ::= */
#line 182 "./emdroslang.yxx"
{ tmplgyymsp[1].minor.tmplgyy154 = 0; }
#line 1836 "./emdroslang.c"
        break;
      case 31: /* opt_formal_parameter_list ::= formal_parameter_list */
      case 32: /* formal_parameter_list ::= formal_parameter_name */ tmplgyytestcase(tmplgyyruleno==32);
#line 184 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy154 = tmplgyymsp[0].minor.tmplgyy154; }
#line 1842 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy154 = tmplgyylhsminor.tmplgyy154;
        break;
      case 33: /* formal_parameter_list ::= formal_parameter_list KEY_COMMA formal_parameter_name */
#line 191 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy154 = tmplgyymsp[-2].minor.tmplgyy154; tmplgyylhsminor.tmplgyy154->setNext(tmplgyymsp[0].minor.tmplgyy154); }
#line 1848 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy154 = tmplgyylhsminor.tmplgyy154;
        break;
      case 34: /* formal_parameter_name ::= IDENTIFIER */
#line 196 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy154 = new ELParameterName(*(tmplgyymsp[0].minor.tmplgyy0->pString)); deleteToken(tmplgyymsp[0].minor.tmplgyy0); }
#line 1855 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy154 = tmplgyylhsminor.tmplgyy154;
        break;
      case 35: /* function_body ::= KEY_LBRACE opt_statement_list KEY_RBRACE */
      case 44: /* suite ::= KEY_LBRACE statement_list KEY_RBRACE */ tmplgyytestcase(tmplgyyruleno==44);
{  tmplgyy_destructor(tmplgyypParser,12,&tmplgyymsp[-2].minor);
#line 201 "./emdroslang.yxx"
{ tmplgyymsp[-2].minor.tmplgyy137 = new ELNewScopeStatement(tmplgyymsp[-1].minor.tmplgyy137); }
#line 1863 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,13,&tmplgyymsp[0].minor);
}
        break;
      case 36: /* opt_statement_list ::= */
#line 206 "./emdroslang.yxx"
{ tmplgyymsp[1].minor.tmplgyy137 = new ELNoopStatement(); }
#line 1870 "./emdroslang.c"
        break;
      case 37: /* opt_statement_list ::= statement_list */
      case 38: /* statement_list ::= statement */ tmplgyytestcase(tmplgyyruleno==38);
      case 40: /* statement ::= simple_statement */ tmplgyytestcase(tmplgyyruleno==40);
      case 41: /* statement ::= compound_statement */ tmplgyytestcase(tmplgyyruleno==41);
      case 42: /* suite ::= simple_statement */ tmplgyytestcase(tmplgyyruleno==42);
      case 45: /* simple_statement ::= var_decl_statement */ tmplgyytestcase(tmplgyyruleno==45);
      case 46: /* simple_statement ::= assignment_statement */ tmplgyytestcase(tmplgyyruleno==46);
      case 47: /* simple_statement ::= function_call_statement */ tmplgyytestcase(tmplgyyruleno==47);
      case 48: /* simple_statement ::= noop_statement */ tmplgyytestcase(tmplgyyruleno==48);
      case 49: /* compound_statement ::= while_statement */ tmplgyytestcase(tmplgyyruleno==49);
      case 50: /* compound_statement ::= do_while_statement */ tmplgyytestcase(tmplgyyruleno==50);
      case 51: /* compound_statement ::= for_statement */ tmplgyytestcase(tmplgyyruleno==51);
      case 52: /* compound_statement ::= if_statement */ tmplgyytestcase(tmplgyyruleno==52);
      case 54: /* var_decl_list ::= var_decl */ tmplgyytestcase(tmplgyyruleno==54);
#line 208 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = tmplgyymsp[0].minor.tmplgyy137; }
#line 1888 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 39: /* statement_list ::= statement statement_list */
      case 66: /* opt_elif_list ::= elif_part opt_elif_list */ tmplgyytestcase(tmplgyyruleno==66);
#line 215 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = tmplgyymsp[-1].minor.tmplgyy137; tmplgyymsp[-1].minor.tmplgyy137->setNext(tmplgyymsp[0].minor.tmplgyy137); }
#line 1895 "./emdroslang.c"
  tmplgyymsp[-1].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 43: /* suite ::= KEY_LBRACE KEY_RBRACE */
{  tmplgyy_destructor(tmplgyypParser,12,&tmplgyymsp[-1].minor);
#line 229 "./emdroslang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy137 = new ELNewScopeStatement(new ELNoopStatement()); }
#line 1902 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,13,&tmplgyymsp[0].minor);
}
        break;
      case 53: /* var_decl_statement ::= KEY_VAR var_decl_list KEY_SEMICOLON */
{  tmplgyy_destructor(tmplgyypParser,22,&tmplgyymsp[-2].minor);
#line 258 "./emdroslang.yxx"
{ tmplgyymsp[-2].minor.tmplgyy137 = tmplgyymsp[-1].minor.tmplgyy137; }
#line 1910 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,23,&tmplgyymsp[0].minor);
}
        break;
      case 55: /* var_decl_list ::= var_decl_list KEY_COMMA var_decl */
#line 265 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = tmplgyymsp[-2].minor.tmplgyy137; tmplgyylhsminor.tmplgyy137->setNext(tmplgyymsp[0].minor.tmplgyy137); }
#line 1917 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 56: /* var_decl ::= var_name */
#line 270 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = new ELVarDeclStatement(*(tmplgyymsp[0].minor.tmplgyy0->pString), 0); deleteToken(tmplgyymsp[0].minor.tmplgyy0); }
#line 1924 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 57: /* var_decl ::= var_name KEY_ASSIGN expression */
#line 272 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = new ELVarDeclStatement(*(tmplgyymsp[-2].minor.tmplgyy0->pString), tmplgyymsp[0].minor.tmplgyy156); deleteToken(tmplgyymsp[-2].minor.tmplgyy0); }
#line 1930 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,24,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 58: /* assignment_statement ::= var_name KEY_ASSIGN expression KEY_SEMICOLON */
#line 277 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = new ELAssignmentStatement(*(tmplgyymsp[-3].minor.tmplgyy0->pString), tmplgyymsp[-1].minor.tmplgyy156); deleteToken(tmplgyymsp[-3].minor.tmplgyy0); }
#line 1937 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,24,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,23,&tmplgyymsp[0].minor);
  tmplgyymsp[-3].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 59: /* function_call_statement ::= function_call_expression KEY_SEMICOLON */
#line 282 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy137 = new ELFunctionCallStatement(tmplgyymsp[-1].minor.tmplgyy156); }
#line 1945 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,23,&tmplgyymsp[0].minor);
  tmplgyymsp[-1].minor.tmplgyy137 = tmplgyylhsminor.tmplgyy137;
        break;
      case 60: /* noop_statement ::= KEY_SEMICOLON */
{  tmplgyy_destructor(tmplgyypParser,23,&tmplgyymsp[0].minor);
#line 288 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy137 = new ELNoopStatement(); }
#line 1953 "./emdroslang.c"
}
        break;
      case 61: /* while_statement ::= KEY_WHILE KEY_LPAREN expression KEY_RPAREN statement */
{  tmplgyy_destructor(tmplgyypParser,25,&tmplgyymsp[-4].minor);
#line 293 "./emdroslang.yxx"
{ tmplgyymsp[-4].minor.tmplgyy137 = new ELWhileStatement(tmplgyymsp[-2].minor.tmplgyy156, tmplgyymsp[0].minor.tmplgyy137, true); }
#line 1960 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-1].minor);
}
        break;
      case 62: /* do_while_statement ::= KEY_DO statement KEY_WHILE KEY_LPAREN expression KEY_RPAREN */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-5].minor);
#line 299 "./emdroslang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy137 = new ELWhileStatement(tmplgyymsp[-1].minor.tmplgyy156, tmplgyymsp[-4].minor.tmplgyy137, false); }
#line 1969 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,25,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[0].minor);
}
        break;
      case 63: /* for_statement ::= KEY_FOR KEY_LPAREN var_name KEY_IN expression KEY_RPAREN statement */
{  tmplgyy_destructor(tmplgyypParser,27,&tmplgyymsp[-6].minor);
#line 304 "./emdroslang.yxx"
{ tmplgyymsp[-6].minor.tmplgyy137 = new ELForStatement(*(tmplgyymsp[-4].minor.tmplgyy0->pString), tmplgyymsp[-2].minor.tmplgyy156, tmplgyymsp[0].minor.tmplgyy137); deleteToken(tmplgyymsp[-4].minor.tmplgyy0); }
#line 1979 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,28,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-1].minor);
}
        break;
      case 64: /* if_statement ::= KEY_IF KEY_LPAREN expression KEY_RPAREN suite opt_elif_list opt_else_part */
{  tmplgyy_destructor(tmplgyypParser,29,&tmplgyymsp[-6].minor);
#line 310 "./emdroslang.yxx"
{
  tmplgyymsp[-6].minor.tmplgyy137 = new ELIfStatement(tmplgyymsp[-4].minor.tmplgyy156, tmplgyymsp[-2].minor.tmplgyy137);

  if (tmplgyymsp[-1].minor.tmplgyy137 == 0 && tmplgyymsp[0].minor.tmplgyy137 == 0) {
     ; // nothing to do
  } else if (tmplgyymsp[-1].minor.tmplgyy137 == 0 && tmplgyymsp[0].minor.tmplgyy137 != 0) {
     tmplgyymsp[-6].minor.tmplgyy137->setNext(tmplgyymsp[0].minor.tmplgyy137);
  } else if (tmplgyymsp[-1].minor.tmplgyy137 != 0 && tmplgyymsp[0].minor.tmplgyy137 == 0) {
     tmplgyymsp[-6].minor.tmplgyy137->setNext(tmplgyymsp[-1].minor.tmplgyy137);
  } else {
     // tmplgyymsp[-1].minor.tmplgyy137 != 0 && tmplgyymsp[0].minor.tmplgyy137 != 0
     tmplgyymsp[-1].minor.tmplgyy137->getTail()->setNext(tmplgyymsp[0].minor.tmplgyy137);
     tmplgyymsp[-6].minor.tmplgyy137->setNext(tmplgyymsp[-1].minor.tmplgyy137);
  }
}
#line 2003 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-3].minor);
}
        break;
      case 65: /* opt_elif_list ::= */
      case 68: /* opt_else_part ::= */ tmplgyytestcase(tmplgyyruleno==68);
#line 329 "./emdroslang.yxx"
{ tmplgyymsp[1].minor.tmplgyy137 = 0; }
#line 2012 "./emdroslang.c"
        break;
      case 67: /* elif_part ::= KEY_ELIF KEY_LPAREN expression KEY_RPAREN suite */
{  tmplgyy_destructor(tmplgyypParser,30,&tmplgyymsp[-4].minor);
#line 336 "./emdroslang.yxx"
{ tmplgyymsp[-4].minor.tmplgyy137 = new ELIfStatement(tmplgyymsp[-2].minor.tmplgyy156, tmplgyymsp[0].minor.tmplgyy137); }
#line 2018 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-1].minor);
}
        break;
      case 69: /* opt_else_part ::= KEY_ELSE suite */
{  tmplgyy_destructor(tmplgyypParser,31,&tmplgyymsp[-1].minor);
#line 343 "./emdroslang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy137 = tmplgyymsp[0].minor.tmplgyy137; }
#line 2027 "./emdroslang.c"
}
        break;
      case 71: /* expression ::= literal_expression */
      case 72: /* expression ::= varname_expression */ tmplgyytestcase(tmplgyyruleno==72);
      case 73: /* expression ::= lookup_expression */ tmplgyytestcase(tmplgyyruleno==73);
      case 74: /* expression ::= expression1 */ tmplgyytestcase(tmplgyyruleno==74);
      case 77: /* expression1 ::= expression2 */ tmplgyytestcase(tmplgyyruleno==77);
      case 79: /* expression2 ::= expression3 */ tmplgyytestcase(tmplgyyruleno==79);
      case 81: /* expression3 ::= expression4 */ tmplgyytestcase(tmplgyyruleno==81);
      case 83: /* expression4 ::= expression5 */ tmplgyytestcase(tmplgyyruleno==83);
      case 86: /* expression5 ::= expression6 */ tmplgyytestcase(tmplgyyruleno==86);
      case 90: /* expression6 ::= expression7 */ tmplgyytestcase(tmplgyyruleno==90);
      case 100: /* lookup_index ::= expression */ tmplgyytestcase(tmplgyyruleno==100);
      case 104: /* opt_actual_parameter_list ::= actual_parameter_list */ tmplgyytestcase(tmplgyyruleno==104);
      case 105: /* actual_parameter_list ::= expression */ tmplgyytestcase(tmplgyyruleno==105);
#line 355 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = tmplgyymsp[0].minor.tmplgyy156; }
#line 2045 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 75: /* literal_expression ::= json_value */
#line 366 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[0].minor.tmplgyy90); }
#line 2051 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 76: /* varname_expression ::= IDENTIFIER */
#line 372 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(*(tmplgyymsp[0].minor.tmplgyy0->pString)); deleteToken(tmplgyymsp[0].minor.tmplgyy0); }
#line 2057 "./emdroslang.c"
  tmplgyymsp[0].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 78: /* expression1 ::= expression1 KEY_AND_AND expression2 */
#line 387 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpAnd, tmplgyymsp[0].minor.tmplgyy156); }
#line 2063 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,32,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 80: /* expression2 ::= expression2 KEY_PIPE_PIPE expression3 */
#line 394 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpOr, tmplgyymsp[0].minor.tmplgyy156); }
#line 2070 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,33,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 82: /* expression3 ::= expression3 comparison_op expression4 */
#line 401 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, tmplgyymsp[-1].minor.tmplgyy149, tmplgyymsp[0].minor.tmplgyy156); }
#line 2077 "./emdroslang.c"
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 84: /* expression4 ::= expression4 KEY_PLUS expression5 */
#line 408 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpPlus, tmplgyymsp[0].minor.tmplgyy156); }
#line 2083 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,40,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 85: /* expression4 ::= expression4 KEY_MINUS expression5 */
#line 410 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpMinus, tmplgyymsp[0].minor.tmplgyy156); }
#line 2090 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,9,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 87: /* expression5 ::= expression5 KEY_STAR expression6 */
#line 418 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpStar, tmplgyymsp[0].minor.tmplgyy156); }
#line 2097 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,41,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 88: /* expression5 ::= expression5 KEY_SLASH expression6 */
#line 420 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpSlash, tmplgyymsp[0].minor.tmplgyy156); }
#line 2104 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,42,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 89: /* expression5 ::= expression5 KEY_PERCENT expression6 */
#line 422 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpPercent, tmplgyymsp[0].minor.tmplgyy156); }
#line 2111 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,43,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 91: /* expression6 ::= KEY_NOT expression7 */
{  tmplgyy_destructor(tmplgyypParser,44,&tmplgyymsp[-1].minor);
#line 429 "./emdroslang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy156 = new ELExpression(kOpNot, tmplgyymsp[0].minor.tmplgyy156); }
#line 2119 "./emdroslang.c"
}
        break;
      case 92: /* expression7 ::= KEY_LPAREN expression KEY_RPAREN */
{  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-2].minor);
#line 434 "./emdroslang.yxx"
{ tmplgyymsp[-2].minor.tmplgyy156 = tmplgyymsp[-1].minor.tmplgyy156; }
#line 2126 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[0].minor);
}
        break;
      case 93: /* comparison_op ::= KEY_EQEQ */
{  tmplgyy_destructor(tmplgyypParser,34,&tmplgyymsp[0].minor);
#line 439 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpEqEq; }
#line 2134 "./emdroslang.c"
}
        break;
      case 94: /* comparison_op ::= KEY_NEQ */
{  tmplgyy_destructor(tmplgyypParser,35,&tmplgyymsp[0].minor);
#line 441 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpNeq; }
#line 2141 "./emdroslang.c"
}
        break;
      case 95: /* comparison_op ::= KEY_LT */
{  tmplgyy_destructor(tmplgyypParser,38,&tmplgyymsp[0].minor);
#line 443 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpLt; }
#line 2148 "./emdroslang.c"
}
        break;
      case 96: /* comparison_op ::= KEY_LEQ */
{  tmplgyy_destructor(tmplgyypParser,39,&tmplgyymsp[0].minor);
#line 445 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpLeq; }
#line 2155 "./emdroslang.c"
}
        break;
      case 97: /* comparison_op ::= KEY_GT */
{  tmplgyy_destructor(tmplgyypParser,36,&tmplgyymsp[0].minor);
#line 447 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpGt; }
#line 2162 "./emdroslang.c"
}
        break;
      case 98: /* comparison_op ::= KEY_GEQ */
{  tmplgyy_destructor(tmplgyypParser,37,&tmplgyymsp[0].minor);
#line 449 "./emdroslang.yxx"
{ tmplgyymsp[0].minor.tmplgyy149 = kOpGeq; }
#line 2169 "./emdroslang.c"
}
        break;
      case 99: /* lookup_expression ::= expression KEY_LSQUARE_BRACKET lookup_index KEY_RSQUARE_BRACKET */
#line 454 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-3].minor.tmplgyy156, kOpLookup, tmplgyymsp[-1].minor.tmplgyy156); }
#line 2175 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,16,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,45,&tmplgyymsp[0].minor);
  tmplgyymsp[-3].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 101: /* lookup_index ::= expression KEY_COLON expression */
#line 461 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-2].minor.tmplgyy156, kOpSlice, tmplgyymsp[0].minor.tmplgyy156); }
#line 2183 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,15,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 102: /* function_call_expression ::= fully_qualified_function_name KEY_LPAREN opt_actual_parameter_list KEY_RPAREN */
#line 467 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = new ELExpression(tmplgyymsp[-3].minor.tmplgyy167, tmplgyymsp[-1].minor.tmplgyy156); }
#line 2190 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[0].minor);
  tmplgyymsp[-3].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 103: /* opt_actual_parameter_list ::= */
#line 472 "./emdroslang.yxx"
{ tmplgyymsp[1].minor.tmplgyy156 = 0; }
#line 2198 "./emdroslang.c"
        break;
      case 106: /* actual_parameter_list ::= expression KEY_COMMA actual_parameter_list */
#line 481 "./emdroslang.yxx"
{ tmplgyylhsminor.tmplgyy156 = tmplgyymsp[-2].minor.tmplgyy156; tmplgyylhsminor.tmplgyy156->setNext(tmplgyymsp[0].minor.tmplgyy156); }
#line 2203 "./emdroslang.c"
  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
  tmplgyymsp[-2].minor.tmplgyy156 = tmplgyylhsminor.tmplgyy156;
        break;
      case 107: /* top_value ::= compilation_unit */
{  tmplgyy_destructor(tmplgyypParser,47,&tmplgyymsp[0].minor);
#line 57 "./emdroslang.yxx"
{
}
#line 2212 "./emdroslang.c"
}
        break;
      default:
        break;
/********** End reduce actions ************************************************/
  };
  assert( tmplgyyruleno<sizeof(tmplgyyRuleInfoLhs)/sizeof(tmplgyyRuleInfoLhs[0]) );
  tmplgyygoto = tmplgyyRuleInfoLhs[tmplgyyruleno];
  tmplgyysize = tmplgyyRuleInfoNRhs[tmplgyyruleno];
  tmplgyyact = tmplgyy_find_reduce_action(tmplgyymsp[tmplgyysize].stateno,(TMPLGYYCODETYPE)tmplgyygoto);

  /* There are no SHIFTREDUCE actions on nonterminals because the table
  ** generator has simplified them to pure REDUCE actions. */
  assert( !(tmplgyyact>TMPLGYY_MAX_SHIFT && tmplgyyact<=TMPLGYY_MAX_SHIFTREDUCE) );

  /* It is not possible for a REDUCE to be followed by an error */
  assert( tmplgyyact!=TMPLGYY_ERROR_ACTION );

  tmplgyymsp += tmplgyysize+1;
  tmplgyypParser->tmplgyytos = tmplgyymsp;
  tmplgyymsp->stateno = (TMPLGYYACTIONTYPE)tmplgyyact;
  tmplgyymsp->major = (TMPLGYYCODETYPE)tmplgyygoto;
  tmplgyyTraceShift(tmplgyypParser, tmplgyyact, "... then shift");
  return tmplgyyact;
}

/*
** The following code executes when the parse fails
*/
#ifndef TMPLGYYNOERRORRECOVERY
static void tmplgyy_parse_failed(
  tmplgyyParser *tmplgyypParser           /* The parser */
){
  EmdroslangParserARG_FETCH
  EmdroslangParserCTX_FETCH
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    fprintf(tmplgyyTraceFILE,"%sFail!\n",tmplgyyTracePrompt);
  }
#endif
  while( tmplgyypParser->tmplgyytos>tmplgyypParser->tmplgyystack ) tmplgyy_pop_parser_stack(tmplgyypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
/************ Begin %parse_failure code ***************************************/
#line 51 "./emdroslang.yxx"

  pEE->bCompilerError = true;
#line 2260 "./emdroslang.c"
/************ End %parse_failure code *****************************************/
  EmdroslangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  EmdroslangParserCTX_STORE
}
#endif /* TMPLGYYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void tmplgyy_syntax_error(
  tmplgyyParser *tmplgyypParser,           /* The parser */
  int tmplgyymajor,                   /* The major type of the error token */
  EmdroslangParserTOKENTYPE tmplgyyminor         /* The minor type of the error token */
){
  EmdroslangParserARG_FETCH
  EmdroslangParserCTX_FETCH
#define TOKEN tmplgyyminor
/************ Begin %syntax_error code ****************************************/
#line 44 "./emdroslang.yxx"

  pEE->bCompilerError = true;
  std::string errMsg = "syntax error near " + TOKEN->getTokenName();
  pEE->appendCompilerError(errMsg);
#line 2284 "./emdroslang.c"
/************ End %syntax_error code ******************************************/
  EmdroslangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  EmdroslangParserCTX_STORE
}

/*
** The following is executed when the parser accepts
*/
static void tmplgyy_accept(
  tmplgyyParser *tmplgyypParser           /* The parser */
){
  EmdroslangParserARG_FETCH
  EmdroslangParserCTX_FETCH
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    fprintf(tmplgyyTraceFILE,"%sAccept!\n",tmplgyyTracePrompt);
  }
#endif
#ifndef TMPLGYYNOERRORRECOVERY
  tmplgyypParser->tmplgyyerrcnt = -1;
#endif
  assert( tmplgyypParser->tmplgyytos==tmplgyypParser->tmplgyystack );
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
/*********** Begin %parse_accept code *****************************************/
/*********** End %parse_accept code *******************************************/
  EmdroslangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  EmdroslangParserCTX_STORE
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "EmdroslangParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void EmdroslangParser(
  void *tmplgyyp,                   /* The parser */
  int tmplgyymajor,                 /* The major token code number */
  EmdroslangParserTOKENTYPE tmplgyyminor       /* The value for the token */
  EmdroslangParserARG_PDECL               /* Optional %extra_argument parameter */
){
  TMPLGYYMINORTYPE tmplgyyminorunion;
  TMPLGYYACTIONTYPE tmplgyyact;   /* The parser action. */
#if !defined(TMPLGYYERRORSYMBOL) && !defined(TMPLGYYNOERRORRECOVERY)
  int tmplgyyendofinput;     /* True if we are at the end of input */
#endif
#ifdef TMPLGYYERRORSYMBOL
  int tmplgyyerrorhit = 0;   /* True if tmplgyymajor has invoked an error */
#endif
  tmplgyyParser *tmplgyypParser = (tmplgyyParser*)tmplgyyp;  /* The parser */
  EmdroslangParserCTX_FETCH
  EmdroslangParserARG_STORE

  assert( tmplgyypParser->tmplgyytos!=0 );
#if !defined(TMPLGYYERRORSYMBOL) && !defined(TMPLGYYNOERRORRECOVERY)
  tmplgyyendofinput = (tmplgyymajor==0);
#endif

  tmplgyyact = tmplgyypParser->tmplgyytos->stateno;
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    if( tmplgyyact < TMPLGYY_MIN_REDUCE ){
      fprintf(tmplgyyTraceFILE,"%sInput '%s' in state %d\n",
              tmplgyyTracePrompt,tmplgyyTokenName[tmplgyymajor],tmplgyyact);
    }else{
      fprintf(tmplgyyTraceFILE,"%sInput '%s' with pending reduce %d\n",
              tmplgyyTracePrompt,tmplgyyTokenName[tmplgyymajor],tmplgyyact-TMPLGYY_MIN_REDUCE);
    }
  }
#endif

  do{
    assert( tmplgyyact==tmplgyypParser->tmplgyytos->stateno );
    tmplgyyact = tmplgyy_find_shift_action((TMPLGYYCODETYPE)tmplgyymajor,tmplgyyact);
    if( tmplgyyact >= TMPLGYY_MIN_REDUCE ){
      tmplgyyact = tmplgyy_reduce(tmplgyypParser,tmplgyyact-TMPLGYY_MIN_REDUCE,tmplgyymajor,
                        tmplgyyminor EmdroslangParserCTX_PARAM);
    }else if( tmplgyyact <= TMPLGYY_MAX_SHIFTREDUCE ){
      tmplgyy_shift(tmplgyypParser,tmplgyyact,(TMPLGYYCODETYPE)tmplgyymajor,tmplgyyminor);
#ifndef TMPLGYYNOERRORRECOVERY
      tmplgyypParser->tmplgyyerrcnt--;
#endif
      break;
    }else if( tmplgyyact==TMPLGYY_ACCEPT_ACTION ){
      tmplgyypParser->tmplgyytos--;
      tmplgyy_accept(tmplgyypParser);
      return;
    }else{
      assert( tmplgyyact == TMPLGYY_ERROR_ACTION );
      tmplgyyminorunion.tmplgyy0 = tmplgyyminor;
#ifdef TMPLGYYERRORSYMBOL
      int tmplgyymx;
#endif
#ifndef NDEBUG
      if( tmplgyyTraceFILE ){
        fprintf(tmplgyyTraceFILE,"%sSyntax Error!\n",tmplgyyTracePrompt);
      }
#endif
#ifdef TMPLGYYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( tmplgyypParser->tmplgyyerrcnt<0 ){
        tmplgyy_syntax_error(tmplgyypParser,tmplgyymajor,tmplgyyminor);
      }
      tmplgyymx = tmplgyypParser->tmplgyytos->major;
      if( tmplgyymx==TMPLGYYERRORSYMBOL || tmplgyyerrorhit ){
#ifndef NDEBUG
        if( tmplgyyTraceFILE ){
          fprintf(tmplgyyTraceFILE,"%sDiscard input token %s\n",
             tmplgyyTracePrompt,tmplgyyTokenName[tmplgyymajor]);
        }
#endif
        tmplgyy_destructor(tmplgyypParser, (TMPLGYYCODETYPE)tmplgyymajor, &tmplgyyminorunion);
        tmplgyymajor = TMPLGYYNOCODE;
      }else{
        while( tmplgyypParser->tmplgyytos >= tmplgyypParser->tmplgyystack
            && (tmplgyyact = tmplgyy_find_reduce_action(
                        tmplgyypParser->tmplgyytos->stateno,
                        TMPLGYYERRORSYMBOL)) > TMPLGYY_MAX_SHIFTREDUCE
        ){
          tmplgyy_pop_parser_stack(tmplgyypParser);
        }
        if( tmplgyypParser->tmplgyytos < tmplgyypParser->tmplgyystack || tmplgyymajor==0 ){
          tmplgyy_destructor(tmplgyypParser,(TMPLGYYCODETYPE)tmplgyymajor,&tmplgyyminorunion);
          tmplgyy_parse_failed(tmplgyypParser);
#ifndef TMPLGYYNOERRORRECOVERY
          tmplgyypParser->tmplgyyerrcnt = -1;
#endif
          tmplgyymajor = TMPLGYYNOCODE;
        }else if( tmplgyymx!=TMPLGYYERRORSYMBOL ){
          tmplgyy_shift(tmplgyypParser,tmplgyyact,TMPLGYYERRORSYMBOL,tmplgyyminor);
        }
      }
      tmplgyypParser->tmplgyyerrcnt = 3;
      tmplgyyerrorhit = 1;
      if( tmplgyymajor==TMPLGYYNOCODE ) break;
      tmplgyyact = tmplgyypParser->tmplgyytos->stateno;
#elif defined(TMPLGYYNOERRORRECOVERY)
      /* If the TMPLGYYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      tmplgyy_syntax_error(tmplgyypParser,tmplgyymajor, tmplgyyminor);
      tmplgyy_destructor(tmplgyypParser,(TMPLGYYCODETYPE)tmplgyymajor,&tmplgyyminorunion);
      break;
#else  /* TMPLGYYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( tmplgyypParser->tmplgyyerrcnt<=0 ){
        tmplgyy_syntax_error(tmplgyypParser,tmplgyymajor, tmplgyyminor);
      }
      tmplgyypParser->tmplgyyerrcnt = 3;
      tmplgyy_destructor(tmplgyypParser,(TMPLGYYCODETYPE)tmplgyymajor,&tmplgyyminorunion);
      if( tmplgyyendofinput ){
        tmplgyy_parse_failed(tmplgyypParser);
#ifndef TMPLGYYNOERRORRECOVERY
        tmplgyypParser->tmplgyyerrcnt = -1;
#endif
      }
      break;
#endif
    }
  }while( tmplgyypParser->tmplgyytos>tmplgyypParser->tmplgyystack );
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    tmplgyyStackEntry *i;
    char cDiv = '[';
    fprintf(tmplgyyTraceFILE,"%sReturn. Stack=",tmplgyyTracePrompt);
    for(i=&tmplgyypParser->tmplgyystack[1]; i<=tmplgyypParser->tmplgyytos; i++){
      fprintf(tmplgyyTraceFILE,"%c%s", cDiv, tmplgyyTokenName[i->major]);
      cDiv = ' ';
    }
    fprintf(tmplgyyTraceFILE,"]\n");
  }
#endif
  return;
}

/*
** Return the fallback token corresponding to canonical token iToken, or
** 0 if iToken has no fallback.
*/
int EmdroslangParserFallback(int iToken){
#ifdef TMPLGYYFALLBACK
  assert( iToken<(int)(sizeof(tmplgyyFallback)/sizeof(tmplgyyFallback[0])) );
  return tmplgyyFallback[iToken];
#else
  (void)iToken;
  return 0;
#endif
}
