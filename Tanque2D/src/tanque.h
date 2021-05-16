#pragma once
#include "Vector2D.h"
#include "Proyectil.h"

class tanque {
protected:
	float salud;
	float daño_disparo;
	float municion;
	float velocidad_proyectil;
	float cadencia;
	float rango;
	float num_proyectiles;
	float vel;
	Proyectil proyectil;
	Vector2D apuntado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	tanque();
	void Inicializa(Vector2D posicion, Vector2D velocidad, Vector2D aceleracion, float salud, float daño_disparo, float municion, float velocidad_proyectil, float cadencia, float rango, float num_proyectiles, float vel);
	void Recarga();
	void Muerte();
	void Dibuja();
	void Mueve(float t);
	void Dispara();
	void setVel(float vx, float vy);
	void setApuntado(float x, float y);
	void mueveTecla(unsigned char key);
};

