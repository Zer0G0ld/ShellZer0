CC = gcc
CFLAGS = -Wall -g
SRC = src/main.c src/parser.c src/exec.c
OBJ = $(SRC:.c=.o)
TARGET = ShellZer0

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
