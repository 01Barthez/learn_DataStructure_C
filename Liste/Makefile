# Variables
CC = gcc # compilateur utilisé
CFLAGS = -Wall -Wextra -g # Options de compilation pour afficher les avertissements et activer le débogage
TARGET = list_program # Nom du programme compilé
SRCS = $(wildcard *.c) # Fichiers source
OBJS = $(SRCS:.c=.o) # Fichiers objet générés à partir des fichiers source

# Règles
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
