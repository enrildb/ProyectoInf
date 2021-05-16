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

	proyectil.dibuja();

	glBegin(GL_QUADS);              
      glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex2f(posicion.x - 0.05f, posicion.y - 0.05f);   
	  glVertex2f(posicion.x + 0.05f, posicion.y - 0.05f);
	  glVertex2f(posicion.x + 0.05f, posicion.y + 0.05f);
	  glVertex2f(posicion.x - 0.05f, posicion.y + 0.05f);
	glEnd();

	//Dibuja el cañon, podríamos hacer un clase para el cañon
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(posicion.x, posicion.y);
	glVertex2d(apuntado.x+posicion.x, apuntado.y+posicion.y);
	glEnd();


}
void tanque::Mueve(float t) {


	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	//NO es la forma adecuada de resolverlo
	if (posicion.x > 1.0f)posicion.x = 1.0f;
	if (posicion.x < -1.0f)posicion.x = -1.0f;
	if (proyectil.getDisparado()) proyectil.mueve(t);
	else proyectil.setPos(posicion);
}
void tanque::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void tanque::setApuntado(float x, float y) {
	apuntado.x = (x-400)-400*posicion.x;  //Generalizar para distintas dimensiones
	apuntado.y = (375-y)-400*posicion.y;
	apuntado = apuntado.unitario()*0.2;//0.2 es el tamaño del cañon
}

//alternativa para mover el tanque
void tanque::mueveTecla(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		posicion.x = posicion.x - 0.01;
		break;
	case GLUT_KEY_RIGHT:
		posicion.x = posicion.x + 0.01;
		break;
	case GLUT_KEY_UP:
		posicion.y = posicion.y + 0.01;
		break;
	case GLUT_KEY_DOWN:
		posicion.y = posicion.y - 0.01;
		break;
	}
}

void tanque::Dispara() {
	proyectil.setVel(apuntado);
}
