CC = clang++

EXE = blinkenmat

main: blinkenmat.cpp
	$(CC) -o $(EXE) blinkenmat.cpp -std=c++11
