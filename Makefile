TARGET := solve.out
OBJS := main.o dice.o condition_base.o
CXXFLAGS := -std=c++11 -O3 -flto


.PHONY: all clean rebuild
.SUFFIXES:
.SUFFIXES: .cpp .o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(TARGET) *.o

rebuild: clean all
