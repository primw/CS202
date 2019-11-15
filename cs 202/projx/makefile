output: projx.o DataType.o SmartPtr.o
	g++ projx.o DataType.o SmartPtr.o -o projx

proj7.o: projx.cpp
	g++ -c projx.cpp

DataType.o: DataType.cpp
	g++ -c DataType.cpp

SmartPtr.o: SmartPtr.cpp
	g++ -c SmartPtr.cpp


target: dependencies
	action

clean:
	rm *.o output
