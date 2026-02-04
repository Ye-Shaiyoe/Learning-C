# Makefile untuk Text Editor

# Compiler dan flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = text_editor

# Source files dan object files
SOURCES = main.c buffer.c file_ops.c search.c editor.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = text_editor.h

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Kompilasi selesai! Executable: $(TARGET)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "File hasil kompilasi telah dihapus"

# Rebuild (clean + build)
rebuild: clean all

# Phony targets
.PHONY: all run clean rebuild