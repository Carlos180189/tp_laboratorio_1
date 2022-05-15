

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>

#define TAM_BUFFER 10

int Get_IntRange(char *MSJ, char *ERROR_MSJ,int MIN,int MAX);
int Get_Int(char *MSJ, char *ERROR_MSJ);
int Validate_OnlyNumberInt(char *pData);


void Get_String(char *MSJ,char *ERROR_MSJ, char *pString, int TAM);

float Get_Float(char *MSJ,char *ERROR_MSJ);
int Validate_OnlyNumberFloat(char *pData);

#endif /* UTN_H_ */
