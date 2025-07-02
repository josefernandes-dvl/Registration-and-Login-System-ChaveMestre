#include <stdio.h>
#include <string.h>
#include <prototipos.h>

// Função para limpar a tela a partir de uma linha específica e redesenhar as bordas
void reset(int n)
{
    // Percorre da linha logo abaixo de n (n+1) até a linha 25 (final da tela)
    for (int x = n + 1; x <= 25; x++)
    {
        ir_para(0, x);    // Move o cursor para o início da linha x (coluna 0)
        printf("\33[2K"); // Envia código ANSI para apagar completamente a linha atual
    }
    bordas(); // Após limpar as linhas, redesenha as bordas da interface na tela
}
