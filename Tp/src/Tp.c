

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main (void)
{
	setbuf(stdout,NULL);

	int opcion;
	int respuesta;

	float kilometros;
	float PrecioVueloAerolineas;
	float PrecioVueloLatam;
	float respuestaPrecioVueloAerolineas;
	float respuestaPrecioVueloLatam;
	float respuestakm;
	float TarjetadeDebitoA;
	float TarjetadeDebitoL;
	float tarjetadeCreditoA;
	float tarjetadeCreditoL;
	float BitcoinA;
	float BitcoinL;
	float PuA;
	float PuL;
	float DiferenciadePrecio;

			do
			{
				respuesta=utn_getNumero(&opcion,"\n1. Ingresar Kilómetros:\n2. Ingresar Precio de Vuelos:\n- Precio vuelo Aerolíneas:\n- Precio vuelo Latam:\n3. Calcular todos los costos:\na) Tarjeta de débito (descuento 10%)\nb) Tarjeta de crédito (interés 25%)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n4. Informar Resultados\nLatam:\na) Precio con tarjeta de débito:\nb) Precio con tarjeta de crédito:\nc) Precio pagando con bitcoin :\nd) Precio unitario:\nAerolíneas:\na) Precio con tarjeta de débito:\nb) Precio con tarjeta de crédito:\nc) Precio pagando con bitcoin :\nd) Precio unitario:\nLa diferencia de precio es :\n5. Carga forzada de datos\n6. Salir\n","No es una opcion válida\n",1,6,2);


						switch(opcion)
						{
								case 1:
									respuestakm=utn_getNumeroFlotante(&kilometros,"1. Ingrese Kilómetros a realizar, por favor:\nKm=","Por favor, reingrese su kilometraje correctamente\n(entre 50km y 100.000 km)\nKm=",50,1000000,2);
								break;
								case 2:
									respuestaPrecioVueloAerolineas=utn_getNumeroFlotante(&PrecioVueloAerolineas,"-Ingrese Precio de vuelo Aerolineas, por favor\n$:","Por favor, reingrese su precio correctamente\n(Importe mayor a 0)\n$:",0,1000000,2);
									respuestaPrecioVueloLatam=utn_getNumeroFlotante(&PrecioVueloLatam,"-Ingrese Precio de vuelos Latam, por favor\n$:","Por favor, reingrese su precio correctamente\n(Importe mayor a 0)\n$:",0,1000000,2);
									break;
								case 3:
									Calcularcostos(kilometros, PrecioVueloAerolineas,PrecioVueloLatam, &TarjetadeDebitoA,&TarjetadeDebitoL,&tarjetadeCreditoA,&tarjetadeCreditoL,&BitcoinA,&BitcoinL,&PuA,&PuL,&DiferenciadePrecio);
								break;
								case 4:
									MostrarRdos(kilometros,PrecioVueloAerolineas,PrecioVueloLatam,TarjetadeDebitoA,TarjetadeDebitoL,tarjetadeCreditoA,tarjetadeCreditoL,BitcoinA,BitcoinL,PuA,PuL,DiferenciadePrecio);
								break;
								case 5:
									kilometros=7090;
									PrecioVueloAerolineas=162965;
									PrecioVueloLatam=159339;
									Calcularcostos(kilometros,PrecioVueloAerolineas,PrecioVueloLatam, &TarjetadeDebitoA,&TarjetadeDebitoL,&tarjetadeCreditoA,&tarjetadeCreditoL,&BitcoinA,&BitcoinL,&PuA,&PuL,&DiferenciadePrecio);
									MostrarRdos(kilometros,PrecioVueloAerolineas,PrecioVueloLatam,TarjetadeDebitoA,TarjetadeDebitoL,tarjetadeCreditoA,tarjetadeCreditoL,BitcoinA,BitcoinL,PuA,PuL,DiferenciadePrecio);
								break;
						}

			}while(opcion!=6);
	return EXIT_SUCCESS;
}
