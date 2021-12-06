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
#line 1 "./mql.yxx"


/*
 * mql.yxx
 *
 * MQL parser
 *
 * Ulrik Petersen
 * Created: 2/27-2001
 * Last update: 11/30-2018
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
#include <string_list.h>
#include <cstdlib>
#include <string>
#include <mql_error.h>
#include <mql_types.h>
#include <mql_database_statements.h>
#include <mql_enumeration_statements.h>
#include <mql_features_statements.h>
#include <mql_meta_statements.h>
#include <mql_monads_statements.h>
#include <mql_object_statements.h>
#include <mql_object_type_statements.h>
#include <mql_segment_statements.h>
#include <mql_select_statements.h>
#include <mql_query.h>
#include <mql_extern.h>
#include <mql_execution_environment.h>
#include <mql_yylex.h>

#undef TOKEN

#undef MQLYYCODETYPE
#undef MQLYYNOCODE
#undef MQLYYACTIONTYPE
#undef MQLYYNSTATE
#undef MQLYYNRULE
#undef MQLYY_ACTTAB_COUNT
#undef MQLYY_SHIFT_COUNT
#undef MQLYY_SHIFT_MAX
#undef MQLYY_REDUCE_USE_DFLT
#undef MQLYY_REDUCE_COUNT
#undef MQLYY_REDUCE_MIN
#undef MQLYY_REDUCE_MAX
#undef MYMIN


#line 93 "./mql.c"
/**************** End of %include directives **********************************/
/* These constants specify the various numeric values for terminal symbols
** in a format understandable to "makeheaders".  This section is blank unless
** "lemon" is run with the "-m" command-line option.
***************** Begin makeheaders token definitions *************************/
/**************** End makeheaders token definitions ***************************/

/* The next sections is a series of control #defines.
** various aspects of the generated parser.
**    MQLYYCODETYPE         is the data type used to store the integer codes
**                       that represent terminal and non-terminal symbols.
**                       "unsigned char" is used if there are fewer than
**                       256 symbols.  Larger types otherwise.
**    MQLYYNOCODE           is a number of type MQLYYCODETYPE that is not used for
**                       any terminal or nonterminal symbol.
**    MQLYYFALLBACK         If defined, this indicates that one or more tokens
**                       (also known as: "terminal symbols") have fall-back
**                       values which should be used if the original symbol
**                       would not parse.  This permits keywords to sometimes
**                       be used as identifiers, for example.
**    MQLYYACTIONTYPE       is the data type used for "action codes" - numbers
**                       that indicate what to do in response to the next
**                       token.
**    MQLParserTOKENTYPE     is the data type used for minor type for terminal
**                       symbols.  Background: A "minor type" is a semantic
**                       value associated with a terminal or non-terminal
**                       symbols.  For example, for an "ID" terminal symbol,
**                       the minor type might be the name of the identifier.
**                       Each non-terminal can have a different minor type.
**                       Terminal symbols all have the same minor type, though.
**                       This macros defines the minor type for terminal 
**                       symbols.
**    MQLYYMINORTYPE        is the data type used for all minor types.
**                       This is typically a union of many types, one of
**                       which is MQLParserTOKENTYPE.  The entry in the union
**                       for terminal symbols is called "mqlyy0".
**    MQLYYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    MQLParserARG_SDECL     A static variable declaration for the %extra_argument
**    MQLParserARG_PDECL     A parameter declaration for the %extra_argument
**    MQLParserARG_PARAM     Code to pass %extra_argument as a subroutine parameter
**    MQLParserARG_STORE     Code to store %extra_argument into mqlyypParser
**    MQLParserARG_FETCH     Code to extract %extra_argument from mqlyypParser
**    MQLParserCTX_*         As MQLParserARG_ except for %extra_context
**    MQLYYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
**    MQLYYNSTATE           the combined number of states.
**    MQLYYNRULE            the number of rules in the grammar
**    MQLYYNTOKEN           Number of terminal symbols
**    MQLYY_MAX_SHIFT       Maximum value for shift actions
**    MQLYY_MIN_SHIFTREDUCE Minimum value for shift-reduce actions
**    MQLYY_MAX_SHIFTREDUCE Maximum value for shift-reduce actions
**    MQLYY_ERROR_ACTION    The mqlyy_action[] code for syntax error
**    MQLYY_ACCEPT_ACTION   The mqlyy_action[] code for accept
**    MQLYY_NO_ACTION       The mqlyy_action[] code for no-op
**    MQLYY_MIN_REDUCE      Minimum value for reduce actions
**    MQLYY_MAX_REDUCE      Maximum value for reduce actions
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/************* Begin control #defines *****************************************/
#define MQLYYCODETYPE unsigned short int
#define MQLYYNOCODE 312
#define MQLYYACTIONTYPE unsigned short int
#define MQLParserTOKENTYPE Token*
typedef union {
  int mqlyyinit;
  MQLParserTOKENTYPE mqlyy0;
  FTerm* mqlyy1;
  BlockString2* mqlyy23;
  eMonadUniquenessType mqlyy51;
  monad_m mqlyy88;
  FFactor* mqlyy108;
  int mqlyy124;
  UnorderedGroup* mqlyy128;
  GapBlock* mqlyy138;
  FFeatures* mqlyy168;
  ECDeclaration* mqlyy173;
  IntegerListNode* mqlyy183;
  MQLType* mqlyy187;
  MonadSetChainElement* mqlyy207;
  GrammarFeature* mqlyy218;
  UsingRange* mqlyy222;
  ID_D* mqlyy243;
  eMonadSetRelationOperation mqlyy248;
  OptGapBlock* mqlyy289;
  Value* mqlyy300;
  eObjectRangeType mqlyy316;
  ObjectBlockString* mqlyy324;
  ECUpdate* mqlyy338;
  AggregateFeature* mqlyy354;
  ObjectReferenceUsage* mqlyy366;
  Topograph* mqlyy367;
  StringListNode* mqlyy368;
  MaxRange* mqlyy374;
  bool mqlyy377;
  eComparisonOp mqlyy384;
  FeatureDeclaration* mqlyy385;
  ObjectSpec* mqlyy389;
  eUniverseOrSubstrate mqlyy397;
  MonadSetRelationClause* mqlyy409;
  BlockString* mqlyy421;
  FeatureAssignment* mqlyy432;
  ObjectBlock* mqlyy461;
  emdf_ivalue mqlyy466;
  Expression* mqlyy475;
  ObjectSpecNoOT* mqlyy481;
  ComputedFeatureName* mqlyy485;
  eFocusSpec mqlyy493;
  FeatureComparison* mqlyy526;
  Block* mqlyy534;
  MQLMonadSetElement* mqlyy538;
  eRetrieval mqlyy540;
  BlockString0* mqlyy541;
  Blocks* mqlyy545;
  eFirstLast mqlyy546;
  FeatureUpdate* mqlyy550;
  eSetOperator mqlyy566;
  Statement* mqlyy568;
  Power* mqlyy572;
  BlockString1* mqlyy594;
  id_d_t mqlyy600;
  sheaf_return_type_pair* mqlyy621;
  emdf_ivalue* mqlyy624;
} MQLYYMINORTYPE;
#ifndef MQLYYSTACKDEPTH
#define MQLYYSTACKDEPTH 2000
#endif
#define MQLParserARG_SDECL MQLExecEnv *pEE;
#define MQLParserARG_PDECL ,MQLExecEnv *pEE
#define MQLParserARG_PARAM ,pEE
#define MQLParserARG_FETCH MQLExecEnv *pEE=mqlyypParser->pEE;
#define MQLParserARG_STORE mqlyypParser->pEE=pEE;
#define MQLParserCTX_SDECL
#define MQLParserCTX_PDECL
#define MQLParserCTX_PARAM
#define MQLParserCTX_FETCH
#define MQLParserCTX_STORE
#define MQLYYNSTATE             437
#define MQLYYNRULE              396
#define MQLYYNRULE_WITH_ACTION  396
#define MQLYYNTOKEN             131
#define MQLYY_MAX_SHIFT         436
#define MQLYY_MIN_SHIFTREDUCE   772
#define MQLYY_MAX_SHIFTREDUCE   1167
#define MQLYY_ERROR_ACTION      1168
#define MQLYY_ACCEPT_ACTION     1169
#define MQLYY_NO_ACTION         1170
#define MQLYY_MIN_REDUCE        1171
#define MQLYY_MAX_REDUCE        1566
/************* End control #defines *******************************************/
#define MQLYY_NLOOKAHEAD ((int)(sizeof(mqlyy_lookahead)/sizeof(mqlyy_lookahead[0])))

