#include "tanque.h"
#include"freeglut.h"
void tanque::Inicializa(Vector2D posicion, Vector2D velocidad, Vector2D aceleracion, float salud, float daño_disparo, float municion, float velocidad_proyectil, float cadencia, float rango, float num_proyectiles, float vel) {
	this->posicion.x = posicion.x;
	this->posicion.y = posicion.y;
	this->velocidad.x = velocidad.x;
	this->velocidad.y = velocidad.y;
	this->aceleracion.x = aceleracion.x;
	this->aceleracion.y = aceleracion.y;
	this->salud = salud;
	this->daño_disparo = daño_disparo;
	this->municion = municion;
	this->velocidad_proyectil = velocidad_proyectil;
	this->cadencia = cadencia;
	this->rango = rango;
	this->num_proyectiles = num_proyectiles;
	this->vel = vel;
}
tanque::tanque() {
	Inicializa(posicion, velocidad, aceleracion, salud, daño_disparo, municion, velocidad_proyectil, cadencia, rango, num_proyectiles, vel);
}
void Recarga() {
}
void Muerte() {

}
void tanque::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(1);
	glPopMatrix();
}
void tanque::Mueve(float t) {

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	//NO es la forma adecuada de resolverlo
	if (posicion.x > 10.0f)posicion.x = 10.0f;
	if (posicion.x < -10.0f)posicion.x = -10.0f;
}
void tanque::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

