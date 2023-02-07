all: matrix

matrix: Matrix.o main.cpp
	g++ -Wall -o matrix Matrix.o main.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ -Wall -c Matrix.cpp

clean:
	rm -f matrix *.o