#include "movepgn.hh"

void
MovePGN::typemove_set (movetype typemove)
{
  typemove_ = typemove;
}


void
MovePGN::dest_set (Position dest)
{
  dest_ = dest;
}


void
MovePGN::ambFile_set (Position::File ambFile)
{
  ambFile_ = ambFile;

}
void
MovePGN::ambRank_set (Position::Rank ambRank)
{
  ambRank_ = ambRank;
}

void
MovePGN::typepiece_set (PieceType typepiece)
{
  typepiece_ = typepiece;
}


void
MovePGN::promu_set (PieceType promu)
{
  promu_ = promu;
}

void
MovePGN::promotion_set (bool b)
{
  promotion_ = b;
}

void
MovePGN::mat_set (bool b)
{
  mat_ = b;
}

void
MovePGN::echec_set (bool b)
{
  echec_ = b;
}

movetype
MovePGN::typemove_get ()
{
  return typemove_;
}

Position
MovePGN::dest_get ()
{
  return dest_;
}




PieceType
MovePGN::typepiece_get ()
{
  return typepiece_;
}

PieceType
MovePGN::promu_get ()
{
  return promu_;
}

bool
MovePGN::promotion_get ()
{
  return promotion_;
}

bool
MovePGN::mat_get ()
{
  return mat_;
}

bool
MovePGN::echec_get ()
{
  return echec_;
}

Position::Rank
MovePGN::ambRank_get ()
{
  return ambRank_;
}
Position::File
MovePGN::ambFile_get ()
{
  return ambFile_;
}


std::ostream&
operator<< (std::ostream& ost, MovePGN& move)
{
  if (move.promotion_get () != false)
  {
    ost <<  "la piece est promu en ";
    switch (move.promu_get ())
    {
      case KING:
	ost << "un roi";
	break;
      case QUEEN:
	ost << "une reine";
	break;
      case ROOK:
	ost << "une tour";
	break;
      case BISHOP:
	ost << "un fou";
	break;
      case KNIGHT:
	ost << "un chevalier";
	break;
      case PAWN:
	ost << "un pion";
	break;
      default:
	ost << "va te faire";
    }
  }
  if (move.echec_get ())
    ost << "echec" << std::endl;

  return ost;
}
