/* Generated by re2c 2.0.3 on Tue Dec  8 12:13:26 2020 */
#line 1 "pennlexer.re"
/*
 * pennlexer.lxx
 *
 * Penn Treebank lexer
 *
 * Ulrik Petersen
 * Created: 2/17-2006
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




#include <string>
#include <sstream>
#include <pennimporter.h>
#include "pennparser.h"

#define TOKEN_RETURN(X,Y) { yylval->setName(X); /* std::cerr << "UP200: TOKEN_NAME = " << #X << ", token = " << Y << std::endl; */ return Y; }

#define YYMAXFILL 4



#define BSIZE 8192
#if YYMAXFILL > BSIZE
#error YYMAXFILL must be less than or equal to BSIZE!
#endif

#define YYCTYPE         unsigned char
#define YYCURSOR        cur
#define YYLIMIT         lim
#define YYMARKER        ptr
#define YYFILL(n)       {cur = fill(cur);}

#line 55 "pennlexer.re"


PennScanner::PennScanner(std::istream *pIstr)
{
	pIn = pIstr;
	bot = tok = ptr = cur = pos = lim = top = eof = 0;
}

PennScanner::~PennScanner()
{
	if (bot) {
		delete[] bot;
	}
}

void PennScanner::addToken(void)
{
	yylval->setString(new std::string);
	const unsigned char *p;
	for (p = tok;
	     p != cur;
	     ++p) {
	     yylval->pString->append(1, *p);
	}
	// std::cerr << "UP202: addToken: '" << *(yylval->pString) << "'" << std::endl;
}

unsigned char *PennScanner::fill(unsigned char *cursor)
{
        if(!eof)
        {
                std::streamsize cnt = tok - bot;
                if(cnt)
                {
                        memcpy(bot, tok, lim - tok);
                        tok = bot;
                        ptr -= cnt;
                        cursor -= cnt;
                        pos -= cnt;
                        lim -= cnt;
                }
                if((top - lim) < BSIZE)
                {
                        unsigned char *buf = new unsigned char[(lim - bot) + BSIZE];
                        memcpy(buf, tok, lim - tok);
                        tok = buf;
                        ptr = &buf[ptr - bot];
                        cursor = &buf[cursor - bot];
                        pos = &buf[pos - bot];
                        lim = &buf[lim - bot];
                        top = &lim[BSIZE];
                        delete [] bot;
                        bot = buf;
                }
                pIn->read((char *) lim, BSIZE);
                if ((cnt = pIn->gcount()) != BSIZE )
                {
                        eof = &lim[cnt]; *eof++ = '\0';
                }
                lim += cnt;
        }
        return cursor;
}


int PennScanner::scan(PennToken *pYYLVAL)
{
	yylval = pYYLVAL;
	

 scan:	
	tok = cur;


#line 125 "pennlexer.cpp"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	if (yych <= ' ') {
		if (yych <= '\v') {
			if (yych <= 0x00) goto yy2;
			if (yych <= 0x08) goto yy4;
			if (yych <= '\n') goto yy7;
			goto yy9;
		} else {
			if (yych == '\r') goto yy7;
			if (yych <= 0x1F) goto yy4;
			goto yy7;
		}
	} else {
		if (yych <= '\'') {
			if (yych <= '#') goto yy4;
			if (yych <= '$') goto yy10;
			if (yych <= '%') goto yy11;
			goto yy4;
		} else {
			if (yych <= ')') {
				if (yych <= '(') goto yy12;
				goto yy14;
			} else {
				if (yych == '[') goto yy16;
				goto yy4;
			}
		}
	}
yy2:
	++YYCURSOR;
#line 137 "pennlexer.re"
	{ if (cur >= eof) { goto end; } }
#line 161 "pennlexer.cpp"
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy5:
	if (yych <= '\r') {
		if (yych <= 0x08) {
			if (yych >= 0x01) goto yy4;
		} else {
			if (yych <= '\n') goto yy6;
			if (yych <= '\f') goto yy4;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy4;
		} else {
			if (yych <= '\'') goto yy4;
			if (yych >= '*') goto yy4;
		}
	}
yy6:
#line 132 "pennlexer.re"
	{ addToken();
            TOKEN_RETURN("word/function", T_NAME);
          }
#line 187 "pennlexer.cpp"
yy7:
	++YYCURSOR;
