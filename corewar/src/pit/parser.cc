#include "parser.hh"
#include <fstream>
#include <sstream>

# include <iostream>
# include <string>

#include <boost/spirit/utility.hpp>

# include "crash.hh"
# include "nop.hh"
# include "and.hh"
# include "or.hh"
# include "xor.hh"
# include "not.hh"
# include "rol.hh"
# include "asr.hh"
# include "add.hh"
# include "sub.hh"
# include "cmp.hh"
# include "neg.hh"
# include "mov.hh"
# include "ldr.hh"
# include "str.hh"
# include "ldb.hh"
# include "stb.hh"
# include "lc.hh"
# include "ll.hh"
# include "swp.hh"
# include "addi.hh"
# include "cmpi.hh"
# include "b.hh"
# include "bz.hh"
# include "bnz.hh"
# include "bs.hh"
# include "stat.hh"
# include "check.hh"
# include "mode.hh"
# include "fork.hh"
# include "write.hh"
# include "plus.hh"
# include "minus.hh"
# include "div.hh"
# include "mult.hh"
# include "modulo.hh"
# include "value.hh"

# include "ast-print.hh"
# include "writter.hh"
# include "evaluator.hh"
# include "labels.hh"
# include "exeption.hh"


void
print(char const*	d, char const*	e) {
  std::string	msg (d, e);
  std::cout << "BEG " << msg << std::endl;
}


Parser::Parser ()
 : write_ (true),
   print_ (false),
   print_xml_ (false)
{
}

Parser::Parser(bool	write,
	       bool	print,
	       bool	print_xml)
  : write_ (write),
    print_ (print),
    print_xml_ (print_xml)
{
}

Parser::~Parser ()
{
}


Parser::StoreLbl::StoreLbl(size_t*	offset)
  : offset_ (offset)
{
}

Parser::StoreLbl::~StoreLbl()
{
}

void
Parser::StoreLbl::operator() (iterator_t	beg,
			      iterator_t	end) const
{
  std::string	slbl = std::string (beg, end);
#ifdef DEBUG_LBL
  std::cout << "storing lbl <" << slbl
	    << "> at " << *offset_ << std::endl;
#endif	// DEBUG_LBL

  Labels&	lbls = Labels::instance_get ();

  lbls.labels_set (slbl, *offset_);
}

template<int	inc>
Parser::IncOffset<inc>::IncOffset(size_t*	offset)
  : offset_ (offset)
{
}

template<int	inc>
Parser::IncOffset<inc>::~IncOffset()
{
}

template<int	inc>
void
Parser::IncOffset<inc>::operator() (iterator_t	b,
				    iterator_t	e) const
{
  iterator_t	nop = e;

  nop = b;
#ifdef DEBUG_LBL
  std::cout << std::string (b, e) << " incrementing offset of "
	    << inc << std::endl;
#endif	// DEBUG_LBL
  if (*offset_ >= 65536)
    throw Error ("Offset code can't be > 65536");
  *offset_ += inc;
}

template <typename	ScannerT>
boost::spirit::rule<ScannerT> const&
Parser::PitGrammar::definition<ScannerT>::start () const
{
  return input;
}

