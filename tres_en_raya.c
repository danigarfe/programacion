#include <stdio.h>
#include <string.h>
#include <stdlib.h>

                typedef struct{
                  int tipo; //0 es redonda, 1 es cruz
                  int ocupado; //0 si no hay ficha, 1 si hay
                } Ficha;

                typedef struct{
                Ficha casillas[3][3];
                } Tablero;

                              int ponerficha(Tablero *mitablero, int tipo, int fila, int columna){
                              Ficha nuevaficha;
                              nuevaficha.tipo = tipo;
                              nuevaficha.ocupado = 1;
                              if(mitablero->casillas[fila][columna].ocupado == 0){
                                mitablero->casillas[fila][columna] = nuevaficha;
                                return 0;
                              }
                              else
                                return 1;
                              }

                              void mostrartablerografico(Tablero mitablero){
                              for(int fila=0;fila<3;fila++){
                                for(int columna = 0; columna<3; columna++){
                                  if(mitablero.casillas[fila][columna].tipo==0){
                                    printf("O      ");
                                  }
                                  else if(mitablero.casillas[fila][columna].tipo==1){
                                    printf("X      ");
                                  }
                                  else{
                                          printf("       ");
                                  }
                                }
                                printf("\n\n\n");
                              }
}

                              void mostrartablerotexto(Tablero mitablero){
                                for(int fila=0;fila<3;fila++){
                                  for(int columna = 0; columna<3; columna++){
                                    printf("Fila: %d  Columna: %d   Valor: %d Ocupado: %d\n", fila, columna, mitablero.casillas[fila][columna].tipo, mitablero.casillas[fila][columna].ocupado);
                                  }
                                }
}

                              int comprueba3enraya(Tablero mitablero){
                                int acabado = 0;
                                for(int i=0; i<3 && acabado==0;i++){ //comprueba rayas verticales
                                  if((mitablero.casillas[0][i].tipo == mitablero.casillas[1][i].tipo) && (mitablero.casillas[1][i].tipo == mitablero.casillas[2][i].tipo) && (mitablero.casillas[0][i].tipo==0 || mitablero.casillas[0][i].tipo==1) ){
                                    acabado = 1;
                                    printf("Acabado por l%cnea vertical\n", 161);
                                  }
                                }

                                for(int i=0; i<3 && acabado==0;i++){ //comprueba rayas horizontales
                                  if((mitablero.casillas[i][0].tipo == mitablero.casillas[i][1].tipo) && (mitablero.casillas[i][1].tipo == mitablero.casillas[i][2].tipo) && (mitablero.casillas[i][0].tipo==0 || mitablero.casillas[i][0].tipo==1)){
                                    acabado = 1;
                                    printf("Acabado por l%cnea horizontal\n", 161);
                                  }
                                }
                                  //comprueba raya diagonal de izquierda arriba a derecha abajo:
                                if((mitablero.casillas[0][0].tipo == mitablero.casillas[1][1].tipo) && (mitablero.casillas[1][1].tipo == mitablero.casillas[2][2].tipo) && (mitablero.casillas[0][0].tipo==0 || mitablero.casillas[0][0].tipo==1) && acabado==0){
                                    acabado = 1;
                                    printf("Acabado por diagonal.\n");
                                  }

                                  if((mitablero.casillas[2][0].tipo == mitablero.casillas[1][1].tipo) && (mitablero.casillas[1][1].tipo == mitablero.casillas[0][2].tipo) && (mitablero.casillas[1][1].tipo==0 || mitablero.casillas[1][1].tipo==1) && acabado==0){
                                      acabado = 1;
                                      printf("Acabado por diagonal.\n");
                                    }
                                return acabado;
                          }

                              Tablero iniciartablero(){
                                Tablero nuevotablero;
                                for(int i = 0; i<3; i++){
                                  for(int j = 0; j<3; j++){
                                    nuevotablero.casillas[i][j].ocupado = 0;
                                    nuevotablero.casillas[i][j].tipo = 500;
                                  }
                                }
                                return nuevotablero;
                              }

int main(){
Tablero mitablero=iniciartablero();
int tipo=0;
int fila;
int res;
int acabado = 0;
int columna;
char tipochar[8];
strcpy(tipochar, "redondas");
while(acabado == 0){
  printf("Turno de las %s.\n", tipochar);
  printf("Introduzca una posici%cn: \n", 162);
  scanf("%d %d", &fila, &columna);
  res = ponerficha(&mitablero, tipo, fila, columna);
  if(res == 0){
    if(tipo==0){
        tipo=1;
        strcpy(tipochar, "cruces");
    }
    else{
        tipo = 0;
        strcpy(tipochar, "redondas");
    }
    system("cls");
    mostrartablerografico(mitablero);
  }
  else if (res==1){
    printf("Casilla ocupada.\n");
  }
  acabado = comprueba3enraya(mitablero);
}
printf("Partida finalizada.\n");
return 0;
}
