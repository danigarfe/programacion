#include <string.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
int partida(){
	int resultado;
	int ganados = 0;
	int perdidos = 0;
	double apostado;
	double maximobalance = 0;
	int palmadas=0;
	double balance=500; //aquí pones la pasta con la que vas al casino
	while (balance >=0)
	{
			resultado = rand() % 38;
			apostado = pow(2, palmadas);
			if(resultado >=1 && resultado <= 12)
			{
					printf("Has ganado bro\n");
					ganados=ganados + 1;
					palmadas = 0;
					balance = (balance-apostado) + 3*apostado;
			}
			if(resultado == 0 || (resultado>12 && resultado <= 36)){

					printf("Has perdido bro\n");
					perdidos=perdidos + 1;
					palmadas=palmadas + 1;
					balance = balance - apostado;
			}
			printf("Numero de ganadas: %d\n", ganados);
			printf("Numero de perdidas: %d\n", perdidos);
			printf("Tienes: %f euros\n", balance);
			printf("\n\n\n");
			if(balance>maximobalance)
				maximobalance = balance;
	}
	printf("Te has arruinado bro\n");
	return maximobalance;
}
float media(int vector[], int longitud){
float suma=0;
for(int i = 0;i<longitud;i++){
suma = suma + (float)vector[i];
}
return suma/longitud;
}

int main()
{
					int longitud = 5;
          int vector[100];
					for(int i = 0; i<100; i++){
						vector[i]=partida();
					}
					printf("Dinero máximo conseguido de media: %f", media(vector, longitud));
					return 0;
}
