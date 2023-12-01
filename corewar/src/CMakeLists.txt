SET(CMAKE_CXX_COMPILER g++42)
SET(CMAKE_VERBOSE_MAKEFILE on)

PROJECT(track CXX)
PROJECT(pit CXX)

include_directories(
 ../
 ./
 track/
 track/track/
 track/processor/
 track/instr/
 pit/
 /usr/local/include
 pit/asts/
 pit/visitor/
 pit/error/
)

SET(TRACK_SRCS
 track/main
 track/processor/processor_vector
 track/processor/processor_venom
 track/processor/processor_rapier
 track/processor/processor_phantom
 track/track/track_vector
 track/track/track_venom
 track/track/track_rapier
 track/track/track_phantom
 track/quartet
 track/buffer
 track/fetchqueue
 track/delays
 track/parse_opt
 track/file_loader
 track/debug
 track/instr/instr
 track/instr/nop_track
 track/instr/crash_track
 track/instr/ll_track
 track/instr/lc_track
 track/instr/add_track
 track/instr/sub_track
 track/instr/cmp_track
 track/instr/addi_track
 track/instr/cmpi_track
 track/instr/neg_track
 track/instr/asr_track
 track/instr/swp_track
 track/instr/mov_track
 track/instr/check_track
 track/instr/mode_track
 track/instr/stat_track
 track/instr/str_track
 track/instr/b_track
 track/instr/bs_track
 track/instr/bz_track
 track/instr/bnz_track
 track/instr/ldb_track
 track/instr/stb_track
 track/instr/write_track
 track/instr/and_track
 track/instr/or_track
 track/instr/xor_track
 track/instr/not_track
)

SET(PIT_SRCS
  pit/main
  pit/parser
  pit/token
  pit/ast
  pit/visitor/visitor
  pit/visitor/ast-print
  pit/visitor/writter
  pit/visitor/evaluator
  pit/error/exeption
  pit/labels
  pit/asts/add
  pit/asts/addi
  pit/asts/and
  pit/asts/asr
  pit/asts/b
  pit/asts/bnz
  pit/asts/bs
  pit/asts/bz
  pit/asts/check
  pit/asts/cmp
  pit/asts/cmpi
  pit/asts/crash
  pit/asts/fork
  pit/asts/lc
  pit/asts/ldb
  pit/asts/ldr
  pit/asts/ll
  pit/asts/mode
  pit/asts/mov
  pit/asts/neg
  pit/asts/nop
  pit/asts/not
  pit/asts/or
  pit/asts/rol
  pit/asts/stat
  pit/asts/stb
  pit/asts/str
  pit/asts/sub
  pit/asts/swp
  pit/asts/write
  pit/asts/xor
  pit/asts/plus
  pit/asts/minus
  pit/asts/value
  pit/asts/modulo
  pit/asts/mult
  pit/asts/div
)


ADD_EXECUTABLE(track ${TRACK_SRCS})
ADD_EXECUTABLE(pit ${PIT_SRCS})
