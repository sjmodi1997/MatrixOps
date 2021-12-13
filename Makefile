CC = g++
CPPFLAGS = --std=c++11 -g -Wall
#GTEST_LL = -I /opt/homebrew/Cellar/googletest/1.11.0/include/gtest -l gtest -l gtest_main -pthread

exe: main.o Matrix.o
	$(CC) $(CPPFLAGS) main.o Matrix.o -o exe

Matrix.o: Matrix.cpp Matrix.h
	$(CC) $(CPPFLAGS) -c Matrix.cpp 

main.o: main.cpp Matrix.h
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	-@rm -f *.o
	-@rm -f exe
	-@echo "--- All Clean! ---"