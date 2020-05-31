



unitTestMain: unitTestMain.o modelGame.o
	g++ -o unitTestMain unitTestMain.o modelGame.o

modelGame.o: modelGame.cpp modelGame.h
	g++ -c modelGame.cpp

unitTestMain.o: unitTestMain.cpp 
	g++ -c unitTestMain.cpp

clean:
	rm *.o unitTestMain