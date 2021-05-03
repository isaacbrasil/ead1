
#include "hotel.h"

#define disponivel 0
#define indisponivel 1

#define MAX 50
#define MAX_NAME 80
#define MAX_QUARTO 40

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char nome[MAX_NAME];
    char cpf[11];
    char telefone[10];
    char reserva;
    int id;
    float gasto;
} HOSPEDE;
typedef struct
{
    TIPOCHAVE chave;
    int disponibilidade;

} QUARTO;
typedef struct
{
    QUARTO Q[MAX_QUARTO];
    HOSPEDE H[MAX];

} HOTEL;
//-------------------------------- implementação das funções --------------------------------------

void menu()
{
    printf("Ola, Seja Bem Vindo\n");
    printf("\n\n-------------------------------------- MENU ------------------------------------------------------ \n\n");
    printf("-------------- R)  Reservar Quarto ---------------------------------------------------------------- \n");
    printf("-------------- E)  Cancelar a Reserva ------------------------------------------------------------- \n");
    printf("-------------- D)  Checar disponibilidade de um quarto -------------------------------------------- \n");
    printf("-------------- L)  Listar quartos disponiveis ----------------------------------------------------- \n");
    printf("-------------- S)  Servico de quarto -------------------------------------------------------------- \n");
    printf("-------------- V)  Valor da receita --------------------------------------------------------------- \n");
    printf("-------------- X) SAIR DO PROGRAMA ---------------------------------------------------------------- \n");
}
void menuReserva()
{

    printf("Qual a sua reserva ?\n");
    printf("\n\n-------------------------------------- MENU RESERVA------------------------------------------------ \n\n");
    printf("-------------- 1)  Cafe da Manha RS 125,00 ------------------------------------------------------------------------------- \n");
    printf("-------------- 2)  Meia Pensao RS 150,00 ------------------------------------------------------------------------------- \n");
    printf("-------------- 3)  Pensao Completa RS 175,00 ------------------------------------------------------------------------------- \n");
    printf("-------------- 4)  All-inclusive RS 250,00 ------------------------------------------------------------------------ \n");
}
char tipoReserva(HOTEL *h)
{
    char reserva;
    scanf("%c", &reserva);
    return reserva;
}
void reservaQuarto(HOTEL *h, int i)
{
    h->Q[i].disponibilidade = indisponivel;
    h->H[i].id = i;
    printf("Quarto reservado com sucesso!\n");
}

void getDadoCliente(HOTEL *h)
{
    printf("NOME: \n");
    scanf("%s", h->H->nome); // ver como scanear strings
    printf("CPF: \n");
    scanf("%s", h->H->cpf);
    printf("TELEFONE (XXXXX-XXXX): \n");
    scanf("%s", h->H->telefone);
}
void printDadoCliente(HOTEL *h)
{
    printf("NOME: %s\n", h->H->nome);
    printf("CPF: %s\n", h->H->cpf);
    printf("TELEFONE: %s\n", h->H->telefone);
}

void cancelaReserva();

void dispQuarto(HOTEL *h) // ok
{
    int i;
    for (i = 0; i < MAX_QUARTO; i++)
    {
        h->Q[i].disponibilidade = disponivel;
    }
}
void listagemQuartos(HOTEL *h) // ok
{
    int i;
    printf("Quartos disponiveis: ");

    for (i = 0; i < MAX_QUARTO; i++)
    {
        if (h->Q[i].disponibilidade == disponivel)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}
float receitaGeral();
float servicoQuarto();
void menu();
