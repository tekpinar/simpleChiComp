#This is my Makefile for simpleChiComp.c
CC=gcc

CFLAG=-Wall -g

MYLIBDIR=/net/franz/home/bahar/tekpinar/mylib
MY_INC_DIR=${MYLIBDIR}/include
MY_SRC_DIR=${MYLIBDIR}/src

OBJ=${MYLIBDIR}/stat_functions.o

simpleChiComp.exe: simpleChiComp.o ${OBJ}
	${CC}  ${CFLAG}  -L${MYLIBDIR} simpleChiComp.o ${OBJ} -o simpleChiComp.exe -lm

simpleChiComp.o: simpleChiComp.c
	${CC}  ${CFLAG} -c -std=gnu99 -I${MY_INC_DIR} simpleChiComp.c -o simpleChiComp.o

stat_functions.o: stat_functions.c
	${CC} ${CFLAGS} -c ${MY_SRC_DIR}/stat_functions.c -I${MY_INC_DIR} -o ${MYLIBDIR}/stat_functions.o
