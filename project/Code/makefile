main: *.cpp
	g++ -g *.cpp -o main
	
run:
	./main
	
clean:
	rm *.o main
	
leak_check:
	valgrind --leak-check=yes ./main
	
gdb:
	gdb ./main