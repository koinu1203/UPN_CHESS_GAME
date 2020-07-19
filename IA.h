#pragma once
#include "Chess.h"
#include "TabP.h"

#define PEON 1
#define TORRE 2
#define CABALLO 3
#define ALFIL 4 
#define REINA 5
#define REY 6 

struct mov { 
	pos movimiento; 
	mov* sgte; 
};

typedef struct mov* pilaMov;

struct movpiezas { //<-
	pos act; //<-posicion actual
	pilaMov m; //<-es un puntero que determinara los movimientos posibles de la pieza, si el puntero esta en null entonces no existen movimientos pasa esa pieza
	int pieza;//<-
};

int tabV[8][8]; //tablero de valor contendra los valores de las fichas en tiempo real 

/*
	-BLANCO / +NEGRO
	PEON = 10
	CABALLO = 30
	ALFIL = 30
	TORRE = 50
	REINA = 90
	REY = 900
*/

void actTabV() {
	//actualizar tablero de valor 
	for (int i = 0; i < 8; i++) {
		for (int s = 0; s < 8; s++) {
			switch (abs(tablero[i][s])) { //valor absoluto de la casilla en el tablero original 
			case 1: case 3: case 4: tabV[i][s] = tablero[i][s] * 10; break; //PEON CABALLO ALFIL 
			case 2: tabV[i][s] = tablero[i][s] * 25; break; //TORRE
			case 5: tabV[i][s] = (tablero[i][s] / 5) * 90; break; // REINA
			case 6: tabV[i][s] = (tablero[i][s] / 6) * 900; break; //REY 
			default: break;
			}
		}
	}
}
/*
	requisitos del algoritmo
	1)	Que te permita escoger un movimiento de todos los permitidos
	2)	Escoger el movimiento que de mayor valor, acá entra en juego
		el tabV o tablero de valor (asegurarse de actualizar el tablero)
	3)	Saber si la jugada escogida a futuro (pensando un turno luego)
		es la mejor
	4)	aplicar una tabla de posicion para definir la mejor posicion para pieza.
		ejemplo PEON:
			[0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0]
			[5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0,  5.0]
			[1.0,  1.0,  2.0,  3.0,  3.0,  2.0,  1.0,  1.0]
			[0.0,  0.0,  0.0,  2.0,  2.0,  0.0,  0.0,  0.0]
			[0.5, -0.5, -1.0,  0.0,  0.0, -1.0, -0.5,  0.5]
			[0.5,  1.0,  1.0, -2.0, -2.0,  1.0,  1.0,  0.5]
			[0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0]
		Segun este mapa las mejores posiciones en que puede estar el peon es en el centro
		para ver las demas posiciones de las piezas https://translate.google.com.pe/translate?hl=es&sl=auto&tl=es&u=https%3A%2F%2Fwww.freecodecamp.org%2Fnews%2Fsimple-chess-ai-step-by-step-1d55a9266977%2F

	SeudoCodigo:
	funcion IA:
		buscar todos los posibles movimientos de todas las posibles fichas
	->	generar las tablas de posicion para el caballo, reina y alfil con respecto al rey enemigo y las demas piezas enemigas (aca podemos usar un algoritmo voraz o algun otro)
		funcion Evaluar movimiento:
			escoger un movimiento entre los posibles
			realizarlo
			ver el mejor movimiento del rival
			realizarlo
			escoger el siguiente mejor movimiento para la IA
			calcular el valor de la jugada con la tabV y la tabla de posicion
			comparar el valor de la jugada con la mejor jugada hasta el momento
			probar siguiente jugada
		retornar movimiento escogido
*/


/*
int tablero[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, }
*/


/*
		agrega un elemento a pila
		el elemento valor es una posicion posible
*/
void addPila(pilaMov& p, pos valor) {

	pilaMov nuevo = new mov;
	nuevo->movimiento = valor;
	nuevo->sgte = p;
	try
	{
		nuevo->sgte = p;
		p = nuevo;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error al grabar en la pila" << std::endl;
		std::cout << "Valor no grabado: " << valor.x << "|" << valor.y << std::endl;
		p = NULL;
		addPila(p, valor);
	}
}

/*
	retorna pos x=-1 & y=-1 si ya no quedan elementos en la pila
	o si existe un error en la pila
*/
pos getPila(pilaMov& p) {
	pos temp;
	temp.x = -1;
	temp.y = -1;
	try {
		if (p != NULL) {
			temp = p->movimiento;
			pilaMov aux = p;
			p = p->sgte;
			delete aux;
		}
		else {
			return temp;
		}
	}
	catch (const std::exception&) {
		std::cout << "Error de pila: pila sin un NULL declarado" << std::endl;
		temp.x = -1;
		temp.y = -1;
		return temp;
	}
}

