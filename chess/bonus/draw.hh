#ifndef DRAW_H_
# define DRAW_H_

# include <vector>

# include "textures.hh"
# include "chessboard-adapter.hh"

void    draw_all(std::vector <s_texture_image*>& tab,
		 const ChessboardAdapter& chessboard);

#endif /* !DRAW_H_ */
