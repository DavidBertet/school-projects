#ifndef CHESSDRIVER_HH_
# define CHESSDRIVER_HH_
# include <string>
# include <map>

# include "parsechess.hh"

# define YY_DECL \
  ::yy::parser::token_type			\
  yylex (::yy::parser::semantic_type *lval,	\
	 ::yy::parser::location_type *lloc,	\
	 ChessDriver &driver)

YY_DECL;

class ChessDriver
{
  public:
    ChessDriver ();
    virtual ~ChessDriver ();

    void parse ();

    void scan_begin ();
    void scan_end ();
    void scan_driver ();
    std::vector <std::pair<MovePGN*, MovePGN*>*>*
    pgn_get ();
    void
    pgn_set (std::vector <std::pair<MovePGN*, MovePGN*>*>* pgn);
    void error (const yy::location&	l,
		const std::string&	m);
    void error (const std::string	&m);

    bool trace_scanning;
    int	result;
    bool trace_parsing;
    int	vreturn;
    int	end;
  private:
    std::vector <std::pair<MovePGN*, MovePGN*>*> *pgn_;
};

#endif /* !CHESSDRIVER_HH_ */
