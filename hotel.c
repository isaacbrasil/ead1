
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

    printf("\n\n-------------------------------------- MENU --------------------------------------------------- \n\n");
    printf("-------------- R)  Reservar Quarto ---------------------------------------------------------------- \n"); //ver se hospede i existe
    printf("-------------- E)  Cancelar a Reserva ------------------------------------------------------------- \n"); //ver se hospede i existe
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
// void valorReserva(HOTEL *h, int i) // talvez trocar char por HOSPEDE *c e as variaveis sao c.reserva
// {
//     h->H->gasto = 0;

//     if (h->H[i].reserva == '1')
//     {
//         h->H[i].gasto = 125;
//     }
//     if (h->H[i].reserva == '2')
//     {
//         h->H[i].gasto = 150;
//     }
//     if (h->H[i].reserva == '3')
//     {
//         h->H[i].gasto = 175;
//     }
//     if (h->H[i].reserva == '4')
//     {
//         h->H[i].gasto = 250;
//     }
//     printf("%.2f", h->H[i].gasto);
// }

void reservaQuarto(HOTEL *h, int i, int idHosp)
{
    i = i - 1;
    h->Q[i].disponibilidade = indisponivel;
    h->H[idHosp].quarto = i;
    printf("\nQuarto reservado com sucesso!\n");
}
void CadastraHospede(HOTEL *h, int i)
{
    printf("NOME: \n");
    getchar();
    fgets(h->H[i].nome, MAX_NAME, stdin);
    printf("CPF: \n");
    scanf("%s", h->H[i].cpf);
    printf("TELEFONE (XXXXX-XXXX): \n");
    scanf("%s", h->H[i].telefone);
    h->H[i].id = i + 1;
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
void cancelaReserva(HOTEL *h, int i)
{

    i--;

    if (h->Q[i].disponibilidade == disponivel)
    {
        printf("Esse quarto esta disponivel: \n");
    }
    else
    {
        h->Q[i].disponibilidade = disponivel;
        printf("Reserva cancelada com sucesso: \n");
    }
}
void printDadoHospede(HOTEL *h, int i)
{

    printf("\nNOME: %s", h->H[i].nome);
    printf("CPF: %s\n", h->H[i].cpf);
    printf("TELEFONE: %s\n", h->H[i].telefone);
    printf("CODIGO: %d\n", h->H[i].id);
    if (h->H[i].reserva == '1')
    {
        printf("RESERVA: %c - Cafe da Manha\n", h->H[i].reserva);
    }
    if (h->H[i].reserva == '2')
    {
        printf("RESERVA: %c - Meia Pensao\n", h->H[i].reserva);
    }
    if (h->H[i].reserva == '3')
    {
        printf("RESERVA: %c - Pensao Completa\n", h->H[i].reserva);
    }
    if (h->H[i].reserva == '4')
    {
        printf("RESERVA: %c - All-inclusive\n", h->H[i].reserva);
    }

    printf("GASTO: %.2f\n\n", h->H[i].gasto);
}

void inicializaID(HOTEL *h)
{
    int j;
    for (j = 0; j < MAX; j++)
    {

        h->H[j].id = 0;
    }
}
void mostraHospedes(HOTEL *h, int i)
{
    int j;
    printf("\n\n------ TODOS OS HOSPEDES ------ \n\n");

    for (j = 0; j < MAX; j++)
    {
        if (h->Q[j].disponibilidade == indisponivel)
        {
            if (h->H[j].id == (int)h->H[j].id && h->H[j].id <= MAX && h->H[j].id > 0)
            {
                printDadoHospede(h, j);
            }
        }
    }
    printf("\n\n----- FIM DA LISTA ----------- \n\n");
}
void receitaGeral(HOTEL *h, int i) // soma servicoQuarto + Reserva
{

    int j;
    printf("\n\n------ RECEITA GERAL ------ \n\n");

    for (j = 0; j < MAX; j++)
    {
        if (h->H[j].id == (int)h->H[j].id && h->H[j].id <= MAX && h->H[j].id > 0)
        {
            printf("\nNOME: %s", h->H[j].nome);
            printf("CPF: %s\n", h->H[j].cpf);
            printf("GASTO TOTAL: %.2f\n\n", h->H[j].gasto);
        }
    }
    printf("\n\n----- FIM DA LISTA ----------- \n\n");
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

void menuServicoQuarto()
{
    // printf("Servicos Extras: \n");
    printf("\n\n---------- Frigobar --------------------------------------------------------------------------------------------------- \n\n");
    printf("-------------- 1) Lata Refrigerante - R$ 3,50 ------------------------------------------------------------------------------ \n");
    printf("-------------- 2) Agua - Mineral R$ 2,00 ----------------------------------------------------------------------------------- \n");
    printf("-------------- 3) Suco - R$ 3,00 ------------------------------------------------------------------------------------------- \n");
    printf("\n\n---------- Lanches --------------------------------------------------------------------------------------------------- \n\n");
    printf("-------------- 4) Amendoim - R$ 4,50 ------------------------------------------------------------------------------------------- \n");
    printf("-------------- 5) Chocolate - R$ 3,00 ------------------------------------------------------------------------------------------- \n");
}
float servicoQuarto(HOTEL *h, int i)
{
    char servico;
    i--;

    menuServicoQuarto();

    scanf(" %c", &servico);

    switch (servico)
    {
    case '1':
        h->H[i].gasto += 3.5;
        break;
    case '2':
        h->H[i].gasto += 2;

        break;
    case '3':
        h->H[i].gasto += 3;

        break;
    case '4':
        h->H[i].gasto += 4.5;

        break;
    case '5':
        h->H[i].gasto += 3;

        break;
    default:
        break;
    }
}
void menu();