yy8:
#line 130 "pennlexer.re"
	{ goto scan; }
#line 193 "pennlexer.cpp"
yy9:
	yych = *++YYCURSOR;
	if (yych <= '\r') {
		if (yych <= 0x08) {
			if (yych <= 0x00) goto yy8;
			goto yy4;
		} else {
			if (yych <= '\n') goto yy8;
			if (yych <= '\f') goto yy4;
			goto yy8;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy4;
			goto yy8;
		} else {
			if (yych <= '\'') goto yy4;
			if (yych <= ')') goto yy8;
			goto yy4;
		}
	}
yy10:
	yych = *++YYCURSOR;
	if (yych == '(') goto yy17;
	goto yy5;
yy11:
	yych = *++YYCURSOR;
	if (yych == '%') goto yy18;
	goto yy5;
yy12:
	++YYCURSOR;
#line 135 "pennlexer.re"
	{ TOKEN_RETURN("LPAREN", T_KEY_LPAREN); }
#line 227 "pennlexer.cpp"
yy14:
	++YYCURSOR;
#line 136 "pennlexer.re"
	{ TOKEN_RETURN("RPAREN", T_KEY_RPAREN); }
#line 232 "pennlexer.cpp"
yy16:
	yych = *++YYCURSOR;
	if (yych == '.') goto yy20;
	if (yych <= '/') goto yy5;
	if (yych <= '9') goto yy20;
	goto yy5;
yy17:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '-') goto yy22;
	goto yy6;
yy18:
	yych = *++YYCURSOR;
	if (yych <= '\r') {
		if (yych <= 0x08) {
			if (yych >= 0x01) goto yy4;
		} else {
			if (yych <= '\n') goto yy19;
			if (yych <= '\f') goto yy4;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy4;
		} else {
			if (yych <= '\'') goto yy4;
			if (yych >= '*') goto yy4;
		}
	}
yy19:
#line 129 "pennlexer.re"
	{ goto comment; }
#line 263 "pennlexer.cpp"
yy20:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '\'') {
		if (yych <= '\f') {
			if (yych <= 0x00) goto yy6;
			if (yych <= 0x08) goto yy4;
			if (yych <= '\n') goto yy6;
			goto yy4;
		} else {
			if (yych <= '\r') goto yy6;
			if (yych == ' ') goto yy6;
			goto yy4;
		}
	} else {
		if (yych <= '/') {
			if (yych <= ')') goto yy6;
			if (yych == '.') goto yy20;
			goto yy4;
		} else {
			if (yych <= '9') goto yy20;
			if (yych == ']') goto yy24;
			goto yy4;
		}
	}
yy22:
	yych = *++YYCURSOR;
	if (yych <= '\r') {
		if (yych <= 0x08) {
			if (yych >= 0x01) goto yy4;
		} else {
			if (yych <= '\n') goto yy23;
			if (yych <= '\f') goto yy4;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy4;
		} else {
			if (yych <= '\'') goto yy4;
			if (yych >= '*') goto yy4;
		}
	}
yy23:
	YYCURSOR = YYMARKER;
	goto yy6;
yy24:
	yych = *++YYCURSOR;
	if (yych <= '\r') {
		if (yych <= 0x08) {
			if (yych >= 0x01) goto yy4;
		} else {
			if (yych <= '\n') goto yy25;
			if (yych <= '\f') goto yy4;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy4;
		} else {
			if (yych <= '\'') goto yy4;
			if (yych >= '*') goto yy4;
		}
	}
yy25:
#line 131 "pennlexer.re"
	{ goto scan; }
#line 330 "pennlexer.cpp"
}
#line 139 "pennlexer.re"


 comment:

#line 337 "pennlexer.cpp"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x00) goto yy28;
	if (yych == '\n') goto yy32;
	goto yy30;
yy28:
	++YYCURSOR;
#line 144 "pennlexer.re"
	{ if (cur >= eof) { goto end; } }
#line 349 "pennlexer.cpp"
yy30:
	++YYCURSOR;
#line 145 "pennlexer.re"
	{ tok = cur; goto comment; }
#line 354 "pennlexer.cpp"
yy32:
	++YYCURSOR;
#line 143 "pennlexer.re"
	{ goto scan; }
#line 359 "pennlexer.cpp"
}
#line 146 "pennlexer.re"


 end:
 	return 0;
}