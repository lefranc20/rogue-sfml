# Definições básicas
EXEC = rogue-sfml
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = g++
CXXFLAGS = -std=c++17 -Wall
BIN_DIR = bin

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    TARGET_OS := Windows
    EXT := .exe
    RM := del /Q
    CXXFLAGS += -I"C:/SFML/include"
    LDFLAGS = -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system
else
    TARGET_OS := Linux
    EXT :=
    RM := rm -f
    CXXFLAGS += $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system)
    LDFLAGS = $(shell pkg-config --libs sfml-graphics sfml-window sfml-system)
endif

# Garante que o diretório bin exista
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra padrão
all: $(BIN_DIR) $(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@$(EXT) $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	$(RM) $(OBJ) $(BIN_DIR)/$(EXEC)$(EXT)

# Execução rápida
run: all
	./$(BIN_DIR)/$(EXEC)$(EXT)