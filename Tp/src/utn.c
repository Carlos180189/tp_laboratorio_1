
#include <stdio.h>
#include <stdlib.h>



int utn_getNumero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno=-1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{	do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt>=minimo && bufferInt <= maximo)
			{
				*pResultado= bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);

	}
	return retorno;
}

int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{

	int retorno=-1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{	do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);
			if(bufferFloat>=minimo && bufferFloat <= maximo)
			{
				*pResultado= bufferFloat;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);

	}
	return retorno;

}

void Calcularcostos(float kilometros,float PrecioVueloAerolineas,float PrecioVueloLatam, float*pTarjetadeDebitoA,float*pTarjetadeDebitoL,float*ptarjetadeCreditoA,float*ptarjetadeCreditoL,float*pBitcoinA,float*pBitcoinL,float*pPuA,float*pPuL,float*pDiferenciadePrecio)
{

	 *pTarjetadeDebitoA=PrecioVueloAerolineas*0.9;
	 *pTarjetadeDebitoL=PrecioVueloLatam*0.9;
	 *ptarjetadeCreditoA=PrecioVueloAerolineas*1.25;
	 *ptarjetadeCreditoL=PrecioVueloLatam*1.25;
	 *pBitcoinA=PrecioVueloAerolineas/4606954.55;
	 *pBitcoinL=PrecioVueloLatam/4606954.55;
	 *pPuA=PrecioVueloAerolineas/kilometros;
	 *pPuL=PrecioVueloLatam/kilometros;
	 *pDiferenciadePrecio=PrecioVueloAerolineas-PrecioVueloLatam;
	 if(*pDiferenciadePrecio<0)
	 {
		 *pDiferenciadePrecio=*pDiferenciadePrecio*(-1);
	 }

	 printf("calculosok!\n\n");
}

void MostrarRdos(float kilometros, float PrecioVueloAerolineas,float PrecioVueloLatam, float TarjetadeDebitoA,float TarjetadeDebitoL,float tarjetadeCreditoA,float tarjetadeCreditoL,float BitcoinA,float BitcoinL,float PuA,float PuL,float DiferenciadePrecio)
{

	printf("KMs Ingresados: %2.f km",kilometros);
	printf("\n\nPrecio Aerolineas: $%2.f \na) Precio con tarjeta de débito: $%2.f\nb) Precio con tarjeta de crédito: $%2.f\nc) Precio pagando con bitcoin: %f BTC\nd)Mostrar precio unitario: $%2.f",PrecioVueloAerolineas,TarjetadeDebitoA,tarjetadeCreditoA,BitcoinA,PuA);
	printf("\n\nPrecio Latam: $%2.f \na) Precio con tarjeta de débito: $%2.f\nb) Precio con tarjeta de crédito: $%2.f\nc) Precio pagando con bitcoin: %f BTC\nd)Mostrar precio unitario: $%2.f\n\nLa diferencia de precio es: $%2.f\n",PrecioVueloLatam,TarjetadeDebitoL,tarjetadeCreditoL,BitcoinL,PuL,DiferenciadePrecio);

}

