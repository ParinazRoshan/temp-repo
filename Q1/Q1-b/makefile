CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = Q1.o map.o
TARGET = Q1

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
Q1.o: Q1.cpp
	$(CXX) $(CXXFLAGS) Q1.cpp
map.o: map.cpp map.h
	$(CXX) $(CXXFLAGS) map.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
