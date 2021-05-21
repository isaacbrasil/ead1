#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int bool;
typedef int TIPOCHAVE;
typedef struct hotel HOTEL;
typedef struct quarto QUARTO;
typedef struct hospede HOSPEDE;

void inicializaID();      //OK
void reservaQuarto();     //OK
HOTEL criaHotel();        //OK
void valorReserva();      //OK
void mostraHospedes();    //OK
void CadastraHospede();   //OK
void printDadoHospede();  //OK
char tipoReserva();       //OK
void cancelaReserva();    //
void listagemQuartos();   //OK
void receitaGeral();      //
float servicoQuarto();    //
void menuServicoQuarto(); //OK
void menu();              //OK
void menuReserva();       //OK