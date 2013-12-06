CXXFLAGS = -Wall -Werror -pedantic -std=c++11
TARGET = bftr
OBJS = bftr.o Range.o Generator.o

DEBUGFLAGS = -g3 -gdwarf-2 -O0 -DDEBUG

all : debug

debug : CXXFLAGS += $(DEBUGFLAGS)
debug : $(TARGET)

release : CXXFLAGS += -O3
release : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

bftr.o : bftr.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Range.o : Range.cpp Range.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Generator.o : Generator.cpp Generator.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
