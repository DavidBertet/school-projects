#ifndef USE_LISTENER_HH_
# define USE_LISTENER_HH_

# include <list>
# include "listener.hh"

void register_chessboard_adapter (std::list<Listener*>& listener,
				  const ChessboardAdapter& chessboard_adapter);

void on_game_started (std::list<Listener*>& listener);

void on_game_finished (std::list<Listener*>& listener);

void on_piece_moved (std::list<Listener*>& listener,
		     const PieceType& piece,
		     const Position& from,
		     const Position& to);

void on_piece_taken (std::list<Listener*>& listener,
		     const PieceType& piece,
		     const Position& at);

void on_piece_promoted (std::list<Listener*>& listener,
			const PieceType& piece,
			const Position& at);

void on_kingside_castling (std::list<Listener*>& listener,
			   const Color& color);

void on_queenside_castling (std::list<Listener*>& listener,
			    const Color& color);

void on_player_check (std::list<Listener*>& listener,
		      const Color& color);

void on_player_mat (std::list<Listener*>& listener,
		    const Color& color);

void on_player_pat (std::list<Listener*>& listener,
		    const Color& color);

void on_player_timeout (std::list<Listener*>& listener,
			const Color& color);

void on_player_disqualified (std::list<Listener*>& listener,
			     const Color& color);

void on_draw (std::list<Listener*>& listener);

#endif /* !USE_LISTENER_HH_ */
