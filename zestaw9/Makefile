CXX=g++
CXXFLAGS=-std=c++20 -Wall

# Compile all cpp files into standalone executables
ALL: $(patsubst %.cpp, %.x, $(wildcard *.cpp))

optim: $(patsubst %.cpp, %.xopt, $(wildcard *.cpp))

%.x: %.cpp Makefile
	$(CXX) $< -o $@ $(CXXFLAGS)

%.xopt: %.cpp Makefile
	$(CXX) $< -o $@ $(CXXFLAGS) -O1

clean:
	rm -f *.x *.o *.xopt
