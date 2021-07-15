#include<stdio.h>
#include<graphics.h>
#include<time.h>
int m=1024;  //243, 324, 486, 405
void iteracion(int x, int y, int z){
	int k=z/3,i,j;
	setcolor(0);
	rectangle(x+k,y+2*k,x+2*k,y+k);
	floodfill(x+z/2,y+z/2,BLACK);
  if(k%3==0){
	for(i = x; i < x+3*k; i+=k){
		for(j = y; j < y+3*k; j+=k){		  
		  if(i==(m/3) && j==m/3){
		}else
		  	iteracion(i,j,k);
		}
	}
  }
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
setbkcolor(WHITE);
iteracion(0,0,m);
getch();
closegraph();
return 0;
}
