#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para verificar se um nome já existe em um arquivo binário.
// Se o nome for encontrado, retorna 1 e preenche a struct 'dados' com as informações do arquivo.
// Se não for encontrado, retorna 0.
int verificar_nome(Cadastro *dados, char tentativa_nome[])
{
    FILE *arquivo;
    Cadastro ler_dados; // Struct temporária para ler os dados do arquivo.

    // Determina qual arquivo deve ser lido.
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Tenta abrir o arquivo para leitura em modo binário ("rb").
    arquivo = fopen(nome_arquivo, "rb");

    // Se o arquivo for NULL, significa que ele não existe (nenhum cadastro ainda).
    // Isso não é um erro fatal, apenas significa que o nome não foi encontrado.
    if (arquivo == NULL)
    {
        return 0; // Retorna 0 (nome não encontrado).
    }

    // Se o arquivo abriu, o loop while lê o arquivo registro por registro.
    // A cada iteração, 'fread' tenta ler um bloco do tamanho de 'sizeof(Cadastro)' para dentro da 'ler_dados'.
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        // Compara o nome lido do arquivo com o nome que estamos procurando.
        if (strcmp(ler_dados.nome, tentativa_nome) == 0)
        {
            // Se os nomes são iguais, encontramos o usuário!
            *dados = ler_dados; // Copia os dados encontrados para a struct principal do programa.
            fclose(arquivo);    // Fecha o arquivo.
            return 1;           // Retorna 1 (nome encontrado).
        }
    }

    // Se o loop terminar sem encontrar o nome, fecha o arquivo.
    fclose(arquivo);
    return 0; // Retorna 0 (nome não encontrado).
}