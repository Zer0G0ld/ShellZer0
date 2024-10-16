# Detecta o sistema operacional
UNAME := $(shell uname)

# Definindo variáveis
CC = gcc
CFLAGS = -Wall -g -Iinclude
SRC = src/main.c src/parser.c src/exec.c src/utils.c
OBJ_DIR = build/obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
TARGET = ShellZer0
SETUP = ./setup.sh
ZER0RC = .zer0rc
HOME = $(shell echo $$HOME)
ASM_SRC = src/asm/syscall.asm
ASM_OBJ = build/obj/syscall.o

# Verifica se o sistema é Termux ou Debian/WSL
ifeq ($(findstring Android, $(UNAME)), Android)
    # Ambiente Termux
    LDFLAGS = -lreadline
else
    # Ambiente Debian/WSL
    LDFLAGS = -lreadline
    CFLAGS += -I/usr/include
endif

# Regra principal
all: setup $(TARGET)

# Regra para executar o setup.sh antes da compilação
setup:
	@if [ -x "$(SETUP)" ]; then \
		echo "Executando o script setup.sh para instalar dependências..."; \
		bash $(SETUP); \
	else \
		echo "setup.sh não encontrado ou não executável."; \
	fi

# Cria o diretório de objetos, se necessário
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linkando os arquivos objeto
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compilação dos arquivos de objeto
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar um único arquivo
single: $(OBJ_DIR)/exec.o
	$(CC) $(CFLAGS) -o exec_test $(OBJ_DIR)/exec.o $(LDFLAGS)

# Limpeza dos arquivos gerados
clean:
	rm -rf build $(TARGET)

# Regra para limpar apenas os objetos
clean-obj:
	rm -rf $(OBJ_DIR)/*.o
