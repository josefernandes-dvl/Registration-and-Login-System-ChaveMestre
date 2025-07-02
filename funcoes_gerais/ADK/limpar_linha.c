#include <stdio.h>
#include "prototipos.h"

// Função para limpar visualmente uma linha no console.
void limpar_linha(void)
{
    // Imprime uma longa sequência de espaços em branco.
    // Isso sobrescreve qualquer texto que estivesse anteriormente na linha,
    // dando a impressão de que a linha foi "apagada".
    printf("                                                       ");
    // Redesenha as bordas para que a limpeza da linha não apague partes da interface.
    bordas();
}