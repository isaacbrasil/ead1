#include <stdio.h>
#include <malloc.h>
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
    char telefone[9];
    char reserva;
} HOSPEDE;
typedef struct
{
    TIPOCHAVE chave;
    int disponibilidade;
    char nomeHospede[MAX_NAME];
} QUARTO;
typedef struct
{
    QUARTO Q[MAX_QUARTO];
    HOSPEDE H[MAX];

} HOTEL;

//-------------------------------------- main --------------------------------------
int main()

{
    HOTEL hotel;
    dispQuarto(&hotel);
    QUARTO dado, p, e;
    HOSPEDE dadoh, ph, eh;
    int x;
    char operacao;
    // menu();

    listagemQuartos(&hotel);
    scanf("%d", &x); // qual quarto reservar

    reservaQuarto(&hotel, x - 1);
    listagemQuartos(&hotel);

    // scanf("%c", &operacao);
    // do
    // {
    //     scanf("%c", &operacao);
    //     if (operacao == 'R') //reserva um quarto
    //     {
    //         listagemQuartos(&hotel);
    //         scanf("%d", &x);

    //         reservaQuarto(&hotel, x - 1);
    //     }

    //     if (operacao == 'E') //cancela a reserva de um quarto
    //     {
    //     }

    //     if (operacao == 'D') //vê se um quarto está vazio
    //     {
    //     }

    //     if (operacao == 'L') //vê a lista de todos os quartos vazios
    //     {
    //     }
    //     if (operacao == 'V') //valor da receita
    //     {
    //     }
    //     if (operacao == 'X') //ENCERRA
    //     {
    //         printf("fim\n");
    //         break;
    //     }

    // } while (1);
    return 0;
}
//-------------------------------- implementação das funções --------------------------------------

void menu()
{
    printf("Ola, Seja Bem Vindo\n");
    printf("\n\n-------------------------------------- MENU ------------------------------------------------------ \n\n");
    printf("-------------- R)  Reserva Quarto ---------------------------------------------------------------- \n");
    printf("-------------- E)  Cancela a Reserva ------------------------------------------------------------- \n");
    printf("-------------- D)  Checa disponibilidade de um quarto -------------------------------------------- \n");
    printf("-------------- L)  Listagem de quartos vazios ---------------------------------------------------- \n");
    printf("-------------- S)  Servico de quarto ------------------------------------------------------------- \n");
    printf("-------------- V)  Valor da receita -------------------------------------------------------------- \n");
    printf("-------------- X) SAIR DO PROGRAMA --------------------------------------------------------------- \n");
}
void menuReserva()
{
    printf("Qual a sua reserva ?\n");
    printf("\n\n-------------------------------------- MENU RESERVA------------------------------------------------ \n\n");
    printf("-------------- 1)  Normal ------------------------------------------------------------------------------- \n");
    printf("-------------- 2)  All-inclusive ------------------------------------------------------------------------ \n");
}
void reservaQuarto(HOTEL *h, int i)
{
    h->Q[i].disponibilidade = indisponivel;
    printf("Quarto reservado com sucesso!\n");
}

int tipoReserva();
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
