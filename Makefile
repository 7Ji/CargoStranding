BINARY = CargoStranding
DIR_INCLUDE = include
DIR_SOURCE = src
DIR_OBJECT = obj
C++ ?= g++
# STRIP ?= strip
CFLAGS = -I$(DIR_INCLUDE) -Wall -Wextra

INCLUDES = $(wildcard $(DIR_INCLUDE)/*.hpp)

_OBJECTS = $(wildcard $(DIR_SOURCE)/*.cpp)
OBJECTS = $(patsubst $(DIR_SOURCE)/%.cpp,$(DIR_OBJECT)/%.cpp.o,$(_OBJECTS))

$(BINARY): $(OBJECTS)
	$(C++) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(DIR_OBJECT)/%.cpp.o: $(DIR_SOURCE)/%.cpp $(INCLUDES)
	$(C++) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(DIR_OBJECT)/*.o $(BINARY)