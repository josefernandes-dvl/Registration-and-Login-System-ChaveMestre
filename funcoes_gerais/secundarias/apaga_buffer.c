#include <stdio.h>
#include "prototipos.h"

// Função para apagar o buffer de entrada (stdin).
void apaga_buffer(void)
{
    // Este loop é um truque comum em C para limpar o buffer do teclado.
    // A função getchar() lê um caractere do buffer de entrada a cada iteração.
    // O loop continua lendo e descartando caracteres até encontrar um '\n' (a tecla Enter).
    // Quando o '\n' é encontrado, ele também é lido e descartado, e o loop termina,
    // deixando o buffer de entrada limpo para a próxima leitura.
    while (getchar() != '\n')
        ;
}