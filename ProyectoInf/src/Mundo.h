#include "tanque.h"

class Mundo
{
private:
	tanque tank;

public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char);


	float x_ojo;
	float y_ojo;
	float z_ojo;
};
