#include <stdio.h>
#include <string.h>
typedef struct{
char nombre[30];
int puntuacion;
int libre;
} Jugador;

typedef struct{
  Jugador lista[100];
  int num;
} ListaJugadores;


Jugador construyejugador(char nom[30], int punt, int libre){
Jugador pepe;
strcpy(pepe.nombre, nom);
pepe.puntuacion = punt;
pepe.libre = libre;
return pepe;
}


ListaJugadores iniciartabla(){
Jugador vacio = construyejugador("", 0, 1);
ListaJugadores milista;
for(int i = 0; i<100; i++){
milista.lista[i] = vacio;
}
return milista;
}

int metejugador(Jugador jugador, ListaJugadores *milista){
int encontrado = 0;
int posicion;
for(int i = 0; i<milista->num && encontrado == 0;i++){
if(milista->lista[i].libre == 1){
  encontrado = 1;
}
posicion = i;
}
if(encontrado == 0)
  return -1;
milista->lista[posicion] = jugador;
return posicion;
}

void muestralista(ListaJugadores *milista){
  for(int i=0;milista->lista[i].libre == 0; i++){
    printf("Nombre: %s\n", milista->lista[i].nombre);
    printf("Puntuación: %d\n", milista->lista[i].puntuacion);
    printf("Posicion: %d\n\n\n", i);
  }
}
void construyecadena(ListaJugadores *milista, int puntuacionminima, char cadena[100]){
char micadena[100];
for(int i=0; milista->lista[i].libre == 0; i++){
if(milista->lista[i].puntuacion>=puntuacionminima)
  sprintf(cadena, "%s %s,", cadena, milista->lista[i].nombre);
}
cadena[strlen(cadena)-1]='\0';
}

int main(){
ListaJugadores milista =  iniciartabla();
Jugador pepe = construyejugador("pepe", 3200, 0);
metejugador(pepe, &milista);
Jugador daniel = construyejugador("daniel", 2500, 0);
metejugador(daniel, &milista);
muestralista(&milista);
char cadenanombres[100];
construyecadena(&milista, 1000, cadenanombres);
printf("Cadena de nombres: %s", cadenanombres);
}