template <typename	ScannerT>
void
Parser::PitGrammar::definition<ScannerT>::init_rule ()
{
  label = boost::spirit::lexeme_d
    [boost::spirit::token_node_d
     [boost::spirit::alpha_p
      // to correct no _ at end...
      >> *(boost::spirit::alpha_p | boost::spirit::digit_p | '_')]];

  integer = boost::spirit::lexeme_d
    [(boost::spirit::token_node_d["0x" >> boost::spirit::hex_p]) |
     (boost::spirit::token_node_d["0" >> boost::spirit::oct_p]) |
     (boost::spirit::token_node_d["%" >> +(boost::spirit::ch_p ('1') | '0')]) |
     (boost::spirit::token_node_d[(!boost::spirit::ch_p('-') >>
				   *boost::spirit::digit_p)])];

  factor =
    (boost::spirit::no_node_d[boost::spirit::ch_p ('(')]
     >> expression >> boost::spirit::no_node_d[boost::spirit::ch_p (')')])
    // how to manage
    | ('-' >> factor)
    | label
    | integer
    ;

  term =
    factor >>
    *((boost::spirit::root_node_d[boost::spirit::ch_p ('*')] >> factor) |
      (boost::spirit::root_node_d[boost::spirit::ch_p ('%')] >> factor) |
      (boost::spirit::root_node_d[boost::spirit::ch_p ('/')] >> factor)
      );

  expression = term >>
    *((boost::spirit::root_node_d[boost::spirit::ch_p ('+')] >> term) |
      (boost::spirit::root_node_d[boost::spirit::ch_p ('-')] >> term)
      );

  reg = boost::spirit::lexeme_d
    [boost::spirit::no_node_d[ boost::spirit::ch_p('r')]
     >> boost::spirit::token_node_d
     [boost::spirit::digit_p
      >> !boost::spirit::range_p ('0', '5')]];

  label_def = boost::spirit::lexeme_d
    [(boost::spirit::token_node_d
      [boost::spirit::alpha_p
       // to correct no _ at end...
       >> *(boost::spirit::alpha_p | boost::spirit::digit_p | '_')][str_lbl])
     >> boost::spirit::ch_p (':')];
}

template <typename	ScannerT>
void
Parser::PitGrammar::definition<ScannerT>::init_rule_bis ()
{
  // case sensitive + one space mandatory after instruction
  instruction =
    boost::spirit::str_p ("crash")[IncOffset<1> (&offset_)] |
    boost::spirit::str_p ("nop")[IncOffset<1> (&offset_)] |
    (boost::spirit::str_p ("and") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("or") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("xor") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("not") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("rol") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("asr") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("add") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("sub") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("cmp") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("neg") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("mov") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("ldr") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> '[' >>reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (']')])
    [IncOffset<3> (&offset_)]|
    (boost::spirit::str_p ("str")
     >> boost::spirit::no_node_d[boost::spirit::ch_p ('[')]
     >> reg >> boost::spirit::no_node_d[boost::spirit::ch_p (']')]
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("ldb")
     >> boost::spirit::no_node_d[boost::spirit::ch_p ('[')] >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (']')]
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')]
     >> expression
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<7> (&offset_)] |
    (boost::spirit::str_p ("stb")
     >> boost::spirit::no_node_d[boost::spirit::ch_p ('[')]
     >> reg >> boost::spirit::no_node_d[boost::spirit::ch_p (']')]
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')]
     >> expression
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<7> (&offset_)] |
    (boost::spirit::str_p ("lc") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<5> (&offset_)] |
    (boost::spirit::str_p ("ll") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<7> (&offset_)] |
    (boost::spirit::str_p ("swp") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> reg)
    [IncOffset<4> (&offset_)] |
    (boost::spirit::str_p ("addi") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<4> (&offset_)] |
    (boost::spirit::str_p ("addi") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<4> (&offset_)] |
    (boost::spirit::str_p ("cmpi") >> reg
     >> boost::spirit::no_node_d[boost::spirit::ch_p (',')] >> expression)
    [IncOffset<4> (&offset_)] |
    (boost::spirit::str_p ("b") >> reg)[IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("bz") >> reg)[IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("bnz") >> reg)[IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("bs") >> reg)[IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("stat") >> reg
     >> boost::spirit::no_node_d [ boost::spirit::ch_p(',')] >> expression)
    [IncOffset<4> (&offset_)] |
    (boost::spirit::str_p ("check"))[IncOffset<2> (&offset_)] |
    (boost::spirit::str_p ("mode")
     >> (boost::spirit::str_p ("feisar") | "goteki45" | "agsystems" | "auricom"
	 | "assegai" | "piranha" | "qirex" | "icaras" | "rocket" | "missile" |
	 "mine" | "plasma" | "miniplasma"))[IncOffset<3> (&offset_)] |
    (boost::spirit::str_p ("fork"))[IncOffset<2> (&offset_)] |
    (boost::spirit::str_p ("write") >> reg)[IncOffset<3> (&offset_)];
}

