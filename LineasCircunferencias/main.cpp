#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

using namespace std;
int tam =60;
char matriz[60][60];
int i,j,x,y,radio,contador;

void inicia()
{
     for (int i=0;i<=tam;i++)
     {
         for (int j=0; j<=tam;j++)
         {
             matriz[i][j]='.';
         }
     }

}
void pinta()
{
   for (int i=0;i<=tam;i++)
     {
         for (int j=0; j<=tam;j++)
         {
             cout << matriz[i][j];
              cout << " ";
         }
         cout  <<endl;
     }
}
void insertaPunto(int x, int y,int x1, int y1)
{
     x = x+x1;
     y = y+y1;
    if((x>=0&&y>=0)&&(x<tam&&y<tam)){ matriz[x][y]='*';}
}
void insertaPuntoL(int x, int y)
{
     x = x;
     y = y;
    if((x>=0&&y>=0)&&(x<tam&&y<tam)){ matriz[x][y]='*';}
}
void circunferencia(int radio, int x1, int y1)
{

int radioCuadrado = radio * radio;
int e,es,ed,contador;
int x=radio; int y=0;
//Obtener total de coordenadas
contador=0;
while (y<x){
contador++;
e= (x * x)+ (y * y) - radioCuadrado;
es = e + (2 * y + 1);
ed = es - (2* x + 1);
if (abs (es)> abs (ed))
    {x= x-1; y = y + 1;
    }
else
    { y = y + 1; }
}
//___________________________

x= radio; y=0;
int coordenadasx[contador];
int coordenadasy[contador];
//_____________________________
// ya que se cuantas coordenadas capturo los valores
contador=0;
while (y<=x){

coordenadasx[contador]=x;
coordenadasy[contador]=y;

e= (x * x)+ (y * y) - radioCuadrado;
es = e + (2 * y) + 1;
ed = es - (2* x) + 1;

if (abs (es)> abs (ed))
    {x= x-1; y = y + 1;}

else { y = y + 1; }

    contador++;
}
//:::::::::::::::::::::
int coordenadasxy[2][contador];
for (i=0; i<=contador;i++){
    for(j=0;j<=contador; j++){
        if(i==0){coordenadasxy[i][j]=coordenadasx[j];}
        if(i==1){coordenadasxy[i][j]=coordenadasy[j];}
    }
    }

      for(i=0;i<contador;i++){
x=coordenadasxy[0][i];
y=coordenadasxy[1][i];
insertaPunto(x,y,x1,y1);
insertaPunto(y,x,x1,y1);
insertaPunto((-1 * x),y,x1,y1);
insertaPunto((-1 * y),x,x1,y1);
insertaPunto(x,(-1 * y),x1,y1);
insertaPunto(y,(-1 * x),x1,y1);
insertaPunto((-1 * x),(-1 * y),x1,y1);
insertaPunto((-1 * y),(-1 * x),x1,y1);
}
}
void linea(int xi, int yi, int xf,int yf)
{
     int dx = xf - xi;
     int dy = yf - yi;
     int cont = 0;
     int x_i = 1;
     int y_i = 1;

     if (dx < 0) x_i = -1;
     if (dy < 0) y_i = -1;



     insertaPuntoL(xi,yi);
     if (abs(dx) >= abs(dy)){

         int pk = (abs(dy) * 2) - abs(dx);

         while (cont < abs(dx)){

             if (pk < 0){
                 xi = xi + x_i;

                 pk = pk + (abs(dy) * 2);
             }else{
                 xi = xi + x_i;
                 yi = yi + y_i;

                 pk = pk + (abs(dy) * 2) - (abs(dx) * 2);
             }

             insertaPuntoL(xi,yi);
             cont++;
         }
     }else{
         int pk = (abs(dx) * 2) - abs(dy);

         while (cont < abs(dy)){

             if (pk < 0){

                 yi = yi + y_i;
                 pk = pk + (abs(dx) * 2);
             }else{
                 xi = xi + x_i;
                 yi = yi + y_i;

                 pk = pk + (abs(dx) * 2) - (abs(dy) * 2);
             }

             insertaPuntoL(xi,yi);
             cont++;
         }
     }
}
int main()
{
   inicia(); //lleno la matriz
    //int x1,y1,x2,y2,radio;
    /*cout << "ingresa el radio del circulo" << endl;
    cin >> radio;
    cout << "ingresa el valor de x del centro" << endl;
    cin >> x1;
    cout << "ingresa el valor de y del centro" << endl;
    cin >> y1;*/

    //circunferencia (15,-1,-1);
    circunferencia (20,30,30);
         linea (30,30,30,20);
         linea (30,30,25,30);
         linea (30,30,15,40);
     //linea (60,60,30,30);

     pinta();
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


    getch();
    return 0;
}
