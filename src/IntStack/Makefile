
OBJS = main.o IntStack.o

stack : ${OBJS}
	g++ -o $@ ${OBJS}

main.o IntStack.o : IntStack.h

clean : rm ${OBJS}
