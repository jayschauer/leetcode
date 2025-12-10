CXX ?= g++
CXXFLAGS = --std=c++20 -Wall -Werror -pedantic -g -Wno-comment -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

# Compile the main executable
main.exe: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.exe

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump

# Disable built-in rules
.SUFFIXES:
