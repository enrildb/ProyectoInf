#include "freeglut.h"
#include <iostream>
#include "Mundo.h"
#include "ColorRGB.h"

using namespace std;

Mundo mundo;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);	
void onSpecialKeyboardDown(int key, int x, int y);
void getMouse(int x, int y);
void onMouseClicked(int button, int state, int x, int y);


int main(int argc, char* argv[])
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(ANCHO, ALTO);
	glutCreateWindow("MiJuego");
	//glMatrixMode(GL_PROJECTION);
	//gluPerspective(45, (float)ANCHO / ALTO, 0.1, 150);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0f, ANCHO, ALTO, 0.0f, 0.0f, 1.0f);
	//glOrtho(-1.0f, 1.0F, -1.0F, 1.0f, 0.0f, 1.0f);
	//glOrtho(-1, ANCHO/ESCALA-1, 1-ALTO/ESCALA, 1, 0.0f, 1.0f);
	glOrtho(-ANCHO / (2*ESCALA), ANCHO / (2*ESCALA), - ALTO / (2*ESCALA), ALTO / (2*ESCALA), 0.0f, 1.0f);




	ColorRGB color = ColorRGB(233, 208, 154);
	glClearColor(color.r/255.0f, color.g/255.0f, color.b/255.0f,0.0f);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);
	glutPassiveMotionFunc(getMouse);
	glutMouseFunc(onMouseClicked);

	mundo.inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	mundo.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
	mundo.mueve();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaEspecial(key);
}

void getMouse(int x, int y) {
	//cout << x << "  " << y << endl;
	mundo.setRaton(x,y);
}

void onMouseClicked(int button, int state, int x, int y) {
	if(state == GLUT_DOWN)
	mundo.tecla(button);
}