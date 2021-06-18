#include "Mundo.h"
#include "freeglut.h"
#include "Interaccion.h"
#include <math.h>

Mundo::Mundo(){}

void Mundo::dibuja()
{        
	//gluLookAt(1.0, 0.0, 0.0,
	//	0.0, 0.0, 0.0,
	//	0.0, 1.0, 0.0);


	tankJ.Dibuja();
	tankE.Dibuja();
	caja.Dibuja();
	cajas.Dibuja();
}

void Mundo::mueve()
{
	tankJ.Mueve(0.025f);
	tankJ.setApuntado(raton.x, raton.y);
	tankE.Mueve(0.025f);
	tankE.setApuntado(tankJ.getPos());
    Interaccion::rebote(tankJ, caja);
	for (int i = 0; i < 4; i++) {
		Interaccion::rebote(tankJ, *cajas[i]);
	}

}

void Mundo::inicializa()
{
	tankJ.Inicializa();
	tankE.Inicializa();
	caja.Inicializa(-0.04f, 0.2f, 0.04f,-0.2f);
	cajas.Inicializa();
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case GLUT_LEFT_BUTTON:
		tankJ.Dispara();
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	tankJ.mueveTecla(key); //Alternativa para mover el tanque
	//switch (key)
	//{
	//case GLUT_KEY_LEFT:
	//	tank.setVel(-5.0f, 0.0f);
	//	break;
	//case GLUT_KEY_RIGHT:
	//	tank.setVel(5.0f, 0.0f);
	//	break;
	//case GLUT_KEY_UP:
	//	tank.setVel(0.0f, 5.0f);
	//	break;
	//case GLUT_KEY_DOWN:
	//	tank.setVel(0.0f, -5.0f);
	//	break;
	//case GLUT_KEY_F1:
	//	tank.setVel(0.0f, 0.0f);
	//	break;
 //   }


}
	//void Mundo::setRaton(int x, int y) {
	//	raton.x = x;
	//	raton.y = y;
 //   }

//void Mundo::setRaton(int x, int y) {
//	raton.x = (x / 400.0f - 1);
//	raton.y = (400 - y) / 400.0f;
//}
//void Mundo::setRaton(int x, int y) {
//	raton.x = (x / ESCALA - 1);
//	raton.y = (ESCALA - y) / ESCALA;
//
//}
void Mundo::setRaton(int x, int y) {
	raton.x = (x - ANCHO/2)/ESCALA;
	raton.y = (ALTO/2 - y) / ESCALA;

}




