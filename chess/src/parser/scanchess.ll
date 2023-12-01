/* -*- C++ -*- */
%{
#include <iostream>
#include <stdlib.h>
#include "parsechess.hh"
#include "chessdriver.hh"
#include <sstream>

#define yyterminate() return  ::yy::parser::token::END_OF_FILE
  typedef ::yy::parser::token token;
#define YY_USER_ACTION lloc->columns(yyleng);
#define YY_NO_TOP_STATE
%}

/* The lexer shall stop after EOF */
%option nounput
%option noyywrap
%option debug
%option batch
%option stack


%x SC_STRING
%x SC_COMMENT1
%x SC_COMMENT2
%x SC_SCAN_MOVE
%x SC_RULES

%%
%{
  lloc->step ();
%}

"Event"				{ return token::EVENT; }
"Site"				{ return token::SITE; }
"Date"				{ return token::DATE; }
"Round"				{ return token::ROUND; }
"White"				{ return token::WHITE; }
"Black"				{ return token::BLACK; }
"Result"			{ return token::RESULT; }
"["				{ return token::OBRACKET; }
"]"				{ return token::CBRACKET; }
"1"				{ yy_push_state(SC_RULES); return token::NO_TURN; }
([[:alnum:]])*			{ return token::SYMBOL; }
[ \t\r]+			{ lloc->step(); }
[\r]*"\n"[\r]*                  { lloc->lines(1); lloc->step();}
"\""				{ lval->str = new std::string (); yy_push_state(SC_STRING);}
<<EOF>>				{ yyterminate(); }
.      {const std::string p ("scan error");driver.vreturn = 2;driver.error (*lloc, p);lloc->columns(yyleng);return ::yy::parser::token::ERROR;}


<SC_RULES>
{
  "1-0"				{ return token::WIN;}
  "0-1"				{ return token::LOSE;}
  "1/2-1/2"			{ return token::EQUALITY;}
  "0,5-0,5"			{ return token::EQUALITY;}
  "*"				{ return token::NO_END;}
  "."[ \t\r]*			{ yy_push_state(SC_SCAN_MOVE);}

  ([[:digit:]])*		{ return token::NO_TURN;}

  [ \t\r]*			{ lloc->step(); }
  [\r]*"\n"[\r]*                { lloc->lines(1); lloc->step(); }
   [KPBRNQ]			{ if (*yytext == 'P') lval->ival = 5;
  				if (*yytext == 'B') lval->ival = 3;
 				if (*yytext == 'R') lval->ival = 2;
  				if (*yytext == 'N') lval->ival = 4;
 				if (*yytext == 'Q') lval->ival = 1;
				if (*yytext == 'K') lval->ival = 0;
 				yy_push_state(SC_SCAN_MOVE);
 				return token::PIECE_ID; }
   [a-h]		       {if (*yytext == 'a') lval->ival = 1;
 				if (*yytext == 'b') lval->ival = 2;
 				if (*yytext == 'c') lval->ival = 3;
 				if (*yytext == 'd') lval->ival = 4;
 				if (*yytext == 'e') lval->ival = 5;
 				if (*yytext == 'f') lval->ival = 6;
 				if (*yytext == 'g') lval->ival = 7;
 				if (*yytext == 'h') lval->ival = 8;
 				yy_push_state(SC_SCAN_MOVE);
 				return token::FILE;}
   "O-O"				{ yy_push_state(SC_SCAN_MOVE); return token::KING_CASTLING;}
   "O-O-O"			{ yy_push_state(SC_SCAN_MOVE); return token::QUEEN_CASTLING;}

   .				{std::cout << "gyuop" << std::endl; yy_pop_state ();}
}


<SC_STRING>
{

  "\""				{yy_pop_state (); return token::STRING;}
  "\\"[0-7]{1,3}		{
    std::stringstream k (std::stringstream::in | std::stringstream::out);
    k << std::oct << (yytext + 1);
    lval->str->append (k.str ());
  }
  "\\x"[0-9a-fA-F]{2}		{
    std::stringstream k (std::stringstream::in | std::stringstream::out);
    k << std::hex << (yytext + 2);
    lval->str->append (k.str ());
  }

  "\\n"				{lval->str->append (1, '\n');}
  "\\t" 			{lval->str->append (1, '\t');}
  "\\r" 			{lval->str->append (1, '\r');}
  "\\b" 			{lval->str->append (1, '\b');}
  "\\f" 			{lval->str->append (1, '\f');}
  "\\a" 			{lval->str->append (1, '\a');}
  "\\v" 			{lval->str->append (1, '\v');}
  "\\"[89]     		        {driver.vreturn = 2;driver.error(*lloc, "mauvaise sequence d'echapement");return token::ERROR;}
  "\\"[0-7]{4,}			{driver.vreturn = 2;driver.error(*lloc, "mauvaise sequence d'echapement");return token::ERROR;}
  "\\x"[0-9a-fA-F]{3,}		{driver.vreturn = 2;driver.error(*lloc, "mauvaise sequence d'echapement");return token::ERROR;}
  "\\"[^ntrbfav]		{driver.vreturn = 2;driver.error(*lloc, "mauvaise sequence d'echapement");return token::ERROR;}

  .				{lval->str->append (yytext);}
}



<SC_SCAN_MOVE>
{
   [KPBRNQ]	{ if (*yytext == 'P') lval->ival = 5;
 		  if (*yytext == 'B') lval->ival = 3;
  		  if (*yytext == 'R') lval->ival = 2;
 		  if (*yytext == 'N') lval->ival = 4;
 		  if (*yytext == 'Q') lval->ival = 1;
 		  if (*yytext == 'K') lval->ival = 0;
 		  return token::PIECE_ID;}
   [a-h]		{ if (*yytext == 'a') lval->ival = 1;
 		  if (*yytext == 'b') lval->ival = 2;
 		  if (*yytext == 'c') lval->ival = 3;
 		  if (*yytext == 'd') lval->ival = 4;
 		  if (*yytext == 'e') lval->ival = 5;
 		  if (*yytext == 'f') lval->ival = 6;
 		  if (*yytext == 'g') lval->ival = 7;
 		  if (*yytext == 'h') lval->ival = 8;
                   return token::FILE;}
   [1-8]		{lval->ival = (*yytext) - '0';
                 return token::RANK;}
  "O-O"		{ return token::KING_CASTLING;}
  "O-O-O"	{ return token::QUEEN_CASTLING;}
  "x"		{ return token::CAPTURE;}
  "="		{ return token::PROMOTION;}
  "+"		{ return token::CHECK;}
  "#"		{ return token::MAT;}
  ";"		{ yy_push_state(SC_COMMENT2);}
  "{"		{ yy_push_state(SC_COMMENT1);}
  "\n"          { lloc->lines(1); lloc->step(); yy_pop_state (); }
  [ \t\r\n]+	{ yy_pop_state ();}
  .		{}
}



 <SC_COMMENT1>
 {
  "\n"				{lloc->lines(1);lloc->step();}
  "}"				{ yy_pop_state (); }
  .				{}
}
<SC_COMMENT2>
 {
  "\n"				{lloc->lines(1);lloc->step();yy_pop_state ();}
  .				{}
}


%%

void
ChessDriver::scan_begin ()
{
  yy_flex_debug = trace_scanning;

//   if (!(yyin = fopen (file.c_str (), "r")))
//     error (file += "cannot open ");
}

void
ChessDriver::scan_end ()
{
  fclose (yyin);
}
