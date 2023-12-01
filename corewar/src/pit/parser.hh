#ifndef PARSER_HH_
# define PARSER_HH_

#include <boost/spirit/core.hpp>
#include <boost/spirit/tree/parse_tree.hpp>
#include <boost/spirit/tree/ast.hpp>

#include <iostream>
#include <stack>
#include <functional>
#include <string>

//#define DEBUG_LBL

#include <boost/spirit/tree/tree_to_xml.hpp>
#include <map>

#include "visitor.hh"
#include "ast.hh"
#include <vector>

//BOOST SPIRIT
typedef char const*	iterator_t;
typedef boost::spirit::tree_match<iterator_t>		parse_tree_match_t;
typedef parse_tree_match_t::const_tree_iterator	iter_t;

class Parser
{
public:
  Parser();
  Parser(bool	write,
	 bool	print,
	 bool	print_xml);
  ~Parser ();

  void	visit(Visitor&	v);
  void	parse(std::string	file);
  void  transf_input (iter_t const& node);
  void	transform (const boost::spirit::tree_parse_info<>&	info);
  Ast&	transf_instruction (iter_t const&      	node);
  Ast&	transf_expression (iter_t const&	node);
  int	transf_reg (iter_t const&		node);
  Ast&	transf_term (iter_t const&		node);
  Ast&	transf_factor (iter_t const&		node);
  Ast&	transf_integer (iter_t const&		node);

  int fault;
  enum {
    integer_ID = 1,
    instruction_ID,
    expression_ID,
    term_ID,
    factor_ID,
    reg_ID,
    label_ID,
    label_def_ID,
    guide_lines_ID,
    input_ID,
    no_node_ID
  };
private:
  // store_lbl functor to store a label in singleton Labels
  struct StoreLbl
  {
    StoreLbl (size_t*	offset);
    ~StoreLbl ();

    void	operator() (iterator_t	beg,
			    iterator_t	end) const;
    size_t*	offset_;
  };

  // functor to increment offset by parameter inc.
  // Usefull for StoreLbl
  template<int	inc>
  struct IncOffset
  {
    IncOffset (size_t*	offset);
    ~IncOffset ();

    void	operator() (iterator_t	beg,
			    iterator_t	end) const;
    size_t*	offset_;
  };
  // ---------------- BOOST SPIRIT --------------------------------------------

  struct PitGrammar : public boost::spirit::grammar<PitGrammar>
  {
    template <typename ScannerT>
    struct definition
    {
      void	init_rule ();
      void	init_rule_bis ();

      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<integer_ID> >
      integer;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<instruction_ID> >
      instruction;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<expression_ID> >
      expression;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<term_ID> >
      term;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<factor_ID> >
      factor;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<reg_ID> >
      reg;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<label_ID> >
      label;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<label_def_ID> >
      label_def;
      boost::spirit::rule<ScannerT, boost::spirit::parser_context<>,
			  boost::spirit::parser_tag<guide_lines_ID> >
      guide_lines;

      // input rule
      boost::spirit::rule<ScannerT>	input;


      definition(PitGrammar const& self);
      boost::spirit::rule<ScannerT> const& start() const;


      size_t	offset_;
      StoreLbl	str_lbl;
      //      IncOffset	inc_off;
    };
  };

  std::vector<Ast*>	vect_;
  std::string		name_;
  std::string		comment_;
  bool			write_;
  bool			print_;
  bool			print_xml_;

  // for norm
  void	eparse (boost::spirit::tree_parse_info<>& info, std::string	file);

};

#endif	// !PARSER_HH_
