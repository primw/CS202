output: proj7.o MyString.o
	g++ proj7.o MyString.o -o proj7

proj7.o: proj7.cpp
	g++ -c proj7.cpp

MyString.o: MyString.cpp
	g++ -c MyString.cpp

target: dependencies
	action

clean:
	rm *.o output
