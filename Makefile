all: bin/chess

bin/chess: obj/src/chess/main.o obj/src/libchess/libchess.a
		gcc -Wall -Werror -I src -o bin/chess obj/src/chess/main.o obj/src/libchess/libchess.a

obj/src/libchess/libchess.a: obj/src/libchess/turning.o 
		ar rcs obj/src/libchess/libchess.a obj/src/libchess/turning.o

obj/src/chess/main.o: src/chess/main.c
		gcc -Wall -Werror -c -I src -o obj/src/chess/main.o src/chess/main.c

obj/src/libchess/turning.o: src/libchess/turning.c
		gcc -Wall -Werror -c -I src -o obj/src/libchess/turning.o src/libchess/turning.c

test: bin/test

bin/test: obj/test/tests.o obj/test/main.o obj/test/libchess.a
	gcc -Wall -I thirdparty -I src -Werror -o bin/test obj/test/tests.o obj/test/main.o obj/test/libchess.a

obj/test/libchess.a: obj/src/libchess/turning.o 
		ar rcs obj/test/libchess.a obj/src/libchess/turning.o

obj/test/main.o: test/main.c
	gcc -Wall -I thirdparty -I src -Werror -c -o obj/test/main.o test/main.c

obj/test/tests.o: test/tests.c
	gcc -Wall -I thirdparty -I src -Werror -c -o obj/test/tests.o test/tests.c

.PHONY : clean;

clean:
		rm -rf obj/src/chess/*.o obj/src/libchess/*.o obj/src/libchess/*.a obj/test/*.o obj/test/*.a bin/chess bin/test