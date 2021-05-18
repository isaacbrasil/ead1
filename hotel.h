#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int bool;
typedef int TIPOCHAVE;
typedef struct hotel HOTEL;
typedef struct quarto QUARTO;
typedef struct hospede HOSPEDE;

void reservaQuarto(); //OK
HOTEL criaHotel();    //
void valorReserva();  //
void mostraHospedes();
void CadastraHospede();   //OK
void printDadoHospede();  //OK
char tipoReserva();       //OK
void cancelaReserva();    //
void dispQuarto();        //OK
void listagemQuartos();   //OK
float receitaGeral();     //
float servicoQuarto();    //
void menuServicoQuarto(); //
void menu();              //OK
void menuReserva();       //