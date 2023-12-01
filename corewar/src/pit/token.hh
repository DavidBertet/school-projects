#ifndef TOKEN_HH_
# define TOKEN_HH_

class Token
{
public:
  Token (std::string	val);
  Token ();
  ~Token ();

  // token type
  enum
  {
      NUM = 0,	// number
      REG,	// register r0..15
      REG_ADD,	// register as address [r0..15]
      MNEM,	// mnemonic
      LABEL,	// "label:"
      ADD,	// +
      SUB,	// -
      MULT,	// *
      DIV,	// /
      LPAR,	// (
      RPAR,	// )
      GUIDE,	// .{str, cf subject} ex : .comment
      LBL,	// a string (=label)
      STR,	// a real string = "every think"
      COMAS	// ,
  };

  // raise SyntaxeError if error
  void	match_type ();

  friend std::ostream&	operator<< (std::ostream&	out, Token&	tok);
  friend std::istream&	operator>> (std::istream&	in, Token&	tok);
  friend std::string&	operator>> (std::string&	in, Token&	tok);
private:
  std::string	value_;

};

std::ostream&	operator<< (std::ostream&	out, Token&	tok);

std::istream&
operator>> (std::istream&	out, Token&	tok);

#endif	// TOKEN_HH_
