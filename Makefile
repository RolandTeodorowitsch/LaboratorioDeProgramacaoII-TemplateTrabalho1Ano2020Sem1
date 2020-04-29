# Makefile (Roland Teodorowitsch; 29 abr. 2020)
EXECUTAVEL=app
CC=g++
CFLAGS=-c -std=c++11


all:			${EXECUTAVEL} teste

test:			teste
			@./teste
			
teste:			teste.o Cnpj.o
			@${CC} -o teste teste.o Cnpj.o

${EXECUTAVEL}:		main.o Cnpj.o
			@${CC} -o ${EXECUTAVEL}	main.o Cnpj.o

teste.o:		teste.cpp Cnpj.hpp
			@${CC} ${CFLAGS} teste.cpp

main.o:			main.cpp
			@${CC} ${CFLAGS} main.cpp

Cnpj.o:			Cnpj.cpp Cnpj.hpp
			@${CC} ${CFLAGS} Cnpj.cpp

run:			${EXECUTAVEL}
			@./${EXECUTAVEL}

clean:
			@rm -f *.o ${EXECUTAVEL} teste
