#pragma once
#include "Chess.h"
#include "TabP.h"

#define PEON 1
#define TORRE 2
#define CABALLO 3
#define ALFIL 4 
#define REINA 5
#define REY 6 
int colorIA=1; //blanco =-1 negro =1
struct mov { 
	pos movimiento; 
	mov* sgte; 
};

typedef struct mov* pilaMov;


struct movpiezas { //<-
	pos act; //<-posicion actual
	pilaMov m; //<-es un puntero que determinara los movimientos posibles de la pieza, si el puntero esta en null entonces no existen movimientos pasa esa pieza
	int pieza;//<-
	movpiezas* sgte;
};

typedef struct movpiezas* lPiezas;
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
	A -> tabla de juego normal
	B -> tabla con valores de juego;
*/
void acTabV(int a[N][N],int b[N][N]) {
	for (int i = 0; i < 8; i++) {
		for (int s = 0; s < 8; s++) {
			switch (abs(a[i][s])) { //valor absoluto de la casilla en el tablero original 
			case 1: case 3: case 4: b[i][s] = a[i][s] * 10; break; //PEON CABALLO ALFIL 
			case 2: b[i][s] = a[i][s] * 25; break; //TORRE
			case 5: b[i][s] = (a[i][s] / 5) * 90; break; // REINA
			case 6: b[i][s] = (a[i][s] / 6) * 900; break; //REY 
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
	try
	{
		if (p == NULL) {
			nuevo->sgte = NULL;
			p = nuevo;
		}
		else {
			nuevo->sgte = p;
			p = nuevo;
		}
		
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error al grabar en la pila" << std::endl;
		std::cout << "Valor no grabado: " << valor.x << "|" << valor.y << std::endl;
		p = NULL;
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


void aniadirJugada(int x, int y, pilaMov &pilamovi) {
	pos posi;
	posi.x = x;
	posi.y = y;
	addPila(pilamovi, posi);
}

/*
	Blanco=-1 | Negro=1
*/
int numPiezas(int color, int t[N][N]) {
	int sum=0;
	for (int i = 0; i < N; i++) {
		for (int s = 0; s < N; s++) {
			if (t[i][s] * color > 0) {
				sum++;
			}
		}
	}
	return sum;
}
//por mejorar lista de mov 
void generarListaDeMovimientos(movpiezas lista[], int color, int t[N][N]) { //color a seleccionar blanco=-1, negro=1
	int cont = 0;
	for (int i = 0; i < LONGITUD; i++) {
		for (int s = 0; s < LONGITUD; s++) {
			if (t[i][s] * color > 0) {
				lista[cont].act.x = s; //tablero[y][x];
				lista[cont].act.y = i;
				pilaMov movimiento = NULL;
				switch (abs(t[i][s])) { //falta los movimientos para las blancas y usar como tablero en int t[N][N]
				case PEON: {
					lista[cont].pieza = PEON * color;
					int movcolor = 0;
					for (int y = 0; y < N; y++) {
						for (int x = 0; x < N; x++) {
							if (x == s && y == i) {

							}
							else {
								if (color > 0) {
									if (movPeonNegro(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
								else {
									if (movPeonBlanco(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
							}
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case TORRE: {
					lista[cont].pieza = TORRE * color;
					int y;
					for (int y = 0; y < N; y++) {
						for (int x = 0; x < N; x++) {
							if (x == s && y == i) {

							}
							else {
								if (color > 0) {
									if (movTorreNegra(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
								else {
									if (movTorreBlanca(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
							}
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case CABALLO: { //riesgo de causar error, revisar luego...
					lista[cont].pieza = CABALLO * color;
					//intenté hacer que verifique si la posición que está verificando, es una posición valida dentro del tablero,
					//quizá esto cause error, revisar luego.
					//lo indicaré aquí		       vv 
					if (color == 1) {
						if (t[i - 2][s - 1] <= 0 && (i - 2 >= 0 && i < LONGITUD) && (s - 1 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 1, i - 2, movimiento);
						}
						if (t[i - 2][s + 1] <= 0 && (i - 2 >= 0 && i  < LONGITUD) && (s >= 0 && s + 1 < LONGITUD)) {
							aniadirJugada(s + 1, i - 2, movimiento);
						}
						if (t[i + 2][s - 1] <= 0 && (i >= 0 && i + 2 < LONGITUD) && (s - 1 >= 0 && s< LONGITUD)) {
							aniadirJugada(s - 1, i + 2, movimiento);
						}
						if (t[i + 2][s + 1] <= 0 && (i >= 0 && i + 2 < LONGITUD) && (s >= 0 && s + 1 < LONGITUD)) {
							aniadirJugada(s + 1, i + 2, movimiento);
						}
						///
						if (t[i - 1][s - 2] <= 0 && (i - 1 >= 0 && i < LONGITUD) && (s - 2 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 2, i - 1, movimiento);
						}
						if (t[i - 1][s + 2] <= 0 && (i - 1 >= 0 && i  < LONGITUD) && (s >= 0 && s + 2 < LONGITUD)) {
							aniadirJugada(s + 2, i - 1, movimiento);
						}
						if (t[i + 1][s - 2] <= 0 && (i >= 0 && i + 1 < LONGITUD) && (s - 2 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 2, i + 1, movimiento);
						}
						if (t[i + 1][s + 2] <= 0 && (i >= 0 && i + 1 < LONGITUD) && (s >= 0 && s + 2 < LONGITUD)) {
							aniadirJugada(s + 2, i + 1, movimiento);
						}
					}
					if (color == -1) {
						if (t[i - 2][s - 1] >= 0 && (i - 2 >= 0 && i < LONGITUD) && (s - 1 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 1, i - 2, movimiento);
						}
						if (t[i - 2][s + 1] >= 0 && (i - 2 >= 0 && i < LONGITUD) && (s  >= 0 && s + 1 < LONGITUD)) {
							aniadirJugada(s + 1, i - 2, movimiento);
						}
						if (t[i + 2][s - 1] >= 0 && (i >= 0 && i + 2 < LONGITUD) && (s - 1 >= 0 && s  < LONGITUD)) {
							aniadirJugada(s - 1, i + 2, movimiento);
						}
						if (t[i + 2][s + 1] >= 0 && (i >= 0 && i + 2 < LONGITUD) && (s  >= 0 && s + 1 < LONGITUD)) {
							aniadirJugada(s + 1, i + 2, movimiento);
						}
						///
						if (t[i - 1][s - 2] >= 0 && (i - 1 >= 0 && i < LONGITUD) && (s - 2 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 2, i - 1, movimiento);
						}
						if (t[i - 1][s + 2] >= 0 && (i - 1 >= 0 && i < LONGITUD) && (s >= 0 && s + 2 < LONGITUD)) {
							aniadirJugada(s + 2, i - 1, movimiento);
						}
						if (t[i + 1][s - 2] >= 0 && (i >= 0 && i + 1 < LONGITUD) && (s - 2 >= 0 && s < LONGITUD)) {
							aniadirJugada(s - 2, i + 1, movimiento);
						}
						if (t[i + 1][s + 2] >= 0 && (i>= 0 && i + 1 < LONGITUD) && (s >= 0 && s + 2 < LONGITUD)) {
							aniadirJugada(s + 2, i + 1, movimiento);
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case ALFIL: {
					lista[cont].pieza = ALFIL * color;
					for (int y = 0; y < N; y++) {
						for (int x = 0; x < N; x++) {
							if (x == s && y == i) {
								
							}
							else {
								if (color > 0) {
									if (movAlfilNegro(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
								else {
									if (movAlfilBlanco(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
							}
						}
					}
					/*int y = i;
					for (int x = s; x < N && y < N; x++, y++) {
						if (x != s && y < N) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x < N && y >= 0; x++, y--) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x >= 0 && y < N; x--, y++) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x >= 0 && y >= 0; x--, y--) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}*/
					lista[cont].m = movimiento;
					break;
				};
				case REINA: {
					lista[cont].pieza = REINA * color;
					/*int y = i;
					for (int x = s; x < N && y<N; x++,y++) {
						if (x != s && y < N) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[y][x] *color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x < N && y>=0; x++,y--) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] *color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x>=0 && y<N; x--,y++) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}
					y = i;
					for (int x = s; x >=0 && y>=0; x--,y--) {
						if (x != s) {
							if (t[y][x] == 0) {
								aniadirJugada(x, y, movimiento);
								break;
							}
							else {
								if (t[y][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
								}
								else {
									break;
								}
							}
						}
					}

					for (y = i; y < N; y++) {
						if (y!= i ) {
							if (t[y][s] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[y][s] * color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}
					for (y = i; y >= 0; y--) {
						if (y != i) {
							if (t[y][s] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[y][s] * color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}
					for (int x=s; x < N; x++) {
						if (x != i) {
							if (t[i][x] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[i][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}
					for (int x = s; x >=0; x--) {
						if (x != i) {
							if (t[i][x] == 0) {
								aniadirJugada(x, y, movimiento);
							}
							else {
								if (t[i][x] * color < 0) {
									aniadirJugada(x, y, movimiento);
									break;
								}
								else {
									break;
								}
							}
						}
					}*/
					for (int y = 0; y < N; y++) {
						for (int x = 0; x < N; x++) {
							if (x == s && y == i) {

							}
							else {
								if (color > 0) {
									if (movReinaNegra(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
								else {
									if (movReinaBlanca(s, i, x, y, t) == 1) {
										aniadirJugada(x, y, movimiento);
									}
								}
							}
						}
					}
					lista[cont].m = movimiento;
					break;
				};
				case REY: {
					lista[cont].pieza = REY * color;
					for (int y = -1; y <= 1; y++) {
						for (int x = -1; x <= 1; x++) {
							if ((i + y >= 0 && i + y < LONGITUD) && (s + x >= 0 && s + x < LONGITUD)) {
								if (color == 1) {
									if (t[i + y][s + x] <= 0) {
										aniadirJugada(s + x, i + y, movimiento);
									}
								}
								if (color == -1) {
									if (t[i + y][s + x] >= 0) {
										aniadirJugada(s + x, i + y, movimiento);
									}
								}
							}
						}
						lista[cont].m = movimiento;
						break;
					}
				}
				}
				cont++;
			}
		}
	}
}

void addLista(lPiezas &l, movpiezas value) {
	lPiezas nuevo= new movpiezas;
	nuevo->act = value.act;
	nuevo->m = value.m;
	try
	{
		if (l != NULL) {
			nuevo->sgte = l;
			l = nuevo;
		}
		else {
			nuevo->sgte = NULL;
			l = nuevo;
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error de escritura lista piezas" << std::endl;
	}
}
/*
	dejar excep en NULL si no quieres obviar ningun elemento
*/
void limpiarLPiezas(lPiezas &l, lPiezas &excep) {
	while (l != NULL) {
		if (excep != NULL && l == excep) {
			try
			{
				l = l->sgte;
				excep->sgte = NULL;
			}
			catch (const std::exception&)
			{
				try
				{
					excep->sgte = NULL;
				}
				catch (const std::exception&)
				{
					excep = NULL;
					std::cout << "Error escribir en excep lista: lista sin fin (null)" << std::endl;
				}
				l = NULL;
				std::cout << "Error al limpiar lista: lista sin fin (null)" << std::endl;
			}
		}else {
			try
			{
				lPiezas temp = new movpiezas;
				temp = l;
				l = l->sgte;
				delete temp;
			}
			catch (const std::exception&)
			{
				l = NULL;
				std::cout << "Error al limpiar lista: lista sin fin (null)" << std::endl;
			}
		}
	}
}
/*
	Excep como null si solo quiere eliminar todo los elementos de la pila
*/
void limpiarpilaMov(pilaMov& l, pilaMov& excep) {
	while (l != NULL) {
		if (excep != NULL && l == excep) {
			try
			{
				l = l->sgte;
				excep->sgte = NULL;
			}
			catch (const std::exception&)
			{
				try
				{
					excep->sgte = NULL;
				}
				catch (const std::exception&)
				{
					excep = NULL;
					std::cout << "Error escribir en excep lista: lista sin fin (null)" << std::endl;
				}
				l = NULL;
				std::cout << "Error al limpiar lista: lista sin fin (null)" << std::endl;
			}
		}
		else {
			try
			{
				pilaMov temp = new mov;
				temp = l;
				l = l->sgte;
				delete temp;
			}
			catch (const std::exception&)
			{
				l = NULL;
				std::cout << "Error al limpiar lista: lista sin fin (null)" << std::endl;
			}
		}
	}
	l = excep;
}
void obtenerMejorMovdePieza(int tJuego[N][N],lPiezas &p,int color) {
	if (p != NULL) {
		try
		{
			TabP t;
			pilaMov mayor = p->m;
			pilaMov temp;
			if (mayor->sgte != NULL) {
				temp = p->m->sgte;
			}
			else {
				temp = NULL;
			}
			
			while (temp != NULL) {
				if (t.getValor(tJuego, color, p->pieza, temp->movimiento.x, temp->movimiento.y) > t.getValor(tJuego, color, p->pieza, mayor->movimiento.x, mayor->movimiento.y))
					mayor = temp;
				temp = temp->sgte;
			}
			limpiarpilaMov(p->m, mayor);
		}
		catch (const std::exception&)
		{
			p->m = NULL;
		}
	}
}

void realizarMov(int t[N][N], lPiezas m) {
	if (abs(m->pieza) == 6 && (m->act.x+2== m->m->movimiento.x || m->act.x - 2 == m->m->movimiento.x)) {
		if (m->m->movimiento.x > m->act.x) {
			t[m->act.y][m->act.x + 1] = t[m->act.y][7];
			t[m->act.y][7] = 0;
		}
		else {
			t[m->act.y][m->act.x - 1] = t[m->act.y][0];
			t[m->act.y][0] = 0;
		}
			
	}
	//TABLERO[y][x]
	t[m->m->movimiento.y][m->m->movimiento.x] = t[m->act.y][m->act.x];
	t[m->act.y][m->act.x] = 0;
}

/*
	valor de tablero 
	para las blancas= -1
	para negras = 1;
*/
float calcularVTablero(int t[8][8]) {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int s = 0; s < 8; s++) {
			switch (abs(t[i][s]))
			{
			case 1: sum = t[i][s]>0? sum+10:sum-10; break;
			case 2: sum = t[i][s] > 0 ? sum + 50 : sum - 50; break;
			case 3: case 4: sum = t[y][x] > 0 ? sum + 30 : sum - 30; break;
			case 5: sum = t[i][s] > 0 ? sum + 90 : sum - 90; break; 
			case 6: sum = t[i][s] > 0 ? sum + 900 : sum - 900; break;
			default:
				break;
			}
		}
	}
	return (float)sum * (float)colorIA;
}
void escribirpila(int t[8][8], pilaMov x) {
	int r[8][8];
	TabP s;
	while (x != NULL) {
		t[x->movimiento.y][x->movimiento.x] = 1;
		s.copiarMatriz(r, t);
		x = x->sgte;
	}
}
/*
	cont = contador de profundidad
	color blanco =-1 negro =1
*/
float fBackTraking(int cont,int tJuegoSec[N][N],int color){
	if (cont == 0) {
		return calcularVTablero(tJuegoSec);
	}
	else {
		int num = numPiezas(color, tJuegoSec);
		if (num > 1) {
			lPiezas l = new movpiezas[num];
			lPiezas mayor = new movpiezas;
			lPiezas temp;
			mayor->m = NULL;
			TabP t;
			int g[8][8];
			generarListaDeMovimientos(l,color,tJuegoSec);//adaptar obtener movimientos
			for (int i = 0; i < num; i++) {
				if (l[i].m != NULL) {
					temp = &l[i];
					obtenerMejorMovdePieza(tJuegoSec, temp, color);
					if (mayor->m == NULL) {
						mayor = &l[i];
					}
					else {
						if (t.getValor(tJuegoSec, color, l[i].pieza, l[i].m->movimiento.x, l[i].m->movimiento.y) > t.getValor(tJuegoSec, color, mayor->pieza, mayor->m->movimiento.x, mayor->m->movimiento.y)) {
							mayor = &l[i];
						}
					}
				}
			}
			if (mayor != NULL) {
				//realizar movimiento en tablero tJuegoSec
				t.copiarMatriz(g, tJuegoSec);
				realizarMov(tJuegoSec, mayor);
				t.copiarMatriz(g, tJuegoSec);
				//liberar la memoria
				delete l;
				//delete mayor;
				//devolver la funcion con cont--, tablero actualizado, color*-1
				return fBackTraking(cont-1,tJuegoSec,color*-1);
			}
			else {
				return calcularVTablero(tJuegoSec)-900;
			}
		}
		else {
			return -900;
		}
		
	}
}
/*
	dif = dificultad 
*/
lPiezas fGeneral(int dif){
	TabP t;
	int tab[N][N];
	t.copiarMatriz(tab, tablero);
	int n = numPiezas(colorIA, tab);
	lPiezas l = new movpiezas[n];
	lPiezas movEs = new movpiezas;
	movEs = NULL;
	lPiezas temp = new movpiezas;
	temp = NULL;
	float mayor;
	generarListaDeMovimientos(l, colorIA, tab);
	for (int i = 0; i < n; i++) {
		if (l[i].m != NULL) {
			t.copiarMatriz(tab, tablero);
			if (movEs == NULL) {
				temp = &l[i];
				obtenerMejorMovdePieza(tab, temp, colorIA);
				movEs = temp;
				mayor = fBackTraking(dif, tab, colorIA);
			}
			else
			{
				temp = &l[i];
				obtenerMejorMovdePieza(tab, temp, colorIA);
				realizarMov(tab, temp);
				if (fBackTraking(dif, tab, colorIA) > mayor) {
					movEs = &l[i];
					mayor = fBackTraking(dif, tab, colorIA);
				}
				else if (fBackTraking(dif, tab, colorIA) == mayor && t.getValor(tab, colorIA, l[i].pieza, l[i].m->movimiento.x, l[i].m->movimiento.y) > t.getValor(tab, colorIA, movEs->pieza, movEs->m->movimiento.x, movEs->m->movimiento.y)) {
					movEs = &l[i];
					mayor = fBackTraking(dif, tab, colorIA);
				}
			}
		}
	}
	if (movEs != NULL) {
		return movEs;
	}
	else {
		return NULL;
	}
	//funcion donde debemos analizar los posibles casos dentro de la tabla 

}
