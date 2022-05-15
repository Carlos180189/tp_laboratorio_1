

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

#define MAX_TAM_CHAR 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}typedef Passenger;



int initPassengers(Passenger* list, int len);

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengers(Passenger* list, int len, int order);

int printPassenger(Passenger* list, int length, int estado);

int sortPassengersByCode(Passenger* list, int len, int order);

int Passenger_searchfirstemptyposition(Passenger list[], int len);

void pasajero_imprimirUno(Passenger p);

Passenger pasajero_CargarUnPasajero();
int Pasajero_Modificar(Passenger list[], int len);
Passenger Pasajero_ModificarunPasajero(Passenger p);


#endif /* ARRAYPASSENGER_H_ */
