CXX = g++
TARGET = quatseq.o

ifndef debuglevel
    debuglevel=0
endif

ifeq ($(debuglevel), 0)
    CXXFLAGS = -O2 -D'NDEBUG' -D'DEBUG_LEVEL=0'
else ifeq ($(debuglevel), 1)
    CXXFLAGS = -g -Wall -D'DEBUG_LEVEL=1'
else ifeq ($(debuglevel), 2)
    CXXFLAGS = -g -Wall -D'DEBUG_LEVEL=2'
else
    $(error Invalid debuglevel. Allowed values: 0, 1, 2)
endif


%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
    
all: clean $(TARGET)

clean:
	rm -f *.o

