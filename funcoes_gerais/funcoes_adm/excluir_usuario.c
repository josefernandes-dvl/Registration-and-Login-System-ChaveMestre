#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função para excluir um usuário do arquivo binário de cadastros.
void excluir_usuario(Cadastro *dados)
{
    Cadastro busca_dados;
    busca_dados.menu_principal = '1'; // Configura a estrutura para pesquisar no arquivo de usuários

    // Desenha a interface visual da tela de exclusão
    limpar();
    bordas();
    ir_para(25, 2);
    // Desenha a borda superior do quadro de texto no console
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    // Exibe o título com cor no console
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c         Excluir Usuario         %c", 179, 179);
    ir_para(25, 5);
    // Desenha a borda inferior do quadro
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 217);

    FILE *arquivo, *copia_arquivo;
    Cadastro ler_dados;
    char usuario[37];   // Buffer para armazenar o nome do usuário a ser excluído
    int encontrado = 0; // Flag para indicar se o usuário foi encontrado
    int nome_existe;    // Flag para controle da existência do nome

    // Loop para garantir que o nome informado existe no arquivo de cadastros
    do
    {
        ir_para(25, 9);
        limpar_linha();
        ir_para(25, 9);
        escreva("Nome: ", PINK);
        fgets(usuario, sizeof(usuario), stdin); // Lê o nome do usuário com segurança

        // Remove o caractere de nova linha '\n' se presente no final da string
        if (strchr(usuario, '\n'))
            usuario[strcspn(usuario, "\n")] = '\0';
        else
            apaga_buffer(); // Limpa o buffer caso o '\n' não tenha sido lido (entrada maior que o buffer)

        // Verifica se o usuário existe chamando função que busca o nome no arquivo
        nome_existe = verificar_nome(&busca_dados, usuario);

        // Se não existir, exibe mensagem de erro e repete o loop
        if (nome_existe == 0)
        {
            reset(9);
            ir_para(33, 14);
            escreva("Usuario nao existe!", RED);
        }
    } while (nome_existe == 0);

    ir_para(33, 14);
    limpar_linha();

    // Abre o arquivo original para leitura e cria um arquivo cópia para escrita
    arquivo = fopen("usuarios_cadastrados.bin", "rb");
    copia_arquivo = fopen("usuarios_copia.bin", "ab");

    if (arquivo == NULL || copia_arquivo == NULL)
    {
        reset(9);
        escreva("Nao foi possivel abrir o arquivo.\n", RED);
        exit(1); // Sai do programa caso não consiga abrir arquivos
    }

    // Lê o arquivo original registro por registro
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        // Copia todos os registros exceto o do usuário a ser excluído
        if (strcmp(ler_dados.nome, usuario) != 0)
        {
            fwrite(&ler_dados, sizeof(Cadastro), 1, copia_arquivo);
        }
        else
        {
            encontrado = 1; // Marca que o usuário foi encontrado e excluído (não copiado)
        }
    }

    // Fecha os arquivos após a operação
    fclose(arquivo);
    fclose(copia_arquivo);

    // Remove o arquivo original e renomeia a cópia para o nome original
    // Essa é a técnica padrão para remover registros de arquivos binários sequenciais
    remove("usuarios_cadastrados.bin");
    rename("usuarios_copia.bin", "usuarios_cadastrados.bin");

    // Exibe mensagem confirmando exclusão ou falha
    if (encontrado)
    {
        ir_para(29, 14);
        printf("\033[1;32mO usuario %s foi excluido.\033[0m", usuario);
    }
    else
    {
        ir_para(28, 14);
        reset(9);
        printf("\033[1;31mO usuario %s nao foi encontrado.\033[0m", usuario);
    }

    // Mensagem final e saída do programa
    ir_para(4, 23);
    escreva("Operacao de exclusao finalizada. Encerrando o programa...", BLUE);
    exit(0);
}