/* Define the mqlyytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define mqlyytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the mqlyytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef mqlyytestcase
# define mqlyytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N <= MQLYY_MAX_SHIFT             Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   N between MQLYY_MIN_SHIFTREDUCE       Shift to an arbitrary state then
**     and MQLYY_MAX_SHIFTREDUCE           reduce by rule N-MQLYY_MIN_SHIFTREDUCE.
**
**   N == MQLYY_ERROR_ACTION               A syntax error has occurred.
**
**   N == MQLYY_ACCEPT_ACTION              The parser accepts its input.
**
**   N == MQLYY_NO_ACTION                  No such action.  Denotes unused
**                                      slots in the mqlyy_action[] table.
**
**   N between MQLYY_MIN_REDUCE            Reduce by rule N-MQLYY_MIN_REDUCE
**     and MQLYY_MAX_REDUCE
**
** The action table is constructed as a single large table named mqlyy_action[].
** Given state S and lookahead X, the action is computed as either:
**
**    (A)   N = mqlyy_action[ mqlyy_shift_ofst[S] + X ]
**    (B)   N = mqlyy_default[S]
**
** The (A) formula is preferred.  The B formula is used instead if
** mqlyy_lookahead[mqlyy_shift_ofst[S]+X] is not equal to X.
**
** The formulas above are for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the mqlyy_reduce_ofst[] array is used in place of
** the mqlyy_shift_ofst[] array.
**
** The following are the tables generated in this section:
**
**  mqlyy_action[]        A single table containing all actions.
**  mqlyy_lookahead[]     A table containing the lookahead for each entry in
**                     mqlyy_action.  Used to detect hash collisions.
**  mqlyy_shift_ofst[]    For each state, the offset into mqlyy_action for
**                     shifting terminals.
**  mqlyy_reduce_ofst[]   For each state, the offset into mqlyy_action for
**                     shifting non-terminals after a reduce.
**  mqlyy_default[]       Default action for each state.
**
*********** Begin parsing tables **********************************************/
#define MQLYY_ACTTAB_COUNT (1006)
static const MQLYYACTIONTYPE mqlyy_action[] = {
 /*     0 */  1169,  436, 1172, 1173, 1174, 1175, 1176, 1177, 1178, 1179,
 /*    10 */  1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189,
 /*    20 */  1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197, 1198, 1199,
 /*    30 */  1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209,
 /*    40 */  1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219,
 /*    50 */    46,  136,  329,  855,  361,  194,  425,   73, 1257,  424,
 /*    60 */    47,  188, 1469, 1470,  277, 1471,    5,    2,  266,  276,
 /*    70 */   356,  127,  355,  354,  887,  901,  902,  903,  300,    3,
 /*    80 */  1375,   68, 1124,  222,  384,  387, 1541, 1542, 1543, 1544,
 /*    90 */  1545, 1018, 1430,  172,  310,  171,  370, 1479,  378,  277,
 /*   100 */  1471,    5,  153,  266,  276,   25,  853, 1427,  173,   55,
 /*   110 */    87, 1467, 1468,  115,  892,   15, 1019,  297, 1026,  298,
 /*   120 */    83, 1541, 1542, 1543, 1544, 1545,  112, 1125, 1126, 1127,
 /*   130 */  1128, 1129, 1130, 1131, 1132,  278,  272,  277, 1471,    5,
 /*   140 */   427,  266,  276,  919,  920,  428,  327,  201, 1027,  380,
 /*   150 */  1380, 1067, 1538,  231,   63, 1081, 1082, 1434,  949, 1541,
 /*   160 */  1542, 1543, 1544, 1545,  919,  920, 1030, 1029,  855,  203,
 /*   170 */   948, 1461, 1013,  115,  892,   76,  138,  137,   93, 1350,
 /*   180 */    83,  285,    2,  239,  240,   83, 1006,  855, 1012,  925,
 /*   190 */    83, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132,  277,
 /*   200 */  1471,    5,  228, 1476,  276,  277, 1471,    5, 1124, 1477,
 /*   210 */   276,  270,   83,    1,   26,  937,   62,  333, 1507, 1511,
 /*   220 */    84, 1541, 1542, 1543, 1544, 1545,  120, 1541, 1542, 1543,
 /*   230 */  1544, 1545,  134, 1051,  360,   82, 1051,  143,  242,  422,
 /*   240 */   939, 1383,  335,  315, 1052,  113,    2, 1052,  403,  343,
 /*   250 */   381,  248,  982, 1125, 1126, 1127, 1128, 1129, 1130, 1131,
 /*   260 */  1132,  307,  418,  189,  124,  215,  213,  121,  411, 1533,
 /*   270 */  1081, 1082,  331, 1135,  331, 1135,  334,  332, 1507, 1511,
 /*   280 */    84,  334,  332, 1507, 1511,   84,  334,  332, 1507, 1511,
 /*   290 */    84,  138,  137,   93, 1390,    2, 1282,  855,  385, 1060,
 /*   300 */  1533, 1081, 1082,  116, 1430, 1037,  338, 1061,  241,  332,
 /*   310 */  1507, 1511,   84, 1087, 1026,  192, 1533,  853,  183, 1427,
 /*   320 */    27,  937,   83,  937,   93, 1513,   83,  330,  385,   82,
 /*   330 */   357, 1037,    6,  385, 1081, 1082,  243, 1330,  353, 1535,
 /*   340 */  1532, 1512, 1539, 1037, 1027,  422,  939,  422,  939, 1052,
 /*   350 */   228,  349,  133,  287,  937, 1115,  322,   93,  330,   16,
 /*   360 */   915,   54,   10,  362,   72, 1422,  381,  324,  320,  318,
 /*   370 */  1535, 1532,  915, 1026,  330,  919,  920, 1041,  422,  939,
 /*   380 */   937, 1434,  281, 1081, 1082, 1434, 1535, 1532, 1434,  352,
 /*   390 */   310,  310,  937, 1032,   56, 1422,  919,  920,  386,   72,
 /*   400 */  1422,  160,  292, 1027,  422,  939,   93,  249,  250,    3,
 /*   410 */   346,  234,  233,    3,  237,  238,  422,  939,  184, 1353,
 /*   420 */  1509, 1511,   84,    3, 1508, 1511,   84,  176,  211,  174,
 /*   430 */   207,    3, 1379, 1042,  180,  177,  892, 1380,  311, 1456,
 /*   440 */   130,   82, 1540, 1026, 1380, 1351, 1540,  385,  365,  269,
 /*   450 */   229,   58, 1287,   70,  937,  310, 1540,  244, 1321,  202,
 /*   460 */  1099, 1100, 1101, 1091, 1540, 1156,  263, 1461, 1461, 1444,
 /*   470 */   264, 1102, 1103, 1027,  379, 1442, 1026,  873,  422,  939,
 /*   480 */   265,  255,   85,  380,  380,  901,  902,  903,  268, 1434,
 /*   490 */   293, 1053, 1089, 1090, 1154, 1155, 1041,  140, 1295,  345,
 /*   500 */   139,    7,  273,    8,  273,  955, 1027,  302,  183,   82,
 /*   510 */   142,  256,   99,  955, 1423,  871,  236,   82,  872, 1288,
 /*   520 */    70, 1353,  330,  344, 1087,  330,  915, 1331,  341,  339,
 /*   530 */  1315, 1373, 1462, 1550, 1521,  317,  316, 1520, 1312, 1311,
 /*   540 */  1289,  424, 1310, 1309, 1444,  198, 1446,  165, 1258,  424,
 /*   550 */  1443,  996, 1042, 1547,   95, 1298, 1323, 1327,  100,  251,
 /*   560 */  1356,  380, 1322,  202,  133, 1147,  275, 1102, 1103, 1094,
 /*   570 */  1009, 1008,   28,  282,  919,  920, 1004,  908,  822,  823,
 /*   580 */   259,  416,  380,  973,  399,  839,  840,  262,  149,  261,
 /*   590 */   395,  906,  107,  309,  994,  997,  993,  992, 1120,  907,
 /*   600 */   148, 1118, 1474,   60, 1119,  971, 1111,   96,   13, 1116,
 /*   610 */   415, 1117,   60,   98,  419,   98,  421,  391,  419,  337,
 /*   620 */   390,   98,  218,  308,  393,  998,  419,  245,   98,   57,
 /*   630 */    81, 1034,  930,  918,  850,  397, 1033,   29,  406,   88,
 /*   640 */   216,  409,   12,  956,   11,   40, 1384,   69,  419,  101,
 /*   650 */    35,  103,   36,   98, 1335, 1561,  161,   14,  417, 1435,
 /*   660 */   254, 1548,   50,  271,   52,  154,  284,  156,  303,  305,
 /*   670 */    66,  342,  319,  321,  323,  328,  350, 1231,  193,  195,
 /*   680 */  1415,  426, 1265, 1264, 1263, 1262, 1261,  224,  429,  226,
 /*   690 */    21,  258, 1345,   38,  128,   34,  129,  252, 1374,  136,
 /*   700 */   144,   90, 1086, 1167,  135,   91, 1087,   92, 1565, 1564,
 /*   710 */  1562,  267,   37, 1483,  940,   94,  279,  146,   49,  145,
 /*   720 */   227, 1344,  921,  150,  151,  152,  289, 1406,  283, 1410,
 /*   730 */   294,  290,  950, 1346,  301, 1299,  326,   65,  291,  304,
 /*   740 */   915,   41,  232,    9,  167, 1316,  381,  175,  340, 1294,
 /*   750 */   927,  312, 1334,  179,   42,  835, 1453,  336, 1232,  830,
 /*   760 */   187,   43,  432,  430, 1333, 1457, 1224, 1236, 1223,  117,
 /*   770 */   383,  943,  363,  358,  372,  178,  209,  413, 1438,  206,
 /*   780 */   885,  366,   89, 1454, 1449, 1447,  181, 1332,  414,  182,
 /*   790 */   348, 1340,  246,  196,   23,  434, 1313,   19,  389,  965,
 /*   800 */  1220, 1235,  223,  253,   20,  125, 1308,  220,  131,  964,
 /*   810 */   212, 1414,  122, 1341,  123,  376,  214,  377,   80,  374,
 /*   820 */   423,  217,  963,  225,  257,   75,  132,  260,  141, 1160,
 /*   830 */   967, 1157, 1152,    4, 1161,   60, 1097, 1096,   51,  102,
 /*   840 */  1095,  274,  147,  972,   77, 1073,  104,  280, 1003, 1001,
 /*   850 */  1357,  155,  105,  106,  977,  286,  978,  157,   39,  288,
 /*   860 */   158,  979,  296, 1413,  299,  210,  295,  904,   78, 1059,
 /*   870 */   162,  159,   59, 1002,  163, 1066,  108, 1065,  306,  995,
 /*   880 */   164,  230,   61,  313,  314,  325,   64,  983, 1486,  166,
 /*   890 */   990,  989,  988,   53,   17,  235,  109,  168,  110,  987,
 /*   900 */   111,  986,   14,   24,  897,  170,   48,   67, 1056,   30,
 /*   910 */   112, 1123,  185,  891,  114,  186,  351,  843,   31, 1450,
 /*   920 */   894,  842,  190,  841,  191,  359,  118, 1049,   18,  197,
 /*   930 */   364,   79,  169,  199,  367,  368,  369,  944,   32,  347,
 /*   940 */   204,  205,   33,  373,  200, 1020,   45,  371,  382,  375,
 /*   950 */    71,  388,   44,  208,  119,  848, 1025,  877,  847,  846,
 /*   960 */   392,  396,  400,  852,  412,  401,  394,  402,  398,  851,
 /*   970 */   247,  875,  870,  869,  882,   22, 1038,  868,  844,  219,
 /*   980 */   867,  420,  404,  221,  838,  407,   74,  126,  405,  410,
 /*   990 */   861,  408,   86,  879,   97,  860,  874,  826,  431,  828,
 /*  1000 */  1171,  433,  435,  960, 1170,  938,
};
static const MQLYYCODETYPE mqlyy_lookahead[] = {
 /*     0 */   131,  132,  133,  134,  135,  136,  137,  138,  139,  140,
 /*    10 */   141,  142,  143,  144,  145,  146,  147,  148,  149,  150,
 /*    20 */   151,  152,  153,  154,  155,  156,  157,  158,  159,  160,
 /*    30 */   161,  162,  163,  164,  165,  166,  167,  168,  169,  170,
 /*    40 */   171,  172,  173,  174,  175,  176,  177,  178,  179,  180,
 /*    50 */     2,  194,  198,    4,    6,    7,  195,  196,  197,  198,
 /*    60 */    12,   13,  278,  279,  280,  281,  282,   18,  284,  285,
 /*    70 */    22,    3,   24,   25,   19,   64,   65,   66,   30,  244,
 /*    80 */   245,   70,   72,   15,  206,   17,  302,  303,  304,  305,
 /*    90 */   306,   53,  214,  210,  198,  212,   28,  278,   30,  280,
 /*   100 */   281,  282,  233,  284,  285,   57,   17,  229,   60,   61,
 /*   110 */    62,  276,  277,   58,   59,   67,   78,   28,    4,   30,
 /*   120 */   198,  302,  303,  304,  305,  306,   52,  117,  118,  119,
 /*   130 */   120,  121,  122,  123,  124,  278,  218,  280,  281,  282,
 /*   140 */   190,  284,  285,   75,   76,  189,   72,   79,   34,  266,
 /*   150 */   194,  103,  298,  257,   80,  106,  107,  229,   69,  302,
 /*   160 */   303,  304,  305,  306,   75,   76,    4,    5,    4,  219,
 /*   170 */    81,  275,   83,   58,   59,  126,  127,  128,  129,   90,
 /*   180 */   198,   92,   18,  255,  256,  198,   97,    4,   99,   55,
 /*   190 */   198,  117,  118,  119,  120,  121,  122,  123,  124,  280,
 /*   200 */   281,  282,   27,  284,  285,  280,  281,  282,   72,  284,
 /*   210 */   285,  293,  198,   18,   52,   53,   80,  295,  296,  297,
 /*   220 */   298,  302,  303,  304,  305,  306,    4,  302,  303,  304,
 /*   230 */   305,  306,  250,   17,  190,   73,   17,  250,  248,   77,
 /*   240 */    78,  251,  250,   28,   28,   30,   18,   28,   26,   34,
 /*   250 */    34,   29,   69,  117,  118,  119,  120,  121,  122,  123,
 /*   260 */   124,   46,   40,  219,   42,   43,   44,   45,   46,  229,
 /*   270 */   106,  107,    4,    5,    4,    5,  294,  295,  296,  297,
 /*   280 */   298,  294,  295,  296,  297,  298,  294,  295,  296,  297,
 /*   290 */   298,  127,  128,  129,  254,   18,  206,    4,  198,   84,
 /*   300 */   229,  106,  107,    3,  214,    4,   91,   92,  294,  295,
 /*   310 */   296,  297,  298,    4,    4,   15,  229,   17,  209,  229,
 /*   320 */    52,   53,  198,   53,  129,  254,  198,  287,  198,   73,
 /*   330 */    30,    4,  104,  198,  106,  107,  227,  228,   17,  299,
 /*   340 */   300,  254,   19,    4,   34,   77,   78,   77,   78,   28,
 /*   350 */    27,   30,   18,  190,   53,   54,   82,  129,  287,   49,
 /*   360 */     4,   52,   52,  263,  264,  265,   34,   93,   94,   95,
 /*   370 */   299,  300,    4,    4,  287,   75,   76,   45,   77,   78,
 /*   380 */    53,  229,  219,  106,  107,  229,  299,  300,  229,  190,
 /*   390 */   198,  198,   53,   54,  264,  265,   75,   76,  263,  264,
 /*   400 */   265,  238,  239,   34,   77,   78,  129,  255,  256,  244,
 /*   410 */   211,  255,  256,  244,  255,  256,   77,   78,  219,  214,
 /*   420 */   296,  297,  298,  244,  296,  297,  298,  210,  210,  212,
 /*   430 */   212,  244,  189,  101,   57,   58,   59,  194,   69,  189,
 /*   440 */     4,   73,  277,    4,  194,  240,  277,  198,    2,  257,
 /*   450 */   257,  207,  208,  209,   53,  198,  277,  221,  222,  223,
 /*   460 */   112,  113,  114,   81,  277,   81,  301,  275,  275,  262,
 /*   470 */   301,  115,  116,   34,  267,  268,    4,    4,   77,   78,
 /*   480 */   301,   53,  198,  266,  266,   64,   65,   66,  301,  229,
 /*   490 */   247,   19,  110,  111,  110,  111,   45,  117,  210,  211,
 /*   500 */   120,  291,  292,  291,  292,   69,   34,  212,  209,   73,
 /*   510 */   130,   83,   84,   69,  265,   42,  256,   73,   45,  208,
 /*   520 */   209,  214,  287,  273,    4,  287,    4,  228,  212,  217,
 /*   530 */   218,  194,  275,  214,  299,   96,  252,  299,  214,  214,
 /*   540 */   197,  198,  218,  218,  262,  269,  270,  240,  197,  198,
 /*   550 */   268,   19,  101,  302,  213,  214,  225,  226,  307,  241,
 /*   560 */   242,  266,  222,  223,   18,   19,   33,  115,  116,   36,
 /*   570 */    75,   76,   52,   17,   75,   76,   20,   46,    4,    5,
 /*   580 */   243,    8,  266,   54,   31,   20,   21,   86,   52,   88,
 /*   590 */    37,   69,   51,    4,   19,    4,   54,   54,   54,   68,
 /*   600 */    71,   54,  283,   71,   54,   69,   54,   72,  253,   54,
 /*   610 */    37,   54,   71,   71,   71,   71,   53,   27,   71,   51,
 /*   620 */    30,   71,  199,   34,   26,   34,   71,   29,   71,   71,
 /*   630 */    71,   54,   74,   74,   34,   35,   54,   62,   27,   71,
 /*   640 */    71,   30,  253,   74,  253,  274,  251,  215,   71,  289,
 /*   650 */   308,  289,  308,   71,  229,  310,  215,  105,  202,  229,
 /*   660 */   198,  302,  290,  293,  290,  259,  258,  219,  211,  198,
 /*   670 */   216,  211,  198,  198,  198,  198,  198,  181,  181,  181,
 /*   680 */   262,  193,  203,  203,  203,  203,  203,  181,  188,   85,
 /*   690 */    89,    8,  237,   62,  236,  309,  235,  194,  194,  194,
 /*   700 */   108,  286,  109,   53,  288,  288,    4,  288,  311,  311,
 /*   710 */   311,  311,  309,  287,   53,  286,  230,  194,   80,  288,
 /*   720 */   230,  237,    4,  236,  235,  234,   30,  220,  194,  220,
 /*   730 */   214,  194,   28,  239,  194,  214,   10,   80,  246,  194,
 /*   740 */     4,   18,  194,  194,  234,  218,   34,   18,  194,  210,
 /*   750 */     4,  249,  224,  223,  194,   14,  271,  249,  186,    3,
 /*   760 */   184,  194,    8,   16,  226,  272,  182,  187,  182,  184,
 /*   770 */     8,    4,  260,  194,   53,  224,   18,   52,  261,  260,
 /*   780 */    56,  194,  218,  272,  271,  270,  224,  226,   51,  223,
 /*   790 */   220,  220,    8,  210,   55,   10,  218,  194,   48,   19,
 /*   800 */   183,  187,  182,   51,  194,  192,  210,  191,   18,   34,
 /*   810 */   204,  214,  205,  232,  205,  220,  204,  218,  224,  231,
 /*   820 */   201,  200,   34,   27,   82,   16,   71,   87,   35,   19,
 /*   830 */    87,   19,   19,  105,   19,   71,   54,   54,   52,   71,
 /*   840 */    36,   35,   18,   54,   96,   19,   51,   98,   20,   19,
 /*   850 */   242,   18,   51,   10,   19,   21,   53,   18,   18,   72,
 /*   860 */    90,   19,   31,  261,   46,  260,   34,   68,   63,   19,
 /*   870 */    18,   80,    8,   19,   18,   54,   84,   54,   51,   19,
 /*   880 */    18,   52,   80,   34,   31,   30,  125,   19,  125,   18,
 /*   890 */    54,   54,   54,   52,   35,   84,   52,   28,   52,   54,
 /*   900 */    52,   54,  105,   52,   19,   18,   92,    8,   19,  102,
 /*   910 */    52,   54,   46,   39,   51,   18,   20,   23,  102,  102,
 /*   920 */    19,   23,   46,   23,   18,   20,    3,   19,   18,   51,
 /*   930 */    17,   19,   71,   18,   20,   17,    8,   53,   73,   72,
 /*   940 */     8,   46,   51,   27,   72,   19,   73,   77,   45,   72,
 /*   950 */    71,   49,   72,   72,   72,   28,   39,   50,   28,   28,
 /*   960 */    27,   36,   41,   34,   53,   46,   32,   27,   32,   34,
 /*   970 */    33,   47,   34,   34,   54,  100,    4,   34,   19,   18,
 /*   980 */    34,   77,   41,   20,   19,   41,   18,   17,   46,   41,
 /*   990 */    39,   46,   38,   46,   41,   39,   47,    5,    9,    5,
 /*  1000 */     0,   11,    1,   53,  312,   53,  312,  312,  312,  312,
 /*  1010 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1020 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1030 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1040 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1050 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1060 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1070 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1080 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1090 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1100 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1110 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1120 */   312,  312,  312,  312,  312,  312,  312,  312,  312,  312,
 /*  1130 */   312,  312,  312,  312,  312,  312,  312,
};
#define MQLYY_SHIFT_COUNT    (436)
#define MQLYY_SHIFT_MIN      (0)
#define MQLYY_SHIFT_MAX      (1001)
static const unsigned short int mqlyy_shift_ofst[] = {
 /*     0 */    48,   49,  164,  195,  277,  228,  277,  310,  310,  310,
 /*    10 */   310,  268,  270,  270,  310,   89,  310,  310,  114,  114,
 /*    20 */   114,  175,  162,  162,  301,  321,  339,  327,  327,  369,
 /*    30 */   332,  332,  377,  332,  323,  323,  323,  323,  114,  183,
 /*    40 */   114,  183,  114,  115,   38,  134,   68,  300,  274,  436,
 /*    50 */   348,  356,  348,  439,  401,  216,  472,  377,   55,  451,
 /*    60 */   114,  444,  309,  520,  114,  444,  522,  451,  368,  368,
 /*    70 */   114,   38,  114,  114,  183,  293,  334,  256,  256,  446,
 /*    80 */   535,  134,  563,   74,  136,   10,  222,  215,  274,   11,
 /*    90 */   382,  384,  384,  380,  382,  421,  401,  473,  401,  114,
 /*   100 */   546,  533,  452,  533,  495,  556,  499,  219,  114,  114,
 /*   110 */   114,  114,  114,  531,  219,  114,  574,  574,  574,   38,
 /*   120 */   573,  573,  573,  573,  573,  553,  565,  574,  601,  604,
 /*   130 */   683,  293,  293,  293,  631,  592,  593,  593,  593,  650,
 /*   140 */   650,  650,  650,  631,  702,  592,  593,  293,  661,  661,
 /*   150 */   601,  604,  683,  638,  718,  293,  718,  293,  696,  256,
 /*   160 */   704,  256,  293,  293,  293,  726,  293,  726,  657,  736,
 /*   170 */   293,  723,  723,  712,  729,  293,  729,  746,  535,  746,
 /*   180 */   134,  535,  746,  134,  718,  736,  293,  741,  756,  718,
 /*   190 */   736,  293,  747,  754,  756,  754,  762,  712,  446,  293,
 /*   200 */   721,  767,  746,  718,  712,  736,  758,  762,  256,  293,
 /*   210 */   758,  762,  737,  725,  737,  725,  563,  724,  739,  293,
 /*   220 */   784,  750,  747,  785,  754,  428,  501,  529,  536,  541,
 /*   230 */   589,  532,  575,  542,  543,  591,  544,  547,  550,  555,
 /*   240 */   557,  552,  568,  558,  559,  590,  598,  600,  611,  577,
 /*   250 */   582,  569,  780,  790,  752,  775,  788,  796,  742,  755,
 /*   260 */   809,  740,  743,  810,  812,  813,  728,  793,  815,  764,
 /*   270 */   782,  783,  768,  786,  804,  806,  824,  748,  826,  789,
 /*   280 */   795,  749,  828,  830,  833,  801,  843,  834,  803,  787,
 /*   290 */   835,  839,  770,  842,  840,  791,  832,  831,  799,  805,
 /*   300 */   818,  850,  852,  864,  854,  856,  792,  827,  821,  823,
 /*   310 */   829,  860,  862,  802,  849,  853,  836,  837,  841,  838,
 /*   320 */   844,  845,  846,  847,  848,  811,  855,  851,  857,  858,
 /*   330 */   761,  763,  859,  859,  797,  868,  871,  869,  814,  861,
 /*   340 */   885,  887,  899,  863,  889,  807,  816,  865,  867,  866,
 /*   350 */   874,  897,  896,  817,  894,  898,  900,  876,  901,  906,
 /*   360 */   905,  923,  908,  910,  878,  913,  912,  915,  914,  918,
 /*   370 */   928,  884,  870,  872,  916,  873,  877,  932,  895,  879,
 /*   380 */   880,  881,  882,  903,  917,  875,  926,  891,  907,  902,
 /*   390 */   927,  930,  931,  933,  929,  934,  935,  925,  937,  936,
 /*   400 */   938,  921,  919,  940,  939,  941,  942,  943,  944,  945,
 /*   410 */   946,  948,  920,  911,  947,  924,  949,  951,  953,  972,
 /*   420 */   950,  904,  952,  956,  954,  959,  961,  963,  965,  968,
 /*   430 */   970,  992,  989,  994,  990, 1000, 1001,
};
#define MQLYY_REDUCE_COUNT (224)
#define MQLYY_REDUCE_MIN   (-216)
#define MQLYY_REDUCE_MAX   (621)
static const short mqlyy_reduce_ofst[] = {
 /*     0 */  -131, -143, -143, -216, -181,  -81,  -75,  -18,  -13,   -8,
 /*    10 */    14,   40,   71,   87,  -78,  163,  124,  128,  100,  135,
 /*    20 */  -139, -165, -122,   90,  -72,  199,  152,  156,  159, -104,
 /*    30 */  -117,  217,  109,  218,  165,  169,  179,  187,  192,  243,
 /*    40 */   193,  250,  130,  244,  207,  236,  -50,   44,  -10,  205,
 /*    50 */   210,  -82,  212,  284,  260,  288,  249,  299,  311,  295,
 /*    60 */   257,  307,  235,  238, -146,  205,  312,  316,  324,  325,
 /*    70 */   343,  282,  249,  351,  -44,  337,  251,  319,  341,  276,
 /*    80 */   331,  340,  318,  355,  389,  391,  423,  371,  395,  432,
 /*    90 */   360,  342,  344,  345,  362,  441,  425,  456,  430,  462,
 /*   100 */   359,  372,  370,  374,  406,  408,  448,  457,  471,  474,
 /*   110 */   475,  476,  477,  454,  460,  478,  496,  497,  498,  418,
 /*   120 */   479,  480,  481,  482,  483,  488,  500,  506,  455,  458,
 /*   130 */   461,  503,  504,  505,  386,  415,  416,  417,  419,  397,
 /*   140 */   398,  399,  400,  403,  426,  429,  431,  523,  486,  490,
 /*   150 */   484,  487,  489,  491,  507,  534,  509,  537,  492,  516,
 /*   160 */   494,  521,  540,  545,  548,  502,  549,  508,  510,  527,
 /*   170 */   554,  493,  511,  539,  485,  560,  513,  528,  538,  551,
 /*   180 */   530,  561,  562,  566,  570,  564,  567,  572,  576,  571,
 /*   190 */   578,  579,  580,  584,  585,  586,  512,  583,  515,  587,
 /*   200 */   581,  588,  594,  595,  596,  599,  517,  519,  597,  603,
 /*   210 */   602,  605,  607,  606,  609,  612,  608,  619,  621,  610,
 /*   220 */   613,  616,  614,  617,  620,
};
static const MQLYYACTIONTYPE mqlyy_default[] = {
 /*     0 */  1168, 1168, 1168, 1168, 1168, 1475, 1168, 1503, 1503, 1503,
 /*    10 */  1168, 1168, 1168, 1168, 1168, 1253, 1168, 1168, 1421, 1421,
 /*    20 */  1256, 1369, 1168, 1168, 1168, 1253, 1168, 1168, 1168, 1168,
 /*    30 */  1168, 1168, 1292, 1168, 1369, 1369, 1369, 1369, 1168, 1168,
 /*    40 */  1168, 1168, 1168, 1292, 1168, 1325, 1253, 1253, 1168, 1168,
 /*    50 */  1497, 1168, 1497, 1168, 1168, 1168, 1168, 1292, 1292, 1168,
 /*    60 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*    70 */  1168, 1168, 1420, 1255, 1168, 1168, 1168, 1549, 1168, 1168,
 /*    80 */  1328, 1325, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*    90 */  1487, 1552, 1552, 1563, 1487, 1297, 1168, 1168, 1168, 1168,
 /*   100 */  1168, 1491, 1168, 1491, 1409, 1404, 1168, 1168, 1168, 1168,
 /*   110 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   120 */  1275, 1275, 1275, 1275, 1275, 1248, 1168, 1168, 1168, 1365,
 /*   130 */  1361, 1168, 1168, 1168, 1558, 1482, 1484, 1484, 1484, 1168,
 /*   140 */  1168, 1168, 1168, 1558, 1168, 1482, 1484, 1168, 1168, 1168,
 /*   150 */  1168, 1365, 1361, 1352, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   160 */  1350, 1168, 1168, 1168, 1168, 1398, 1168, 1398, 1352, 1168,
 /*   170 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   180 */  1325, 1168, 1168, 1325, 1168, 1168, 1168, 1233, 1230, 1168,
 /*   190 */  1168, 1168, 1168, 1226, 1230, 1226, 1416, 1168, 1445, 1168,
 /*   200 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1416, 1168, 1168,
 /*   210 */  1168, 1416, 1279, 1280, 1279, 1280, 1168, 1285, 1283, 1168,
 /*   220 */  1244, 1277, 1168, 1228, 1226, 1168, 1168, 1168, 1168, 1168,
 /*   230 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   240 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   250 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1368,
 /*   260 */  1367, 1168, 1168, 1168, 1168, 1168, 1478, 1168, 1168, 1557,
 /*   270 */  1168, 1168, 1168, 1168, 1168, 1492, 1168, 1473, 1168, 1168,
 /*   280 */  1168, 1168, 1168, 1168, 1168, 1168, 1399, 1168, 1168, 1168,
 /*   290 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1349, 1168, 1168,
 /*   300 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   310 */  1463, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   320 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1523, 1168, 1537,
 /*   330 */  1168, 1536, 1505, 1506, 1504, 1168, 1168, 1168, 1168, 1304,
 /*   340 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   350 */  1168, 1168, 1168, 1252, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   360 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   370 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1439,
 /*   380 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1252, 1168, 1168,
 /*   390 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   400 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   410 */  1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   420 */  1360, 1358, 1168, 1168, 1168, 1168, 1168, 1168, 1168, 1168,
 /*   430 */  1168, 1168, 1168, 1168, 1168, 1168, 1168,
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
#ifdef MQLYYFALLBACK
static const MQLYYCODETYPE mqlyyFallback[] = {
};
#endif /* MQLYYFALLBACK */

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
struct mqlyyStackEntry {
  MQLYYACTIONTYPE stateno;  /* The state-number, or reduce action in SHIFTREDUCE */
  MQLYYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  MQLYYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct mqlyyStackEntry mqlyyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct mqlyyParser {
  mqlyyStackEntry *mqlyytos;          /* Pointer to top element of the stack */
#ifdef MQLYYTRACKMAXSTACKDEPTH
  int mqlyyhwm;                    /* High-water mark of the stack */
#endif
#ifndef MQLYYNOERRORRECOVERY
  int mqlyyerrcnt;                 /* Shifts left before out of the error */
#endif
  MQLParserARG_SDECL                /* A place to hold %extra_argument */
  MQLParserCTX_SDECL                /* A place to hold %extra_context */
#if MQLYYSTACKDEPTH<=0
  int mqlyystksz;                  /* Current side of the stack */
  mqlyyStackEntry *mqlyystack;        /* The parser's stack */
  mqlyyStackEntry mqlyystk0;          /* First stack entry */
#else
  mqlyyStackEntry mqlyystack[MQLYYSTACKDEPTH];  /* The parser's stack */
  mqlyyStackEntry *mqlyystackEnd;            /* Last entry in the stack */
#endif
};
typedef struct mqlyyParser mqlyyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *mqlyyTraceFILE = 0;
static char *mqlyyTracePrompt = 0;
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
void MQLParserTrace(FILE *TraceFILE, char *zTracePrompt){
  mqlyyTraceFILE = TraceFILE;
  mqlyyTracePrompt = zTracePrompt;
  if( mqlyyTraceFILE==0 ) mqlyyTracePrompt = 0;
  else if( mqlyyTracePrompt==0 ) mqlyyTraceFILE = 0;
}
#endif /* NDEBUG */

#if defined(MQLYYCOVERAGE) || !defined(NDEBUG)
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const mqlyyTokenName[] = { 
  /*    0 */ "$",
  /*    1 */ "KEY_GO",
  /*    2 */ "KEY_CREATE",
  /*    3 */ "KEY_DATABASE",
  /*    4 */ "IDENTIFIER",
  /*    5 */ "STRING",
  /*    6 */ "KEY_INITIALIZE",
  /*    7 */ "KEY_USE",
  /*    8 */ "KEY_WITH",
  /*    9 */ "KEY_KEY",
  /*   10 */ "KEY_USING",
  /*   11 */ "KEY_ENCODING",
  /*   12 */ "KEY_DROP",
  /*   13 */ "KEY_VACUUM",
  /*   14 */ "KEY_ANALYZE",
  /*   15 */ "KEY_INDEXES",
  /*   16 */ "KEY_ON",
  /*   17 */ "KEY_OBJECT",
  /*   18 */ "KEY_OPEN_SQUARE_BRACKET",
  /*   19 */ "KEY_CLOSE_SQUARE_BRACKET",
  /*   20 */ "KEY_TYPE",
  /*   21 */ "KEY_TYPES",
  /*   22 */ "KEY_BEGIN",
  /*   23 */ "KEY_TRANSACTION",
  /*   24 */ "KEY_COMMIT",
  /*   25 */ "KEY_ABORT",
  /*   26 */ "KEY_MULTIPLE",
  /*   27 */ "KEY_RANGE",
  /*   28 */ "KEY_OBJECTS",
  /*   29 */ "KEY_SINGLE",
  /*   30 */ "KEY_MONAD",
  /*   31 */ "KEY_HAVING",
  /*   32 */ "KEY_UNIQUE",
  /*   33 */ "KEY_FIRST",
  /*   34 */ "KEY_MONADS",
  /*   35 */ "KEY_AND",
  /*   36 */ "KEY_LAST",
  /*   37 */ "KEY_WITHOUT",
  /*   38 */ "KEY_COLON",
  /*   39 */ "KEY_SEMICOLON",
  /*   40 */ "KEY_LIST",
  /*   41 */ "KEY_OF",
  /*   42 */ "KEY_INTEGER",
  /*   43 */ "KEY_STRING",
  /*   44 */ "KEY_ASCII",
  /*   45 */ "KEY_ID_D",
  /*   46 */ "KEY_SET",
  /*   47 */ "KEY_INDEX",
  /*   48 */ "KEY_IF",
  /*   49 */ "KEY_NOT",
  /*   50 */ "KEY_EXISTS",
  /*   51 */ "KEY_FROM",
  /*   52 */ "KEY_OPEN_BRACKET",
  /*   53 */ "INTEGER",
  /*   54 */ "KEY_CLOSE_BRACKET",
  /*   55 */ "KEY_DEFAULT",
  /*   56 */ "KEY_COMPUTED",
  /*   57 */ "KEY_UPDATE",
  /*   58 */ "KEY_REMOVE",
  /*   59 */ "KEY_ADD",
  /*   60 */ "KEY_INSERT",
  /*   61 */ "KEY_DELETE",
  /*   62 */ "KEY_GET",
  /*   63 */ "KEY_CALCULATION",
  /*   64 */ "KEY_UNION",
  /*   65 */ "KEY_DIFFERENCE",
  /*   66 */ "KEY_INTERSECT",
  /*   67 */ "KEY_SELECT",
  /*   68 */ "KEY_SETS",
  /*   69 */ "KEY_ALL",
  /*   70 */ "KEY_REPLACE",
  /*   71 */ "KEY_COMMA",
  /*   72 */ "KEY_EQUALS",
  /*   73 */ "KEY_OPEN_BRACE",
  /*   74 */ "KEY_CLOSE_BRACE",
  /*   75 */ "KEY_ENUMERATION",
  /*   76 */ "KEY_ENUM",
  /*   77 */ "KEY_DASH",
  /*   78 */ "KEY_NIL",
  /*   79 */ "KEY_SEGMENT",
  /*   80 */ "KEY_IN",
  /*   81 */ "KEY_FOCUS",
  /*   82 */ "KEY_MAX",
  /*   83 */ "KEY_MAX_M",
  /*   84 */ "KEY_FEATURE",
  /*   85 */ "KEY_RETURNING",
  /*   86 */ "KEY_FULL",
  /*   87 */ "KEY_SHEAF",
  /*   88 */ "KEY_FLAT",
  /*   89 */ "KEY_WHERE",
  /*   90 */ "KEY_AT",
  /*   91 */ "KEY_AGGREGATE",
  /*   92 */ "KEY_FEATURES",
  /*   93 */ "KEY_MIN",
  /*   94 */ "KEY_SUM",
  /*   95 */ "KEY_COUNT",
  /*   96 */ "KEY_STAR",
  /*   97 */ "KEY_ENUMERATIONS",
  /*   98 */ "KEY_CONSTANTS",
  /*   99 */ "KEY_MIN_M",
  /*  100 */ "KEY_ASSIGN",
  /*  101 */ "KEY_ID_DS",
  /*  102 */ "KEY_BY",
  /*  103 */ "KEY_QUIT",
  /*  104 */ "KEY_EXCLAMATION",
  /*  105 */ "KEY_OR",
  /*  106 */ "KEY_NOTEXIST",
  /*  107 */ "KEY_NOTEXISTS",
  /*  108 */ "KEY_AS",
  /*  109 */ "MARK",
  /*  110 */ "KEY_NORETRIEVE",
  /*  111 */ "KEY_RETRIEVE",
  /*  112 */ "KEY_PART_OF",
  /*  113 */ "KEY_STARTS_IN",
  /*  114 */ "KEY_OVERLAP",
  /*  115 */ "KEY_UNIVERSE",
  /*  116 */ "KEY_SUBSTRATE",
  /*  117 */ "KEY_LESS_THAN",
  /*  118 */ "KEY_GREATER_THAN",
  /*  119 */ "KEY_NOT_EQUAL",
  /*  120 */ "KEY_LESS_THAN_OR_EQUAL",
  /*  121 */ "KEY_GREATER_THAN_OR_EQUAL",
  /*  122 */ "KEY_TILDE",
  /*  123 */ "KEY_NOT_TILDE",
  /*  124 */ "KEY_HAS",
  /*  125 */ "KEY_DOT",
  /*  126 */ "KEY_UNORDERED_GROUP",
  /*  127 */ "KEY_OPT_GAP",
  /*  128 */ "KEY_GAP",
  /*  129 */ "KEY_POWER",
  /*  130 */ "KEY_BETWEEN",
  /*  131 */ "statement",
  /*  132 */ "statement_by_itself",
  /*  133 */ "create_database_statement",
  /*  134 */ "initialize_database_statement",
  /*  135 */ "use_statement",
  /*  136 */ "drop_database_statement",
  /*  137 */ "vacuum_database_statement",
  /*  138 */ "create_object_type_statement",
  /*  139 */ "update_object_type_statement",
  /*  140 */ "drop_object_type_statement",
  /*  141 */ "insert_monads_statement",
  /*  142 */ "delete_monads_statement",
  /*  143 */ "get_monads_statement",
  /*  144 */ "monad_set_calculation_statement",
  /*  145 */ "create_enumeration_statement",
  /*  146 */ "update_enumeration_statement",
  /*  147 */ "drop_enumeration_statement",
  /*  148 */ "create_segment_statement",
  /*  149 */ "select_statement",
  /*  150 */ "select_objects_at_statement",
  /*  151 */ "select_objects_having_monads_in_statement",
  /*  152 */ "get_aggregate_features_statement",
  /*  153 */ "get_objects_having_monads_in_statement",
  /*  154 */ "get_set_from_feature_statement",
  /*  155 */ "select_object_types_statement",
  /*  156 */ "select_features_statement",
  /*  157 */ "select_enumerations_statement",
  /*  158 */ "select_enumeration_constants_statement",
  /*  159 */ "select_object_types_which_use_enum_statement",
  /*  160 */ "select_min_m_statement",
  /*  161 */ "select_max_m_statement",
  /*  162 */ "create_object_from_monads_statement",
  /*  163 */ "create_object_from_id_ds_statement",
  /*  164 */ "update_objects_by_monads_statement",
  /*  165 */ "update_objects_by_id_ds_statement",
  /*  166 */ "delete_objects_by_monads_statement",
  /*  167 */ "delete_objects_by_id_ds_statement",
  /*  168 */ "get_features_statement",
  /*  169 */ "quit_statement",
  /*  170 */ "create_indexes_statement",
  /*  171 */ "drop_indexes_statement",
  /*  172 */ "begin_transaction_statement",
  /*  173 */ "commit_transaction_statement",
  /*  174 */ "abort_transaction_statement",
  /*  175 */ "select_monad_sets_statement",
  /*  176 */ "get_monad_sets_statement",
  /*  177 */ "create_monad_set_statement",
  /*  178 */ "update_monad_set_statement",
  /*  179 */ "drop_monad_set_statement",
  /*  180 */ "create_objects_statement",
  /*  181 */ "database_name",
  /*  182 */ "opt_WITH_KEY",
  /*  183 */ "opt_USING_ENCODING",
  /*  184 */ "opt_DATABASE",
  /*  185 */ "opt_WITH_ENCODING",
  /*  186 */ "opt_ANALYZE",
  /*  187 */ "on_object_type",
  /*  188 */ "choice_type_types",
  /*  189 */ "choice_object_type_or_all",
  /*  190 */ "opt_OBJECT",
  /*  191 */ "opt_if_not_exists",
  /*  192 */ "opt_range_type",
  /*  193 */ "opt_monad_uniqueness_type",
  /*  194 */ "object_type_name",
  /*  195 */ "opt_feature_declaration_list",
  /*  196 */ "feature_declaration_list",
  /*  197 */ "feature_declaration",
  /*  198 */ "feature_name",
  /*  199 */ "feature_type",
  /*  200 */ "default_specification",
  /*  201 */ "opt_computed",
  /*  202 */ "list_feature_type",
  /*  203 */ "opt_with_index",
  /*  204 */ "opt_string_length",
  /*  205 */ "opt_from_set",
  /*  206 */ "expression",
  /*  207 */ "feature_update_list",
  /*  208 */ "feature_update",
  /*  209 */ "opt_ADD",
  /*  210 */ "monad_specification",
  /*  211 */ "choice_number_OBJECTS",
  /*  212 */ "id_ds_specification",
  /*  213 */ "monad_set_chain",
  /*  214 */ "monad_set",
  /*  215 */ "monad_set_operator",
  /*  216 */ "choice_number_SET",
  /*  217 */ "monad_set_name_list",
  /*  218 */ "monad_set_name",
  /*  219 */ "choice_ENUM_ERATION",
  /*  220 */ "enumeration_name",
  /*  221 */ "ec_declaration_list",
  /*  222 */ "ec_declaration",
  /*  223 */ "opt_DEFAULT",
  /*  224 */ "ec_name",
  /*  225 */ "opt_ec_initialization",
  /*  226 */ "ec_initialization",
  /*  227 */ "ec_update_list",
  /*  228 */ "ec_update",
  /*  229 */ "signed_integer",
  /*  230 */ "unsigned_integer",
  /*  231 */ "segment_name",
  /*  232 */ "segment_range",
  /*  233 */ "select_clause",
  /*  234 */ "in_clause",
  /*  235 */ "with_max_range_clause",
  /*  236 */ "returning_clause",
  /*  237 */ "where_clause",
  /*  238 */ "focus_specification",
  /*  239 */ "opt_OBJECTS",
  /*  240 */ "in_specification",
  /*  241 */ "monad_set_element_list",
  /*  242 */ "monad_set_element",
  /*  243 */ "object_type_name_list",
  /*  244 */ "using_range_clause",
  /*  245 */ "mql_query",
  /*  246 */ "single_monad_specification",
  /*  247 */ "object_type_to_find",
  /*  248 */ "aggregate_feature_list",
  /*  249 */ "using_monad_feature",
  /*  250 */ "feature_constraints",
  /*  251 */ "aggregate_feature",
  /*  252 */ "aggregate_feature_comparison",
  /*  253 */ "comparison_operator",
  /*  254 */ "value",
  /*  255 */ "list_of_identifier",
  /*  256 */ "list_of_integer",
  /*  257 */ "feature_list",
  /*  258 */ "opt_OBJECTYPE",
  /*  259 */ "opt_ENUM_ERATION",
  /*  260 */ "with_id_d_specification",
  /*  261 */ "object_creation_specification",
  /*  262 */ "id_d_const",
  /*  263 */ "opt_list_of_feature_assignments",
  /*  264 */ "list_of_feature_assignments",
  /*  265 */ "feature_assignment",
  /*  266 */ "choice_number_ID_DS",
  /*  267 */ "id_d_list",
  /*  268 */ "id_d",
  /*  269 */ "object_creation_list",
  /*  270 */ "object_creation_no_object_type",
  /*  271 */ "object_update_specification",
  /*  272 */ "object_deletion_specification",
  /*  273 */ "object_type_name_to_delete",
  /*  274 */ "choice_number_FEATURES",
  /*  275 */ "feature_list_member",
  /*  276 */ "topograph",
  /*  277 */ "blocks",
  /*  278 */ "block_string",
  /*  279 */ "unordered_group",
  /*  280 */ "block_string0",
  /*  281 */ "block",
  /*  282 */ "block_string1",
  /*  283 */ "star_monad_set",
  /*  284 */ "block_string2",
  /*  285 */ "notexist",
  /*  286 */ "object_reference_declaration",
  /*  287 */ "object_reference",
  /*  288 */ "mark_declaration",
  /*  289 */ "retrieval",
  /*  290 */ "firstlast",
  /*  291 */ "monad_set_relation_clause",
  /*  292 */ "monad_set_relation_operation",
  /*  293 */ "universe_or_substrate",
  /*  294 */ "ffeatures",
  /*  295 */ "fterm",
  /*  296 */ "ffactor",
  /*  297 */ "feature_comparison",
  /*  298 */ "computed_feature_name",
  /*  299 */ "object_reference_usage",
  /*  300 */ "enum_const",
  /*  301 */ "opt_blocks",
  /*  302 */ "object_block",
  /*  303 */ "power",
  /*  304 */ "opt_gap_block",
  /*  305 */ "gap_block",
  /*  306 */ "notexist_object_block",
  /*  307 */ "object_block_string",
  /*  308 */ "gap_retrieval",
  /*  309 */ "feature_retrieval",
  /*  310 */ "restrictor",
  /*  311 */ "limit",
};
#endif /* defined(MQLYYCOVERAGE) || !defined(NDEBUG) */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const mqlyyRuleName[] = {
 /*   0 */ "statement ::= statement_by_itself KEY_GO",
 /*   1 */ "statement_by_itself ::= create_database_statement",
 /*   2 */ "statement_by_itself ::= initialize_database_statement",
 /*   3 */ "statement_by_itself ::= use_statement",
 /*   4 */ "statement_by_itself ::= drop_database_statement",
 /*   5 */ "statement_by_itself ::= vacuum_database_statement",
 /*   6 */ "statement_by_itself ::= create_object_type_statement",
 /*   7 */ "statement_by_itself ::= update_object_type_statement",
 /*   8 */ "statement_by_itself ::= drop_object_type_statement",
 /*   9 */ "statement_by_itself ::= insert_monads_statement",
 /*  10 */ "statement_by_itself ::= delete_monads_statement",
 /*  11 */ "statement_by_itself ::= get_monads_statement",
 /*  12 */ "statement_by_itself ::= monad_set_calculation_statement",
 /*  13 */ "statement_by_itself ::= create_enumeration_statement",
 /*  14 */ "statement_by_itself ::= update_enumeration_statement",
 /*  15 */ "statement_by_itself ::= drop_enumeration_statement",
 /*  16 */ "statement_by_itself ::= create_segment_statement",
 /*  17 */ "statement_by_itself ::= select_statement",
 /*  18 */ "statement_by_itself ::= select_objects_at_statement",
 /*  19 */ "statement_by_itself ::= select_objects_having_monads_in_statement",
 /*  20 */ "statement_by_itself ::= get_aggregate_features_statement",
 /*  21 */ "statement_by_itself ::= get_objects_having_monads_in_statement",
 /*  22 */ "statement_by_itself ::= get_set_from_feature_statement",
 /*  23 */ "statement_by_itself ::= select_object_types_statement",
 /*  24 */ "statement_by_itself ::= select_features_statement",
 /*  25 */ "statement_by_itself ::= select_enumerations_statement",
 /*  26 */ "statement_by_itself ::= select_enumeration_constants_statement",
 /*  27 */ "statement_by_itself ::= select_object_types_which_use_enum_statement",
 /*  28 */ "statement_by_itself ::= select_min_m_statement",
 /*  29 */ "statement_by_itself ::= select_max_m_statement",
 /*  30 */ "statement_by_itself ::= create_object_from_monads_statement",
 /*  31 */ "statement_by_itself ::= create_object_from_id_ds_statement",
 /*  32 */ "statement_by_itself ::= update_objects_by_monads_statement",
 /*  33 */ "statement_by_itself ::= update_objects_by_id_ds_statement",
 /*  34 */ "statement_by_itself ::= delete_objects_by_monads_statement",
 /*  35 */ "statement_by_itself ::= delete_objects_by_id_ds_statement",
 /*  36 */ "statement_by_itself ::= get_features_statement",
 /*  37 */ "statement_by_itself ::= quit_statement",
 /*  38 */ "statement_by_itself ::= create_indexes_statement",
 /*  39 */ "statement_by_itself ::= drop_indexes_statement",
 /*  40 */ "statement_by_itself ::= begin_transaction_statement",
 /*  41 */ "statement_by_itself ::= commit_transaction_statement",
 /*  42 */ "statement_by_itself ::= abort_transaction_statement",
 /*  43 */ "statement_by_itself ::= select_monad_sets_statement",
 /*  44 */ "statement_by_itself ::= get_monad_sets_statement",
 /*  45 */ "statement_by_itself ::= create_monad_set_statement",
 /*  46 */ "statement_by_itself ::= update_monad_set_statement",
 /*  47 */ "statement_by_itself ::= drop_monad_set_statement",
 /*  48 */ "statement_by_itself ::= create_objects_statement",
 /*  49 */ "create_database_statement ::= KEY_CREATE KEY_DATABASE database_name opt_WITH_KEY opt_USING_ENCODING",
 /*  50 */ "database_name ::= IDENTIFIER",
 /*  51 */ "database_name ::= STRING",
 /*  52 */ "initialize_database_statement ::= KEY_INITIALIZE KEY_DATABASE database_name opt_WITH_KEY",
 /*  53 */ "use_statement ::= KEY_USE opt_DATABASE database_name opt_WITH_KEY",
 /*  54 */ "opt_WITH_KEY ::= KEY_WITH KEY_KEY STRING",
 /*  55 */ "opt_WITH_KEY ::=",
 /*  56 */ "opt_USING_ENCODING ::= KEY_USING KEY_ENCODING STRING",
 /*  57 */ "opt_USING_ENCODING ::=",
 /*  58 */ "opt_DATABASE ::= KEY_DATABASE",
 /*  59 */ "opt_DATABASE ::=",
 /*  60 */ "drop_database_statement ::= KEY_DROP KEY_DATABASE database_name",
 /*  61 */ "vacuum_database_statement ::= KEY_VACUUM opt_DATABASE opt_ANALYZE",
 /*  62 */ "opt_ANALYZE ::=",
 /*  63 */ "opt_ANALYZE ::= KEY_ANALYZE",
 /*  64 */ "create_indexes_statement ::= KEY_CREATE KEY_INDEXES on_object_type",
 /*  65 */ "drop_indexes_statement ::= KEY_DROP KEY_INDEXES on_object_type",
 /*  66 */ "on_object_type ::= KEY_ON KEY_OBJECT choice_type_types KEY_OPEN_SQUARE_BRACKET choice_object_type_or_all KEY_CLOSE_SQUARE_BRACKET",
 /*  67 */ "choice_type_types ::= KEY_TYPE",
 /*  68 */ "choice_type_types ::= KEY_TYPES",
 /*  69 */ "begin_transaction_statement ::= KEY_BEGIN KEY_TRANSACTION",
 /*  70 */ "commit_transaction_statement ::= KEY_COMMIT KEY_TRANSACTION",
 /*  71 */ "abort_transaction_statement ::= KEY_ABORT KEY_TRANSACTION",
 /*  72 */ "create_object_type_statement ::= KEY_CREATE opt_OBJECT KEY_TYPE opt_if_not_exists opt_range_type opt_monad_uniqueness_type KEY_OPEN_SQUARE_BRACKET object_type_name opt_feature_declaration_list KEY_CLOSE_SQUARE_BRACKET",
 /*  73 */ "opt_range_type ::=",
 /*  74 */ "opt_range_type ::= KEY_WITH KEY_MULTIPLE KEY_RANGE KEY_OBJECTS",
 /*  75 */ "opt_range_type ::= KEY_WITH KEY_SINGLE KEY_RANGE KEY_OBJECTS",
 /*  76 */ "opt_range_type ::= KEY_WITH KEY_SINGLE KEY_MONAD KEY_OBJECTS",
 /*  77 */ "opt_monad_uniqueness_type ::=",
 /*  78 */ "opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_MONADS",
 /*  79 */ "opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_AND KEY_LAST KEY_MONADS",
 /*  80 */ "opt_monad_uniqueness_type ::= KEY_WITHOUT KEY_UNIQUE KEY_MONADS",
 /*  81 */ "opt_OBJECT ::= KEY_OBJECT",
 /*  82 */ "opt_OBJECT ::=",
 /*  83 */ "object_type_name ::= IDENTIFIER",
 /*  84 */ "opt_feature_declaration_list ::= feature_declaration_list",
 /*  85 */ "opt_feature_declaration_list ::=",
 /*  86 */ "feature_declaration_list ::= feature_declaration",
 /*  87 */ "feature_declaration_list ::= feature_declaration_list feature_declaration",
 /*  88 */ "feature_declaration ::= feature_name KEY_COLON feature_type default_specification opt_computed KEY_SEMICOLON",
 /*  89 */ "feature_declaration ::= feature_name KEY_COLON KEY_LIST KEY_OF list_feature_type KEY_SEMICOLON",
 /*  90 */ "feature_type ::= KEY_INTEGER opt_with_index",
 /*  91 */ "feature_type ::= KEY_STRING opt_string_length opt_from_set opt_with_index",
 /*  92 */ "feature_type ::= KEY_ASCII opt_string_length opt_from_set opt_with_index",
 /*  93 */ "feature_type ::= KEY_ID_D opt_with_index",
 /*  94 */ "feature_type ::= IDENTIFIER opt_with_index",
 /*  95 */ "feature_type ::= KEY_SET KEY_OF KEY_MONADS",
 /*  96 */ "feature_type ::= KEY_SINGLE KEY_MONAD KEY_SET KEY_OF KEY_MONADS",
 /*  97 */ "feature_type ::= KEY_SINGLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS",
 /*  98 */ "feature_type ::= KEY_MULTIPLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS",
 /*  99 */ "list_feature_type ::= KEY_INTEGER",
 /* 100 */ "list_feature_type ::= KEY_ID_D",
 /* 101 */ "list_feature_type ::= IDENTIFIER",
 /* 102 */ "opt_with_index ::= KEY_WITH KEY_INDEX",
 /* 103 */ "opt_with_index ::= KEY_WITHOUT KEY_INDEX",
 /* 104 */ "opt_with_index ::=",
 /* 105 */ "opt_if_not_exists ::= KEY_IF KEY_NOT KEY_EXISTS",
 /* 106 */ "opt_if_not_exists ::=",
 /* 107 */ "opt_from_set ::= KEY_FROM KEY_SET",
 /* 108 */ "opt_from_set ::=",
 /* 109 */ "opt_string_length ::=",
 /* 110 */ "opt_string_length ::= KEY_OPEN_BRACKET INTEGER KEY_CLOSE_BRACKET",
 /* 111 */ "default_specification ::= KEY_DEFAULT expression",
 /* 112 */ "default_specification ::=",
 /* 113 */ "opt_computed ::= KEY_COMPUTED",
 /* 114 */ "opt_computed ::=",
 /* 115 */ "update_object_type_statement ::= KEY_UPDATE opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name feature_update_list KEY_CLOSE_SQUARE_BRACKET",
 /* 116 */ "feature_update_list ::= feature_update",
 /* 117 */ "feature_update_list ::= feature_update_list feature_update",
 /* 118 */ "feature_update ::= opt_ADD feature_declaration",
 /* 119 */ "feature_update ::= KEY_REMOVE feature_name KEY_SEMICOLON",
 /* 120 */ "opt_ADD ::= KEY_ADD",
 /* 121 */ "opt_ADD ::=",
 /* 122 */ "drop_object_type_statement ::= KEY_DROP opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 123 */ "insert_monads_statement ::= KEY_INSERT monad_specification",
 /* 124 */ "delete_monads_statement ::= KEY_DELETE monad_specification",
 /* 125 */ "get_monads_statement ::= KEY_GET KEY_MONADS KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 126 */ "monad_set_calculation_statement ::= KEY_MONAD KEY_SET KEY_CALCULATION monad_set_chain",
 /* 127 */ "monad_set_chain ::= monad_set",
 /* 128 */ "monad_set_chain ::= monad_set_chain monad_set_operator monad_set",
 /* 129 */ "monad_set_operator ::= KEY_UNION",
 /* 130 */ "monad_set_operator ::= KEY_DIFFERENCE",
 /* 131 */ "monad_set_operator ::= KEY_INTERSECT",
 /* 132 */ "select_monad_sets_statement ::= KEY_SELECT KEY_MONAD KEY_SETS",
 /* 133 */ "get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET monad_set_name_list",
 /* 134 */ "get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET KEY_ALL",
 /* 135 */ "choice_number_SET ::= KEY_SETS",
 /* 136 */ "choice_number_SET ::= KEY_SET",
 /* 137 */ "create_monad_set_statement ::= KEY_CREATE KEY_MONAD KEY_SET monad_set_name KEY_WITH monad_specification",
 /* 138 */ "update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set_name",
 /* 139 */ "update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set_name",
 /* 140 */ "update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set",
 /* 141 */ "update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set",
 /* 142 */ "drop_monad_set_statement ::= KEY_DROP KEY_MONAD KEY_SET monad_set_name",
 /* 143 */ "monad_set_name ::= IDENTIFIER",
 /* 144 */ "monad_set_name_list ::= monad_set_name",
 /* 145 */ "monad_set_name_list ::= monad_set_name_list KEY_COMMA monad_set_name",
 /* 146 */ "create_enumeration_statement ::= KEY_CREATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_declaration_list KEY_CLOSE_BRACE",
 /* 147 */ "choice_ENUM_ERATION ::= KEY_ENUMERATION",
 /* 148 */ "choice_ENUM_ERATION ::= KEY_ENUM",
 /* 149 */ "enumeration_name ::= IDENTIFIER",
 /* 150 */ "ec_declaration_list ::= ec_declaration",
 /* 151 */ "ec_declaration_list ::= ec_declaration_list KEY_COMMA ec_declaration",
 /* 152 */ "ec_declaration ::= opt_DEFAULT ec_name opt_ec_initialization",
 /* 153 */ "opt_DEFAULT ::= KEY_DEFAULT",
 /* 154 */ "opt_DEFAULT ::=",
 /* 155 */ "ec_name ::= IDENTIFIER",
 /* 156 */ "opt_ec_initialization ::= ec_initialization",
 /* 157 */ "opt_ec_initialization ::=",
 /* 158 */ "update_enumeration_statement ::= KEY_UPDATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_update_list KEY_CLOSE_BRACE",
 /* 159 */ "ec_update_list ::= ec_update",
 /* 160 */ "ec_update_list ::= ec_update_list KEY_COMMA ec_update",
 /* 161 */ "ec_update ::= opt_ADD opt_DEFAULT ec_name ec_initialization",
 /* 162 */ "ec_update ::= KEY_UPDATE opt_DEFAULT ec_name ec_initialization",
 /* 163 */ "ec_update ::= KEY_REMOVE ec_name",
 /* 164 */ "ec_initialization ::= KEY_EQUALS signed_integer",
 /* 165 */ "signed_integer ::= INTEGER",
 /* 166 */ "signed_integer ::= KEY_DASH INTEGER",
 /* 167 */ "signed_integer ::= KEY_NIL",
 /* 168 */ "unsigned_integer ::= INTEGER",
 /* 169 */ "drop_enumeration_statement ::= KEY_DROP choice_ENUM_ERATION enumeration_name",
 /* 170 */ "create_segment_statement ::= KEY_CREATE KEY_SEGMENT segment_name KEY_RANGE KEY_EQUALS segment_range",
 /* 171 */ "segment_name ::= IDENTIFIER",
 /* 172 */ "segment_range ::= INTEGER KEY_DASH INTEGER",
 /* 173 */ "select_statement ::= select_clause in_clause with_max_range_clause returning_clause where_clause",
 /* 174 */ "select_statement ::= select_clause KEY_IN IDENTIFIER with_max_range_clause returning_clause where_clause",
 /* 175 */ "select_clause ::= KEY_SELECT focus_specification opt_OBJECTS",
 /* 176 */ "focus_specification ::= KEY_FOCUS",
 /* 177 */ "focus_specification ::= KEY_ALL",
 /* 178 */ "opt_OBJECTS ::= KEY_OBJECTS",
 /* 179 */ "opt_OBJECTS ::=",
 /* 180 */ "in_clause ::= KEY_IN in_specification",
 /* 181 */ "in_clause ::=",
 /* 182 */ "in_specification ::= monad_set",
 /* 183 */ "in_specification ::= KEY_ALL",
 /* 184 */ "monad_set ::= KEY_OPEN_BRACE monad_set_element_list KEY_CLOSE_BRACE",
 /* 185 */ "monad_set_element_list ::= monad_set_element",
 /* 186 */ "monad_set_element_list ::= monad_set_element_list KEY_COMMA monad_set_element",
 /* 187 */ "monad_set_element ::= INTEGER",
 /* 188 */ "monad_set_element ::= INTEGER KEY_DASH INTEGER",
 /* 189 */ "monad_set_element ::= INTEGER KEY_DASH",
 /* 190 */ "with_max_range_clause ::=",
 /* 191 */ "with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_MAX_M KEY_MONADS",
 /* 192 */ "with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE INTEGER KEY_MONADS",
 /* 193 */ "with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_FEATURE feature_name KEY_FROM KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 194 */ "returning_clause ::=",
 /* 195 */ "returning_clause ::= KEY_RETURNING KEY_FULL KEY_SHEAF",
 /* 196 */ "returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF",
 /* 197 */ "returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF KEY_ON object_type_name_list",
 /* 198 */ "using_range_clause ::=",
 /* 199 */ "using_range_clause ::= KEY_RANGE KEY_ALL",
 /* 200 */ "using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_COMMA unsigned_integer KEY_CLOSE_BRACKET",
 /* 201 */ "using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_CLOSE_BRACKET",
 /* 202 */ "object_type_name_list ::= object_type_name",
 /* 203 */ "object_type_name_list ::= object_type_name_list KEY_COMMA object_type_name",
 /* 204 */ "where_clause ::= KEY_WHERE mql_query",
 /* 205 */ "select_objects_at_statement ::= KEY_SELECT opt_OBJECTS KEY_AT single_monad_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 206 */ "single_monad_specification ::= KEY_MONAD KEY_EQUALS INTEGER",
 /* 207 */ "select_objects_having_monads_in_statement ::= KEY_SELECT KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN monad_set KEY_OPEN_SQUARE_BRACKET object_type_to_find KEY_CLOSE_SQUARE_BRACKET",
 /* 208 */ "object_type_to_find ::= choice_object_type_or_all",
 /* 209 */ "choice_object_type_or_all ::= object_type_name",
 /* 210 */ "choice_object_type_or_all ::= KEY_ALL",
 /* 211 */ "get_aggregate_features_statement ::= KEY_GET KEY_AGGREGATE KEY_FEATURES aggregate_feature_list KEY_FROM KEY_OBJECTS in_clause using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name feature_constraints KEY_CLOSE_SQUARE_BRACKET",
 /* 212 */ "aggregate_feature_list ::= aggregate_feature",
 /* 213 */ "aggregate_feature_list ::= aggregate_feature_list KEY_COMMA aggregate_feature",
 /* 214 */ "aggregate_feature ::= KEY_MIN KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET",
 /* 215 */ "aggregate_feature ::= KEY_MAX KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET",
 /* 216 */ "aggregate_feature ::= KEY_SUM KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET",
 /* 217 */ "aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET KEY_STAR KEY_CLOSE_BRACKET",
 /* 218 */ "aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET aggregate_feature_comparison KEY_CLOSE_BRACKET",
 /* 219 */ "aggregate_feature_comparison ::= feature_name comparison_operator value",
 /* 220 */ "aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET",
 /* 221 */ "aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET",
 /* 222 */ "get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 223 */ "get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET KEY_ALL KEY_CLOSE_SQUARE_BRACKET",
 /* 224 */ "get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET feature_list KEY_CLOSE_SQUARE_BRACKET",
 /* 225 */ "using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE IDENTIFIER",
 /* 226 */ "using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE KEY_MONADS",
 /* 227 */ "using_monad_feature ::=",
 /* 228 */ "select_object_types_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES",
 /* 229 */ "select_features_statement ::= KEY_SELECT KEY_FEATURES KEY_FROM opt_OBJECTYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 230 */ "get_set_from_feature_statement ::= KEY_GET KEY_SET KEY_FROM KEY_FEATURE feature_name KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 231 */ "opt_OBJECTYPE ::= KEY_OBJECT KEY_TYPE",
 /* 232 */ "opt_OBJECTYPE ::= KEY_TYPE",
 /* 233 */ "opt_OBJECTYPE ::=",
 /* 234 */ "select_enumerations_statement ::= KEY_SELECT KEY_ENUMERATIONS",
 /* 235 */ "select_enumeration_constants_statement ::= KEY_SELECT choice_ENUM_ERATION KEY_CONSTANTS KEY_FROM opt_ENUM_ERATION enumeration_name",
 /* 236 */ "opt_ENUM_ERATION ::= KEY_ENUM",
 /* 237 */ "opt_ENUM_ERATION ::= KEY_ENUMERATION",
 /* 238 */ "opt_ENUM_ERATION ::=",
 /* 239 */ "select_object_types_which_use_enum_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES KEY_USING choice_ENUM_ERATION enumeration_name",
 /* 240 */ "select_min_m_statement ::= KEY_SELECT KEY_MIN_M",
 /* 241 */ "select_max_m_statement ::= KEY_SELECT KEY_MAX_M",
 /* 242 */ "create_object_from_monads_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification object_creation_specification",
 /* 243 */ "monad_specification ::= KEY_MONADS KEY_EQUALS monad_set",
 /* 244 */ "with_id_d_specification ::= KEY_WITH KEY_ID_D KEY_EQUALS id_d_const",
 /* 245 */ "with_id_d_specification ::=",
 /* 246 */ "id_d_const ::= INTEGER",
 /* 247 */ "id_d_const ::= KEY_NIL",
 /* 248 */ "object_creation_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET",
 /* 249 */ "opt_list_of_feature_assignments ::= list_of_feature_assignments",
 /* 250 */ "opt_list_of_feature_assignments ::=",
 /* 251 */ "list_of_feature_assignments ::= feature_assignment",
 /* 252 */ "list_of_feature_assignments ::= list_of_feature_assignments feature_assignment",
 /* 253 */ "feature_assignment ::= feature_name KEY_ASSIGN expression KEY_SEMICOLON",
 /* 254 */ "feature_name ::= IDENTIFIER",
 /* 255 */ "feature_name ::= KEY_MONADS",
 /* 256 */ "expression ::= signed_integer",
 /* 257 */ "expression ::= STRING",
 /* 258 */ "expression ::= IDENTIFIER",
 /* 259 */ "expression ::= monad_set",
 /* 260 */ "expression ::= KEY_OPEN_BRACKET KEY_CLOSE_BRACKET",
 /* 261 */ "expression ::= KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET",
 /* 262 */ "expression ::= KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET",
 /* 263 */ "list_of_integer ::= signed_integer",
 /* 264 */ "list_of_integer ::= list_of_integer KEY_COMMA signed_integer",
 /* 265 */ "list_of_identifier ::= IDENTIFIER",
 /* 266 */ "list_of_identifier ::= list_of_identifier KEY_COMMA IDENTIFIER",
 /* 267 */ "create_object_from_id_ds_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM id_ds_specification with_id_d_specification object_creation_specification",
 /* 268 */ "id_ds_specification ::= choice_number_ID_DS KEY_EQUALS id_d_list",
 /* 269 */ "choice_number_ID_DS ::= KEY_ID_D",
 /* 270 */ "choice_number_ID_DS ::= KEY_ID_DS",
 /* 271 */ "id_d_list ::= id_d",
 /* 272 */ "id_d_list ::= id_d_list KEY_COMMA id_d",
 /* 273 */ "id_d ::= id_d_const",
 /* 274 */ "create_objects_statement ::= KEY_CREATE KEY_OBJECTS KEY_WITH KEY_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET object_creation_list",
 /* 275 */ "object_creation_list ::= object_creation_no_object_type",
 /* 276 */ "object_creation_list ::= object_creation_list object_creation_no_object_type",
 /* 277 */ "object_creation_no_object_type ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification KEY_OPEN_SQUARE_BRACKET opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET",
 /* 278 */ "update_objects_by_monads_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY monad_specification object_update_specification",
 /* 279 */ "choice_number_OBJECTS ::= KEY_OBJECT",
 /* 280 */ "choice_number_OBJECTS ::= KEY_OBJECTS",
 /* 281 */ "object_update_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET",
 /* 282 */ "update_objects_by_id_ds_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY id_ds_specification object_update_specification",
 /* 283 */ "delete_objects_by_monads_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY monad_specification object_deletion_specification",
 /* 284 */ "object_deletion_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name_to_delete KEY_CLOSE_SQUARE_BRACKET",
 /* 285 */ "object_type_name_to_delete ::= choice_object_type_or_all",
 /* 286 */ "delete_objects_by_id_ds_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY id_ds_specification object_deletion_specification",
 /* 287 */ "get_features_statement ::= KEY_GET choice_number_FEATURES feature_list KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET",
 /* 288 */ "choice_number_FEATURES ::= KEY_FEATURE",
 /* 289 */ "choice_number_FEATURES ::= KEY_FEATURES",
 /* 290 */ "feature_list ::= feature_list_member",
 /* 291 */ "feature_list ::= feature_list KEY_COMMA feature_list_member",
 /* 292 */ "feature_list_member ::= feature_name",
 /* 293 */ "feature_list_member ::= feature_name KEY_OPEN_BRACKET IDENTIFIER KEY_CLOSE_BRACKET",
 /* 294 */ "feature_list_member ::= feature_name KEY_OPEN_BRACKET KEY_MONADS KEY_CLOSE_BRACKET",
 /* 295 */ "quit_statement ::= KEY_QUIT",
 /* 296 */ "mql_query ::= topograph",
 /* 297 */ "topograph ::= blocks",
 /* 298 */ "blocks ::= using_range_clause block_string",
 /* 299 */ "blocks ::= using_range_clause unordered_group",
 /* 300 */ "block_string0 ::= block",
 /* 301 */ "block_string0 ::= KEY_OPEN_SQUARE_BRACKET block_string KEY_CLOSE_SQUARE_BRACKET",
 /* 302 */ "block_string1 ::= block_string0",
 /* 303 */ "block_string1 ::= block_string0 KEY_STAR star_monad_set",
 /* 304 */ "block_string2 ::= block_string1",
 /* 305 */ "block_string2 ::= block_string1 block_string2",
 /* 306 */ "block_string2 ::= block_string1 KEY_EXCLAMATION block_string2",
 /* 307 */ "block_string ::= block_string2",
 /* 308 */ "block_string ::= block_string2 KEY_OR block_string",
 /* 309 */ "notexist ::= KEY_NOTEXIST",
 /* 310 */ "notexist ::= KEY_NOTEXISTS",
 /* 311 */ "object_reference_declaration ::=",
 /* 312 */ "object_reference_declaration ::= KEY_AS object_reference",
 /* 313 */ "mark_declaration ::=",
 /* 314 */ "mark_declaration ::= MARK",
 /* 315 */ "object_reference ::= IDENTIFIER",
 /* 316 */ "retrieval ::=",
 /* 317 */ "retrieval ::= KEY_NORETRIEVE",
 /* 318 */ "retrieval ::= KEY_RETRIEVE",
 /* 319 */ "retrieval ::= KEY_FOCUS",
 /* 320 */ "firstlast ::=",
 /* 321 */ "firstlast ::= KEY_FIRST",
 /* 322 */ "firstlast ::= KEY_LAST",
 /* 323 */ "firstlast ::= KEY_FIRST KEY_AND KEY_LAST",
 /* 324 */ "monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET monad_set_name KEY_COMMA universe_or_substrate KEY_CLOSE_BRACKET",
 /* 325 */ "monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET universe_or_substrate KEY_CLOSE_BRACKET",
 /* 326 */ "monad_set_relation_clause ::=",
 /* 327 */ "monad_set_relation_operation ::= KEY_PART_OF",
 /* 328 */ "monad_set_relation_operation ::= KEY_STARTS_IN",
 /* 329 */ "monad_set_relation_operation ::= KEY_OVERLAP",
 /* 330 */ "universe_or_substrate ::= KEY_UNIVERSE",
 /* 331 */ "universe_or_substrate ::= KEY_SUBSTRATE",
 /* 332 */ "feature_constraints ::=",
 /* 333 */ "feature_constraints ::= ffeatures",
 /* 334 */ "ffeatures ::= fterm",
 /* 335 */ "ffeatures ::= ffeatures KEY_OR fterm",
 /* 336 */ "fterm ::= ffactor",
 /* 337 */ "fterm ::= fterm KEY_AND ffactor",
 /* 338 */ "ffactor ::= KEY_NOT ffactor",
 /* 339 */ "ffactor ::= KEY_OPEN_BRACKET ffeatures KEY_CLOSE_BRACKET",
 /* 340 */ "ffactor ::= feature_comparison",
 /* 341 */ "feature_comparison ::= feature_name comparison_operator value",
 /* 342 */ "feature_comparison ::= computed_feature_name comparison_operator value",
 /* 343 */ "feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET KEY_CLOSE_BRACKET",
 /* 344 */ "feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET",
 /* 345 */ "feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET",
 /* 346 */ "feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET",
 /* 347 */ "feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET",
 /* 348 */ "feature_comparison ::= computed_feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET",
 /* 349 */ "feature_comparison ::= feature_name KEY_IN object_reference_usage",
 /* 350 */ "feature_comparison ::= computed_feature_name KEY_IN object_reference_usage",
 /* 351 */ "computed_feature_name ::= feature_name KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET",
 /* 352 */ "comparison_operator ::= KEY_EQUALS",
 /* 353 */ "comparison_operator ::= KEY_LESS_THAN",
 /* 354 */ "comparison_operator ::= KEY_GREATER_THAN",
 /* 355 */ "comparison_operator ::= KEY_NOT_EQUAL",
 /* 356 */ "comparison_operator ::= KEY_LESS_THAN_OR_EQUAL",
 /* 357 */ "comparison_operator ::= KEY_GREATER_THAN_OR_EQUAL",
 /* 358 */ "comparison_operator ::= KEY_TILDE",
 /* 359 */ "comparison_operator ::= KEY_NOT_TILDE",
 /* 360 */ "comparison_operator ::= KEY_HAS",
 /* 361 */ "value ::= enum_const",
 /* 362 */ "value ::= signed_integer",
 /* 363 */ "value ::= STRING",
 /* 364 */ "value ::= object_reference_usage",
 /* 365 */ "enum_const ::= IDENTIFIER",
 /* 366 */ "object_reference_usage ::= object_reference KEY_DOT feature_name",
 /* 367 */ "object_reference_usage ::= object_reference KEY_DOT computed_feature_name",
 /* 368 */ "opt_blocks ::=",
 /* 369 */ "opt_blocks ::= blocks",
 /* 370 */ "block ::= object_block",
 /* 371 */ "block ::= power",
 /* 372 */ "block ::= opt_gap_block",
 /* 373 */ "block ::= gap_block",
 /* 374 */ "block ::= notexist_object_block",
 /* 375 */ "unordered_group ::= KEY_OPEN_SQUARE_BRACKET KEY_UNORDERED_GROUP object_block_string KEY_CLOSE_SQUARE_BRACKET",
 /* 376 */ "object_block_string ::= object_block",
 /* 377 */ "object_block_string ::= object_block_string object_block",
 /* 378 */ "star_monad_set ::=",
 /* 379 */ "star_monad_set ::= monad_set",
 /* 380 */ "opt_gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_OPT_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET",
 /* 381 */ "gap_retrieval ::=",
 /* 382 */ "gap_retrieval ::= KEY_NORETRIEVE",
 /* 383 */ "gap_retrieval ::= KEY_RETRIEVE",
 /* 384 */ "gap_retrieval ::= KEY_FOCUS",
 /* 385 */ "gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET",
 /* 386 */ "feature_retrieval ::= KEY_GET feature_list",
 /* 387 */ "feature_retrieval ::=",
 /* 388 */ "object_block ::= KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET",
 /* 389 */ "notexist_object_block ::= notexist KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET",
 /* 390 */ "power ::= KEY_POWER restrictor",
 /* 391 */ "power ::= KEY_POWER KEY_BETWEEN limit KEY_AND limit",
 /* 392 */ "restrictor ::=",
 /* 393 */ "restrictor ::= KEY_LESS_THAN limit",
 /* 394 */ "restrictor ::= KEY_LESS_THAN_OR_EQUAL limit",
 /* 395 */ "limit ::= INTEGER",
};
#endif /* NDEBUG */


#if MQLYYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.  Return the number
** of errors.  Return 0 on success.
*/
static int mqlyyGrowStack(mqlyyParser *p){
  int newSize;
  int idx;
  mqlyyStackEntry *pNew;

  newSize = p->mqlyystksz*2 + 100;
  idx = p->mqlyytos ? (int)(p->mqlyytos - p->mqlyystack) : 0;
  if( p->mqlyystack==&p->mqlyystk0 ){
    pNew = malloc(newSize*sizeof(pNew[0]));
    if( pNew ) pNew[0] = p->mqlyystk0;
  }else{
    pNew = realloc(p->mqlyystack, newSize*sizeof(pNew[0]));
  }
  if( pNew ){
    p->mqlyystack = pNew;
    p->mqlyytos = &p->mqlyystack[idx];
#ifndef NDEBUG
    if( mqlyyTraceFILE ){
      fprintf(mqlyyTraceFILE,"%sStack grows from %d to %d entries.\n",
              mqlyyTracePrompt, p->mqlyystksz, newSize);
    }
#endif
    p->mqlyystksz = newSize;
  }
  return pNew==0; 
}
#endif

/* Datatype of the argument to the memory allocated passed as the
** second argument to MQLParserAlloc() below.  This can be changed by
** putting an appropriate #define in the %include section of the input
** grammar.
*/
#ifndef MQLYYMALLOCARGTYPE
# define MQLYYMALLOCARGTYPE size_t
#endif

/* Initialize a new parser that has already been allocated.
*/
void MQLParserInit(void *mqlyypRawParser MQLParserCTX_PDECL){
  mqlyyParser *mqlyypParser = (mqlyyParser*)mqlyypRawParser;
  MQLParserCTX_STORE
#ifdef MQLYYTRACKMAXSTACKDEPTH
  mqlyypParser->mqlyyhwm = 0;
#endif
#if MQLYYSTACKDEPTH<=0
  mqlyypParser->mqlyytos = NULL;
  mqlyypParser->mqlyystack = NULL;
  mqlyypParser->mqlyystksz = 0;
  if( mqlyyGrowStack(mqlyypParser) ){
    mqlyypParser->mqlyystack = &mqlyypParser->mqlyystk0;
    mqlyypParser->mqlyystksz = 1;
  }
#endif
#ifndef MQLYYNOERRORRECOVERY
  mqlyypParser->mqlyyerrcnt = -1;
#endif
  mqlyypParser->mqlyytos = mqlyypParser->mqlyystack;
  mqlyypParser->mqlyystack[0].stateno = 0;
  mqlyypParser->mqlyystack[0].major = 0;
#if MQLYYSTACKDEPTH>0
  mqlyypParser->mqlyystackEnd = &mqlyypParser->mqlyystack[MQLYYSTACKDEPTH-1];
#endif
}

#ifndef MQLParser_ENGINEALWAYSONSTACK
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
** to MQLParser and MQLParserFree.
*/
void *MQLParserAlloc(void *(*mallocProc)(MQLYYMALLOCARGTYPE) MQLParserCTX_PDECL){
  mqlyyParser *mqlyypParser;
  mqlyypParser = (mqlyyParser*)(*mallocProc)( (MQLYYMALLOCARGTYPE)sizeof(mqlyyParser) );
  if( mqlyypParser ){
    MQLParserCTX_STORE
    MQLParserInit(mqlyypParser MQLParserCTX_PARAM);
  }
  return (void*)mqlyypParser;
}
#endif /* MQLParser_ENGINEALWAYSONSTACK */


/* The following function deletes the "minor type" or semantic value
** associated with a symbol.  The symbol can be either a terminal
** or nonterminal. "mqlyymajor" is the symbol code, and "mqlyypminor" is
** a pointer to the value to be deleted.  The code used to do the 
** deletions is derived from the %destructor and/or %token_destructor
** directives of the input grammar.
*/
static void mqlyy_destructor(
  mqlyyParser *mqlyypParser,    /* The parser */
  MQLYYCODETYPE mqlyymajor,     /* Type code for object to destroy */
  MQLYYMINORTYPE *mqlyypminor   /* The object to be destroyed */
){
  MQLParserARG_FETCH
  MQLParserCTX_FETCH
  switch( mqlyymajor ){
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
    case 1: /* KEY_GO */
    case 2: /* KEY_CREATE */
    case 3: /* KEY_DATABASE */
    case 4: /* IDENTIFIER */
    case 5: /* STRING */
    case 6: /* KEY_INITIALIZE */
    case 7: /* KEY_USE */
    case 8: /* KEY_WITH */
    case 9: /* KEY_KEY */
    case 10: /* KEY_USING */
    case 11: /* KEY_ENCODING */
    case 12: /* KEY_DROP */
    case 13: /* KEY_VACUUM */
    case 14: /* KEY_ANALYZE */
    case 15: /* KEY_INDEXES */
    case 16: /* KEY_ON */
    case 17: /* KEY_OBJECT */
    case 18: /* KEY_OPEN_SQUARE_BRACKET */
    case 19: /* KEY_CLOSE_SQUARE_BRACKET */
    case 20: /* KEY_TYPE */
    case 21: /* KEY_TYPES */
    case 22: /* KEY_BEGIN */
    case 23: /* KEY_TRANSACTION */
    case 24: /* KEY_COMMIT */
    case 25: /* KEY_ABORT */
    case 26: /* KEY_MULTIPLE */
    case 27: /* KEY_RANGE */
    case 28: /* KEY_OBJECTS */
    case 29: /* KEY_SINGLE */
    case 30: /* KEY_MONAD */
    case 31: /* KEY_HAVING */
    case 32: /* KEY_UNIQUE */
    case 33: /* KEY_FIRST */
    case 34: /* KEY_MONADS */
    case 35: /* KEY_AND */
    case 36: /* KEY_LAST */
    case 37: /* KEY_WITHOUT */
    case 38: /* KEY_COLON */
    case 39: /* KEY_SEMICOLON */
    case 40: /* KEY_LIST */
    case 41: /* KEY_OF */
    case 42: /* KEY_INTEGER */
    case 43: /* KEY_STRING */
    case 44: /* KEY_ASCII */
    case 45: /* KEY_ID_D */
    case 46: /* KEY_SET */
    case 47: /* KEY_INDEX */
    case 48: /* KEY_IF */
    case 49: /* KEY_NOT */
    case 50: /* KEY_EXISTS */
    case 51: /* KEY_FROM */
    case 52: /* KEY_OPEN_BRACKET */
    case 53: /* INTEGER */
    case 54: /* KEY_CLOSE_BRACKET */
    case 55: /* KEY_DEFAULT */
    case 56: /* KEY_COMPUTED */
    case 57: /* KEY_UPDATE */
    case 58: /* KEY_REMOVE */
    case 59: /* KEY_ADD */
    case 60: /* KEY_INSERT */
    case 61: /* KEY_DELETE */
    case 62: /* KEY_GET */
    case 63: /* KEY_CALCULATION */
    case 64: /* KEY_UNION */
    case 65: /* KEY_DIFFERENCE */
    case 66: /* KEY_INTERSECT */
    case 67: /* KEY_SELECT */
    case 68: /* KEY_SETS */
    case 69: /* KEY_ALL */
    case 70: /* KEY_REPLACE */
    case 71: /* KEY_COMMA */
    case 72: /* KEY_EQUALS */
    case 73: /* KEY_OPEN_BRACE */
    case 74: /* KEY_CLOSE_BRACE */
    case 75: /* KEY_ENUMERATION */
    case 76: /* KEY_ENUM */
    case 77: /* KEY_DASH */
    case 78: /* KEY_NIL */
    case 79: /* KEY_SEGMENT */
    case 80: /* KEY_IN */
    case 81: /* KEY_FOCUS */
    case 82: /* KEY_MAX */
    case 83: /* KEY_MAX_M */
    case 84: /* KEY_FEATURE */
    case 85: /* KEY_RETURNING */
    case 86: /* KEY_FULL */
    case 87: /* KEY_SHEAF */
    case 88: /* KEY_FLAT */
    case 89: /* KEY_WHERE */
    case 90: /* KEY_AT */
    case 91: /* KEY_AGGREGATE */
    case 92: /* KEY_FEATURES */
    case 93: /* KEY_MIN */
    case 94: /* KEY_SUM */
    case 95: /* KEY_COUNT */
    case 96: /* KEY_STAR */
    case 97: /* KEY_ENUMERATIONS */
    case 98: /* KEY_CONSTANTS */
    case 99: /* KEY_MIN_M */
    case 100: /* KEY_ASSIGN */
    case 101: /* KEY_ID_DS */
    case 102: /* KEY_BY */
    case 103: /* KEY_QUIT */
    case 104: /* KEY_EXCLAMATION */
    case 105: /* KEY_OR */
    case 106: /* KEY_NOTEXIST */
    case 107: /* KEY_NOTEXISTS */
    case 108: /* KEY_AS */
    case 109: /* MARK */
    case 110: /* KEY_NORETRIEVE */
    case 111: /* KEY_RETRIEVE */
    case 112: /* KEY_PART_OF */
    case 113: /* KEY_STARTS_IN */
    case 114: /* KEY_OVERLAP */
    case 115: /* KEY_UNIVERSE */
    case 116: /* KEY_SUBSTRATE */
    case 117: /* KEY_LESS_THAN */
    case 118: /* KEY_GREATER_THAN */
    case 119: /* KEY_NOT_EQUAL */
    case 120: /* KEY_LESS_THAN_OR_EQUAL */
    case 121: /* KEY_GREATER_THAN_OR_EQUAL */
    case 122: /* KEY_TILDE */
    case 123: /* KEY_NOT_TILDE */
    case 124: /* KEY_HAS */
    case 125: /* KEY_DOT */
    case 126: /* KEY_UNORDERED_GROUP */
    case 127: /* KEY_OPT_GAP */
    case 128: /* KEY_GAP */
    case 129: /* KEY_POWER */
    case 130: /* KEY_BETWEEN */
{
#line 67 "./mql.yxx"
 deleteToken((mqlyypminor->mqlyy0)); UNUSED(pEE); 
#line 1733 "./mql.c"
}
      break;
    case 131: /* statement */
    case 132: /* statement_by_itself */
    case 133: /* create_database_statement */
    case 134: /* initialize_database_statement */
    case 135: /* use_statement */
    case 136: /* drop_database_statement */
    case 137: /* vacuum_database_statement */
    case 138: /* create_object_type_statement */
    case 139: /* update_object_type_statement */
    case 140: /* drop_object_type_statement */
    case 141: /* insert_monads_statement */
    case 142: /* delete_monads_statement */
    case 143: /* get_monads_statement */
    case 144: /* monad_set_calculation_statement */
    case 145: /* create_enumeration_statement */
    case 146: /* update_enumeration_statement */
    case 147: /* drop_enumeration_statement */
    case 148: /* create_segment_statement */
    case 149: /* select_statement */
    case 150: /* select_objects_at_statement */
    case 151: /* select_objects_having_monads_in_statement */
    case 152: /* get_aggregate_features_statement */
    case 153: /* get_objects_having_monads_in_statement */
    case 155: /* select_object_types_statement */
    case 157: /* select_enumerations_statement */
    case 158: /* select_enumeration_constants_statement */
    case 159: /* select_object_types_which_use_enum_statement */
    case 160: /* select_min_m_statement */
    case 161: /* select_max_m_statement */
    case 162: /* create_object_from_monads_statement */
    case 163: /* create_object_from_id_ds_statement */
    case 164: /* update_objects_by_monads_statement */
    case 165: /* update_objects_by_id_ds_statement */
    case 166: /* delete_objects_by_monads_statement */
    case 167: /* delete_objects_by_id_ds_statement */
    case 168: /* get_features_statement */
    case 169: /* quit_statement */
    case 170: /* create_indexes_statement */
    case 171: /* drop_indexes_statement */
    case 172: /* begin_transaction_statement */
    case 173: /* commit_transaction_statement */
    case 174: /* abort_transaction_statement */
    case 175: /* select_monad_sets_statement */
    case 176: /* get_monad_sets_statement */
    case 177: /* create_monad_set_statement */
    case 178: /* update_monad_set_statement */
    case 179: /* drop_monad_set_statement */
    case 180: /* create_objects_statement */
{
#line 89 "./mql.yxx"
delete((mqlyypminor->mqlyy568));
#line 1787 "./mql.c"
}
      break;
    case 181: /* database_name */
    case 182: /* opt_WITH_KEY */
    case 185: /* opt_WITH_ENCODING */
    case 187: /* on_object_type */
    case 189: /* choice_object_type_or_all */
    case 194: /* object_type_name */
    case 198: /* feature_name */
    case 220: /* enumeration_name */
    case 231: /* segment_name */
    case 247: /* object_type_to_find */
    case 249: /* using_monad_feature */
    case 272: /* object_deletion_specification */
    case 273: /* object_type_name_to_delete */
    case 286: /* object_reference_declaration */
    case 287: /* object_reference */
    case 288: /* mark_declaration */
    case 300: /* enum_const */
{
#line 154 "./mql.yxx"
 deleteToken((mqlyypminor->mqlyy0)); 
#line 1810 "./mql.c"
}
      break;
    case 184: /* opt_DATABASE */
    case 188: /* choice_type_types */
    case 190: /* opt_OBJECT */
    case 209: /* opt_ADD */
    case 211: /* choice_number_OBJECTS */
    case 216: /* choice_number_SET */
    case 219: /* choice_ENUM_ERATION */
    case 239: /* opt_OBJECTS */
    case 258: /* opt_OBJECTYPE */
    case 259: /* opt_ENUM_ERATION */
    case 266: /* choice_number_ID_DS */
    case 274: /* choice_number_FEATURES */
    case 285: /* notexist */
{
#line 182 "./mql.yxx"
;
#line 1829 "./mql.c"
}
      break;
    case 186: /* opt_ANALYZE */
    case 191: /* opt_if_not_exists */
    case 201: /* opt_computed */
    case 203: /* opt_with_index */
    case 205: /* opt_from_set */
    case 223: /* opt_DEFAULT */
{
#line 200 "./mql.yxx"
;
#line 1841 "./mql.c"
}
      break;
    case 192: /* opt_range_type */
{
#line 265 "./mql.yxx"
;
#line 1848 "./mql.c"
}
      break;
    case 193: /* opt_monad_uniqueness_type */
{
#line 276 "./mql.yxx"
;
#line 1855 "./mql.c"
}
      break;
    case 195: /* opt_feature_declaration_list */
    case 196: /* feature_declaration_list */
    case 197: /* feature_declaration */
{
#line 298 "./mql.yxx"
delete((mqlyypminor->mqlyy385));
#line 1864 "./mql.c"
}
      break;
    case 199: /* feature_type */
    case 202: /* list_feature_type */
{
#line 320 "./mql.yxx"
delete((mqlyypminor->mqlyy187));
#line 1872 "./mql.c"
}
      break;
    case 200: /* default_specification */
    case 206: /* expression */
{
#line 378 "./mql.yxx"
delete((mqlyypminor->mqlyy475));
#line 1880 "./mql.c"
}
      break;
    case 204: /* opt_string_length */
    case 226: /* ec_initialization */
    case 229: /* signed_integer */
    case 230: /* unsigned_integer */
{
#line 370 "./mql.yxx"
;
#line 1890 "./mql.c"
}
      break;
    case 207: /* feature_update_list */
    case 208: /* feature_update */
{
#line 403 "./mql.yxx"
delete((mqlyypminor->mqlyy550));
#line 1898 "./mql.c"
}
      break;
    case 210: /* monad_specification */
    case 214: /* monad_set */
    case 232: /* segment_range */
    case 234: /* in_clause */
    case 240: /* in_specification */
    case 241: /* monad_set_element_list */
    case 242: /* monad_set_element */
    case 283: /* star_monad_set */
{
#line 1018 "./mql.yxx"
delete((mqlyypminor->mqlyy538));
#line 1912 "./mql.c"
}
      break;
    case 212: /* id_ds_specification */
    case 267: /* id_d_list */
    case 268: /* id_d */
{
#line 1119 "./mql.yxx"
delete((mqlyypminor->mqlyy243));
#line 1921 "./mql.c"
}
      break;
    case 213: /* monad_set_chain */
{
#line 464 "./mql.yxx"
delete((mqlyypminor->mqlyy207));
#line 1928 "./mql.c"
}
      break;
    case 215: /* monad_set_operator */
{
#line 472 "./mql.yxx"
;
#line 1935 "./mql.c"
}
      break;
    case 217: /* monad_set_name_list */
    case 243: /* object_type_name_list */
    case 255: /* list_of_identifier */
{
#line 548 "./mql.yxx"
delete((mqlyypminor->mqlyy368));
#line 1944 "./mql.c"
}
      break;
    case 218: /* monad_set_name */
{
#line 543 "./mql.yxx"
deleteToken((mqlyypminor->mqlyy0));
#line 1951 "./mql.c"
}
      break;
    case 221: /* ec_declaration_list */
    case 222: /* ec_declaration */
{
#line 576 "./mql.yxx"
delete((mqlyypminor->mqlyy173));
#line 1959 "./mql.c"
}
      break;
    case 224: /* ec_name */
{
#line 599 "./mql.yxx"
 deleteToken((mqlyypminor->mqlyy0));  
#line 1966 "./mql.c"
}
      break;
    case 225: /* opt_ec_initialization */
{
#line 603 "./mql.yxx"
delete((mqlyypminor->mqlyy624));
#line 1973 "./mql.c"
}
      break;
    case 227: /* ec_update_list */
    case 228: /* ec_update */
{
#line 620 "./mql.yxx"
delete((mqlyypminor->mqlyy338));
#line 1981 "./mql.c"
}
      break;
    case 233: /* select_clause */
    case 238: /* focus_specification */
{
#line 698 "./mql.yxx"
;
#line 1989 "./mql.c"
}
      break;
    case 235: /* with_max_range_clause */
{
#line 757 "./mql.yxx"
delete((mqlyypminor->mqlyy374));
#line 1996 "./mql.c"
}
      break;
    case 236: /* returning_clause */
{
#line 769 "./mql.yxx"
delete((mqlyypminor->mqlyy621));
#line 2003 "./mql.c"
}
      break;
    case 237: /* where_clause */
    case 245: /* mql_query */
    case 276: /* topograph */
{
#line 810 "./mql.yxx"
delete((mqlyypminor->mqlyy367));
#line 2012 "./mql.c"
}
      break;
    case 244: /* using_range_clause */
{
#line 784 "./mql.yxx"
delete((mqlyypminor->mqlyy222));
#line 2019 "./mql.c"
}
      break;
    case 246: /* single_monad_specification */
    case 310: /* restrictor */
    case 311: /* limit */
{
#line 825 "./mql.yxx"
;
#line 2028 "./mql.c"
}
      break;
    case 248: /* aggregate_feature_list */
    case 251: /* aggregate_feature */
{
#line 867 "./mql.yxx"
delete((mqlyypminor->mqlyy354));
#line 2036 "./mql.c"
}
      break;
    case 250: /* feature_constraints */
    case 294: /* ffeatures */
{
#line 1403 "./mql.yxx"
delete((mqlyypminor->mqlyy168));
#line 2044 "./mql.c"
}
      break;
    case 252: /* aggregate_feature_comparison */
    case 297: /* feature_comparison */
{
#line 890 "./mql.yxx"
delete((mqlyypminor->mqlyy526));
#line 2052 "./mql.c"
}
      break;
    case 253: /* comparison_operator */
{
#line 1459 "./mql.yxx"
;
#line 2059 "./mql.c"
}
      break;
    case 254: /* value */
{
#line 1473 "./mql.yxx"
delete((mqlyypminor->mqlyy300));
#line 2066 "./mql.c"
}
      break;
    case 256: /* list_of_integer */
{
#line 1092 "./mql.yxx"
delete((mqlyypminor->mqlyy183));
#line 2073 "./mql.c"
}
      break;
    case 257: /* feature_list */
    case 275: /* feature_list_member */
    case 309: /* feature_retrieval */
{
#line 1265 "./mql.yxx"
delete((mqlyypminor->mqlyy218));
#line 2082 "./mql.c"
}
      break;
    case 260: /* with_id_d_specification */
    case 262: /* id_d_const */
{
#line 1022 "./mql.yxx"
;
#line 2090 "./mql.c"
}
      break;
    case 261: /* object_creation_specification */
    case 271: /* object_update_specification */
{
#line 1037 "./mql.yxx"
delete((mqlyypminor->mqlyy389));
#line 2098 "./mql.c"
}
      break;
    case 263: /* opt_list_of_feature_assignments */
    case 264: /* list_of_feature_assignments */
    case 265: /* feature_assignment */
{
#line 1046 "./mql.yxx"
delete((mqlyypminor->mqlyy432));
#line 2107 "./mql.c"
}
      break;
    case 269: /* object_creation_list */
    case 270: /* object_creation_no_object_type */
{
#line 1156 "./mql.yxx"
delete((mqlyypminor->mqlyy481));
#line 2115 "./mql.c"
}
      break;
    case 277: /* blocks */
    case 301: /* opt_blocks */
{
#line 1300 "./mql.yxx"
delete((mqlyypminor->mqlyy545));
#line 2123 "./mql.c"
}
      break;
    case 278: /* block_string */
{
#line 1332 "./mql.yxx"
delete((mqlyypminor->mqlyy421));
#line 2130 "./mql.c"
}
      break;
    case 279: /* unordered_group */
{
#line 1512 "./mql.yxx"
delete((mqlyypminor->mqlyy128));
#line 2137 "./mql.c"
}
      break;
    case 280: /* block_string0 */
{
#line 1308 "./mql.yxx"
delete((mqlyypminor->mqlyy541));
#line 2144 "./mql.c"
}
      break;
    case 281: /* block */
{
#line 1503 "./mql.yxx"
delete((mqlyypminor->mqlyy534));
#line 2151 "./mql.c"
}
      break;
    case 282: /* block_string1 */
{
#line 1315 "./mql.yxx"
delete((mqlyypminor->mqlyy594));
#line 2158 "./mql.c"
}
      break;
    case 284: /* block_string2 */
{
#line 1322 "./mql.yxx"
delete((mqlyypminor->mqlyy23));
#line 2165 "./mql.c"
}
      break;
    case 289: /* retrieval */
    case 308: /* gap_retrieval */
{
#line 1362 "./mql.yxx"
;
#line 2173 "./mql.c"
}
      break;
    case 290: /* firstlast */
{
#line 1369 "./mql.yxx"
;
#line 2180 "./mql.c"
}
      break;
    case 291: /* monad_set_relation_clause */
{
#line 1376 "./mql.yxx"
delete((mqlyypminor->mqlyy409));
#line 2187 "./mql.c"
}
      break;
    case 292: /* monad_set_relation_operation */
{
#line 1385 "./mql.yxx"

#line 2194 "./mql.c"
}
      break;
    case 293: /* universe_or_substrate */
{
#line 1395 "./mql.yxx"
 
#line 2201 "./mql.c"
}
      break;
    case 295: /* fterm */
{
#line 1415 "./mql.yxx"
delete((mqlyypminor->mqlyy1));
#line 2208 "./mql.c"
}
      break;
    case 296: /* ffactor */
{
#line 1420 "./mql.yxx"
delete((mqlyypminor->mqlyy108));
#line 2215 "./mql.c"
}
      break;
    case 298: /* computed_feature_name */
{
#line 1453 "./mql.yxx"
 delete((mqlyypminor->mqlyy485)); 
#line 2222 "./mql.c"
}
      break;
    case 299: /* object_reference_usage */
{
#line 1489 "./mql.yxx"
delete((mqlyypminor->mqlyy366));
#line 2229 "./mql.c"
}
      break;
    case 302: /* object_block */
    case 306: /* notexist_object_block */
{
#line 1561 "./mql.yxx"
delete((mqlyypminor->mqlyy461));
#line 2237 "./mql.c"
}
      break;
    case 303: /* power */
{
#line 1590 "./mql.yxx"
delete((mqlyypminor->mqlyy572));
#line 2244 "./mql.c"
}
      break;
    case 304: /* opt_gap_block */
{
#line 1533 "./mql.yxx"
delete((mqlyypminor->mqlyy289));
#line 2251 "./mql.c"
}
      break;
    case 305: /* gap_block */
{
#line 1547 "./mql.yxx"
delete((mqlyypminor->mqlyy138));
#line 2258 "./mql.c"
}
      break;
    case 307: /* object_block_string */
{
#line 1520 "./mql.yxx"
delete((mqlyypminor->mqlyy324));
#line 2265 "./mql.c"
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
static void mqlyy_pop_parser_stack(mqlyyParser *pParser){
  mqlyyStackEntry *mqlyytos;
  assert( pParser->mqlyytos!=0 );
  assert( pParser->mqlyytos > pParser->mqlyystack );
  mqlyytos = pParser->mqlyytos--;
#ifndef NDEBUG
  if( mqlyyTraceFILE ){
    fprintf(mqlyyTraceFILE,"%sPopping %s\n",
      mqlyyTracePrompt,
      mqlyyTokenName[mqlyytos->major]);
  }
#endif
  mqlyy_destructor(pParser, mqlyytos->major, &mqlyytos->minor);
}

/*
** Clear all secondary memory allocations from the parser
*/
void MQLParserFinalize(void *p){
  mqlyyParser *pParser = (mqlyyParser*)p;
  while( pParser->mqlyytos>pParser->mqlyystack ) mqlyy_pop_parser_stack(pParser);
#if MQLYYSTACKDEPTH<=0
  if( pParser->mqlyystack!=&pParser->mqlyystk0 ) free(pParser->mqlyystack);
#endif
}

#ifndef MQLParser_ENGINEALWAYSONSTACK
/* 
** Deallocate and destroy a parser.  Destructors are called for
** all stack elements before shutting the parser down.
**
** If the MQLYYPARSEFREENEVERNULL macro exists (for example because it
** is defined in a %include section of the input grammar) then it is
** assumed that the input pointer is never NULL.
*/
void MQLParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
#ifndef MQLYYPARSEFREENEVERNULL
  if( p==0 ) return;
#endif
  MQLParserFinalize(p);
  (*freeProc)(p);
}
#endif /* MQLParser_ENGINEALWAYSONSTACK */

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef MQLYYTRACKMAXSTACKDEPTH
int MQLParserStackPeak(void *p){
  mqlyyParser *pParser = (mqlyyParser*)p;
  return pParser->mqlyyhwm;
}
#endif

/* This array of booleans keeps track of the parser statement
** coverage.  The element mqlyycoverage[X][Y] is set when the parser
** is in state X and has a lookahead token Y.  In a well-tested
** systems, every element of this matrix should end up being set.
*/
#if defined(MQLYYCOVERAGE)
static unsigned char mqlyycoverage[MQLYYNSTATE][MQLYYNTOKEN];
#endif

/*
** Write into out a description of every state/lookahead combination that
**
**   (1)  has not been used by the parser, and
**   (2)  is not a syntax error.
**
** Return the number of missed state/lookahead combinations.
*/
#if defined(MQLYYCOVERAGE)
int MQLParserCoverage(FILE *out){
  int stateno, iLookAhead, i;
  int nMissed = 0;
  for(stateno=0; stateno<MQLYYNSTATE; stateno++){
    i = mqlyy_shift_ofst[stateno];
    for(iLookAhead=0; iLookAhead<MQLYYNTOKEN; iLookAhead++){
      if( mqlyy_lookahead[i+iLookAhead]!=iLookAhead ) continue;
      if( mqlyycoverage[stateno][iLookAhead]==0 ) nMissed++;
      if( out ){
        fprintf(out,"State %d lookahead %s %s\n", stateno,
                mqlyyTokenName[iLookAhead],
                mqlyycoverage[stateno][iLookAhead] ? "ok" : "missed");
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
static MQLYYACTIONTYPE mqlyy_find_shift_action(
  MQLYYCODETYPE iLookAhead,    /* The look-ahead token */
  MQLYYACTIONTYPE stateno      /* Current state number */
){
  int i;

  if( stateno>MQLYY_MAX_SHIFT ) return stateno;
  assert( stateno <= MQLYY_SHIFT_COUNT );
#if defined(MQLYYCOVERAGE)
  mqlyycoverage[stateno][iLookAhead] = 1;
#endif
  do{
    i = mqlyy_shift_ofst[stateno];
    assert( i>=0 );
    assert( i<=MQLYY_ACTTAB_COUNT );
    assert( i+MQLYYNTOKEN<=(int)MQLYY_NLOOKAHEAD );
    assert( iLookAhead!=MQLYYNOCODE );
    assert( iLookAhead < MQLYYNTOKEN );
    i += iLookAhead;
    assert( i<(int)MQLYY_NLOOKAHEAD );
    if( mqlyy_lookahead[i]!=iLookAhead ){
#ifdef MQLYYFALLBACK
      MQLYYCODETYPE iFallback;            /* Fallback token */
      assert( iLookAhead<sizeof(mqlyyFallback)/sizeof(mqlyyFallback[0]) );
      iFallback = mqlyyFallback[iLookAhead];
      if( iFallback!=0 ){
#ifndef NDEBUG
        if( mqlyyTraceFILE ){
          fprintf(mqlyyTraceFILE, "%sFALLBACK %s => %s\n",
             mqlyyTracePrompt, mqlyyTokenName[iLookAhead], mqlyyTokenName[iFallback]);
        }
#endif
        assert( mqlyyFallback[iFallback]==0 ); /* Fallback loop must terminate */
        iLookAhead = iFallback;
        continue;
      }
#endif
#ifdef MQLYYWILDCARD
      {
        int j = i - iLookAhead + MQLYYWILDCARD;
        assert( j<(int)(sizeof(mqlyy_lookahead)/sizeof(mqlyy_lookahead[0])) );
        if( mqlyy_lookahead[j]==MQLYYWILDCARD && iLookAhead>0 ){
#ifndef NDEBUG
          if( mqlyyTraceFILE ){
            fprintf(mqlyyTraceFILE, "%sWILDCARD %s => %s\n",
               mqlyyTracePrompt, mqlyyTokenName[iLookAhead],
               mqlyyTokenName[MQLYYWILDCARD]);
          }
#endif /* NDEBUG */
          return mqlyy_action[j];
        }
      }
#endif /* MQLYYWILDCARD */
      return mqlyy_default[stateno];
    }else{
      assert( i>=0 && i<sizeof(mqlyy_action)/sizeof(mqlyy_action[0]) );
      return mqlyy_action[i];
    }
  }while(1);
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
*/
static MQLYYACTIONTYPE mqlyy_find_reduce_action(
  MQLYYACTIONTYPE stateno,     /* Current state number */
  MQLYYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef MQLYYERRORSYMBOL
  if( stateno>MQLYY_REDUCE_COUNT ){
    return mqlyy_default[stateno];
  }
#else
  assert( stateno<=MQLYY_REDUCE_COUNT );
#endif
  i = mqlyy_reduce_ofst[stateno];
  assert( iLookAhead!=MQLYYNOCODE );
  i += iLookAhead;
#ifdef MQLYYERRORSYMBOL
  if( i<0 || i>=MQLYY_ACTTAB_COUNT || mqlyy_lookahead[i]!=iLookAhead ){
    return mqlyy_default[stateno];
  }
#else
  assert( i>=0 && i<MQLYY_ACTTAB_COUNT );
  assert( mqlyy_lookahead[i]==iLookAhead );
#endif
  return mqlyy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void mqlyyStackOverflow(mqlyyParser *mqlyypParser){
   MQLParserARG_FETCH
   MQLParserCTX_FETCH
#ifndef NDEBUG
   if( mqlyyTraceFILE ){
     fprintf(mqlyyTraceFILE,"%sStack Overflow!\n",mqlyyTracePrompt);
   }
#endif
   while( mqlyypParser->mqlyytos>mqlyypParser->mqlyystack ) mqlyy_pop_parser_stack(mqlyypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
/******** Begin %stack_overflow code ******************************************/
#line 71 "./mql.yxx"

  std::string errMsg = "stack overflow. Bailing out...\n";
  pEE->pError->appendError(errMsg);
   
#line 2488 "./mql.c"
/******** End %stack_overflow code ********************************************/
   MQLParserARG_STORE /* Suppress warning about unused %extra_argument var */
   MQLParserCTX_STORE
}

/*
** Print tracing information for a SHIFT action
*/
#ifndef NDEBUG
static void mqlyyTraceShift(mqlyyParser *mqlyypParser, int mqlyyNewState, const char *zTag){
  if( mqlyyTraceFILE ){
    if( mqlyyNewState<MQLYYNSTATE ){
      fprintf(mqlyyTraceFILE,"%s%s '%s', go to state %d\n",
         mqlyyTracePrompt, zTag, mqlyyTokenName[mqlyypParser->mqlyytos->major],
         mqlyyNewState);
    }else{
      fprintf(mqlyyTraceFILE,"%s%s '%s', pending reduce %d\n",
         mqlyyTracePrompt, zTag, mqlyyTokenName[mqlyypParser->mqlyytos->major],
         mqlyyNewState - MQLYY_MIN_REDUCE);
    }
  }
}
#else
# define mqlyyTraceShift(X,Y,Z)
#endif

/*
** Perform a shift action.
*/
static void mqlyy_shift(
  mqlyyParser *mqlyypParser,          /* The parser to be shifted */
  MQLYYACTIONTYPE mqlyyNewState,      /* The new state to shift in */
  MQLYYCODETYPE mqlyyMajor,           /* The major token to shift in */
  MQLParserTOKENTYPE mqlyyMinor        /* The minor token to shift in */
){
  mqlyyStackEntry *mqlyytos;
  mqlyypParser->mqlyytos++;
#ifdef MQLYYTRACKMAXSTACKDEPTH
  if( (int)(mqlyypParser->mqlyytos - mqlyypParser->mqlyystack)>mqlyypParser->mqlyyhwm ){
    mqlyypParser->mqlyyhwm++;
    assert( mqlyypParser->mqlyyhwm == (int)(mqlyypParser->mqlyytos - mqlyypParser->mqlyystack) );
  }
#endif
#if MQLYYSTACKDEPTH>0 
  if( mqlyypParser->mqlyytos>mqlyypParser->mqlyystackEnd ){
    mqlyypParser->mqlyytos--;
    mqlyyStackOverflow(mqlyypParser);
    return;
  }
#else
  if( mqlyypParser->mqlyytos>=&mqlyypParser->mqlyystack[mqlyypParser->mqlyystksz] ){
    if( mqlyyGrowStack(mqlyypParser) ){
      mqlyypParser->mqlyytos--;
      mqlyyStackOverflow(mqlyypParser);
      return;
    }
  }
#endif
  if( mqlyyNewState > MQLYY_MAX_SHIFT ){
    mqlyyNewState += MQLYY_MIN_REDUCE - MQLYY_MIN_SHIFTREDUCE;
  }
  mqlyytos = mqlyypParser->mqlyytos;
  mqlyytos->stateno = mqlyyNewState;
  mqlyytos->major = mqlyyMajor;
  mqlyytos->minor.mqlyy0 = mqlyyMinor;
  mqlyyTraceShift(mqlyypParser, mqlyyNewState, "Shift");
}

/* For rule J, mqlyyRuleInfoLhs[J] contains the symbol on the left-hand side
** of that rule */
static const MQLYYCODETYPE mqlyyRuleInfoLhs[] = {
   131,  /* (0) statement ::= statement_by_itself KEY_GO */
   132,  /* (1) statement_by_itself ::= create_database_statement */
   132,  /* (2) statement_by_itself ::= initialize_database_statement */
   132,  /* (3) statement_by_itself ::= use_statement */
   132,  /* (4) statement_by_itself ::= drop_database_statement */
   132,  /* (5) statement_by_itself ::= vacuum_database_statement */
   132,  /* (6) statement_by_itself ::= create_object_type_statement */
   132,  /* (7) statement_by_itself ::= update_object_type_statement */
   132,  /* (8) statement_by_itself ::= drop_object_type_statement */
   132,  /* (9) statement_by_itself ::= insert_monads_statement */
   132,  /* (10) statement_by_itself ::= delete_monads_statement */
   132,  /* (11) statement_by_itself ::= get_monads_statement */
   132,  /* (12) statement_by_itself ::= monad_set_calculation_statement */
   132,  /* (13) statement_by_itself ::= create_enumeration_statement */
   132,  /* (14) statement_by_itself ::= update_enumeration_statement */
   132,  /* (15) statement_by_itself ::= drop_enumeration_statement */
   132,  /* (16) statement_by_itself ::= create_segment_statement */
   132,  /* (17) statement_by_itself ::= select_statement */
   132,  /* (18) statement_by_itself ::= select_objects_at_statement */
   132,  /* (19) statement_by_itself ::= select_objects_having_monads_in_statement */
   132,  /* (20) statement_by_itself ::= get_aggregate_features_statement */
   132,  /* (21) statement_by_itself ::= get_objects_having_monads_in_statement */
   132,  /* (22) statement_by_itself ::= get_set_from_feature_statement */
   132,  /* (23) statement_by_itself ::= select_object_types_statement */
   132,  /* (24) statement_by_itself ::= select_features_statement */
   132,  /* (25) statement_by_itself ::= select_enumerations_statement */
   132,  /* (26) statement_by_itself ::= select_enumeration_constants_statement */
   132,  /* (27) statement_by_itself ::= select_object_types_which_use_enum_statement */
   132,  /* (28) statement_by_itself ::= select_min_m_statement */
   132,  /* (29) statement_by_itself ::= select_max_m_statement */
   132,  /* (30) statement_by_itself ::= create_object_from_monads_statement */
   132,  /* (31) statement_by_itself ::= create_object_from_id_ds_statement */
   132,  /* (32) statement_by_itself ::= update_objects_by_monads_statement */
   132,  /* (33) statement_by_itself ::= update_objects_by_id_ds_statement */
   132,  /* (34) statement_by_itself ::= delete_objects_by_monads_statement */
   132,  /* (35) statement_by_itself ::= delete_objects_by_id_ds_statement */
   132,  /* (36) statement_by_itself ::= get_features_statement */
   132,  /* (37) statement_by_itself ::= quit_statement */
   132,  /* (38) statement_by_itself ::= create_indexes_statement */
   132,  /* (39) statement_by_itself ::= drop_indexes_statement */
   132,  /* (40) statement_by_itself ::= begin_transaction_statement */
   132,  /* (41) statement_by_itself ::= commit_transaction_statement */
   132,  /* (42) statement_by_itself ::= abort_transaction_statement */
   132,  /* (43) statement_by_itself ::= select_monad_sets_statement */
   132,  /* (44) statement_by_itself ::= get_monad_sets_statement */
   132,  /* (45) statement_by_itself ::= create_monad_set_statement */
   132,  /* (46) statement_by_itself ::= update_monad_set_statement */
   132,  /* (47) statement_by_itself ::= drop_monad_set_statement */
   132,  /* (48) statement_by_itself ::= create_objects_statement */
   133,  /* (49) create_database_statement ::= KEY_CREATE KEY_DATABASE database_name opt_WITH_KEY opt_USING_ENCODING */
   181,  /* (50) database_name ::= IDENTIFIER */
   181,  /* (51) database_name ::= STRING */
   134,  /* (52) initialize_database_statement ::= KEY_INITIALIZE KEY_DATABASE database_name opt_WITH_KEY */
   135,  /* (53) use_statement ::= KEY_USE opt_DATABASE database_name opt_WITH_KEY */
   182,  /* (54) opt_WITH_KEY ::= KEY_WITH KEY_KEY STRING */
   182,  /* (55) opt_WITH_KEY ::= */
   183,  /* (56) opt_USING_ENCODING ::= KEY_USING KEY_ENCODING STRING */
   183,  /* (57) opt_USING_ENCODING ::= */
   184,  /* (58) opt_DATABASE ::= KEY_DATABASE */
   184,  /* (59) opt_DATABASE ::= */
   136,  /* (60) drop_database_statement ::= KEY_DROP KEY_DATABASE database_name */
   137,  /* (61) vacuum_database_statement ::= KEY_VACUUM opt_DATABASE opt_ANALYZE */
   186,  /* (62) opt_ANALYZE ::= */
   186,  /* (63) opt_ANALYZE ::= KEY_ANALYZE */
   170,  /* (64) create_indexes_statement ::= KEY_CREATE KEY_INDEXES on_object_type */
   171,  /* (65) drop_indexes_statement ::= KEY_DROP KEY_INDEXES on_object_type */
   187,  /* (66) on_object_type ::= KEY_ON KEY_OBJECT choice_type_types KEY_OPEN_SQUARE_BRACKET choice_object_type_or_all KEY_CLOSE_SQUARE_BRACKET */
   188,  /* (67) choice_type_types ::= KEY_TYPE */
   188,  /* (68) choice_type_types ::= KEY_TYPES */
   172,  /* (69) begin_transaction_statement ::= KEY_BEGIN KEY_TRANSACTION */
   173,  /* (70) commit_transaction_statement ::= KEY_COMMIT KEY_TRANSACTION */
   174,  /* (71) abort_transaction_statement ::= KEY_ABORT KEY_TRANSACTION */
   138,  /* (72) create_object_type_statement ::= KEY_CREATE opt_OBJECT KEY_TYPE opt_if_not_exists opt_range_type opt_monad_uniqueness_type KEY_OPEN_SQUARE_BRACKET object_type_name opt_feature_declaration_list KEY_CLOSE_SQUARE_BRACKET */
   192,  /* (73) opt_range_type ::= */
   192,  /* (74) opt_range_type ::= KEY_WITH KEY_MULTIPLE KEY_RANGE KEY_OBJECTS */
   192,  /* (75) opt_range_type ::= KEY_WITH KEY_SINGLE KEY_RANGE KEY_OBJECTS */
   192,  /* (76) opt_range_type ::= KEY_WITH KEY_SINGLE KEY_MONAD KEY_OBJECTS */
   193,  /* (77) opt_monad_uniqueness_type ::= */
   193,  /* (78) opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_MONADS */
   193,  /* (79) opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_AND KEY_LAST KEY_MONADS */
   193,  /* (80) opt_monad_uniqueness_type ::= KEY_WITHOUT KEY_UNIQUE KEY_MONADS */
   190,  /* (81) opt_OBJECT ::= KEY_OBJECT */
   190,  /* (82) opt_OBJECT ::= */
   194,  /* (83) object_type_name ::= IDENTIFIER */
   195,  /* (84) opt_feature_declaration_list ::= feature_declaration_list */
   195,  /* (85) opt_feature_declaration_list ::= */
   196,  /* (86) feature_declaration_list ::= feature_declaration */
   196,  /* (87) feature_declaration_list ::= feature_declaration_list feature_declaration */
   197,  /* (88) feature_declaration ::= feature_name KEY_COLON feature_type default_specification opt_computed KEY_SEMICOLON */
   197,  /* (89) feature_declaration ::= feature_name KEY_COLON KEY_LIST KEY_OF list_feature_type KEY_SEMICOLON */
   199,  /* (90) feature_type ::= KEY_INTEGER opt_with_index */
   199,  /* (91) feature_type ::= KEY_STRING opt_string_length opt_from_set opt_with_index */
   199,  /* (92) feature_type ::= KEY_ASCII opt_string_length opt_from_set opt_with_index */
   199,  /* (93) feature_type ::= KEY_ID_D opt_with_index */
   199,  /* (94) feature_type ::= IDENTIFIER opt_with_index */
   199,  /* (95) feature_type ::= KEY_SET KEY_OF KEY_MONADS */
   199,  /* (96) feature_type ::= KEY_SINGLE KEY_MONAD KEY_SET KEY_OF KEY_MONADS */
   199,  /* (97) feature_type ::= KEY_SINGLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
   199,  /* (98) feature_type ::= KEY_MULTIPLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
   202,  /* (99) list_feature_type ::= KEY_INTEGER */
   202,  /* (100) list_feature_type ::= KEY_ID_D */
   202,  /* (101) list_feature_type ::= IDENTIFIER */
   203,  /* (102) opt_with_index ::= KEY_WITH KEY_INDEX */
   203,  /* (103) opt_with_index ::= KEY_WITHOUT KEY_INDEX */
   203,  /* (104) opt_with_index ::= */
   191,  /* (105) opt_if_not_exists ::= KEY_IF KEY_NOT KEY_EXISTS */
   191,  /* (106) opt_if_not_exists ::= */
   205,  /* (107) opt_from_set ::= KEY_FROM KEY_SET */
   205,  /* (108) opt_from_set ::= */
   204,  /* (109) opt_string_length ::= */
   204,  /* (110) opt_string_length ::= KEY_OPEN_BRACKET INTEGER KEY_CLOSE_BRACKET */
   200,  /* (111) default_specification ::= KEY_DEFAULT expression */
   200,  /* (112) default_specification ::= */
   201,  /* (113) opt_computed ::= KEY_COMPUTED */
   201,  /* (114) opt_computed ::= */
   139,  /* (115) update_object_type_statement ::= KEY_UPDATE opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name feature_update_list KEY_CLOSE_SQUARE_BRACKET */
   207,  /* (116) feature_update_list ::= feature_update */
   207,  /* (117) feature_update_list ::= feature_update_list feature_update */
   208,  /* (118) feature_update ::= opt_ADD feature_declaration */
   208,  /* (119) feature_update ::= KEY_REMOVE feature_name KEY_SEMICOLON */
   209,  /* (120) opt_ADD ::= KEY_ADD */
   209,  /* (121) opt_ADD ::= */
   140,  /* (122) drop_object_type_statement ::= KEY_DROP opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   141,  /* (123) insert_monads_statement ::= KEY_INSERT monad_specification */
   142,  /* (124) delete_monads_statement ::= KEY_DELETE monad_specification */
   143,  /* (125) get_monads_statement ::= KEY_GET KEY_MONADS KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   144,  /* (126) monad_set_calculation_statement ::= KEY_MONAD KEY_SET KEY_CALCULATION monad_set_chain */
   213,  /* (127) monad_set_chain ::= monad_set */
   213,  /* (128) monad_set_chain ::= monad_set_chain monad_set_operator monad_set */
   215,  /* (129) monad_set_operator ::= KEY_UNION */
   215,  /* (130) monad_set_operator ::= KEY_DIFFERENCE */
   215,  /* (131) monad_set_operator ::= KEY_INTERSECT */
   175,  /* (132) select_monad_sets_statement ::= KEY_SELECT KEY_MONAD KEY_SETS */
   176,  /* (133) get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET monad_set_name_list */
   176,  /* (134) get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET KEY_ALL */
   216,  /* (135) choice_number_SET ::= KEY_SETS */
   216,  /* (136) choice_number_SET ::= KEY_SET */
   177,  /* (137) create_monad_set_statement ::= KEY_CREATE KEY_MONAD KEY_SET monad_set_name KEY_WITH monad_specification */
   178,  /* (138) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set_name */
   178,  /* (139) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set_name */
   178,  /* (140) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set */
   178,  /* (141) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set */
   179,  /* (142) drop_monad_set_statement ::= KEY_DROP KEY_MONAD KEY_SET monad_set_name */
   218,  /* (143) monad_set_name ::= IDENTIFIER */
   217,  /* (144) monad_set_name_list ::= monad_set_name */
   217,  /* (145) monad_set_name_list ::= monad_set_name_list KEY_COMMA monad_set_name */
   145,  /* (146) create_enumeration_statement ::= KEY_CREATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_declaration_list KEY_CLOSE_BRACE */
   219,  /* (147) choice_ENUM_ERATION ::= KEY_ENUMERATION */
   219,  /* (148) choice_ENUM_ERATION ::= KEY_ENUM */
   220,  /* (149) enumeration_name ::= IDENTIFIER */
   221,  /* (150) ec_declaration_list ::= ec_declaration */
   221,  /* (151) ec_declaration_list ::= ec_declaration_list KEY_COMMA ec_declaration */
   222,  /* (152) ec_declaration ::= opt_DEFAULT ec_name opt_ec_initialization */
   223,  /* (153) opt_DEFAULT ::= KEY_DEFAULT */
   223,  /* (154) opt_DEFAULT ::= */
   224,  /* (155) ec_name ::= IDENTIFIER */
   225,  /* (156) opt_ec_initialization ::= ec_initialization */
   225,  /* (157) opt_ec_initialization ::= */
   146,  /* (158) update_enumeration_statement ::= KEY_UPDATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_update_list KEY_CLOSE_BRACE */
   227,  /* (159) ec_update_list ::= ec_update */
   227,  /* (160) ec_update_list ::= ec_update_list KEY_COMMA ec_update */
   228,  /* (161) ec_update ::= opt_ADD opt_DEFAULT ec_name ec_initialization */
   228,  /* (162) ec_update ::= KEY_UPDATE opt_DEFAULT ec_name ec_initialization */
   228,  /* (163) ec_update ::= KEY_REMOVE ec_name */
   226,  /* (164) ec_initialization ::= KEY_EQUALS signed_integer */
   229,  /* (165) signed_integer ::= INTEGER */
   229,  /* (166) signed_integer ::= KEY_DASH INTEGER */
   229,  /* (167) signed_integer ::= KEY_NIL */
   230,  /* (168) unsigned_integer ::= INTEGER */
   147,  /* (169) drop_enumeration_statement ::= KEY_DROP choice_ENUM_ERATION enumeration_name */
   148,  /* (170) create_segment_statement ::= KEY_CREATE KEY_SEGMENT segment_name KEY_RANGE KEY_EQUALS segment_range */
   231,  /* (171) segment_name ::= IDENTIFIER */
   232,  /* (172) segment_range ::= INTEGER KEY_DASH INTEGER */
   149,  /* (173) select_statement ::= select_clause in_clause with_max_range_clause returning_clause where_clause */
   149,  /* (174) select_statement ::= select_clause KEY_IN IDENTIFIER with_max_range_clause returning_clause where_clause */
   233,  /* (175) select_clause ::= KEY_SELECT focus_specification opt_OBJECTS */
   238,  /* (176) focus_specification ::= KEY_FOCUS */
   238,  /* (177) focus_specification ::= KEY_ALL */
   239,  /* (178) opt_OBJECTS ::= KEY_OBJECTS */
   239,  /* (179) opt_OBJECTS ::= */
   234,  /* (180) in_clause ::= KEY_IN in_specification */
   234,  /* (181) in_clause ::= */
   240,  /* (182) in_specification ::= monad_set */
   240,  /* (183) in_specification ::= KEY_ALL */
   214,  /* (184) monad_set ::= KEY_OPEN_BRACE monad_set_element_list KEY_CLOSE_BRACE */
   241,  /* (185) monad_set_element_list ::= monad_set_element */
   241,  /* (186) monad_set_element_list ::= monad_set_element_list KEY_COMMA monad_set_element */
   242,  /* (187) monad_set_element ::= INTEGER */
   242,  /* (188) monad_set_element ::= INTEGER KEY_DASH INTEGER */
   242,  /* (189) monad_set_element ::= INTEGER KEY_DASH */
   235,  /* (190) with_max_range_clause ::= */
   235,  /* (191) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_MAX_M KEY_MONADS */
   235,  /* (192) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE INTEGER KEY_MONADS */
   235,  /* (193) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_FEATURE feature_name KEY_FROM KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   236,  /* (194) returning_clause ::= */
   236,  /* (195) returning_clause ::= KEY_RETURNING KEY_FULL KEY_SHEAF */
   236,  /* (196) returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF */
   236,  /* (197) returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF KEY_ON object_type_name_list */
   244,  /* (198) using_range_clause ::= */
   244,  /* (199) using_range_clause ::= KEY_RANGE KEY_ALL */
   244,  /* (200) using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_COMMA unsigned_integer KEY_CLOSE_BRACKET */
   244,  /* (201) using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_CLOSE_BRACKET */
   243,  /* (202) object_type_name_list ::= object_type_name */
   243,  /* (203) object_type_name_list ::= object_type_name_list KEY_COMMA object_type_name */
   237,  /* (204) where_clause ::= KEY_WHERE mql_query */
   150,  /* (205) select_objects_at_statement ::= KEY_SELECT opt_OBJECTS KEY_AT single_monad_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   246,  /* (206) single_monad_specification ::= KEY_MONAD KEY_EQUALS INTEGER */
   151,  /* (207) select_objects_having_monads_in_statement ::= KEY_SELECT KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN monad_set KEY_OPEN_SQUARE_BRACKET object_type_to_find KEY_CLOSE_SQUARE_BRACKET */
   247,  /* (208) object_type_to_find ::= choice_object_type_or_all */
   189,  /* (209) choice_object_type_or_all ::= object_type_name */
   189,  /* (210) choice_object_type_or_all ::= KEY_ALL */
   152,  /* (211) get_aggregate_features_statement ::= KEY_GET KEY_AGGREGATE KEY_FEATURES aggregate_feature_list KEY_FROM KEY_OBJECTS in_clause using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name feature_constraints KEY_CLOSE_SQUARE_BRACKET */
   248,  /* (212) aggregate_feature_list ::= aggregate_feature */
   248,  /* (213) aggregate_feature_list ::= aggregate_feature_list KEY_COMMA aggregate_feature */
   251,  /* (214) aggregate_feature ::= KEY_MIN KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   251,  /* (215) aggregate_feature ::= KEY_MAX KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   251,  /* (216) aggregate_feature ::= KEY_SUM KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   251,  /* (217) aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET KEY_STAR KEY_CLOSE_BRACKET */
   251,  /* (218) aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET aggregate_feature_comparison KEY_CLOSE_BRACKET */
   252,  /* (219) aggregate_feature_comparison ::= feature_name comparison_operator value */
   252,  /* (220) aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   252,  /* (221) aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   153,  /* (222) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   153,  /* (223) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET KEY_ALL KEY_CLOSE_SQUARE_BRACKET */
   153,  /* (224) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET feature_list KEY_CLOSE_SQUARE_BRACKET */
   249,  /* (225) using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE IDENTIFIER */
   249,  /* (226) using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE KEY_MONADS */
   249,  /* (227) using_monad_feature ::= */
   155,  /* (228) select_object_types_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES */
   156,  /* (229) select_features_statement ::= KEY_SELECT KEY_FEATURES KEY_FROM opt_OBJECTYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   154,  /* (230) get_set_from_feature_statement ::= KEY_GET KEY_SET KEY_FROM KEY_FEATURE feature_name KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   258,  /* (231) opt_OBJECTYPE ::= KEY_OBJECT KEY_TYPE */
   258,  /* (232) opt_OBJECTYPE ::= KEY_TYPE */
   258,  /* (233) opt_OBJECTYPE ::= */
   157,  /* (234) select_enumerations_statement ::= KEY_SELECT KEY_ENUMERATIONS */
   158,  /* (235) select_enumeration_constants_statement ::= KEY_SELECT choice_ENUM_ERATION KEY_CONSTANTS KEY_FROM opt_ENUM_ERATION enumeration_name */
   259,  /* (236) opt_ENUM_ERATION ::= KEY_ENUM */
   259,  /* (237) opt_ENUM_ERATION ::= KEY_ENUMERATION */
   259,  /* (238) opt_ENUM_ERATION ::= */
   159,  /* (239) select_object_types_which_use_enum_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES KEY_USING choice_ENUM_ERATION enumeration_name */
   160,  /* (240) select_min_m_statement ::= KEY_SELECT KEY_MIN_M */
   161,  /* (241) select_max_m_statement ::= KEY_SELECT KEY_MAX_M */
   162,  /* (242) create_object_from_monads_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification object_creation_specification */
   210,  /* (243) monad_specification ::= KEY_MONADS KEY_EQUALS monad_set */
   260,  /* (244) with_id_d_specification ::= KEY_WITH KEY_ID_D KEY_EQUALS id_d_const */
   260,  /* (245) with_id_d_specification ::= */
   262,  /* (246) id_d_const ::= INTEGER */
   262,  /* (247) id_d_const ::= KEY_NIL */
   261,  /* (248) object_creation_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   263,  /* (249) opt_list_of_feature_assignments ::= list_of_feature_assignments */
   263,  /* (250) opt_list_of_feature_assignments ::= */
   264,  /* (251) list_of_feature_assignments ::= feature_assignment */
   264,  /* (252) list_of_feature_assignments ::= list_of_feature_assignments feature_assignment */
   265,  /* (253) feature_assignment ::= feature_name KEY_ASSIGN expression KEY_SEMICOLON */
   198,  /* (254) feature_name ::= IDENTIFIER */
   198,  /* (255) feature_name ::= KEY_MONADS */
   206,  /* (256) expression ::= signed_integer */
   206,  /* (257) expression ::= STRING */
   206,  /* (258) expression ::= IDENTIFIER */
   206,  /* (259) expression ::= monad_set */
   206,  /* (260) expression ::= KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
   206,  /* (261) expression ::= KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   206,  /* (262) expression ::= KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   256,  /* (263) list_of_integer ::= signed_integer */
   256,  /* (264) list_of_integer ::= list_of_integer KEY_COMMA signed_integer */
   255,  /* (265) list_of_identifier ::= IDENTIFIER */
   255,  /* (266) list_of_identifier ::= list_of_identifier KEY_COMMA IDENTIFIER */
   163,  /* (267) create_object_from_id_ds_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM id_ds_specification with_id_d_specification object_creation_specification */
   212,  /* (268) id_ds_specification ::= choice_number_ID_DS KEY_EQUALS id_d_list */
   266,  /* (269) choice_number_ID_DS ::= KEY_ID_D */
   266,  /* (270) choice_number_ID_DS ::= KEY_ID_DS */
   267,  /* (271) id_d_list ::= id_d */
   267,  /* (272) id_d_list ::= id_d_list KEY_COMMA id_d */
   268,  /* (273) id_d ::= id_d_const */
   180,  /* (274) create_objects_statement ::= KEY_CREATE KEY_OBJECTS KEY_WITH KEY_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET object_creation_list */
   269,  /* (275) object_creation_list ::= object_creation_no_object_type */
   269,  /* (276) object_creation_list ::= object_creation_list object_creation_no_object_type */
   270,  /* (277) object_creation_no_object_type ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification KEY_OPEN_SQUARE_BRACKET opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   164,  /* (278) update_objects_by_monads_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY monad_specification object_update_specification */
   211,  /* (279) choice_number_OBJECTS ::= KEY_OBJECT */
   211,  /* (280) choice_number_OBJECTS ::= KEY_OBJECTS */
   271,  /* (281) object_update_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   165,  /* (282) update_objects_by_id_ds_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY id_ds_specification object_update_specification */
   166,  /* (283) delete_objects_by_monads_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY monad_specification object_deletion_specification */
   272,  /* (284) object_deletion_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name_to_delete KEY_CLOSE_SQUARE_BRACKET */
   273,  /* (285) object_type_name_to_delete ::= choice_object_type_or_all */
   167,  /* (286) delete_objects_by_id_ds_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY id_ds_specification object_deletion_specification */
   168,  /* (287) get_features_statement ::= KEY_GET choice_number_FEATURES feature_list KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   274,  /* (288) choice_number_FEATURES ::= KEY_FEATURE */
   274,  /* (289) choice_number_FEATURES ::= KEY_FEATURES */
   257,  /* (290) feature_list ::= feature_list_member */
   257,  /* (291) feature_list ::= feature_list KEY_COMMA feature_list_member */
   275,  /* (292) feature_list_member ::= feature_name */
   275,  /* (293) feature_list_member ::= feature_name KEY_OPEN_BRACKET IDENTIFIER KEY_CLOSE_BRACKET */
   275,  /* (294) feature_list_member ::= feature_name KEY_OPEN_BRACKET KEY_MONADS KEY_CLOSE_BRACKET */
   169,  /* (295) quit_statement ::= KEY_QUIT */
   245,  /* (296) mql_query ::= topograph */
   276,  /* (297) topograph ::= blocks */
   277,  /* (298) blocks ::= using_range_clause block_string */
   277,  /* (299) blocks ::= using_range_clause unordered_group */
   280,  /* (300) block_string0 ::= block */
   280,  /* (301) block_string0 ::= KEY_OPEN_SQUARE_BRACKET block_string KEY_CLOSE_SQUARE_BRACKET */
   282,  /* (302) block_string1 ::= block_string0 */
   282,  /* (303) block_string1 ::= block_string0 KEY_STAR star_monad_set */
   284,  /* (304) block_string2 ::= block_string1 */
   284,  /* (305) block_string2 ::= block_string1 block_string2 */
   284,  /* (306) block_string2 ::= block_string1 KEY_EXCLAMATION block_string2 */
   278,  /* (307) block_string ::= block_string2 */
   278,  /* (308) block_string ::= block_string2 KEY_OR block_string */
   285,  /* (309) notexist ::= KEY_NOTEXIST */
   285,  /* (310) notexist ::= KEY_NOTEXISTS */
   286,  /* (311) object_reference_declaration ::= */
   286,  /* (312) object_reference_declaration ::= KEY_AS object_reference */
   288,  /* (313) mark_declaration ::= */
   288,  /* (314) mark_declaration ::= MARK */
   287,  /* (315) object_reference ::= IDENTIFIER */
   289,  /* (316) retrieval ::= */
   289,  /* (317) retrieval ::= KEY_NORETRIEVE */
   289,  /* (318) retrieval ::= KEY_RETRIEVE */
   289,  /* (319) retrieval ::= KEY_FOCUS */
   290,  /* (320) firstlast ::= */
   290,  /* (321) firstlast ::= KEY_FIRST */
   290,  /* (322) firstlast ::= KEY_LAST */
   290,  /* (323) firstlast ::= KEY_FIRST KEY_AND KEY_LAST */
   291,  /* (324) monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET monad_set_name KEY_COMMA universe_or_substrate KEY_CLOSE_BRACKET */
   291,  /* (325) monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET universe_or_substrate KEY_CLOSE_BRACKET */
   291,  /* (326) monad_set_relation_clause ::= */
   292,  /* (327) monad_set_relation_operation ::= KEY_PART_OF */
   292,  /* (328) monad_set_relation_operation ::= KEY_STARTS_IN */
   292,  /* (329) monad_set_relation_operation ::= KEY_OVERLAP */
   293,  /* (330) universe_or_substrate ::= KEY_UNIVERSE */
   293,  /* (331) universe_or_substrate ::= KEY_SUBSTRATE */
   250,  /* (332) feature_constraints ::= */
   250,  /* (333) feature_constraints ::= ffeatures */
   294,  /* (334) ffeatures ::= fterm */
   294,  /* (335) ffeatures ::= ffeatures KEY_OR fterm */
   295,  /* (336) fterm ::= ffactor */
   295,  /* (337) fterm ::= fterm KEY_AND ffactor */
   296,  /* (338) ffactor ::= KEY_NOT ffactor */
   296,  /* (339) ffactor ::= KEY_OPEN_BRACKET ffeatures KEY_CLOSE_BRACKET */
   296,  /* (340) ffactor ::= feature_comparison */
   297,  /* (341) feature_comparison ::= feature_name comparison_operator value */
   297,  /* (342) feature_comparison ::= computed_feature_name comparison_operator value */
   297,  /* (343) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
   297,  /* (344) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   297,  /* (345) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   297,  /* (346) feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   297,  /* (347) feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   297,  /* (348) feature_comparison ::= computed_feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   297,  /* (349) feature_comparison ::= feature_name KEY_IN object_reference_usage */
   297,  /* (350) feature_comparison ::= computed_feature_name KEY_IN object_reference_usage */
   298,  /* (351) computed_feature_name ::= feature_name KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   253,  /* (352) comparison_operator ::= KEY_EQUALS */
   253,  /* (353) comparison_operator ::= KEY_LESS_THAN */
   253,  /* (354) comparison_operator ::= KEY_GREATER_THAN */
   253,  /* (355) comparison_operator ::= KEY_NOT_EQUAL */
   253,  /* (356) comparison_operator ::= KEY_LESS_THAN_OR_EQUAL */
   253,  /* (357) comparison_operator ::= KEY_GREATER_THAN_OR_EQUAL */
   253,  /* (358) comparison_operator ::= KEY_TILDE */
   253,  /* (359) comparison_operator ::= KEY_NOT_TILDE */
   253,  /* (360) comparison_operator ::= KEY_HAS */
   254,  /* (361) value ::= enum_const */
   254,  /* (362) value ::= signed_integer */
   254,  /* (363) value ::= STRING */
   254,  /* (364) value ::= object_reference_usage */
   300,  /* (365) enum_const ::= IDENTIFIER */
   299,  /* (366) object_reference_usage ::= object_reference KEY_DOT feature_name */
   299,  /* (367) object_reference_usage ::= object_reference KEY_DOT computed_feature_name */
   301,  /* (368) opt_blocks ::= */
   301,  /* (369) opt_blocks ::= blocks */
   281,  /* (370) block ::= object_block */
   281,  /* (371) block ::= power */
   281,  /* (372) block ::= opt_gap_block */
   281,  /* (373) block ::= gap_block */
   281,  /* (374) block ::= notexist_object_block */
   279,  /* (375) unordered_group ::= KEY_OPEN_SQUARE_BRACKET KEY_UNORDERED_GROUP object_block_string KEY_CLOSE_SQUARE_BRACKET */
   307,  /* (376) object_block_string ::= object_block */
   307,  /* (377) object_block_string ::= object_block_string object_block */
   283,  /* (378) star_monad_set ::= */
   283,  /* (379) star_monad_set ::= monad_set */
   304,  /* (380) opt_gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_OPT_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   308,  /* (381) gap_retrieval ::= */
   308,  /* (382) gap_retrieval ::= KEY_NORETRIEVE */
   308,  /* (383) gap_retrieval ::= KEY_RETRIEVE */
   308,  /* (384) gap_retrieval ::= KEY_FOCUS */
   305,  /* (385) gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   309,  /* (386) feature_retrieval ::= KEY_GET feature_list */
   309,  /* (387) feature_retrieval ::= */
   302,  /* (388) object_block ::= KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   306,  /* (389) notexist_object_block ::= notexist KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   303,  /* (390) power ::= KEY_POWER restrictor */
   303,  /* (391) power ::= KEY_POWER KEY_BETWEEN limit KEY_AND limit */
   310,  /* (392) restrictor ::= */
   310,  /* (393) restrictor ::= KEY_LESS_THAN limit */
   310,  /* (394) restrictor ::= KEY_LESS_THAN_OR_EQUAL limit */
   311,  /* (395) limit ::= INTEGER */
};

/* For rule J, mqlyyRuleInfoNRhs[J] contains the negative of the number
** of symbols on the right-hand side of that rule. */
static const signed char mqlyyRuleInfoNRhs[] = {
   -2,  /* (0) statement ::= statement_by_itself KEY_GO */
   -1,  /* (1) statement_by_itself ::= create_database_statement */
   -1,  /* (2) statement_by_itself ::= initialize_database_statement */
   -1,  /* (3) statement_by_itself ::= use_statement */
   -1,  /* (4) statement_by_itself ::= drop_database_statement */
   -1,  /* (5) statement_by_itself ::= vacuum_database_statement */
   -1,  /* (6) statement_by_itself ::= create_object_type_statement */
   -1,  /* (7) statement_by_itself ::= update_object_type_statement */
   -1,  /* (8) statement_by_itself ::= drop_object_type_statement */
   -1,  /* (9) statement_by_itself ::= insert_monads_statement */
   -1,  /* (10) statement_by_itself ::= delete_monads_statement */
   -1,  /* (11) statement_by_itself ::= get_monads_statement */
   -1,  /* (12) statement_by_itself ::= monad_set_calculation_statement */
   -1,  /* (13) statement_by_itself ::= create_enumeration_statement */
   -1,  /* (14) statement_by_itself ::= update_enumeration_statement */
   -1,  /* (15) statement_by_itself ::= drop_enumeration_statement */
   -1,  /* (16) statement_by_itself ::= create_segment_statement */
   -1,  /* (17) statement_by_itself ::= select_statement */
   -1,  /* (18) statement_by_itself ::= select_objects_at_statement */
   -1,  /* (19) statement_by_itself ::= select_objects_having_monads_in_statement */
   -1,  /* (20) statement_by_itself ::= get_aggregate_features_statement */
   -1,  /* (21) statement_by_itself ::= get_objects_having_monads_in_statement */
   -1,  /* (22) statement_by_itself ::= get_set_from_feature_statement */
   -1,  /* (23) statement_by_itself ::= select_object_types_statement */
   -1,  /* (24) statement_by_itself ::= select_features_statement */
   -1,  /* (25) statement_by_itself ::= select_enumerations_statement */
   -1,  /* (26) statement_by_itself ::= select_enumeration_constants_statement */
   -1,  /* (27) statement_by_itself ::= select_object_types_which_use_enum_statement */
   -1,  /* (28) statement_by_itself ::= select_min_m_statement */
   -1,  /* (29) statement_by_itself ::= select_max_m_statement */
   -1,  /* (30) statement_by_itself ::= create_object_from_monads_statement */
   -1,  /* (31) statement_by_itself ::= create_object_from_id_ds_statement */
   -1,  /* (32) statement_by_itself ::= update_objects_by_monads_statement */
   -1,  /* (33) statement_by_itself ::= update_objects_by_id_ds_statement */
   -1,  /* (34) statement_by_itself ::= delete_objects_by_monads_statement */
   -1,  /* (35) statement_by_itself ::= delete_objects_by_id_ds_statement */
   -1,  /* (36) statement_by_itself ::= get_features_statement */
   -1,  /* (37) statement_by_itself ::= quit_statement */
   -1,  /* (38) statement_by_itself ::= create_indexes_statement */
   -1,  /* (39) statement_by_itself ::= drop_indexes_statement */
   -1,  /* (40) statement_by_itself ::= begin_transaction_statement */
   -1,  /* (41) statement_by_itself ::= commit_transaction_statement */
   -1,  /* (42) statement_by_itself ::= abort_transaction_statement */
   -1,  /* (43) statement_by_itself ::= select_monad_sets_statement */
   -1,  /* (44) statement_by_itself ::= get_monad_sets_statement */
   -1,  /* (45) statement_by_itself ::= create_monad_set_statement */
   -1,  /* (46) statement_by_itself ::= update_monad_set_statement */
   -1,  /* (47) statement_by_itself ::= drop_monad_set_statement */
   -1,  /* (48) statement_by_itself ::= create_objects_statement */
   -5,  /* (49) create_database_statement ::= KEY_CREATE KEY_DATABASE database_name opt_WITH_KEY opt_USING_ENCODING */
   -1,  /* (50) database_name ::= IDENTIFIER */
   -1,  /* (51) database_name ::= STRING */
   -4,  /* (52) initialize_database_statement ::= KEY_INITIALIZE KEY_DATABASE database_name opt_WITH_KEY */
   -4,  /* (53) use_statement ::= KEY_USE opt_DATABASE database_name opt_WITH_KEY */
   -3,  /* (54) opt_WITH_KEY ::= KEY_WITH KEY_KEY STRING */
    0,  /* (55) opt_WITH_KEY ::= */
   -3,  /* (56) opt_USING_ENCODING ::= KEY_USING KEY_ENCODING STRING */
    0,  /* (57) opt_USING_ENCODING ::= */
   -1,  /* (58) opt_DATABASE ::= KEY_DATABASE */
    0,  /* (59) opt_DATABASE ::= */
   -3,  /* (60) drop_database_statement ::= KEY_DROP KEY_DATABASE database_name */
   -3,  /* (61) vacuum_database_statement ::= KEY_VACUUM opt_DATABASE opt_ANALYZE */
    0,  /* (62) opt_ANALYZE ::= */
   -1,  /* (63) opt_ANALYZE ::= KEY_ANALYZE */
   -3,  /* (64) create_indexes_statement ::= KEY_CREATE KEY_INDEXES on_object_type */
   -3,  /* (65) drop_indexes_statement ::= KEY_DROP KEY_INDEXES on_object_type */
   -6,  /* (66) on_object_type ::= KEY_ON KEY_OBJECT choice_type_types KEY_OPEN_SQUARE_BRACKET choice_object_type_or_all KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (67) choice_type_types ::= KEY_TYPE */
   -1,  /* (68) choice_type_types ::= KEY_TYPES */
   -2,  /* (69) begin_transaction_statement ::= KEY_BEGIN KEY_TRANSACTION */
   -2,  /* (70) commit_transaction_statement ::= KEY_COMMIT KEY_TRANSACTION */
   -2,  /* (71) abort_transaction_statement ::= KEY_ABORT KEY_TRANSACTION */
  -10,  /* (72) create_object_type_statement ::= KEY_CREATE opt_OBJECT KEY_TYPE opt_if_not_exists opt_range_type opt_monad_uniqueness_type KEY_OPEN_SQUARE_BRACKET object_type_name opt_feature_declaration_list KEY_CLOSE_SQUARE_BRACKET */
    0,  /* (73) opt_range_type ::= */
   -4,  /* (74) opt_range_type ::= KEY_WITH KEY_MULTIPLE KEY_RANGE KEY_OBJECTS */
   -4,  /* (75) opt_range_type ::= KEY_WITH KEY_SINGLE KEY_RANGE KEY_OBJECTS */
   -4,  /* (76) opt_range_type ::= KEY_WITH KEY_SINGLE KEY_MONAD KEY_OBJECTS */
    0,  /* (77) opt_monad_uniqueness_type ::= */
   -4,  /* (78) opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_MONADS */
   -6,  /* (79) opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_AND KEY_LAST KEY_MONADS */
   -3,  /* (80) opt_monad_uniqueness_type ::= KEY_WITHOUT KEY_UNIQUE KEY_MONADS */
   -1,  /* (81) opt_OBJECT ::= KEY_OBJECT */
    0,  /* (82) opt_OBJECT ::= */
   -1,  /* (83) object_type_name ::= IDENTIFIER */
   -1,  /* (84) opt_feature_declaration_list ::= feature_declaration_list */
    0,  /* (85) opt_feature_declaration_list ::= */
   -1,  /* (86) feature_declaration_list ::= feature_declaration */
   -2,  /* (87) feature_declaration_list ::= feature_declaration_list feature_declaration */
   -6,  /* (88) feature_declaration ::= feature_name KEY_COLON feature_type default_specification opt_computed KEY_SEMICOLON */
   -6,  /* (89) feature_declaration ::= feature_name KEY_COLON KEY_LIST KEY_OF list_feature_type KEY_SEMICOLON */
   -2,  /* (90) feature_type ::= KEY_INTEGER opt_with_index */
   -4,  /* (91) feature_type ::= KEY_STRING opt_string_length opt_from_set opt_with_index */
   -4,  /* (92) feature_type ::= KEY_ASCII opt_string_length opt_from_set opt_with_index */
   -2,  /* (93) feature_type ::= KEY_ID_D opt_with_index */
   -2,  /* (94) feature_type ::= IDENTIFIER opt_with_index */
   -3,  /* (95) feature_type ::= KEY_SET KEY_OF KEY_MONADS */
   -5,  /* (96) feature_type ::= KEY_SINGLE KEY_MONAD KEY_SET KEY_OF KEY_MONADS */
   -5,  /* (97) feature_type ::= KEY_SINGLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
   -5,  /* (98) feature_type ::= KEY_MULTIPLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
   -1,  /* (99) list_feature_type ::= KEY_INTEGER */
   -1,  /* (100) list_feature_type ::= KEY_ID_D */
   -1,  /* (101) list_feature_type ::= IDENTIFIER */
   -2,  /* (102) opt_with_index ::= KEY_WITH KEY_INDEX */
   -2,  /* (103) opt_with_index ::= KEY_WITHOUT KEY_INDEX */
    0,  /* (104) opt_with_index ::= */
   -3,  /* (105) opt_if_not_exists ::= KEY_IF KEY_NOT KEY_EXISTS */
    0,  /* (106) opt_if_not_exists ::= */
   -2,  /* (107) opt_from_set ::= KEY_FROM KEY_SET */
    0,  /* (108) opt_from_set ::= */
    0,  /* (109) opt_string_length ::= */
   -3,  /* (110) opt_string_length ::= KEY_OPEN_BRACKET INTEGER KEY_CLOSE_BRACKET */
   -2,  /* (111) default_specification ::= KEY_DEFAULT expression */
    0,  /* (112) default_specification ::= */
   -1,  /* (113) opt_computed ::= KEY_COMPUTED */
    0,  /* (114) opt_computed ::= */
   -7,  /* (115) update_object_type_statement ::= KEY_UPDATE opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name feature_update_list KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (116) feature_update_list ::= feature_update */
   -2,  /* (117) feature_update_list ::= feature_update_list feature_update */
   -2,  /* (118) feature_update ::= opt_ADD feature_declaration */
   -3,  /* (119) feature_update ::= KEY_REMOVE feature_name KEY_SEMICOLON */
   -1,  /* (120) opt_ADD ::= KEY_ADD */
    0,  /* (121) opt_ADD ::= */
   -6,  /* (122) drop_object_type_statement ::= KEY_DROP opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -2,  /* (123) insert_monads_statement ::= KEY_INSERT monad_specification */
   -2,  /* (124) delete_monads_statement ::= KEY_DELETE monad_specification */
   -9,  /* (125) get_monads_statement ::= KEY_GET KEY_MONADS KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -4,  /* (126) monad_set_calculation_statement ::= KEY_MONAD KEY_SET KEY_CALCULATION monad_set_chain */
   -1,  /* (127) monad_set_chain ::= monad_set */
   -3,  /* (128) monad_set_chain ::= monad_set_chain monad_set_operator monad_set */
   -1,  /* (129) monad_set_operator ::= KEY_UNION */
   -1,  /* (130) monad_set_operator ::= KEY_DIFFERENCE */
   -1,  /* (131) monad_set_operator ::= KEY_INTERSECT */
   -3,  /* (132) select_monad_sets_statement ::= KEY_SELECT KEY_MONAD KEY_SETS */
   -4,  /* (133) get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET monad_set_name_list */
   -4,  /* (134) get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET KEY_ALL */
   -1,  /* (135) choice_number_SET ::= KEY_SETS */
   -1,  /* (136) choice_number_SET ::= KEY_SET */
   -6,  /* (137) create_monad_set_statement ::= KEY_CREATE KEY_MONAD KEY_SET monad_set_name KEY_WITH monad_specification */
   -6,  /* (138) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set_name */
   -6,  /* (139) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set_name */
   -6,  /* (140) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set */
   -6,  /* (141) update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set */
   -4,  /* (142) drop_monad_set_statement ::= KEY_DROP KEY_MONAD KEY_SET monad_set_name */
   -1,  /* (143) monad_set_name ::= IDENTIFIER */
   -1,  /* (144) monad_set_name_list ::= monad_set_name */
   -3,  /* (145) monad_set_name_list ::= monad_set_name_list KEY_COMMA monad_set_name */
   -7,  /* (146) create_enumeration_statement ::= KEY_CREATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_declaration_list KEY_CLOSE_BRACE */
   -1,  /* (147) choice_ENUM_ERATION ::= KEY_ENUMERATION */
   -1,  /* (148) choice_ENUM_ERATION ::= KEY_ENUM */
   -1,  /* (149) enumeration_name ::= IDENTIFIER */
   -1,  /* (150) ec_declaration_list ::= ec_declaration */
   -3,  /* (151) ec_declaration_list ::= ec_declaration_list KEY_COMMA ec_declaration */
   -3,  /* (152) ec_declaration ::= opt_DEFAULT ec_name opt_ec_initialization */
   -1,  /* (153) opt_DEFAULT ::= KEY_DEFAULT */
    0,  /* (154) opt_DEFAULT ::= */
   -1,  /* (155) ec_name ::= IDENTIFIER */
   -1,  /* (156) opt_ec_initialization ::= ec_initialization */
    0,  /* (157) opt_ec_initialization ::= */
   -7,  /* (158) update_enumeration_statement ::= KEY_UPDATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_update_list KEY_CLOSE_BRACE */
   -1,  /* (159) ec_update_list ::= ec_update */
   -3,  /* (160) ec_update_list ::= ec_update_list KEY_COMMA ec_update */
   -4,  /* (161) ec_update ::= opt_ADD opt_DEFAULT ec_name ec_initialization */
   -4,  /* (162) ec_update ::= KEY_UPDATE opt_DEFAULT ec_name ec_initialization */
   -2,  /* (163) ec_update ::= KEY_REMOVE ec_name */
   -2,  /* (164) ec_initialization ::= KEY_EQUALS signed_integer */
   -1,  /* (165) signed_integer ::= INTEGER */
   -2,  /* (166) signed_integer ::= KEY_DASH INTEGER */
   -1,  /* (167) signed_integer ::= KEY_NIL */
   -1,  /* (168) unsigned_integer ::= INTEGER */
   -3,  /* (169) drop_enumeration_statement ::= KEY_DROP choice_ENUM_ERATION enumeration_name */
   -6,  /* (170) create_segment_statement ::= KEY_CREATE KEY_SEGMENT segment_name KEY_RANGE KEY_EQUALS segment_range */
   -1,  /* (171) segment_name ::= IDENTIFIER */
   -3,  /* (172) segment_range ::= INTEGER KEY_DASH INTEGER */
   -5,  /* (173) select_statement ::= select_clause in_clause with_max_range_clause returning_clause where_clause */
   -6,  /* (174) select_statement ::= select_clause KEY_IN IDENTIFIER with_max_range_clause returning_clause where_clause */
   -3,  /* (175) select_clause ::= KEY_SELECT focus_specification opt_OBJECTS */
   -1,  /* (176) focus_specification ::= KEY_FOCUS */
   -1,  /* (177) focus_specification ::= KEY_ALL */
   -1,  /* (178) opt_OBJECTS ::= KEY_OBJECTS */
    0,  /* (179) opt_OBJECTS ::= */
   -2,  /* (180) in_clause ::= KEY_IN in_specification */
    0,  /* (181) in_clause ::= */
   -1,  /* (182) in_specification ::= monad_set */
   -1,  /* (183) in_specification ::= KEY_ALL */
   -3,  /* (184) monad_set ::= KEY_OPEN_BRACE monad_set_element_list KEY_CLOSE_BRACE */
   -1,  /* (185) monad_set_element_list ::= monad_set_element */
   -3,  /* (186) monad_set_element_list ::= monad_set_element_list KEY_COMMA monad_set_element */
   -1,  /* (187) monad_set_element ::= INTEGER */
   -3,  /* (188) monad_set_element ::= INTEGER KEY_DASH INTEGER */
   -2,  /* (189) monad_set_element ::= INTEGER KEY_DASH */
    0,  /* (190) with_max_range_clause ::= */
   -5,  /* (191) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_MAX_M KEY_MONADS */
   -5,  /* (192) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE INTEGER KEY_MONADS */
   -9,  /* (193) with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_FEATURE feature_name KEY_FROM KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
    0,  /* (194) returning_clause ::= */
   -3,  /* (195) returning_clause ::= KEY_RETURNING KEY_FULL KEY_SHEAF */
   -3,  /* (196) returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF */
   -5,  /* (197) returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF KEY_ON object_type_name_list */
    0,  /* (198) using_range_clause ::= */
   -2,  /* (199) using_range_clause ::= KEY_RANGE KEY_ALL */
   -6,  /* (200) using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_COMMA unsigned_integer KEY_CLOSE_BRACKET */
   -4,  /* (201) using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_CLOSE_BRACKET */
   -1,  /* (202) object_type_name_list ::= object_type_name */
   -3,  /* (203) object_type_name_list ::= object_type_name_list KEY_COMMA object_type_name */
   -2,  /* (204) where_clause ::= KEY_WHERE mql_query */
   -7,  /* (205) select_objects_at_statement ::= KEY_SELECT opt_OBJECTS KEY_AT single_monad_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -3,  /* (206) single_monad_specification ::= KEY_MONAD KEY_EQUALS INTEGER */
   -9,  /* (207) select_objects_having_monads_in_statement ::= KEY_SELECT KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN monad_set KEY_OPEN_SQUARE_BRACKET object_type_to_find KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (208) object_type_to_find ::= choice_object_type_or_all */
   -1,  /* (209) choice_object_type_or_all ::= object_type_name */
   -1,  /* (210) choice_object_type_or_all ::= KEY_ALL */
  -12,  /* (211) get_aggregate_features_statement ::= KEY_GET KEY_AGGREGATE KEY_FEATURES aggregate_feature_list KEY_FROM KEY_OBJECTS in_clause using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name feature_constraints KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (212) aggregate_feature_list ::= aggregate_feature */
   -3,  /* (213) aggregate_feature_list ::= aggregate_feature_list KEY_COMMA aggregate_feature */
   -4,  /* (214) aggregate_feature ::= KEY_MIN KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   -4,  /* (215) aggregate_feature ::= KEY_MAX KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   -4,  /* (216) aggregate_feature ::= KEY_SUM KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   -4,  /* (217) aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET KEY_STAR KEY_CLOSE_BRACKET */
   -4,  /* (218) aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET aggregate_feature_comparison KEY_CLOSE_BRACKET */
   -3,  /* (219) aggregate_feature_comparison ::= feature_name comparison_operator value */
   -5,  /* (220) aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   -5,  /* (221) aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
  -10,  /* (222) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
  -12,  /* (223) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET KEY_ALL KEY_CLOSE_SQUARE_BRACKET */
  -12,  /* (224) get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET feature_list KEY_CLOSE_SQUARE_BRACKET */
   -4,  /* (225) using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE IDENTIFIER */
   -4,  /* (226) using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE KEY_MONADS */
    0,  /* (227) using_monad_feature ::= */
   -3,  /* (228) select_object_types_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES */
   -7,  /* (229) select_features_statement ::= KEY_SELECT KEY_FEATURES KEY_FROM opt_OBJECTYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -8,  /* (230) get_set_from_feature_statement ::= KEY_GET KEY_SET KEY_FROM KEY_FEATURE feature_name KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -2,  /* (231) opt_OBJECTYPE ::= KEY_OBJECT KEY_TYPE */
   -1,  /* (232) opt_OBJECTYPE ::= KEY_TYPE */
    0,  /* (233) opt_OBJECTYPE ::= */
   -2,  /* (234) select_enumerations_statement ::= KEY_SELECT KEY_ENUMERATIONS */
   -6,  /* (235) select_enumeration_constants_statement ::= KEY_SELECT choice_ENUM_ERATION KEY_CONSTANTS KEY_FROM opt_ENUM_ERATION enumeration_name */
   -1,  /* (236) opt_ENUM_ERATION ::= KEY_ENUM */
   -1,  /* (237) opt_ENUM_ERATION ::= KEY_ENUMERATION */
    0,  /* (238) opt_ENUM_ERATION ::= */
   -6,  /* (239) select_object_types_which_use_enum_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES KEY_USING choice_ENUM_ERATION enumeration_name */
   -2,  /* (240) select_min_m_statement ::= KEY_SELECT KEY_MIN_M */
   -2,  /* (241) select_max_m_statement ::= KEY_SELECT KEY_MAX_M */
   -6,  /* (242) create_object_from_monads_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification object_creation_specification */
   -3,  /* (243) monad_specification ::= KEY_MONADS KEY_EQUALS monad_set */
   -4,  /* (244) with_id_d_specification ::= KEY_WITH KEY_ID_D KEY_EQUALS id_d_const */
    0,  /* (245) with_id_d_specification ::= */
   -1,  /* (246) id_d_const ::= INTEGER */
   -1,  /* (247) id_d_const ::= KEY_NIL */
   -4,  /* (248) object_creation_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (249) opt_list_of_feature_assignments ::= list_of_feature_assignments */
    0,  /* (250) opt_list_of_feature_assignments ::= */
   -1,  /* (251) list_of_feature_assignments ::= feature_assignment */
   -2,  /* (252) list_of_feature_assignments ::= list_of_feature_assignments feature_assignment */
   -4,  /* (253) feature_assignment ::= feature_name KEY_ASSIGN expression KEY_SEMICOLON */
   -1,  /* (254) feature_name ::= IDENTIFIER */
   -1,  /* (255) feature_name ::= KEY_MONADS */
   -1,  /* (256) expression ::= signed_integer */
   -1,  /* (257) expression ::= STRING */
   -1,  /* (258) expression ::= IDENTIFIER */
   -1,  /* (259) expression ::= monad_set */
   -2,  /* (260) expression ::= KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
   -3,  /* (261) expression ::= KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   -3,  /* (262) expression ::= KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   -1,  /* (263) list_of_integer ::= signed_integer */
   -3,  /* (264) list_of_integer ::= list_of_integer KEY_COMMA signed_integer */
   -1,  /* (265) list_of_identifier ::= IDENTIFIER */
   -3,  /* (266) list_of_identifier ::= list_of_identifier KEY_COMMA IDENTIFIER */
   -6,  /* (267) create_object_from_id_ds_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM id_ds_specification with_id_d_specification object_creation_specification */
   -3,  /* (268) id_ds_specification ::= choice_number_ID_DS KEY_EQUALS id_d_list */
   -1,  /* (269) choice_number_ID_DS ::= KEY_ID_D */
   -1,  /* (270) choice_number_ID_DS ::= KEY_ID_DS */
   -1,  /* (271) id_d_list ::= id_d */
   -3,  /* (272) id_d_list ::= id_d_list KEY_COMMA id_d */
   -1,  /* (273) id_d ::= id_d_const */
   -9,  /* (274) create_objects_statement ::= KEY_CREATE KEY_OBJECTS KEY_WITH KEY_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET object_creation_list */
   -1,  /* (275) object_creation_list ::= object_creation_no_object_type */
   -2,  /* (276) object_creation_list ::= object_creation_list object_creation_no_object_type */
   -8,  /* (277) object_creation_no_object_type ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification KEY_OPEN_SQUARE_BRACKET opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   -5,  /* (278) update_objects_by_monads_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY monad_specification object_update_specification */
   -1,  /* (279) choice_number_OBJECTS ::= KEY_OBJECT */
   -1,  /* (280) choice_number_OBJECTS ::= KEY_OBJECTS */
   -4,  /* (281) object_update_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
   -5,  /* (282) update_objects_by_id_ds_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY id_ds_specification object_update_specification */
   -5,  /* (283) delete_objects_by_monads_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY monad_specification object_deletion_specification */
   -3,  /* (284) object_deletion_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name_to_delete KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (285) object_type_name_to_delete ::= choice_object_type_or_all */
   -5,  /* (286) delete_objects_by_id_ds_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY id_ds_specification object_deletion_specification */
  -10,  /* (287) get_features_statement ::= KEY_GET choice_number_FEATURES feature_list KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (288) choice_number_FEATURES ::= KEY_FEATURE */
   -1,  /* (289) choice_number_FEATURES ::= KEY_FEATURES */
   -1,  /* (290) feature_list ::= feature_list_member */
   -3,  /* (291) feature_list ::= feature_list KEY_COMMA feature_list_member */
   -1,  /* (292) feature_list_member ::= feature_name */
   -4,  /* (293) feature_list_member ::= feature_name KEY_OPEN_BRACKET IDENTIFIER KEY_CLOSE_BRACKET */
   -4,  /* (294) feature_list_member ::= feature_name KEY_OPEN_BRACKET KEY_MONADS KEY_CLOSE_BRACKET */
   -1,  /* (295) quit_statement ::= KEY_QUIT */
   -1,  /* (296) mql_query ::= topograph */
   -1,  /* (297) topograph ::= blocks */
   -2,  /* (298) blocks ::= using_range_clause block_string */
   -2,  /* (299) blocks ::= using_range_clause unordered_group */
   -1,  /* (300) block_string0 ::= block */
   -3,  /* (301) block_string0 ::= KEY_OPEN_SQUARE_BRACKET block_string KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (302) block_string1 ::= block_string0 */
   -3,  /* (303) block_string1 ::= block_string0 KEY_STAR star_monad_set */
   -1,  /* (304) block_string2 ::= block_string1 */
   -2,  /* (305) block_string2 ::= block_string1 block_string2 */
   -3,  /* (306) block_string2 ::= block_string1 KEY_EXCLAMATION block_string2 */
   -1,  /* (307) block_string ::= block_string2 */
   -3,  /* (308) block_string ::= block_string2 KEY_OR block_string */
   -1,  /* (309) notexist ::= KEY_NOTEXIST */
   -1,  /* (310) notexist ::= KEY_NOTEXISTS */
    0,  /* (311) object_reference_declaration ::= */
   -2,  /* (312) object_reference_declaration ::= KEY_AS object_reference */
    0,  /* (313) mark_declaration ::= */
   -1,  /* (314) mark_declaration ::= MARK */
   -1,  /* (315) object_reference ::= IDENTIFIER */
    0,  /* (316) retrieval ::= */
   -1,  /* (317) retrieval ::= KEY_NORETRIEVE */
   -1,  /* (318) retrieval ::= KEY_RETRIEVE */
   -1,  /* (319) retrieval ::= KEY_FOCUS */
    0,  /* (320) firstlast ::= */
   -1,  /* (321) firstlast ::= KEY_FIRST */
   -1,  /* (322) firstlast ::= KEY_LAST */
   -3,  /* (323) firstlast ::= KEY_FIRST KEY_AND KEY_LAST */
   -6,  /* (324) monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET monad_set_name KEY_COMMA universe_or_substrate KEY_CLOSE_BRACKET */
   -4,  /* (325) monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET universe_or_substrate KEY_CLOSE_BRACKET */
    0,  /* (326) monad_set_relation_clause ::= */
   -1,  /* (327) monad_set_relation_operation ::= KEY_PART_OF */
   -1,  /* (328) monad_set_relation_operation ::= KEY_STARTS_IN */
   -1,  /* (329) monad_set_relation_operation ::= KEY_OVERLAP */
   -1,  /* (330) universe_or_substrate ::= KEY_UNIVERSE */
   -1,  /* (331) universe_or_substrate ::= KEY_SUBSTRATE */
    0,  /* (332) feature_constraints ::= */
   -1,  /* (333) feature_constraints ::= ffeatures */
   -1,  /* (334) ffeatures ::= fterm */
   -3,  /* (335) ffeatures ::= ffeatures KEY_OR fterm */
   -1,  /* (336) fterm ::= ffactor */
   -3,  /* (337) fterm ::= fterm KEY_AND ffactor */
   -2,  /* (338) ffactor ::= KEY_NOT ffactor */
   -3,  /* (339) ffactor ::= KEY_OPEN_BRACKET ffeatures KEY_CLOSE_BRACKET */
   -1,  /* (340) ffactor ::= feature_comparison */
   -3,  /* (341) feature_comparison ::= feature_name comparison_operator value */
   -3,  /* (342) feature_comparison ::= computed_feature_name comparison_operator value */
   -4,  /* (343) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
   -5,  /* (344) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   -5,  /* (345) feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   -5,  /* (346) feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
   -5,  /* (347) feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   -5,  /* (348) feature_comparison ::= computed_feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
   -3,  /* (349) feature_comparison ::= feature_name KEY_IN object_reference_usage */
   -3,  /* (350) feature_comparison ::= computed_feature_name KEY_IN object_reference_usage */
   -4,  /* (351) computed_feature_name ::= feature_name KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
   -1,  /* (352) comparison_operator ::= KEY_EQUALS */
   -1,  /* (353) comparison_operator ::= KEY_LESS_THAN */
   -1,  /* (354) comparison_operator ::= KEY_GREATER_THAN */
   -1,  /* (355) comparison_operator ::= KEY_NOT_EQUAL */
   -1,  /* (356) comparison_operator ::= KEY_LESS_THAN_OR_EQUAL */
   -1,  /* (357) comparison_operator ::= KEY_GREATER_THAN_OR_EQUAL */
   -1,  /* (358) comparison_operator ::= KEY_TILDE */
   -1,  /* (359) comparison_operator ::= KEY_NOT_TILDE */
   -1,  /* (360) comparison_operator ::= KEY_HAS */
   -1,  /* (361) value ::= enum_const */
   -1,  /* (362) value ::= signed_integer */
   -1,  /* (363) value ::= STRING */
   -1,  /* (364) value ::= object_reference_usage */
   -1,  /* (365) enum_const ::= IDENTIFIER */
   -3,  /* (366) object_reference_usage ::= object_reference KEY_DOT feature_name */
   -3,  /* (367) object_reference_usage ::= object_reference KEY_DOT computed_feature_name */
    0,  /* (368) opt_blocks ::= */
   -1,  /* (369) opt_blocks ::= blocks */
   -1,  /* (370) block ::= object_block */
   -1,  /* (371) block ::= power */
   -1,  /* (372) block ::= opt_gap_block */
   -1,  /* (373) block ::= gap_block */
   -1,  /* (374) block ::= notexist_object_block */
   -4,  /* (375) unordered_group ::= KEY_OPEN_SQUARE_BRACKET KEY_UNORDERED_GROUP object_block_string KEY_CLOSE_SQUARE_BRACKET */
   -1,  /* (376) object_block_string ::= object_block */
   -2,  /* (377) object_block_string ::= object_block_string object_block */
    0,  /* (378) star_monad_set ::= */
   -1,  /* (379) star_monad_set ::= monad_set */
   -6,  /* (380) opt_gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_OPT_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
    0,  /* (381) gap_retrieval ::= */
   -1,  /* (382) gap_retrieval ::= KEY_NORETRIEVE */
   -1,  /* (383) gap_retrieval ::= KEY_RETRIEVE */
   -1,  /* (384) gap_retrieval ::= KEY_FOCUS */
   -6,  /* (385) gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   -2,  /* (386) feature_retrieval ::= KEY_GET feature_list */
    0,  /* (387) feature_retrieval ::= */
  -11,  /* (388) object_block ::= KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
  -12,  /* (389) notexist_object_block ::= notexist KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
   -2,  /* (390) power ::= KEY_POWER restrictor */
   -5,  /* (391) power ::= KEY_POWER KEY_BETWEEN limit KEY_AND limit */
    0,  /* (392) restrictor ::= */
   -2,  /* (393) restrictor ::= KEY_LESS_THAN limit */
   -2,  /* (394) restrictor ::= KEY_LESS_THAN_OR_EQUAL limit */
   -1,  /* (395) limit ::= INTEGER */
};

static void mqlyy_accept(mqlyyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
**
** The mqlyyLookahead and mqlyyLookaheadToken parameters provide reduce actions
** access to the lookahead token (if any).  The mqlyyLookahead will be MQLYYNOCODE
** if the lookahead token has already been consumed.  As this procedure is
** only called from one place, optimizing compilers will in-line it, which
** means that the extra parameters have no performance impact.
*/
static MQLYYACTIONTYPE mqlyy_reduce(
  mqlyyParser *mqlyypParser,         /* The parser */
  unsigned int mqlyyruleno,       /* Number of the rule by which to reduce */
  int mqlyyLookahead,             /* Lookahead token, or MQLYYNOCODE if none */
  MQLParserTOKENTYPE mqlyyLookaheadToken  /* Value of the lookahead token */
  MQLParserCTX_PDECL                   /* %extra_context */
){
  int mqlyygoto;                     /* The next state */
  MQLYYACTIONTYPE mqlyyact;             /* The next action */
  mqlyyStackEntry *mqlyymsp;            /* The top of the parser's stack */
  int mqlyysize;                     /* Amount to pop the stack */
  MQLParserARG_FETCH
  (void)mqlyyLookahead;
  (void)mqlyyLookaheadToken;
  mqlyymsp = mqlyypParser->mqlyytos;
#ifndef NDEBUG
  if( mqlyyTraceFILE && mqlyyruleno<(int)(sizeof(mqlyyRuleName)/sizeof(mqlyyRuleName[0])) ){
    mqlyysize = mqlyyRuleInfoNRhs[mqlyyruleno];
    if( mqlyysize ){
      fprintf(mqlyyTraceFILE, "%sReduce %d [%s]%s, pop back to state %d.\n",
        mqlyyTracePrompt,
        mqlyyruleno, mqlyyRuleName[mqlyyruleno],
        mqlyyruleno<MQLYYNRULE_WITH_ACTION ? "" : " without external action",
        mqlyymsp[mqlyysize].stateno);
    }else{
      fprintf(mqlyyTraceFILE, "%sReduce %d [%s]%s.\n",
        mqlyyTracePrompt, mqlyyruleno, mqlyyRuleName[mqlyyruleno],
        mqlyyruleno<MQLYYNRULE_WITH_ACTION ? "" : " without external action");
    }
  }
#endif /* NDEBUG */

  /* Check that the stack is large enough to grow by a single entry
  ** if the RHS of the rule is empty.  This ensures that there is room
  ** enough on the stack to push the LHS value */
  if( mqlyyRuleInfoNRhs[mqlyyruleno]==0 ){
#ifdef MQLYYTRACKMAXSTACKDEPTH
    if( (int)(mqlyypParser->mqlyytos - mqlyypParser->mqlyystack)>mqlyypParser->mqlyyhwm ){
      mqlyypParser->mqlyyhwm++;
      assert( mqlyypParser->mqlyyhwm == (int)(mqlyypParser->mqlyytos - mqlyypParser->mqlyystack));
    }
#endif
#if MQLYYSTACKDEPTH>0 
    if( mqlyypParser->mqlyytos>=mqlyypParser->mqlyystackEnd ){
      mqlyyStackOverflow(mqlyypParser);
      /* The call to mqlyyStackOverflow() above pops the stack until it is
      ** empty, causing the main parser loop to exit.  So the return value
      ** is never used and does not matter. */
      return 0;
    }
#else
    if( mqlyypParser->mqlyytos>=&mqlyypParser->mqlyystack[mqlyypParser->mqlyystksz-1] ){
      if( mqlyyGrowStack(mqlyypParser) ){
        mqlyyStackOverflow(mqlyypParser);
        /* The call to mqlyyStackOverflow() above pops the stack until it is
        ** empty, causing the main parser loop to exit.  So the return value
        ** is never used and does not matter. */
        return 0;
      }
      mqlyymsp = mqlyypParser->mqlyytos;
    }
#endif
  }

  switch( mqlyyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
/********** Begin reduce actions **********************************************/
        MQLYYMINORTYPE mqlyylhsminor;
      case 0: /* statement ::= statement_by_itself KEY_GO */
#line 90 "./mql.yxx"
{ pEE->pStatement = mqlyymsp[-1].minor.mqlyy568; }
#line 3449 "./mql.c"
  mqlyy_destructor(mqlyypParser,1,&mqlyymsp[0].minor);
        break;
      case 1: /* statement_by_itself ::= create_database_statement */
      case 2: /* statement_by_itself ::= initialize_database_statement */ mqlyytestcase(mqlyyruleno==2);
      case 3: /* statement_by_itself ::= use_statement */ mqlyytestcase(mqlyyruleno==3);
      case 4: /* statement_by_itself ::= drop_database_statement */ mqlyytestcase(mqlyyruleno==4);
      case 5: /* statement_by_itself ::= vacuum_database_statement */ mqlyytestcase(mqlyyruleno==5);
      case 6: /* statement_by_itself ::= create_object_type_statement */ mqlyytestcase(mqlyyruleno==6);
      case 7: /* statement_by_itself ::= update_object_type_statement */ mqlyytestcase(mqlyyruleno==7);
      case 8: /* statement_by_itself ::= drop_object_type_statement */ mqlyytestcase(mqlyyruleno==8);
      case 9: /* statement_by_itself ::= insert_monads_statement */ mqlyytestcase(mqlyyruleno==9);
      case 10: /* statement_by_itself ::= delete_monads_statement */ mqlyytestcase(mqlyyruleno==10);
      case 11: /* statement_by_itself ::= get_monads_statement */ mqlyytestcase(mqlyyruleno==11);
      case 12: /* statement_by_itself ::= monad_set_calculation_statement */ mqlyytestcase(mqlyyruleno==12);
      case 13: /* statement_by_itself ::= create_enumeration_statement */ mqlyytestcase(mqlyyruleno==13);
      case 14: /* statement_by_itself ::= update_enumeration_statement */ mqlyytestcase(mqlyyruleno==14);
      case 15: /* statement_by_itself ::= drop_enumeration_statement */ mqlyytestcase(mqlyyruleno==15);
      case 16: /* statement_by_itself ::= create_segment_statement */ mqlyytestcase(mqlyyruleno==16);
      case 17: /* statement_by_itself ::= select_statement */ mqlyytestcase(mqlyyruleno==17);
      case 18: /* statement_by_itself ::= select_objects_at_statement */ mqlyytestcase(mqlyyruleno==18);
      case 19: /* statement_by_itself ::= select_objects_having_monads_in_statement */ mqlyytestcase(mqlyyruleno==19);
      case 20: /* statement_by_itself ::= get_aggregate_features_statement */ mqlyytestcase(mqlyyruleno==20);
      case 21: /* statement_by_itself ::= get_objects_having_monads_in_statement */ mqlyytestcase(mqlyyruleno==21);
      case 22: /* statement_by_itself ::= get_set_from_feature_statement */ mqlyytestcase(mqlyyruleno==22);
      case 23: /* statement_by_itself ::= select_object_types_statement */ mqlyytestcase(mqlyyruleno==23);
      case 24: /* statement_by_itself ::= select_features_statement */ mqlyytestcase(mqlyyruleno==24);
      case 25: /* statement_by_itself ::= select_enumerations_statement */ mqlyytestcase(mqlyyruleno==25);
      case 26: /* statement_by_itself ::= select_enumeration_constants_statement */ mqlyytestcase(mqlyyruleno==26);
      case 27: /* statement_by_itself ::= select_object_types_which_use_enum_statement */ mqlyytestcase(mqlyyruleno==27);
      case 28: /* statement_by_itself ::= select_min_m_statement */ mqlyytestcase(mqlyyruleno==28);
      case 29: /* statement_by_itself ::= select_max_m_statement */ mqlyytestcase(mqlyyruleno==29);
      case 30: /* statement_by_itself ::= create_object_from_monads_statement */ mqlyytestcase(mqlyyruleno==30);
      case 31: /* statement_by_itself ::= create_object_from_id_ds_statement */ mqlyytestcase(mqlyyruleno==31);
      case 32: /* statement_by_itself ::= update_objects_by_monads_statement */ mqlyytestcase(mqlyyruleno==32);
      case 33: /* statement_by_itself ::= update_objects_by_id_ds_statement */ mqlyytestcase(mqlyyruleno==33);
      case 34: /* statement_by_itself ::= delete_objects_by_monads_statement */ mqlyytestcase(mqlyyruleno==34);
      case 35: /* statement_by_itself ::= delete_objects_by_id_ds_statement */ mqlyytestcase(mqlyyruleno==35);
      case 36: /* statement_by_itself ::= get_features_statement */ mqlyytestcase(mqlyyruleno==36);
      case 37: /* statement_by_itself ::= quit_statement */ mqlyytestcase(mqlyyruleno==37);
      case 38: /* statement_by_itself ::= create_indexes_statement */ mqlyytestcase(mqlyyruleno==38);
      case 39: /* statement_by_itself ::= drop_indexes_statement */ mqlyytestcase(mqlyyruleno==39);
      case 40: /* statement_by_itself ::= begin_transaction_statement */ mqlyytestcase(mqlyyruleno==40);
      case 41: /* statement_by_itself ::= commit_transaction_statement */ mqlyytestcase(mqlyyruleno==41);
      case 42: /* statement_by_itself ::= abort_transaction_statement */ mqlyytestcase(mqlyyruleno==42);
      case 43: /* statement_by_itself ::= select_monad_sets_statement */ mqlyytestcase(mqlyyruleno==43);
      case 44: /* statement_by_itself ::= get_monad_sets_statement */ mqlyytestcase(mqlyyruleno==44);
      case 45: /* statement_by_itself ::= create_monad_set_statement */ mqlyytestcase(mqlyyruleno==45);
      case 46: /* statement_by_itself ::= update_monad_set_statement */ mqlyytestcase(mqlyyruleno==46);
      case 47: /* statement_by_itself ::= drop_monad_set_statement */ mqlyytestcase(mqlyyruleno==47);
      case 48: /* statement_by_itself ::= create_objects_statement */ mqlyytestcase(mqlyyruleno==48);
#line 94 "./mql.yxx"
{ mqlyylhsminor.mqlyy568 = mqlyymsp[0].minor.mqlyy568; }
#line 3502 "./mql.c"
  mqlyymsp[0].minor.mqlyy568 = mqlyylhsminor.mqlyy568;
        break;
      case 49: /* create_database_statement ::= KEY_CREATE KEY_DATABASE database_name opt_WITH_KEY opt_USING_ENCODING */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-4].minor);
#line 150 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy568 = new CreateDatabaseStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3509 "./mql.c"
  mqlyy_destructor(mqlyypParser,3,&mqlyymsp[-3].minor);
}
        break;
      case 50: /* database_name ::= IDENTIFIER */
      case 51: /* database_name ::= STRING */ mqlyytestcase(mqlyyruleno==51);
      case 143: /* monad_set_name ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==143);
      case 149: /* enumeration_name ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==149);
      case 155: /* ec_name ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==155);
      case 171: /* segment_name ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==171);
      case 208: /* object_type_to_find ::= choice_object_type_or_all */ mqlyytestcase(mqlyyruleno==208);
      case 209: /* choice_object_type_or_all ::= object_type_name */ mqlyytestcase(mqlyyruleno==209);
      case 254: /* feature_name ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==254);
      case 285: /* object_type_name_to_delete ::= choice_object_type_or_all */ mqlyytestcase(mqlyyruleno==285);
      case 314: /* mark_declaration ::= MARK */ mqlyytestcase(mqlyyruleno==314);
      case 315: /* object_reference ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==315);
      case 365: /* enum_const ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==365);
#line 155 "./mql.yxx"
{ mqlyylhsminor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 3528 "./mql.c"
  mqlyymsp[0].minor.mqlyy0 = mqlyylhsminor.mqlyy0;
        break;
      case 52: /* initialize_database_statement ::= KEY_INITIALIZE KEY_DATABASE database_name opt_WITH_KEY */
{  mqlyy_destructor(mqlyypParser,6,&mqlyymsp[-3].minor);
#line 162 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new InitializeDatabaseStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3535 "./mql.c"
  mqlyy_destructor(mqlyypParser,3,&mqlyymsp[-2].minor);
}
        break;
      case 53: /* use_statement ::= KEY_USE opt_DATABASE database_name opt_WITH_KEY */
{  mqlyy_destructor(mqlyypParser,7,&mqlyymsp[-3].minor);
#line 167 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new UseStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3543 "./mql.c"
  mqlyy_destructor(mqlyypParser,184,&mqlyymsp[-2].minor);
}
        break;
      case 54: /* opt_WITH_KEY ::= KEY_WITH KEY_KEY STRING */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-2].minor);
#line 171 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 3551 "./mql.c"
  mqlyy_destructor(mqlyypParser,9,&mqlyymsp[-1].minor);
}
        break;
      case 55: /* opt_WITH_KEY ::= */
      case 57: /* opt_USING_ENCODING ::= */ mqlyytestcase(mqlyyruleno==57);
#line 172 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy0 = newToken(); mqlyymsp[1].minor.mqlyy0->setString(new std::string("")); }
#line 3559 "./mql.c"
        break;
      case 56: /* opt_USING_ENCODING ::= KEY_USING KEY_ENCODING STRING */
{  mqlyy_destructor(mqlyypParser,10,&mqlyymsp[-2].minor);
#line 177 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 3565 "./mql.c"
  mqlyy_destructor(mqlyypParser,11,&mqlyymsp[-1].minor);
}
        break;
      case 58: /* opt_DATABASE ::= KEY_DATABASE */
{  mqlyy_destructor(mqlyypParser,3,&mqlyymsp[0].minor);
#line 183 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124=0;}
#line 3573 "./mql.c"
}
        break;
      case 59: /* opt_DATABASE ::= */
#line 184 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy124=0;}
#line 3579 "./mql.c"
        break;
      case 60: /* drop_database_statement ::= KEY_DROP KEY_DATABASE database_name */
{  mqlyy_destructor(mqlyypParser,12,&mqlyymsp[-2].minor);
#line 190 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new DropDatabaseStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3585 "./mql.c"
  mqlyy_destructor(mqlyypParser,3,&mqlyymsp[-1].minor);
}
        break;
      case 61: /* vacuum_database_statement ::= KEY_VACUUM opt_DATABASE opt_ANALYZE */
{  mqlyy_destructor(mqlyypParser,13,&mqlyymsp[-2].minor);
#line 196 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new VacuumDatabaseStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy377); }
#line 3593 "./mql.c"
  mqlyy_destructor(mqlyypParser,184,&mqlyymsp[-1].minor);
}
        break;
      case 62: /* opt_ANALYZE ::= */
      case 104: /* opt_with_index ::= */ mqlyytestcase(mqlyyruleno==104);
      case 106: /* opt_if_not_exists ::= */ mqlyytestcase(mqlyyruleno==106);
      case 114: /* opt_computed ::= */ mqlyytestcase(mqlyyruleno==114);
      case 154: /* opt_DEFAULT ::= */ mqlyytestcase(mqlyyruleno==154);
#line 201 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy377 = false; }
#line 3604 "./mql.c"
        break;
      case 63: /* opt_ANALYZE ::= KEY_ANALYZE */
{  mqlyy_destructor(mqlyypParser,14,&mqlyymsp[0].minor);
#line 202 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy377 = true; }
#line 3610 "./mql.c"
}
        break;
      case 64: /* create_indexes_statement ::= KEY_CREATE KEY_INDEXES on_object_type */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-2].minor);
#line 208 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new CreateIndexesStatement((MQLExecEnv*) pEE, *(mqlyymsp[0].minor.mqlyy0->pString)); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3617 "./mql.c"
  mqlyy_destructor(mqlyypParser,15,&mqlyymsp[-1].minor);
}
        break;
      case 65: /* drop_indexes_statement ::= KEY_DROP KEY_INDEXES on_object_type */
{  mqlyy_destructor(mqlyypParser,12,&mqlyymsp[-2].minor);
#line 214 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new DropIndexesStatement((MQLExecEnv*) pEE, *(mqlyymsp[0].minor.mqlyy0->pString)); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3625 "./mql.c"
  mqlyy_destructor(mqlyypParser,15,&mqlyymsp[-1].minor);
}
        break;
      case 66: /* on_object_type ::= KEY_ON KEY_OBJECT choice_type_types KEY_OPEN_SQUARE_BRACKET choice_object_type_or_all KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,16,&mqlyymsp[-5].minor);
#line 223 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy0 = mqlyymsp[-1].minor.mqlyy0; }
#line 3633 "./mql.c"
  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,188,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 67: /* choice_type_types ::= KEY_TYPE */
{  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[0].minor);
#line 229 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 3644 "./mql.c"
}
        break;
      case 68: /* choice_type_types ::= KEY_TYPES */
{  mqlyy_destructor(mqlyypParser,21,&mqlyymsp[0].minor);
#line 230 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 3651 "./mql.c"
}
        break;
      case 69: /* begin_transaction_statement ::= KEY_BEGIN KEY_TRANSACTION */
{  mqlyy_destructor(mqlyypParser,22,&mqlyymsp[-1].minor);
#line 236 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new BeginTransactionStatement((MQLExecEnv*) pEE); }
#line 3658 "./mql.c"
  mqlyy_destructor(mqlyypParser,23,&mqlyymsp[0].minor);
}
        break;
      case 70: /* commit_transaction_statement ::= KEY_COMMIT KEY_TRANSACTION */
{  mqlyy_destructor(mqlyypParser,24,&mqlyymsp[-1].minor);
#line 242 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new CommitTransactionStatement((MQLExecEnv*) pEE); }
#line 3666 "./mql.c"
  mqlyy_destructor(mqlyypParser,23,&mqlyymsp[0].minor);
}
        break;
      case 71: /* abort_transaction_statement ::= KEY_ABORT KEY_TRANSACTION */
{  mqlyy_destructor(mqlyypParser,25,&mqlyymsp[-1].minor);
#line 248 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new AbortTransactionStatement((MQLExecEnv*) pEE); }
#line 3674 "./mql.c"
  mqlyy_destructor(mqlyypParser,23,&mqlyymsp[0].minor);
}
        break;
      case 72: /* create_object_type_statement ::= KEY_CREATE opt_OBJECT KEY_TYPE opt_if_not_exists opt_range_type opt_monad_uniqueness_type KEY_OPEN_SQUARE_BRACKET object_type_name opt_feature_declaration_list KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-9].minor);
#line 261 "./mql.yxx"
{ mqlyymsp[-9].minor.mqlyy568 = new CreateObjectTypeStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-5].minor.mqlyy316, mqlyymsp[-4].minor.mqlyy51, mqlyymsp[-1].minor.mqlyy385, mqlyymsp[-6].minor.mqlyy377); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 3682 "./mql.c"
  mqlyy_destructor(mqlyypParser,190,&mqlyymsp[-8].minor);
  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 73: /* opt_range_type ::= */
#line 267 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy316 = kORTMultipleRange; }
#line 3692 "./mql.c"
        break;
      case 74: /* opt_range_type ::= KEY_WITH KEY_MULTIPLE KEY_RANGE KEY_OBJECTS */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-3].minor);
#line 269 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy316 = kORTMultipleRange; }
#line 3698 "./mql.c"
  mqlyy_destructor(mqlyypParser,26,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[0].minor);
}
        break;
      case 75: /* opt_range_type ::= KEY_WITH KEY_SINGLE KEY_RANGE KEY_OBJECTS */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-3].minor);
