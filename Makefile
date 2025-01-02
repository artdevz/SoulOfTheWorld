CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LIBS = -lraylib -lm -lpthread -ldl -lX11

# Diretórios de fontes e objetos
SRC_DIR = src
OBJ_DIR = obj

# Subdiretórios para incluir
SUBDIRS = $(SRC_DIR) $(SRC_DIR)/entities $(SRC_DIR)/roots $(SRC_DIR)/screens $(SRC_DIR)/spells 

# Criação do diretório obj se não existir
$(shell mkdir -p $(OBJ_DIR))

# Listar todos os arquivos .cpp nos diretórios especificados
SRCS = $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))

# Gerar os arquivos .o correspondentes em obj/
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Nome do executável final
EXEC = main

# Regra para compilar o executável
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LIBS)

# Regra para gerar arquivos .o a partir de .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D) # Cria os subdiretórios em obj/ conforme necessário
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objetos e o executável
clean:
	rm -rf $(OBJ_DIR) $(EXEC)