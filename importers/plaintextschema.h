
/*
 * Copyright (C) 2001-2018     Ulrik Sandborg-Petersen
 * Copyright (C) 2018-present  Sandborg-Petersen Holding ApS, Denmark
 *
 * Licensed under the MIT License.
 *
 * Please see the file COPYING in the root of the sources for more details.
 *
 */


char plaintext_schema[] = 
"CREATE OBJECT TYPE\n"
"WITH SINGLE MONAD OBJECTS\n"
"HAVING UNIQUE FIRST MONADS\n"
"[Word\n"
"    surface : STRING FROM SET WITH INDEX;\n"
"    stripped_surface : STRING FROM SET WITH INDEX;\n"
"]\n"
"GO\n"
"\n"
"\n"
"CREATE OBJECT TYPE\n"
"WITH SINGLE RANGE OBJECTS\n"
"HAVING UNIQUE FIRST MONADS\n"
"[Paragraph]\n"
"GO\n"
"\n"
"\n"
"\n"
"CREATE OBJECT TYPE\n"
"WITH SINGLE RANGE OBJECTS\n"
"HAVING UNIQUE FIRST MONADS\n"
"[Document]\n"
"GO\n"
"\n"
"\n"
;