#line 271 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy316 = kORTSingleRange; }
#line 3708 "./mql.c"
  mqlyy_destructor(mqlyypParser,29,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[0].minor);
}
        break;
      case 76: /* opt_range_type ::= KEY_WITH KEY_SINGLE KEY_MONAD KEY_OBJECTS */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-3].minor);
#line 273 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy316 = kORTSingleMonad; }
#line 3718 "./mql.c"
  mqlyy_destructor(mqlyypParser,29,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[0].minor);
}
        break;
      case 77: /* opt_monad_uniqueness_type ::= */
#line 278 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy51 = kMUTNonUniqueMonads; }
#line 3727 "./mql.c"
        break;
      case 78: /* opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-3].minor);
#line 280 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy51 = kMUTUniqueFirstMonads; }
#line 3733 "./mql.c"
  mqlyy_destructor(mqlyypParser,32,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,33,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 79: /* opt_monad_uniqueness_type ::= KEY_HAVING KEY_UNIQUE KEY_FIRST KEY_AND KEY_LAST KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-5].minor);
#line 282 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy51 = kMUTUniqueFirstAndLastMonads; }
#line 3743 "./mql.c"
  mqlyy_destructor(mqlyypParser,32,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,33,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,35,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,36,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 80: /* opt_monad_uniqueness_type ::= KEY_WITHOUT KEY_UNIQUE KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,37,&mqlyymsp[-2].minor);
#line 284 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy51 = kMUTNonUniqueMonads; }
#line 3755 "./mql.c"
  mqlyy_destructor(mqlyypParser,32,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 81: /* opt_OBJECT ::= KEY_OBJECT */
{  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[0].minor);
#line 289 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 3764 "./mql.c"
}
        break;
      case 82: /* opt_OBJECT ::= */
      case 121: /* opt_ADD ::= */ mqlyytestcase(mqlyyruleno==121);
      case 179: /* opt_OBJECTS ::= */ mqlyytestcase(mqlyyruleno==179);
