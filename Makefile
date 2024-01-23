#CXX = clang++
CXX = g++
LIBDIR = ${HOME}/nestdaq/lib
LDFLAGS = -L$(LIBDIR) -Wl,-rpath,$(LIBDIR)

PROGRAM = std_chrono_coding_sandbox

all: $(PROGRAM)
$(PROGRAM): $(PROGRAM).o
	$(CXX) $(LDFLAGS) $^ -o $(PROGRAM)
clean:
	rm -f *.o *~
	rm -f $(PROGRAM)
