#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

using namespace std;
int tam =60; int origen= 30;
char matriz[60][60];

void inicia()
{
     for (int i=0;i<=tam;i++)
     {
         for (int j=0; j<=tam;j++)
         {
             matriz[i][j]='.';
         }
     }
     matriz[origen][origen]='+';
}

void pinta()
{
   for (int i=0;i<=tam;i++)
     {
         for (int j=0; j<=tam;j++)
         {
             cout << matriz[i][j];
         }
         cout  <<endl;
     }
}

void insertaPunto(int x, int y)
{
     x = x + origen;
     y = y + origen;
     matriz[x][y]='*';
}

void bres(int xi, int xf,int yi, int yf)
{
     int dx = xf - xi;
     int dy = yf - yi;
     int cont = 0;
     int x_i = 1;
     int y_i = 1;

     if (dx < 0) x_i = -1;
     if (dy < 0) y_i = -1;

     //cout << dx << " " << dy << endl;

     insertaPunto(xi,yi);
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

             insertaPunto(xi,yi);
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

             insertaPunto(xi,yi);
             cont++;
         }
     }
}
int main()
{
    inicia();
    int x1,y1,x2,y2;
    cout << "ingresa el valor de x1" << endl;
    cin >> x1;
    cout << "ingresa el valor de y1" << endl;
    cin >> y1;
    cout << "ingresa el valor de x2" << endl;
    cin >> x2;
    cout << "ingresa el valor de y2" << endl;
    cin >> y2;
    bres (x1, x2, y1,y2);
    pinta();


    getch();
    return 0;
}