#line 290 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy124 = 0; }
#line 3772 "./mql.c"
        break;
      case 83: /* object_type_name ::= IDENTIFIER */
#line 295 "./mql.yxx"
{mqlyylhsminor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 3777 "./mql.c"
  mqlyymsp[0].minor.mqlyy0 = mqlyylhsminor.mqlyy0;
        break;
      case 84: /* opt_feature_declaration_list ::= feature_declaration_list */
      case 86: /* feature_declaration_list ::= feature_declaration */ mqlyytestcase(mqlyyruleno==86);
#line 299 "./mql.yxx"
{ mqlyylhsminor.mqlyy385 = mqlyymsp[0].minor.mqlyy385; }
#line 3784 "./mql.c"
  mqlyymsp[0].minor.mqlyy385 = mqlyylhsminor.mqlyy385;
        break;
      case 85: /* opt_feature_declaration_list ::= */
#line 300 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy385 = 0; }
#line 3790 "./mql.c"
        break;
      case 87: /* feature_declaration_list ::= feature_declaration_list feature_declaration */
#line 307 "./mql.yxx"
{ mqlyylhsminor.mqlyy385 = mqlyymsp[0].minor.mqlyy385; mqlyylhsminor.mqlyy385->setNext(mqlyymsp[-1].minor.mqlyy385); }
#line 3795 "./mql.c"
  mqlyymsp[-1].minor.mqlyy385 = mqlyylhsminor.mqlyy385;
        break;
      case 88: /* feature_declaration ::= feature_name KEY_COLON feature_type default_specification opt_computed KEY_SEMICOLON */
#line 313 "./mql.yxx"
{ mqlyylhsminor.mqlyy385 = new FeatureDeclaration(mqlyymsp[-5].minor.mqlyy0->extractString(), mqlyymsp[-3].minor.mqlyy187, mqlyymsp[-2].minor.mqlyy475, mqlyymsp[-1].minor.mqlyy377, 0); deleteToken(mqlyymsp[-5].minor.mqlyy0); }
#line 3801 "./mql.c"
  mqlyy_destructor(mqlyypParser,38,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,39,&mqlyymsp[0].minor);
  mqlyymsp[-5].minor.mqlyy385 = mqlyylhsminor.mqlyy385;
        break;
      case 89: /* feature_declaration ::= feature_name KEY_COLON KEY_LIST KEY_OF list_feature_type KEY_SEMICOLON */
#line 316 "./mql.yxx"
{ mqlyylhsminor.mqlyy385 = new FeatureDeclaration(mqlyymsp[-5].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy187, new Expression(), false, 0); deleteToken(mqlyymsp[-5].minor.mqlyy0); }
#line 3809 "./mql.c"
  mqlyy_destructor(mqlyypParser,38,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,40,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,41,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,39,&mqlyymsp[0].minor);
  mqlyymsp[-5].minor.mqlyy385 = mqlyylhsminor.mqlyy385;
        break;
      case 90: /* feature_type ::= KEY_INTEGER opt_with_index */
{  mqlyy_destructor(mqlyypParser,42,&mqlyymsp[-1].minor);
#line 322 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy187 = new MQLType(kInteger, mqlyymsp[0].minor.mqlyy377); }
#line 3820 "./mql.c"
}
        break;
      case 91: /* feature_type ::= KEY_STRING opt_string_length opt_from_set opt_with_index */
{  mqlyy_destructor(mqlyypParser,43,&mqlyymsp[-3].minor);
#line 324 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy187 = new MQLType(kString, mqlyymsp[-1].minor.mqlyy377, mqlyymsp[0].minor.mqlyy377); }
#line 3827 "./mql.c"
  mqlyy_destructor(mqlyypParser,204,&mqlyymsp[-2].minor);
}
        break;
      case 92: /* feature_type ::= KEY_ASCII opt_string_length opt_from_set opt_with_index */
{  mqlyy_destructor(mqlyypParser,44,&mqlyymsp[-3].minor);
#line 326 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy187 = new MQLType(kASCII, mqlyymsp[-1].minor.mqlyy377, mqlyymsp[0].minor.mqlyy377); }
#line 3835 "./mql.c"
  mqlyy_destructor(mqlyypParser,204,&mqlyymsp[-2].minor);
}
        break;
      case 93: /* feature_type ::= KEY_ID_D opt_with_index */
{  mqlyy_destructor(mqlyypParser,45,&mqlyymsp[-1].minor);
#line 328 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy187 = new MQLType(kID_D, mqlyymsp[0].minor.mqlyy377); }
#line 3843 "./mql.c"
}
        break;
      case 94: /* feature_type ::= IDENTIFIER opt_with_index */
#line 330 "./mql.yxx"
{ mqlyylhsminor.mqlyy187 = new MQLType(mqlyymsp[-1].minor.mqlyy0->extractString(), false, mqlyymsp[0].minor.mqlyy377); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 3849 "./mql.c"
  mqlyymsp[-1].minor.mqlyy187 = mqlyylhsminor.mqlyy187;
        break;
      case 95: /* feature_type ::= KEY_SET KEY_OF KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-2].minor);
#line 332 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy187 = new MQLType(kORTMultipleRange); }
#line 3856 "./mql.c"
  mqlyy_destructor(mqlyypParser,41,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 96: /* feature_type ::= KEY_SINGLE KEY_MONAD KEY_SET KEY_OF KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,29,&mqlyymsp[-4].minor);
#line 334 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy187 = new MQLType(kORTSingleMonad); }
#line 3865 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,41,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 97: /* feature_type ::= KEY_SINGLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,29,&mqlyymsp[-4].minor);
#line 336 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy187 = new MQLType(kORTSingleRange); }
#line 3876 "./mql.c"
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,41,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 98: /* feature_type ::= KEY_MULTIPLE KEY_RANGE KEY_SET KEY_OF KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,26,&mqlyymsp[-4].minor);
#line 338 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy187 = new MQLType(kORTMultipleRange); }
#line 3887 "./mql.c"
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,41,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 99: /* list_feature_type ::= KEY_INTEGER */
{  mqlyy_destructor(mqlyypParser,42,&mqlyymsp[0].minor);
#line 345 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy187 = new MQLType(kListOfInteger); }
#line 3898 "./mql.c"
}
        break;
      case 100: /* list_feature_type ::= KEY_ID_D */
{  mqlyy_destructor(mqlyypParser,45,&mqlyymsp[0].minor);
#line 347 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy187 = new MQLType(kListOfID_D); }
#line 3905 "./mql.c"
}
        break;
      case 101: /* list_feature_type ::= IDENTIFIER */
#line 349 "./mql.yxx"
{ mqlyylhsminor.mqlyy187 = new MQLType(mqlyymsp[0].minor.mqlyy0->extractString(), true, false); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 3911 "./mql.c"
  mqlyymsp[0].minor.mqlyy187 = mqlyylhsminor.mqlyy187;
        break;
      case 102: /* opt_with_index ::= KEY_WITH KEY_INDEX */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-1].minor);
#line 354 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy377 = true; }
#line 3918 "./mql.c"
  mqlyy_destructor(mqlyypParser,47,&mqlyymsp[0].minor);
}
        break;
      case 103: /* opt_with_index ::= KEY_WITHOUT KEY_INDEX */
{  mqlyy_destructor(mqlyypParser,37,&mqlyymsp[-1].minor);
#line 355 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy377 = false; }
#line 3926 "./mql.c"
  mqlyy_destructor(mqlyypParser,47,&mqlyymsp[0].minor);
}
        break;
      case 105: /* opt_if_not_exists ::= KEY_IF KEY_NOT KEY_EXISTS */
{  mqlyy_destructor(mqlyypParser,48,&mqlyymsp[-2].minor);
#line 360 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy377 = true; }
#line 3934 "./mql.c"
  mqlyy_destructor(mqlyypParser,49,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,50,&mqlyymsp[0].minor);
}
        break;
      case 107: /* opt_from_set ::= KEY_FROM KEY_SET */
{  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-1].minor);
#line 365 "./mql.yxx"
{mqlyymsp[-1].minor.mqlyy377 = true;}
#line 3943 "./mql.c"
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[0].minor);
}
        break;
      case 108: /* opt_from_set ::= */
