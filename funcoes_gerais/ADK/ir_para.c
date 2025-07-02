#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para posicionar o cursor na tela do terminal em coordenadas (x, y)
void ir_para(int x, int y)
{
    // Imprime uma sequência de controle ANSI para mover o cursor
    // 0x1B é o código ASCII para ESC (escape), que indica o início de uma sequência ANSI
    // Depois vem o caractere '[' que inicia o comando de controle
    // '%d;%df' indica a posição do cursor: y (linha) e x (coluna)
    // Assim, o comando inteiro "\033[y;xf" move o cursor para a linha y e coluna x no terminal
    printf("%c[%d;%df", 0x1B, y, x);
}
