CXXFLAGS += -O3 -m64
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

ASFLAGS64  = --64

all:
	$(info For Windows use: $(MAKE) windows)
	$(info For Linux use: $(MAKE) linux)
	$(error Missing argument: windows or linux)

compile:
	$(CXX) -c argv_parser.cpp -o argv_parser.o $(CXXFLAGS)
	$(CXX) -c main.cpp -o main.o $(CXXFLAGS)

linux: compile
	$(AS) crc32_func_linux.S ${ASFLAGS64} -o crc32_func_linux.o
	$(CXX) main.o argv_parser.o crc32_func_linux.o -o crc32sum

windows: compile
	$(AS) crc32_func_windows.S ${ASFLAGS64} -o crc32_func_windows.o
	$(CXX) main.o argv_parser.o crc32_func_windows.o -o crc32sum.exe