#line 366 "./mql.yxx"
{mqlyymsp[1].minor.mqlyy377 = false;}
#line 3950 "./mql.c"
        break;
      case 109: /* opt_string_length ::= */
#line 372 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy466 = 0; }
#line 3955 "./mql.c"
        break;
      case 110: /* opt_string_length ::= KEY_OPEN_BRACKET INTEGER KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
#line 374 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy466 = 0; }
#line 3961 "./mql.c"
  mqlyy_destructor(mqlyypParser,53,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 111: /* default_specification ::= KEY_DEFAULT expression */
{  mqlyy_destructor(mqlyypParser,55,&mqlyymsp[-1].minor);
#line 380 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy475 = mqlyymsp[0].minor.mqlyy475; }
#line 3970 "./mql.c"
}
        break;
      case 112: /* default_specification ::= */
#line 382 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy475 = 0; }
#line 3976 "./mql.c"
        break;
      case 113: /* opt_computed ::= KEY_COMPUTED */
{  mqlyy_destructor(mqlyypParser,56,&mqlyymsp[0].minor);
#line 388 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy377 = true; }
#line 3982 "./mql.c"
}
        break;
      case 115: /* update_object_type_statement ::= KEY_UPDATE opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name feature_update_list KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-6].minor);
#line 399 "./mql.yxx"
{ mqlyymsp[-6].minor.mqlyy568 = new UpdateObjectTypeStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy550); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 3989 "./mql.c"
  mqlyy_destructor(mqlyypParser,190,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 116: /* feature_update_list ::= feature_update */
