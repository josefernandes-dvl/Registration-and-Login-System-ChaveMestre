#include <stdio.h>
#include <string.h>
#include "C:/msys64/mingw64/include/curl/curl.h" // Biblioteca libcurl para transferências via URL, usada aqui para SMTP
#include "prototipos.h"

// Struct para manter os dados do e-mail em memória durante o envio
struct upload_data
{
    const char *readptr; // Ponteiro para os dados da mensagem que serão enviados
    size_t sizeleft;     // Quantidade de bytes restantes para enviar
};

// Callback de leitura usado pelo libcurl para enviar dados em partes
// Essa função será chamada pelo libcurl sempre que precisar enviar mais dados
size_t read_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    struct upload_data *data = (struct upload_data *)userdata; // Cast do ponteiro void para struct correta
    size_t max = size * nmemb;                                 // Número máximo de bytes que podem ser copiados neste ciclo

    if (data->sizeleft == 0)
        return 0; // Se não há mais dados a enviar, retorna zero para indicar fim da transferência

    // Determina quantos bytes copiar: o menor entre os disponíveis e o máximo que cabe no buffer
    size_t to_copy = data->sizeleft < max ? data->sizeleft : max;

    // Copia os dados para o buffer apontado por ptr
    memcpy(ptr, data->readptr, to_copy);

    // Atualiza o ponteiro e o tamanho restante, para próxima chamada
    data->readptr += to_copy;
    data->sizeleft -= to_copy;

    return to_copy; // Retorna quantos bytes foram copiados para envio
}

// Função para enviar e-mail contendo nova senha para o usuário
void envia_email(Cadastro *dados, char mensagem_email[])
{
    const char *remetente = "chavemestre.tech@gmail.com"; // Email do remetente (conta de envio)
    const char *codigo = "cqxb tmuh zwgu zsxm";           // Codigo do remetente para autenticação SMTP

    // Verificação simples: se a senha não estiver definida, exibe erro e sai da função
    if (!codigo)
    {
        ir_para(15, 16); // Função para posicionar o cursor no terminal (linha 17, coluna 16)
        fprintf(stderr, "\033[1;33mErro: variavel de ambiente EMAIL_SENHA nao definida.\033[0m");
        return;
    }

    CURL *curl;                           // Ponteiro para estrutura CURL, que controla a operação
    CURLcode res;                         // Variável para armazenar código de retorno das operações CURL
    struct curl_slist *recipients = NULL; // Lista encadeada para armazenar destinatários do email
    char mensagem[1024];                  // Buffer para montar o corpo do email

    // Monta a mensagem do email no formato SMTP padrão
    snprintf(mensagem, sizeof(mensagem),
             "To: %s\r\n"                               // Destinatário
             "From: %s\r\n"                             // Remetente
             "Subject: Sistema de Cadastro e Login\r\n" // Assunto
             "\r\n"                                     // Linha em branco separando cabeçalho do corpo
             "%s",                                      // Corpo
             dados->email, remetente, mensagem_email);

    // Inicializa struct com dados da mensagem para envio via callback
    struct upload_data payload = {
        .readptr = mensagem,
        .sizeleft = strlen(mensagem)};

    curl = curl_easy_init(); // Inicializa libcurl, retornando objeto de controle
    if (curl)
    {
        // Configura autenticação SMTP com usuário e senha
        curl_easy_setopt(curl, CURLOPT_USERNAME, remetente);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, codigo);

        // Define URL do servidor SMTP com SSL via porta 465
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:465");

        // Define o endereço do remetente
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, remetente);

        // Adiciona destinatário à lista de emails
        recipients = curl_slist_append(recipients, dados->email);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Define a função callback que libcurl usará para obter os dados da mensagem
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, &payload);

        // Habilita o modo upload, pois o libcurl irá enviar dados
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Usa SSL para conexão segura
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

        // Executa a operação de envio
        res = curl_easy_perform(curl);

        // Verifica se ocorreu erro no envio
        if (res != CURLE_OK)
        {
            ir_para(4, 23);
            printf("\033[1;90mErro ao enviar email para: %s\033[0m", dados->email); // Mensagem de erro em amarelo
        }
        else
        {
            ir_para(4, 23);
            printf("\033[1;90mEmail enviado para: %s\033[0m", dados->email); // Mensagem de sucesso em amarelo
        }

        // Libera memória da lista de destinatários
        curl_slist_free_all(recipients);

        // Limpa recursos alocados pelo libcurl
        curl_easy_cleanup(curl);
    }
}
