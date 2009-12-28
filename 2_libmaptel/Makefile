CXX = g++

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
    ERROR = 'Invalid debuglevel. Allowed values: 0, 1, 2.'
endif

ifdef ERROR
	MAPTEL_CMD = @echo $(ERROR)
else
	MAPTEL_CMD = $(CXX) $(CXXFLAGS) -c maptel.cc
endif

maptel.o: clean maptel.cc maptel.h
	$(MAPTEL_CMD)
    
all: maptel.o

clean:
	rm -f *.o

