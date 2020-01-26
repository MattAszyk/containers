CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

main: main.o 
	$(CXX) $(CXX_FLAGS) main.o -o main.out

clean:
	rm *.o main.out