#include "tanque.h"
#include "Vector2D.h"
#include "tanqueJugador.h"
#include "tanqueEnemigo.h"

class Mundo
{
private:
	Vector2D raton;
	tanqueJugador tankJ;
	tanqueEnemigo tankE;

public: 
	Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char);
	void setRaton(int x, int y);
};
