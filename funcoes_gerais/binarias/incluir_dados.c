#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para incluir (gravar) os dados de uma struct 'Cadastro' em um arquivo binário.
void incluir_dados(Cadastro *dados)
{
    // Define o nome do arquivo dependendo do tipo de cadastro (usuário ou administrador).
    // Se 'menu_principal' for '1', grava no arquivo de usuários.
    // Se for '2', grava no arquivo de administradores.
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abre o arquivo em modo append binário ("ab").
    // Isso faz com que os dados sejam adicionados ao final do arquivo,
    // sem apagar o conteúdo existente. Caso o arquivo não exista, ele é criado.
    FILE *arquivo = fopen(nome_arquivo, "ab");

    // Verifica se o arquivo foi aberto com sucesso.
    if (arquivo == NULL)
    {
        ir_para(20, 16);
        escreva("Nao foi possivel abrir ou criar o arquivo.", RED);
        exit(1); // Encerra o programa com código de erro 1.
    }

    // Escreve no arquivo o conteúdo da struct 'dados'.
    // fwrite grava 1 elemento do tamanho da struct Cadastro.
    fwrite(dados, sizeof(Cadastro), 1, arquivo);

    // Fecha o arquivo para garantir que os dados sejam salvos corretamente.
    fclose(arquivo);
}
