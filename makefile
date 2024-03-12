CC = gcc
AR = ar 
FLAGS = -Wall -g
CFLAGS = -fPIC
HEADER_NUMCLASS = NumClass.h
OBJECT_MAIN = main.o
OBJECT_BASIC = basicClassification.o
OBJECT_RECURSION = advancedClassificationRecursion.o
OBJECT_LOOP = advancedClassificationLoop.o

all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so

libclassloops.a: $(OBJECT_BASIC) $(OBJECT_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_BASIC) $(OBJECT_LOOP)

libclassrec.a: $(OBJECT_BASIC) $(OBJECT_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECT_BASIC) $(OBJECT_RECURSION)

libclassrec.so: $(OBJECT_BASIC) $(OBJECT_RECURSION)
	$(CC) $(FLAGS) -shared $(CFLAGS) -o libclassrec.so $(OBJECT_BASIC) $(OBJECT_RECURSION)	

libclassloops.so: $(OBJECT_BASIC) $(OBJECT_LOOP)
	$(CC) $(FLAGS) -shared $(CFLAGS) -o libclassloops.so $(OBJECT_BASIC) $(OBJECT_LOOP)	

mains: $(OBJECT_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECT_MAIN) libclassrec.a -lm

maindloop: $(OBJECT_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECT_MAIN) ./libclassloops.so -lm

maindrec: $(OBJECT_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECT_MAIN) ./libclassrec.so -lm

$(OBJECT_MAIN): main.c $(HEADER_NUMCLASS) 
	$(CC) $(FLAGS) -c main.c

$(OBJECT_BASIC): basicClassification.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c basicClassification.c

$(OBJECT_RECURSION): advancedClassificationRecursion.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c advancedClassificationRecursion.c	

$(OBJECT_LOOP): advancedClassificationLoop.c	$(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c advancedClassificationLoop.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.gch mains maindloop maindrec
