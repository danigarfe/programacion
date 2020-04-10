#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void crearvector(int vector[100]){
srand(time(NULL)); //para crear una semilla pseudoaleatoria, en func. de la fecha y hora
for(int i = 0; i<100; i++){
vector[i] = rand() % 100;
}
}
void mostrarvector(int vector[100]){
for(int i = 0; i<100; i++){
printf("Posicion: %d       Valor: %d\n", i, vector[i]);
}
printf("\n\n");
}
void ordenarvector(int vector[100]){
int vectorordenado[100];
int min=200;
int posicionmin;
for(int i=0; i<100;i++)
{
  for(int y=0; y<100;y++)
  {
    if(vector[y]<min){
      min = vector[y];
      posicionmin = y;
    }
  }
      vectorordenado[i] = min;
      vector[posicionmin]=200;
      min = 200;
}
for(int i=0;i<100;i++){ //copia el vector ordenado al vector normal
vector[i]=vectorordenado[i];
}
}

int main(){
  int vector[100];
  int vector2[100];
  crearvector(vector);
  mostrarvector(vector);
  ordenarvector(vector);
  mostrarvector(vector);                       /* Free y array */
}
