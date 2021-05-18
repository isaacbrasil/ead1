
#include "hotel.h"

#define disponivel 0
#define indisponivel 1

#define MAX 50
#define MAX_NAME 80
#define MAX_QUARTO 40

struct hospede
{
    TIPOCHAVE chave;
    char nome[MAX_NAME];
    char cpf[12];
    char telefone[11];
    char reserva;
    int id;
    float gasto;
    int quarto;
};
struct quarto
{
    TIPOCHAVE chave;
    int disponibilidade;
};
struct hotel
{
    QUARTO Q[MAX_QUARTO];
    HOSPEDE H[MAX];
};
//-------------------------------- implementação das funções --------------------------------------

void menu()
{

    printf("\n\n-------------------------------------- MENU ------------------------------------------------- \n\n");
    printf("-------------- R)  Reservar Quarto ---------------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- E)  Cancelar a Reserva ------------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- D)  Checar disponibilidade de um quarto -------------------------------------------- \n");
    printf("-------------- L)  Listar quartos disponiveis ----------------------------------------------------- \n");
    printf("-------------- S)  Servico de quarto -------------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- V)  Valor da receita --------------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- M)  Mostra todos os Hospedes ------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- X) SAIR DO PROGRAMA ---------------------------------------------------------------- \n");
}
void menuReserva()
{

    printf("\nQual a sua reserva ?\n");
    printf("\n\n-------------------------------------- MENU RESERVA----------------------------------------------------------------- \n\n");
    printf("-------------- 1)  Cafe da Manha RS 125,00 ------------------------------------------------------------------------------- \n");
    printf("-------------- 2)  Meia Pensao RS 150,00 --------------------------------------------------------------------------------- \n");
    printf("-------------- 3)  Pensao Completa RS 175,00 ----------------------------------------------------------------------------- \n");
    printf("-------------- 4)  All-inclusive RS 250,00 ------------------------------------------------------------------------------- \n");
}
char tipoReserva(HOTEL *h, int i)
{
    scanf(" %c", &h->H[i].reserva);
    return h->H[i].reserva;
}
// HOTEL criaHotel()
// {
//     HOTEL hotel;
// }
void valorReserva(HOTEL *h, int i) // talvez trocar char por HOSPEDE *c e as variaveis sao c.reserva
{
    h->H->gasto = 0;

    if (h->H[i].reserva == '1')
    {
        h->H[i].gasto = 125;
    }
    if (h->H[i].reserva == '2')
    {
        h->H[i].gasto = 150;
    }
    if (h->H[i].reserva == '3')
    {
        h->H[i].gasto = 175;
    }
    if (h->H[i].reserva == '4')
    {
        h->H[i].gasto = 250;
    }
    printf("%.2f", h->H[i].gasto);
}

void reservaQuarto(HOTEL *h, int i, int idHosp)
{
    i = i - 1;
    h->Q[i].disponibilidade = indisponivel;
    h->H[idHosp].quarto = i;
    printf("Quarto reservado com sucesso!\n");
}

void CadastraHospede(HOTEL *h, int i)
{
    printf("NOME: \n");
    scanf("%s", h->H[i].nome); // ver como scanear strings
    printf("CPF: \n");
    scanf("%s", h->H[i].cpf);
    printf("TELEFONE (XXXXX-XXXX): \n");
    scanf("%s", h->H[i].telefone);
    h->H[i].id = i;
    menuReserva();

    switch (tipoReserva(h, i))
    {
    case '1':
        h->H[i].gasto = 125;
        break;
    case '2':
        h->H[i].gasto = 150;

        break;
    case '3':
        h->H[i].gasto = 175;

        break;
    case '4':
        h->H[i].gasto = 250;

        break;
    default:
        break;
    }
}
void printDadoHospede(HOTEL *h, int i)
{
    printf("NOME: %s\n", h->H[i].nome);
    printf("CPF: %s\n", h->H[i].cpf);
    printf("TELEFONE: %s\n", h->H[i].telefone);
    printf("CODIGO: %d\n", h->H[i].id);
    printf("RESERVA: %c\n", h->H[i].reserva);
    printf("TIPO: %.2f\n", h->H[i].gasto);
}

void cancelaReserva(HOTEL *h, int i)
{
    if (h->Q[i].disponibilidade == indisponivel)
    {
        h->Q[i].disponibilidade = disponivel;
        h->H[i].id = -1;
    }
}
void mostraHospedes(HOTEL *h, int i)
{
    int j;
    for (j = 0; j < MAX; j++)
    {
        if (h->H[i].id != -1)
        {
            printDadoHospede(h, i);
        }
    }
}
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
float receitaGeral(); // soma servicoQuarto + Reserva
void menuServicoQuarto()
{
    printf("Servicos Extras: \n");
    printf("\n\n-------------------------------------- Frigobar ------------------------------------------------ \n\n");
    printf("-------------- 1) Lata Refrigerante - R$ 3,50 ------------------------------------------------------------------------------ \n");
    printf("-------------- 2) Agua - Mineral R$ 2,00 ------------------------------------------------------------------------------- \n");
    printf("-------------- 3) Suco - R$ 3,00 ------------------------------------------------------------------------------- \n");
}
// float servicoQuarto(HOTEL *h)
// {
// }
void menu();
