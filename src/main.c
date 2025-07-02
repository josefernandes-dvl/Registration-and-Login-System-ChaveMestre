#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "prototipos.h"

// A função main é o ponto de entrada de qualquer programa em C.
int main()
{
    // Declara uma string para armazenar o nome do sistema operacional.
    char SO[10];
    // Diretiva de pré-processador para verificar se o código está sendo compilado no Windows.
#ifdef _WIN32
    {
        // Se for Windows, define a variável SO como "Windows".
        strcpy(SO, "Windows");
    }
#else
    {
        // Caso contrário (Linux, etc.), define como "Linux".
        strcpy(SO, "Linux");
    }
#endif

    // Formata o console do Windows para 80 colunas e 25 linhas.
    // Isso garante que a interface gráfica do terminal (bordas, etc.) seja exibida corretamente.
    system("mode con:cols=80 lines=25");

    // Cria uma instância da struct 'Cadastro'.
    // Esta variável armazenará os dados do usuário/adm durante a execução.
    Cadastro dados;
    // Buffer para armazenar a mensagem que será enviada por e-mail.
    char mensagem_email[300];

    // Loop do Menu Principal.
    // O 'do-while' garante que o menu seja exibido pelo menos uma vez.
    do
    {
        // Funções para desenhar a interface gráfica no terminal.
        bordas();       // Desenha as bordas da tela.
        ir_para(25, 2); // Move o cursor para a posição (coluna, linha).
        // Imprime o título do menu.
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c          Menu Principal         %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
               196, 196, 196, 196, 217);

        // Exibe as opções do menu.
        ir_para(23, 9);
        escreva("            1.", PINK); // Escreve o texto com a cor rosa.
        printf(" MENU USUARIO            ");
        ir_para(23, 10);
        escreva("         2.", PINK);
        printf(" MENU ADMINISTRADOR         ");
        ir_para(23, 11);
        escreva("                3.", PINK);
        printf(" SAIR                ");

        // Solicita a entrada do usuário.
        ir_para(26, 13);
        limpar_linha(); // Limpa a linha de entrada antes de pedir a opção.
        ir_para(26, 13);
        escreva("Digite a opcao que deseja: ", PINK);
        scanf("%c", &dados.menu_principal); // Lê a opção e armazena na struct 'dados'.
        apaga_buffer();                     // Limpa o buffer do teclado para evitar leituras indesejadas.

        // Estrutura 'switch' para tratar a opção escolhida.
        switch (dados.menu_principal)
        {
            // Variável local para o submenu do usuário.
            char menu_usuario;
        case '1': // Caso o usuário escolha "MENU USUARIO".
            // Loop do Menu do Usuário.
            do
            {
                // Desenha a interface do menu do usuário.
                bordas();
                ir_para(25, 2);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
                       218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
                       196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
                       196, 196, 196, 196, 191);
                ir_para(25, 3);
                printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
                ir_para(25, 4);
                printf("%c           Menu Usuario          %c", 179, 179);
                ir_para(25, 5);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
                       192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
                       196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
                       196, 196, 196, 196, 217);

                // Exibe as opções do submenu.
                ir_para(21, 9);
                escreva("       1.", PINK);
                printf(" CADASTRO            ");
                ir_para(21, 10);
                limpar_linha();
                ir_para(21, 10);
                escreva("       2.", PINK);
                printf(" FAZER LOGIN          ");
                ir_para(21, 11);
                escreva("       3.", PINK);
                printf(" RECUPERACAO DE SENHA     ");
                ir_para(21, 12);
                escreva("       4.", PINK);
                printf(" SAIR    ");

                // Solicita a entrada do usuário.
                ir_para(26, 13);
                limpar_linha();
                ir_para(26, 14);
                limpar_linha();
                ir_para(26, 15);
                limpar_linha();
                ir_para(26, 14);
                escreva("Digite a opcao que deseja: ", PINK);
                scanf("%c", &menu_usuario);
                apaga_buffer();

                // Switch para tratar a opção do submenu do usuário.
                switch (menu_usuario)
                {
                case '1': // Cadastro de novo usuário.
                    // Garante que o arquivo 'usuarios_cadastrados.bin' exista.
                    inicializar_arquivo(dados.menu_principal);
                    // Chama a função de cadastro para preencher os dados.
                    cadastro(&dados);
                    // Salva os dados no arquivo binário.
                    incluir_dados(&dados);
                    // Prepara a mensagem de e-mail para o novo usuário.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Você fez seu cadastro no Sistema de Cadastro e Login CHAVEMESTRE como Usuário!\n    Ações na sua conta serão notificadas, não se preocupe!", dados.nome);
                    // Envia um e-mail de boas-vindas.
                    envia_email(&dados, mensagem_email);
                    ir_para(33, 19);
                    escreva("Usuario Cadastrado.", GREEN);

                    // Pergunta se o usuário deseja fazer login após o cadastro.
                    char quer_login;
                    do
                    {
                        ir_para(33, 20);
                        escreva("Deseja fazer login?", BLUE);
                        ir_para(30, 21);
                        printf("                                ");
                        ir_para(30, 21);
                        escreva("[1] ", GREEN);
                        printf("SIM ou ");
                        escreva("[2] ", RED);
                        printf("NAO : ");
                        scanf("%c", &quer_login);
                        apaga_buffer();
                        switch (quer_login)
                        {
                        case '1': // Se sim, chama a função de login.
                            login(&dados);
                            // Prepara e envia e-mail notificando o login.
                            snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Detectamos um novo login na sua Conta CHAVEMESTRE em um %s.\n    Caso não tenha sido você, entre em contato com algum administrador para verificar a ação.", dados.nome, SO);
                            envia_email(&dados, mensagem_email);
                            break;
                        case '2': // Se não, exibe mensagem de saída.
                            ir_para(32, 18);
                            escreva("Saindo do programa...", BLUE);
                            break;
                        default:       // Se a opção for inválida.
                            reset(21); // Limpa a tela a partir da linha 21.
                            ir_para(34, 18);
                            limpar_linha();
                            ir_para(33, 18);
                            escreva("DIGITO INVALIDO!", RED);
                            break;
                        }
                    } while (quer_login != '1' && quer_login != '2');
                    break;

                case '2':          // Fazer Login.
                    login(&dados); // Chama a função de login.
                    // Prepara e envia e-mail de notificação de login.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Detectamos um novo login na sua Conta CHAVEMESTRE em um %s.\n    Caso não tenha sido você, entre em contato com algum administrador", dados.nome, SO);
                    envia_email(&dados, mensagem_email);
                    break;

                case '3':                    // Recuperação de Senha.
                    recuperar_senha(&dados); // Chama a função de recuperação.
                    // Prepara e envia e-mail notificando a alteração de senha.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    A senha da sua Conta CHAVEMESTRE foi alterada.\n    Caso não tenha sido você, entre em contato com algum administrador para verificar a atividade!", dados.nome);
                    envia_email(&dados, mensagem_email);
                    break;

                case '4': // Sair.
                    ir_para(34, 16);
                    escreva("Saindo do programa...", BLUE);
                    exit(0); // Encerra o programa.
                    break;

                default:       // Opção inválida.
                    reset(14); // Limpa a tela a partir da linha 14.
                    ir_para(34, 16);
                    escreva("DIGITO INVALIDO!", RED);
                    break;
                }
            } while (menu_usuario != '1' && menu_usuario != '2' && menu_usuario != '3' && menu_usuario != '4');
            break;

            // Variável local para o submenu do administrador.
            char menu_adm;
        case '2': // Caso o usuário escolha "MENU ADMINISTRADOR".
            // Loop do Menu do Administrador.
            do
            {
                // Desenha a interface do menu do administrador.
                bordas();
                ir_para(25, 2);
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

                // Exibe as opções do submenu.
                ir_para(21, 9);
                escreva("           1.", PINK);
                printf(" CADASTRAR ADMINISTRADOR           ");
                ir_para(21, 10);
                escreva("           2.", PINK);
                printf(" LOGIN ADMINISTRADOR            ");
                ir_para(21, 11);
                escreva("           3.", PINK);
                printf(" RECUPERACAO DE SENHA          ");
                ir_para(21, 12);
                escreva("           4.", PINK);
                printf(" SAIR         ");

                // Solicita a entrada do usuário.
                ir_para(26, 13);
                limpar_linha();
                ir_para(26, 14);
                limpar_linha();
                ir_para(26, 15);
                limpar_linha();
                ir_para(26, 14);
                escreva("Digite a opcao que deseja: ", PINK);
                scanf("%c", &menu_adm);
                apaga_buffer();

                // Switch para tratar a opção do submenu do administrador.
                switch (menu_adm)
                {
                case '1': // Cadastro de novo administrador.
                    // Garante que o arquivo 'adms_cadastrados.bin' exista.
                    inicializar_arquivo(dados.menu_principal);
                    cadastro(&dados);
                    incluir_dados(&dados);
                    // Prepara e envia e-mail de boas-vindas.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Você fez seu cadastro no Sistema de Cadastro e Login CHAVEMESTRE como Administrador!\n    Ações na sua conta serão notificadas, não se preocupe!", dados.nome);
                    envia_email(&dados, mensagem_email);
                    ir_para(29, 19);
                    escreva("Administrador Cadastrado.", GREEN);

                    // Pergunta se o adm deseja fazer login após o cadastro.
                    char quer_login;
                    do
                    {
                        ir_para(32, 20);
                        escreva(" Deseja fazer login?", BLUE);
                        ir_para(30, 21);
                        printf("                                ");
                        ir_para(30, 21);
                        escreva("[1]", GREEN);
                        printf(" SIM ou");
                        escreva("[2]", RED);
                        printf(" NAO : ");
                        scanf("%c", &quer_login);
                        apaga_buffer();
                        switch (quer_login)
                        {
                        case '1': // Se sim, realiza o login.
                            login(&dados);
                            // Envia e-mail de notificação de login.
                            snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Detectamos um novo login na sua Conta CHAVEMESTRE em um %s.\n    Caso não tenha sido você, entre em contato com a gestão.", dados.nome, SO);
                            envia_email(&dados, mensagem_email);
                            // Exibe o menu de funções do administrador.
                            adm_funcoes(&dados);
                            break;
                        case '2': // Se não, exibe mensagem de saída.
                            ir_para(32, 18);
                            limpar_linha();
                            ir_para(32, 18);
                            escreva("Saindo do programa...", BLUE);
                            break;
                        default: // Se a opção for inválida.
                            reset(21);
                            ir_para(33, 18);
                            limpar_linha();
                            ir_para(34, 18);
                            escreva("DIGITO INVALIDO!", RED);
                            break;
                        }
                    } while (quer_login != '1' && quer_login != '2');
                    break;

                case '2': // Login do Administrador.
                    login(&dados);
                    // Prepara e envia e-mail de notificação de login.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    Detectamos um novo login na sua Conta CHAVEMESTRE em um %s.\n     Caso não tenha sido você, entre em contato com a gestão.", dados.nome, SO);
                    envia_email(&dados, mensagem_email);
                    // Após o login, mostra as funções de administrador.
                    adm_funcoes(&dados);
                    break;

                case '3': // Recuperação de Senha do Administrador.
                    recuperar_senha(&dados);
                    // Prepara e envia e-mail notificando a alteração de senha.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Olá, %s!\n\n    A senha da sua Conta CHAVEMESTRE foi alterada.\n    Caso não tenha sido você, entre em contato com a equipe de gestão!", dados.nome);
                    envia_email(&dados, mensagem_email);
                    envia_email(&dados, mensagem_email);
                    break;

                case '4': // Sair.
                    ir_para(32, 16);
                    limpar_linha();
                    ir_para(32, 16);
                    escreva("Saindo do programa...", BLUE);
                    exit(0);
                    break;

                default: // Opção inválida.
                    reset(14);
                    ir_para(34, 16);
                    escreva("DIGITO INVALIDO!", RED);
                    break;
                }
            } while (menu_adm != '1' && menu_adm != '2' && menu_adm != '3' && menu_adm != '4');
            break;

        case '3': // Sair do programa principal.
            ir_para(32, 16);
            escreva("Saindo do programa...", BLUE);
            break;

        default: // Opção inválida no menu principal.
            reset(14);
            ir_para(34, 16);
            escreva("DIGITO INVALIDO!", RED);
            break;
        }
        // O loop principal continua até que o usuário escolha uma opção que direcione para um submenu ('1' ou '2') ou saia ('3').
    } while (dados.menu_principal != '1' && dados.menu_principal != '2' && dados.menu_principal != '3');

    // Retorno padrão da função main, indica que o programa terminou com sucesso.
    return 0;
}