void aniadirJugada(int x, int y, pilaMov pilamovi) {
	pos posi;
	posi.x = x;
	posi.y = y;
	addPila(pilamovi, posi);
}

void generarListaDeMovimientos(movpiezas lista[], int color) { //color a seleccionar blanco=-1, negro=1
	int cont = 0;
	for (int i = 0; i < LONGITUD; i++) {
		for (int s = 0; s < LONGITUD; s++) {
			if (tablero[i][s] * color > 0) {
				lista[cont].act.x = s; //tablero[y][x];
				lista[cont].act.y = i;
				switch (abs(tablero[i][s])) {
					pilaMov movimiento = new mov;
				case PEON: {
					lista[cont].pieza = PEON;
					if (color == 1) {
						if (tablero[i + 1][s] == 0) {
							aniadirJugada(s, i + 1, movimiento);
						}
						if (i == 1 && (s == 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8)){
							if (tablero[i + 2][s] == 0) {
								aniadirJugada(s, i + 2, movimiento);
							}

						}
						if (tablero[i + 1][s - 1] < 0) {
							aniadirJugada(s - 1, i + 1, movimiento);
						}
						if (tablero[i + 1][s + 1] < 0) {
							aniadirJugada(s+1, i + 1, movimiento);
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case TORRE: { 
					lista[cont].pieza = TORRE;
					for (int x = s - 1; x >= 0; x--) // a la izq.
					{
						if (tablero[i][x] <= 0)
						{
							aniadirJugada(x, i, movimiento);
						}
						else if (tablero[i][x] != 0)
						{
							break;
						}
					}
					for (int y = i - 1; y >= 0; y--) // arriba
					{
						if (tablero[y][s] <= 0)
						{
							aniadirJugada(s, y, movimiento);
						}
						else if (tablero[y][s] != 0)
						{
							break;
						}
					}
					for (int x = s + 1; x <= 7; x++) // a la der.
					{
						if (tablero[i][x] <= 0)
						{
							aniadirJugada(x, i, movimiento);
						}
						else if (tablero[i][x] != 0)
						{
							break;
						}
					}
					for (int y = i + 1; y <= 7; y++) // abajo
					{
						if (tablero[y][s] <= 0)
						{
							aniadirJugada(s, y, movimiento);
						}
						else if (tablero[y][s] != 0)
						{
							break;
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case CABALLO: { //riesgo de causar error, revisar luego...
					lista[cont].pieza = CABALLO;
					//intenté hacer que verifique si la posición que está verificando, es una posición valida dentro del tablero,
					//quizá esto cause error, revisar luego.
					//lo indicaré aquí		       vv 
					if (tablero[i - 2][s - 1] <= 0 && (i - 2 >= 0 && i - 2 < LONGITUD) && (s - 1 >= 0 && s - 1 < LONGITUD)) {
						aniadirJugada(s - 1, i - 2, movimiento);
					}
					if (tablero[i - 2][s + 1] <= 0 && (i - 2 >= 0 && i - 2 < LONGITUD) && (s + 1 >= 0 && s + 1 < LONGITUD)) {
						aniadirJugada(s + 1, i - 2, movimiento);
					}
					if (tablero[i + 2][s - 1] <= 0 && (i + 2 >= 0 && i + 2 < LONGITUD) && (s - 1 >= 0 && s - 1 < LONGITUD)) {
						aniadirJugada(s - 1, i + 2, movimiento);
					}
					if (tablero[i + 2][s + 1] <= 0 && (i + 2 >= 0 && i + 2 < LONGITUD) && (s + 1 >= 0 && s + 1 < LONGITUD)) {
						aniadirJugada(s + 1, i + 2, movimiento);
					}
					///
					if (tablero[i - 1][s - 2] <= 0 && (i - 1 >= 0 && i - 1 < LONGITUD) && (s - 2 >= 0 && s - 2 < LONGITUD)) {
						aniadirJugada(s - 2, i - 1, movimiento);
					}
					if (tablero[i - 1][s + 2] <= 0 && (i - 1 >= 0 && i - 1 < LONGITUD) && (s + 2 >= 0 && s + 2 < LONGITUD)) {
						aniadirJugada(s + 2, i - 1, movimiento);
					}
					if (tablero[i + 1][s - 2] <= 0 && (i + 1 >= 0 && i + 1 < LONGITUD) && (s - 2 >= 0 && s - 2 < LONGITUD)) {
						aniadirJugada(s - 2, i + 1, movimiento);
					}
					if (tablero[i + 1][s + 2] <= 0 && (i + 1 >= 0 && i + 1 < LONGITUD) && (s + 2 >= 0 && s + 2 < LONGITUD)) {
						aniadirJugada(s + 2, i + 1, movimiento);
					}
					lista[cont].m = movimiento;
					break;
				};
				case ALFIL: {
					lista[cont].pieza = ALFIL;
					int x = s - 1;
					for (int y = i - 1; y >= 0; y--) // diagonal der. arriba
					{
						if (tablero[y][x] <= 0 && (x < LONGITUD && y < LONGITUD))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x--;
					}
					x = s + 1;
					for (int y = i - 1; y >= 0; y--) // diagonal izq. arriba
					{
						if (tablero[y][x] <= 0 && (x < LONGITUD && y >= 0))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x++;
					}
					x = s - 1;
					for (int y = i + 1; y < LONGITUD; y++) // diagonal izq. abajo
					{
						if (tablero[y][x] <= 0 && (x >= 0 && y < LONGITUD))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x--;
					}
					x = s + 1;
					for (int y = i + 1; y < LONGITUD; y++)  // diagonal der. abajo
					{
						if (tablero[y][x] <= 0 && (x < LONGITUD && y < LONGITUD))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x++;
					}
					lista[cont].m = movimiento;
					break;
				};
				case REINA: {
					lista[cont].pieza = REINA;
					for (int x = s - 1; x >= 0; x--) // a la izq.
					{
						if (tablero[i][x] <= 0)
						{
							aniadirJugada(x, i, movimiento);
						}
						else if (tablero[i][x] != 0)
						{
							break;
						}
					}
					for (int y = i - 1; y >= 0; y--) // arriba
					{
						if (tablero[y][s] <= 0)
						{
							aniadirJugada(s, y, movimiento);
						}
						else if (tablero[y][s] != 0)
						{
							break;
						}
					}
					for (int x = s + 1; x <= 7; x++) // a la der.
					{
						if (tablero[i][x] <= 0)
						{
							aniadirJugada(x, i, movimiento);
						}
						else if (tablero[i][x] != 0)
						{
							break;
						}
					}
					for (int y = i + 1; y <= 7; y++) // abajo
					{
						if (tablero[y][s] <= 0)
						{
							aniadirJugada(s, y, movimiento);
						}
						else if (tablero[y][s] != 0)
						{
							break;
						}
					}
					int x = s - 1;
					for (int y = i - 1; y >= 0; y--) // arriba a la izq.
					{
						if (tablero[y][x] <= 0 && (x >= 0 && y >= 0))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x--;
					}
					x = s + 1;
					for (int y = i - 1; y >= 0; y--) // arriba a la der.
					{
						if (tablero[y][x] <= 0 && (x < LONGITUD && y >= 0))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x++;
					}
					x = s - 1;
					for (int y = i + 1; y <= 7; y++) // abajo a la izq.
					{
						if (tablero[y][x] <= 0 && (x >= 0 && y < LONGITUD))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x--;
					}
					x = s + 1;
					for (int y = i + 1; y <= 7; y++)  // abajo a la der.
					{
						if (tablero[y][x] <= 0 && (x < LONGITUD && y < LONGITUD))
						{
							aniadirJugada(x, y, movimiento);
						}
						else if (tablero[y][x] != 0)
						{
							break;
						}
						x++;
					}
					lista[cont].m = movimiento;
					break;
				};
				case REY: {
					lista[cont].pieza = REY;
					for (int y = -1; y <= 1; y++) {
						for (int x = -1; x <= 1; x++) {
							if ((i + y >= 0 && i + y < LONGITUD) && (s + x >= 0 && s + x < LONGITUD)) {
								if (tablero[i + y][s + x] <= 0) {
									aniadirJugada(s + x, i + y, movimiento);
								}
							}
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				delete movimiento;
				}
				cont++;
			}
		}
	}
}

/*
	Tablas De Posiciones (se descarta las tablas variables, ahora seran tablas fijas)
*/
/*float tabPPeon[8][8]
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
	1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0,
	0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0,
	0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5,
	0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5, };
float tabPCaballo[8][8]
{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
  1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0
  0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0
  0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5
  0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5 };
float tabPPeon[8][8]
{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
  1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0
  0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0
  0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5
  0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5 };
float tabPPeon[8][8]
{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
  1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0
  0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0
  0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5
  0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5 };
float tabPPeon[8][8]
{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
  1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0
  0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0
  0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5
  0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5 };*/
/*
	Actualiza Las Tablas Posicion de las demas 
*/