#line 405 "./mql.yxx"
{ mqlyylhsminor.mqlyy550 = mqlyymsp[0].minor.mqlyy550; }
#line 3999 "./mql.c"
  mqlyymsp[0].minor.mqlyy550 = mqlyylhsminor.mqlyy550;
        break;
      case 117: /* feature_update_list ::= feature_update_list feature_update */
#line 407 "./mql.yxx"
{ mqlyylhsminor.mqlyy550 = mqlyymsp[0].minor.mqlyy550; mqlyylhsminor.mqlyy550->setNext(mqlyymsp[-1].minor.mqlyy550); }
#line 4005 "./mql.c"
  mqlyymsp[-1].minor.mqlyy550 = mqlyylhsminor.mqlyy550;
        break;
      case 118: /* feature_update ::= opt_ADD feature_declaration */
{  mqlyy_destructor(mqlyypParser,209,&mqlyymsp[-1].minor);
#line 413 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy550 = new FeatureUpdate(mqlyymsp[0].minor.mqlyy385, 0); }
#line 4012 "./mql.c"
}
        break;
      case 119: /* feature_update ::= KEY_REMOVE feature_name KEY_SEMICOLON */
{  mqlyy_destructor(mqlyypParser,58,&mqlyymsp[-2].minor);
#line 415 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy550 = new FeatureUpdate(mqlyymsp[-1].minor.mqlyy0->extractString(), 0); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4019 "./mql.c"
  mqlyy_destructor(mqlyypParser,39,&mqlyymsp[0].minor);
}
        break;
      case 120: /* opt_ADD ::= KEY_ADD */
{  mqlyy_destructor(mqlyypParser,59,&mqlyymsp[0].minor);
#line 420 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 4027 "./mql.c"
}
        break;
      case 122: /* drop_object_type_statement ::= KEY_DROP opt_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,12,&mqlyymsp[-5].minor);
#line 430 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new DropObjectTypeStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4034 "./mql.c"
  mqlyy_destructor(mqlyypParser,190,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 123: /* insert_monads_statement ::= KEY_INSERT monad_specification */
{  mqlyy_destructor(mqlyypParser,60,&mqlyymsp[-1].minor);
#line 436 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new InsertMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy538); }
#line 4045 "./mql.c"
}
        break;
      case 124: /* delete_monads_statement ::= KEY_DELETE monad_specification */
{  mqlyy_destructor(mqlyypParser,61,&mqlyymsp[-1].minor);
#line 442 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new DeleteMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy538); }
#line 4052 "./mql.c"
}
        break;
      case 125: /* get_monads_statement ::= KEY_GET KEY_MONADS KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-8].minor);
#line 453 "./mql.yxx"
{ mqlyymsp[-8].minor.mqlyy568 = new GetMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[-3].minor.mqlyy243, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4059 "./mql.c"
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 126: /* monad_set_calculation_statement ::= KEY_MONAD KEY_SET KEY_CALCULATION monad_set_chain */
{  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-3].minor);
#line 460 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new MonadSetCalculationStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy207); }
#line 4072 "./mql.c"
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,63,&mqlyymsp[-1].minor);
}
        break;
      case 127: /* monad_set_chain ::= monad_set */
#line 466 "./mql.yxx"
{ mqlyylhsminor.mqlyy207 = new MonadSetChainElement(mqlyymsp[0].minor.mqlyy538, kSONone, 0); }
#line 4080 "./mql.c"
  mqlyymsp[0].minor.mqlyy207 = mqlyylhsminor.mqlyy207;
        break;
      case 128: /* monad_set_chain ::= monad_set_chain monad_set_operator monad_set */
#line 468 "./mql.yxx"
{ mqlyylhsminor.mqlyy207 = new MonadSetChainElement(mqlyymsp[0].minor.mqlyy538, mqlyymsp[-1].minor.mqlyy566, 0); mqlyylhsminor.mqlyy207->setNext(mqlyymsp[-2].minor.mqlyy207); }
#line 4086 "./mql.c"
  mqlyymsp[-2].minor.mqlyy207 = mqlyylhsminor.mqlyy207;
        break;
      case 129: /* monad_set_operator ::= KEY_UNION */
{  mqlyy_destructor(mqlyypParser,64,&mqlyymsp[0].minor);
#line 473 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy566 = kSOUnion; }
#line 4093 "./mql.c"
}
        break;
      case 130: /* monad_set_operator ::= KEY_DIFFERENCE */
{  mqlyy_destructor(mqlyypParser,65,&mqlyymsp[0].minor);
#line 474 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy566 = kSODifference; }
#line 4100 "./mql.c"
}
        break;
      case 131: /* monad_set_operator ::= KEY_INTERSECT */
{  mqlyy_destructor(mqlyypParser,66,&mqlyymsp[0].minor);
#line 475 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy566 = kSOIntersect; }
#line 4107 "./mql.c"
}
        break;
      case 132: /* select_monad_sets_statement ::= KEY_SELECT KEY_MONAD KEY_SETS */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-2].minor);
#line 481 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new SelectMonadSetsStatement((MQLExecEnv*) pEE); }
#line 4114 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,68,&mqlyymsp[0].minor);
}
        break;
      case 133: /* get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET monad_set_name_list */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-3].minor);
#line 488 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new GetMonadSetsStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy368); }
#line 4123 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,216,&mqlyymsp[-1].minor);
}
        break;
      case 134: /* get_monad_sets_statement ::= KEY_GET KEY_MONAD choice_number_SET KEY_ALL */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-3].minor);
#line 491 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new GetMonadSetsStatement((MQLExecEnv*) pEE); }
#line 4132 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,216,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[0].minor);
}
        break;
      case 135: /* choice_number_SET ::= KEY_SETS */
{  mqlyy_destructor(mqlyypParser,68,&mqlyymsp[0].minor);
#line 496 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124 = 0;}
#line 4142 "./mql.c"
}
        break;
      case 136: /* choice_number_SET ::= KEY_SET */
{  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[0].minor);
#line 497 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124 = 0;}
#line 4149 "./mql.c"
}
        break;
      case 137: /* create_monad_set_statement ::= KEY_CREATE KEY_MONAD KEY_SET monad_set_name KEY_WITH monad_specification */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-5].minor);
#line 504 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new CreateMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy538); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4156 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-1].minor);
}
        break;
      case 138: /* update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set_name */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-5].minor);
#line 514 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new UpdateMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy566, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4166 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-3].minor);
}
        break;
      case 139: /* update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set_name */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-5].minor);
#line 520 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new UpdateMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), kSOReplace, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4175 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,70,&mqlyymsp[-1].minor);
}
        break;
      case 140: /* update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name monad_set_operator monad_set */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-5].minor);
#line 526 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new UpdateMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy566, mqlyymsp[0].minor.mqlyy538); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4185 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-3].minor);
}
        break;
      case 141: /* update_monad_set_statement ::= KEY_UPDATE KEY_MONAD KEY_SET monad_set_name KEY_REPLACE monad_set */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-5].minor);
#line 532 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new UpdateMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), kSOReplace, mqlyymsp[0].minor.mqlyy538); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4194 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,70,&mqlyymsp[-1].minor);
}
        break;
      case 142: /* drop_monad_set_statement ::= KEY_DROP KEY_MONAD KEY_SET monad_set_name */
{  mqlyy_destructor(mqlyypParser,12,&mqlyymsp[-3].minor);
#line 539 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy568 = new DropMonadSetStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4204 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-1].minor);
}
        break;
      case 144: /* monad_set_name_list ::= monad_set_name */
      case 202: /* object_type_name_list ::= object_type_name */ mqlyytestcase(mqlyyruleno==202);
      case 265: /* list_of_identifier ::= IDENTIFIER */ mqlyytestcase(mqlyyruleno==265);
#line 550 "./mql.yxx"
{ mqlyylhsminor.mqlyy368 = new StringListNode(*(mqlyymsp[0].minor.mqlyy0->pString), 0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4214 "./mql.c"
  mqlyymsp[0].minor.mqlyy368 = mqlyylhsminor.mqlyy368;
        break;
      case 145: /* monad_set_name_list ::= monad_set_name_list KEY_COMMA monad_set_name */
      case 203: /* object_type_name_list ::= object_type_name_list KEY_COMMA object_type_name */ mqlyytestcase(mqlyyruleno==203);
      case 266: /* list_of_identifier ::= list_of_identifier KEY_COMMA IDENTIFIER */ mqlyytestcase(mqlyyruleno==266);
#line 553 "./mql.yxx"
{ mqlyylhsminor.mqlyy368 = new StringListNode(*(mqlyymsp[0].minor.mqlyy0->pString), mqlyymsp[-2].minor.mqlyy368); mqlyymsp[-2].minor.mqlyy368->setNext(mqlyylhsminor.mqlyy368); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4222 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy368 = mqlyylhsminor.mqlyy368;
        break;
      case 146: /* create_enumeration_statement ::= KEY_CREATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_declaration_list KEY_CLOSE_BRACE */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-6].minor);
#line 562 "./mql.yxx"
{ mqlyymsp[-6].minor.mqlyy568 = new CreateEnumerationStatement((MQLExecEnv*) pEE, mqlyymsp[-4].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy173); deleteToken(mqlyymsp[-4].minor.mqlyy0); }
#line 4230 "./mql.c"
  mqlyy_destructor(mqlyypParser,219,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,73,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,74,&mqlyymsp[0].minor);
}
        break;
      case 147: /* choice_ENUM_ERATION ::= KEY_ENUMERATION */
{  mqlyy_destructor(mqlyypParser,75,&mqlyymsp[0].minor);
#line 567 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 4241 "./mql.c"
}
        break;
      case 148: /* choice_ENUM_ERATION ::= KEY_ENUM */
{  mqlyy_destructor(mqlyypParser,76,&mqlyymsp[0].minor);
#line 568 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 4248 "./mql.c"
}
        break;
      case 150: /* ec_declaration_list ::= ec_declaration */
#line 578 "./mql.yxx"
{ mqlyylhsminor.mqlyy173 = mqlyymsp[0].minor.mqlyy173; }
#line 4254 "./mql.c"
  mqlyymsp[0].minor.mqlyy173 = mqlyylhsminor.mqlyy173;
        break;
      case 151: /* ec_declaration_list ::= ec_declaration_list KEY_COMMA ec_declaration */
#line 580 "./mql.yxx"
{ mqlyylhsminor.mqlyy173 = mqlyymsp[0].minor.mqlyy173; mqlyylhsminor.mqlyy173->setNext(mqlyymsp[-2].minor.mqlyy173); }
#line 4260 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy173 = mqlyylhsminor.mqlyy173;
        break;
      case 152: /* ec_declaration ::= opt_DEFAULT ec_name opt_ec_initialization */
#line 585 "./mql.yxx"
{ mqlyylhsminor.mqlyy173 = new ECDeclaration(mqlyymsp[-2].minor.mqlyy377, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy624, 0); 
      deleteToken(mqlyymsp[-1].minor.mqlyy0); 
    }
#line 4269 "./mql.c"
  mqlyymsp[-2].minor.mqlyy173 = mqlyylhsminor.mqlyy173;
        break;
      case 153: /* opt_DEFAULT ::= KEY_DEFAULT */
{  mqlyy_destructor(mqlyypParser,55,&mqlyymsp[0].minor);
#line 593 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy377 = true; }
#line 4276 "./mql.c"
}
        break;
      case 156: /* opt_ec_initialization ::= ec_initialization */
#line 605 "./mql.yxx"
{ mqlyylhsminor.mqlyy624 = new emdf_ivalue(mqlyymsp[0].minor.mqlyy466); }
#line 4282 "./mql.c"
  mqlyymsp[0].minor.mqlyy624 = mqlyylhsminor.mqlyy624;
        break;
      case 157: /* opt_ec_initialization ::= */
#line 608 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy624 = 0; }
#line 4288 "./mql.c"
        break;
      case 158: /* update_enumeration_statement ::= KEY_UPDATE choice_ENUM_ERATION enumeration_name KEY_EQUALS KEY_OPEN_BRACE ec_update_list KEY_CLOSE_BRACE */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-6].minor);
#line 616 "./mql.yxx"
{ mqlyymsp[-6].minor.mqlyy568 = new UpdateEnumerationStatement((MQLExecEnv*) pEE, mqlyymsp[-4].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy338); deleteToken(mqlyymsp[-4].minor.mqlyy0); }
#line 4294 "./mql.c"
  mqlyy_destructor(mqlyypParser,219,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,73,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,74,&mqlyymsp[0].minor);
}
        break;
      case 159: /* ec_update_list ::= ec_update */
#line 622 "./mql.yxx"
{ mqlyylhsminor.mqlyy338 = mqlyymsp[0].minor.mqlyy338; }
#line 4304 "./mql.c"
  mqlyymsp[0].minor.mqlyy338 = mqlyylhsminor.mqlyy338;
        break;
      case 160: /* ec_update_list ::= ec_update_list KEY_COMMA ec_update */
#line 624 "./mql.yxx"
{ mqlyylhsminor.mqlyy338 = mqlyymsp[0].minor.mqlyy338; mqlyylhsminor.mqlyy338->setNext(mqlyymsp[-2].minor.mqlyy338); }
#line 4310 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy338 = mqlyylhsminor.mqlyy338;
        break;
      case 161: /* ec_update ::= opt_ADD opt_DEFAULT ec_name ec_initialization */
{  mqlyy_destructor(mqlyypParser,209,&mqlyymsp[-3].minor);
#line 630 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy338 = new ECUpdate(mqlyymsp[-2].minor.mqlyy377, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy466, kAdd, 0); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4318 "./mql.c"
}
        break;
      case 162: /* ec_update ::= KEY_UPDATE opt_DEFAULT ec_name ec_initialization */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-3].minor);
#line 632 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy338 = new ECUpdate(mqlyymsp[-2].minor.mqlyy377, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy466, kUpdate, 0); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4325 "./mql.c"
}
        break;
      case 163: /* ec_update ::= KEY_REMOVE ec_name */
{  mqlyy_destructor(mqlyypParser,58,&mqlyymsp[-1].minor);
#line 634 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy338 = new ECUpdate(false, mqlyymsp[0].minor.mqlyy0->extractString(), 0, kRemove, 0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4332 "./mql.c"
}
        break;
      case 164: /* ec_initialization ::= KEY_EQUALS signed_integer */
{  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
#line 639 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy466 = mqlyymsp[0].minor.mqlyy466; }
#line 4339 "./mql.c"
}
        break;
      case 165: /* signed_integer ::= INTEGER */
      case 168: /* unsigned_integer ::= INTEGER */ mqlyytestcase(mqlyyruleno==168);
#line 643 "./mql.yxx"
{ mqlyylhsminor.mqlyy466 = (emdf_ivalue) mqlyymsp[0].minor.mqlyy0->integer; deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4346 "./mql.c"
  mqlyymsp[0].minor.mqlyy466 = mqlyylhsminor.mqlyy466;
        break;
      case 166: /* signed_integer ::= KEY_DASH INTEGER */
{  mqlyy_destructor(mqlyypParser,77,&mqlyymsp[-1].minor);
#line 644 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy466 = (emdf_ivalue) -(mqlyymsp[0].minor.mqlyy0->integer); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4353 "./mql.c"
}
        break;
      case 167: /* signed_integer ::= KEY_NIL */
{  mqlyy_destructor(mqlyypParser,78,&mqlyymsp[0].minor);
#line 645 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy466 = NIL; }
#line 4360 "./mql.c"
}
        break;
      case 169: /* drop_enumeration_statement ::= KEY_DROP choice_ENUM_ERATION enumeration_name */
{  mqlyy_destructor(mqlyypParser,12,&mqlyymsp[-2].minor);
#line 658 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new DropEnumerationStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4367 "./mql.c"
  mqlyy_destructor(mqlyypParser,219,&mqlyymsp[-1].minor);
}
        break;
      case 170: /* create_segment_statement ::= KEY_CREATE KEY_SEGMENT segment_name KEY_RANGE KEY_EQUALS segment_range */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-5].minor);
#line 668 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new CreateSegmentStatement((MQLExecEnv*) pEE, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy538); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 4375 "./mql.c"
  mqlyy_destructor(mqlyypParser,79,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
}
        break;
      case 172: /* segment_range ::= INTEGER KEY_DASH INTEGER */
#line 678 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = new MQLMonadSetElement((monad_m) mqlyymsp[-2].minor.mqlyy0->integer, (monad_m) mqlyymsp[0].minor.mqlyy0->integer, 0, true);  deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4384 "./mql.c"
  mqlyy_destructor(mqlyypParser,77,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 173: /* select_statement ::= select_clause in_clause with_max_range_clause returning_clause where_clause */
#line 688 "./mql.yxx"
{ mqlyylhsminor.mqlyy568 = new SelectStatement((MQLExecEnv*) pEE, mqlyymsp[-4].minor.mqlyy493, mqlyymsp[-3].minor.mqlyy538, mqlyymsp[-2].minor.mqlyy374, mqlyymsp[-1].minor.mqlyy621, mqlyymsp[0].minor.mqlyy367); }
#line 4391 "./mql.c"
  mqlyymsp[-4].minor.mqlyy568 = mqlyylhsminor.mqlyy568;
        break;
      case 174: /* select_statement ::= select_clause KEY_IN IDENTIFIER with_max_range_clause returning_clause where_clause */
#line 694 "./mql.yxx"
{ mqlyylhsminor.mqlyy568 = new SelectStatement((MQLExecEnv*) pEE, mqlyymsp[-5].minor.mqlyy493, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-2].minor.mqlyy374, mqlyymsp[-1].minor.mqlyy621, mqlyymsp[0].minor.mqlyy367); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 4397 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-4].minor);
  mqlyymsp[-5].minor.mqlyy568 = mqlyylhsminor.mqlyy568;
        break;
      case 175: /* select_clause ::= KEY_SELECT focus_specification opt_OBJECTS */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-2].minor);
#line 700 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy493 = mqlyymsp[-1].minor.mqlyy493; }
#line 4405 "./mql.c"
  mqlyy_destructor(mqlyypParser,239,&mqlyymsp[0].minor);
}
        break;
      case 176: /* focus_specification ::= KEY_FOCUS */
{  mqlyy_destructor(mqlyypParser,81,&mqlyymsp[0].minor);
#line 705 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy493 = kFocus; }
#line 4413 "./mql.c"
}
        break;
      case 177: /* focus_specification ::= KEY_ALL */
{  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[0].minor);
#line 706 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy493 = kAll; }
#line 4420 "./mql.c"
}
        break;
      case 178: /* opt_OBJECTS ::= KEY_OBJECTS */
{  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[0].minor);
#line 711 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 4427 "./mql.c"
}
        break;
      case 180: /* in_clause ::= KEY_IN in_specification */
{  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-1].minor);
#line 718 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy538 = mqlyymsp[0].minor.mqlyy538; mqlyymsp[-1].minor.mqlyy538->setIsFirst(true); }
#line 4434 "./mql.c"
}
        break;
      case 181: /* in_clause ::= */
