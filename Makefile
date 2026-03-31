CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -I/opt/homebrew/include
SRC := src/main.cpp src/server.cpp src/utilities.cpp
TARGET := caching-proxy

.PHONY: all build run test clean

all: build

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: build
	./$(TARGET) --port 3000 --origin http://dummyjson.com

test:
	curl -i http://localhost:3000/products

clean:
	rm -f $(TARGET)
