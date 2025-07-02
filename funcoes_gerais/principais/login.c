#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "prototipos.h"

// Função que realiza o login do usuário ou administrador.
// Recebe um ponteiro para a struct 'Cadastro' para carregar os dados do usuário logado.
void login(Cadastro *dados)
{
    char tentativa_nome[37]; // Buffer para armazenar o nome digitado pelo usuário
    int nome_existe;         // Flag para indicar se o nome foi encontrado no banco de dados

    // Loop principal para solicitar o nome até que um nome existente seja inserido.
    do
    {
        limpar(); // Limpa a tela
        bordas(); // Desenha as bordas da interface de login

        // Imprime a interface de login com bordas e título
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c              Login              %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 217);

        ir_para(24, 9);

        // Solicita o nome de usuário
        ir_para(25, 10);
        escreva("Nome: ", PINK);
        fgets(tentativa_nome, sizeof(tentativa_nome), stdin);
        tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0'; // Remove o '\n' do final da string

        // Verifica se o nome existe no arquivo (arquivo binário ou banco de dados)
        // A função verificar_nome deve carregar os dados do usuário em 'dados' caso encontre o nome
        nome_existe = verificar_nome(dados, tentativa_nome);

        if (nome_existe == 1)
        {                                // Se o nome foi encontrado
            char tentativa_senha[22];    // Buffer para senha digitada pelo usuário
            int aux_tentativa_senha = 0; // Contador de tentativas de senha

            // Loop para solicitar a senha até que a correta seja digitada
            do
            {
                ir_para(6, 11);
                limpar_linha();
                ir_para(25, 11);
                escreva("Senha: ", PINK);

                // Lê a senha sem exibi-la no console
                get_secret(tentativa_senha, sizeof(tentativa_senha));
                // Aplica cifra de César na senha para comparar com a senha armazenada cifrada
                cifra_cesar(tentativa_senha, 17);

                // Compara a senha digitada (cifrada) com a senha armazenada
                if (strcmp(dados->senha, tentativa_senha) == 0)
                {
                    // Senha correta, permite o acesso
                    ir_para(25, 15);
                    printf("                                               ");
                    ir_para(29, 16);
                    escreva("Acesso ao programa liberado!", GREEN);
                    break; // Sai do loop de senha
                }
                else
                {
                    // Senha incorreta, informa o usuário e incrementa o contador
                    reset(11);
                    ir_para(25, 15);
                    escreva("Senha Incorreta! Tente novamente.", RED);
                    aux_tentativa_senha++;

                    // A cada 3 tentativas incorretas, oferece opção de recuperação de senha
                    if (aux_tentativa_senha % 3 == 0)
                    {
                        char deseja_recuperar;
                        do
                        {
                            ir_para(25, 15);
                            escreva("     Deseja recuperar a senha?     ", BLUE);
                            ir_para(22, 16);
                            escreva("[1] ", GREEN);
                            printf("SIM ");
                            escreva("[2] ", BLUE);
                            printf("CONTINUAR TENTANDO ");
                            escreva("[3] ", RED);
                            printf("SAIR : ");
                            scanf("%c", &deseja_recuperar);
                            apaga_buffer(); // Limpa o buffer do teclado

                            switch (deseja_recuperar)
                            {
                            case '1': // Usuário quer recuperar senha
                                limpar();
                                recuperar_senha(dados); // Chama função para recuperar senha
                                // Monta mensagem de aviso de alteração de senha
                                char mensagem_email[200];
                                snprintf(mensagem_email, sizeof(mensagem_email),
                                         "Olá, %s!\n\n    A senha da sua Conta CHAVEMESTRE foi alterada.\n    Caso não tenha sido você, entre em contato com algum administrador para verificar a atividade!", dados->nome);
                                envia_email(dados, mensagem_email); // Envia email notificando
                                exit(0);                            // Encerra o programa após recuperação
                            case '2':                               // Continua tentando senha
                                reset(11);
                                ir_para(25, 15);
                                limpar_linha();
                                ir_para(22, 16);
                                limpar_linha();
                                bordas();
                                break;
                            case '3': // Sai do programa
                                reset(11);
                                ir_para(29, 19);
                                escreva("Tentativa de login mal sucedida", RED);
                                exit(0);
                            default: // Opção inválida, repete a pergunta
                                break;
                            }
                        } while (deseja_recuperar != '1' && deseja_recuperar != '2' && deseja_recuperar != '3');
                    }
                }
            } while (strcmp(dados->senha, tentativa_senha) != 0); // Repete até senha correta
        }
        else
        { // Se o nome não foi encontrado
            char deseja_repetir_nome;
            do
            {
                reset(10);
                ir_para(35, 12);
                escreva("Usuario nao existe.", RED);
                ir_para(26, 14);
                escreva("Deseja repetir o nome do usuario?", BLUE);
                ir_para(30, 15);
                escreva("[1] ", GREEN);
                printf("SIM  ou ");
                escreva("[2] ", RED);
                printf("NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer();

                switch (deseja_repetir_nome)
                {
                case '1': // Tenta digitar o nome novamente
                    limpar();
                    continue; // Volta ao início do loop principal
                case '2':     // Sai do programa
                    ir_para(29, 19);
                    escreva("Tentativa de Login mal sucedida.", RED);
                    exit(0);
                default:
                    ir_para(36, 17);
                    escreva("Digito Invalido.", RED);
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }
    } while (nome_existe == 0); // Repete até que um nome válido seja digitado
}
