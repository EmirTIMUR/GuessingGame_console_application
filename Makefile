
CXX = g++
CXXFLAGS = -g -Wall -std=c++11
LIBS = -lm

PROGRAM = GuessingGame
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean install

install: all

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(PROGRAM)

