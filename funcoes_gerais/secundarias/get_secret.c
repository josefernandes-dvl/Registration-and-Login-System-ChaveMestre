#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <prototipos.h>

// Função para ler uma senha ou texto secreto do usuário, escondendo os caracteres digitados.
void get_secret(char *s, int tam)
{
    int i = 0; // Índice para a posição atual no array de caracteres
    char ch;

    while (1)
    {
        ch = getch(); // Lê um caractere do teclado sem exibir (ecoar) na tela

        if (ch == 13)
        {                // Se a tecla pressionada for Enter (código ASCII 13)
            s[i] = '\0'; // Finaliza a string com caractere nulo
            break;       // Sai do loop, terminando a leitura
        }
        else if (ch == 8)
        { // Se a tecla for Backspace (código ASCII 8)
            if (i > 0)
            {
                i--;             // Decrementa o índice para apagar o último caractere digitado
                printf("\b \b"); // Move o cursor para trás, apaga o caractere na tela, e posiciona o cursor novamente
            }
        }
        else if (i < tam - 1 && ch >= 32 && ch <= 126)
        {
            // Se ainda há espaço na string e o caractere é imprimível
            s[i++] = ch; // Armazena o caractere na string
            printf("*"); // Imprime um asterisco para mascarar a entrada do usuário
        }
        // Caracteres fora do intervalo imprimível são ignorados
    }
}
