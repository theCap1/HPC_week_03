BUILD_DIR = ./build

$(shell mkdir -p $(BUILD_DIR))

bits: test.cpp
	g++ -Wall -o test test.cpp -g -O0