template <typename	ScannerT>
Parser::PitGrammar::definition<ScannerT>::definition
(Parser::PitGrammar const&)
  : offset_ (0),
    str_lbl (StoreLbl (&offset_))
{
  //  Start grammar definition
  init_rule ();
  init_rule_bis ();

  guide_lines = boost::spirit::lexeme_d
    [boost::spirit::token_node_d
     [boost::spirit::ch_p ('.')
      // verify spec on this rule
      >> +(boost::spirit::alpha_p | boost::spirit::digit_p)]]
    >> boost::spirit::lexeme_d
    [boost::spirit::token_node_d
     [boost::spirit::confix_p
      (boost::spirit::no_node_d[boost::spirit::ch_p ('"')],
       *boost::spirit::c_escape_ch_p,
       boost::spirit::no_node_d[boost::spirit::ch_p ('"')])]];

  input =
    (guide_lines |
     instruction |
     label_def) >> !input;
  //  End grammar definition
}

void
Parser::eparse (boost::spirit::tree_parse_info<>& info, std::string	file)
{
  if (info.full)
    {
      fault = 0;
      // print the result
      Visitor&		p = *new AstPrint ();
      Writter&		w = *new Writter ();
      Evaluator&	e = *new Evaluator ();

      transform(info);
      for (unsigned int i = 0; i < vect_.size (); ++i)
	{
	  vect_[i]->accept (e);
	  if (print_)
	    vect_[i]->accept (p);

	  if (write_)
	    vect_[i]->accept (w);
	}

      if (write_)
	{
	  size_t	cmt2 = file.find (".s");
	  std::string	out ("");

	  if (cmt2 == std::string::npos)
	    out.append(file + ".cor");
	  else
	    out.append(file.substr (0, cmt2) + ".cor");

	  std::ofstream	file_s (out.c_str (),
				std::ios::out | std::ios::binary);
	  w.write (file_s, name_, comment_);
	  file_s.close ();
	}
    }
  else
    fault = 1;
}

void
Parser::parse (std::string	file)
{
  std::ifstream	in (file.c_str ());

  fault = 0;
  std::string	line;
  std::string	input ("");

  while (getline(in, line))
    {
      size_t	cmt = line.find ('#');
      // handle \n
      if (cmt == std::string::npos)
	input.append(line + " ");
      else
	input.append(line.substr (0, cmt) + " ");
    }
  in.close ();
  PitGrammar	g;
  boost::spirit::tree_parse_info<> info =
    ast_parse(input.c_str (), g, boost::spirit::blank_p);

  if (print_xml_)
    {
      // dump parse tree as XML
      std::map<boost::spirit::parser_id, std::string> rule_names;
      rule_names[Parser::integer_ID] = "integer";
      rule_names[Parser::factor_ID] = "factor";
      rule_names[Parser::term_ID] = "term";
      rule_names[Parser::expression_ID] = "expression";
      rule_names[Parser::instruction_ID] = "instruction";
      rule_names[Parser::label_def_ID] = "label definition";
      rule_names[Parser::label_ID] = "label";
      rule_names[Parser::reg_ID] = "register";
      rule_names[Parser::guide_lines_ID] = "guideline";
      tree_to_xml(std::cout, info.trees, input.c_str (), rule_names);
    }

  eparse (info, file);
}

void
Parser::transform (const boost::spirit::tree_parse_info<>&	info)
{
  (void) info;
  transf_input(info.trees.begin());
}


