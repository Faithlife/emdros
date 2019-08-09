
/*
 * Copyright (C) 2001-2018     Ulrik Sandborg-Petersen
 * Copyright (C) 2018-present  Sandborg-Petersen Holding ApS, Denmark
 *
 * Licensed under the MIT License.
 *
 * Please see the file COPYING in the root of the sources for more details.
 *
 */


char negra_schema[] = 
"CREATE OBJECT TYPE\n"
"WITH SINGLE MONAD OBJECTS\n"
"HAVING UNIQUE FIRST MONADS\n"
"[Word\n"
"    surface : STRING WITH INDEX;\n"
"    postag : STRING FROM SET WITH INDEX;\n"
"    morphtag : STRING FROM SET WITH INDEX;\n"
"    edge : STRING WITH INDEX;\n"
"    parent : ID_D;\n"
"    parents : LIST OF ID_D;\n"
"    secedge1 : STRING FROM SET WITH INDEX;\n"
"    secparent1 : ID_D;\n"
"    secedge2 : STRING FROM SET WITH INDEX;\n"
"    secparent2 : ID_D;\n"
"    secedge3 : STRING FROM SET WITH INDEX;\n"
"    secparent3 : ID_D;\n"
"    secedge4 : STRING FROM SET WITH INDEX;\n"
"    secparent4 : ID_D;\n"
"    secedge5 : STRING FROM SET WITH INDEX;\n"
"    secparent5 : ID_D;\n"
"]\n"
"GO\n"
"\n"
"\n"
"CREATE OBJECT TYPE\n"
"[Phrase\n"
"    tag : STRING FROM SET WITH INDEX;\n"
"    morphtag : STRING FROM SET WITH INDEX;\n"
"    edge : STRING FROM SET WITH INDEX;\n"
"    parent : ID_D;\n"
"    parents : LIST OF ID_D;\n"
"    secedge1 : STRING FROM SET WITH INDEX;\n"
"    secparent1 : ID_D;\n"
"    secedge2 : STRING FROM SET WITH INDEX;\n"
"    secparent2 : ID_D;\n"
"    secedge3 : STRING FROM SET WITH INDEX;\n"
"    secparent3 : ID_D;\n"
"    secedge4 : STRING FROM SET WITH INDEX;\n"
"    secparent4 : ID_D;\n"
"    secedge5 : STRING FROM SET WITH INDEX;\n"
"    secparent5 : ID_D;\n"
"]\n"
"GO\n"
"\n"
"CREATE OBJECT TYPE\n"
"WITH SINGLE RANGE OBJECTS\n"
"HAVING UNIQUE FIRST MONADS\n"
"[Sentence\n"
"    sentence_id : INTEGER;\n"
"    editor_id : STRING FROM SET WITH INDEX;\n"
"    date : INTEGER;\n"
"    origin_id : STRING WITH INDEX;\n"
"]\n"
"GO\n"
;
