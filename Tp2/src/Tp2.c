
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "ArrayPassenger.h"


#define MAX_PASSENGERS 2000

int main(void){

	setbuf(stdout,NULL);

	int opcion;

	char nombre[51];
	char apellido[51];
	float precio=0;
	int ID;
	int tipodepasajero=0;
	char codigodeVuelo[10];
	int rAlta;
	int rModificacion;
	int rBaja;



	Passenger list[MAX_PASSENGERS];

	initPassengers(list, MAX_PASSENGERS);


			do{

						printf("\n1. ALTA DE PASAJERO\n"
						"2. MODIFICAR DATOS DE PASAJERO\n"
						"3. BAJA DE PASAJERO\n"
						"4. INFORMAR\n"
						"\t\t1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n"
						"\t\t2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
						"\t\t3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n\n"
								"presione cualquier otra tecla para salir\n\n");

						opcion=Get_Int("Elija la opcion que desea realizar:\n\n","Error, reingrese la opcion");

						switch (opcion)
						{
							case 1:
									rAlta=addPassenger(list, MAX_PASSENGERS,ID,nombre,apellido,precio,tipodepasajero,codigodeVuelo);
									if(rAlta>=0)
									{
										puts("\nCarga exitosa!\nPasajero cargado:");
										pasajero_imprimirUno(list[rAlta]);
									}else{
										if(rAlta==-3)
										{
											puts("Lista llena");
										}else{
											puts("Falla en la carga");

										}

									}

							break;
							case 2:

									rModificacion = Pasajero_Modificar(list,MAX_PASSENGERS);
										if (rModificacion == 0){
											puts("PASAJERO MODIFICADO");
											printPassenger(list, MAX_PASSENGERS,OCUPADO);
										} else {
											puts("HUBO UN ERROR AL MODIFICAR DATOS DEL PASAJERO");
										}

								break;
							case 3:
										rBaja = removePassenger(list, MAX_PASSENGERS,OCUPADO);
										if (rBaja == 0) {
													puts("PASAJERO DADO DE BAJA");
													printPassenger(list,MAX_PASSENGERS,OCUPADO);
										}else{
											puts("HUBO UN ERROR AL DAR DE BAJA AL PASAJERO");
										}

								break;
							case 4:

							break;
						}

			}while(opcion ==1 || opcion==2 || opcion==3 || opcion==4);
	return 0;

}
