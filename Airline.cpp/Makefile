# Do not modify this file
CXX=g++
CXXFLAGS=-Wall
assign: assign.o Airline.o Airplane.o
	$(CXX) -o $@ $^
run: assign
	./assign
clean:
	rm -f *.o assign
