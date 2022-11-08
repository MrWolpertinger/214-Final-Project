main: *.cpp
	g++ -std=c++17 *.cpp -o main

run:
	./main

clean:
	rm -f *.out *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main
