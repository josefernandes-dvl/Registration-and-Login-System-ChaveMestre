#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Função que aplica a cifra de César em uma string, deslocando caracteres por um valor fixo.
void cifra_cesar(char *codificada, int deslocamento)
{
    int i;
    char c;

    // Percorre cada caractere da string até o caractere nulo '\0'
    for (i = 0; codificada[i] != '\0'; i++)
    {
        c = codificada[i];

        // Se for letra maiúscula (A-Z), aplica o deslocamento dentro do alfabeto maiúsculo
        if (c >= 'A' && c <= 'Z')
        {
            // Calcula o novo caractere com deslocamento circular (mod 26)
            codificada[i] = ((c - 'A' + deslocamento) % 26) + 'A';
        }
        // Se for letra minúscula (a-z), aplica o deslocamento dentro do alfabeto minúsculo
        else if (c >= 'a' && c <= 'z')
        {
            // Calcula o novo caractere com deslocamento circular (mod 26)
            codificada[i] = ((c - 'a' + deslocamento) % 26) + 'a';
        }
        // Se for número (0-9), aplica o deslocamento circular dentro dos dígitos
        else if (c >= '0' && c <= '9')
        {
            // Calcula o novo dígito com deslocamento circular (mod 10)
            codificada[i] = ((c - '0' + deslocamento) % 10) + '0';
        }
        // Outros caracteres (como símbolos, espaços) permanecem inalterados
    }
}
