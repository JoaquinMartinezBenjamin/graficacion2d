#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#define Pi 3.14159
#include <math.h>

GLfloat xi=0.0;
GLfloat yi=0.0;
GLfloat x=0.0;
GLfloat y=0.0;
GLfloat inc=1.0;
GLfloat ang=0.0;
GLfloat tamanio_lado=3.0;
int lados=3;
GLfloat c=1.0;

void init(void){

       glClearColor(1.0,1.0,1.0,0.0);

}

void ArrowKey(int key,int x,int y){
	switch(key){
	case GLUT_KEY_RIGHT:
		if(xi<10)
			xi+=0.5;
		break;
	case GLUT_KEY_LEFT:
		if(xi>-10)
			xi-=0.5;
		break;
	case GLUT_KEY_UP:
		if(yi<10)
			yi+=0.5;
		break;
	case GLUT_KEY_DOWN:
		if(yi>-10)
			yi-=0.5;
		break;
	case GLUT_KEY_F1:
		ang+=20;
	    break;
	case GLUT_KEY_F2:
		inc+=0.5;
		break;
	case GLUT_KEY_F3:
		inc-=0.5;
		break;
	case GLUT_KEY_F4:
		lados=4;
		break;
	case GLUT_KEY_F5:
		lados=5;
		break;
	case GLUT_KEY_F6:
		lados=6;
		break;
	case GLUT_KEY_F7:
		lados=7;
		break;
	case GLUT_KEY_F8:
		lados=8;
		break;
	case GLUT_KEY_F9:
		lados=9;
		break;
	case GLUT_KEY_F10:
		lados=10;
		break;
	case GLUT_KEY_F11:
		lados=11;
		break;
	case GLUT_KEY_F12:
		lados=12;
		break;
	case GLUT_KEY_INSERT:
		lados=3;
		break;
	}
	glutPostRedisplay();
}

void poligono(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0,0.0,0.5,0.0,0.0,0.0,0.0,1.0,0.0);
	glPushMatrix();

	glTranslatef(xi,yi,0.0);
	glRotatef(ang,0.0f,0.0f,1.0f);
	glScalef(inc,inc,inc);
	int angulo_incrementar_en=360/lados;
	int angulo=45;
	glBegin(GL_POLYGON);

	for(int q=0;q<lados;q++){
		x=(tamanio_lado*cos(angulo*(Pi/180)));
		y=(tamanio_lado*sin(angulo*(Pi/180)));
		angulo=angulo+angulo_incrementar_en;
        glColor3f(q*1.1,q*0.5,q*0.1);
		glVertex3f(x,y,0.0f);
	}
	glEnd();
}

void display(void){
	poligono();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0,10.0,-10.0,10.0,0.1,20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key,int x,int y){
	switch(key){
	case 27:
		exit(0);
		break;
	}
}

int main (int argc, char **argv) {
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,500);
	glutCreateWindow("POLIGONO");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();

	return 0;
}


