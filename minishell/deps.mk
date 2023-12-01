lib_string.o: lib_string.c lib_string.h
utils.o: utils.c lib_string.h utils.h
utils_str.o: utils_str.c lib_string.h utils.h utils_str.h
builtin.o: builtin.c utils_str.h lib_string.h builtin.h
utils_builtin.o: utils_builtin.c lib_string.h builtin.h utils_builtin.h
utils_redir.o: utils_redir.c utils_redir.h utils_app.h utils_str.h
utils_app.o: utils_app.c utils_str.h lib_string.h utils_app.h builtin.h \
  utils_redir.h utils_builtin.h
parse_cmd.o: parse_cmd.c lib_string.h parse_cmd.h
