#include <stdio.h>
#include "prototipos.h"

// Função que imprime uma string na tela com cor específica usando códigos ANSI para cores no terminal
void escreva(char *s, Color color)
{
    switch (color)
    {
    case 'r': // Se a cor for 'r' (vermelho)
        // \033[1;31m ativa o texto vermelho em negrito
        // %s imprime a string passada como parâmetro
        // \033[0m reseta a cor para o padrão após a impressão
        printf("\033[1;31m%s\033[0m", s);
        break;

    case 'g': // Se a cor for 'g' (verde)
        // Ativa texto verde em negrito
        printf("\033[1;32m%s\033[0m", s);
        break;

    case 'a': // Se a cor for 'a' (azul)
        // Ativa texto azul em negrito
        printf("\033[1;34m%s\033[0m", s);
        break;

    case 'p': // Se a cor for 'p' (rosa)
        // Ativa texto rosa (magenta) em negrito
        printf("\033[1;35m%s\033[0m", s);
        break;
    }
}
