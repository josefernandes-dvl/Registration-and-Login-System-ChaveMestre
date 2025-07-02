#pragma once
// Diretiva para garantir que este arquivo seja incluído apenas uma vez durante
// a compilação, evitando redefinições e erros.

// Definição da estrutura 'Cadastro' que armazena as informações de um usuário ou administrador
typedef struct
{
    char nome[37];       // Nome do usuário (até 36 caracteres + caractere nulo)
    char pergunta[52];   // Pergunta de segurança para recuperação de senha (até 51 caracteres + '\0')
    char resposta[50];   // Resposta da pergunta de segurança (até 49 caracteres + '\0')
    char senha[31];      // Senha do usuário (até 30 caracteres + '\0')
    char cpf[13];        // CPF do usuário sem pontuação (11 dígitos + '\0')
    char email[50];      // Email do usuário (até 49 caracteres + '\0')
    char menu_principal; // Indica se é usuário ('1') ou administrador ('2')
} Cadastro;

// Enumeração para as cores usadas na interface, associando letras para representar cores
typedef enum
{
    RED = 'r',   // Vermelho
    GREEN = 'g', // Verde
    BLUE = 'a',  // Azul
    PINK = 'p'   // Rosa
} Color;

// --- Protótipos das Funções Principais ---
// Permitem declarar as funções para o compilador antes da implementação real,
// facilitando a organização do código.

// Funções para cadastro, login e recuperação de senha, operando diretamente na struct Cadastro
void cadastro(Cadastro *dados);        // Registra um novo usuário ou administrador
void login(Cadastro *dados);           // Realiza autenticação de usuário ou administrador
void recuperar_senha(Cadastro *dados); // Permite recuperação de senha via pergunta de segurança

// --- Protótipos das Funções do Administrador ---
// Funções específicas para o menu e operações do administrador
void adm_funcoes(Cadastro *dados);      // Exibe o menu de funções administrativas
void listagem_usuario(void);            // Lista todos os usuários cadastrados
void localiza_usuario(Cadastro *dados); // Busca um usuário específico pelo nome ou outro dado
void excluir_usuario(Cadastro *dados);  // Remove um usuário do sistema

// --- Protótipos das Funções de Interface (ADK - ANSIstyle Dev Kit) ---
// Funções auxiliares para controle e desenho da interface no terminal
void limpar(void);                  // Limpa toda a tela do terminal
void ir_para(int x, int y);         // Move o cursor para a posição (coluna x, linha y)
void bordas(void);                  // Desenha bordas na interface do terminal
void limpar_linha(void);            // Limpa uma linha específica da tela
void escreva(char *s, Color color); // Imprime texto colorido no terminal
void reset(int n);                  // Limpa da linha n para baixo e redesenha bordas

// --- Protótipos das Funções Secundárias (Utilitárias) ---
// Funções utilitárias para auxiliar em tarefas específicas
void apaga_buffer(void);                                  // Limpa o buffer de entrada para evitar erros na leitura
void envia_email(Cadastro *dados, char mensagem_email[]); // Envia um email com a mensagem especificada
void cifra_cesar(char *codificada, int deslocamento);     // Aplica ou decifra a cifra de César na string passada
void get_secret(char *s, int tam);                        // Lê entrada secreta do usuário (ex: senha) escondendo os caracteres

// --- Protótipos das Funções de Manipulação de Arquivos Binários ---
// Funções para gerenciar o armazenamento persistente dos dados em arquivos binários
void inicializar_arquivo(char menu_principal);              // Cria o arquivo binário se não existir (usuário ou adm)
void incluir_dados(Cadastro *dados);                        // Grava um novo cadastro no arquivo binário
int verificar_nome(Cadastro *dados, char tentativa_nome[]); // Verifica se um nome já está cadastrado
int alterar_senha(Cadastro *dados);                         // Altera a senha de um usuário existente no arquivo
