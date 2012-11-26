CXX=g++
RM=rm -f
CPPFLAGS=-g -Wall -Iinclude

SRCS=src/simplexityDrv.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(OBJS)
	$(CXX) $(CPPFLAGS) -o simplexity $(OBJS)

clean:
	$(RM) $(OBJS)
