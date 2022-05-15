


#include "ArrayPassenger.h"


static int idAutoincremental=1000;
static int pasajero_ObtenerId(void);
static int pasajero_ObtenerId(){
	return idAutoincremental++;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len)
{

	int i;
	int rtn=0;
	if(list !=NULL){
		if(len>0){
			// esta ok
			for(i=0; i<len;i++){
				list[i].isEmpty=LIBRE;

			}
		}else{
			rtn=-2;
		}
	}else{
		rtn=-1;
	}
	return rtn;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int rtn = 0;
	int primerindexLibre;
	Passenger auxiliarPassenger;

	primerindexLibre = Passenger_searchfirstemptyposition(list, len);

	if (list != NULL) {
		if (len > 0) {
			if (primerindexLibre >=0) {

				auxiliarPassenger = pasajero_CargarUnPasajero();

				auxiliarPassenger.id = pasajero_ObtenerId();
				auxiliarPassenger.isEmpty = OCUPADO;


				list[primerindexLibre] = auxiliarPassenger;
				rtn=primerindexLibre;


			} else {
				rtn = -3;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}

	return rtn;
}


/** \brief find a Passenger by Id en returns the index position in array.
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int rtn = 0;
		int flag = 0;
		int i;
		int buscarID;

		if (list!= NULL) {
			if (len > 0) {

				printPassenger(list, len, OCUPADO);

				buscarID = Get_Int("ID: ", "ERROR.");

				for (i = 0; i < len; i++) {
					if (list[i].isEmpty == OCUPADO) {
						if (list[i].id == buscarID) {
							flag = 1;
							rtn = i;
							break;
						}
					}
				}

				if (flag == 0) {
					rtn = -1;
				}
			} else {
				rtn = -2;
			}
		} else {
			rtn = -3;
		}

		return rtn;
}
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*/
int removePassenger(Passenger* list, int len, int id){
	int rtn = 0;
	int indexBaja;

	if (list != NULL) {
		if (len > 0) {

			indexBaja = findPassengerById(list, len,id);
			if (indexBaja < 0) {
				rtn = -1;
			} else {
				list[indexBaja].isEmpty = BAJA;
			}

		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}



/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(Passenger* list, int len, int order)
{
	return 0;
}

/** \brief print the content of passengers array
* \param list Passenger*
* \param length int
* \return int
*/
int printPassenger(Passenger* list, int length, int estado)
{
	int i;
	int rtn=1;
	if(list !=NULL){
		if(length>0){
			// esta todo bien
			for(i=0; i<length;i++){
				if(estado==-1){
					pasajero_imprimirUno(list[i]);
				}else{

					if(list[i].isEmpty==estado){
						pasajero_imprimirUno(list[i]);
					}
				}
			}
		}else{
			rtn=-2;
		}
	}else{
		rtn=-1;
	}
	return rtn;
}


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(Passenger* list, int len, int order)
{
	return 0;
}

/**
 \brief Search the first empty position in Array Passenger
/// @param list Passenger*
/// @param len int
/// @return position if it can be found or 0 if it can't be founded.
 */
int Passenger_searchfirstemptyposition(Passenger list[], int len) {
	int rtn = 0;
	int flag = 0;
	int i;

	if (list != NULL) {
		if (len> 0) {
			for (i = 0; i < len; i++){
				if(list[i].isEmpty== LIBRE){
					flag = 1;
					rtn = i;
					break;
				}
			}

			if (flag == 0) {
				rtn = -1;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}


Passenger pasajero_CargarUnPasajero(){

   Passenger p;

	Get_String("\nNombre:","ERROR",p.name,MAX_TAM_CHAR);
	Get_String("\nApellido:","ERROR",p.lastName,MAX_TAM_CHAR);

	p.price=Get_Float("Precio:$","error");


	Get_String("\nCodigo de Vuelo:","ERROR",p.flycode,MAX_TAM_CHAR);

	p.typePassenger=Get_IntRange("Tipo de pasajero:\n\t1.Ejecutivo\n\t2.Media\n"
			"\t3.Baja\n","ERROR",1,3);

   return p;

}


void pasajero_imprimirUno(Passenger p){


	printf("ID %d\n"
			"nombre:%s\n"
			"apellido: %s\n"
			"Precio:$ %.2f\n"
			"Nº de vuelo: %s\n"
			"Tipo de pasajero:\n%d\n",
			p.id,p.name,p.lastName,p.price,p.flycode,p.typePassenger);


}

int Pasajero_Modificar(Passenger list[], int len) {

	int rtn = 0;
	int indexModificacion;
	Passenger auxiliarPasajero;

	if (list != NULL) {
		if (len > 0) {
			indexModificacion = findPassengerById(list,
					len,OCUPADO);
			if (indexModificacion < 0) {
				rtn = -1;
			} else {
				auxiliarPasajero = list[indexModificacion];
				auxiliarPasajero = Pasajero_ModificarunPasajero(auxiliarPasajero);
				list[indexModificacion] = auxiliarPasajero;
			}

		} else {
			rtn = -2;
		}
	} else {
		rtn = -3;
	}

	return rtn;
}

Passenger Pasajero_ModificarunPasajero(Passenger p) {

	int opcion = Get_Int("Seleccione una opcion a modificar:\n"
			"\t1.Nombre\n"
			"\t2.Apellido\n"
			"\t3.Precio\n"
			"\t4.Nº de vuelo\n"
			"\t5.Tipo de pasajero\n",
			"Error.");


	switch (opcion) {
			case 1:
					Get_String("\nNombre:","ERROR",p.name,MAX_TAM_CHAR);

				break;
			case 2:
				Get_String("\nApellido:","ERROR",p.lastName,MAX_TAM_CHAR);

				break;
			case 3:
				p.price=Get_Float("Precio:$","error");

				break;
			case 4:
				Get_String("\nCodigo de Vuelo:","ERROR",p.flycode,MAX_TAM_CHAR);

				break;
			case 5:
				p.typePassenger=Get_IntRange("Tipo de pasajero:\n\t1.Ejecutivo\n\t2.Media\n"
						"\t3.Baja\n","ERROR",1,3);
			break;
			default:
			break;
	}

	return p;
}




