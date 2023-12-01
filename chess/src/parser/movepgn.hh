#ifndef MOVEPGN_HH_
# define MOVEPGN_HH_
# include "../misc/piece-type.hh"
# include "../misc/position.hh"


enum movetype
{
  NORMAL,
  ROQUE,
  GROQUE,
  CAPTURE
};


class MovePGN
{
  public:
    MovePGN ()
      :  typemove_(NORMAL),
	 dest_ (Position(Position::FILE_FIRST,
			 Position::RANK_FIRST)),
	 ambRank_ (Position::RANK_FIRST),
	 ambFile_ (Position::FILE_FIRST),
	 typepiece_ (PAWN),
	 promu_ (NONE),
	 promotion_ (false),
	 mat_ (false),
	 echec_ (false)
    {
    }

    void
    typemove_set (movetype typemove);
    void
    dest_set (Position P);


    void
    ambFile_set (Position::File ambFile);
    void
    ambRank_set (Position::Rank ambRank);
    void
    typepiece_set (PieceType typepiece);
    void
    promu_set (PieceType promu);
    void
    promotion_set (bool b);
    void
    mat_set (bool b);
    void
    echec_set (bool b);
    movetype
    typemove_get ();
    Position
    dest_get ();
    Position::File
    ambFile_get ();
    Position::Rank
    ambRank_get ();
    PieceType
    typepiece_get ();
    PieceType
    promu_get ();
    bool
    promotion_get ();
    bool
    mat_get ();
    bool
    echec_get ();

  private:
    movetype typemove_;
    Position dest_;
    Position::Rank ambRank_;
    Position::File ambFile_;
    PieceType typepiece_;
    PieceType promu_;
    bool promotion_;
    bool mat_;
    bool echec_;
};

std::ostream&
operator<< (std::ostream& ost, MovePGN& move);
#endif /* !MOVEPGN_HH_ */
