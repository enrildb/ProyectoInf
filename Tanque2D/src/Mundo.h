#include "tanque.h"
#include "Vector2D.h"


class Mundo
{
private:
	Vector2D raton;
	tanque tank;

public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char);
	void setRaton(int x, int y);


	float x_ojo;
	float y_ojo;
	float z_ojo;
};
