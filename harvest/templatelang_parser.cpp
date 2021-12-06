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
#line 1 "./templatelang.yxx"


/*
 * templatelang.yxx
 *
 * Template language parser
 *
 * Ulrik Sandborg-Petersen
 * Created: 7/28-2008
 * Last update: 4/16-2019
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



#include <templatelang_classes.h>
#include <mql_yylex.h>
#include <cstdlib>
#include <string>
#include <cassert>

#undef TOKEN

#line 63 "./templatelang.c"
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
**    TemplateLangParserTOKENTYPE     is the data type used for minor type for terminal
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
**                       which is TemplateLangParserTOKENTYPE.  The entry in the union
**                       for terminal symbols is called "tmplgyy0".
**    TMPLGYYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    TemplateLangParserARG_SDECL     A static variable declaration for the %extra_argument
**    TemplateLangParserARG_PDECL     A parameter declaration for the %extra_argument
**    TemplateLangParserARG_PARAM     Code to pass %extra_argument as a subroutine parameter
**    TemplateLangParserARG_STORE     Code to store %extra_argument into tmplgyypParser
**    TemplateLangParserARG_FETCH     Code to extract %extra_argument from tmplgyypParser
**    TemplateLangParserCTX_*         As TemplateLangParserARG_ except for %extra_context
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
#define TMPLGYYNOCODE 89
#define TMPLGYYACTIONTYPE unsigned short int
#define TemplateLangParserTOKENTYPE Token*
typedef union {
  int tmplgyyinit;
  TemplateLangParserTOKENTYPE tmplgyy0;
  TemplateIfNamedSetEmpty* tmplgyy4;
  TemplateIfFeatureEqual* tmplgyy10;
  TemplateSetVarNow* tmplgyy16;
  TemplateIf* tmplgyy22;
  TemplateSetVarEnd* tmplgyy29;
  TemplateDictlookupCounter* tmplgyy45;
  TemplateString* tmplgyy52;
  TemplateListAppendBegin* tmplgyy62;
  TemplateIfHasAttrib* tmplgyy68;
  TemplateListAppendEnd* tmplgyy70;
  TemplateNamedSetRemoveEnd* tmplgyy73;
  TemplateNamedSetRemoveBegin* tmplgyy77;
  TemplateNixing* tmplgyy80;
  TemplateSetVarBegin* tmplgyy81;
  TemplateDictlookupFeature* tmplgyy85;
  TemplateDictlookupVar* tmplgyy90;
  TemplateNamedSetAddEnd* tmplgyy92;
  TemplateSetVarSubString* tmplgyy93;
  TemplateASTNode* tmplgyy95;
  TemplateEmitVar* tmplgyy107;
  TemplateIfVarEqual* tmplgyy108;
  TemplateIfListEmpty* tmplgyy147;
  TemplateIfAttribEqual* tmplgyy156;
  long tmplgyy157;
  TemplateNamedSetAddBegin* tmplgyy160;
} TMPLGYYMINORTYPE;
#ifndef TMPLGYYSTACKDEPTH
#define TMPLGYYSTACKDEPTH 100
#endif
#define TemplateLangParserARG_SDECL TemplateLangExecEnv *pEE;
#define TemplateLangParserARG_PDECL ,TemplateLangExecEnv *pEE
#define TemplateLangParserARG_PARAM ,pEE
#define TemplateLangParserARG_FETCH TemplateLangExecEnv *pEE=tmplgyypParser->pEE;
#define TemplateLangParserARG_STORE tmplgyypParser->pEE=pEE;
#define TemplateLangParserCTX_SDECL
#define TemplateLangParserCTX_PDECL
#define TemplateLangParserCTX_PARAM
#define TemplateLangParserCTX_FETCH
#define TemplateLangParserCTX_STORE
#define TMPLGYYNSTATE             217
#define TMPLGYYNRULE              107
#define TMPLGYYNRULE_WITH_ACTION  107
#define TMPLGYYNTOKEN             61
#define TMPLGYY_MAX_SHIFT         216
#define TMPLGYY_MIN_SHIFTREDUCE   323
#define TMPLGYY_MAX_SHIFTREDUCE   429
#define TMPLGYY_ERROR_ACTION      430
#define TMPLGYY_ACCEPT_ACTION     431
#define TMPLGYY_NO_ACTION         432
#define TMPLGYY_MIN_REDUCE        433
#define TMPLGYY_MAX_REDUCE        539
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
#define TMPLGYY_ACTTAB_COUNT (724)
static const TMPLGYYACTIONTYPE tmplgyy_action[] = {
 /*     0 */    34,  328,  329,  330,  216,  425,  423,   44,  213,  210,
 /*    10 */   334,  207,  409,  204,  201,  200,  424,  418,  194,  421,
 /*    20 */   187,  181,  175,  170,  167,  162,  159,  413,  414,  422,
 /*    30 */   412,  372,  373,  374,  131,  126,  119,  116,  113,  110,
 /*    40 */   388,    3,  105,  393,  101,  395,   96,  397,   91,  417,
 /*    50 */   419,  416,  410,  411,  415,  406,   29,  408,  420,  426,
 /*    60 */   427,  328,  329,  330,  216,  425,  423,   89,  213,  210,
 /*    70 */   334,  207,  409,  204,  201,  200,  424,  418,  194,  421,
 /*    80 */   187,  181,  175,  170,  167,  162,  159,  413,  414,  422,
 /*    90 */   412,  372,  373,  374,  131,  126,  119,  116,  113,  110,
 /*   100 */    16,    2,  105,  393,  101,  395,   96,  397,   91,  417,
 /*   110 */   419,  416,  410,  411,  415,  406,   29,  408,  420,  426,
 /*   120 */   427,  328,  329,  330,  216,  425,  423,   54,  213,  210,
 /*   130 */   334,  207,  409,  204,  201,  200,  424,  418,  194,  421,
 /*   140 */   187,  181,  175,  170,  167,  162,  159,  413,  414,  422,
 /*   150 */   412,  372,  373,  374,  131,  126,  119,  116,  113,  110,
 /*   160 */   390,   64,  105,  393,  101,  395,   96,  397,   91,  417,
 /*   170 */   419,  416,  410,  411,  415,  406,   29,  408,  420,  426,
 /*   180 */   427,  328,  329,  330,  216,  425,  423,   74,  213,  210,
 /*   190 */   334,  207,  409,  204,  201,  200,  424,  418,  194,  421,
 /*   200 */   187,  181,  175,  170,  167,  162,  159,  413,  414,  422,
 /*   210 */   412,  372,  373,  374,  131,  126,  119,  116,  113,  110,
 /*   220 */   389,   84,  105,  393,  101,  395,   96,  397,   91,  417,
 /*   230 */   419,  416,  410,  411,  415,  406,   29,  408,  420,  426,
 /*   240 */   427,  433,  328,  329,  330,  216,  425,  423,   27,  213,
 /*   250 */   210,  334,  207,  409,  204,  201,  200,  424,  418,  194,
 /*   260 */   421,  187,  181,  175,  170,  167,  162,  159,  413,  414,
 /*   270 */   422,  412,  372,  373,  374,  131,  126,  119,  116,  113,
 /*   280 */   110,  407,   28,  105,  393,  101,  395,   96,  397,   91,
 /*   290 */   417,  419,  416,  410,  411,  415,  406,   29,  408,  420,
 /*   300 */   426,  427,  328,  329,  330,  216,  425,  423,   31,  213,
 /*   310 */   210,  334,  207,  409,  204,  201,  200,  424,  418,  194,
 /*   320 */   421,  187,  181,  175,  170,  167,  162,  159,  413,  414,
 /*   330 */   422,  412,  372,  373,  374,  131,  126,  119,  116,  113,
 /*   340 */   110,  404,   30,  105,  393,  101,  395,   96,  397,   91,
 /*   350 */   417,  419,  416,  410,  411,  415,  406,   29,  408,  420,
 /*   360 */   426,  427,   32,  431,    7,  434,  436,  437,  462,  463,
 /*   370 */   464,  465,  466,  467,  468,  469,  470,  471,  472,  473,
 /*   380 */   474,  475,  476,  492,  493,  494,  495,  497,  496,    1,
 /*   390 */     4,  434,  436,  437,  462,  463,  464,  465,  466,  467,
 /*   400 */   468,  469,  470,  471,  472,  473,  474,  475,  476,  492,
 /*   410 */   493,  494,  495,  497,  496,    1,    5,  434,  436,  437,
 /*   420 */   462,  463,  464,  465,  466,  467,  468,  469,  470,  471,
 /*   430 */   472,  473,  474,  475,  476,  492,  493,  494,  495,  497,
 /*   440 */   496,    1,    6,  434,  436,  437,  462,  463,  464,  465,
 /*   450 */   466,  467,  468,  469,  470,  471,  472,  473,  474,  475,
 /*   460 */   476,  492,  493,  494,  495,  497,  496,    1,  435,  436,
 /*   470 */   437,  462,  463,  464,  465,  466,  467,  468,  469,  470,
 /*   480 */   471,  472,  473,  474,  475,  476,  492,  493,  494,  495,
 /*   490 */   497,  496,    1,   59,   49,  146,  428,   14,   17,  103,
 /*   500 */   405,  391,  179,  156,  151,  141,  136,  123,  185,  191,
 /*   510 */   122,   88,   21,   33,  345,  178,    8,   35,   78,   69,
 /*   520 */    39,  184,  190,   36,   23,  198,  342,  338,   37,   38,
 /*   530 */   403,   40,   41,   42,   43,    9,   45,   46,  402,   47,
 /*   540 */    48,  401,   50,   51,   53,   10,   52,   55,   56,   79,
 /*   550 */    57,   58,   62,   60,   61,   63,   11,   66,   67,   65,
 /*   560 */    68,  400,   70,   71,   72,   73,   12,   75,   76,   77,
 /*   570 */   429,   81,  399,   80,   83,   13,   86,   82,   85,  398,
 /*   580 */    90,  396,   93,  432,   87,   95,  394,   98,  432,   18,
 /*   590 */   100,  432,   92,  392,   94,  104,  432,   97,  381,   99,
 /*   600 */   107,  109,  432,  102,   19,  380,  108,  112,  379,  106,
 /*   610 */   115,  111,  118,  378,  432,  377,  114,  121,  376,   20,
 /*   620 */   117,  125,  432,  128,  375,  120,  124,  129,  432,  127,
 /*   630 */   130,  371,  133,  135,  432,  132,  134,  370,  137,  138,
 /*   640 */   369,  140,  139,  143,  145,  148,  150,  142,  144,  368,
 /*   650 */   149,  153,  367,  147,  154,  155,   15,  158,  432,  152,
 /*   660 */   351,  161,  350,  157,  432,  160,  164,  166,  169,  432,
 /*   670 */   163,  349,  172,  165,  168,  348,  171,  174,  347,  177,
 /*   680 */   346,  180,  173,  432,  344,  176,  183,  343,  186,  341,
 /*   690 */   432,   22,  189,  340,  182,   24,  339,   25,  193,  196,
 /*   700 */   432,  188,  432,  199,  192,  208,  195,  337,  202,  336,
 /*   710 */   203,  335,  197,   26,  206,  333,  209,  332,  211,  205,
 /*   720 */   212,  331,  214,  215,
};
static const TMPLGYYCODETYPE tmplgyy_lookahead[] = {
 /*     0 */    88,    1,    2,    3,    4,    5,    6,   88,    8,    9,
 /*    10 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*    20 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*    30 */    30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
 /*    40 */    40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
 /*    50 */    50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
 /*    60 */    60,    1,    2,    3,    4,    5,    6,   16,    8,    9,
 /*    70 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*    80 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*    90 */    30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
 /*   100 */    49,   41,   42,   43,   44,   45,   46,   47,   48,   49,
 /*   110 */    50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
 /*   120 */    60,    1,    2,    3,    4,    5,    6,   88,    8,    9,
 /*   130 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   140 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   150 */    30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
 /*   160 */    40,   88,   42,   43,   44,   45,   46,   47,   48,   49,
 /*   170 */    50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
 /*   180 */    60,    1,    2,    3,    4,    5,    6,   88,    8,    9,
 /*   190 */    10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
 /*   200 */    20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
 /*   210 */    30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
 /*   220 */    40,   88,   42,   43,   44,   45,   46,   47,   48,   49,
 /*   230 */    50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
 /*   240 */    60,    0,    1,    2,    3,    4,    5,    6,   16,    8,
 /*   250 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   260 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   270 */    29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
 /*   280 */    39,    7,    5,   42,   43,   44,   45,   46,   47,   48,
 /*   290 */    49,   50,   51,   52,   53,   54,   55,   56,   57,   58,
 /*   300 */    59,   60,    1,    2,    3,    4,    5,    6,    5,    8,
 /*   310 */     9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   320 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   330 */    29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
 /*   340 */    39,    7,    6,   42,   43,   44,   45,   46,   47,   48,
 /*   350 */    49,   50,   51,   52,   53,   54,   55,   56,   57,   58,
 /*   360 */    59,   60,   51,   61,   62,   63,   64,   65,   66,   67,
 /*   370 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   380 */    78,   79,   80,   81,   82,   83,   84,   85,   86,   87,
 /*   390 */    62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   400 */    72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
 /*   410 */    82,   83,   84,   85,   86,   87,   62,   63,   64,   65,
 /*   420 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   430 */    76,   77,   78,   79,   80,   81,   82,   83,   84,   85,
 /*   440 */    86,   87,   62,   63,   64,   65,   66,   67,   68,   69,
 /*   450 */    70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
 /*   460 */    80,   81,   82,   83,   84,   85,   86,   87,   63,   64,
 /*   470 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   480 */    75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
 /*   490 */    85,   86,   87,   27,   28,   19,    6,    5,    5,    5,
 /*   500 */     7,    7,    6,   27,   28,   29,   30,   16,    6,    6,
 /*   510 */    19,   19,    5,    5,    7,   19,    5,   50,   52,   53,
 /*   520 */    54,   19,   19,    5,    5,    5,    7,    7,    6,    5,
 /*   530 */     7,    6,    5,   51,    5,    5,   50,    5,    7,    6,
 /*   540 */     5,    7,    6,    5,    5,    5,   51,   50,    5,   59,
 /*   550 */     6,    5,   51,    6,    5,    5,    5,    5,   16,   50,
 /*   560 */     5,    7,    6,    5,   51,    5,    5,   50,    5,   16,
 /*   570 */     6,    5,    7,    6,    5,    5,    5,   51,   50,    7,
 /*   580 */     5,    7,    5,   89,   16,    5,    7,    5,   89,   16,
 /*   590 */     5,   89,   16,    7,   16,    5,   89,   16,    7,   16,
 /*   600 */     5,    5,   89,   16,   16,    7,   12,    5,    7,   16,
 /*   610 */     5,   12,    5,    7,   89,    7,   16,    5,    7,    5,
 /*   620 */    16,    5,   89,    5,    7,   16,   16,    6,   89,   16,
 /*   630 */     5,    7,    5,    5,   89,   16,   16,    7,   16,    5,
 /*   640 */     7,    5,   16,    5,    5,    5,    5,   16,   16,    7,
 /*   650 */     6,    5,    7,   16,    6,    5,    5,    5,   89,   16,
 /*   660 */     7,    5,    7,   16,   89,   16,    5,    5,    5,   89,
 /*   670 */    16,    7,    5,   16,   16,    7,   16,    5,    7,    5,
 /*   680 */     7,    5,   16,   89,    7,   16,    5,    7,    5,    7,
 /*   690 */    89,   16,    5,    7,   16,   16,    7,    5,    5,    5,
 /*   700 */    89,   16,   89,    5,   16,    6,   16,    7,   12,    7,
 /*   710 */     5,    7,   17,   16,    5,    7,    5,    7,    6,   12,
 /*   720 */     5,    7,    6,    5,   89,   89,   89,   89,   89,   89,
 /*   730 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   740 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   750 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   760 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   770 */    89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
 /*   780 */    89,   89,   89,   89,   89,
};
#define TMPLGYY_SHIFT_COUNT    (216)
#define TMPLGYY_SHIFT_MIN      (0)
#define TMPLGYY_SHIFT_MAX      (718)
static const unsigned short int tmplgyy_shift_ofst[] = {
 /*     0 */   301,   60,  301,  301,    0,  120,  180,  241,  490,  490,
 /*    10 */   490,  490,  490,  490,  466,  476,  492,   51,  493,  494,
 /*    20 */   491,  496,  507,  502,  519,  503,  520,  274,  232,  277,
 /*    30 */   334,  336,  303,  311,  508,  511,  467,  518,  522,  524,
 /*    40 */   523,  525,  527,  482,  529,  530,  486,  532,  533,  535,
 /*    50 */   531,  536,  538,  495,  539,  540,  497,  543,  544,  546,
 /*    60 */   534,  547,  549,  501,  550,  551,  509,  552,  542,  555,
 /*    70 */   554,  556,  558,  513,  560,  561,  517,  563,  553,  564,
 /*    80 */   565,  567,  566,  526,  569,  570,  528,  571,  568,  572,
 /*    90 */   573,  575,  574,  576,  577,  578,  580,  579,  581,  582,
 /*   100 */   583,  585,  586,  587,  588,  590,  591,  593,  595,  594,
 /*   110 */   596,  598,  599,  602,  601,  600,  605,  606,  604,  607,
 /*   120 */   608,  609,  612,  611,  614,  610,  616,  617,  613,  618,
 /*   130 */   621,  625,  624,  619,  627,  620,  628,  630,  622,  634,
 /*   140 */   626,  636,  633,  631,  638,  632,  639,  642,  637,  640,
 /*   150 */   644,  641,  645,  643,  646,  648,  650,  651,  647,  652,
 /*   160 */   653,  649,  656,  655,  654,  661,  657,  662,  664,  658,
 /*   170 */   663,  668,  660,  667,  666,  672,  671,  669,  674,  673,
 /*   180 */   675,  676,  677,  678,  681,  680,  679,  683,  682,  685,
 /*   190 */   687,  686,  692,  688,  693,  689,  690,  694,  695,  697,
 /*   200 */   698,  700,  702,  696,  705,  704,  707,  709,  708,  699,
 /*   210 */   711,  710,  712,  715,  714,  716,  718,
};
#define TMPLGYY_REDUCE_COUNT (13)
#define TMPLGYY_REDUCE_MIN   (-88)
#define TMPLGYY_REDUCE_MAX   (405)
static const short tmplgyy_reduce_ofst[] = {
 /*     0 */   302,  328,  354,  380,  405,  405,  405,  405,  -88,  -81,
 /*    10 */    39,   73,   99,  133,
};
static const TMPLGYYACTIONTYPE tmplgyy_default[] = {
 /*     0 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    10 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    20 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    30 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    40 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    50 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    60 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    70 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    80 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*    90 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   100 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   110 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   120 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   130 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   140 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   150 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   160 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   170 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   180 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   190 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   200 */   430,  430,  430,  430,  430,  430,  430,  430,  430,  430,
 /*   210 */   430,  430,  430,  430,  430,  430,  430,
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
  TemplateLangParserARG_SDECL                /* A place to hold %extra_argument */
  TemplateLangParserCTX_SDECL                /* A place to hold %extra_context */
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
void TemplateLangParserTrace(FILE *TraceFILE, char *zTracePrompt){
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
  /*    1 */ "KEY_ID_D",
  /*    2 */ "KEY_FIRSTMONAD",
  /*    3 */ "KEY_LASTMONAD",
  /*    4 */ "KEY_FEATURE",
  /*    5 */ "KEY_SPACE",
  /*    6 */ "INTEGER",
  /*    7 */ "KEY_BB_CLOSE",
  /*    8 */ "KEY_FEATUREJSONMANGLE",
  /*    9 */ "KEY_FEATURENOMANGLE",
  /*   10 */ "KEY_DBNAME",
  /*   11 */ "KEY_ATTRIB",
  /*   12 */ "IDENTIFIER",
  /*   13 */ "KEY_ATTRIB_NOMANGLE",
  /*   14 */ "KEY_COPYATTRIBS",
  /*   15 */ "KEY_COUNTER",
  /*   16 */ "STRING",
  /*   17 */ "KEY_BARE_FORMAT",
  /*   18 */ "KEY_SETCOUNTER",
  /*   19 */ "KEY_BARE_VAR",
  /*   20 */ "KEY_INCCOUNTER",
  /*   21 */ "KEY_DECCOUNTER",
  /*   22 */ "KEY_LISTEMIT",
  /*   23 */ "KEY_LISTCLEAR",
  /*   24 */ "KEY_NAMEDSETEMIT",
  /*   25 */ "KEY_NAMEDSETCLEAR",
  /*   26 */ "KEY_DICTLOOKUP",
  /*   27 */ "KEY_BARE_FEATURE",
  /*   28 */ "KEY_BARE_FEATURENOMANGLE",
  /*   29 */ "KEY_BARE_VARNOMANGLE",
  /*   30 */ "KEY_BARE_COUNTER",
  /*   31 */ "KEY_SETNIXING_ALL",
  /*   32 */ "KEY_SETNIXING_DOC",
  /*   33 */ "KEY_SETNIXING_OFF",
  /*   34 */ "KEY_IF_FEATUREEQUAL",
  /*   35 */ "KEY_IF_VAREQUAL",
  /*   36 */ "KEY_IF_LISTEMPTY",
  /*   37 */ "KEY_IF_NAMEDSETEMPTY",
  /*   38 */ "KEY_IF_HASATTRIB",
  /*   39 */ "KEY_IF_ATTRIBEQUAL",
  /*   40 */ "KEY_ENDIF",
  /*   41 */ "KEY_ELSE",
  /*   42 */ "KEY_LISTAPPENDBEGIN",
  /*   43 */ "KEY_LISTAPPENDEND",
  /*   44 */ "KEY_NAMEDSETADD",
  /*   45 */ "KEY_NAMEDSETADDEND",
  /*   46 */ "KEY_NAMEDSETREMOVE",
  /*   47 */ "KEY_NAMEDSETREMOVEEND",
  /*   48 */ "KEY_SETVAR",
  /*   49 */ "KEY_BARE_SUBSTRING",
  /*   50 */ "KEY_BARE_FROM",
  /*   51 */ "KEY_BARE_MAXLENGTH",
  /*   52 */ "KEY_BARE_ATTRIB",
  /*   53 */ "KEY_BARE_ATTRIBNOMANGLE",
  /*   54 */ "KEY_BARE_FEATUREJSONMANGLE",
  /*   55 */ "KEY_SETVAREND",
  /*   56 */ "KEY_EMITVAR",
  /*   57 */ "CHAR",
  /*   58 */ "KEY_BARE_TO",
  /*   59 */ "KEY_DASH",
  /*   60 */ "KEY_NEWLINE",
  /*   61 */ "top_value",
  /*   62 */ "template_list",
  /*   63 */ "template_list_element",
  /*   64 */ "template_string",
  /*   65 */ "template_if",
  /*   66 */ "template_listappend",
  /*   67 */ "template_listappend_end",
  /*   68 */ "template_namedsetadd",
  /*   69 */ "template_namedsetadd_end",
  /*   70 */ "template_namedsetremove",
  /*   71 */ "template_namedsetremove_end",
  /*   72 */ "template_setvarnow",
  /*   73 */ "template_setvarsubstring",
  /*   74 */ "template_setvar",
  /*   75 */ "template_setvar_end",
  /*   76 */ "template_emitvar",
  /*   77 */ "template_setnixing",
  /*   78 */ "template_dictlookup_feature",
  /*   79 */ "template_dictlookup_var",
  /*   80 */ "template_dictlookup_counter",
  /*   81 */ "template_if_featureequal",
  /*   82 */ "template_if_varequal",
  /*   83 */ "template_if_listempty",
  /*   84 */ "template_if_namedsetempty",
  /*   85 */ "template_if_hasattrib",
  /*   86 */ "template_if_attribequal",
  /*   87 */ "template_some_if",
  /*   88 */ "signed_integer",
};
#endif /* defined(TMPLGYYCOVERAGE) || !defined(NDEBUG) */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const tmplgyyRuleName[] = {
 /*   0 */ "top_value ::= template_list",
 /*   1 */ "template_list ::= template_list_element",
 /*   2 */ "template_list ::= template_list template_list_element",
 /*   3 */ "template_list_element ::= template_string",
 /*   4 */ "template_list_element ::= template_if",
 /*   5 */ "template_list_element ::= KEY_ID_D",
 /*   6 */ "template_list_element ::= KEY_FIRSTMONAD",
 /*   7 */ "template_list_element ::= KEY_LASTMONAD",
 /*   8 */ "template_list_element ::= KEY_FEATURE KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*   9 */ "template_list_element ::= KEY_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  10 */ "template_list_element ::= KEY_FEATURENOMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  11 */ "template_list_element ::= KEY_DBNAME",
 /*  12 */ "template_list_element ::= KEY_ATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE",
 /*  13 */ "template_list_element ::= KEY_ATTRIB_NOMANGLE KEY_SPACE IDENTIFIER KEY_BB_CLOSE",
 /*  14 */ "template_list_element ::= KEY_COPYATTRIBS KEY_BB_CLOSE",
 /*  15 */ "template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  16 */ "template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_FORMAT KEY_SPACE STRING KEY_BB_CLOSE",
 /*  17 */ "template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  18 */ "template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  19 */ "template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  20 */ "template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  21 */ "template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  22 */ "template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  23 */ "template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  24 */ "template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  25 */ "template_list_element ::= KEY_LISTEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  26 */ "template_list_element ::= KEY_LISTCLEAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  27 */ "template_list_element ::= KEY_NAMEDSETEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  28 */ "template_list_element ::= KEY_NAMEDSETCLEAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  29 */ "template_list_element ::= template_listappend",
 /*  30 */ "template_list_element ::= template_listappend_end",
 /*  31 */ "template_list_element ::= template_namedsetadd",
 /*  32 */ "template_list_element ::= template_namedsetadd_end",
 /*  33 */ "template_list_element ::= template_namedsetremove",
 /*  34 */ "template_list_element ::= template_namedsetremove_end",
 /*  35 */ "template_list_element ::= template_setvarnow",
 /*  36 */ "template_list_element ::= template_setvarsubstring",
 /*  37 */ "template_list_element ::= template_setvar",
 /*  38 */ "template_list_element ::= template_setvar_end",
 /*  39 */ "template_list_element ::= template_emitvar",
 /*  40 */ "template_list_element ::= template_setnixing",
 /*  41 */ "template_list_element ::= template_dictlookup_feature",
 /*  42 */ "template_list_element ::= template_dictlookup_var",
 /*  43 */ "template_list_element ::= template_dictlookup_counter",
 /*  44 */ "template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  45 */ "template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  46 */ "template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  47 */ "template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VARNOMANGLE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  48 */ "template_dictlookup_counter ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_COUNTER KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  49 */ "template_setnixing ::= KEY_SETNIXING_ALL",
 /*  50 */ "template_setnixing ::= KEY_SETNIXING_DOC",
 /*  51 */ "template_setnixing ::= KEY_SETNIXING_OFF",
 /*  52 */ "template_if_featureequal ::= KEY_IF_FEATUREEQUAL KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  53 */ "template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  54 */ "template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  55 */ "template_if_listempty ::= KEY_IF_LISTEMPTY KEY_SPACE STRING KEY_BB_CLOSE",
 /*  56 */ "template_if_namedsetempty ::= KEY_IF_NAMEDSETEMPTY KEY_SPACE STRING KEY_BB_CLOSE",
 /*  57 */ "template_if_hasattrib ::= KEY_IF_HASATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE",
 /*  58 */ "template_if_attribequal ::= KEY_IF_ATTRIBEQUAL KEY_SPACE IDENTIFIER KEY_SPACE STRING KEY_BB_CLOSE",
 /*  59 */ "template_some_if ::= template_if_featureequal",
 /*  60 */ "template_some_if ::= template_if_varequal",
 /*  61 */ "template_some_if ::= template_if_listempty",
 /*  62 */ "template_some_if ::= template_if_namedsetempty",
 /*  63 */ "template_some_if ::= template_if_attribequal",
 /*  64 */ "template_some_if ::= template_if_hasattrib",
 /*  65 */ "template_if ::= template_some_if template_list KEY_ENDIF",
 /*  66 */ "template_if ::= template_some_if template_list KEY_ELSE template_list KEY_ENDIF",
 /*  67 */ "template_if ::= template_some_if KEY_ELSE template_list KEY_ENDIF",
 /*  68 */ "template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_BB_CLOSE",
 /*  69 */ "template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  70 */ "template_listappend_end ::= KEY_LISTAPPENDEND",
 /*  71 */ "template_namedsetadd ::= KEY_NAMEDSETADD KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  72 */ "template_namedsetadd_end ::= KEY_NAMEDSETADDEND",
 /*  73 */ "template_namedsetremove ::= KEY_NAMEDSETREMOVE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  74 */ "template_namedsetremove_end ::= KEY_NAMEDSETREMOVEEND",
 /*  75 */ "template_setvarnow ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE",
 /*  76 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_BARE_VAR STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  77 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIB STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  78 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIBNOMANGLE KEY_SPACE STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  79 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  80 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  81 */ "template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE",
 /*  82 */ "template_setvar ::= KEY_SETVAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  83 */ "template_setvar_end ::= KEY_SETVAREND",
 /*  84 */ "template_emitvar ::= KEY_EMITVAR KEY_SPACE STRING KEY_BB_CLOSE",
 /*  85 */ "template_string ::= CHAR",
 /*  86 */ "template_string ::= IDENTIFIER",
 /*  87 */ "template_string ::= KEY_BARE_ATTRIB",
 /*  88 */ "template_string ::= KEY_BARE_ATTRIBNOMANGLE",
 /*  89 */ "template_string ::= KEY_BARE_COUNTER",
 /*  90 */ "template_string ::= KEY_BARE_FEATURE",
 /*  91 */ "template_string ::= KEY_BARE_FEATURENOMANGLE",
 /*  92 */ "template_string ::= KEY_BARE_FEATUREJSONMANGLE",
 /*  93 */ "template_string ::= KEY_BARE_MAXLENGTH",
 /*  94 */ "template_string ::= KEY_BARE_SUBSTRING",
 /*  95 */ "template_string ::= KEY_BARE_FORMAT",
 /*  96 */ "template_string ::= KEY_BARE_FROM",
 /*  97 */ "template_string ::= KEY_BARE_TO",
 /*  98 */ "template_string ::= KEY_BARE_VAR",
 /*  99 */ "template_string ::= KEY_BARE_VARNOMANGLE",
 /* 100 */ "template_string ::= INTEGER",
 /* 101 */ "template_string ::= STRING",
 /* 102 */ "template_string ::= KEY_SPACE",
 /* 103 */ "template_string ::= KEY_DASH",
 /* 104 */ "template_string ::= KEY_NEWLINE",
 /* 105 */ "signed_integer ::= INTEGER",
 /* 106 */ "signed_integer ::= KEY_DASH INTEGER",
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
** second argument to TemplateLangParserAlloc() below.  This can be changed by
** putting an appropriate #define in the %include section of the input
** grammar.
*/
#ifndef TMPLGYYMALLOCARGTYPE
# define TMPLGYYMALLOCARGTYPE size_t
#endif

/* Initialize a new parser that has already been allocated.
*/
void TemplateLangParserInit(void *tmplgyypRawParser TemplateLangParserCTX_PDECL){
  tmplgyyParser *tmplgyypParser = (tmplgyyParser*)tmplgyypRawParser;
  TemplateLangParserCTX_STORE
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

#ifndef TemplateLangParser_ENGINEALWAYSONSTACK
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
** to TemplateLangParser and TemplateLangParserFree.
*/
void *TemplateLangParserAlloc(void *(*mallocProc)(TMPLGYYMALLOCARGTYPE) TemplateLangParserCTX_PDECL){
  tmplgyyParser *tmplgyypParser;
  tmplgyypParser = (tmplgyyParser*)(*mallocProc)( (TMPLGYYMALLOCARGTYPE)sizeof(tmplgyyParser) );
  if( tmplgyypParser ){
    TemplateLangParserCTX_STORE
    TemplateLangParserInit(tmplgyypParser TemplateLangParserCTX_PARAM);
  }
  return (void*)tmplgyypParser;
}
#endif /* TemplateLangParser_ENGINEALWAYSONSTACK */


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
  TemplateLangParserARG_FETCH
  TemplateLangParserCTX_FETCH
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
    case 1: /* KEY_ID_D */
    case 2: /* KEY_FIRSTMONAD */
    case 3: /* KEY_LASTMONAD */
    case 4: /* KEY_FEATURE */
    case 5: /* KEY_SPACE */
    case 6: /* INTEGER */
    case 7: /* KEY_BB_CLOSE */
    case 8: /* KEY_FEATUREJSONMANGLE */
    case 9: /* KEY_FEATURENOMANGLE */
    case 10: /* KEY_DBNAME */
    case 11: /* KEY_ATTRIB */
    case 12: /* IDENTIFIER */
    case 13: /* KEY_ATTRIB_NOMANGLE */
    case 14: /* KEY_COPYATTRIBS */
    case 15: /* KEY_COUNTER */
    case 16: /* STRING */
    case 17: /* KEY_BARE_FORMAT */
    case 18: /* KEY_SETCOUNTER */
    case 19: /* KEY_BARE_VAR */
    case 20: /* KEY_INCCOUNTER */
    case 21: /* KEY_DECCOUNTER */
    case 22: /* KEY_LISTEMIT */
    case 23: /* KEY_LISTCLEAR */
    case 24: /* KEY_NAMEDSETEMIT */
    case 25: /* KEY_NAMEDSETCLEAR */
    case 26: /* KEY_DICTLOOKUP */
    case 27: /* KEY_BARE_FEATURE */
    case 28: /* KEY_BARE_FEATURENOMANGLE */
    case 29: /* KEY_BARE_VARNOMANGLE */
    case 30: /* KEY_BARE_COUNTER */
    case 31: /* KEY_SETNIXING_ALL */
    case 32: /* KEY_SETNIXING_DOC */
    case 33: /* KEY_SETNIXING_OFF */
    case 34: /* KEY_IF_FEATUREEQUAL */
    case 35: /* KEY_IF_VAREQUAL */
    case 36: /* KEY_IF_LISTEMPTY */
    case 37: /* KEY_IF_NAMEDSETEMPTY */
    case 38: /* KEY_IF_HASATTRIB */
    case 39: /* KEY_IF_ATTRIBEQUAL */
    case 40: /* KEY_ENDIF */
    case 41: /* KEY_ELSE */
    case 42: /* KEY_LISTAPPENDBEGIN */
    case 43: /* KEY_LISTAPPENDEND */
    case 44: /* KEY_NAMEDSETADD */
    case 45: /* KEY_NAMEDSETADDEND */
    case 46: /* KEY_NAMEDSETREMOVE */
    case 47: /* KEY_NAMEDSETREMOVEEND */
    case 48: /* KEY_SETVAR */
    case 49: /* KEY_BARE_SUBSTRING */
    case 50: /* KEY_BARE_FROM */
    case 51: /* KEY_BARE_MAXLENGTH */
    case 52: /* KEY_BARE_ATTRIB */
    case 53: /* KEY_BARE_ATTRIBNOMANGLE */
    case 54: /* KEY_BARE_FEATUREJSONMANGLE */
    case 55: /* KEY_SETVAREND */
    case 56: /* KEY_EMITVAR */
    case 57: /* CHAR */
    case 58: /* KEY_BARE_TO */
    case 59: /* KEY_DASH */
    case 60: /* KEY_NEWLINE */
{
#line 37 "./templatelang.yxx"
 (tmplgyypminor->tmplgyy0)->clear(); delete (tmplgyypminor->tmplgyy0);
                    UNUSED(pEE); // Just to silence a warning
		  
#line 964 "./templatelang.c"
}
      break;
    case 61: /* top_value */
{
#line 57 "./templatelang.yxx"
 delete((tmplgyypminor->tmplgyy95)); 
#line 971 "./templatelang.c"
}
      break;
    case 62: /* template_list */
    case 63: /* template_list_element */
    case 87: /* template_some_if */
{
#line 61 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy95));
#line 980 "./templatelang.c"
}
      break;
    case 64: /* template_string */
{
#line 351 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy52));
#line 987 "./templatelang.c"
}
      break;
    case 65: /* template_if */
{
#line 263 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy22));
#line 994 "./templatelang.c"
}
      break;
    case 66: /* template_listappend */
{
#line 273 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy62));
#line 1001 "./templatelang.c"
}
      break;
    case 67: /* template_listappend_end */
{
#line 280 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy70));
#line 1008 "./templatelang.c"
}
      break;
    case 68: /* template_namedsetadd */
{
#line 285 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy160));
#line 1015 "./templatelang.c"
}
      break;
    case 69: /* template_namedsetadd_end */
{
#line 290 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy92));
#line 1022 "./templatelang.c"
}
      break;
    case 70: /* template_namedsetremove */
{
#line 295 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy77));
#line 1029 "./templatelang.c"
}
      break;
    case 71: /* template_namedsetremove_end */
{
#line 300 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy73));
#line 1036 "./templatelang.c"
}
      break;
    case 72: /* template_setvarnow */
{
#line 306 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy16));
#line 1043 "./templatelang.c"
}
      break;
    case 73: /* template_setvarsubstring */
{
#line 311 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy93));
#line 1050 "./templatelang.c"
}
      break;
    case 74: /* template_setvar */
{
#line 331 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy81));
#line 1057 "./templatelang.c"
}
      break;
    case 75: /* template_setvar_end */
{
#line 337 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy29));
#line 1064 "./templatelang.c"
}
      break;
    case 76: /* template_emitvar */
{
#line 343 "./templatelang.yxx"
delete((tmplgyypminor->tmplgyy107));
#line 1071 "./templatelang.c"
}
      break;
    case 77: /* template_setnixing */
{
#line 185 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy80));
#line 1078 "./templatelang.c"
}
      break;
    case 78: /* template_dictlookup_feature */
{
#line 154 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy85));
#line 1085 "./templatelang.c"
}
      break;
    case 79: /* template_dictlookup_var */
{
#line 165 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy90));
#line 1092 "./templatelang.c"
}
      break;
    case 80: /* template_dictlookup_counter */
{
#line 177 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy45));
#line 1099 "./templatelang.c"
}
      break;
    case 81: /* template_if_featureequal */
{
#line 202 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy10));
#line 1106 "./templatelang.c"
}
      break;
    case 82: /* template_if_varequal */
{
#line 209 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy108));
#line 1113 "./templatelang.c"
}
      break;
    case 83: /* template_if_listempty */
{
#line 220 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy147));
#line 1120 "./templatelang.c"
}
      break;
    case 84: /* template_if_namedsetempty */
{
#line 227 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy4));
#line 1127 "./templatelang.c"
}
      break;
    case 85: /* template_if_hasattrib */
{
#line 234 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy68));
#line 1134 "./templatelang.c"
}
      break;
    case 86: /* template_if_attribequal */
{
#line 241 "./templatelang.yxx"
delete ((tmplgyypminor->tmplgyy156));
#line 1141 "./templatelang.c"
}
      break;
    case 88: /* signed_integer */
{
#line 395 "./templatelang.yxx"
;
#line 1148 "./templatelang.c"
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
void TemplateLangParserFinalize(void *p){
  tmplgyyParser *pParser = (tmplgyyParser*)p;
  while( pParser->tmplgyytos>pParser->tmplgyystack ) tmplgyy_pop_parser_stack(pParser);
#if TMPLGYYSTACKDEPTH<=0
  if( pParser->tmplgyystack!=&pParser->tmplgyystk0 ) free(pParser->tmplgyystack);
#endif
}

#ifndef TemplateLangParser_ENGINEALWAYSONSTACK
/* 
** Deallocate and destroy a parser.  Destructors are called for
** all stack elements before shutting the parser down.
**
** If the TMPLGYYPARSEFREENEVERNULL macro exists (for example because it
** is defined in a %include section of the input grammar) then it is
** assumed that the input pointer is never NULL.
*/
void TemplateLangParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
#ifndef TMPLGYYPARSEFREENEVERNULL
  if( p==0 ) return;
#endif
  TemplateLangParserFinalize(p);
  (*freeProc)(p);
}
#endif /* TemplateLangParser_ENGINEALWAYSONSTACK */

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef TMPLGYYTRACKMAXSTACKDEPTH
int TemplateLangParserStackPeak(void *p){
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
int TemplateLangParserCoverage(FILE *out){
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
   TemplateLangParserARG_FETCH
   TemplateLangParserCTX_FETCH
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
   TemplateLangParserARG_STORE /* Suppress warning about unused %extra_argument var */
   TemplateLangParserCTX_STORE
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
  TemplateLangParserTOKENTYPE tmplgyyMinor        /* The minor token to shift in */
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
    61,  /* (0) top_value ::= template_list */
    62,  /* (1) template_list ::= template_list_element */
    62,  /* (2) template_list ::= template_list template_list_element */
    63,  /* (3) template_list_element ::= template_string */
    63,  /* (4) template_list_element ::= template_if */
    63,  /* (5) template_list_element ::= KEY_ID_D */
    63,  /* (6) template_list_element ::= KEY_FIRSTMONAD */
    63,  /* (7) template_list_element ::= KEY_LASTMONAD */
    63,  /* (8) template_list_element ::= KEY_FEATURE KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (9) template_list_element ::= KEY_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (10) template_list_element ::= KEY_FEATURENOMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (11) template_list_element ::= KEY_DBNAME */
    63,  /* (12) template_list_element ::= KEY_ATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
    63,  /* (13) template_list_element ::= KEY_ATTRIB_NOMANGLE KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
    63,  /* (14) template_list_element ::= KEY_COPYATTRIBS KEY_BB_CLOSE */
    63,  /* (15) template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (16) template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_FORMAT KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (17) template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (18) template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (19) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (20) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (21) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (22) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (23) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
    63,  /* (24) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (25) template_list_element ::= KEY_LISTEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (26) template_list_element ::= KEY_LISTCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (27) template_list_element ::= KEY_NAMEDSETEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (28) template_list_element ::= KEY_NAMEDSETCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
    63,  /* (29) template_list_element ::= template_listappend */
    63,  /* (30) template_list_element ::= template_listappend_end */
    63,  /* (31) template_list_element ::= template_namedsetadd */
    63,  /* (32) template_list_element ::= template_namedsetadd_end */
    63,  /* (33) template_list_element ::= template_namedsetremove */
    63,  /* (34) template_list_element ::= template_namedsetremove_end */
    63,  /* (35) template_list_element ::= template_setvarnow */
    63,  /* (36) template_list_element ::= template_setvarsubstring */
    63,  /* (37) template_list_element ::= template_setvar */
    63,  /* (38) template_list_element ::= template_setvar_end */
    63,  /* (39) template_list_element ::= template_emitvar */
    63,  /* (40) template_list_element ::= template_setnixing */
    63,  /* (41) template_list_element ::= template_dictlookup_feature */
    63,  /* (42) template_list_element ::= template_dictlookup_var */
    63,  /* (43) template_list_element ::= template_dictlookup_counter */
    78,  /* (44) template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
    78,  /* (45) template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
    79,  /* (46) template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    79,  /* (47) template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VARNOMANGLE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    80,  /* (48) template_dictlookup_counter ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_COUNTER KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    77,  /* (49) template_setnixing ::= KEY_SETNIXING_ALL */
    77,  /* (50) template_setnixing ::= KEY_SETNIXING_DOC */
    77,  /* (51) template_setnixing ::= KEY_SETNIXING_OFF */
    81,  /* (52) template_if_featureequal ::= KEY_IF_FEATUREEQUAL KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
    82,  /* (53) template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    82,  /* (54) template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
    83,  /* (55) template_if_listempty ::= KEY_IF_LISTEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
    84,  /* (56) template_if_namedsetempty ::= KEY_IF_NAMEDSETEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
    85,  /* (57) template_if_hasattrib ::= KEY_IF_HASATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
    86,  /* (58) template_if_attribequal ::= KEY_IF_ATTRIBEQUAL KEY_SPACE IDENTIFIER KEY_SPACE STRING KEY_BB_CLOSE */
    87,  /* (59) template_some_if ::= template_if_featureequal */
    87,  /* (60) template_some_if ::= template_if_varequal */
    87,  /* (61) template_some_if ::= template_if_listempty */
    87,  /* (62) template_some_if ::= template_if_namedsetempty */
    87,  /* (63) template_some_if ::= template_if_attribequal */
    87,  /* (64) template_some_if ::= template_if_hasattrib */
    65,  /* (65) template_if ::= template_some_if template_list KEY_ENDIF */
    65,  /* (66) template_if ::= template_some_if template_list KEY_ELSE template_list KEY_ENDIF */
    65,  /* (67) template_if ::= template_some_if KEY_ELSE template_list KEY_ENDIF */
    66,  /* (68) template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_BB_CLOSE */
    66,  /* (69) template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    67,  /* (70) template_listappend_end ::= KEY_LISTAPPENDEND */
    68,  /* (71) template_namedsetadd ::= KEY_NAMEDSETADD KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    69,  /* (72) template_namedsetadd_end ::= KEY_NAMEDSETADDEND */
    70,  /* (73) template_namedsetremove ::= KEY_NAMEDSETREMOVE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    71,  /* (74) template_namedsetremove_end ::= KEY_NAMEDSETREMOVEEND */
    72,  /* (75) template_setvarnow ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
    73,  /* (76) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_BARE_VAR STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    73,  /* (77) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIB STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    73,  /* (78) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIBNOMANGLE KEY_SPACE STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    73,  /* (79) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    73,  /* (80) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    73,  /* (81) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
    74,  /* (82) template_setvar ::= KEY_SETVAR KEY_SPACE STRING KEY_BB_CLOSE */
    75,  /* (83) template_setvar_end ::= KEY_SETVAREND */
    76,  /* (84) template_emitvar ::= KEY_EMITVAR KEY_SPACE STRING KEY_BB_CLOSE */
    64,  /* (85) template_string ::= CHAR */
    64,  /* (86) template_string ::= IDENTIFIER */
    64,  /* (87) template_string ::= KEY_BARE_ATTRIB */
    64,  /* (88) template_string ::= KEY_BARE_ATTRIBNOMANGLE */
    64,  /* (89) template_string ::= KEY_BARE_COUNTER */
    64,  /* (90) template_string ::= KEY_BARE_FEATURE */
    64,  /* (91) template_string ::= KEY_BARE_FEATURENOMANGLE */
    64,  /* (92) template_string ::= KEY_BARE_FEATUREJSONMANGLE */
    64,  /* (93) template_string ::= KEY_BARE_MAXLENGTH */
    64,  /* (94) template_string ::= KEY_BARE_SUBSTRING */
    64,  /* (95) template_string ::= KEY_BARE_FORMAT */
    64,  /* (96) template_string ::= KEY_BARE_FROM */
    64,  /* (97) template_string ::= KEY_BARE_TO */
    64,  /* (98) template_string ::= KEY_BARE_VAR */
    64,  /* (99) template_string ::= KEY_BARE_VARNOMANGLE */
    64,  /* (100) template_string ::= INTEGER */
    64,  /* (101) template_string ::= STRING */
    64,  /* (102) template_string ::= KEY_SPACE */
    64,  /* (103) template_string ::= KEY_DASH */
    64,  /* (104) template_string ::= KEY_NEWLINE */
    88,  /* (105) signed_integer ::= INTEGER */
    88,  /* (106) signed_integer ::= KEY_DASH INTEGER */
};

/* For rule J, tmplgyyRuleInfoNRhs[J] contains the negative of the number
** of symbols on the right-hand side of that rule. */
static const signed char tmplgyyRuleInfoNRhs[] = {
   -1,  /* (0) top_value ::= template_list */
   -1,  /* (1) template_list ::= template_list_element */
   -2,  /* (2) template_list ::= template_list template_list_element */
   -1,  /* (3) template_list_element ::= template_string */
   -1,  /* (4) template_list_element ::= template_if */
   -1,  /* (5) template_list_element ::= KEY_ID_D */
   -1,  /* (6) template_list_element ::= KEY_FIRSTMONAD */
   -1,  /* (7) template_list_element ::= KEY_LASTMONAD */
   -4,  /* (8) template_list_element ::= KEY_FEATURE KEY_SPACE INTEGER KEY_BB_CLOSE */
   -4,  /* (9) template_list_element ::= KEY_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
   -4,  /* (10) template_list_element ::= KEY_FEATURENOMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
   -1,  /* (11) template_list_element ::= KEY_DBNAME */
   -4,  /* (12) template_list_element ::= KEY_ATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
   -4,  /* (13) template_list_element ::= KEY_ATTRIB_NOMANGLE KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
   -2,  /* (14) template_list_element ::= KEY_COPYATTRIBS KEY_BB_CLOSE */
   -4,  /* (15) template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_BB_CLOSE */
   -8,  /* (16) template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_FORMAT KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (17) template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
   -8,  /* (18) template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (19) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (20) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
   -8,  /* (21) template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (22) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (23) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
   -8,  /* (24) template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (25) template_list_element ::= KEY_LISTEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (26) template_list_element ::= KEY_LISTCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (27) template_list_element ::= KEY_NAMEDSETEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (28) template_list_element ::= KEY_NAMEDSETCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (29) template_list_element ::= template_listappend */
   -1,  /* (30) template_list_element ::= template_listappend_end */
   -1,  /* (31) template_list_element ::= template_namedsetadd */
   -1,  /* (32) template_list_element ::= template_namedsetadd_end */
   -1,  /* (33) template_list_element ::= template_namedsetremove */
   -1,  /* (34) template_list_element ::= template_namedsetremove_end */
   -1,  /* (35) template_list_element ::= template_setvarnow */
   -1,  /* (36) template_list_element ::= template_setvarsubstring */
   -1,  /* (37) template_list_element ::= template_setvar */
   -1,  /* (38) template_list_element ::= template_setvar_end */
   -1,  /* (39) template_list_element ::= template_emitvar */
   -1,  /* (40) template_list_element ::= template_setnixing */
   -1,  /* (41) template_list_element ::= template_dictlookup_feature */
   -1,  /* (42) template_list_element ::= template_dictlookup_var */
   -1,  /* (43) template_list_element ::= template_dictlookup_counter */
  -10,  /* (44) template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
  -10,  /* (45) template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
  -10,  /* (46) template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
  -10,  /* (47) template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VARNOMANGLE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
  -10,  /* (48) template_dictlookup_counter ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_COUNTER KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (49) template_setnixing ::= KEY_SETNIXING_ALL */
   -1,  /* (50) template_setnixing ::= KEY_SETNIXING_DOC */
   -1,  /* (51) template_setnixing ::= KEY_SETNIXING_OFF */
   -6,  /* (52) template_if_featureequal ::= KEY_IF_FEATUREEQUAL KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (53) template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -8,  /* (54) template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (55) template_if_listempty ::= KEY_IF_LISTEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (56) template_if_namedsetempty ::= KEY_IF_NAMEDSETEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
   -4,  /* (57) template_if_hasattrib ::= KEY_IF_HASATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
   -6,  /* (58) template_if_attribequal ::= KEY_IF_ATTRIBEQUAL KEY_SPACE IDENTIFIER KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (59) template_some_if ::= template_if_featureequal */
   -1,  /* (60) template_some_if ::= template_if_varequal */
   -1,  /* (61) template_some_if ::= template_if_listempty */
   -1,  /* (62) template_some_if ::= template_if_namedsetempty */
   -1,  /* (63) template_some_if ::= template_if_attribequal */
   -1,  /* (64) template_some_if ::= template_if_hasattrib */
   -3,  /* (65) template_if ::= template_some_if template_list KEY_ENDIF */
   -5,  /* (66) template_if ::= template_some_if template_list KEY_ELSE template_list KEY_ENDIF */
   -4,  /* (67) template_if ::= template_some_if KEY_ELSE template_list KEY_ENDIF */
   -4,  /* (68) template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_BB_CLOSE */
   -6,  /* (69) template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (70) template_listappend_end ::= KEY_LISTAPPENDEND */
   -6,  /* (71) template_namedsetadd ::= KEY_NAMEDSETADD KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (72) template_namedsetadd_end ::= KEY_NAMEDSETADDEND */
   -6,  /* (73) template_namedsetremove ::= KEY_NAMEDSETREMOVE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (74) template_namedsetremove_end ::= KEY_NAMEDSETREMOVEEND */
   -6,  /* (75) template_setvarnow ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
  -16,  /* (76) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_BARE_VAR STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
  -17,  /* (77) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIB STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
  -18,  /* (78) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIBNOMANGLE KEY_SPACE STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
  -18,  /* (79) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
  -18,  /* (80) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
  -18,  /* (81) template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
   -4,  /* (82) template_setvar ::= KEY_SETVAR KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (83) template_setvar_end ::= KEY_SETVAREND */
   -4,  /* (84) template_emitvar ::= KEY_EMITVAR KEY_SPACE STRING KEY_BB_CLOSE */
   -1,  /* (85) template_string ::= CHAR */
   -1,  /* (86) template_string ::= IDENTIFIER */
   -1,  /* (87) template_string ::= KEY_BARE_ATTRIB */
   -1,  /* (88) template_string ::= KEY_BARE_ATTRIBNOMANGLE */
   -1,  /* (89) template_string ::= KEY_BARE_COUNTER */
   -1,  /* (90) template_string ::= KEY_BARE_FEATURE */
   -1,  /* (91) template_string ::= KEY_BARE_FEATURENOMANGLE */
   -1,  /* (92) template_string ::= KEY_BARE_FEATUREJSONMANGLE */
   -1,  /* (93) template_string ::= KEY_BARE_MAXLENGTH */
   -1,  /* (94) template_string ::= KEY_BARE_SUBSTRING */
   -1,  /* (95) template_string ::= KEY_BARE_FORMAT */
   -1,  /* (96) template_string ::= KEY_BARE_FROM */
   -1,  /* (97) template_string ::= KEY_BARE_TO */
   -1,  /* (98) template_string ::= KEY_BARE_VAR */
   -1,  /* (99) template_string ::= KEY_BARE_VARNOMANGLE */
   -1,  /* (100) template_string ::= INTEGER */
   -1,  /* (101) template_string ::= STRING */
   -1,  /* (102) template_string ::= KEY_SPACE */
   -1,  /* (103) template_string ::= KEY_DASH */
   -1,  /* (104) template_string ::= KEY_NEWLINE */
   -1,  /* (105) signed_integer ::= INTEGER */
   -2,  /* (106) signed_integer ::= KEY_DASH INTEGER */
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
  TemplateLangParserTOKENTYPE tmplgyyLookaheadToken  /* Value of the lookahead token */
  TemplateLangParserCTX_PDECL                   /* %extra_context */
){
  int tmplgyygoto;                     /* The next state */
  TMPLGYYACTIONTYPE tmplgyyact;             /* The next action */
  tmplgyyStackEntry *tmplgyymsp;            /* The top of the parser's stack */
  int tmplgyysize;                     /* Amount to pop the stack */
  TemplateLangParserARG_FETCH
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
      case 0: /* top_value ::= template_list */
#line 58 "./templatelang.yxx"
{ pEE->setTopNode(tmplgyymsp[0].minor.tmplgyy95); }
#line 1748 "./templatelang.c"
        break;
      case 1: /* template_list ::= template_list_element */
#line 63 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy95; }
#line 1753 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 2: /* template_list ::= template_list template_list_element */
#line 65 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy95; tmplgyylhsminor.tmplgyy95->setNext(tmplgyymsp[-1].minor.tmplgyy95); }
#line 1759 "./templatelang.c"
  tmplgyymsp[-1].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 3: /* template_list_element ::= template_string */
#line 70 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy52; }
#line 1765 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 4: /* template_list_element ::= template_if */
#line 72 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy22; }
#line 1771 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 5: /* template_list_element ::= KEY_ID_D */
{  tmplgyy_destructor(tmplgyypParser,1,&tmplgyymsp[0].minor);
#line 74 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy95 = new TemplateSimpleNode(kTemplateID_D); }
#line 1778 "./templatelang.c"
}
        break;
      case 6: /* template_list_element ::= KEY_FIRSTMONAD */
{  tmplgyy_destructor(tmplgyypParser,2,&tmplgyymsp[0].minor);
#line 76 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy95 = new TemplateSimpleNode(kTemplateFirstMonad); }
#line 1785 "./templatelang.c"
}
        break;
      case 7: /* template_list_element ::= KEY_LASTMONAD */
{  tmplgyy_destructor(tmplgyypParser,3,&tmplgyymsp[0].minor);
#line 78 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy95 = new TemplateSimpleNode(kTemplateLastMonad); }
#line 1792 "./templatelang.c"
}
        break;
      case 8: /* template_list_element ::= KEY_FEATURE KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,4,&tmplgyymsp[-3].minor);
#line 80 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateFeature((long) tmplgyymsp[-1].minor.tmplgyy0->integer, kMKXML); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1799 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 9: /* template_list_element ::= KEY_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,8,&tmplgyymsp[-3].minor);
#line 82 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateFeature((long) tmplgyymsp[-1].minor.tmplgyy0->integer, kMKJSON); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1808 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 10: /* template_list_element ::= KEY_FEATURENOMANGLE KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,9,&tmplgyymsp[-3].minor);
#line 84 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateFeature((long) tmplgyymsp[-1].minor.tmplgyy0->integer, kMKNone); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1817 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 11: /* template_list_element ::= KEY_DBNAME */
{  tmplgyy_destructor(tmplgyypParser,10,&tmplgyymsp[0].minor);
#line 86 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy95 = new TemplateSimpleNode(kTemplateDBName); }
#line 1826 "./templatelang.c"
}
        break;
      case 12: /* template_list_element ::= KEY_ATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,11,&tmplgyymsp[-3].minor);
#line 88 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateAttrib(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1833 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 13: /* template_list_element ::= KEY_ATTRIB_NOMANGLE KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,13,&tmplgyymsp[-3].minor);
#line 90 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateAttribNoMangle(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1842 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 14: /* template_list_element ::= KEY_COPYATTRIBS KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,14,&tmplgyymsp[-1].minor);
#line 92 "./templatelang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy95 = new TemplateCopyAttribs(); }
#line 1851 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 15: /* template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,15,&tmplgyymsp[-3].minor);
#line 94 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateCounter(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1859 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 16: /* template_list_element ::= KEY_COUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_FORMAT KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,15,&tmplgyymsp[-7].minor);
#line 96 "./templatelang.yxx"
{ tmplgyymsp[-7].minor.tmplgyy95 = new TemplateCounterFormat(tmplgyymsp[-5].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-5].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;}
#line 1868 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,17,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 17: /* template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,18,&tmplgyymsp[-5].minor);
#line 98 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy95 = new TemplateSetCounter(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1880 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 18: /* template_list_element ::= KEY_SETCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,18,&tmplgyymsp[-7].minor);
#line 100 "./templatelang.yxx"
{ tmplgyymsp[-7].minor.tmplgyy95 = new TemplateSetCounterVar(tmplgyymsp[-5].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-5].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1890 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 19: /* template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-3].minor);
#line 102 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateIncCounter(tmplgyymsp[-1].minor.tmplgyy0->extractString(), 1, 0); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1902 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 20: /* template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-5].minor);
#line 104 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy95 = new TemplateIncCounter(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->integer, 0); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1911 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 21: /* template_list_element ::= KEY_INCCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,20,&tmplgyymsp[-7].minor);
#line 106 "./templatelang.yxx"
{ tmplgyymsp[-7].minor.tmplgyy95 = new TemplateIncCounter(tmplgyymsp[-5].minor.tmplgyy0->extractString(), 0, tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-5].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1921 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 22: /* template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-3].minor);
#line 108 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateDecCounter(tmplgyymsp[-1].minor.tmplgyy0->extractString(), 1, 0); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1933 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 23: /* template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-5].minor);
#line 110 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy95 = new TemplateDecCounter(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->integer, 0); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1942 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 24: /* template_list_element ::= KEY_DECCOUNTER KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,21,&tmplgyymsp[-7].minor);
#line 112 "./templatelang.yxx"
{ tmplgyymsp[-7].minor.tmplgyy95 = new TemplateDecCounter(tmplgyymsp[-5].minor.tmplgyy0->extractString(), 0, tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-5].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1952 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 25: /* template_list_element ::= KEY_LISTEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,22,&tmplgyymsp[-5].minor);
#line 114 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy95 = new TemplateListEmit(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1964 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 26: /* template_list_element ::= KEY_LISTCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,23,&tmplgyymsp[-3].minor);
#line 116 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateListClear(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1974 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 27: /* template_list_element ::= KEY_NAMEDSETEMIT KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,24,&tmplgyymsp[-5].minor);
#line 118 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy95 = new TemplateNamedSetEmit(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1983 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 28: /* template_list_element ::= KEY_NAMEDSETCLEAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,25,&tmplgyymsp[-3].minor);
#line 120 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy95 = new TemplateNamedSetClear(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 1993 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 29: /* template_list_element ::= template_listappend */
#line 122 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy62; }
#line 2001 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 30: /* template_list_element ::= template_listappend_end */
#line 124 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy70; }
#line 2007 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 31: /* template_list_element ::= template_namedsetadd */
#line 126 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy160; }
#line 2013 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 32: /* template_list_element ::= template_namedsetadd_end */
#line 128 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy92; }
#line 2019 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 33: /* template_list_element ::= template_namedsetremove */
#line 130 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy77; }
#line 2025 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 34: /* template_list_element ::= template_namedsetremove_end */
#line 132 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy73; }
#line 2031 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 35: /* template_list_element ::= template_setvarnow */
#line 134 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy16; }
#line 2037 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 36: /* template_list_element ::= template_setvarsubstring */
#line 136 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy93; }
#line 2043 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 37: /* template_list_element ::= template_setvar */
#line 138 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy81; }
#line 2049 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 38: /* template_list_element ::= template_setvar_end */
#line 140 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy29; }
#line 2055 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 39: /* template_list_element ::= template_emitvar */
#line 142 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy107; }
#line 2061 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 40: /* template_list_element ::= template_setnixing */
#line 144 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy80; }
#line 2067 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 41: /* template_list_element ::= template_dictlookup_feature */
#line 146 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy85; }
#line 2073 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 42: /* template_list_element ::= template_dictlookup_var */
#line 148 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy90; }
#line 2079 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 43: /* template_list_element ::= template_dictlookup_counter */
#line 150 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy45; }
#line 2085 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 44: /* template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-9].minor);
#line 156 "./templatelang.yxx"
{ tmplgyymsp[-9].minor.tmplgyy85 = new TemplateDictlookupFeature(tmplgyymsp[-7].minor.tmplgyy0->extractString(), (long) tmplgyymsp[-3].minor.tmplgyy0->integer, tmplgyymsp[-1].minor.tmplgyy0->extractString(), true); 
  delete tmplgyymsp[-7].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 2094 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,27,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 45: /* template_dictlookup_feature ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-9].minor);
#line 160 "./templatelang.yxx"
{ tmplgyymsp[-9].minor.tmplgyy85 = new TemplateDictlookupFeature(tmplgyymsp[-7].minor.tmplgyy0->extractString(), (long) tmplgyymsp[-3].minor.tmplgyy0->integer, tmplgyymsp[-1].minor.tmplgyy0->extractString(), false); 
  delete tmplgyymsp[-7].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 2109 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,28,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 46: /* template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-9].minor);
#line 167 "./templatelang.yxx"
{ tmplgyymsp[-9].minor.tmplgyy90 = new TemplateDictlookupVar(tmplgyymsp[-7].minor.tmplgyy0->extractString(), tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString(), true); 
  delete tmplgyymsp[-7].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 2124 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 47: /* template_dictlookup_var ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_VARNOMANGLE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-9].minor);
#line 171 "./templatelang.yxx"
{ tmplgyymsp[-9].minor.tmplgyy90 = new TemplateDictlookupVar(tmplgyymsp[-7].minor.tmplgyy0->extractString(), tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString(), false); 
  delete tmplgyymsp[-7].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 2139 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,29,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 48: /* template_dictlookup_counter ::= KEY_DICTLOOKUP KEY_SPACE STRING KEY_SPACE KEY_BARE_COUNTER KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,26,&tmplgyymsp[-9].minor);
#line 179 "./templatelang.yxx"
{ tmplgyymsp[-9].minor.tmplgyy45 = new TemplateDictlookupCounter(tmplgyymsp[-7].minor.tmplgyy0->extractString(), tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString(), true); 
  delete tmplgyymsp[-7].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;
}
#line 2154 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,30,&tmplgyymsp[-5].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 49: /* template_setnixing ::= KEY_SETNIXING_ALL */
{  tmplgyy_destructor(tmplgyypParser,31,&tmplgyymsp[0].minor);
#line 187 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy80 = new TemplateNixing(kTNTAll); 
}
#line 2168 "./templatelang.c"
}
        break;
      case 50: /* template_setnixing ::= KEY_SETNIXING_DOC */
{  tmplgyy_destructor(tmplgyypParser,32,&tmplgyymsp[0].minor);
#line 190 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy80 = new TemplateNixing(kTNTDoc); 
}
#line 2176 "./templatelang.c"
}
        break;
      case 51: /* template_setnixing ::= KEY_SETNIXING_OFF */
{  tmplgyy_destructor(tmplgyypParser,33,&tmplgyymsp[0].minor);
#line 193 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy80 = new TemplateNixing(kTNTOff); 
}
#line 2184 "./templatelang.c"
}
        break;
      case 52: /* template_if_featureequal ::= KEY_IF_FEATUREEQUAL KEY_SPACE INTEGER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,34,&tmplgyymsp[-5].minor);
#line 204 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy10 = new TemplateIfFeatureEqual((long) tmplgyymsp[-3].minor.tmplgyy0->integer, tmplgyymsp[-1].minor.tmplgyy0->extractString()); 
  delete tmplgyymsp[-1].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0;			     
}
#line 2193 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 53: /* template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,35,&tmplgyymsp[-5].minor);
#line 211 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy108 = new TemplateIfVarEqual(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString(), false); 
  delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;			     
}
#line 2205 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 54: /* template_if_varequal ::= KEY_IF_VAREQUAL KEY_SPACE STRING KEY_SPACE KEY_BARE_VAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,35,&tmplgyymsp[-7].minor);
#line 215 "./templatelang.yxx"
{ tmplgyymsp[-7].minor.tmplgyy108 = new TemplateIfVarEqual(tmplgyymsp[-5].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString(), true); 
  delete tmplgyymsp[-5].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0;			     
}
#line 2217 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 55: /* template_if_listempty ::= KEY_IF_LISTEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,36,&tmplgyymsp[-3].minor);
#line 222 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy147 = new TemplateIfListEmpty(tmplgyymsp[-1].minor.tmplgyy0->extractString());
  delete tmplgyymsp[-1].minor.tmplgyy0; 
}
#line 2231 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 56: /* template_if_namedsetempty ::= KEY_IF_NAMEDSETEMPTY KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,37,&tmplgyymsp[-3].minor);
#line 229 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy4 = new TemplateIfNamedSetEmpty(tmplgyymsp[-1].minor.tmplgyy0->extractString());
  delete tmplgyymsp[-1].minor.tmplgyy0; 
}
#line 2242 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 57: /* template_if_hasattrib ::= KEY_IF_HASATTRIB KEY_SPACE IDENTIFIER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,38,&tmplgyymsp[-3].minor);
#line 236 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy68 = new TemplateIfHasAttrib(tmplgyymsp[-1].minor.tmplgyy0->extractString()); 
  delete tmplgyymsp[-1].minor.tmplgyy0; 
}
#line 2253 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 58: /* template_if_attribequal ::= KEY_IF_ATTRIBEQUAL KEY_SPACE IDENTIFIER KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,39,&tmplgyymsp[-5].minor);
#line 243 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy156 = new TemplateIfAttribEqual(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); 
  delete tmplgyymsp[-1].minor.tmplgyy0; delete tmplgyymsp[-3].minor.tmplgyy0; 
}
#line 2264 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 59: /* template_some_if ::= template_if_featureequal */
#line 250 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy10; }
#line 2273 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 60: /* template_some_if ::= template_if_varequal */
#line 252 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy108; }
#line 2279 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 61: /* template_some_if ::= template_if_listempty */
#line 254 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy147; }
#line 2285 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 62: /* template_some_if ::= template_if_namedsetempty */
#line 256 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy4; }
#line 2291 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 63: /* template_some_if ::= template_if_attribequal */
#line 258 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy156; }
#line 2297 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 64: /* template_some_if ::= template_if_hasattrib */
#line 260 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy95 = tmplgyymsp[0].minor.tmplgyy68; }
#line 2303 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy95 = tmplgyylhsminor.tmplgyy95;
        break;
      case 65: /* template_if ::= template_some_if template_list KEY_ENDIF */
#line 265 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy22 = new TemplateIf(tmplgyymsp[-2].minor.tmplgyy95, tmplgyymsp[-1].minor.tmplgyy95, 0); }
#line 2309 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,40,&tmplgyymsp[0].minor);
  tmplgyymsp[-2].minor.tmplgyy22 = tmplgyylhsminor.tmplgyy22;
        break;
      case 66: /* template_if ::= template_some_if template_list KEY_ELSE template_list KEY_ENDIF */
#line 267 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy22 = new TemplateIf(tmplgyymsp[-4].minor.tmplgyy95, tmplgyymsp[-3].minor.tmplgyy95, tmplgyymsp[-1].minor.tmplgyy95); }
#line 2316 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,41,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,40,&tmplgyymsp[0].minor);
  tmplgyymsp[-4].minor.tmplgyy22 = tmplgyylhsminor.tmplgyy22;
        break;
      case 67: /* template_if ::= template_some_if KEY_ELSE template_list KEY_ENDIF */
#line 269 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy22 = new TemplateIf(tmplgyymsp[-3].minor.tmplgyy95, 0, tmplgyymsp[-1].minor.tmplgyy95); }
#line 2324 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,41,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,40,&tmplgyymsp[0].minor);
  tmplgyymsp[-3].minor.tmplgyy22 = tmplgyylhsminor.tmplgyy22;
        break;
      case 68: /* template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,42,&tmplgyymsp[-3].minor);
#line 275 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy62 = new TemplateListAppendBegin(tmplgyymsp[-1].minor.tmplgyy0->extractString(), 0); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2333 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 69: /* template_listappend ::= KEY_LISTAPPENDBEGIN KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,42,&tmplgyymsp[-5].minor);
#line 277 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy62 = new TemplateListAppendBegin(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2342 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 70: /* template_listappend_end ::= KEY_LISTAPPENDEND */
{  tmplgyy_destructor(tmplgyypParser,43,&tmplgyymsp[0].minor);
#line 282 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy70 = new TemplateListAppendEnd(); }
#line 2352 "./templatelang.c"
}
        break;
      case 71: /* template_namedsetadd ::= KEY_NAMEDSETADD KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,44,&tmplgyymsp[-5].minor);
#line 287 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy160 = new TemplateNamedSetAddBegin(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2359 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 72: /* template_namedsetadd_end ::= KEY_NAMEDSETADDEND */
{  tmplgyy_destructor(tmplgyypParser,45,&tmplgyymsp[0].minor);
#line 292 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy92 = new TemplateNamedSetAddEnd(); }
#line 2369 "./templatelang.c"
}
        break;
      case 73: /* template_namedsetremove ::= KEY_NAMEDSETREMOVE KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,46,&tmplgyymsp[-5].minor);
#line 297 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy77 = new TemplateNamedSetRemoveBegin(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2376 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 74: /* template_namedsetremove_end ::= KEY_NAMEDSETREMOVEEND */
{  tmplgyy_destructor(tmplgyypParser,47,&tmplgyymsp[0].minor);
#line 302 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy73 = new TemplateNamedSetRemoveEnd(); }
#line 2386 "./templatelang.c"
}
        break;
      case 75: /* template_setvarnow ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-5].minor);
#line 308 "./templatelang.yxx"
{ tmplgyymsp[-5].minor.tmplgyy16 = new TemplateSetVarNow(tmplgyymsp[-3].minor.tmplgyy0->extractString(), tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-3].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2393 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 76: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_BARE_VAR STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-15].minor);
#line 313 "./templatelang.yxx"
{ tmplgyymsp[-15].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-13].minor.tmplgyy0->extractString(), tmplgyymsp[-9].minor.tmplgyy0->extractString(), tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-13].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2403 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-14].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 77: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIB STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-16].minor);
#line 316 "./templatelang.yxx"
{ tmplgyymsp[-16].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-14].minor.tmplgyy0->extractString(), tmplgyymsp[-9].minor.tmplgyy0->extractString(), kMKXML, tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-14].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2421 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-15].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-13].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,52,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 78: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_ATTRIBNOMANGLE KEY_SPACE STRING KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-17].minor);
#line 319 "./templatelang.yxx"
{ tmplgyymsp[-17].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-15].minor.tmplgyy0->extractString(), tmplgyymsp[-9].minor.tmplgyy0->extractString(), kMKNone, tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-15].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2440 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-16].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-14].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-13].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,53,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 79: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-17].minor);
#line 322 "./templatelang.yxx"
{ tmplgyymsp[-17].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-15].minor.tmplgyy0->extractString(), (long) tmplgyymsp[-9].minor.tmplgyy0->integer, kMKXML, tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-15].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2460 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-16].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-14].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-13].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,27,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 80: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATURENOMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-17].minor);
#line 325 "./templatelang.yxx"
{ tmplgyymsp[-17].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-15].minor.tmplgyy0->extractString(), (long) tmplgyymsp[-9].minor.tmplgyy0->integer, kMKNone, tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-15].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2480 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-16].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-14].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-13].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,28,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 81: /* template_setvarsubstring ::= KEY_SETVAR KEY_SPACE STRING KEY_SPACE KEY_BARE_SUBSTRING KEY_SPACE KEY_BARE_FEATUREJSONMANGLE KEY_SPACE INTEGER KEY_SPACE KEY_BARE_FROM KEY_SPACE signed_integer KEY_SPACE KEY_BARE_MAXLENGTH KEY_SPACE INTEGER KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-17].minor);
#line 328 "./templatelang.yxx"
{ tmplgyymsp[-17].minor.tmplgyy93 = new TemplateSetVarSubString(tmplgyymsp[-15].minor.tmplgyy0->extractString(), (long) tmplgyymsp[-9].minor.tmplgyy0->integer, kMKJSON, tmplgyymsp[-5].minor.tmplgyy157, (long) tmplgyymsp[-1].minor.tmplgyy0->integer); delete tmplgyymsp[-15].minor.tmplgyy0; delete tmplgyymsp[-9].minor.tmplgyy0; delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2500 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-16].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-14].minor);
  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[-13].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-12].minor);
  tmplgyy_destructor(tmplgyypParser,54,&tmplgyymsp[-11].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-10].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-8].minor);
  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[-7].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-6].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-4].minor);
  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[-3].minor);
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 82: /* template_setvar ::= KEY_SETVAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,48,&tmplgyymsp[-3].minor);
#line 333 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy81 = new TemplateSetVarBegin(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2520 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 83: /* template_setvar_end ::= KEY_SETVAREND */
{  tmplgyy_destructor(tmplgyypParser,55,&tmplgyymsp[0].minor);
#line 339 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy29 = new TemplateSetVarEnd(); }
#line 2529 "./templatelang.c"
}
        break;
      case 84: /* template_emitvar ::= KEY_EMITVAR KEY_SPACE STRING KEY_BB_CLOSE */
{  tmplgyy_destructor(tmplgyypParser,56,&tmplgyymsp[-3].minor);
#line 345 "./templatelang.yxx"
{ tmplgyymsp[-3].minor.tmplgyy107 = new TemplateEmitVar(tmplgyymsp[-1].minor.tmplgyy0->extractString()); delete tmplgyymsp[-1].minor.tmplgyy0; }
#line 2536 "./templatelang.c"
  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[-2].minor);
  tmplgyy_destructor(tmplgyypParser,7,&tmplgyymsp[0].minor);
}
        break;
      case 85: /* template_string ::= CHAR */
#line 353 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy52 = new TemplateString(new std::string(1, tmplgyymsp[0].minor.tmplgyy0->cChar)); delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2544 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy52 = tmplgyylhsminor.tmplgyy52;
        break;
      case 86: /* template_string ::= IDENTIFIER */
#line 355 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy52 = new TemplateString(tmplgyymsp[0].minor.tmplgyy0->extractString()); delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2550 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy52 = tmplgyylhsminor.tmplgyy52;
        break;
      case 87: /* template_string ::= KEY_BARE_ATTRIB */
{  tmplgyy_destructor(tmplgyypParser,52,&tmplgyymsp[0].minor);
#line 357 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("attrib")); }
#line 2557 "./templatelang.c"
}
        break;
      case 88: /* template_string ::= KEY_BARE_ATTRIBNOMANGLE */
{  tmplgyy_destructor(tmplgyypParser,53,&tmplgyymsp[0].minor);
#line 359 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("attribnomangle")); }
#line 2564 "./templatelang.c"
}
        break;
      case 89: /* template_string ::= KEY_BARE_COUNTER */
{  tmplgyy_destructor(tmplgyypParser,30,&tmplgyymsp[0].minor);
#line 361 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("counter")); }
#line 2571 "./templatelang.c"
}
        break;
      case 90: /* template_string ::= KEY_BARE_FEATURE */
{  tmplgyy_destructor(tmplgyypParser,27,&tmplgyymsp[0].minor);
#line 363 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("feature")); }
#line 2578 "./templatelang.c"
}
        break;
      case 91: /* template_string ::= KEY_BARE_FEATURENOMANGLE */
{  tmplgyy_destructor(tmplgyypParser,28,&tmplgyymsp[0].minor);
#line 365 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("featurenomangle")); }
#line 2585 "./templatelang.c"
}
        break;
      case 92: /* template_string ::= KEY_BARE_FEATUREJSONMANGLE */
{  tmplgyy_destructor(tmplgyypParser,54,&tmplgyymsp[0].minor);
#line 367 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("featurejsonmangle")); }
#line 2592 "./templatelang.c"
}
        break;
      case 93: /* template_string ::= KEY_BARE_MAXLENGTH */
{  tmplgyy_destructor(tmplgyypParser,51,&tmplgyymsp[0].minor);
#line 369 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("maxlength")); }
#line 2599 "./templatelang.c"
}
        break;
      case 94: /* template_string ::= KEY_BARE_SUBSTRING */
{  tmplgyy_destructor(tmplgyypParser,49,&tmplgyymsp[0].minor);
#line 371 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("substring")); }
#line 2606 "./templatelang.c"
}
        break;
      case 95: /* template_string ::= KEY_BARE_FORMAT */
{  tmplgyy_destructor(tmplgyypParser,17,&tmplgyymsp[0].minor);
#line 373 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("format")); }
#line 2613 "./templatelang.c"
}
        break;
      case 96: /* template_string ::= KEY_BARE_FROM */
{  tmplgyy_destructor(tmplgyypParser,50,&tmplgyymsp[0].minor);
#line 375 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("from")); }
#line 2620 "./templatelang.c"
}
        break;
      case 97: /* template_string ::= KEY_BARE_TO */
{  tmplgyy_destructor(tmplgyypParser,58,&tmplgyymsp[0].minor);
#line 377 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("to")); }
#line 2627 "./templatelang.c"
}
        break;
      case 98: /* template_string ::= KEY_BARE_VAR */
{  tmplgyy_destructor(tmplgyypParser,19,&tmplgyymsp[0].minor);
#line 379 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("var")); }
#line 2634 "./templatelang.c"
}
        break;
      case 99: /* template_string ::= KEY_BARE_VARNOMANGLE */
{  tmplgyy_destructor(tmplgyypParser,29,&tmplgyymsp[0].minor);
#line 381 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("varnomangle")); }
#line 2641 "./templatelang.c"
}
        break;
      case 100: /* template_string ::= INTEGER */
#line 383 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy52 = new TemplateString(new std::string(*tmplgyymsp[0].minor.tmplgyy0->pString)); delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2647 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy52 = tmplgyylhsminor.tmplgyy52;
        break;
      case 101: /* template_string ::= STRING */
#line 385 "./templatelang.yxx"
{ std::string *pString = new std::string("\""); *pString += *tmplgyymsp[0].minor.tmplgyy0->pString + "\""; tmplgyylhsminor.tmplgyy52 = new TemplateString(pString); delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2653 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy52 = tmplgyylhsminor.tmplgyy52;
        break;
      case 102: /* template_string ::= KEY_SPACE */
{  tmplgyy_destructor(tmplgyypParser,5,&tmplgyymsp[0].minor);
#line 387 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string(" ")); }
#line 2660 "./templatelang.c"
}
        break;
      case 103: /* template_string ::= KEY_DASH */
{  tmplgyy_destructor(tmplgyypParser,59,&tmplgyymsp[0].minor);
#line 389 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("-")); }
#line 2667 "./templatelang.c"
}
        break;
      case 104: /* template_string ::= KEY_NEWLINE */
{  tmplgyy_destructor(tmplgyypParser,60,&tmplgyymsp[0].minor);
#line 391 "./templatelang.yxx"
{ tmplgyymsp[0].minor.tmplgyy52 = new TemplateString(new std::string("\n")); }
#line 2674 "./templatelang.c"
}
        break;
      case 105: /* signed_integer ::= INTEGER */
#line 396 "./templatelang.yxx"
{ tmplgyylhsminor.tmplgyy157 = (long) tmplgyymsp[0].minor.tmplgyy0->integer; delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2680 "./templatelang.c"
  tmplgyymsp[0].minor.tmplgyy157 = tmplgyylhsminor.tmplgyy157;
        break;
      case 106: /* signed_integer ::= KEY_DASH INTEGER */
{  tmplgyy_destructor(tmplgyypParser,59,&tmplgyymsp[-1].minor);
#line 397 "./templatelang.yxx"
{ tmplgyymsp[-1].minor.tmplgyy157 = (long) -(tmplgyymsp[0].minor.tmplgyy0->integer); delete tmplgyymsp[0].minor.tmplgyy0; }
#line 2687 "./templatelang.c"
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
  TemplateLangParserARG_FETCH
  TemplateLangParserCTX_FETCH
#ifndef NDEBUG
  if( tmplgyyTraceFILE ){
    fprintf(tmplgyyTraceFILE,"%sFail!\n",tmplgyyTracePrompt);
  }
#endif
  while( tmplgyypParser->tmplgyytos>tmplgyypParser->tmplgyystack ) tmplgyy_pop_parser_stack(tmplgyypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
/************ Begin %parse_failure code ***************************************/
#line 52 "./templatelang.yxx"

  pEE->bSyntaxError = true;
#line 2735 "./templatelang.c"
/************ End %parse_failure code *****************************************/
  TemplateLangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  TemplateLangParserCTX_STORE
}
#endif /* TMPLGYYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void tmplgyy_syntax_error(
  tmplgyyParser *tmplgyypParser,           /* The parser */
  int tmplgyymajor,                   /* The major type of the error token */
  TemplateLangParserTOKENTYPE tmplgyyminor         /* The minor type of the error token */
){
  TemplateLangParserARG_FETCH
  TemplateLangParserCTX_FETCH
#define TOKEN tmplgyyminor
/************ Begin %syntax_error code ****************************************/
#line 43 "./templatelang.yxx"

  UNUSED(tmplgyymajor);
  UNUSED(tmplgyyminor);
  pEE->bSyntaxError = true;
  std::string errMsg = "syntax error near " + TOKEN->getTokenName();
  pEE->addToError(errMsg);
#line 2761 "./templatelang.c"
/************ End %syntax_error code ******************************************/
  TemplateLangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  TemplateLangParserCTX_STORE
}

/*
** The following is executed when the parser accepts
*/
static void tmplgyy_accept(
  tmplgyyParser *tmplgyypParser           /* The parser */
){
  TemplateLangParserARG_FETCH
  TemplateLangParserCTX_FETCH
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
  TemplateLangParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  TemplateLangParserCTX_STORE
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "TemplateLangParserAlloc" which describes the current state of the parser.
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
void TemplateLangParser(
  void *tmplgyyp,                   /* The parser */
  int tmplgyymajor,                 /* The major token code number */
  TemplateLangParserTOKENTYPE tmplgyyminor       /* The value for the token */
  TemplateLangParserARG_PDECL               /* Optional %extra_argument parameter */
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
  TemplateLangParserCTX_FETCH
  TemplateLangParserARG_STORE

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
                        tmplgyyminor TemplateLangParserCTX_PARAM);
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
int TemplateLangParserFallback(int iToken){
#ifdef TMPLGYYFALLBACK
  assert( iToken<(int)(sizeof(tmplgyyFallback)/sizeof(tmplgyyFallback[0])) );
  return tmplgyyFallback[iToken];
#else
  (void)iToken;
  return 0;
#endif
}
