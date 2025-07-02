#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função para localizar um usuário pelo nome no sistema.
void localiza_usuario(Cadastro *dados)
{
    Cadastro usuario_buscado;
    usuario_buscado.menu_principal = '1'; // Define que a busca será feita entre usuários comuns.

    int nome_existe;

    // Loop para permitir múltiplas tentativas de busca pelo nome do usuário.
    do
    {
        char usuario_procurado[37];

        // Monta a interface visual da tela de localização.
        limpar(); // Limpa o console.
        bordas(); // Desenha bordas na tela.
        ir_para(25, 2);
        // Linha superior da caixa.
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Localizar Usuario        %c", 179, 179);
        ir_para(25, 5);
        // Linha inferior da caixa.
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 217);

        // Solicita ao administrador o nome do usuário que deseja localizar.
        ir_para(25, 10);
        escreva("Nome do Usuario: ", PINK);
        fgets(usuario_procurado, sizeof(usuario_procurado), stdin);
        usuario_procurado[strcspn(usuario_procurado, "\n")] = '\0'; // Remove o '\n' da string.

        // Verifica se o nome digitado existe e carrega os dados na struct usuario_buscado.
        nome_existe = verificar_nome(&usuario_buscado, usuario_procurado);

        if (nome_existe == 1)
        { // Se o usuário foi encontrado
            ir_para(25, 9);
            escreva("Usuario : ", PINK);
            printf("%s", usuario_buscado.nome); // Mostra o nome do usuário encontrado.
            ir_para(25, 10);
            limpar_linha(); // Limpa a linha para exibir o CPF.
            ir_para(25, 10);
            escreva("CPF: ", PINK);
            printf("%s", usuario_buscado.cpf); // Mostra o CPF do usuário.
            ir_para(25, 11);
            escreva("Email: ", PINK);
            printf("%s", usuario_buscado.email); // Mostra o email do usuário.

            ir_para(4, 23);
            escreva("Usuario localizado. Encerrando o programa...", BLUE);
            exit(0); // Encerra o programa após localizar o usuário.
        }
        else
        { // Caso o usuário não seja encontrado
            char deseja_repetir_nome;
            do
            {
                reset(10);
                ir_para(30, 12);
                escreva("Usuario nao encontrado", RED);
                ir_para(26, 14);
                escreva("Deseja repetir o nome do Usuario?", BLUE);
                ir_para(30, 15);
                escreva("[1] ", GREEN);
                printf("SIM ou ");
                escreva("[2] ", RED);
                printf("NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer(); // Limpa buffer para evitar problemas no input.

                switch (deseja_repetir_nome)
                {
                case '1':
                    limpar(); // Limpa a tela para nova tentativa de busca.
                    break;
                case '2':
                    ir_para(24, 17);
                    escreva("Saindo do programa...", BLUE);
                    exit(0); // Sai do programa caso escolha não tentar novamente.
                default:
                    reset(15);
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }
    } while (nome_existe == 0); // Continua perguntando até encontrar ou o usuário desistir.
}
