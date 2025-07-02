#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para inicializar (criar, se não existir) o arquivo binário apropriado.
void inicializar_arquivo(char menu_principal)
{
    // Um ponteiro 'const char*' é usado para apontar para uma string literal (constante).
    // Isso é eficiente pois a string "usuarios_cadastrados.bin" já existe na memória do programa.
    const char *nome_arquivo = NULL;
    if (menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abre o arquivo em modo "ab" (append binary).
    // Este modo tem um efeito útil: se o arquivo não existir, ele será criado.
    // Se já existir, nada acontece, e o arquivo é simplesmente aberto e fechado.
    // É uma maneira simples e eficaz de garantir a existência do arquivo.
    FILE *arquivo = fopen(nome_arquivo, "ab");
    if (arquivo == NULL)
    {
        // Se mesmo assim houver um erro (ex: falta de permissão de escrita), o programa é encerrado.
        ir_para(20, 16);
        escreva("Nao foi possivel abrir ou criar o arquivo.", RED);
        exit(1);
    }
    fclose(arquivo); // Fecha o arquivo imediatamente.
}