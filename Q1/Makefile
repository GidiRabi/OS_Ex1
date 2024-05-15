CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
PROGRAMS = division_by_zero infinite_recursion undefined_memory
CORES = $(addprefix core., $(PROGRAMS))

.PHONY: all $(PROGRAMS) $(CORES)

all: $(PROGRAMS) $(CORES)

$(PROGRAMS):
	$(CXX) $(CXXFLAGS) -g -o $@_with_debug $@.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp

$(CORES): $(PROGRAMS)
	-./$(basename $@) || true
	-./$(basename $@)_with_debug || true
	gdb -ex "core-file $@" -ex "where" -ex "quit" $(basename $@)
	gdb -ex "core-file $@" -ex "where" -ex "quit" $(basename $@)_with_debug

clean:
	rm -f $(PROGRAMS) $(addprefix *, $(PROGRAMS)) core.*
