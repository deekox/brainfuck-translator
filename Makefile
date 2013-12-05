CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -std=c++11
TARGET = bftr
OBJS = bftr.o Range.o Generator.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

bftr.o : bftr.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Range.o : Range.cpp Range.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Generator.o : Generator.cpp Generator.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
