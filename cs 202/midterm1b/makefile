output: proj6.o Book.o Library.o
	g++ proj6.o Book.o Library.o -o output

proj5.o: proj6.cpp
	g++ -c proj6.cpp

Book.o: Book.cpp
	g++ -c Book.cpp

Library.o: Library.cpp
	g++ -c Library.cpp

target: dependencies
	action

clean:
	rm *.o output
