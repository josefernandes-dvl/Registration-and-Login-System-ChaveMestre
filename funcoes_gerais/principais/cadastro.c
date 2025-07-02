#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "prototipos.h"

// Função que realiza o cadastro do usuário ou administrador.
// Recebe um ponteiro para a struct 'Cadastro' para modificar seus campos diretamente.
void cadastro(Cadastro *dados)
{
    // Limpa a tela e desenha a interface do sistema para cadastro.
    limpar();
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c             Cadastro            %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,
           196, 196, 217);

    int nome_existe;
    char tentativa_nome[37];
    // --- COLETA E VALIDAÇÃO DO NOME ---
    // Loop para garantir que o nome informado seja válido (não duplicado e tamanho aceitável).
    do
    {
        ir_para(25, 9);
        limpar_linha();
        ir_para(25, 9);
        escreva("Nome: ", PINK);
        fgets(tentativa_nome, sizeof(tentativa_nome), stdin); // Lê o nome do usuário.

        // Caso o nome lido não contenha '\n', limpa o buffer para evitar problemas.
        if (strchr(tentativa_nome, '\n') == NULL)
            apaga_buffer();
        else // Remove o '\n' do final da string.
            tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';

        // Valida o tamanho máximo do nome (máximo 35 caracteres).
        if (strlen(tentativa_nome) > 35)
        {
            reset(9); // Limpa as linhas a partir da linha 9.
            ir_para(20, 14);
            escreva("A quantidade maxima de caracteres e 35!", RED);
        }

        // Verifica se o nome já está cadastrado usando a função 'verificar_nome'.
        nome_existe = verificar_nome(dados, tentativa_nome);
        if (nome_existe == 1)
        {
            ir_para(30, 14);
            limpar_linha();
            reset(9);
            ir_para(30, 14);
            escreva("Usuario ja cadastrado!", RED);
        }
    } while (nome_existe == 1 || strlen(tentativa_nome) > 35);
    // Repetir enquanto o nome for duplicado ou muito longo.

    ir_para(30, 14);
    limpar_linha();
    strcpy(dados->nome, tentativa_nome); // Copia o nome válido para a struct.

    // --- COLETA E VALIDAÇÃO DA SENHA ---
    char senha[50];
    char senha_conf[50];
    int senha_valida, flag = 1;

    do
    {
        flag = 1;
        senha_valida = 1; // Assume que a senha é válida no início.
        ir_para(25, 10);
        limpar_linha();
        ir_para(25, 10);
        escreva("Senha: ", PINK);

        get_secret(senha, sizeof(senha)); // Lê a senha sem mostrar na tela.
        ir_para(25, 11);
        limpar_linha();
        int tamanho = strlen(senha);
        int contem_digito = 0;

        // Valida tamanho da senha: mínimo 6 e máximo 20 caracteres.
        if (tamanho > 20)
        {
            reset(10);
            ir_para(20, 14);
            escreva("O tamanho maximo da senha e de 20 caracteres!", RED);
            flag = 0;
            senha_valida = 0;
        }
        else if (tamanho < 6)
        {
            ir_para(20, 14);
            limpar_linha();
            ir_para(27, 13);
            limpar_linha();
            ir_para(20, 14);
            escreva("O tamanho minimo da senha e de 6 caracteres!", RED);
            flag = 0;
            senha_valida = 0;
        }
        else
        {
            // Verifica se a senha contém pelo menos um dígito numérico.
            for (int j = 0; j < tamanho; j++)
            {
                if (isdigit(senha[j]))
                {
                    contem_digito = 1;
                    break;
                }
            }
            if (!contem_digito)
            {
                ir_para(20, 14);
                limpar_linha();
                ir_para(27, 13);
                limpar_linha();
                ir_para(20, 14);
                escreva("A senha deve conter pelo menos um numero!", RED);
                senha_valida = 0;
                flag = 0;
            }
        }

        // Se senha passou nas validações, pede a confirmação da senha.
        if (flag == 1)
        {
            ir_para(25, 11);
            escreva("Confirme sua Senha: ", PINK);
            get_secret(senha_conf, sizeof(senha_conf));

            // Confirmação deve ser igual à senha digitada.
            if (strcmp(senha, senha_conf) != 0)
            {
                ir_para(20, 14);
                limpar_linha();
                ir_para(27, 13);
                escreva("As senhas nao sao iguais!", RED);
                ir_para(25, 11);
                limpar_linha();
                senha_valida = 0;
            }
        }
    } while (!senha_valida); // Repete enquanto a senha for inválida.

    cifra_cesar(senha, 17);      // Aplica cifra de César para criptografar a senha.
    strcpy(dados->senha, senha); // Salva a senha criptografada.
    ir_para(20, 14);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DA PERGUNTA SECRETA ---
    int pergunta_valida;
    do
    {
        pergunta_valida = 1; // Assume que a pergunta é válida.
        ir_para(25, 12);
        escreva("Pergunta secreta: \n", PINK);
        ir_para(25, 13);
        limpar_linha();
        ir_para(25, 13);
        fgets(dados->pergunta, sizeof(dados->pergunta), stdin);

        // Remove '\n' e limpa buffer se necessário.
        if (strchr(dados->pergunta, '\n') == NULL)
            apaga_buffer();
        else
            dados->pergunta[strcspn(dados->pergunta, "\n")] = '\0';

        int tamanho = strlen(dados->pergunta);
        // Valida tamanho da pergunta (entre 10 e 50 caracteres).
        if (tamanho > 50)
        {
            reset(12);
            ir_para(20, 16);
            escreva("O tamanho maximo da pergunta e 50 caracteres!", RED);
            pergunta_valida = 0;
        }
        else if (tamanho < 10)
        {
            ir_para(20, 16);
            escreva("O tamanho minimo da pergunta e 10 caracteres!", RED);
            pergunta_valida = 0;
        }
    } while (!pergunta_valida); // Repetir se inválida.
    ir_para(20, 16);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DA RESPOSTA ---
    int resposta_valida;
    char resposta[51];
    do
    {
        resposta_valida = 1; // Assume que a resposta é válida.
        ir_para(25, 14);
        escreva("Resposta da pergunta secreta: ", PINK);
        ir_para(25, 15);
        limpar_linha();
        ir_para(25, 15);

        get_secret(resposta, sizeof(resposta)); // Entrada oculta da resposta.

        int tamanho = strlen(resposta);
        // Valida tamanho máximo da resposta (50 caracteres).
        if (tamanho > 50)
        {
            reset(13);
            ir_para(20, 18);
            escreva("O tamanho maximo da resposta e de 50 caracteres!", RED);
            resposta_valida = 0;
        }
    } while (!resposta_valida); // Repetir se inválida.

    cifra_cesar(resposta, 23); // Criptografa a resposta.
    strcpy(dados->resposta, resposta);
    ir_para(20, 17);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DO CPF ---
    do
    {
        ir_para(25, 16);
        limpar_linha();
        ir_para(25, 16);
        escreva("CPF: ", PINK);
        fgets(dados->cpf, sizeof(dados->cpf), stdin);

        // Limpa buffer caso a entrada tenha excedido o limite.
        if (strchr(dados->cpf, '\n') == NULL)
        {
            apaga_buffer();
            reset(16);
            ir_para(25, 18);
            escreva("Entrada muito longa!", RED);
            continue; // Reinicia o loop.
        }

        dados->cpf[strcspn(dados->cpf, "\n")] = '\0'; // Remove '\n'.

        int cpf_valido_formatado = 1;

        // Verifica se todos os 11 caracteres são dígitos.
        for (int i = 0; i < 11; i++)
        {
            if (!isdigit(dados->cpf[i]))
            {
                cpf_valido_formatado = 0;
                break;
            }
        }

        // Valida o tamanho e formato do CPF.
        if (cpf_valido_formatado == 0 || strlen(dados->cpf) != 11)
        {
            ir_para(25, 18);
            limpar_linha();
            reset(15);
            ir_para(25, 18);
            escreva("CPF Invalido!", RED);
        }
        else
        {
            break; // CPF válido, sai do loop.
        }
    } while (1);
    ir_para(25, 18);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DO E-MAIL ---
    int eh_email;
    do
    {
        eh_email = 1; // Assume inválido.
        ir_para(25, 17);
        limpar_linha();
        ir_para(25, 17);
        escreva("Email: ", PINK);
        fgets(dados->email, sizeof(dados->email), stdin);
        dados->email[strcspn(dados->email, "\n")] = '\0';

        int tamanho = strlen(dados->email);

        // Validação simples: verifica se contém '@'.
        for (int i = 0; i < tamanho; i++)
        {
            if (dados->email[i] == '@')
            {
                eh_email = 0; // Possível e-mail válido.
                break;
            }
        }

        // Se inválido ou muito curto, exibe mensagem de erro.
        if (eh_email == 1 || tamanho < 6)
        {
            reset(17);
            ir_para(32, 20);
            escreva("Email Invalido!", RED);
        }
    } while (eh_email == 1 || strlen(dados->email) < 6); // Repetir se inválido.
    ir_para(32, 19);
    limpar_linha();
}