void
Parser::transf_input (iter_t const& node)
{
  if (node->value.id () == Parser::instruction_ID)
  {
    Ast* test;
    vect_.push_back (test = (&(transf_instruction (node))));
    assert (test != NULL);
    return;
  }
  if (node->value.id () == Parser::guide_lines_ID)
  {
    iter_t	chld = node->children.begin ();
    std::string	val = std::string (chld->value.begin (), chld->value.end ());

    ++chld;

    if (".name" == val)
    {
      name_ = std::string (chld->value.begin (), chld->value.end ());
      assert (++chld == node->children.end ());
    }
    else if (".comment" == val)
      comment_ = std::string (chld->value.begin (), chld->value.end ());
    else
    {
      throw Error (val + " undefined guideline");
    }
    return;
  }
  if (node->value.id () == Parser::label_def_ID)
  {
    // already parsed by functor
    return;
  }
  assert((node->value.id () != Parser::integer_ID) &&
         (node->value.id () != Parser::instruction_ID) &&
         (node->value.id () != Parser::expression_ID) &&
         (node->value.id () != Parser::term_ID) &&
         (node->value.id () != Parser::factor_ID) &&
         (node->value.id () != Parser::reg_ID) &&
         (node->value.id () != Parser::label_ID) &&
         (node->value.id () != Parser::label_def_ID) &&
         (node->value.id () != Parser::guide_lines_ID) &&
         (node->value.id () != Parser::input_ID));

  for (iter_t child = node->children.begin (); child != node->children.end (); ++child)
  {
    transf_input (child);
  }
}

static	Ast&	transf_instr1 (iter_t const&,
			       std::string&	chld_str,
			       iter_t&		node_ch,
			       Parser*		p)
{
  if (chld_str == "mode")
  {
    Mode& ast = *(new Mode);
    ++node_ch;
    chld_str.assign (node_ch->value.begin (), node_ch->value.end ());

    int	val = -1;
    if (chld_str == "feisar")
      val = 0;
    if (chld_str == "goteki45")
      val = 1;
    if (chld_str == "agsystems")
      val = 2;
    if (chld_str == "auricom")
      val = 3;
    if (chld_str == "assegai")
      val = 4;
    if (chld_str == "piranha")
      val = 5;
    if (chld_str == "qirex")
      val = 6;
    if (chld_str == "icaras")
      val = 7;
    if (chld_str == "rocket")
      val = 8;
    if (chld_str == "missile")
      val = 9;
    if (chld_str == "mine")
      val = 10;
    if (chld_str == "plasma")
      val = 11;
    if (chld_str == "miniplasma")
      val = 12;

    if (-1 == val)
      throw Error ("Unknown mode " + chld_str);

    ast.m_set (*new Value (val, chld_str));
    return ast;
  }

  if (chld_str  == "fork")
    return *(new Fork);

  if (chld_str == "write")
  {
    Write& ast = *(new Write);
    ast.rx_set (p->transf_reg (++node_ch));
    return ast;
  }

  assert (true);
  return *(new Nop);
}

static	Ast&	transf_instr2 (iter_t const&	node,
			       std::string&	chld_str,
			       iter_t&		node_ch,
			       Parser*		p)
{
  if (chld_str == "cmpi")
  {
    Cmpi& ast = *(new Cmpi);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "b")
  {
    B& ast = *(new B);
    ast.rx_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "bz")
  {
    Bz& ast = *(new Bz);
    ast.rx_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "bnz")
  {
    Bnz& ast = *(new Bnz);
    ast.rx_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "bs")
  {
    Bs& ast = *(new Bs);
    ast.rx_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "stat")
  {
    Stat& ast = *(new Stat);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str  == "check")
  {
    Check& ast = *(new Check);
    return ast;
  }

  return transf_instr1 (node, chld_str, node_ch, p);
}

