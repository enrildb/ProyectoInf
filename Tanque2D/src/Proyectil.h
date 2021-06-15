#pragma once
#include "Vector2D.h"

class Proyectil
{
	friend class Interaccion;
private:
	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	//bool disparado = false;//para saber si se ha disparado o no
	//inecesario si se crea en en momento que se dispara

public:
	Proyectil();
	Proyectil(Vector2D,Vector2D);
	virtual ~Proyectil();
	void dibuja();
	void mueve(float);
	void setPos(Vector2D);
	//void setVel(Vector2D apuntando);
	//bool getDisparado();//tambi�n innecesario
};

