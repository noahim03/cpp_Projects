#Noah Im ID:923109389

CXX = g++
CXXFLAGS = -Wall

all: robot

robot: Angle.o robot.o
	$(CXX) $(CXXFLAGS) -o robot Angle.o robot.o

Angle.o: Angle.cpp Angle.h
	$(CXX) $(CXXFLAGS) -c Angle.cpp

robot.o: robot.cpp Angle.h
	$(CXX) $(CXXFLAGS) -c robot.cpp

run: robot
	./robot

clean:
	rm -f robot Angle.o robot.o