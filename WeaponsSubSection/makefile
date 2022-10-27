main: *.o
	g++	-g -o	main  *.o

*.o:	*.cpp
	g++	-g	-c	*.cpp HeavyWeightWeapons/*.cpp LightWeightWeapons/*.cpp WeaponsFactory/*.cpp

run:
	./main

clean:
	rm	*.o	main