output: proj8.o DataType.o ArrayList.o NodeList.o
	g++ proj8.o DataType.o ArrayList.o NodeList.o -o proj8

proj7.o: proj8.cpp
	g++ -c proj8.cpp

DataType.o: DataType.cpp
	g++ -c DataType.cpp

ArrayList.o: ArrayList.cpp
	g++ -c ArrayList.cpp

NodeList.o: NodeList.cpp
	g++ -c NodeList.cpp

target: dependencies
	action

clean:
	rm *.o output
