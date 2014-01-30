
# platform / project specific compiler, flags, etc.
#
CXX         =      /usr/bin/g++
CXXFLAGS    =	 -W -Wall -pedantic

# project specifics
#
APP      = puzzle
OBJS     = main.o NQueens.o


# make commands - all, clean
#
all:	$(APP)

$(APP):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(APP) $(OBJS)

clean:	
	rm -f *.o *~* $(APP)
