

#include "utn.h"
#include <string.h>



int Get_IntRange(char *MSJ, char *ERROR_MSJ,int MIN,int MAX){

	int rtn= Get_Int(MSJ, ERROR_MSJ);

	while(rtn<MIN || rtn >MAX ){
		printf("error, fuera de rango -> [MIN]=%d [MAX]=%d.\n",MIN,MAX);
		rtn=Get_Int(MSJ,ERROR_MSJ);
	}

	return rtn;
}

int Get_Int(char *MSJ, char *ERROR_MSJ){

	char buffer[TAM_BUFFER];
	int rtn;

	printf("%s",MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberInt(buffer)==0){
		printf("%s",ERROR_MSJ);
		fflush(stdin);
		gets(buffer);

	}
	rtn=atoi(buffer);
	return rtn;
}

int Validate_OnlyNumberInt(char *pData){

	int rtn=1;

	if(strlen(pData)>0){
		for(int i=0;i<strlen(pData); i++){
			if(isdigit(pData[i])==0){
				if(i==0){
					if(pData[0]!='-'){
						rtn=0;
						break;
					}
				}else{
					rtn=0;
					break;
				}
			}
		}
	}else{
		rtn=0;
	}

	return rtn;
}

void Get_String(char *MSJ,char *ERROR_MSJ, char *pString, int TAM){
	char buffer[TAM_BUFFER];

	printf("%s",MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)>TAM|| strlen(buffer)==0){
		printf("error.fuera de rango->CARACTERES[MIN]=1%d\n",TAM);
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString,buffer);
}



float Get_Float(char *MSJ,char *ERROR_MSJ){
	char buffer[TAM_BUFFER];
	float rtn;

	printf("%s",MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberFloat(buffer)==0){
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);

	}

	rtn=atof(buffer);
	return rtn;
}

int Validate_OnlyNumberFloat(char *pData)
{
	int countSigno=0;
	int rtn=1;

	if(strlen(pData)>0){
		for(int i=0;i<strlen(pData);i++){
			if(pData[i]=='.'|| pData[i]==','){
				countSigno++;
			}else{
				if(isdigit(pData[i])==0){
					if(i==0){
						if(pData[0]!='-'){
							rtn=0;
							break;
						}
					}else{
						rtn=0;
						break;
					}
				}
			}
		}
		if(countSigno>1){
			rtn=0;
		}
	}else{
		rtn=0;
	}

	return rtn;
}


