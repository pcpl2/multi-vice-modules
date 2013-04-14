CXX=g++
#-m32
CXXFLAGS=-c -g -w -Wall -I../SDK/ -I./ -I./md2/ -I./md4/ -I./md5/ -I./sha1/ -I./sha2/ 
LDFLAGS=-shared -s
SOURCES=$(wildcard *.cpp)
SOURCES+=$(wildcard ../SDK/*.cpp)
SOURCES+=$(wildcard md2/*.c)
SOURCES+=$(wildcard md4/*.c)
SOURCES+=$(wildcard md5/*.c)
SOURCES+=$(wildcard sha1/*.cpp)
SOURCES+=$(wildcard sha2/*.c)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hash.so

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -g -o  $@ 

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -Rf $(OBJECTS) $(EXECUTABLE)
