TARGET = RCyberXMS
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

debug: 
	echo  $(OBJECTS)

run: 
	./agaevnat;

.PHONY: clean

agaevnat: $(OBJECTS)
	g++ -g $^ -std=c++17 -lncurses -o $@;

clean:
	rm -rf $(OBJECTS) $(TARGET)

./src/data.o: src/data.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/entity.o: src/entity.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/exit.o: src/exit.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/game.o: src/game.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/main.o: src/main.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/manual.o: src/manual.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/menu.o: src/menu.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/namespacer.o: src/namespacer.cpp src/kernel.h src/map.h src/entity.h src/data.h
./src/options.o: src/options.cpp src/kernel.h src/map.h src/entity.h src/data.h
