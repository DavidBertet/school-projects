SET(CMAKE_CXX_COMPILER g++42)
SET(CMAKE_VERBOSE_MAKEFILE on)

SET(CMAKE_FIND_LIBRARY_SUFFIXES on)
SET(CMAKE_FIND_LIBRARY_PREFIXES on)

SUBDIRS(libai)

INCLUDE(FindGLU)
INCLUDE(FindGLUT)
INCLUDE(FindOpenGL)

PROJECT(chess CXX)

include_directories(
 ./
 player/
 player/ai/
 player/human/
 board/
 listener/
 misc/
 parser/
 pieces/
 error/
 ../bonus/
 /usr/pkg/include/
)

INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})

MESSAGE(STATUS "-----------------------------------------------")
MESSAGE(STATUS "opengl found: ${OPENGL_FOUND}")
MESSAGE(STATUS "include opengl: ${OPENGL_INCLUDE_DIR}")
MESSAGE(STATUS "librairie opengl: ${OPENGL_LIBRARIES}")

MESSAGE(STATUS "glut found: ${GLUT_FOUND}")
MESSAGE(STATUS "include glut: ${GLUT_INCLUDE_DIR}")
MESSAGE(STATUS "librairie glut: ${GLUT_LIBRARIES}")
MESSAGE(STATUS "-----------------------------------------------")

TARGET_LINK_LIBRARIES(chess ${OPENGL_LIBRARIES})
TARGET_LINK_LIBRARIES(chess ${GLUT_LIBRARIES})

SET(CHESS_SRCS
  player/player
  player/ai/ai
  player/ai/ai-dummy
  listener/listener
  listener/loadlistener
  listener/loaderlistener
  listener/use_listener
  misc/move
  misc/position
  board/chessboard-adapter
  board/board
  parser/chessdriver
  parser/parsechess.cc
  parser/scanchess.cc
  parser/movepgn
  pieces/queen
  pieces/bishop
  pieces/knight
  pieces/pawn
  pieces/piece
  pieces/king
  pieces/rook
  pieces/piece_visitor
  pieces/piece_move_visitor
  pieces/piece_print_visitor
  pieces/piece_get_list_visitor
  game
  error/error
  error/move_error
 )

ADD_EXECUTABLE(chess ${CHESS_SRCS} ${CHESSBONUS_SRCS})
# Create target for the parser
ADD_CUSTOM_TARGET(ChessParser echo "Creating parser.c")

# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
   SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/parser/scanchess.ll
   COMMAND /usr/bin/flex
   ARGS -o${CMAKE_CURRENT_SOURCE_DIR}/parser/scanchess.cc
           ${CMAKE_CURRENT_SOURCE_DIR}/parser/scanchess.ll
   TARGET ChessParser
   OUTPUTS ${CMAKE_CURRENT_SOURCE_DIR}/parser/scanchess.cc)

# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
   SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/parser/parsechess.yy
   COMMAND /u/prof/acu/public/bin/bison
   ARGS -y ${CMAKE_CURRENT_SOURCE_DIR}/parser/parsechess.yy
        -o ${CMAKE_CURRENT_SOURCE_DIR}/parser/parsechess.cc
   TARGET ChessParser
   DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser/scanchess.cc
   OUTPUTS ${CMAKE_CURRENT_SOURCE_DIR}/parser/parsechess.cc)

# Since parsechess.c does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(parser/parsechess.cc GENERATED)
