CXX=g++
#-m32
CXXFLAGS=-c -g -w -Wall -I../SDK/ -I./ 
LDFLAGS=-shared -s
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard ../SDK/*.cpp)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sample.so

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -g -o  $@ 

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -Rf $(OBJECTS) $(EXECUTABLE)
