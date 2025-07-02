#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // Para usar isdigit() que verifica se um caractere é dígito
#include <conio.h> // Para funções de entrada sem eco (getch, etc)
#include "prototipos.h"

// Função para alterar a senha de um usuário já existente.
// Recebe um ponteiro para a struct Cadastro com dados do usuário que terá a senha alterada.
int alterar_senha(Cadastro *dados)
{
    FILE *arquivo;
    Cadastro ler_dados;  // Struct auxiliar para ler registros do arquivo
    char nova_senha[22]; // Buffer para armazenar a nova senha digitada
    char senha_sup[22];  // Buffer para confirmação da senha

    int senha_valida; // Flag para validar a senha
    int flag = 1;     // Auxiliar para controle interno na validação

    do
    {
        senha_valida = 1; // Assume inicialmente que a senha é válida
        flag = 1;

        ir_para(25, 12); // Posiciona cursor no console (linha 25, coluna 12)
        limpar_linha();  // Limpa a linha para nova mensagem/entrada
        ir_para(25, 12);
        escreva("Digite a nova senha: ", PINK); // Pede que digite a nova senha com cor rosa

        // Função que captura senha sem mostrar no console (input oculto)
        get_secret(nova_senha, strlen(nova_senha));

        int tamanho = strlen(nova_senha);
        int contem_digito = 0;

        // Validação 1: tamanho máximo da senha
        if (tamanho > 20)
        {
            flag = 0;
            reset(12); // Reseta cores ou interface (função custom)
            ir_para(27, 16);
            limpar_linha();
            ir_para(20, 15);
            limpar_linha();
            escreva("O tamanho maximo da senha e de 20 caracteres!", RED);
            senha_valida = 0;
        }
        // Validação 2: tamanho mínimo da senha
        else if (tamanho < 6)
        {
            flag = 0;
            ir_para(27, 16);
            limpar_linha();
            ir_para(20, 15);
            limpar_linha();
            ir_para(20, 15);
            escreva("O tamanho minimo da senha e de 6 caracteres!", RED);
            senha_valida = 0;
        }
        else
        {
            // Validação 3: verifica se a senha contém ao menos um número
            for (int i = 0; i < tamanho; i++)
            {
                if (isdigit(nova_senha[i]))
                { // Se caractere for dígito
                    contem_digito = 1;
                    break;
                }
            }
            if (!contem_digito)
            {
                flag = 0;
                ir_para(27, 16);
                limpar_linha();
                ir_para(20, 15);
                limpar_linha();
                reset(12);
                ir_para(20, 15);
                escreva("A senha deve conter pelo menos um numero!", RED);
                senha_valida = 0;
            }

            // Se passou todas as validações até aqui
            if (flag)
            {
                ir_para(27, 16);
                limpar_linha();
                ir_para(20, 15);
                limpar_linha();
                ir_para(25, 13);
                escreva("Confirme sua Senha: ", PINK);

                // Pede para confirmar a senha digitada (input oculto)
                get_secret(senha_sup, sizeof(senha_sup));

                // Compara se as duas senhas digitadas são iguais
                if (strcmp(nova_senha, senha_sup) != 0)
                {
                    ir_para(27, 16);
                    escreva("As senhas nao sao iguais!", RED);
                    ir_para(25, 13);
                    limpar_linha();
                    senha_valida = 0; // Marca a senha como inválida para repetir o loop
                }
            }
        }
    } while (!senha_valida); // Repete enquanto a senha for inválida

    // Aplica uma cifra de César na senha com deslocamento 17 (simples encriptação)
    cifra_cesar(nova_senha, 17);

    // Copia a nova senha cifrada para a struct do usuário
    strcpy(dados->senha, nova_senha);

    ir_para(20, 14);
    limpar_linha();

    // Define o arquivo onde os dados estão armazenados (usuários ou administradores)
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abre o arquivo para leitura e escrita binária (atualizar senha)
    arquivo = fopen(nome_arquivo, "r+b");

    // Se não conseguiu abrir o arquivo, exibe erro e retorna 1
    if (arquivo == NULL)
    {
        reset(12);
        ir_para(20, 16);
        escreva("Nao foi possivel abrir ou criar o arquivo.", RED);
        return 1;
    }

    // Percorre o arquivo lendo um registro (struct Cadastro) por vez
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        // Se encontrar o usuário com o mesmo nome, atualiza os dados
        if (strcmp(ler_dados.nome, dados->nome) == 0)
        {
            // Move o ponteiro do arquivo para o início do registro atual
            fseek(arquivo, -(long)sizeof(Cadastro), SEEK_CUR);
            // Sobrescreve o registro antigo com os novos dados (incluindo a nova senha)
            fwrite(dados, sizeof(Cadastro), 1, arquivo);
            break; // Sai do loop após atualizar
        }
    }

    fclose(arquivo); // Fecha o arquivo

    ir_para(27, 15);
    escreva("Senha atualizada com sucesso.", GREEN); // Mensagem de sucesso
    ir_para(27, 16);
    limpar_linha();

    return 0; // Retorna 0 para indicar sucesso na alteração
}
