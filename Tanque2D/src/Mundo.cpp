#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{        
	tank.Dibuja();
}

void Mundo::mueve()
{

	tank.Mueve(0.025f);
	tank.setApuntado(raton.x, raton.y);
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=20;

	tank.Inicializa(0,0,0,0,0,0,0,0,0,0,0);
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
		tank.Dispara();
		break;
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	tank.mueveTecla(key); //Alternativa para mover el tanque
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
	void Mundo::setRaton(int x, int y) {
		raton.x = x;
		raton.y = y;
    }

