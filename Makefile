CXX = g++-10
CXXFLAGS = --std=c++20 -Wall -Wextra
LDFLAGS = -lpthread
EXE = spinner_test
OBJS = spinner_test.o

all : $(EXE)

$(EXE) : $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean :
	rm *.o
	rm $(EXE)


