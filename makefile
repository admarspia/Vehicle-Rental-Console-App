CXX = g++
CXXFLAGS = -std=c++11 -I/usr/include/mariadb
LDFLAGS = -L/lib/x86_64-linux-gnu -lmariadbcpp -lmariadb -lsodium


SPECIAL_TARGETS := clean


ifeq (,$(filter $(MAKECMDGOALS),$(SPECIAL_TARGETS)))
SRC = $(addsuffix .cpp, $(MAKECMDGOALS))
OBG = $(MAKECMDGOALS:=.o)
TARGET = $(MAKECMDGOALS)

# Build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build executable
$(TARGET): $(OBG)
	$(CXX) $(OBG) -o $(TARGET) $(LDFLAGS)
endif

# Special target: clean
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
