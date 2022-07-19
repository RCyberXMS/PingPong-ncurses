TARGET = RCyber
SOURCES = $(shell find ./src -type f -name *.cpp)
HEADERS = $(shell find ./src -type f -name *.h)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = Makefile.depend
INCLUDES = -I./src
CPPFLAGS = -std=c++17 -O2 -Wall $(INCLUDES)

all: $(TARGET)

compile: $(TARGET)

%.o: %.cpp
	g++ -c -std=c++17 $< -o $@

run:
	./$(TARGET);

clean:
	rm -rf $(OBJECTS) $(TARGET)

./src/menu.o: menu.cpp src/kernel.h src/map.h
./src/main.o: main.cpp src/kernel.h src/map.h
./src/game.o: game.cpp src/kernel.h src/map.h