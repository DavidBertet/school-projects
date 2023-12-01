/* -*- C++ -*- */
%require "2.3"
%skeleton "lalr1.cc"
%expect 0
%expect-rr 0
%error-verbose
%defines
%debug
%locations
%defines

%code requires
{
 #include <string>
 #include <vector>
 #include "movepgn.hh"

 class ChessDriver;
}

%parse-param  {ChessDriver& driver}
%lex-param  {ChessDriver& driver}

%union
 {
     std::string* sym;
     int 	  ival;
     std::string* str;
     std::vector<std::pair<MovePGN*, MovePGN*>*>* listMove;
     std::pair<MovePGN*, MovePGN*>* pairMove;
     MovePGN* move;

}

%type <listMove> program;
%type <listMove> MOVE;
%type <listMove> elementsequence;
%type <pairMove> element;
%type <move> SANmove;
%type <move> linecol;
%type <ival> apres;





%code
{
 #include <iostream>
 #include "chessdriver.hh"
}


%initial-action
{
  //  @$.begin.filename = @$.end.filename = &driver.file;
};


%locations
%pure-parser
%error-verbose

%token EVENT "Event"
%token SITE "Site"
%token DATE "Date"
%token ROUND "Round"
%token WHITE "White"
%token BLACK "Black"
%token RESULT "Result"
%token OBRACKET "["
%token CBRACKET "]"
%token NO_TURN "noturn"
%token WIN "1-0"
%token LOSE "0-1"
%token EQUALITY "1/2-1/2"
%token NO_END "*"
%token POINT "."
%token <ival> PIECE_ID "id_piece"
%token <ival> FILE "file"
%token <ival> RANK "rank"
%token KING_CASTLING "O-O"
%token QUEEN_CASTLING "O-O-O"
%token CAPTURE "x"
%token PROMOTION "="
%token CHECK "+"
%token MAT "#"
%token SYMBOL "sym"
%token ERROR "error"
%token SPACE "sp"
%token <str> STRING "string"
%token END_OF_FILE 0 "eof"
%%

program:
prelude MOVE {driver.pgn_set ($2);}


prelude:
EventE SiteE DateE RoundE WhiteE BlackE ResultE prel

prel:
 /* nothing */
| "[" "sym" "string" "]" prel

EventE:
"[" "Event" "string" "]"
SiteE:
"[" "Site" "string" "]"
DateE:
"[" "Date" "string" "]"
RoundE:
"[" "Round" "string" "]"
WhiteE:
"[" "White" "string" "]"
BlackE:
"[" "Black" "string" "]"
ResultE:
"[" "Result" "string" "]"


MOVE:
elementsequence {$$ = $1;}

elementsequence:
element {$$ = new std::vector <std::pair<MovePGN*, MovePGN*>*>;$$->clear (); $$->push_back ($1);}
| elementsequence element { $$->push_back ($2);}

element:
numindication SANmove SANmove {$$ = new std::pair<MovePGN*, MovePGN*> ($2, $3);}
|numindication SANmove gametermination {$$ = new std::pair<MovePGN*, MovePGN*> ($2, NULL);}
|numindication SANmove SANmove gametermination {$$ = new std::pair<MovePGN*, MovePGN*> ($2, $3);}

numindication:
"noturn"


SANmove:
linecol apres {
                  int case_tmp = $2 / 100;

		  if (case_tmp == 2 || case_tmp == 3)
		    $$->echec_set (true);
		  if (case_tmp == 4 || case_tmp == 5)
		    $$->mat_set (true);

		  if (case_tmp == 1 || case_tmp == 2 || case_tmp == 5)
		  {
		    $$->promotion_set (true);
		    $$->promu_set (static_cast<PieceType>($2 % 10));
		  }
  	      }
| "O-O" {$$ = new MovePGN (); $$->typemove_set (ROQUE);}
| "O-O-O" {$$ = new MovePGN (); $$->typemove_set (GROQUE);}


linecol:
"file"  "rank" {$$ =  new MovePGN ();
	       Position P (static_cast <Position::File>($1), static_cast <Position::Rank>($2));
		$$->dest_set (P);}
| "x" "file" "rank" {$$ =  new MovePGN ();
		     $$->typemove_set (CAPTURE);
		     Position P (static_cast <Position::File>($2), static_cast <Position::Rank>($3));
		     $$->dest_set (P); }
| "id_piece" "file" "rank" {
			    $$ =  new MovePGN ();
			    $$->typepiece_set (static_cast <PieceType>($1));
			    Position P (static_cast <Position::File>($2),static_cast <Position::Rank>($3));
			    $$->dest_set (P);
			   	}
| "id_piece" "x" "file" "rank" {$$ =  new MovePGN ();
				$$->typemove_set (CAPTURE);
				$$->typepiece_set (static_cast <PieceType>($1));
				Position P (static_cast <Position::File>($3), static_cast <Position::Rank>($4));
				$$->dest_set (P);}
| "file" "file"  "rank" {$$ =  new MovePGN ();
			$$->ambFile_set (static_cast <Position::File>($1));
			Position P (static_cast <Position::File>($2), static_cast <Position::Rank>($3));
			$$->dest_set (P); }
| "file" "x" "file" "rank" {$$ =  new MovePGN ();
			    $$->ambFile_set (static_cast <Position::File>($1));
			    $$->typemove_set (CAPTURE);
			    Position P (static_cast <Position::File>($3), static_cast <Position::Rank>($4));
			    $$->dest_set (P);}
| "id_piece" "file" "file" "rank" {$$ =  new MovePGN ();
				   $$->typepiece_set (static_cast <PieceType>($1));
				   $$->ambFile_set (static_cast <Position::File>($2));
				   Position P (static_cast <Position::File>($3),static_cast <Position::Rank>($4));
				   $$->dest_set (P);}
| "id_piece" "rank"   "file" "rank" {$$ =  new MovePGN ();
					$$->typepiece_set (static_cast <PieceType>($1));
					$$->ambRank_set (static_cast <Position::Rank>($2));
					$$->typemove_set (CAPTURE);
					Position P (static_cast <Position::File>($3), static_cast <Position::Rank>($4));
					$$->dest_set (P);}


| "rank" "file"  "rank" {$$ =  new MovePGN ();
			Position P (static_cast <Position::File>($2), static_cast <Position::Rank>($3));
			$$->dest_set (P);
			$$->ambRank_set (static_cast <Position::Rank>($1));
			}
| "rank" "x" "file" "rank" {$$ =  new MovePGN ();
			    Position P (static_cast <Position::File>($3), static_cast <Position::Rank>($4));
			    $$->dest_set (P);
			    $$->typemove_set (CAPTURE);
			    $$->ambRank_set (static_cast <Position::Rank>($1));}



apres:
/* empty */ {$$ = 0;}
| "=" "id_piece" {$$ = 100 + $2;}
| "=" "id_piece" "+" {$$ = 200 + $2; }
| "+"  {$$ = 300;}
| "#" {$$ = 400;}
| "=" "id_piece" "#" {$$ = 500 + $2;}

gametermination:
"1-0" {driver.end = 1;}
| "0-1"{driver.end = 2;}
| "1/2-1/2"{driver.end = 3;}
| "*"{driver.end = 4;}

%%

void
yy::parser::error (const yy::parser::location_type&	l,
		       const std::string&	m)
{
  if (driver.vreturn == 0) driver.vreturn = 3;
  driver.error (l, m);
}
