# Makefile para o projeto Trabalho-IP. O que é Makefile? É um arquivo de automação de compilação.

# Definindo o compilador a ser usado (gcc para C)
CC = gcc

# Opções de compilação:
# -Wall ativa todos os avisos
# -O2 ativa otimização moderada
# -Iinclude adiciona a pasta 'include' ao caminho dos headers
CFLAGS = -Wall -O2 -Iinclude

# Diretórios onde estão os arquivos .c
SRC_DIRS = src \
           funcoes_gerais/binarias \
           funcoes_gerais/ADK \
           funcoes_gerais/funcoes_adm \
           funcoes_gerais/principais \
           funcoes_gerais/secundarias

# Gera a lista de arquivos .o:
# - 'wildcard' encontra todos os arquivos .c nos diretórios
# - 'patsubst' transforma *.c em *.o
OBJ = $(patsubst %.c, %.o, $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c)))

# Nome do executável final
TARGET = programa

# Regra padrão (executada ao rodar apenas 'make')
all: $(TARGET)

# Regra para gerar o executável a partir dos .o
# $^ = todos os pré-requisitos (os .o)
# $@ = nome do alvo (TARGET)
# Importante: linkar com libcurl (-lcurl) para resolver funções da biblioteca curl usadas no código
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lcurl

# Regra para compilar cada .c em .o individualmente
# $< = nome do arquivo fonte (o .c)
# $@ = nome do alvo (o .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar o projeto
# Remove todos os arquivos .o e o executável
clean:
	rm -f $(OBJ) $(TARGET)