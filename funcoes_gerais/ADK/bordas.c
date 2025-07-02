#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função que desenha uma moldura (bordas) na tela do console
void bordas()
{
    // Desenha as bordas horizontais superior e inferior
    // Percorre as colunas de 3 até 78 para criar a linha superior e inferior
    // O caractere 196 é o traço horizontal "─" na tabela ASCII estendida

    for (int x = 3; x < 79; x++)
    {
        ir_para(x, 2);     // Posiciona o cursor na linha 2 (superior), coluna x
        printf("%c", 196); // Imprime o traço horizontal na linha superior

        ir_para(x, 24);    // Posiciona o cursor na linha 24 (inferior), coluna x
        printf("%c", 196); // Imprime o traço horizontal na linha inferior
    }

    // Desenha as bordas verticais esquerda e direita e os cantos da moldura
    // Percorre as linhas de 3 até 23 para criar as barras verticais
    // O caractere 179 é a barra vertical "|"
    // Os caracteres 218, 191, 192 e 217 representam os cantos ┌, ┐, └ e ┘ respectivamente

    for (int y = 3; y < 24; y++)
    {
        ir_para(2, y);     // Posiciona o cursor na coluna 2 (esquerda), linha y
        printf("%c", 179); // Imprime a barra vertical esquerda

        ir_para(79, y);    // Posiciona o cursor na coluna 79 (direita), linha y
        printf("%c", 179); // Imprime a barra vertical direita
    }

    // Desenha os quatro cantos da moldura usando os caracteres especiais ASCII

    ir_para(2, 2);
    printf("%c", 218); // Canto superior esquerdo ┌

    ir_para(79, 2);
    printf("%c", 191); // Canto superior direito ┐

    ir_para(2, 24);
    printf("%c", 192); // Canto inferior esquerdo └

    ir_para(79, 24);
    printf("%c", 217); // Canto inferior direito ┘
}