static	Ast&	transf_instr3 (iter_t const&	node,
			       std::string&	chld_str,
			       iter_t&		node_ch,
			       Parser*		p)
{
  if (chld_str == "ldb")
  {
    Ldb& ast = *(new Ldb);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    ast.m_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "stb")
  {
    Stb& ast = *(new Stb);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    ast.m_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "ll")
  {
    Ll& ast = *(new Ll);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "lc")
  {
    Lc& ast = *(new Lc);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "swp")
  {
    Swp& ast = *(new Swp);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "addi")
  {
    Addi& ast = *(new Addi);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  return transf_instr2 (node, chld_str, node_ch, p);
}

static	Ast&	transf_instr4 (iter_t const&	node,
			       std::string&	chld_str,
			       iter_t&		node_ch,
			       Parser*		p)
{
  if (chld_str == "add")
  {
    Add& ast = *(new Add);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "sub")
  {
    Sub& ast = *(new Sub);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "cmp")
  {
    Cmp& ast = *(new Cmp);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "neg")
  {
    Neg& ast = *(new Neg);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "mov")
  {
    Mov& ast = *(new Mov);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "ldr")
  {
    Ldr& ast = *(new Ldr);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "str")
  {
    Str& ast = *(new Str);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  return transf_instr3 (node, chld_str, node_ch, p);
}

static	Ast&	transf_instr5 (iter_t const&	node,
			       std::string&	chld_str,
			       iter_t&		node_ch,
			       Parser*		p)
{
  if (chld_str == "and")
  {
    And& ast = *(new And);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "or")
  {
    Or& ast = *(new Or);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "xor")
  {
    Xor& ast = *(new Xor);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "not")
  {
    Not& ast = *(new Not);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.ry_set (p->transf_reg (++node_ch));
    return ast;
  }

  if (chld_str == "rol")
  {
    Rol& ast = *(new Rol);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  if (chld_str == "asr")
  {
    Asr& ast = *(new Asr);
    ast.rx_set (p->transf_reg (++node_ch));
    ast.n_set (p->transf_expression (++node_ch));
    return ast;
  }

  return transf_instr4 (node, chld_str, node_ch, p);
}

Ast&
Parser::transf_instruction (iter_t const&	node)
{
  assert(node->value.id () == Parser::instruction_ID);


  std::string	chld_str (node->value.begin (), node->value.end ());


  if (chld_str  == "crash")
  {
    Ast& crash = *(new Crash);
    return crash;
  }
  if (chld_str == "nop")
  {
    Ast& nop = *(new Nop);
    return nop;
  }
  if (chld_str  == "check")
  {
    Ast& crash = *(new Check);
    return crash;
  }
  if (chld_str  == "fork")
  {
    Ast& crash = *(new Fork);
    return crash;
  }

  iter_t node_ch = node->children.begin ();
  assert((node_ch->value.id () != Parser::integer_ID) &&
         (node_ch->value.id () != Parser::instruction_ID) &&
         (node->value.id () != Parser::expression_ID) &&
         (node_ch->value.id () != Parser::term_ID) &&
         (node_ch->value.id () != Parser::factor_ID) &&
         (node_ch->value.id () != Parser::reg_ID) &&
         (node_ch->value.id () != Parser::label_ID) &&
         (node_ch->value.id () != Parser::label_def_ID) &&
         (node_ch->value.id () != Parser::guide_lines_ID) &&
         (node_ch->value.id () != Parser::input_ID));

  chld_str.assign (node_ch->value.begin (), node_ch->value.end ());
  if (chld_str == "crash")
    return *new Crash;
  if (chld_str == "nop")
    return *new Nop;

  return transf_instr5 (node, chld_str, node_ch, this);
}

int
Parser::transf_reg (iter_t const& node)
{
  int res;
  std::string		str (node->value.begin (), node->value.end ());
  std::istringstream	iss (str);

  iss >> res;

  assert (!iss.fail ());
  return res;
}


/*!
** Find if a number is inside the correct base
**
** @param c The number
** @param type The type of the base, 1 for binary, 2 for octal, 3 for decimal,
** otherwise it's in hexadecimal
**
** @return Bool, true if it's ok, false otherwise
*/
static bool
is_correct_number (char c, int type)
{
  if (type == 1) //binary
    return c >= '0' && c <= '1';
  if (type == 2) //octal
    return c >= '0' && c <= '7';
  if (type == 3) //decimal
    return c >= '0' && c <= '9';
  else //hexa
    return (c >= '0' && c <= '9' || (std::tolower(c) >= 'a' && std::tolower(c) <= 'f'));
}

static int
get_num (std::string&		str,
	 int&			num,
	 std::stringstream&	ss)
{
  int number;

  if (num == 1)
    {
      number = std::bitset<std::numeric_limits<unsigned long>::digits>
	(std::string(ss.str())).to_ulong();
      return number;
    }
  if (num == 2)
    {
      ss >> std::oct >> number;
      if (ss.fail ())
	throw Error ("Syntax error on " + str);
      return number;
    }
  if (num == 3)
    {
      ss >> std::dec >> number;
      if (ss.fail ())
	throw Error ("Syntax error on " + str);
      return number;
    }
  if (num == 4)
    {
      ss >> std::hex >> number;
      if (ss.fail ())
	throw Error ("Syntax error on " + str);
      return number;
    }
  throw Error ("Syntax error on " + str);
}
/*!
** Search if the parameter is a number (binary, octal, decimal, hexadecimal)
**
** @param str The string to parse
**
** @return return 0 if its not a number
** return 1 if its a syntax error
** return 2 if its a valid number
*/
static int
match_number (std::string&	str)
{
  int			num = 0;
  int			pos = 1;
  std::stringstream	ss;

  //find the type of number
  if (str[0] == '%')
    num = 1;
  if (is_correct_number (str[0], 3))
    {
      ss << str[0];
      num = 3;
    }
  if (str[0] == '0')
    {
      if (str[1] == 'x')
	{
	  pos = 2;
	  num = 4;
	}
      else
	num = 2;
    }

  //if it's a number, find it
  if (num)
    {
      for (unsigned int i = pos; i < str.size (); ++i)
	{
	  if (is_correct_number (str[i], num))
	    ss << str[i];
	  else if  (str[i] != '_')
	    throw Error (str + " is a bad number");
	}
      if (is_correct_number (str[str.size() - 1], num))
	{
	  return get_num (str, num, ss);
	}
      else
	throw Error ("Syntax error on " + str);
    }
  throw Error ("Syntax error on " + str);
}

static Ast&
transf_expression2 (iter_t const&	node,
		    iter_t&		chld,
		    Parser*		p)
{
  if (node->value.id () == Parser::integer_ID)
  {
    std::string	str = std::string (node->value.begin (),
                                   node->value.end ());

    Value&	val = *new Value (match_number (str), str);

    return val;
  }

  if (node->value.id () == Parser::factor_ID)
  {
    std::string	str = std::string (chld->value.begin (),
                                   chld->value.end ());

    assert (str == "-");

    Minus&	min = *new Minus ();

    min.fg_set (*new Value (0, "factor " + str));
    min.fd_set (p->transf_expression (++chld));

    assert (++chld == node->children.end ());
    return min;
  }

  if (node->value.id () == Parser::label_ID)
  {
    std::string	str = std::string (node->value.begin (),
                                   node->value.end ());

    Labels&		lbls = Labels::instance_get ();

    Value&	val = *new Value (lbls.value_get (str), str);

    return val;
  }

  throw Error ("expression not handles");
}

Ast&
Parser::transf_expression (iter_t const&	node)
{
  std::string	val = std::string (node->value.begin (), node->value.end ());
  iter_t	chld = node->children.begin ();

  if (node->value.id () == Parser::expression_ID)
  {
    if ("+" == val)
    {
      Plus&	pl = *new Plus ();
      pl.fg_set (transf_expression (chld));
      pl.fd_set (transf_expression (++chld));

      assert (++chld == node->children.end ());
      return pl;
    }
    if ("-" == val)
    {
      Minus&	min = *new Minus ();
      min.fg_set (transf_expression (chld));
      min.fd_set (transf_expression (++chld));

      assert (++chld == node->children.end ());
      return min;
    }
  }

  if (node->value.id () == Parser::term_ID)
  {
    if ("*" == val)
    {
      Mult&	pl = *new Mult ();
      pl.fg_set (transf_expression (chld));
      pl.fd_set (transf_expression (++chld));

      assert (++chld == node->children.end ());
      return pl;
    }
    if ("/" == val)
    {
      Div&	min = *new Div ();
      min.fg_set (transf_expression (chld));
      min.fd_set (transf_expression (++chld));

      assert (++chld == node->children.end ());
      return min;
    }
    if ("%" == val)
    {
      Modulo&	min = *new Modulo ();
      min.fg_set (transf_expression (chld));
      min.fd_set (transf_expression (++chld));

      assert (++chld == node->children.end ());
      return min;
    }
  }

  return transf_expression2 (node, chld, this);
}
