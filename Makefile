#CXX = clang++
CXX = g++

EXE1 = std_chrono_coding_sandbox
EXE2 = std_chrono_multi_platforms
EXE2 = std_chrono_comp_clocks

all: $(EXE1) $(EXE2) $(EXE3) 
$(EXE1): $(EXE1).o
	$(CXX) $(LDFLAGS) $^ -o $@
$(EXE2): $(EXE2).o
	$(CXX) $(LDFLAGS) $^ -o $@
$(EXE3): $(EXE3).o
	$(CXX) $(LDFLAGS) $^ -o $@
clean:
	rm -f *.o *~
	rm -f $(EXE1) $(EXE2) $(EXE3)
