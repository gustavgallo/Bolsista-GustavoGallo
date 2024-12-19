# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -O2

# Nome do executável
TARGET = convolucao

# Lista de arquivos fonte
SRC = conv.c

# Regra padrão: cria o executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regra para limpar arquivos gerados
clean:
	rm -f $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)
