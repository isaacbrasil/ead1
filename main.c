#include "hotel.c"

int main()

{
    HOTEL hotel;
    dispQuarto(&hotel);
    QUARTO dado, p, e;
    HOSPEDE hospede, dadoh, ph, eh, reservaTipo;
    int x, i = 0;
    char operacao = '0';

    inicializaID(&hotel);
    printf("\n Ola, Seja Bem Vindo\n");
    while (operacao != 'X')
    {
        menu();
        scanf(" %c", &operacao);

        // scanf("%c", &operacao);

        if (operacao == 'R') //reserva um quarto
        {
            char reservaTipo;

            CadastraHospede(&hotel, i); //i = id mas ele pede o id dentro da função
                                        // printDadoHospede(&hotel, i);
            printDadoHospede(&hotel, i);

            printf("Qual quarto voce quer reservar?\n");
            listagemQuartos(&hotel); //ANALISAR TODOS OS "&" DAS FUNÇÕES
            scanf("%d", &x);         // talvez não seja x e sim TIPOCHAVE chave da struct quarto
            printf("Qual id do Hospede a reservar quarto?\n");
            reservaQuarto(&hotel, x, i);
            // vetorReservados(&hotel, x);
            i++;
        }

        if (operacao == 'E') //cancela a reserva de um quarto
        {
            // cancelaReserva();
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
        // if (operacao == 'X') //ENCERRA
        // {
        //     printf("PROGRAMA ENCERRADO\n");
        //     break;
        // }
        if (operacao == 'M') //mostra todos os clientes
        {
            mostraHospedes(&hotel, i);
        }
    }
    printf("PROGRAMA ENCERRADO\n");
    return 0;
}