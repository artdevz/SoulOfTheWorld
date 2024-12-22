CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LIBS = -lraylib -lm -lpthread -ldl -lX11

# Diretório de fontes
SRC_DIR = src

# Diretório de objetos
OBJ_DIR = obj

# Criação do diretório obj se não existir
$(shell mkdir -p $(OBJ_DIR))

# Lista de arquivos .cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objetos gerados a partir dos .cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Nome do executável final
EXEC = main

# Regra para compilar o executável
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)

# Regra para gerar arquivos .o a partir de .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objetos e o executável
clean:
	rm -f $(OBJS) $(EXEC)
