SRC_DIR := Source
HEADER_DIR := Header
OBJ_DIR := Compiled
SRC_FOLDER = $(wildcard $(SRC_DIR)/*)
OBJ_FOLDER = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_FOLDER))
SRC_FILES := $(wildcard $(SRC_DIR)/*/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := ...
CPPFLAGS := ...
CXXFLAGS := ...

all: $(OBJ_FILES) Compiled/main.o
	g++  -o app $^

Compiled/main.o: main.cpp
	g++  -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_DIR)/%.h
	g++ -c -o $@ $<

clean:
	rm -rf app all a.*
	rm -rf Compiled
	mkdir Compiled
	mkdir $(OBJ_FOLDER)
	reset

clear:
	del app all a.*
	del Compiled
	mkdir Compiled
	mkdir $(OBJ_FOLDER)
	reset

dir:
	mkdir $(OBJ_FOLDER)