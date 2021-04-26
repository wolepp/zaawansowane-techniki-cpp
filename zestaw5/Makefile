CXX=g++
CXXFLAGS=-std=c++20 -Wall

# Compile all cpp files into standalone executables
ALL: $(patsubst %.cpp, %.x, $(wildcard *.cpp))

%.x: %.cpp Makefile
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.x *.o
