#include <stdlib.h>
#include "prototipos.h"

// Função para limpar a tela do console.
void limpar(void)
{
// A diretiva de pré-processador '#ifdef' verifica se uma macro está definida.
// _WIN32 é uma macro padrão em compiladores para Windows.
#ifdef _WIN32
    // Se estiver compilando no Windows, executa o comando "cls" para limpar a tela.
    system("cls");
#else
    // Em qualquer outro sistema operacional (como Linux ou macOS), executa "clear".
    system("clear");
#endif
}