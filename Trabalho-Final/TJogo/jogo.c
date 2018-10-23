#include <stdlib.h>
#include<stdio.h>
int matriz [12][13];
int inicioLinha;
int inicioColuna;


void verLabririnto(){
	FILE* f = fopen("mapa.txt","r+");

	for (int i = 0; i <12; ++i)
	{
	  fscanf(f,  "%s", &matriz[i]);
	}
	fclose(f);
}

void labririnto(){
	for (int i = 0; i < 12; ++i)
	{
		printf("%s\n",matriz[i]);
	}
}

void inicioLabririnto(){
	for (int i = 0; i <12; ++i)
	{
		if (matriz[i][0] == '.')
		{
		 inicioLinha = i;
		 inicioColuna = 0;
		}
	}
}

void percorreLabririnto(){
	if (matriz[inicioLinha][inicioColuna+1]=='.'){
		matriz[inicioLinha][inicioColuna+1]='X';
		inicioColuna++;
	}else if (matriz[inicioLinha-1][inicioColuna]=='.'){
		matriz[inicioLinha-1][inicioColuna]='x';
		inicioLinha--;
	}else if (matriz[inicioLinha+1][inicioColuna]=='.'){
		matriz[inicioLinha+1][inicioColuna]='X';
		inicioLinha++;
	}else if (matriz[inicioLinha][inicioColuna-1]=='.'){
		matriz[inicioLinha][inicioColuna-1]='X';
		inicioColuna--;
	}
}

int main()
{
	verLabririnto();
	inicioLabririnto();
	
	while(1){
		labririnto();	
		percorreLabririnto();
		printf("%i %i\n",inicioLinha, inicioColuna);
	system("pause");
	}
	return 0;
}