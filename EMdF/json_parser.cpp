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
#line 1 "./json.yxx"


/*
 * json.yxx
 *
 * JSON parser
 *
 * Ulrik Sandborg-Petersen
 * Created: 7/28-2008
 * Last update: 5/11-2018
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

#include <cassert>
#include <json_classes.h>
#include <mql_yylex.h>
#include <cstdlib>
#include <string>

#undef TOKEN

#undef JSONYYCODETYPE
#undef JSONYYNOCODE
#undef JSONYYACTIONTYPE
#undef JSONYYNSTATE
#undef JSONYYNRULE
#undef JSONYY_ACTTAB_COUNT
#undef JSONYY_SHIFT_USE_DFLT
#undef JSONYY_SHIFT_COUNT
#undef JSONYY_SHIFT_MIN
#undef JSONYY_SHIFT_MAX
#undef JSONYY_REDUCE_USE_DFLT
#undef JSONYY_REDUCE_COUNT
#undef JSONYY_REDUCE_MIN
#undef JSONYY_REDUCE_MAX

#line 76 "./json.c"
/**************** End of %include directives **********************************/
/* These constants specify the various numeric values for terminal symbols
** in a format understandable to "makeheaders".  This section is blank unless
** "lemon" is run with the "-m" command-line option.
***************** Begin makeheaders token definitions *************************/
/**************** End makeheaders token definitions ***************************/

/* The next sections is a series of control #defines.
** various aspects of the generated parser.
**    JSONYYCODETYPE         is the data type used to store the integer codes
**                       that represent terminal and non-terminal symbols.
**                       "unsigned char" is used if there are fewer than
**                       256 symbols.  Larger types otherwise.
**    JSONYYNOCODE           is a number of type JSONYYCODETYPE that is not used for
**                       any terminal or nonterminal symbol.
**    JSONYYFALLBACK         If defined, this indicates that one or more tokens
**                       (also known as: "terminal symbols") have fall-back
**                       values which should be used if the original symbol
**                       would not parse.  This permits keywords to sometimes
**                       be used as identifiers, for example.
**    JSONYYACTIONTYPE       is the data type used for "action codes" - numbers
**                       that indicate what to do in response to the next
**                       token.
**    JSONParserTOKENTYPE     is the data type used for minor type for terminal
**                       symbols.  Background: A "minor type" is a semantic
**                       value associated with a terminal or non-terminal
**                       symbols.  For example, for an "ID" terminal symbol,
**                       the minor type might be the name of the identifier.
**                       Each non-terminal can have a different minor type.
**                       Terminal symbols all have the same minor type, though.
**                       This macros defines the minor type for terminal 
**                       symbols.
**    JSONYYMINORTYPE        is the data type used for all minor types.
**                       This is typically a union of many types, one of
**                       which is JSONParserTOKENTYPE.  The entry in the union
**                       for terminal symbols is called "jsonyy0".
**    JSONYYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    JSONParserARG_SDECL     A static variable declaration for the %extra_argument
**    JSONParserARG_PDECL     A parameter declaration for the %extra_argument
**    JSONParserARG_PARAM     Code to pass %extra_argument as a subroutine parameter
**    JSONParserARG_STORE     Code to store %extra_argument into jsonyypParser
**    JSONParserARG_FETCH     Code to extract %extra_argument from jsonyypParser
**    JSONParserCTX_*         As JSONParserARG_ except for %extra_context
**    JSONYYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
**    JSONYYNSTATE           the combined number of states.
**    JSONYYNRULE            the number of rules in the grammar
**    JSONYYNTOKEN           Number of terminal symbols
**    JSONYY_MAX_SHIFT       Maximum value for shift actions
**    JSONYY_MIN_SHIFTREDUCE Minimum value for shift-reduce actions
**    JSONYY_MAX_SHIFTREDUCE Maximum value for shift-reduce actions
**    JSONYY_ERROR_ACTION    The jsonyy_action[] code for syntax error
**    JSONYY_ACCEPT_ACTION   The jsonyy_action[] code for accept
**    JSONYY_NO_ACTION       The jsonyy_action[] code for no-op
**    JSONYY_MIN_REDUCE      Minimum value for reduce actions
**    JSONYY_MAX_REDUCE      Maximum value for reduce actions
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/************* Begin control #defines *****************************************/
#define JSONYYCODETYPE unsigned char
#define JSONYYNOCODE 24
#define JSONYYACTIONTYPE unsigned char
#define JSONParserTOKENTYPE Token*
typedef union {
  int jsonyyinit;
  JSONParserTOKENTYPE jsonyy0;
  JSONValue* jsonyy18;
  int jsonyy28;
  JSONKeyValuePair* jsonyy31;
  JSONListElement* jsonyy39;
} JSONYYMINORTYPE;
#ifndef JSONYYSTACKDEPTH
#define JSONYYSTACKDEPTH 100
#endif
#define JSONParserARG_SDECL JSONExecEnv *pEE;
#define JSONParserARG_PDECL ,JSONExecEnv *pEE
#define JSONParserARG_PARAM ,pEE
#define JSONParserARG_FETCH JSONExecEnv *pEE=jsonyypParser->pEE;
#define JSONParserARG_STORE jsonyypParser->pEE=pEE;
#define JSONParserCTX_SDECL
#define JSONParserCTX_PDECL
#define JSONParserCTX_PARAM
#define JSONParserCTX_FETCH
#define JSONParserCTX_STORE
#define JSONYYNSTATE             12
#define JSONYYNRULE              23
#define JSONYYNRULE_WITH_ACTION  23
#define JSONYYNTOKEN             12
#define JSONYY_MAX_SHIFT         11
#define JSONYY_MIN_SHIFTREDUCE   32
#define JSONYY_MAX_SHIFTREDUCE   54
#define JSONYY_ERROR_ACTION      55
#define JSONYY_ACCEPT_ACTION     56
#define JSONYY_NO_ACTION         57
#define JSONYY_MIN_REDUCE        58
#define JSONYY_MAX_REDUCE        80
/************* End control #defines *******************************************/
#define JSONYY_NLOOKAHEAD ((int)(sizeof(jsonyy_lookahead)/sizeof(jsonyy_lookahead[0])))

