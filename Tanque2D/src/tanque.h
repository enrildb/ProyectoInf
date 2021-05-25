#pragma once
#include "Vector2D.h"
#include "Proyectil.h"
#include "ListaProyectiles.h"
#include "ColorRGB.h"

class tanque {
protected:
	//float salud;
	//float daño_disparo;
	//float velocidad_proyectil;
	//float cadencia;
	//float rango;
	//float num_proyectiles;
	float municion;
	float vel;
	ColorRGB color;

	ListaProyectiles proyectiles;
	Vector2D apuntado;
	Vector2D posicion;
	Vector2D velocidad;
	//Vector2D aceleracion;

public:
	tanque();
	void Inicializa();
	void Inicializa(Vector2D posicion, Vector2D velocidad, Vector2D aceleracion, float salud, float daño_disparo, float municion, float velocidad_proyectil, float cadencia, float rango, float num_proyectiles, float vel);
	//void Recarga();
	//void Muerte();
	void Dibuja();
	void Mueve(float t);
	void Dispara();
	void setVel(float vx, float vy);
	void setApuntado(float x, float y);
	void setApuntado(Vector2D);
	Vector2D getPos();
};

