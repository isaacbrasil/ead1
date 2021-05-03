#include "hotel.c"

int main()

{
    HOTEL hotel;
    dispQuarto(&hotel);
    QUARTO dado, p, e;
    HOSPEDE dadoh, ph, eh, reservaTipo;
    int x;
    char operacao;

    menu();

    // listagemQuartos(&hotel);
    // printf("Qual quarto voce quer reservar?\n");
    // scanf("%d", &x); // qual quarto reservar

    // reservaQuarto(&hotel, x - 1);

    // printf("id do cliente: %d\n", hotel.H->id);
    // listagemQuartos(&hotel);

    scanf("%c", &operacao);
    do
    {
        // scanf("%c", &operacao);
        if (operacao == 'R') //reserva um quarto
        {
            printf("Qual quarto voce quer reservar?\n");
            listagemQuartos(&hotel);
            scanf("%d", &x); // talvez não seja x e sim TIPOCHAVE chave da struct quarto
            reservaQuarto(&hotel, x - 1);
            getDadoCliente(&hotel);
            printDadoCliente(&hotel);
            menuReserva();

            if (tipoReserva(&hotel) == '1')
            {
                hotel.H->gasto = 125;
                // dadoh.gasto = 125;
                printf("alo\n");
                // printf("%f", dadoh.gasto);
            }
            if (tipoReserva(&hotel) == '2')
            {
                dadoh.gasto = 150;
            }
            if (tipoReserva(&hotel) == '3')
            {
                dadoh.gasto = 175;
            }
            if (tipoReserva(&hotel) == '4')
            {
                dadoh.gasto = 250;
            }
        }

        if (operacao == 'E') //cancela a reserva de um quarto
        {
        }

        if (operacao == 'D') //vê se um quarto está vazio
        {
        }

        if (operacao == 'L') //vê a lista de todos os quartos vazios
        {
        }
        if (operacao == 'V') //valor da receita
        {
        }
        if (operacao == 'X') //ENCERRA
        {
            printf("fim\n");
            break;
        }

    } while (1);
    return 0;
}