/* Define the jsonyytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define jsonyytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the jsonyytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef jsonyytestcase
# define jsonyytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N <= JSONYY_MAX_SHIFT             Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   N between JSONYY_MIN_SHIFTREDUCE       Shift to an arbitrary state then
**     and JSONYY_MAX_SHIFTREDUCE           reduce by rule N-JSONYY_MIN_SHIFTREDUCE.
**
**   N == JSONYY_ERROR_ACTION               A syntax error has occurred.
**
**   N == JSONYY_ACCEPT_ACTION              The parser accepts its input.
**
**   N == JSONYY_NO_ACTION                  No such action.  Denotes unused
**                                      slots in the jsonyy_action[] table.
**
**   N between JSONYY_MIN_REDUCE            Reduce by rule N-JSONYY_MIN_REDUCE
**     and JSONYY_MAX_REDUCE
**
** The action table is constructed as a single large table named jsonyy_action[].
** Given state S and lookahead X, the action is computed as either:
**
**    (A)   N = jsonyy_action[ jsonyy_shift_ofst[S] + X ]
**    (B)   N = jsonyy_default[S]
**
** The (A) formula is preferred.  The B formula is used instead if
** jsonyy_lookahead[jsonyy_shift_ofst[S]+X] is not equal to X.
**
** The formulas above are for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the jsonyy_reduce_ofst[] array is used in place of
** the jsonyy_shift_ofst[] array.
**
** The following are the tables generated in this section:
**
**  jsonyy_action[]        A single table containing all actions.
**  jsonyy_lookahead[]     A table containing the lookahead for each entry in
**                     jsonyy_action.  Used to detect hash collisions.
**  jsonyy_shift_ofst[]    For each state, the offset into jsonyy_action for
**                     shifting terminals.
**  jsonyy_reduce_ofst[]   For each state, the offset into jsonyy_action for
**                     shifting non-terminals after a reduce.
**  jsonyy_default[]       Default action for each state.
**
*********** Begin parsing tables **********************************************/
#define JSONYY_ACTTAB_COUNT (59)
static const JSONYYACTIONTYPE jsonyy_action[] = {
 /*     0 */    56,   11,   59,   60,   61,   62,   63,   64,    4,    9,
 /*    10 */    40,   50,    9,    1,   46,   51,   52,   53,   54,   74,
 /*    20 */    59,   60,   61,   62,   63,   64,    2,    4,   47,    5,
 /*    30 */    50,    7,    1,   69,   51,   52,   53,   54,   75,   59,
 /*    40 */    60,   61,   62,   63,   64,    8,   71,   59,   60,   61,
 /*    50 */    62,   63,   64,   70,    6,   10,   39,    3,   58,
};
static const JSONYYCODETYPE jsonyy_lookahead[] = {
 /*     0 */    12,   13,   14,   15,   16,   17,   18,   19,    1,    4,
 /*    10 */     2,    4,    4,    6,    7,    8,    9,   10,   11,   13,
 /*    20 */    14,   15,   16,   17,   18,   19,    3,    1,    7,   23,
 /*    30 */     4,   20,    6,   22,    8,    9,   10,   11,   13,   14,
 /*    40 */    15,   16,   17,   18,   19,   21,   13,   14,   15,   16,
 /*    50 */    17,   18,   19,   22,    3,   21,    2,    5,    0,   24,
 /*    60 */    24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
 /*    70 */    24,
};
#define JSONYY_SHIFT_COUNT    (11)
#define JSONYY_SHIFT_MIN      (0)
#define JSONYY_SHIFT_MAX      (58)
static const unsigned char jsonyy_shift_ofst[] = {
 /*     0 */    26,    7,   26,   26,    8,   23,    5,   51,   21,   52,
 /*    10 */    54,   58,
};
#define JSONYY_REDUCE_COUNT (7)
#define JSONYY_REDUCE_MIN   (-12)
#define JSONYY_REDUCE_MAX   (34)
static const signed char jsonyy_reduce_ofst[] = {
 /*     0 */   -12,    6,   25,   33,   11,   24,   31,   34,
};
static const JSONYYACTIONTYPE jsonyy_default[] = {
 /*     0 */    55,   55,   67,   55,   55,   68,   67,   68,   55,   55,
 /*    10 */    55,   55,
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
#ifdef JSONYYFALLBACK
static const JSONYYCODETYPE jsonyyFallback[] = {
};
#endif /* JSONYYFALLBACK */

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
struct jsonyyStackEntry {
  JSONYYACTIONTYPE stateno;  /* The state-number, or reduce action in SHIFTREDUCE */
  JSONYYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  JSONYYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct jsonyyStackEntry jsonyyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct jsonyyParser {
  jsonyyStackEntry *jsonyytos;          /* Pointer to top element of the stack */
#ifdef JSONYYTRACKMAXSTACKDEPTH
  int jsonyyhwm;                    /* High-water mark of the stack */
#endif
#ifndef JSONYYNOERRORRECOVERY
  int jsonyyerrcnt;                 /* Shifts left before out of the error */
#endif
  JSONParserARG_SDECL                /* A place to hold %extra_argument */
  JSONParserCTX_SDECL                /* A place to hold %extra_context */
#if JSONYYSTACKDEPTH<=0
  int jsonyystksz;                  /* Current side of the stack */
  jsonyyStackEntry *jsonyystack;        /* The parser's stack */
  jsonyyStackEntry jsonyystk0;          /* First stack entry */
#else
  jsonyyStackEntry jsonyystack[JSONYYSTACKDEPTH];  /* The parser's stack */
  jsonyyStackEntry *jsonyystackEnd;            /* Last entry in the stack */
#endif
};
typedef struct jsonyyParser jsonyyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *jsonyyTraceFILE = 0;
static char *jsonyyTracePrompt = 0;
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
void JSONParserTrace(FILE *TraceFILE, char *zTracePrompt){
  jsonyyTraceFILE = TraceFILE;
  jsonyyTracePrompt = zTracePrompt;
  if( jsonyyTraceFILE==0 ) jsonyyTracePrompt = 0;
  else if( jsonyyTracePrompt==0 ) jsonyyTraceFILE = 0;
}
#endif /* NDEBUG */

#if defined(JSONYYCOVERAGE) || !defined(NDEBUG)
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const jsonyyTokenName[] = { 
  /*    0 */ "$",
  /*    1 */ "KEY_BRACE_OPEN",
  /*    2 */ "KEY_BRACE_CLOSE",
  /*    3 */ "KEY_COMMA",
  /*    4 */ "STRING",
  /*    5 */ "KEY_COLON",
  /*    6 */ "KEY_BRACKET_OPEN",
  /*    7 */ "KEY_BRACKET_CLOSE",
  /*    8 */ "KEY_TRUE",
  /*    9 */ "KEY_FALSE",
  /*   10 */ "KEY_NULL",
  /*   11 */ "INTEGER",
  /*   12 */ "top_value",
  /*   13 */ "json_value",
  /*   14 */ "json_object",
  /*   15 */ "json_list",
  /*   16 */ "json_boolean",
  /*   17 */ "json_string",
  /*   18 */ "json_integer",
  /*   19 */ "json_null",
  /*   20 */ "json_key_value_list",
  /*   21 */ "opt_comma",
  /*   22 */ "json_key_value_list_element",
  /*   23 */ "json_value_list",
};
#endif /* defined(JSONYYCOVERAGE) || !defined(NDEBUG) */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const jsonyyRuleName[] = {
 /*   0 */ "top_value ::= json_value",
 /*   1 */ "json_value ::= json_object",
 /*   2 */ "json_value ::= json_list",
 /*   3 */ "json_value ::= json_boolean",
 /*   4 */ "json_value ::= json_string",
 /*   5 */ "json_value ::= json_integer",
 /*   6 */ "json_value ::= json_null",
 /*   7 */ "json_object ::= KEY_BRACE_OPEN json_key_value_list opt_comma KEY_BRACE_CLOSE",
 /*   8 */ "json_object ::= KEY_BRACE_OPEN KEY_BRACE_CLOSE",
 /*   9 */ "opt_comma ::= KEY_COMMA",
 /*  10 */ "opt_comma ::=",
 /*  11 */ "json_key_value_list ::= json_key_value_list_element",
 /*  12 */ "json_key_value_list ::= json_key_value_list KEY_COMMA json_key_value_list_element",
 /*  13 */ "json_key_value_list_element ::= STRING KEY_COLON json_value",
 /*  14 */ "json_list ::= KEY_BRACKET_OPEN KEY_BRACKET_CLOSE",
 /*  15 */ "json_list ::= KEY_BRACKET_OPEN json_value_list opt_comma KEY_BRACKET_CLOSE",
 /*  16 */ "json_value_list ::= json_value",
 /*  17 */ "json_value_list ::= json_value_list KEY_COMMA json_value",
 /*  18 */ "json_string ::= STRING",
 /*  19 */ "json_boolean ::= KEY_TRUE",
 /*  20 */ "json_boolean ::= KEY_FALSE",
 /*  21 */ "json_null ::= KEY_NULL",
 /*  22 */ "json_integer ::= INTEGER",
};
#endif /* NDEBUG */


#if JSONYYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.  Return the number
** of errors.  Return 0 on success.
*/
static int jsonyyGrowStack(jsonyyParser *p){
  int newSize;
  int idx;
  jsonyyStackEntry *pNew;

  newSize = p->jsonyystksz*2 + 100;
  idx = p->jsonyytos ? (int)(p->jsonyytos - p->jsonyystack) : 0;
  if( p->jsonyystack==&p->jsonyystk0 ){
    pNew = malloc(newSize*sizeof(pNew[0]));
    if( pNew ) pNew[0] = p->jsonyystk0;
  }else{
    pNew = realloc(p->jsonyystack, newSize*sizeof(pNew[0]));
  }
  if( pNew ){
    p->jsonyystack = pNew;
    p->jsonyytos = &p->jsonyystack[idx];
#ifndef NDEBUG
    if( jsonyyTraceFILE ){
      fprintf(jsonyyTraceFILE,"%sStack grows from %d to %d entries.\n",
              jsonyyTracePrompt, p->jsonyystksz, newSize);
    }
#endif
    p->jsonyystksz = newSize;
  }
  return pNew==0; 
}
#endif

/* Datatype of the argument to the memory allocated passed as the
** second argument to JSONParserAlloc() below.  This can be changed by
** putting an appropriate #define in the %include section of the input
** grammar.
*/
#ifndef JSONYYMALLOCARGTYPE
# define JSONYYMALLOCARGTYPE size_t
#endif

/* Initialize a new parser that has already been allocated.
*/
void JSONParserInit(void *jsonyypRawParser JSONParserCTX_PDECL){
  jsonyyParser *jsonyypParser = (jsonyyParser*)jsonyypRawParser;
  JSONParserCTX_STORE
#ifdef JSONYYTRACKMAXSTACKDEPTH
  jsonyypParser->jsonyyhwm = 0;
#endif
#if JSONYYSTACKDEPTH<=0
  jsonyypParser->jsonyytos = NULL;
  jsonyypParser->jsonyystack = NULL;
  jsonyypParser->jsonyystksz = 0;
  if( jsonyyGrowStack(jsonyypParser) ){
    jsonyypParser->jsonyystack = &jsonyypParser->jsonyystk0;
    jsonyypParser->jsonyystksz = 1;
  }
#endif
#ifndef JSONYYNOERRORRECOVERY
  jsonyypParser->jsonyyerrcnt = -1;
#endif
  jsonyypParser->jsonyytos = jsonyypParser->jsonyystack;
  jsonyypParser->jsonyystack[0].stateno = 0;
  jsonyypParser->jsonyystack[0].major = 0;
#if JSONYYSTACKDEPTH>0
  jsonyypParser->jsonyystackEnd = &jsonyypParser->jsonyystack[JSONYYSTACKDEPTH-1];
#endif
}

#ifndef JSONParser_ENGINEALWAYSONSTACK
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
** to JSONParser and JSONParserFree.
*/
void *JSONParserAlloc(void *(*mallocProc)(JSONYYMALLOCARGTYPE) JSONParserCTX_PDECL){
  jsonyyParser *jsonyypParser;
  jsonyypParser = (jsonyyParser*)(*mallocProc)( (JSONYYMALLOCARGTYPE)sizeof(jsonyyParser) );
  if( jsonyypParser ){
    JSONParserCTX_STORE
    JSONParserInit(jsonyypParser JSONParserCTX_PARAM);
  }
  return (void*)jsonyypParser;
}
#endif /* JSONParser_ENGINEALWAYSONSTACK */


/* The following function deletes the "minor type" or semantic value
** associated with a symbol.  The symbol can be either a terminal
** or nonterminal. "jsonyymajor" is the symbol code, and "jsonyypminor" is
** a pointer to the value to be deleted.  The code used to do the 
** deletions is derived from the %destructor and/or %token_destructor
** directives of the input grammar.
*/
static void jsonyy_destructor(
  jsonyyParser *jsonyypParser,    /* The parser */
  JSONYYCODETYPE jsonyymajor,     /* Type code for object to destroy */
  JSONYYMINORTYPE *jsonyypminor   /* The object to be destroyed */
){
  JSONParserARG_FETCH
  JSONParserCTX_FETCH
  switch( jsonyymajor ){
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
    case 1: /* KEY_BRACE_OPEN */
    case 2: /* KEY_BRACE_CLOSE */
    case 3: /* KEY_COMMA */
    case 4: /* STRING */
    case 5: /* KEY_COLON */
    case 6: /* KEY_BRACKET_OPEN */
    case 7: /* KEY_BRACKET_CLOSE */
    case 8: /* KEY_TRUE */
    case 9: /* KEY_FALSE */
    case 10: /* KEY_NULL */
    case 11: /* INTEGER */
{
#line 50 "./json.yxx"
 
	if (!pEE->pLexer->isLocallyAllocatedToken((jsonyypminor->jsonyy0))) {
		deleteToken((jsonyypminor->jsonyy0)); 
	}

#line 581 "./json.c"
}
      break;
    case 12: /* top_value */
    case 13: /* json_value */
{
#line 77 "./json.yxx"
 delete((jsonyypminor->jsonyy18)); 
#line 589 "./json.c"
}
      break;
    case 14: /* json_object */
    case 15: /* json_list */
{
#line 90 "./json.yxx"
delete((jsonyypminor->jsonyy18)); 
#line 597 "./json.c"
}
      break;
    case 16: /* json_boolean */
    case 17: /* json_string */
    case 18: /* json_integer */
    case 19: /* json_null */
{
#line 147 "./json.yxx"
delete((jsonyypminor->jsonyy18));
#line 607 "./json.c"
}
      break;
    case 20: /* json_key_value_list */
    case 22: /* json_key_value_list_element */
{
#line 103 "./json.yxx"
delete((jsonyypminor->jsonyy31));
#line 615 "./json.c"
}
      break;
    case 21: /* opt_comma */
{
#line 97 "./json.yxx"
;
#line 622 "./json.c"
}
      break;
    case 23: /* json_value_list */
{
#line 127 "./json.yxx"
delete((jsonyypminor->jsonyy39)); 
#line 629 "./json.c"
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
static void jsonyy_pop_parser_stack(jsonyyParser *pParser){
  jsonyyStackEntry *jsonyytos;
  assert( pParser->jsonyytos!=0 );
  assert( pParser->jsonyytos > pParser->jsonyystack );
  jsonyytos = pParser->jsonyytos--;
#ifndef NDEBUG
  if( jsonyyTraceFILE ){
    fprintf(jsonyyTraceFILE,"%sPopping %s\n",
      jsonyyTracePrompt,
      jsonyyTokenName[jsonyytos->major]);
  }
#endif
  jsonyy_destructor(pParser, jsonyytos->major, &jsonyytos->minor);
}

/*
** Clear all secondary memory allocations from the parser
*/
void JSONParserFinalize(void *p){
  jsonyyParser *pParser = (jsonyyParser*)p;
  while( pParser->jsonyytos>pParser->jsonyystack ) jsonyy_pop_parser_stack(pParser);
#if JSONYYSTACKDEPTH<=0
  if( pParser->jsonyystack!=&pParser->jsonyystk0 ) free(pParser->jsonyystack);
#endif
}

#ifndef JSONParser_ENGINEALWAYSONSTACK
/* 
** Deallocate and destroy a parser.  Destructors are called for
** all stack elements before shutting the parser down.
**
** If the JSONYYPARSEFREENEVERNULL macro exists (for example because it
** is defined in a %include section of the input grammar) then it is
** assumed that the input pointer is never NULL.
*/
void JSONParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
#ifndef JSONYYPARSEFREENEVERNULL
  if( p==0 ) return;
#endif
  JSONParserFinalize(p);
  (*freeProc)(p);
}
#endif /* JSONParser_ENGINEALWAYSONSTACK */

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef JSONYYTRACKMAXSTACKDEPTH
int JSONParserStackPeak(void *p){
  jsonyyParser *pParser = (jsonyyParser*)p;
  return pParser->jsonyyhwm;
}
#endif

/* This array of booleans keeps track of the parser statement
** coverage.  The element jsonyycoverage[X][Y] is set when the parser
** is in state X and has a lookahead token Y.  In a well-tested
** systems, every element of this matrix should end up being set.
*/
#if defined(JSONYYCOVERAGE)
static unsigned char jsonyycoverage[JSONYYNSTATE][JSONYYNTOKEN];
#endif

/*
** Write into out a description of every state/lookahead combination that
**
**   (1)  has not been used by the parser, and
**   (2)  is not a syntax error.
**
** Return the number of missed state/lookahead combinations.
*/
#if defined(JSONYYCOVERAGE)
int JSONParserCoverage(FILE *out){
  int stateno, iLookAhead, i;
  int nMissed = 0;
  for(stateno=0; stateno<JSONYYNSTATE; stateno++){
    i = jsonyy_shift_ofst[stateno];
    for(iLookAhead=0; iLookAhead<JSONYYNTOKEN; iLookAhead++){
      if( jsonyy_lookahead[i+iLookAhead]!=iLookAhead ) continue;
      if( jsonyycoverage[stateno][iLookAhead]==0 ) nMissed++;
      if( out ){
        fprintf(out,"State %d lookahead %s %s\n", stateno,
                jsonyyTokenName[iLookAhead],
                jsonyycoverage[stateno][iLookAhead] ? "ok" : "missed");
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
static JSONYYACTIONTYPE jsonyy_find_shift_action(
  JSONYYCODETYPE iLookAhead,    /* The look-ahead token */
  JSONYYACTIONTYPE stateno      /* Current state number */
){
  int i;

  if( stateno>JSONYY_MAX_SHIFT ) return stateno;
  assert( stateno <= JSONYY_SHIFT_COUNT );
#if defined(JSONYYCOVERAGE)
  jsonyycoverage[stateno][iLookAhead] = 1;
#endif
  do{
    i = jsonyy_shift_ofst[stateno];
    assert( i>=0 );
    assert( i<=JSONYY_ACTTAB_COUNT );
    assert( i+JSONYYNTOKEN<=(int)JSONYY_NLOOKAHEAD );
    assert( iLookAhead!=JSONYYNOCODE );
    assert( iLookAhead < JSONYYNTOKEN );
    i += iLookAhead;
    assert( i<(int)JSONYY_NLOOKAHEAD );
    if( jsonyy_lookahead[i]!=iLookAhead ){
#ifdef JSONYYFALLBACK
      JSONYYCODETYPE iFallback;            /* Fallback token */
      assert( iLookAhead<sizeof(jsonyyFallback)/sizeof(jsonyyFallback[0]) );
      iFallback = jsonyyFallback[iLookAhead];
      if( iFallback!=0 ){
#ifndef NDEBUG
        if( jsonyyTraceFILE ){
          fprintf(jsonyyTraceFILE, "%sFALLBACK %s => %s\n",
             jsonyyTracePrompt, jsonyyTokenName[iLookAhead], jsonyyTokenName[iFallback]);
        }
#endif
        assert( jsonyyFallback[iFallback]==0 ); /* Fallback loop must terminate */
        iLookAhead = iFallback;
        continue;
      }
#endif
#ifdef JSONYYWILDCARD
      {
        int j = i - iLookAhead + JSONYYWILDCARD;
        assert( j<(int)(sizeof(jsonyy_lookahead)/sizeof(jsonyy_lookahead[0])) );
        if( jsonyy_lookahead[j]==JSONYYWILDCARD && iLookAhead>0 ){
#ifndef NDEBUG
          if( jsonyyTraceFILE ){
            fprintf(jsonyyTraceFILE, "%sWILDCARD %s => %s\n",
               jsonyyTracePrompt, jsonyyTokenName[iLookAhead],
               jsonyyTokenName[JSONYYWILDCARD]);
          }
#endif /* NDEBUG */
          return jsonyy_action[j];
        }
      }
#endif /* JSONYYWILDCARD */
      return jsonyy_default[stateno];
    }else{
      assert( i>=0 && i<sizeof(jsonyy_action)/sizeof(jsonyy_action[0]) );
      return jsonyy_action[i];
    }
  }while(1);
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
*/
static JSONYYACTIONTYPE jsonyy_find_reduce_action(
  JSONYYACTIONTYPE stateno,     /* Current state number */
  JSONYYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef JSONYYERRORSYMBOL
  if( stateno>JSONYY_REDUCE_COUNT ){
    return jsonyy_default[stateno];
  }
#else
  assert( stateno<=JSONYY_REDUCE_COUNT );
#endif
  i = jsonyy_reduce_ofst[stateno];
  assert( iLookAhead!=JSONYYNOCODE );
  i += iLookAhead;
#ifdef JSONYYERRORSYMBOL
  if( i<0 || i>=JSONYY_ACTTAB_COUNT || jsonyy_lookahead[i]!=iLookAhead ){
    return jsonyy_default[stateno];
  }
#else
  assert( i>=0 && i<JSONYY_ACTTAB_COUNT );
  assert( jsonyy_lookahead[i]==iLookAhead );
#endif
  return jsonyy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void jsonyyStackOverflow(jsonyyParser *jsonyypParser){
   JSONParserARG_FETCH
   JSONParserCTX_FETCH
#ifndef NDEBUG
   if( jsonyyTraceFILE ){
     fprintf(jsonyyTraceFILE,"%sStack Overflow!\n",jsonyyTracePrompt);
   }
#endif
   while( jsonyypParser->jsonyytos>jsonyypParser->jsonyystack ) jsonyy_pop_parser_stack(jsonyypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
/******** Begin %stack_overflow code ******************************************/
/******** End %stack_overflow code ********************************************/
   JSONParserARG_STORE /* Suppress warning about unused %extra_argument var */
   JSONParserCTX_STORE
}

/*
** Print tracing information for a SHIFT action
*/
#ifndef NDEBUG
static void jsonyyTraceShift(jsonyyParser *jsonyypParser, int jsonyyNewState, const char *zTag){
  if( jsonyyTraceFILE ){
    if( jsonyyNewState<JSONYYNSTATE ){
      fprintf(jsonyyTraceFILE,"%s%s '%s', go to state %d\n",
         jsonyyTracePrompt, zTag, jsonyyTokenName[jsonyypParser->jsonyytos->major],
         jsonyyNewState);
    }else{
      fprintf(jsonyyTraceFILE,"%s%s '%s', pending reduce %d\n",
         jsonyyTracePrompt, zTag, jsonyyTokenName[jsonyypParser->jsonyytos->major],
         jsonyyNewState - JSONYY_MIN_REDUCE);
    }
  }
}
#else
# define jsonyyTraceShift(X,Y,Z)
#endif

/*
** Perform a shift action.
*/
static void jsonyy_shift(
  jsonyyParser *jsonyypParser,          /* The parser to be shifted */
  JSONYYACTIONTYPE jsonyyNewState,      /* The new state to shift in */
  JSONYYCODETYPE jsonyyMajor,           /* The major token to shift in */
  JSONParserTOKENTYPE jsonyyMinor        /* The minor token to shift in */
){
  jsonyyStackEntry *jsonyytos;
  jsonyypParser->jsonyytos++;
#ifdef JSONYYTRACKMAXSTACKDEPTH
  if( (int)(jsonyypParser->jsonyytos - jsonyypParser->jsonyystack)>jsonyypParser->jsonyyhwm ){
    jsonyypParser->jsonyyhwm++;
    assert( jsonyypParser->jsonyyhwm == (int)(jsonyypParser->jsonyytos - jsonyypParser->jsonyystack) );
  }
#endif
#if JSONYYSTACKDEPTH>0 
  if( jsonyypParser->jsonyytos>jsonyypParser->jsonyystackEnd ){
    jsonyypParser->jsonyytos--;
    jsonyyStackOverflow(jsonyypParser);
    return;
  }
#else
  if( jsonyypParser->jsonyytos>=&jsonyypParser->jsonyystack[jsonyypParser->jsonyystksz] ){
    if( jsonyyGrowStack(jsonyypParser) ){
      jsonyypParser->jsonyytos--;
      jsonyyStackOverflow(jsonyypParser);
      return;
    }
  }
#endif
  if( jsonyyNewState > JSONYY_MAX_SHIFT ){
    jsonyyNewState += JSONYY_MIN_REDUCE - JSONYY_MIN_SHIFTREDUCE;
  }
  jsonyytos = jsonyypParser->jsonyytos;
  jsonyytos->stateno = jsonyyNewState;
  jsonyytos->major = jsonyyMajor;
  jsonyytos->minor.jsonyy0 = jsonyyMinor;
  jsonyyTraceShift(jsonyypParser, jsonyyNewState, "Shift");
}

/* For rule J, jsonyyRuleInfoLhs[J] contains the symbol on the left-hand side
** of that rule */
static const JSONYYCODETYPE jsonyyRuleInfoLhs[] = {
    12,  /* (0) top_value ::= json_value */
    13,  /* (1) json_value ::= json_object */
    13,  /* (2) json_value ::= json_list */
    13,  /* (3) json_value ::= json_boolean */
    13,  /* (4) json_value ::= json_string */
    13,  /* (5) json_value ::= json_integer */
    13,  /* (6) json_value ::= json_null */
    14,  /* (7) json_object ::= KEY_BRACE_OPEN json_key_value_list opt_comma KEY_BRACE_CLOSE */
    14,  /* (8) json_object ::= KEY_BRACE_OPEN KEY_BRACE_CLOSE */
    21,  /* (9) opt_comma ::= KEY_COMMA */
    21,  /* (10) opt_comma ::= */
    20,  /* (11) json_key_value_list ::= json_key_value_list_element */
    20,  /* (12) json_key_value_list ::= json_key_value_list KEY_COMMA json_key_value_list_element */
    22,  /* (13) json_key_value_list_element ::= STRING KEY_COLON json_value */
    15,  /* (14) json_list ::= KEY_BRACKET_OPEN KEY_BRACKET_CLOSE */
    15,  /* (15) json_list ::= KEY_BRACKET_OPEN json_value_list opt_comma KEY_BRACKET_CLOSE */
    23,  /* (16) json_value_list ::= json_value */
    23,  /* (17) json_value_list ::= json_value_list KEY_COMMA json_value */
    17,  /* (18) json_string ::= STRING */
    16,  /* (19) json_boolean ::= KEY_TRUE */
    16,  /* (20) json_boolean ::= KEY_FALSE */
    19,  /* (21) json_null ::= KEY_NULL */
    18,  /* (22) json_integer ::= INTEGER */
};

/* For rule J, jsonyyRuleInfoNRhs[J] contains the negative of the number
** of symbols on the right-hand side of that rule. */
static const signed char jsonyyRuleInfoNRhs[] = {
   -1,  /* (0) top_value ::= json_value */
   -1,  /* (1) json_value ::= json_object */
   -1,  /* (2) json_value ::= json_list */
   -1,  /* (3) json_value ::= json_boolean */
   -1,  /* (4) json_value ::= json_string */
   -1,  /* (5) json_value ::= json_integer */
   -1,  /* (6) json_value ::= json_null */
   -4,  /* (7) json_object ::= KEY_BRACE_OPEN json_key_value_list opt_comma KEY_BRACE_CLOSE */
   -2,  /* (8) json_object ::= KEY_BRACE_OPEN KEY_BRACE_CLOSE */
   -1,  /* (9) opt_comma ::= KEY_COMMA */
    0,  /* (10) opt_comma ::= */
   -1,  /* (11) json_key_value_list ::= json_key_value_list_element */
   -3,  /* (12) json_key_value_list ::= json_key_value_list KEY_COMMA json_key_value_list_element */
   -3,  /* (13) json_key_value_list_element ::= STRING KEY_COLON json_value */
   -2,  /* (14) json_list ::= KEY_BRACKET_OPEN KEY_BRACKET_CLOSE */
   -4,  /* (15) json_list ::= KEY_BRACKET_OPEN json_value_list opt_comma KEY_BRACKET_CLOSE */
   -1,  /* (16) json_value_list ::= json_value */
   -3,  /* (17) json_value_list ::= json_value_list KEY_COMMA json_value */
   -1,  /* (18) json_string ::= STRING */
   -1,  /* (19) json_boolean ::= KEY_TRUE */
   -1,  /* (20) json_boolean ::= KEY_FALSE */
   -1,  /* (21) json_null ::= KEY_NULL */
   -1,  /* (22) json_integer ::= INTEGER */
};

static void jsonyy_accept(jsonyyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
**
** The jsonyyLookahead and jsonyyLookaheadToken parameters provide reduce actions
** access to the lookahead token (if any).  The jsonyyLookahead will be JSONYYNOCODE
** if the lookahead token has already been consumed.  As this procedure is
** only called from one place, optimizing compilers will in-line it, which
** means that the extra parameters have no performance impact.
*/
static JSONYYACTIONTYPE jsonyy_reduce(
  jsonyyParser *jsonyypParser,         /* The parser */
  unsigned int jsonyyruleno,       /* Number of the rule by which to reduce */
  int jsonyyLookahead,             /* Lookahead token, or JSONYYNOCODE if none */
  JSONParserTOKENTYPE jsonyyLookaheadToken  /* Value of the lookahead token */
  JSONParserCTX_PDECL                   /* %extra_context */
){
  int jsonyygoto;                     /* The next state */
  JSONYYACTIONTYPE jsonyyact;             /* The next action */
  jsonyyStackEntry *jsonyymsp;            /* The top of the parser's stack */
  int jsonyysize;                     /* Amount to pop the stack */
  JSONParserARG_FETCH
  (void)jsonyyLookahead;
  (void)jsonyyLookaheadToken;
  jsonyymsp = jsonyypParser->jsonyytos;
#ifndef NDEBUG
  if( jsonyyTraceFILE && jsonyyruleno<(int)(sizeof(jsonyyRuleName)/sizeof(jsonyyRuleName[0])) ){
    jsonyysize = jsonyyRuleInfoNRhs[jsonyyruleno];
    if( jsonyysize ){
      fprintf(jsonyyTraceFILE, "%sReduce %d [%s]%s, pop back to state %d.\n",
        jsonyyTracePrompt,
        jsonyyruleno, jsonyyRuleName[jsonyyruleno],
        jsonyyruleno<JSONYYNRULE_WITH_ACTION ? "" : " without external action",
        jsonyymsp[jsonyysize].stateno);
    }else{
      fprintf(jsonyyTraceFILE, "%sReduce %d [%s]%s.\n",
        jsonyyTracePrompt, jsonyyruleno, jsonyyRuleName[jsonyyruleno],
        jsonyyruleno<JSONYYNRULE_WITH_ACTION ? "" : " without external action");
    }
  }
#endif /* NDEBUG */

  /* Check that the stack is large enough to grow by a single entry
  ** if the RHS of the rule is empty.  This ensures that there is room
  ** enough on the stack to push the LHS value */
  if( jsonyyRuleInfoNRhs[jsonyyruleno]==0 ){
#ifdef JSONYYTRACKMAXSTACKDEPTH
    if( (int)(jsonyypParser->jsonyytos - jsonyypParser->jsonyystack)>jsonyypParser->jsonyyhwm ){
      jsonyypParser->jsonyyhwm++;
      assert( jsonyypParser->jsonyyhwm == (int)(jsonyypParser->jsonyytos - jsonyypParser->jsonyystack));
    }
#endif
#if JSONYYSTACKDEPTH>0 
    if( jsonyypParser->jsonyytos>=jsonyypParser->jsonyystackEnd ){
      jsonyyStackOverflow(jsonyypParser);
      /* The call to jsonyyStackOverflow() above pops the stack until it is
      ** empty, causing the main parser loop to exit.  So the return value
      ** is never used and does not matter. */
      return 0;
    }
#else
    if( jsonyypParser->jsonyytos>=&jsonyypParser->jsonyystack[jsonyypParser->jsonyystksz-1] ){
      if( jsonyyGrowStack(jsonyypParser) ){
        jsonyyStackOverflow(jsonyypParser);
        /* The call to jsonyyStackOverflow() above pops the stack until it is
        ** empty, causing the main parser loop to exit.  So the return value
        ** is never used and does not matter. */
        return 0;
      }
      jsonyymsp = jsonyypParser->jsonyytos;
    }
#endif
  }

  switch( jsonyyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
/********** Begin reduce actions **********************************************/
        JSONYYMINORTYPE jsonyylhsminor;
      case 0: /* top_value ::= json_value */
#line 78 "./json.yxx"
{ pEE->setTopValue(jsonyymsp[0].minor.jsonyy18); }
#line 1061 "./json.c"
        break;
      case 1: /* json_value ::= json_object */
      case 2: /* json_value ::= json_list */ jsonyytestcase(jsonyyruleno==2);
      case 3: /* json_value ::= json_boolean */ jsonyytestcase(jsonyyruleno==3);
      case 4: /* json_value ::= json_string */ jsonyytestcase(jsonyyruleno==4);
      case 5: /* json_value ::= json_integer */ jsonyytestcase(jsonyyruleno==5);
      case 6: /* json_value ::= json_null */ jsonyytestcase(jsonyyruleno==6);
#line 82 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = jsonyymsp[0].minor.jsonyy18; }
#line 1071 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 7: /* json_object ::= KEY_BRACE_OPEN json_key_value_list opt_comma KEY_BRACE_CLOSE */
#line 92 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(jsonyymsp[-2].minor.jsonyy31); jsonyymsp[-3].minor.jsonyy0 = 0; jsonyymsp[0].minor.jsonyy0 = 0;}
#line 1077 "./json.c"
  jsonyy_destructor(jsonyypParser,21,&jsonyymsp[-1].minor);
  jsonyymsp[-3].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 8: /* json_object ::= KEY_BRACE_OPEN KEY_BRACE_CLOSE */
#line 94 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue((JSONKeyValuePair*) 0); jsonyymsp[-1].minor.jsonyy0 = 0; jsonyymsp[0].minor.jsonyy0 = 0;}
#line 1084 "./json.c"
  jsonyymsp[-1].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 9: /* opt_comma ::= KEY_COMMA */
#line 98 "./json.yxx"
{ jsonyylhsminor.jsonyy28 = 0; jsonyymsp[0].minor.jsonyy0 = 0;}
#line 1090 "./json.c"
  jsonyymsp[0].minor.jsonyy28 = jsonyylhsminor.jsonyy28;
        break;
      case 10: /* opt_comma ::= */
#line 99 "./json.yxx"
{ jsonyymsp[1].minor.jsonyy28 = 0; }
#line 1096 "./json.c"
        break;
      case 11: /* json_key_value_list ::= json_key_value_list_element */
#line 105 "./json.yxx"
{ jsonyylhsminor.jsonyy31 = jsonyymsp[0].minor.jsonyy31; }
#line 1101 "./json.c"
  jsonyymsp[0].minor.jsonyy31 = jsonyylhsminor.jsonyy31;
        break;
      case 12: /* json_key_value_list ::= json_key_value_list KEY_COMMA json_key_value_list_element */
#line 109 "./json.yxx"
{ jsonyylhsminor.jsonyy31 = jsonyymsp[0].minor.jsonyy31; jsonyylhsminor.jsonyy31->setNext(jsonyymsp[-2].minor.jsonyy31); jsonyymsp[-1].minor.jsonyy0 = 0; }
#line 1107 "./json.c"
  jsonyymsp[-2].minor.jsonyy31 = jsonyylhsminor.jsonyy31;
        break;
      case 13: /* json_key_value_list_element ::= STRING KEY_COLON json_value */
#line 115 "./json.yxx"
{ jsonyylhsminor.jsonyy31 = new JSONKeyValuePair(jsonyymsp[-2].minor.jsonyy0->extractString(),jsonyymsp[0].minor.jsonyy18,0); delete jsonyymsp[-2].minor.jsonyy0; jsonyymsp[-1].minor.jsonyy0 = 0; }
#line 1113 "./json.c"
  jsonyymsp[-2].minor.jsonyy31 = jsonyylhsminor.jsonyy31;
        break;
      case 14: /* json_list ::= KEY_BRACKET_OPEN KEY_BRACKET_CLOSE */
#line 121 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue((JSONListElement*) 0); jsonyymsp[-1].minor.jsonyy0 = 0; jsonyymsp[0].minor.jsonyy0 = 0; }
#line 1119 "./json.c"
  jsonyymsp[-1].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 15: /* json_list ::= KEY_BRACKET_OPEN json_value_list opt_comma KEY_BRACKET_CLOSE */
#line 123 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(jsonyymsp[-2].minor.jsonyy39); jsonyymsp[-3].minor.jsonyy0 = 0; jsonyymsp[0].minor.jsonyy0 = 0; }
#line 1125 "./json.c"
  jsonyy_destructor(jsonyypParser,21,&jsonyymsp[-1].minor);
  jsonyymsp[-3].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 16: /* json_value_list ::= json_value */
#line 129 "./json.yxx"
{ jsonyylhsminor.jsonyy39 = new JSONListElement(jsonyymsp[0].minor.jsonyy18); }
#line 1132 "./json.c"
  jsonyymsp[0].minor.jsonyy39 = jsonyylhsminor.jsonyy39;
        break;
      case 17: /* json_value_list ::= json_value_list KEY_COMMA json_value */
#line 133 "./json.yxx"
{ jsonyylhsminor.jsonyy39 = new JSONListElement(jsonyymsp[0].minor.jsonyy18); jsonyylhsminor.jsonyy39->setNext(jsonyymsp[-2].minor.jsonyy39); jsonyymsp[-1].minor.jsonyy0 = 0; }
#line 1138 "./json.c"
  jsonyymsp[-2].minor.jsonyy39 = jsonyylhsminor.jsonyy39;
        break;
      case 18: /* json_string ::= STRING */
#line 143 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(jsonyymsp[0].minor.jsonyy0->extractString()); jsonyymsp[0].minor.jsonyy0->clear(); delete jsonyymsp[0].minor.jsonyy0; }
#line 1144 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 19: /* json_boolean ::= KEY_TRUE */
#line 149 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(true); jsonyymsp[0].minor.jsonyy0 = 0;}
#line 1150 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 20: /* json_boolean ::= KEY_FALSE */
#line 151 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(false); jsonyymsp[0].minor.jsonyy0 = 0;}
#line 1156 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 21: /* json_null ::= KEY_NULL */
#line 157 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(); jsonyymsp[0].minor.jsonyy0 = 0; }
#line 1162 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      case 22: /* json_integer ::= INTEGER */
#line 163 "./json.yxx"
{ jsonyylhsminor.jsonyy18 = new JSONValue(jsonyymsp[0].minor.jsonyy0->integer); delete jsonyymsp[0].minor.jsonyy0; }
#line 1168 "./json.c"
  jsonyymsp[0].minor.jsonyy18 = jsonyylhsminor.jsonyy18;
        break;
      default:
        break;
/********** End reduce actions ************************************************/
  };
  assert( jsonyyruleno<sizeof(jsonyyRuleInfoLhs)/sizeof(jsonyyRuleInfoLhs[0]) );
  jsonyygoto = jsonyyRuleInfoLhs[jsonyyruleno];
  jsonyysize = jsonyyRuleInfoNRhs[jsonyyruleno];
  jsonyyact = jsonyy_find_reduce_action(jsonyymsp[jsonyysize].stateno,(JSONYYCODETYPE)jsonyygoto);

  /* There are no SHIFTREDUCE actions on nonterminals because the table
  ** generator has simplified them to pure REDUCE actions. */
  assert( !(jsonyyact>JSONYY_MAX_SHIFT && jsonyyact<=JSONYY_MAX_SHIFTREDUCE) );

  /* It is not possible for a REDUCE to be followed by an error */
  assert( jsonyyact!=JSONYY_ERROR_ACTION );

  jsonyymsp += jsonyysize+1;
  jsonyypParser->jsonyytos = jsonyymsp;
  jsonyymsp->stateno = (JSONYYACTIONTYPE)jsonyyact;
  jsonyymsp->major = (JSONYYCODETYPE)jsonyygoto;
  jsonyyTraceShift(jsonyypParser, jsonyyact, "... then shift");
  return jsonyyact;
}

/*
** The following code executes when the parse fails
*/
#ifndef JSONYYNOERRORRECOVERY
static void jsonyy_parse_failed(
  jsonyyParser *jsonyypParser           /* The parser */
){
  JSONParserARG_FETCH
  JSONParserCTX_FETCH
#ifndef NDEBUG
  if( jsonyyTraceFILE ){
    fprintf(jsonyyTraceFILE,"%sFail!\n",jsonyyTracePrompt);
  }
#endif
  while( jsonyypParser->jsonyytos>jsonyypParser->jsonyystack ) jsonyy_pop_parser_stack(jsonyypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
/************ Begin %parse_failure code ***************************************/
#line 72 "./json.yxx"

  pEE->bSyntaxError = true;
#line 1216 "./json.c"
/************ End %parse_failure code *****************************************/
  JSONParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  JSONParserCTX_STORE
}
#endif /* JSONYYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void jsonyy_syntax_error(
  jsonyyParser *jsonyypParser,           /* The parser */
  int jsonyymajor,                   /* The major type of the error token */
  JSONParserTOKENTYPE jsonyyminor         /* The minor type of the error token */
){
  JSONParserARG_FETCH
  JSONParserCTX_FETCH
#define TOKEN jsonyyminor
/************ Begin %syntax_error code ****************************************/
#line 58 "./json.yxx"

  UNUSED(jsonyyminor);
  UNUSED(jsonyymajor);
  pEE->bSyntaxError = true;
  std::string errMsg;
  if (TOKEN == 0) {
     errMsg = "syntax error near <<EOF>>";
  } else {
     errMsg = "syntax error near " + TOKEN->getTokenName();
  }
  pEE->addToError(errMsg);
#line 1247 "./json.c"
/************ End %syntax_error code ******************************************/
  JSONParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  JSONParserCTX_STORE
}

/*
** The following is executed when the parser accepts
*/
static void jsonyy_accept(
  jsonyyParser *jsonyypParser           /* The parser */
){
  JSONParserARG_FETCH
  JSONParserCTX_FETCH
#ifndef NDEBUG
  if( jsonyyTraceFILE ){
    fprintf(jsonyyTraceFILE,"%sAccept!\n",jsonyyTracePrompt);
  }
#endif
#ifndef JSONYYNOERRORRECOVERY
  jsonyypParser->jsonyyerrcnt = -1;
#endif
  assert( jsonyypParser->jsonyytos==jsonyypParser->jsonyystack );
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
/*********** Begin %parse_accept code *****************************************/
/*********** End %parse_accept code *******************************************/
  JSONParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  JSONParserCTX_STORE
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "JSONParserAlloc" which describes the current state of the parser.
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
void JSONParser(
  void *jsonyyp,                   /* The parser */
  int jsonyymajor,                 /* The major token code number */
  JSONParserTOKENTYPE jsonyyminor       /* The value for the token */
  JSONParserARG_PDECL               /* Optional %extra_argument parameter */
){
  JSONYYMINORTYPE jsonyyminorunion;
  JSONYYACTIONTYPE jsonyyact;   /* The parser action. */
#if !defined(JSONYYERRORSYMBOL) && !defined(JSONYYNOERRORRECOVERY)
  int jsonyyendofinput;     /* True if we are at the end of input */
#endif
#ifdef JSONYYERRORSYMBOL
  int jsonyyerrorhit = 0;   /* True if jsonyymajor has invoked an error */
#endif
  jsonyyParser *jsonyypParser = (jsonyyParser*)jsonyyp;  /* The parser */
  JSONParserCTX_FETCH
  JSONParserARG_STORE

  assert( jsonyypParser->jsonyytos!=0 );
#if !defined(JSONYYERRORSYMBOL) && !defined(JSONYYNOERRORRECOVERY)
  jsonyyendofinput = (jsonyymajor==0);
#endif

  jsonyyact = jsonyypParser->jsonyytos->stateno;
#ifndef NDEBUG
  if( jsonyyTraceFILE ){
    if( jsonyyact < JSONYY_MIN_REDUCE ){
      fprintf(jsonyyTraceFILE,"%sInput '%s' in state %d\n",
              jsonyyTracePrompt,jsonyyTokenName[jsonyymajor],jsonyyact);
    }else{
      fprintf(jsonyyTraceFILE,"%sInput '%s' with pending reduce %d\n",
              jsonyyTracePrompt,jsonyyTokenName[jsonyymajor],jsonyyact-JSONYY_MIN_REDUCE);
    }
  }
#endif

  do{
    assert( jsonyyact==jsonyypParser->jsonyytos->stateno );
    jsonyyact = jsonyy_find_shift_action((JSONYYCODETYPE)jsonyymajor,jsonyyact);
    if( jsonyyact >= JSONYY_MIN_REDUCE ){
      jsonyyact = jsonyy_reduce(jsonyypParser,jsonyyact-JSONYY_MIN_REDUCE,jsonyymajor,
                        jsonyyminor JSONParserCTX_PARAM);
    }else if( jsonyyact <= JSONYY_MAX_SHIFTREDUCE ){
      jsonyy_shift(jsonyypParser,jsonyyact,(JSONYYCODETYPE)jsonyymajor,jsonyyminor);
#ifndef JSONYYNOERRORRECOVERY
      jsonyypParser->jsonyyerrcnt--;
#endif
      break;
    }else if( jsonyyact==JSONYY_ACCEPT_ACTION ){
      jsonyypParser->jsonyytos--;
      jsonyy_accept(jsonyypParser);
      return;
    }else{
      assert( jsonyyact == JSONYY_ERROR_ACTION );
      jsonyyminorunion.jsonyy0 = jsonyyminor;
#ifdef JSONYYERRORSYMBOL
      int jsonyymx;
#endif
#ifndef NDEBUG
      if( jsonyyTraceFILE ){
        fprintf(jsonyyTraceFILE,"%sSyntax Error!\n",jsonyyTracePrompt);
      }
#endif
#ifdef JSONYYERRORSYMBOL
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
      if( jsonyypParser->jsonyyerrcnt<0 ){
        jsonyy_syntax_error(jsonyypParser,jsonyymajor,jsonyyminor);
      }
      jsonyymx = jsonyypParser->jsonyytos->major;
      if( jsonyymx==JSONYYERRORSYMBOL || jsonyyerrorhit ){
#ifndef NDEBUG
        if( jsonyyTraceFILE ){
          fprintf(jsonyyTraceFILE,"%sDiscard input token %s\n",
             jsonyyTracePrompt,jsonyyTokenName[jsonyymajor]);
        }
#endif
        jsonyy_destructor(jsonyypParser, (JSONYYCODETYPE)jsonyymajor, &jsonyyminorunion);
        jsonyymajor = JSONYYNOCODE;
      }else{
        while( jsonyypParser->jsonyytos >= jsonyypParser->jsonyystack
            && (jsonyyact = jsonyy_find_reduce_action(
                        jsonyypParser->jsonyytos->stateno,
                        JSONYYERRORSYMBOL)) > JSONYY_MAX_SHIFTREDUCE
        ){
          jsonyy_pop_parser_stack(jsonyypParser);
        }
        if( jsonyypParser->jsonyytos < jsonyypParser->jsonyystack || jsonyymajor==0 ){
          jsonyy_destructor(jsonyypParser,(JSONYYCODETYPE)jsonyymajor,&jsonyyminorunion);
          jsonyy_parse_failed(jsonyypParser);
#ifndef JSONYYNOERRORRECOVERY
          jsonyypParser->jsonyyerrcnt = -1;
#endif
          jsonyymajor = JSONYYNOCODE;
        }else if( jsonyymx!=JSONYYERRORSYMBOL ){
          jsonyy_shift(jsonyypParser,jsonyyact,JSONYYERRORSYMBOL,jsonyyminor);
        }
      }
      jsonyypParser->jsonyyerrcnt = 3;
      jsonyyerrorhit = 1;
      if( jsonyymajor==JSONYYNOCODE ) break;
      jsonyyact = jsonyypParser->jsonyytos->stateno;
#elif defined(JSONYYNOERRORRECOVERY)
      /* If the JSONYYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      jsonyy_syntax_error(jsonyypParser,jsonyymajor, jsonyyminor);
      jsonyy_destructor(jsonyypParser,(JSONYYCODETYPE)jsonyymajor,&jsonyyminorunion);
      break;
#else  /* JSONYYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( jsonyypParser->jsonyyerrcnt<=0 ){
        jsonyy_syntax_error(jsonyypParser,jsonyymajor, jsonyyminor);
      }
      jsonyypParser->jsonyyerrcnt = 3;
      jsonyy_destructor(jsonyypParser,(JSONYYCODETYPE)jsonyymajor,&jsonyyminorunion);
      if( jsonyyendofinput ){
        jsonyy_parse_failed(jsonyypParser);
#ifndef JSONYYNOERRORRECOVERY
        jsonyypParser->jsonyyerrcnt = -1;
#endif
      }
      break;
#endif
    }
  }while( jsonyypParser->jsonyytos>jsonyypParser->jsonyystack );
#ifndef NDEBUG
  if( jsonyyTraceFILE ){
    jsonyyStackEntry *i;
    char cDiv = '[';
    fprintf(jsonyyTraceFILE,"%sReturn. Stack=",jsonyyTracePrompt);
    for(i=&jsonyypParser->jsonyystack[1]; i<=jsonyypParser->jsonyytos; i++){
      fprintf(jsonyyTraceFILE,"%c%s", cDiv, jsonyyTokenName[i->major]);
      cDiv = ' ';
    }
    fprintf(jsonyyTraceFILE,"]\n");
  }
#endif
  return;
}

/*
** Return the fallback token corresponding to canonical token iToken, or
** 0 if iToken has no fallback.
*/
int JSONParserFallback(int iToken){
#ifdef JSONYYFALLBACK
  assert( iToken<(int)(sizeof(jsonyyFallback)/sizeof(jsonyyFallback[0])) );
  return jsonyyFallback[iToken];
#else
  (void)iToken;
  return 0;
#endif
}
