s21_cat:
	gcc -Wall -Werror -Wextra -std=c11 cat.c parser.c reader.c cat.h -o s21_cat

tests:
	sh ./cat_tests/test_func_cat.sh

clean:
	rm -rf *.o *.a *.so src/*.o

rebuild:
	make clean && make
