#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função que exibe o menu de ações do administrador.
// O fluxo é controlado por um loop 'do-while' e uma estrutura 'switch'.
void adm_funcoes(Cadastro *dados)
{
    // Variável para armazenar a opção escolhida pelo administrador.
    char acao_adm;
    // Loop 'do-while' para garantir que o menu seja exibido ao menos uma vez.
    do
    {
        // Desenha a interface do menu do administrador no terminal.
        bordas();       // Desenha as bordas.
        ir_para(25, 2); // Posiciona o cursor para desenhar o cabeçalho.
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Menu Administrador       %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 217);

        // Exibe as opções disponíveis para o administrador.
        ir_para(23, 9);
        ir_para(21, 9);
        escreva("          1. ", PINK);
        printf("LISTAGEM DE PERFIS           ");
        ir_para(21, 10);
        escreva("          2. ", PINK);
        printf("LOCALIZAR USUARIO           ");
        ir_para(21, 11);
        escreva("          3. ", PINK);
        printf("EXCLUIR USUARIO           ");
        ir_para(21, 12);
        escreva("          4. ", PINK);
        printf("SAIR          ");

        // Solicita a entrada do administrador.
        ir_para(26, 14);
        escreva("Digite a opcao que deseja: ", PINK);
        scanf("%c", &acao_adm); // Lê a opção do administrador.
        apaga_buffer();         // Limpa o buffer do teclado.

        // Trata a opção escolhida usando uma estrutura switch.
        switch (acao_adm)
        {
        case '1':               // Se a opção for '1'
            limpar();           // Limpa a tela.
            listagem_usuario(); // Chama a função para listar todos os usuários.
            break;
        case '2':                    // Se a opção for '2'
            limpar();                // Limpa a tela.
            localiza_usuario(dados); // Chama a função para encontrar um usuário específico.
            break;
        case '3':                   // Se a opção for '3'
            limpar();               // Limpa a tela.
            excluir_usuario(dados); // Chama a função para remover um usuário.
            break;
        case '4': // Se a opção for '4' (Sair).
            ir_para(29, 16);
            limpar_linha(); // Limpa a linha para exibir a mensagem de saída.
            ir_para(32, 16);
            escreva("Saindo do programa...", RED); // Exibe a mensagem.
            break;
        default:       // Se for uma opção inválida.
            reset(14); // Limpa a tela a partir da linha 14.
            ir_para(29, 16);
            limpar_linha();
            ir_para(34, 16);
            escreva("DIGITO INVALIDO!", RED); // Exibe uma mensagem de erro.
        }
        // Repete o menu se a opção digitada não for uma das válidas ('1', '2', '3' ou '4').
    } while (acao_adm != '1' && acao_adm != '2' && acao_adm != '3' && acao_adm != '4');
}