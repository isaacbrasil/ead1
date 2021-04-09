#include <stdio.h>
#include <malloc.h>

void menu()
{
    printf("Ola, Seja Bem Vindo\n");
}
int main()

{
    char operacao;

    menu();
    scanf("%c", &operacao);
    do
    {
        scanf("%c", &operacao);
        if (operacao == 'R') //reserva um quarto
        {
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