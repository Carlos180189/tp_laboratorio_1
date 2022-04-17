

#ifndef UTN_H_
#define UTN_H_


int utn_getNumero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

void Calcularcostos(float kilometros,float PrecioVueloAerolineas,float PrecioVueloLatam, float*pTarjetadeDebitoA,float*pTarjetadeDebitoL,float*ptarjetadeCreditoA,float*ptarjetadeCreditoL,float*pBitcoinA,float*pBitcoinL,float*pPuA,float*pPuL,float*pDiferenciadePrecio);

void MostrarRdos(float kilometros, float PrecioVueloAerolineas,float PrecioVueloLatam, float TarjetadeDebitoA,float TarjetadeDebitoL,float tarjetadeCreditoA,float tarjetadeCreditoL,float BitcoinA,float BitcoinL,float PuA,float PuL,float DiferenciadePrecio);

#endif /* UTN_H_ */
