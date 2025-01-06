CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LIBS = -lraylib -lm -lpthread -ldl -lX11

# Dir
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Sub-Dir
SUBDIRS = $(shell find $(SRC_DIR) -type d)

# Create
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Src
SRCS = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))

# Obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Bin
EXEC = $(BIN_DIR)/SOTW

# Exe
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D) # Create subdirs in obj/
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)