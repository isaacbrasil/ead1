#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int bool;
typedef int TIPOCHAVE;
typedef struct hotel HOTEL;
typedef struct quarto QUARTO;
typedef struct hospede HOSPEDE;

void reservaQuarto();     //OK
HOTEL criaHotel();        //OK
void valorReserva();      //OK
void mostraHospedes();    //
void vetorReservados();   //
void CadastraHospede();   //OK
void printDadoHospede();  //OK
char tipoReserva();       //OK
void cancelaReserva();    //
void dispQuarto();        //
void listagemQuartos();   //OK
float receitaGeral();     //
float servicoQuarto();    //
void menuServicoQuarto(); //OK
void menu();              //OK
void menuReserva();       //OK