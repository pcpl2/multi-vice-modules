CC=g++
#-m32
CFLAGS=-c -g -w -Wall -I../SDK/ -I./ 
LDFLAGS=-shared -s
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard ../SDK/*.cpp)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=simple.so

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -g -o  $@ 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -Rf $(OBJECTS) $(EXECUTABLE)