#line 720 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy538 = new MQLMonadSetElement(1L, MAX_MONAD, 0, true); }
#line 4440 "./mql.c"
        break;
      case 182: /* in_specification ::= monad_set */
      case 379: /* star_monad_set ::= monad_set */ mqlyytestcase(mqlyyruleno==379);
#line 726 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = mqlyymsp[0].minor.mqlyy538; mqlyylhsminor.mqlyy538->setIsFirst(true); }
#line 4446 "./mql.c"
  mqlyymsp[0].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 183: /* in_specification ::= KEY_ALL */
{  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[0].minor);
#line 728 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy538 = new MQLMonadSetElement(1L, MAX_MONAD, 0, true); }
#line 4453 "./mql.c"
}
        break;
      case 184: /* monad_set ::= KEY_OPEN_BRACE monad_set_element_list KEY_CLOSE_BRACE */
{  mqlyy_destructor(mqlyypParser,73,&mqlyymsp[-2].minor);
#line 734 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy538 = mqlyymsp[-1].minor.mqlyy538; mqlyymsp[-2].minor.mqlyy538->setIsFirst(true); }
#line 4460 "./mql.c"
  mqlyy_destructor(mqlyypParser,74,&mqlyymsp[0].minor);
}
        break;
      case 185: /* monad_set_element_list ::= monad_set_element */
#line 740 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = mqlyymsp[0].minor.mqlyy538; }
#line 4467 "./mql.c"
  mqlyymsp[0].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 186: /* monad_set_element_list ::= monad_set_element_list KEY_COMMA monad_set_element */
#line 743 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = mqlyymsp[0].minor.mqlyy538; mqlyylhsminor.mqlyy538->setNext(mqlyymsp[-2].minor.mqlyy538); }
#line 4473 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 187: /* monad_set_element ::= INTEGER */
#line 749 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = new MQLMonadSetElement((monad_m) mqlyymsp[0].minor.mqlyy0->integer, 0, false); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4480 "./mql.c"
  mqlyymsp[0].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 188: /* monad_set_element ::= INTEGER KEY_DASH INTEGER */
#line 751 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = new MQLMonadSetElement((monad_m) mqlyymsp[-2].minor.mqlyy0->integer, (monad_m) mqlyymsp[0].minor.mqlyy0->integer, 0, false); deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4486 "./mql.c"
  mqlyy_destructor(mqlyypParser,77,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 189: /* monad_set_element ::= INTEGER KEY_DASH */
#line 753 "./mql.yxx"
{ mqlyylhsminor.mqlyy538 = new MQLMonadSetElement((monad_m) mqlyymsp[-1].minor.mqlyy0->integer, MAX_MONAD, 0, false); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4493 "./mql.c"
  mqlyy_destructor(mqlyypParser,77,&mqlyymsp[0].minor);
  mqlyymsp[-1].minor.mqlyy538 = mqlyylhsminor.mqlyy538;
        break;
      case 190: /* with_max_range_clause ::= */
#line 759 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy374 = new MaxRange(MAX_MONAD); }
#line 4500 "./mql.c"
        break;
      case 191: /* with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_MAX_M KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-4].minor);
#line 761 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy374 = new MaxRange(MAX_MONAD); }
#line 4506 "./mql.c"
  mqlyy_destructor(mqlyypParser,82,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,83,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 192: /* with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE INTEGER KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-4].minor);
#line 763 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy374 = new MaxRange((monad_m) mqlyymsp[-1].minor.mqlyy0->integer); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4517 "./mql.c"
  mqlyy_destructor(mqlyypParser,82,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 193: /* with_max_range_clause ::= KEY_WITH KEY_MAX KEY_RANGE KEY_FEATURE feature_name KEY_FROM KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-8].minor);
#line 765 "./mql.yxx"
{ mqlyymsp[-8].minor.mqlyy374 = new MaxRange(mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[-4].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[-4].minor.mqlyy0); }
#line 4527 "./mql.c"
  mqlyy_destructor(mqlyypParser,82,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,84,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 194: /* returning_clause ::= */
#line 771 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy621 = new sheaf_return_type_pair(kFullSheaf, ((StringList*) 0)); }
#line 4539 "./mql.c"
        break;
      case 195: /* returning_clause ::= KEY_RETURNING KEY_FULL KEY_SHEAF */
{  mqlyy_destructor(mqlyypParser,85,&mqlyymsp[-2].minor);
#line 773 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy621 = new sheaf_return_type_pair(kFullSheaf, ((StringList*) 0)); }
#line 4545 "./mql.c"
  mqlyy_destructor(mqlyypParser,86,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,87,&mqlyymsp[0].minor);
}
        break;
      case 196: /* returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF */
{  mqlyy_destructor(mqlyypParser,85,&mqlyymsp[-2].minor);
#line 775 "./mql.yxx"
{ StringList *pSL = new StringList(); 
      mqlyymsp[-2].minor.mqlyy621 = new sheaf_return_type_pair(kFlatSheaf, pSL); }
#line 4555 "./mql.c"
  mqlyy_destructor(mqlyypParser,88,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,87,&mqlyymsp[0].minor);
}
        break;
      case 197: /* returning_clause ::= KEY_RETURNING KEY_FLAT KEY_SHEAF KEY_ON object_type_name_list */
{  mqlyy_destructor(mqlyypParser,85,&mqlyymsp[-4].minor);
#line 779 "./mql.yxx"
{ StringList *pSL = new StringList(mqlyymsp[0].minor.mqlyy368); 
      delete mqlyymsp[0].minor.mqlyy368;
      mqlyymsp[-4].minor.mqlyy621 = new sheaf_return_type_pair(kFlatSheaf, pSL); }
#line 4566 "./mql.c"
  mqlyy_destructor(mqlyypParser,88,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,87,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,16,&mqlyymsp[-1].minor);
}
        break;
      case 198: /* using_range_clause ::= */
#line 786 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy222 = 0; }
#line 4575 "./mql.c"
        break;
      case 199: /* using_range_clause ::= KEY_RANGE KEY_ALL */
{  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-1].minor);
#line 788 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy222 = 0; }
#line 4581 "./mql.c"
  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[0].minor);
}
        break;
      case 200: /* using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_COMMA unsigned_integer KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-5].minor);
#line 793 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy222 = new UsingRange(mqlyymsp[-3].minor.mqlyy466, mqlyymsp[-1].minor.mqlyy466); }
#line 4589 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 201: /* using_range_clause ::= KEY_RANGE KEY_OPEN_BRACKET unsigned_integer KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,27,&mqlyymsp[-3].minor);
#line 798 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy222 = new UsingRange(0, mqlyymsp[-1].minor.mqlyy466); }
#line 4599 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 204: /* where_clause ::= KEY_WHERE mql_query */
{  mqlyy_destructor(mqlyypParser,89,&mqlyymsp[-1].minor);
#line 811 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy367 = mqlyymsp[0].minor.mqlyy367; }
#line 4608 "./mql.c"
}
        break;
      case 205: /* select_objects_at_statement ::= KEY_SELECT opt_OBJECTS KEY_AT single_monad_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-6].minor);
#line 821 "./mql.yxx"
{ mqlyymsp[-6].minor.mqlyy568 = new SelectObjectsAtStatement((MQLExecEnv*) pEE, mqlyymsp[-3].minor.mqlyy88, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4615 "./mql.c"
  mqlyy_destructor(mqlyypParser,239,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,90,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 206: /* single_monad_specification ::= KEY_MONAD KEY_EQUALS INTEGER */
{  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
#line 827 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy88 = (monad_m) mqlyymsp[0].minor.mqlyy0->integer; deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4626 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
}
        break;
      case 207: /* select_objects_having_monads_in_statement ::= KEY_SELECT KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN monad_set KEY_OPEN_SQUARE_BRACKET object_type_to_find KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-8].minor);
#line 838 "./mql.yxx"
{ mqlyymsp[-8].minor.mqlyy568 = new SelectObjectsHavingMonadsInStatement((MQLExecEnv*) pEE, mqlyymsp[-3].minor.mqlyy538, *(mqlyymsp[-1].minor.mqlyy0->pString)); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4634 "./mql.c"
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 210: /* choice_object_type_or_all ::= KEY_ALL */
{  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[0].minor);
#line 850 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy0 = newToken(); mqlyymsp[0].minor.mqlyy0->setString(new std::string("all")); }
#line 4647 "./mql.c"
}
        break;
      case 211: /* get_aggregate_features_statement ::= KEY_GET KEY_AGGREGATE KEY_FEATURES aggregate_feature_list KEY_FROM KEY_OBJECTS in_clause using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name feature_constraints KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-11].minor);
#line 864 "./mql.yxx"
{ mqlyymsp[-11].minor.mqlyy568 = new GetAggregateFeaturesStatement((MQLExecEnv*) pEE, mqlyymsp[-8].minor.mqlyy354, mqlyymsp[-5].minor.mqlyy538, mqlyymsp[-4].minor.mqlyy0->extractString(), mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy168); deleteToken(mqlyymsp[-4].minor.mqlyy0); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4654 "./mql.c"
  mqlyy_destructor(mqlyypParser,91,&mqlyymsp[-10].minor);
  mqlyy_destructor(mqlyypParser,92,&mqlyymsp[-9].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 212: /* aggregate_feature_list ::= aggregate_feature */
#line 869 "./mql.yxx"
{ mqlyylhsminor.mqlyy354 = mqlyymsp[0].minor.mqlyy354; }
#line 4666 "./mql.c"
  mqlyymsp[0].minor.mqlyy354 = mqlyylhsminor.mqlyy354;
        break;
      case 213: /* aggregate_feature_list ::= aggregate_feature_list KEY_COMMA aggregate_feature */
#line 873 "./mql.yxx"
{ mqlyylhsminor.mqlyy354 = mqlyymsp[0].minor.mqlyy354; mqlyylhsminor.mqlyy354->setNext(mqlyymsp[-2].minor.mqlyy354); }
#line 4672 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy354 = mqlyylhsminor.mqlyy354;
        break;
      case 214: /* aggregate_feature ::= KEY_MIN KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,93,&mqlyymsp[-3].minor);
#line 878 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy354 = new AggregateFeature(kAFMIN, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4680 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 215: /* aggregate_feature ::= KEY_MAX KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,82,&mqlyymsp[-3].minor);
#line 880 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy354 = new AggregateFeature(kAFMAX, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4689 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 216: /* aggregate_feature ::= KEY_SUM KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,94,&mqlyymsp[-3].minor);
#line 882 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy354 = new AggregateFeature(kAFSUM, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4698 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 217: /* aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET KEY_STAR KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,95,&mqlyymsp[-3].minor);
#line 884 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy354 = new AggregateFeature(kAFCOUNT_ALL); }
#line 4707 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,96,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 218: /* aggregate_feature ::= KEY_COUNT KEY_OPEN_BRACKET aggregate_feature_comparison KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,95,&mqlyymsp[-3].minor);
#line 887 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy354 = new AggregateFeature(kAFCOUNT_FEATURE_COMPARISON, mqlyymsp[-1].minor.mqlyy526); }
#line 4717 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 219: /* aggregate_feature_comparison ::= feature_name comparison_operator value */
      case 341: /* feature_comparison ::= feature_name comparison_operator value */ mqlyytestcase(mqlyyruleno==341);
#line 892 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-2].minor.mqlyy0->extractString(), 0, mqlyymsp[-1].minor.mqlyy384, mqlyymsp[0].minor.mqlyy300); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4726 "./mql.c"
  mqlyymsp[-2].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 220: /* aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
#line 894 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, mqlyymsp[-3].minor.mqlyy384, new StringList(mqlyymsp[-1].minor.mqlyy368)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy368; }
#line 4732 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 221: /* aggregate_feature_comparison ::= feature_name comparison_operator KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
#line 896 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, mqlyymsp[-3].minor.mqlyy384, new IntegerList(mqlyymsp[-1].minor.mqlyy183)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy183; }
#line 4740 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 222: /* get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-9].minor);
#line 912 "./mql.yxx"
{ mqlyymsp[-9].minor.mqlyy568 = new GetObjectsHavingMonadsInStatement((MQLExecEnv*) pEE, mqlyymsp[-4].minor.mqlyy538, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[-3].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 4749 "./mql.c"
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-8].minor);
  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 223: /* get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET KEY_ALL KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-11].minor);
#line 920 "./mql.yxx"
{ mqlyymsp[-11].minor.mqlyy568 = new GetObjectsHavingMonadsInStatement((MQLExecEnv*) pEE, mqlyymsp[-6].minor.mqlyy538, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-5].minor.mqlyy0->extractString(), true); deleteToken(mqlyymsp[-3].minor.mqlyy0); deleteToken(mqlyymsp[-5].minor.mqlyy0); }
#line 4762 "./mql.c"
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-10].minor);
  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-9].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-8].minor);
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,69,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 224: /* get_objects_having_monads_in_statement ::= KEY_GET KEY_OBJECTS KEY_HAVING KEY_MONADS KEY_IN in_specification using_monad_feature KEY_OPEN_SQUARE_BRACKET object_type_name KEY_GET feature_list KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-11].minor);
#line 928 "./mql.yxx"
{ mqlyymsp[-11].minor.mqlyy568 = new GetObjectsHavingMonadsInStatement((MQLExecEnv*) pEE, mqlyymsp[-6].minor.mqlyy538, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-5].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy218); deleteToken(mqlyymsp[-3].minor.mqlyy0); deleteToken(mqlyymsp[-5].minor.mqlyy0); }
#line 4777 "./mql.c"
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-10].minor);
  mqlyy_destructor(mqlyypParser,31,&mqlyymsp[-9].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-8].minor);
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 225: /* using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE IDENTIFIER */
{  mqlyy_destructor(mqlyypParser,10,&mqlyymsp[-3].minor);
#line 932 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 4791 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,84,&mqlyymsp[-1].minor);
}
        break;
      case 226: /* using_monad_feature ::= KEY_USING KEY_MONAD KEY_FEATURE KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,10,&mqlyymsp[-3].minor);
#line 933 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy0 = newToken(); mqlyymsp[-3].minor.mqlyy0->setString(new std::string("monads")); }
#line 4800 "./mql.c"
  mqlyy_destructor(mqlyypParser,30,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,84,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
}
        break;
      case 227: /* using_monad_feature ::= */
#line 934 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy0 = newToken(); mqlyymsp[1].minor.mqlyy0->setString(new std::string("monads")); }
#line 4809 "./mql.c"
        break;
      case 228: /* select_object_types_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-2].minor);
#line 941 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy568 = new SelectObjectTypesStatement((MQLExecEnv*) pEE); }
#line 4815 "./mql.c"
  mqlyy_destructor(mqlyypParser,190,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,21,&mqlyymsp[0].minor);
}
        break;
      case 229: /* select_features_statement ::= KEY_SELECT KEY_FEATURES KEY_FROM opt_OBJECTYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-6].minor);
#line 948 "./mql.yxx"
{ mqlyymsp[-6].minor.mqlyy568 = new SelectFeaturesStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 4824 "./mql.c"
  mqlyy_destructor(mqlyypParser,92,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,258,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 230: /* get_set_from_feature_statement ::= KEY_GET KEY_SET KEY_FROM KEY_FEATURE feature_name KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-7].minor);
#line 955 "./mql.yxx"
{ mqlyymsp[-7].minor.mqlyy568 = new GetSetFromFeatureStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy0->extractString(), mqlyymsp[-3].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 4836 "./mql.c"
  mqlyy_destructor(mqlyypParser,46,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,84,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 231: /* opt_OBJECTYPE ::= KEY_OBJECT KEY_TYPE */
{  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-1].minor);
#line 960 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy124=0; }
#line 4848 "./mql.c"
  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[0].minor);
}
        break;
      case 232: /* opt_OBJECTYPE ::= KEY_TYPE */
{  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[0].minor);
#line 961 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124=0; }
#line 4856 "./mql.c"
}
        break;
      case 233: /* opt_OBJECTYPE ::= */
#line 962 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy124=0; }
#line 4862 "./mql.c"
        break;
      case 234: /* select_enumerations_statement ::= KEY_SELECT KEY_ENUMERATIONS */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-1].minor);
#line 968 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new SelectEnumerationsStatement((MQLExecEnv*) pEE); }
#line 4868 "./mql.c"
  mqlyy_destructor(mqlyypParser,97,&mqlyymsp[0].minor);
}
        break;
      case 235: /* select_enumeration_constants_statement ::= KEY_SELECT choice_ENUM_ERATION KEY_CONSTANTS KEY_FROM opt_ENUM_ERATION enumeration_name */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-5].minor);
#line 977 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new SelectEnumerationConstantsStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4876 "./mql.c"
  mqlyy_destructor(mqlyypParser,219,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,98,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,259,&mqlyymsp[-1].minor);
}
        break;
      case 236: /* opt_ENUM_ERATION ::= KEY_ENUM */
{  mqlyy_destructor(mqlyypParser,76,&mqlyymsp[0].minor);
#line 982 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 4887 "./mql.c"
}
        break;
      case 237: /* opt_ENUM_ERATION ::= KEY_ENUMERATION */
{  mqlyy_destructor(mqlyypParser,75,&mqlyymsp[0].minor);
#line 983 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 4894 "./mql.c"
}
        break;
      case 238: /* opt_ENUM_ERATION ::= */
#line 984 "./mql.yxx"
{mqlyymsp[1].minor.mqlyy124=0;}
#line 4900 "./mql.c"
        break;
      case 239: /* select_object_types_which_use_enum_statement ::= KEY_SELECT opt_OBJECT KEY_TYPES KEY_USING choice_ENUM_ERATION enumeration_name */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-5].minor);
#line 993 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new SelectObjectTypesUsingEnumerationStatement((MQLExecEnv*) pEE, mqlyymsp[0].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4906 "./mql.c"
  mqlyy_destructor(mqlyypParser,190,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,21,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,10,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,219,&mqlyymsp[-1].minor);
}
        break;
      case 240: /* select_min_m_statement ::= KEY_SELECT KEY_MIN_M */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-1].minor);
#line 999 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new SelectMinMStatement((MQLExecEnv*) pEE); }
#line 4917 "./mql.c"
  mqlyy_destructor(mqlyypParser,99,&mqlyymsp[0].minor);
}
        break;
      case 241: /* select_max_m_statement ::= KEY_SELECT KEY_MAX_M */
{  mqlyy_destructor(mqlyypParser,67,&mqlyymsp[-1].minor);
#line 1005 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy568 = new SelectMaxMStatement((MQLExecEnv*) pEE); }
#line 4925 "./mql.c"
  mqlyy_destructor(mqlyypParser,83,&mqlyymsp[0].minor);
}
        break;
      case 242: /* create_object_from_monads_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification object_creation_specification */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-5].minor);
#line 1014 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new CreateObjectFromMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy538, mqlyymsp[-1].minor.mqlyy600, mqlyymsp[0].minor.mqlyy389); }
#line 4933 "./mql.c"
  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-3].minor);
}
        break;
      case 243: /* monad_specification ::= KEY_MONADS KEY_EQUALS monad_set */
{  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-2].minor);
#line 1019 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy538 = mqlyymsp[0].minor.mqlyy538; mqlyymsp[-2].minor.mqlyy538->setIsFirst(true); }
#line 4942 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
}
        break;
      case 244: /* with_id_d_specification ::= KEY_WITH KEY_ID_D KEY_EQUALS id_d_const */
{  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-3].minor);
#line 1024 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy600 = mqlyymsp[0].minor.mqlyy600; }
#line 4950 "./mql.c"
  mqlyy_destructor(mqlyypParser,45,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
}
        break;
      case 245: /* with_id_d_specification ::= */
#line 1026 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy600 = NIL; }
#line 4958 "./mql.c"
        break;
      case 246: /* id_d_const ::= INTEGER */
#line 1032 "./mql.yxx"
{ mqlyylhsminor.mqlyy600 = (id_d_t) mqlyymsp[0].minor.mqlyy0->integer; deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 4963 "./mql.c"
  mqlyymsp[0].minor.mqlyy600 = mqlyylhsminor.mqlyy600;
        break;
      case 247: /* id_d_const ::= KEY_NIL */
{  mqlyy_destructor(mqlyypParser,78,&mqlyymsp[0].minor);
#line 1034 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy600 = NIL; }
#line 4970 "./mql.c"
}
        break;
      case 248: /* object_creation_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
      case 281: /* object_update_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */ mqlyytestcase(mqlyyruleno==281);
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
#line 1042 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy389 = new ObjectSpec(mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy432); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 4978 "./mql.c"
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 249: /* opt_list_of_feature_assignments ::= list_of_feature_assignments */
      case 251: /* list_of_feature_assignments ::= feature_assignment */ mqlyytestcase(mqlyyruleno==251);
#line 1048 "./mql.yxx"
{ mqlyylhsminor.mqlyy432 = mqlyymsp[0].minor.mqlyy432; }
#line 4986 "./mql.c"
  mqlyymsp[0].minor.mqlyy432 = mqlyylhsminor.mqlyy432;
        break;
      case 250: /* opt_list_of_feature_assignments ::= */
#line 1050 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy432 = 0; }
#line 4992 "./mql.c"
        break;
      case 252: /* list_of_feature_assignments ::= list_of_feature_assignments feature_assignment */
#line 1059 "./mql.yxx"
{ mqlyylhsminor.mqlyy432 = mqlyymsp[0].minor.mqlyy432; mqlyylhsminor.mqlyy432->setNext(mqlyymsp[-1].minor.mqlyy432); }
#line 4997 "./mql.c"
  mqlyymsp[-1].minor.mqlyy432 = mqlyylhsminor.mqlyy432;
        break;
      case 253: /* feature_assignment ::= feature_name KEY_ASSIGN expression KEY_SEMICOLON */
#line 1065 "./mql.yxx"
{ mqlyylhsminor.mqlyy432 = new FeatureAssignment(mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy475, 0); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5003 "./mql.c"
  mqlyy_destructor(mqlyypParser,100,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,39,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy432 = mqlyylhsminor.mqlyy432;
        break;
      case 255: /* feature_name ::= KEY_MONADS */
{  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[0].minor);
#line 1071 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy0 = newToken(); mqlyymsp[0].minor.mqlyy0->setString(new std::string("monads")); }
#line 5012 "./mql.c"
}
        break;
      case 256: /* expression ::= signed_integer */
#line 1076 "./mql.yxx"
{ mqlyylhsminor.mqlyy475 = new Expression(mqlyymsp[0].minor.mqlyy466); }
#line 5018 "./mql.c"
  mqlyymsp[0].minor.mqlyy475 = mqlyylhsminor.mqlyy475;
        break;
      case 257: /* expression ::= STRING */
#line 1078 "./mql.yxx"
{ mqlyylhsminor.mqlyy475 = new Expression(mqlyymsp[0].minor.mqlyy0->extractString(), kExprString); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5024 "./mql.c"
  mqlyymsp[0].minor.mqlyy475 = mqlyylhsminor.mqlyy475;
        break;
      case 258: /* expression ::= IDENTIFIER */
#line 1080 "./mql.yxx"
{ mqlyylhsminor.mqlyy475 = new Expression(mqlyymsp[0].minor.mqlyy0->extractString(), kExprIdentifier); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5030 "./mql.c"
  mqlyymsp[0].minor.mqlyy475 = mqlyylhsminor.mqlyy475;
        break;
      case 259: /* expression ::= monad_set */
#line 1082 "./mql.yxx"
{ mqlyylhsminor.mqlyy475 = new Expression(mqlyymsp[0].minor.mqlyy538); }
#line 5036 "./mql.c"
  mqlyymsp[0].minor.mqlyy475 = mqlyylhsminor.mqlyy475;
        break;
      case 260: /* expression ::= KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-1].minor);
#line 1084 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy475 = new Expression(); /* empty list */ }
#line 5043 "./mql.c"
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 261: /* expression ::= KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
#line 1086 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy475 = new Expression(new IntegerList(mqlyymsp[-1].minor.mqlyy183)); delete mqlyymsp[-1].minor.mqlyy183; }
#line 5051 "./mql.c"
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 262: /* expression ::= KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
#line 1088 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy475 = new Expression(new StringList(mqlyymsp[-1].minor.mqlyy368), kExprListOfIdentifier); delete mqlyymsp[-1].minor.mqlyy368; }
#line 5059 "./mql.c"
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 263: /* list_of_integer ::= signed_integer */
#line 1094 "./mql.yxx"
{ mqlyylhsminor.mqlyy183 = new IntegerListNode(mqlyymsp[0].minor.mqlyy466, 0); }
#line 5066 "./mql.c"
  mqlyymsp[0].minor.mqlyy183 = mqlyylhsminor.mqlyy183;
        break;
      case 264: /* list_of_integer ::= list_of_integer KEY_COMMA signed_integer */
#line 1097 "./mql.yxx"
{ mqlyylhsminor.mqlyy183 = new IntegerListNode(mqlyymsp[0].minor.mqlyy466, mqlyymsp[-2].minor.mqlyy183); mqlyymsp[-2].minor.mqlyy183->setNext(mqlyylhsminor.mqlyy183); }
#line 5072 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy183 = mqlyylhsminor.mqlyy183;
        break;
      case 267: /* create_object_from_id_ds_statement ::= KEY_CREATE KEY_OBJECT KEY_FROM id_ds_specification with_id_d_specification object_creation_specification */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-5].minor);
#line 1115 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy568 = new CreateObjectFromID_DsStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy243, mqlyymsp[-1].minor.mqlyy600, mqlyymsp[0].minor.mqlyy389); }
#line 5080 "./mql.c"
  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-3].minor);
}
        break;
      case 268: /* id_ds_specification ::= choice_number_ID_DS KEY_EQUALS id_d_list */
{  mqlyy_destructor(mqlyypParser,266,&mqlyymsp[-2].minor);
#line 1121 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy243 = mqlyymsp[0].minor.mqlyy243; }
#line 5089 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-1].minor);
}
        break;
      case 269: /* choice_number_ID_DS ::= KEY_ID_D */
{  mqlyy_destructor(mqlyypParser,45,&mqlyymsp[0].minor);
#line 1126 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5097 "./mql.c"
}
        break;
      case 270: /* choice_number_ID_DS ::= KEY_ID_DS */
{  mqlyy_destructor(mqlyypParser,101,&mqlyymsp[0].minor);
#line 1127 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5104 "./mql.c"
}
        break;
      case 271: /* id_d_list ::= id_d */
#line 1133 "./mql.yxx"
{ mqlyylhsminor.mqlyy243 = mqlyymsp[0].minor.mqlyy243; }
#line 5110 "./mql.c"
  mqlyymsp[0].minor.mqlyy243 = mqlyylhsminor.mqlyy243;
        break;
      case 272: /* id_d_list ::= id_d_list KEY_COMMA id_d */
#line 1135 "./mql.yxx"
{ mqlyylhsminor.mqlyy243 = mqlyymsp[0].minor.mqlyy243; mqlyylhsminor.mqlyy243->setNext(mqlyymsp[-2].minor.mqlyy243); }
#line 5116 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy243 = mqlyylhsminor.mqlyy243;
        break;
      case 273: /* id_d ::= id_d_const */
#line 1140 "./mql.yxx"
{ mqlyylhsminor.mqlyy243 = new ID_D(mqlyymsp[0].minor.mqlyy600, 0); }
#line 5123 "./mql.c"
  mqlyymsp[0].minor.mqlyy243 = mqlyylhsminor.mqlyy243;
        break;
      case 274: /* create_objects_statement ::= KEY_CREATE KEY_OBJECTS KEY_WITH KEY_OBJECT KEY_TYPE KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET object_creation_list */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-8].minor);
#line 1152 "./mql.yxx"
{ mqlyymsp[-8].minor.mqlyy568 = new CreateObjectsStatement((MQLExecEnv*) pEE, mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy481); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 5130 "./mql.c"
  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[-7].minor);
  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,20,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[-1].minor);
}
        break;
      case 275: /* object_creation_list ::= object_creation_no_object_type */
#line 1159 "./mql.yxx"
{ mqlyylhsminor.mqlyy481 = mqlyymsp[0].minor.mqlyy481; }
#line 5142 "./mql.c"
  mqlyymsp[0].minor.mqlyy481 = mqlyylhsminor.mqlyy481;
        break;
      case 276: /* object_creation_list ::= object_creation_list object_creation_no_object_type */
#line 1162 "./mql.yxx"
{ mqlyylhsminor.mqlyy481 = mqlyymsp[0].minor.mqlyy481; mqlyylhsminor.mqlyy481->setNext(mqlyymsp[-1].minor.mqlyy481); }
#line 5148 "./mql.c"
  mqlyymsp[-1].minor.mqlyy481 = mqlyylhsminor.mqlyy481;
        break;
      case 277: /* object_creation_no_object_type ::= KEY_CREATE KEY_OBJECT KEY_FROM monad_specification with_id_d_specification KEY_OPEN_SQUARE_BRACKET opt_list_of_feature_assignments KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,2,&mqlyymsp[-7].minor);
#line 1174 "./mql.yxx"
{ mqlyymsp[-7].minor.mqlyy481 = new ObjectSpecNoOT(mqlyymsp[-4].minor.mqlyy538, mqlyymsp[-3].minor.mqlyy600, mqlyymsp[-1].minor.mqlyy432, 0); }
#line 5155 "./mql.c"
  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 278: /* update_objects_by_monads_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY monad_specification object_update_specification */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-4].minor);
#line 1183 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy568 = new UpdateObjectsByMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy538, mqlyymsp[0].minor.mqlyy389); }
#line 5166 "./mql.c"
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,102,&mqlyymsp[-2].minor);
}
        break;
      case 279: /* choice_number_OBJECTS ::= KEY_OBJECT */
{  mqlyy_destructor(mqlyypParser,17,&mqlyymsp[0].minor);
#line 1188 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5175 "./mql.c"
}
        break;
      case 280: /* choice_number_OBJECTS ::= KEY_OBJECTS */
{  mqlyy_destructor(mqlyypParser,28,&mqlyymsp[0].minor);
#line 1189 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5182 "./mql.c"
}
        break;
      case 282: /* update_objects_by_id_ds_statement ::= KEY_UPDATE choice_number_OBJECTS KEY_BY id_ds_specification object_update_specification */
{  mqlyy_destructor(mqlyypParser,57,&mqlyymsp[-4].minor);
#line 1209 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy568 = new UpdateObjectsByID_DsStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy243, mqlyymsp[0].minor.mqlyy389); }
#line 5189 "./mql.c"
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,102,&mqlyymsp[-2].minor);
}
        break;
      case 283: /* delete_objects_by_monads_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY monad_specification object_deletion_specification */
{  mqlyy_destructor(mqlyypParser,61,&mqlyymsp[-4].minor);
#line 1219 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy568 = new DeleteObjectsByMonadsStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy538, *(mqlyymsp[0].minor.mqlyy0->pString)); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5198 "./mql.c"
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,102,&mqlyymsp[-2].minor);
}
        break;
      case 284: /* object_deletion_specification ::= KEY_OPEN_SQUARE_BRACKET object_type_name_to_delete KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
#line 1228 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy0 = mqlyymsp[-1].minor.mqlyy0; }
#line 5207 "./mql.c"
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 286: /* delete_objects_by_id_ds_statement ::= KEY_DELETE choice_number_OBJECTS KEY_BY id_ds_specification object_deletion_specification */
{  mqlyy_destructor(mqlyypParser,61,&mqlyymsp[-4].minor);
#line 1244 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy568 = new DeleteObjectsByID_DsStatement((MQLExecEnv*) pEE, mqlyymsp[-1].minor.mqlyy243, *(mqlyymsp[0].minor.mqlyy0->pString)); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5215 "./mql.c"
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,102,&mqlyymsp[-2].minor);
}
        break;
      case 287: /* get_features_statement ::= KEY_GET choice_number_FEATURES feature_list KEY_FROM choice_number_OBJECTS KEY_WITH id_ds_specification KEY_OPEN_SQUARE_BRACKET object_type_name KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-9].minor);
#line 1256 "./mql.yxx"
{ mqlyymsp[-9].minor.mqlyy568 = new GetFeaturesStatement((MQLExecEnv*) pEE, mqlyymsp[-7].minor.mqlyy218, mqlyymsp[-3].minor.mqlyy243, mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 5224 "./mql.c"
  mqlyy_destructor(mqlyypParser,274,&mqlyymsp[-8].minor);
  mqlyy_destructor(mqlyypParser,51,&mqlyymsp[-6].minor);
  mqlyy_destructor(mqlyypParser,211,&mqlyymsp[-5].minor);
  mqlyy_destructor(mqlyypParser,8,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 288: /* choice_number_FEATURES ::= KEY_FEATURE */
{  mqlyy_destructor(mqlyypParser,84,&mqlyymsp[0].minor);
#line 1261 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5237 "./mql.c"
}
        break;
      case 289: /* choice_number_FEATURES ::= KEY_FEATURES */
{  mqlyy_destructor(mqlyypParser,92,&mqlyymsp[0].minor);
#line 1262 "./mql.yxx"
{mqlyymsp[0].minor.mqlyy124=0;}
#line 5244 "./mql.c"
}
        break;
      case 290: /* feature_list ::= feature_list_member */
#line 1267 "./mql.yxx"
{ mqlyylhsminor.mqlyy218 = mqlyymsp[0].minor.mqlyy218; }
#line 5250 "./mql.c"
  mqlyymsp[0].minor.mqlyy218 = mqlyylhsminor.mqlyy218;
        break;
      case 291: /* feature_list ::= feature_list KEY_COMMA feature_list_member */
#line 1269 "./mql.yxx"
{ mqlyylhsminor.mqlyy218 = mqlyymsp[0].minor.mqlyy218; mqlyylhsminor.mqlyy218->setNext(mqlyymsp[-2].minor.mqlyy218); }
#line 5256 "./mql.c"
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy218 = mqlyylhsminor.mqlyy218;
        break;
      case 292: /* feature_list_member ::= feature_name */
