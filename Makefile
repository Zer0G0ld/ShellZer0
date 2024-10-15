# Definindo variáveis
CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS = -lreadline
SRC = src/main.c src/parser.c src/exec.c
OBJ_DIR = build/obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
TARGET = ShellZer0

# Regra principal
all: $(TARGET)

# Cria o diretório de objetos, se necessário
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linkando os arquivos objeto
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compilação dos arquivos de objeto
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf build $(TARGET)

