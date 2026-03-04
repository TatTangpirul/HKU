random.o:	random.h random.cpp
	g++ -c random.cpp
main.o: random.h main.cpp
	g++ -c main.cpp
main:	random.o main.o
	g++ random.o main.o -o main
run:
	./main

autotest:
	./main 100000
	./main 200000
	./main 500000
clean:
	rm -f random.o main.o main 	
.PHONY: all run autotest clean