#line 1274 "./mql.yxx"
{ mqlyylhsminor.mqlyy218 = new GrammarFeature(mqlyymsp[0].minor.mqlyy0->extractString(), 0, 0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5263 "./mql.c"
  mqlyymsp[0].minor.mqlyy218 = mqlyylhsminor.mqlyy218;
        break;
      case 293: /* feature_list_member ::= feature_name KEY_OPEN_BRACKET IDENTIFIER KEY_CLOSE_BRACKET */
#line 1276 "./mql.yxx"
{ mqlyylhsminor.mqlyy218 = new GrammarFeature(mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy0->extractString(), 0); deleteToken(mqlyymsp[-3].minor.mqlyy0); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 5269 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy218 = mqlyylhsminor.mqlyy218;
        break;
      case 294: /* feature_list_member ::= feature_name KEY_OPEN_BRACKET KEY_MONADS KEY_CLOSE_BRACKET */
#line 1278 "./mql.yxx"
{ mqlyylhsminor.mqlyy218 = new GrammarFeature(mqlyymsp[-3].minor.mqlyy0->extractString(), new std::string("monads"), 0); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5277 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,34,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy218 = mqlyylhsminor.mqlyy218;
        break;
      case 295: /* quit_statement ::= KEY_QUIT */
{  mqlyy_destructor(mqlyypParser,103,&mqlyymsp[0].minor);
#line 1284 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy568 = new QuitStatement((MQLExecEnv*) pEE); }
#line 5287 "./mql.c"
}
        break;
      case 296: /* mql_query ::= topograph */
#line 1290 "./mql.yxx"
{ mqlyylhsminor.mqlyy367 = mqlyymsp[0].minor.mqlyy367; }
#line 5293 "./mql.c"
  mqlyymsp[0].minor.mqlyy367 = mqlyylhsminor.mqlyy367;
        break;
      case 297: /* topograph ::= blocks */
#line 1296 "./mql.yxx"
{ mqlyylhsminor.mqlyy367 = new Topograph(mqlyymsp[0].minor.mqlyy545); }
#line 5299 "./mql.c"
  mqlyymsp[0].minor.mqlyy367 = mqlyylhsminor.mqlyy367;
        break;
      case 298: /* blocks ::= using_range_clause block_string */
#line 1302 "./mql.yxx"
{ mqlyylhsminor.mqlyy545 = new Blocks(mqlyymsp[0].minor.mqlyy421, mqlyymsp[-1].minor.mqlyy222); }
#line 5305 "./mql.c"
  mqlyymsp[-1].minor.mqlyy545 = mqlyylhsminor.mqlyy545;
        break;
      case 299: /* blocks ::= using_range_clause unordered_group */
#line 1304 "./mql.yxx"
{ mqlyylhsminor.mqlyy545 = new Blocks(mqlyymsp[0].minor.mqlyy128, mqlyymsp[-1].minor.mqlyy222); }
#line 5311 "./mql.c"
  mqlyymsp[-1].minor.mqlyy545 = mqlyylhsminor.mqlyy545;
        break;
      case 300: /* block_string0 ::= block */
#line 1310 "./mql.yxx"
{ mqlyylhsminor.mqlyy541 = new BlockString0(mqlyymsp[0].minor.mqlyy534); }
#line 5317 "./mql.c"
  mqlyymsp[0].minor.mqlyy541 = mqlyylhsminor.mqlyy541;
        break;
      case 301: /* block_string0 ::= KEY_OPEN_SQUARE_BRACKET block_string KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-2].minor);
#line 1312 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy541 = new BlockString0(mqlyymsp[-1].minor.mqlyy421); }
#line 5324 "./mql.c"
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 302: /* block_string1 ::= block_string0 */
#line 1317 "./mql.yxx"
{ mqlyylhsminor.mqlyy594 = new BlockString1(mqlyymsp[0].minor.mqlyy541); }
#line 5331 "./mql.c"
  mqlyymsp[0].minor.mqlyy594 = mqlyylhsminor.mqlyy594;
        break;
      case 303: /* block_string1 ::= block_string0 KEY_STAR star_monad_set */
#line 1319 "./mql.yxx"
{ mqlyylhsminor.mqlyy594 = new BlockString1(mqlyymsp[-2].minor.mqlyy541, mqlyymsp[0].minor.mqlyy538); }
#line 5337 "./mql.c"
  mqlyy_destructor(mqlyypParser,96,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy594 = mqlyylhsminor.mqlyy594;
        break;
      case 304: /* block_string2 ::= block_string1 */
#line 1324 "./mql.yxx"
{ mqlyylhsminor.mqlyy23 = new BlockString2(mqlyymsp[0].minor.mqlyy594); }
#line 5344 "./mql.c"
  mqlyymsp[0].minor.mqlyy23 = mqlyylhsminor.mqlyy23;
        break;
      case 305: /* block_string2 ::= block_string1 block_string2 */
#line 1326 "./mql.yxx"
{ mqlyylhsminor.mqlyy23 = new BlockString2(mqlyymsp[-1].minor.mqlyy594, mqlyymsp[0].minor.mqlyy23, false); }
#line 5350 "./mql.c"
  mqlyymsp[-1].minor.mqlyy23 = mqlyylhsminor.mqlyy23;
        break;
      case 306: /* block_string2 ::= block_string1 KEY_EXCLAMATION block_string2 */
#line 1329 "./mql.yxx"
{ mqlyylhsminor.mqlyy23 = new BlockString2(mqlyymsp[-2].minor.mqlyy594, mqlyymsp[0].minor.mqlyy23, true); }
#line 5356 "./mql.c"
  mqlyy_destructor(mqlyypParser,104,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy23 = mqlyylhsminor.mqlyy23;
        break;
      case 307: /* block_string ::= block_string2 */
#line 1334 "./mql.yxx"
{ mqlyylhsminor.mqlyy421 = new BlockString(mqlyymsp[0].minor.mqlyy23); }
#line 5363 "./mql.c"
  mqlyymsp[0].minor.mqlyy421 = mqlyylhsminor.mqlyy421;
        break;
      case 308: /* block_string ::= block_string2 KEY_OR block_string */
#line 1336 "./mql.yxx"
{ mqlyylhsminor.mqlyy421 = new BlockString(mqlyymsp[-2].minor.mqlyy23, mqlyymsp[0].minor.mqlyy421); }
#line 5369 "./mql.c"
  mqlyy_destructor(mqlyypParser,105,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy421 = mqlyylhsminor.mqlyy421;
        break;
      case 309: /* notexist ::= KEY_NOTEXIST */
{  mqlyy_destructor(mqlyypParser,106,&mqlyymsp[0].minor);
#line 1341 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 5377 "./mql.c"
}
        break;
      case 310: /* notexist ::= KEY_NOTEXISTS */
{  mqlyy_destructor(mqlyypParser,107,&mqlyymsp[0].minor);
#line 1342 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy124 = 0; }
#line 5384 "./mql.c"
}
        break;
      case 311: /* object_reference_declaration ::= */
      case 313: /* mark_declaration ::= */ mqlyytestcase(mqlyyruleno==313);
#line 1347 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy0 = newToken(); mqlyymsp[1].minor.mqlyy0->setString(new std::string()); }
#line 5391 "./mql.c"
        break;
      case 312: /* object_reference_declaration ::= KEY_AS object_reference */
{  mqlyy_destructor(mqlyypParser,108,&mqlyymsp[-1].minor);
#line 1348 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy0 = mqlyymsp[0].minor.mqlyy0; }
#line 5397 "./mql.c"
}
        break;
      case 316: /* retrieval ::= */
#line 1363 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy540 = kRetrieve; }
#line 5403 "./mql.c"
        break;
      case 317: /* retrieval ::= KEY_NORETRIEVE */
      case 382: /* gap_retrieval ::= KEY_NORETRIEVE */ mqlyytestcase(mqlyyruleno==382);
{  mqlyy_destructor(mqlyypParser,110,&mqlyymsp[0].minor);
#line 1364 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy540 = kNoRetrieve; }
#line 5410 "./mql.c"
}
        break;
      case 318: /* retrieval ::= KEY_RETRIEVE */
      case 383: /* gap_retrieval ::= KEY_RETRIEVE */ mqlyytestcase(mqlyyruleno==383);
{  mqlyy_destructor(mqlyypParser,111,&mqlyymsp[0].minor);
#line 1365 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy540 = kRetrieve; }
#line 5418 "./mql.c"
}
        break;
      case 319: /* retrieval ::= KEY_FOCUS */
      case 384: /* gap_retrieval ::= KEY_FOCUS */ mqlyytestcase(mqlyyruleno==384);
{  mqlyy_destructor(mqlyypParser,81,&mqlyymsp[0].minor);
#line 1366 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy540 = kRetrieveFocus; }
#line 5426 "./mql.c"
}
        break;
      case 320: /* firstlast ::= */
#line 1370 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy546 = kNoFirstLast; }
#line 5432 "./mql.c"
        break;
      case 321: /* firstlast ::= KEY_FIRST */
{  mqlyy_destructor(mqlyypParser,33,&mqlyymsp[0].minor);
#line 1371 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy546 = kFirst; }
#line 5438 "./mql.c"
}
        break;
      case 322: /* firstlast ::= KEY_LAST */
{  mqlyy_destructor(mqlyypParser,36,&mqlyymsp[0].minor);
#line 1372 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy546 = kLast; }
#line 5445 "./mql.c"
}
        break;
      case 323: /* firstlast ::= KEY_FIRST KEY_AND KEY_LAST */
{  mqlyy_destructor(mqlyypParser,33,&mqlyymsp[-2].minor);
#line 1373 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy546 = kFirstAndLast; }
#line 5452 "./mql.c"
  mqlyy_destructor(mqlyypParser,35,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,36,&mqlyymsp[0].minor);
}
        break;
      case 324: /* monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET monad_set_name KEY_COMMA universe_or_substrate KEY_CLOSE_BRACKET */
#line 1378 "./mql.yxx"
{ mqlyylhsminor.mqlyy409 = new MonadSetRelationClause(mqlyymsp[-5].minor.mqlyy248, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy397); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5460 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,71,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-5].minor.mqlyy409 = mqlyylhsminor.mqlyy409;
        break;
      case 325: /* monad_set_relation_clause ::= monad_set_relation_operation KEY_OPEN_BRACKET universe_or_substrate KEY_CLOSE_BRACKET */
#line 1380 "./mql.yxx"
{ mqlyylhsminor.mqlyy409 = new MonadSetRelationClause(mqlyymsp[-3].minor.mqlyy248, new std::string("monads"), mqlyymsp[-1].minor.mqlyy397); }
#line 5469 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy409 = mqlyylhsminor.mqlyy409;
        break;
      case 326: /* monad_set_relation_clause ::= */
#line 1382 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy409 = new MonadSetRelationClause(kMSROPartOf, new std::string("monads"), kMSNSubstrate); }
#line 5477 "./mql.c"
        break;
      case 327: /* monad_set_relation_operation ::= KEY_PART_OF */
{  mqlyy_destructor(mqlyypParser,112,&mqlyymsp[0].minor);
#line 1387 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy248 = kMSROPartOf; }
#line 5483 "./mql.c"
}
        break;
      case 328: /* monad_set_relation_operation ::= KEY_STARTS_IN */
{  mqlyy_destructor(mqlyypParser,113,&mqlyymsp[0].minor);
#line 1389 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy248 = kMSROStartsIn; }
#line 5490 "./mql.c"
}
        break;
      case 329: /* monad_set_relation_operation ::= KEY_OVERLAP */
{  mqlyy_destructor(mqlyypParser,114,&mqlyymsp[0].minor);
#line 1391 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy248 = kMSROOverlap; }
#line 5497 "./mql.c"
}
        break;
      case 330: /* universe_or_substrate ::= KEY_UNIVERSE */
{  mqlyy_destructor(mqlyypParser,115,&mqlyymsp[0].minor);
#line 1397 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy397 = kMSNUniverse; }
#line 5504 "./mql.c"
}
        break;
      case 331: /* universe_or_substrate ::= KEY_SUBSTRATE */
{  mqlyy_destructor(mqlyypParser,116,&mqlyymsp[0].minor);
#line 1399 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy397 = kMSNSubstrate; }
#line 5511 "./mql.c"
}
        break;
      case 332: /* feature_constraints ::= */
#line 1404 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy168 = 0; }
#line 5517 "./mql.c"
        break;
      case 333: /* feature_constraints ::= ffeatures */
#line 1405 "./mql.yxx"
{ mqlyylhsminor.mqlyy168 = mqlyymsp[0].minor.mqlyy168; }
#line 5522 "./mql.c"
  mqlyymsp[0].minor.mqlyy168 = mqlyylhsminor.mqlyy168;
        break;
      case 334: /* ffeatures ::= fterm */
#line 1410 "./mql.yxx"
{ mqlyylhsminor.mqlyy168 = new FFeatures(mqlyymsp[0].minor.mqlyy1); }
#line 5528 "./mql.c"
  mqlyymsp[0].minor.mqlyy168 = mqlyylhsminor.mqlyy168;
        break;
      case 335: /* ffeatures ::= ffeatures KEY_OR fterm */
#line 1411 "./mql.yxx"
{ mqlyylhsminor.mqlyy168 = new FFeatures(mqlyymsp[-2].minor.mqlyy168, mqlyymsp[0].minor.mqlyy1); }
#line 5534 "./mql.c"
  mqlyy_destructor(mqlyypParser,105,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy168 = mqlyylhsminor.mqlyy168;
        break;
      case 336: /* fterm ::= ffactor */
#line 1416 "./mql.yxx"
{ mqlyylhsminor.mqlyy1 = new FTerm(mqlyymsp[0].minor.mqlyy108); }
#line 5541 "./mql.c"
  mqlyymsp[0].minor.mqlyy1 = mqlyylhsminor.mqlyy1;
        break;
      case 337: /* fterm ::= fterm KEY_AND ffactor */
#line 1417 "./mql.yxx"
{ mqlyylhsminor.mqlyy1 = new FTerm(mqlyymsp[-2].minor.mqlyy1, mqlyymsp[0].minor.mqlyy108); }
#line 5547 "./mql.c"
  mqlyy_destructor(mqlyypParser,35,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy1 = mqlyylhsminor.mqlyy1;
        break;
      case 338: /* ffactor ::= KEY_NOT ffactor */
{  mqlyy_destructor(mqlyypParser,49,&mqlyymsp[-1].minor);
#line 1422 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy108 = new FFactor(mqlyymsp[0].minor.mqlyy108); }
#line 5555 "./mql.c"
}
        break;
      case 339: /* ffactor ::= KEY_OPEN_BRACKET ffeatures KEY_CLOSE_BRACKET */
{  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
#line 1424 "./mql.yxx"
{ mqlyymsp[-2].minor.mqlyy108 = new FFactor(mqlyymsp[-1].minor.mqlyy168); }
#line 5562 "./mql.c"
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
}
        break;
      case 340: /* ffactor ::= feature_comparison */
#line 1426 "./mql.yxx"
{ mqlyylhsminor.mqlyy108 = new FFactor(mqlyymsp[0].minor.mqlyy526); }
#line 5569 "./mql.c"
  mqlyymsp[0].minor.mqlyy108 = mqlyylhsminor.mqlyy108;
        break;
      case 342: /* feature_comparison ::= computed_feature_name comparison_operator value */
#line 1434 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(new std::string(mqlyymsp[-2].minor.mqlyy485->getFeatureName()), new std::string(mqlyymsp[-2].minor.mqlyy485->getParameter1()), mqlyymsp[-1].minor.mqlyy384, mqlyymsp[0].minor.mqlyy300); delete mqlyymsp[-2].minor.mqlyy485; }
#line 5575 "./mql.c"
  mqlyymsp[-2].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 343: /* feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET KEY_CLOSE_BRACKET */
#line 1436 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-3].minor.mqlyy0->extractString(), 0, kEqual, new IntegerList()); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5581 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-1].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 344: /* feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
#line 1438 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, kEqual, new StringList(mqlyymsp[-1].minor.mqlyy368)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy368; }
#line 5590 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 345: /* feature_comparison ::= feature_name KEY_EQUALS KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
#line 1440 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, kEqual, new IntegerList(mqlyymsp[-1].minor.mqlyy183)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy183; }
#line 5599 "./mql.c"
  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 346: /* feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_identifier KEY_CLOSE_BRACKET */
#line 1442 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, kIn, new StringList(mqlyymsp[-1].minor.mqlyy368)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy368; }
#line 5608 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 347: /* feature_comparison ::= feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
#line 1444 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-4].minor.mqlyy0->extractString(), 0, kIn, new IntegerList(mqlyymsp[-1].minor.mqlyy183)); deleteToken(mqlyymsp[-4].minor.mqlyy0); delete mqlyymsp[-1].minor.mqlyy183; }
#line 5617 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 348: /* feature_comparison ::= computed_feature_name KEY_IN KEY_OPEN_BRACKET list_of_integer KEY_CLOSE_BRACKET */
#line 1446 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(new std::string(mqlyymsp[-4].minor.mqlyy485->getFeatureName()), new std::string(mqlyymsp[-4].minor.mqlyy485->getParameter1()), kIn, new IntegerList(mqlyymsp[-1].minor.mqlyy183)); delete mqlyymsp[-1].minor.mqlyy183; delete mqlyymsp[-4].minor.mqlyy485; }
#line 5626 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-4].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 349: /* feature_comparison ::= feature_name KEY_IN object_reference_usage */
#line 1448 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(mqlyymsp[-2].minor.mqlyy0->extractString(), 0, kIn, new Value(mqlyymsp[0].minor.mqlyy366)); deleteToken(mqlyymsp[-2].minor.mqlyy0); }
#line 5635 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 350: /* feature_comparison ::= computed_feature_name KEY_IN object_reference_usage */
#line 1450 "./mql.yxx"
{ mqlyylhsminor.mqlyy526 = new FeatureComparison(new std::string(mqlyymsp[-2].minor.mqlyy485->getFeatureName()), new std::string(mqlyymsp[-2].minor.mqlyy485->getParameter1()), kIn, new Value(mqlyymsp[0].minor.mqlyy366)); delete mqlyymsp[-2].minor.mqlyy485; }
#line 5642 "./mql.c"
  mqlyy_destructor(mqlyypParser,80,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy526 = mqlyylhsminor.mqlyy526;
        break;
      case 351: /* computed_feature_name ::= feature_name KEY_OPEN_BRACKET feature_name KEY_CLOSE_BRACKET */
#line 1455 "./mql.yxx"
{ mqlyylhsminor.mqlyy485 = new ComputedFeatureName(mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy0->extractString()); deleteToken(mqlyymsp[-3].minor.mqlyy0); deleteToken(mqlyymsp[-1].minor.mqlyy0); }
#line 5649 "./mql.c"
  mqlyy_destructor(mqlyypParser,52,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,54,&mqlyymsp[0].minor);
  mqlyymsp[-3].minor.mqlyy485 = mqlyylhsminor.mqlyy485;
        break;
      case 352: /* comparison_operator ::= KEY_EQUALS */
{  mqlyy_destructor(mqlyypParser,72,&mqlyymsp[0].minor);
#line 1460 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kEqual; }
#line 5658 "./mql.c"
}
        break;
      case 353: /* comparison_operator ::= KEY_LESS_THAN */
{  mqlyy_destructor(mqlyypParser,117,&mqlyymsp[0].minor);
#line 1461 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kLessThan; }
#line 5665 "./mql.c"
}
        break;
      case 354: /* comparison_operator ::= KEY_GREATER_THAN */
{  mqlyy_destructor(mqlyypParser,118,&mqlyymsp[0].minor);
#line 1462 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kGreaterThan; }
#line 5672 "./mql.c"
}
        break;
      case 355: /* comparison_operator ::= KEY_NOT_EQUAL */
{  mqlyy_destructor(mqlyypParser,119,&mqlyymsp[0].minor);
#line 1463 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kNotEqual; }
#line 5679 "./mql.c"
}
        break;
      case 356: /* comparison_operator ::= KEY_LESS_THAN_OR_EQUAL */
{  mqlyy_destructor(mqlyypParser,120,&mqlyymsp[0].minor);
#line 1464 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kLessThanOrEqual; }
#line 5686 "./mql.c"
}
        break;
      case 357: /* comparison_operator ::= KEY_GREATER_THAN_OR_EQUAL */
{  mqlyy_destructor(mqlyypParser,121,&mqlyymsp[0].minor);
#line 1465 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kGreaterThanOrEqual; }
#line 5693 "./mql.c"
}
        break;
      case 358: /* comparison_operator ::= KEY_TILDE */
{  mqlyy_destructor(mqlyypParser,122,&mqlyymsp[0].minor);
#line 1466 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kTilde; }
#line 5700 "./mql.c"
}
        break;
      case 359: /* comparison_operator ::= KEY_NOT_TILDE */
{  mqlyy_destructor(mqlyypParser,123,&mqlyymsp[0].minor);
#line 1467 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kNotTilde; }
#line 5707 "./mql.c"
}
        break;
      case 360: /* comparison_operator ::= KEY_HAS */
{  mqlyy_destructor(mqlyypParser,124,&mqlyymsp[0].minor);
#line 1468 "./mql.yxx"
{ mqlyymsp[0].minor.mqlyy384 = kHas; }
#line 5714 "./mql.c"
}
        break;
      case 361: /* value ::= enum_const */
#line 1475 "./mql.yxx"
{ mqlyylhsminor.mqlyy300 = new Value(mqlyymsp[0].minor.mqlyy0->extractString(), kValEnumConst); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5720 "./mql.c"
  mqlyymsp[0].minor.mqlyy300 = mqlyylhsminor.mqlyy300;
        break;
      case 362: /* value ::= signed_integer */
#line 1477 "./mql.yxx"
{ mqlyylhsminor.mqlyy300 = new Value(mqlyymsp[0].minor.mqlyy466); }
#line 5726 "./mql.c"
  mqlyymsp[0].minor.mqlyy300 = mqlyylhsminor.mqlyy300;
        break;
      case 363: /* value ::= STRING */
#line 1479 "./mql.yxx"
{ mqlyylhsminor.mqlyy300 = new Value(mqlyymsp[0].minor.mqlyy0->extractString(), kValString); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5732 "./mql.c"
  mqlyymsp[0].minor.mqlyy300 = mqlyylhsminor.mqlyy300;
        break;
      case 364: /* value ::= object_reference_usage */
#line 1481 "./mql.yxx"
{ mqlyylhsminor.mqlyy300 = new Value(mqlyymsp[0].minor.mqlyy366); }
#line 5738 "./mql.c"
  mqlyymsp[0].minor.mqlyy300 = mqlyylhsminor.mqlyy300;
        break;
      case 366: /* object_reference_usage ::= object_reference KEY_DOT feature_name */
#line 1491 "./mql.yxx"
{ mqlyylhsminor.mqlyy366 = new ObjectReferenceUsage(mqlyymsp[-2].minor.mqlyy0->extractString(), mqlyymsp[0].minor.mqlyy0->extractString(), 0); deleteToken(mqlyymsp[-2].minor.mqlyy0); deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5744 "./mql.c"
  mqlyy_destructor(mqlyypParser,125,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy366 = mqlyylhsminor.mqlyy366;
        break;
      case 367: /* object_reference_usage ::= object_reference KEY_DOT computed_feature_name */
#line 1493 "./mql.yxx"
{ mqlyylhsminor.mqlyy366 = new ObjectReferenceUsage(mqlyymsp[-2].minor.mqlyy0->extractString(), new std::string(mqlyymsp[0].minor.mqlyy485->getFeatureName()), new std::string(mqlyymsp[0].minor.mqlyy485->getParameter1())); deleteToken(mqlyymsp[-2].minor.mqlyy0); delete mqlyymsp[0].minor.mqlyy485; }
#line 5751 "./mql.c"
  mqlyy_destructor(mqlyypParser,125,&mqlyymsp[-1].minor);
  mqlyymsp[-2].minor.mqlyy366 = mqlyylhsminor.mqlyy366;
        break;
      case 368: /* opt_blocks ::= */
#line 1498 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy545 = 0; }
#line 5758 "./mql.c"
        break;
      case 369: /* opt_blocks ::= blocks */
#line 1499 "./mql.yxx"
{ mqlyylhsminor.mqlyy545 = mqlyymsp[0].minor.mqlyy545; }
#line 5763 "./mql.c"
  mqlyymsp[0].minor.mqlyy545 = mqlyylhsminor.mqlyy545;
        break;
      case 370: /* block ::= object_block */
      case 374: /* block ::= notexist_object_block */ mqlyytestcase(mqlyyruleno==374);
#line 1504 "./mql.yxx"
{ mqlyylhsminor.mqlyy534 = new Block(mqlyymsp[0].minor.mqlyy461); }
#line 5770 "./mql.c"
  mqlyymsp[0].minor.mqlyy534 = mqlyylhsminor.mqlyy534;
        break;
      case 371: /* block ::= power */
#line 1505 "./mql.yxx"
{ mqlyylhsminor.mqlyy534 = new Block(mqlyymsp[0].minor.mqlyy572); }
#line 5776 "./mql.c"
  mqlyymsp[0].minor.mqlyy534 = mqlyylhsminor.mqlyy534;
        break;
      case 372: /* block ::= opt_gap_block */
#line 1506 "./mql.yxx"
{ mqlyylhsminor.mqlyy534 = new Block(mqlyymsp[0].minor.mqlyy289); }
#line 5782 "./mql.c"
  mqlyymsp[0].minor.mqlyy534 = mqlyylhsminor.mqlyy534;
        break;
      case 373: /* block ::= gap_block */
#line 1507 "./mql.yxx"
{ mqlyylhsminor.mqlyy534 = new Block(mqlyymsp[0].minor.mqlyy138); }
#line 5788 "./mql.c"
  mqlyymsp[0].minor.mqlyy534 = mqlyylhsminor.mqlyy534;
        break;
      case 375: /* unordered_group ::= KEY_OPEN_SQUARE_BRACKET KEY_UNORDERED_GROUP object_block_string KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-3].minor);
#line 1517 "./mql.yxx"
{ mqlyymsp[-3].minor.mqlyy128 = new UnorderedGroup(mqlyymsp[-1].minor.mqlyy324); }
#line 5795 "./mql.c"
  mqlyy_destructor(mqlyypParser,126,&mqlyymsp[-2].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 376: /* object_block_string ::= object_block */
#line 1521 "./mql.yxx"
{ mqlyylhsminor.mqlyy324 = new ObjectBlockString(NULL, mqlyymsp[0].minor.mqlyy461); }
#line 5803 "./mql.c"
  mqlyymsp[0].minor.mqlyy324 = mqlyylhsminor.mqlyy324;
        break;
      case 377: /* object_block_string ::= object_block_string object_block */
#line 1522 "./mql.yxx"
{ mqlyylhsminor.mqlyy324 = new ObjectBlockString(mqlyymsp[-1].minor.mqlyy324, mqlyymsp[0].minor.mqlyy461); }
#line 5809 "./mql.c"
  mqlyymsp[-1].minor.mqlyy324 = mqlyylhsminor.mqlyy324;
        break;
      case 378: /* star_monad_set ::= */
#line 1529 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy538 = new MQLMonadSetElement(0, MAX_MONAD, 0, true); }
#line 5815 "./mql.c"
        break;
      case 380: /* opt_gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_OPT_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-5].minor);
#line 1535 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy289 = new OptGapBlock(mqlyymsp[-2].minor.mqlyy540, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy545); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5821 "./mql.c"
  mqlyy_destructor(mqlyypParser,127,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 381: /* gap_retrieval ::= */
#line 1540 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy540 = kNoRetrieve; }
#line 5829 "./mql.c"
        break;
      case 385: /* gap_block ::= KEY_OPEN_SQUARE_BRACKET KEY_GAP mark_declaration gap_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-5].minor);
#line 1549 "./mql.yxx"
{ mqlyymsp[-5].minor.mqlyy138 = new GapBlock(mqlyymsp[-2].minor.mqlyy540, mqlyymsp[-3].minor.mqlyy0->extractString(), mqlyymsp[-1].minor.mqlyy545); deleteToken(mqlyymsp[-3].minor.mqlyy0); }
#line 5835 "./mql.c"
  mqlyy_destructor(mqlyypParser,128,&mqlyymsp[-4].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 386: /* feature_retrieval ::= KEY_GET feature_list */
{  mqlyy_destructor(mqlyypParser,62,&mqlyymsp[-1].minor);
#line 1556 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy218 = mqlyymsp[0].minor.mqlyy218; }
#line 5844 "./mql.c"
}
        break;
      case 387: /* feature_retrieval ::= */
#line 1557 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy218 = 0; }
#line 5850 "./mql.c"
        break;
      case 388: /* object_block ::= KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-10].minor);
#line 1570 "./mql.yxx"
{ mqlyymsp[-10].minor.mqlyy461 = new ObjectBlock(mqlyymsp[-9].minor.mqlyy0->extractString(), mqlyymsp[-8].minor.mqlyy0->extractString(), mqlyymsp[-7].minor.mqlyy0->extractString(), mqlyymsp[-6].minor.mqlyy540, mqlyymsp[-5].minor.mqlyy546, mqlyymsp[-4].minor.mqlyy409, mqlyymsp[-3].minor.mqlyy168, mqlyymsp[-2].minor.mqlyy218, mqlyymsp[-1].minor.mqlyy545, false); 
      deleteToken(mqlyymsp[-9].minor.mqlyy0); deleteToken(mqlyymsp[-8].minor.mqlyy0); deleteToken(mqlyymsp[-7].minor.mqlyy0); 
    }
#line 5858 "./mql.c"
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 389: /* notexist_object_block ::= notexist KEY_OPEN_SQUARE_BRACKET object_type_name mark_declaration object_reference_declaration retrieval firstlast monad_set_relation_clause feature_constraints feature_retrieval opt_blocks KEY_CLOSE_SQUARE_BRACKET */
{  mqlyy_destructor(mqlyypParser,285,&mqlyymsp[-11].minor);
#line 1584 "./mql.yxx"
{ mqlyymsp[-11].minor.mqlyy461 = new ObjectBlock(mqlyymsp[-9].minor.mqlyy0->extractString(), mqlyymsp[-8].minor.mqlyy0->extractString(), mqlyymsp[-7].minor.mqlyy0->extractString(), mqlyymsp[-6].minor.mqlyy540, mqlyymsp[-5].minor.mqlyy546, mqlyymsp[-4].minor.mqlyy409, mqlyymsp[-3].minor.mqlyy168, mqlyymsp[-2].minor.mqlyy218, mqlyymsp[-1].minor.mqlyy545, true); 
      deleteToken(mqlyymsp[-9].minor.mqlyy0); deleteToken(mqlyymsp[-8].minor.mqlyy0); deleteToken(mqlyymsp[-7].minor.mqlyy0); 
    }
#line 5868 "./mql.c"
  mqlyy_destructor(mqlyypParser,18,&mqlyymsp[-10].minor);
  mqlyy_destructor(mqlyypParser,19,&mqlyymsp[0].minor);
}
        break;
      case 390: /* power ::= KEY_POWER restrictor */
{  mqlyy_destructor(mqlyypParser,129,&mqlyymsp[-1].minor);
#line 1592 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy572 = new Power(mqlyymsp[0].minor.mqlyy88); }
#line 5877 "./mql.c"
}
        break;
      case 391: /* power ::= KEY_POWER KEY_BETWEEN limit KEY_AND limit */
{  mqlyy_destructor(mqlyypParser,129,&mqlyymsp[-4].minor);
#line 1594 "./mql.yxx"
{ mqlyymsp[-4].minor.mqlyy572 = new Power(mqlyymsp[-2].minor.mqlyy88, mqlyymsp[0].minor.mqlyy88); }
#line 5884 "./mql.c"
  mqlyy_destructor(mqlyypParser,130,&mqlyymsp[-3].minor);
  mqlyy_destructor(mqlyypParser,35,&mqlyymsp[-1].minor);
}
        break;
      case 392: /* restrictor ::= */
#line 1598 "./mql.yxx"
{ mqlyymsp[1].minor.mqlyy88 = MAX_MONAD; }
#line 5892 "./mql.c"
        break;
      case 393: /* restrictor ::= KEY_LESS_THAN limit */
{  mqlyy_destructor(mqlyypParser,117,&mqlyymsp[-1].minor);
#line 1599 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy88 = mqlyymsp[0].minor.mqlyy88-1; }
#line 5898 "./mql.c"
}
        break;
      case 394: /* restrictor ::= KEY_LESS_THAN_OR_EQUAL limit */
{  mqlyy_destructor(mqlyypParser,120,&mqlyymsp[-1].minor);
#line 1600 "./mql.yxx"
{ mqlyymsp[-1].minor.mqlyy88 = mqlyymsp[0].minor.mqlyy88; }
#line 5905 "./mql.c"
}
        break;
      case 395: /* limit ::= INTEGER */
#line 1606 "./mql.yxx"
{ mqlyylhsminor.mqlyy88 = (monad_m) mqlyymsp[0].minor.mqlyy0->integer; deleteToken(mqlyymsp[0].minor.mqlyy0); }
#line 5911 "./mql.c"
  mqlyymsp[0].minor.mqlyy88 = mqlyylhsminor.mqlyy88;
        break;
      default:
        break;
/********** End reduce actions ************************************************/
  };
  assert( mqlyyruleno<sizeof(mqlyyRuleInfoLhs)/sizeof(mqlyyRuleInfoLhs[0]) );
  mqlyygoto = mqlyyRuleInfoLhs[mqlyyruleno];
  mqlyysize = mqlyyRuleInfoNRhs[mqlyyruleno];
  mqlyyact = mqlyy_find_reduce_action(mqlyymsp[mqlyysize].stateno,(MQLYYCODETYPE)mqlyygoto);

  /* There are no SHIFTREDUCE actions on nonterminals because the table
  ** generator has simplified them to pure REDUCE actions. */
  assert( !(mqlyyact>MQLYY_MAX_SHIFT && mqlyyact<=MQLYY_MAX_SHIFTREDUCE) );

  /* It is not possible for a REDUCE to be followed by an error */
  assert( mqlyyact!=MQLYY_ERROR_ACTION );

  mqlyymsp += mqlyysize+1;
  mqlyypParser->mqlyytos = mqlyymsp;
  mqlyymsp->stateno = (MQLYYACTIONTYPE)mqlyyact;
  mqlyymsp->major = (MQLYYCODETYPE)mqlyygoto;
  mqlyyTraceShift(mqlyypParser, mqlyyact, "... then shift");
  return mqlyyact;
}

/*
** The following code executes when the parse fails
*/
#ifndef MQLYYNOERRORRECOVERY
static void mqlyy_parse_failed(
  mqlyyParser *mqlyypParser           /* The parser */
){
  MQLParserARG_FETCH
  MQLParserCTX_FETCH
#ifndef NDEBUG
  if( mqlyyTraceFILE ){
    fprintf(mqlyyTraceFILE,"%sFail!\n",mqlyyTracePrompt);
  }
#endif
  while( mqlyypParser->mqlyytos>mqlyypParser->mqlyystack ) mqlyy_pop_parser_stack(mqlyypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
/************ Begin %parse_failure code ***************************************/
#line 77 "./mql.yxx"

  pEE->bSyntaxError = true;
#line 5959 "./mql.c"
/************ End %parse_failure code *****************************************/
  MQLParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  MQLParserCTX_STORE
}
#endif /* MQLYYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void mqlyy_syntax_error(
  mqlyyParser *mqlyypParser,           /* The parser */
  int mqlyymajor,                   /* The major type of the error token */
  MQLParserTOKENTYPE mqlyyminor         /* The minor type of the error token */
){
  MQLParserARG_FETCH
  MQLParserCTX_FETCH
#define TOKEN mqlyyminor
/************ Begin %syntax_error code ****************************************/
#line 80 "./mql.yxx"

  UNUSED(mqlyymajor);
  UNUSED(mqlyyminor);
  pEE->bSyntaxError = true;
  std::string errMsg = "syntax error near " + TOKEN->getTokenName() + '\n';
  pEE->pError->appendError(errMsg);
#line 5985 "./mql.c"
/************ End %syntax_error code ******************************************/
  MQLParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  MQLParserCTX_STORE
}

/*
** The following is executed when the parser accepts
*/
static void mqlyy_accept(
  mqlyyParser *mqlyypParser           /* The parser */
){
  MQLParserARG_FETCH
  MQLParserCTX_FETCH
#ifndef NDEBUG
  if( mqlyyTraceFILE ){
    fprintf(mqlyyTraceFILE,"%sAccept!\n",mqlyyTracePrompt);
  }
#endif
#ifndef MQLYYNOERRORRECOVERY
  mqlyypParser->mqlyyerrcnt = -1;
#endif
  assert( mqlyypParser->mqlyytos==mqlyypParser->mqlyystack );
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
/*********** Begin %parse_accept code *****************************************/
/*********** End %parse_accept code *******************************************/
  MQLParserARG_STORE /* Suppress warning about unused %extra_argument variable */
  MQLParserCTX_STORE
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "MQLParserAlloc" which describes the current state of the parser.
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
void MQLParser(
  void *mqlyyp,                   /* The parser */
  int mqlyymajor,                 /* The major token code number */
  MQLParserTOKENTYPE mqlyyminor       /* The value for the token */
  MQLParserARG_PDECL               /* Optional %extra_argument parameter */
){
  MQLYYMINORTYPE mqlyyminorunion;
  MQLYYACTIONTYPE mqlyyact;   /* The parser action. */
#if !defined(MQLYYERRORSYMBOL) && !defined(MQLYYNOERRORRECOVERY)
  int mqlyyendofinput;     /* True if we are at the end of input */
#endif
#ifdef MQLYYERRORSYMBOL
  int mqlyyerrorhit = 0;   /* True if mqlyymajor has invoked an error */
#endif
  mqlyyParser *mqlyypParser = (mqlyyParser*)mqlyyp;  /* The parser */
  MQLParserCTX_FETCH
  MQLParserARG_STORE

  assert( mqlyypParser->mqlyytos!=0 );
#if !defined(MQLYYERRORSYMBOL) && !defined(MQLYYNOERRORRECOVERY)
  mqlyyendofinput = (mqlyymajor==0);
#endif

  mqlyyact = mqlyypParser->mqlyytos->stateno;
#ifndef NDEBUG
  if( mqlyyTraceFILE ){
    if( mqlyyact < MQLYY_MIN_REDUCE ){
      fprintf(mqlyyTraceFILE,"%sInput '%s' in state %d\n",
              mqlyyTracePrompt,mqlyyTokenName[mqlyymajor],mqlyyact);
    }else{
      fprintf(mqlyyTraceFILE,"%sInput '%s' with pending reduce %d\n",
              mqlyyTracePrompt,mqlyyTokenName[mqlyymajor],mqlyyact-MQLYY_MIN_REDUCE);
    }
  }
#endif

  do{
    assert( mqlyyact==mqlyypParser->mqlyytos->stateno );
    mqlyyact = mqlyy_find_shift_action((MQLYYCODETYPE)mqlyymajor,mqlyyact);
    if( mqlyyact >= MQLYY_MIN_REDUCE ){
      mqlyyact = mqlyy_reduce(mqlyypParser,mqlyyact-MQLYY_MIN_REDUCE,mqlyymajor,
                        mqlyyminor MQLParserCTX_PARAM);
    }else if( mqlyyact <= MQLYY_MAX_SHIFTREDUCE ){
      mqlyy_shift(mqlyypParser,mqlyyact,(MQLYYCODETYPE)mqlyymajor,mqlyyminor);
#ifndef MQLYYNOERRORRECOVERY
      mqlyypParser->mqlyyerrcnt--;
#endif
      break;
    }else if( mqlyyact==MQLYY_ACCEPT_ACTION ){
      mqlyypParser->mqlyytos--;
      mqlyy_accept(mqlyypParser);
      return;
    }else{
      assert( mqlyyact == MQLYY_ERROR_ACTION );
      mqlyyminorunion.mqlyy0 = mqlyyminor;
#ifdef MQLYYERRORSYMBOL
      int mqlyymx;
#endif
#ifndef NDEBUG
      if( mqlyyTraceFILE ){
        fprintf(mqlyyTraceFILE,"%sSyntax Error!\n",mqlyyTracePrompt);
      }
#endif
#ifdef MQLYYERRORSYMBOL
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
      if( mqlyypParser->mqlyyerrcnt<0 ){
        mqlyy_syntax_error(mqlyypParser,mqlyymajor,mqlyyminor);
      }
      mqlyymx = mqlyypParser->mqlyytos->major;
      if( mqlyymx==MQLYYERRORSYMBOL || mqlyyerrorhit ){
#ifndef NDEBUG
        if( mqlyyTraceFILE ){
          fprintf(mqlyyTraceFILE,"%sDiscard input token %s\n",
             mqlyyTracePrompt,mqlyyTokenName[mqlyymajor]);
        }
#endif
        mqlyy_destructor(mqlyypParser, (MQLYYCODETYPE)mqlyymajor, &mqlyyminorunion);
        mqlyymajor = MQLYYNOCODE;
      }else{
        while( mqlyypParser->mqlyytos >= mqlyypParser->mqlyystack
            && (mqlyyact = mqlyy_find_reduce_action(
                        mqlyypParser->mqlyytos->stateno,
                        MQLYYERRORSYMBOL)) > MQLYY_MAX_SHIFTREDUCE
        ){
          mqlyy_pop_parser_stack(mqlyypParser);
        }
        if( mqlyypParser->mqlyytos < mqlyypParser->mqlyystack || mqlyymajor==0 ){
          mqlyy_destructor(mqlyypParser,(MQLYYCODETYPE)mqlyymajor,&mqlyyminorunion);
          mqlyy_parse_failed(mqlyypParser);
#ifndef MQLYYNOERRORRECOVERY
          mqlyypParser->mqlyyerrcnt = -1;
#endif
          mqlyymajor = MQLYYNOCODE;
        }else if( mqlyymx!=MQLYYERRORSYMBOL ){
          mqlyy_shift(mqlyypParser,mqlyyact,MQLYYERRORSYMBOL,mqlyyminor);
        }
      }
      mqlyypParser->mqlyyerrcnt = 3;
      mqlyyerrorhit = 1;
      if( mqlyymajor==MQLYYNOCODE ) break;
      mqlyyact = mqlyypParser->mqlyytos->stateno;
#elif defined(MQLYYNOERRORRECOVERY)
      /* If the MQLYYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      mqlyy_syntax_error(mqlyypParser,mqlyymajor, mqlyyminor);
      mqlyy_destructor(mqlyypParser,(MQLYYCODETYPE)mqlyymajor,&mqlyyminorunion);
      break;
#else  /* MQLYYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( mqlyypParser->mqlyyerrcnt<=0 ){
        mqlyy_syntax_error(mqlyypParser,mqlyymajor, mqlyyminor);
      }
      mqlyypParser->mqlyyerrcnt = 3;
      mqlyy_destructor(mqlyypParser,(MQLYYCODETYPE)mqlyymajor,&mqlyyminorunion);
      if( mqlyyendofinput ){
        mqlyy_parse_failed(mqlyypParser);
#ifndef MQLYYNOERRORRECOVERY
        mqlyypParser->mqlyyerrcnt = -1;
#endif
      }
      break;
#endif
    }
  }while( mqlyypParser->mqlyytos>mqlyypParser->mqlyystack );
#ifndef NDEBUG
  if( mqlyyTraceFILE ){
    mqlyyStackEntry *i;
    char cDiv = '[';
    fprintf(mqlyyTraceFILE,"%sReturn. Stack=",mqlyyTracePrompt);
    for(i=&mqlyypParser->mqlyystack[1]; i<=mqlyypParser->mqlyytos; i++){
      fprintf(mqlyyTraceFILE,"%c%s", cDiv, mqlyyTokenName[i->major]);
      cDiv = ' ';
    }
    fprintf(mqlyyTraceFILE,"]\n");
  }
#endif
  return;
}

/*
** Return the fallback token corresponding to canonical token iToken, or
** 0 if iToken has no fallback.
*/
int MQLParserFallback(int iToken){
#ifdef MQLYYFALLBACK
  assert( iToken<(int)(sizeof(mqlyyFallback)/sizeof(mqlyyFallback[0])) );
  return mqlyyFallback[iToken];
#else
  (void)iToken;
  return 0;
#endif
}
