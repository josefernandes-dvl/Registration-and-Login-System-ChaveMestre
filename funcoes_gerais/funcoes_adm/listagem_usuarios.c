#include <stdio.h>      // Biblioteca padrão de entrada e saída (ex: printf, scanf, fopen, fread, etc.)
#include <stdlib.h>     // Biblioteca padrão para funções utilitárias (ex: exit, malloc, free, system, etc.)
#include "prototipos.h" // Arquivo de cabeçalho personalizado contendo declarações de funções, estruturas, cores, etc.

// Função que lista todos os usuários cadastrados no arquivo "usuarios_cadastrados.bin".
void listagem_usuario(void)
{
    FILE *arquivo_u;       // Ponteiro para o arquivo de usuários comuns
    FILE *arquivo_a;       // Ponteiro para o arquivo de administradores
    int adm = 0, user = 0; // Flags para verificar se os arquivos foram encontrados ou se estão vazios
    Cadastro ler_dados;    // Variável do tipo Cadastro para ler os dados de cada usuário

    // Desenha a interface de listagem (caixa com bordas usando caracteres ASCII estendidos)
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c       Listagem de Perfis        %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
           192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 217);
    printf("\n");

    // Desenha uma linha horizontal em toda a largura (de 3 até 78)
    for (int x = 3; x < 79; x++)
    {
        ir_para(x, 2);
        printf("%c", 196); // Linha horizontal superior extra
    }

    // Tenta abrir o arquivo de administradores
    arquivo_a = fopen("adms_cadastrados.bin", "rb");
    if (arquivo_a == NULL)
    {
        // Se não conseguir abrir, exibe mensagem
        ir_para(28, 12);
        escreva("Nenhum administrador cadastrado ainda.\n\n", BLUE);
        adm = 1; // Marca que não há administradores
    }

    // Se não houver nem administradores nem usuários, encerra o programa
    if (adm && user)
    {
        ir_para(26, 16);
        escreva("Encerrando o programa...", RED);
        exit(0); // Finaliza
    }

    int total_adm = 0, total_user = 0; // Contadores de administradores e usuários
    ir_para(0, 8);

    escreva("  => ADMINISTRADORES:\n\n", BLUE);

    // Lê os dados dos administradores enquanto houver dados no arquivo
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo_a) == 1)
    {
        total_adm++; // Incrementa total
        escreva("  Nome: ", PINK);
        printf("%s\n", ler_dados.nome);
        escreva("  CPF: ", PINK);
        printf("%s\n", ler_dados.cpf);
        escreva("  Email: ", PINK);
        printf("%s\n", ler_dados.email);
        printf("\n");
    }
    fclose(arquivo_a); // Fecha o arquivo após leitura

    // Linha de separação
    for (int x = 3; x < 79; x++)
    {
        printf("%c", 196); // Linha horizontal
    }

    printf("\n\n");
    escreva("  => USUARIOS:\n\n", BLUE);

    // Tenta abrir o arquivo de usuários
    arquivo_u = fopen("usuarios_cadastrados.bin", "rb");
    if (arquivo_u == NULL)
    {
        escreva("\n       \n\nNenhum usuario cadastrado ainda.", BLUE);
        user = 1; // Marca que não há usuários
    }

    // Lê os dados dos usuários enquanto houver dados no arquivo
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo_u) == 1)
    {
        total_user++; // Incrementa total
        escreva("  Nome: ", PINK);
        printf("%s\n", ler_dados.nome);
        escreva("  CPF: ", PINK);
        printf("%s\n", ler_dados.cpf);
        escreva("  Email: ", PINK);
        printf("%s\n", ler_dados.email);
        printf("\n");
    }
    fclose(arquivo_u); // Fecha o arquivo após leitura

    // Linha final inferior
    for (int x = 3; x < 79; x++)
    {
        printf("%c", 196); // Linha horizontal
    }

    // Exibe totais formatados
    escreva("\n\n  => TOTAL DE ADMINISTRADORES CADASTRADOS: ", PINK);
    printf("%d\n", total_adm);

    escreva("\n  => TOTAL DE USUARIOS CADASTRADOS: ", PINK);
    printf("%d\n", total_user);

    escreva("\n  => TOTAL DE PERFIS CADASTRADOS: ", PINK);
    printf("%d\n", total_adm + total_user);

    // Finaliza com mensagem de encerramento
    escreva("\n   Listagem concluida. Encerrando o programa...\n\n", GREEN);

    for (int x = 3; x < 79; x++)
    {
        printf("%c", 196); // Linha horizontal de encerramento
    }

    exit(0); // Finaliza o programa
}
