s21_grep:
	gcc -Wall -Werror -Wextra -std=c11 grep.c parser.c reader.c grep.h -o s21_grep

tests:
	sh ./grep_tests/test_func_grep.sh

clean:
	rm -rf *.o *.a *.so src/*.o

rebuild:
	make clean && make
