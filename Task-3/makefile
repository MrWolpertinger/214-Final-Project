ofiles = main.o CountryGroup.o Country.o
gpp_o = g++ -g -c -std=c++11 -static
 
main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main

main.o: main.cpp AlliedForce.h CountryGroup.h Country.h
	$(gpp_o) main.cpp

CountryGroup.o: AlliedForce.h CountryGroup.cpp CountryGroup.h Country.h
	$(gpp_o) CountryGroup.cpp

Country.o: AlliedForce.h Country.cpp Country.h
	$(gpp_o) Country.cpp

run: main
	./main

clean:
	rm *.o main