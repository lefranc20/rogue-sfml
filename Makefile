# Definições básicas
EXEC = rogue-sfml
SRC = src/main.cpp src/Jogo.cpp src/Jogador.cpp src/Inimigo.cpp
OBJ = $(SRC:.cpp=.o)
CXX = g++
CXXFLAGS = -std=c++17 -Wall
BIN_DIR = bin

# Configuração para Linux
RM := rm -f
CXXFLAGS += $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)
LDFLAGS = $(shell pkg-config --libs sfml-graphics sfml-window sfml-system)

# Garante que o diretório bin exista
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra padrão
all: $(BIN_DIR) $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	$(RM) $(OBJ) $(BIN_DIR)/$(EXEC)

# Execução rápida
run: all
	./$(BIN_DIR)/$(EXEC)


# Compilação numa linha
# mkdir -p bin && g++ -std=c++17 -Wall $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system) -o bin/rogue-sfml src/main.cpp src/Jogo.cpp src/Jogador.cpp $(shell pkg-config --libs sfml-graphics sfml-window sfml-system)