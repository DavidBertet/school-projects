SET(CMAKE_CXX_COMPILER g++42)
SET(CMAKE_VERBOSE_MAKEFILE on)

PROJECT(ai CXX)

SET (AI_SRCS
 ai
 # ai-dummy
 myai

  ../player/player
  ../listener/listener
  ../listener/loadlistener
  ../listener/loaderlistener
  ../listener/use_listener
  ../misc/move
  ../misc/position
  ../board/chessboard-adapter
  ../board/board
  ../parser/movepgn
  ../pieces/queen
  ../pieces/bishop
  ../pieces/knight
  ../pieces/pawn
  ../pieces/piece
  ../pieces/king
  ../pieces/rook
  ../pieces/piece_visitor
  ../pieces/piece_move_visitor
  ../pieces/piece_get_list_visitor
  ../pieces/piece_print_visitor
  ../error/error
  ../error/move_error
)

#Declaration da bibliotheque partagee
ADD_LIBRARY(ai SHARED ${AI_SRCS})
