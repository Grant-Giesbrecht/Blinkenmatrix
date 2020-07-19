CC = clang++

EXE = blinkenmat

LIBS = -L/Users/grantgiesbrecht/Documents/GitHub/gstd -lgstd -I/Users/grantgiesbrecht/Documents/GitHub/gstd

main: blinkenmat.cpp
	$(CC) -o $(EXE) blinkenmat.cpp -std=c++11 $(LIBS)
