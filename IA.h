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
struct movpiezas {
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
void acTabV(int a[N][N],int b[N][N]) {

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
  10,10,10,10,10,10,10,10,
  10,10,10,10,10,10,10,10,
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
void generarListaDeMovimientos(movpiezas lista[], int color,int t[N][N]) { //color a seleccionar blanco=-1, negro=1
	int cont = 0;
	for (int i = 0; i < LONGITUD; i++) {
		for (int s = 0; s < LONGITUD; s++) {
			if (t[i][s] * color > 0) {
				lista[cont].act.x = s; //tablero[y][x];
				lista[cont].act.y = i;
				switch (abs(t[i][s])) {
				case PEON: {
					

					break;
				};
				case TORRE: {


					break;
				};
				case CABALLO: {


					break;
				};
				case ALFIL: {


					break;
				};
				case REINA: {


					break;
				};
				case REY: {


					break;
				};
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
	nuevo->pieza = value.pieza;
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
		}
		else {
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
void limpiarLPiezas(lPiezas& l, lPiezas& excep) {
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

void realizarMov(int t[N][N], lPiezas m) {
	if (abs(m->pieza) == 6 && (m->act.x+2== m->m->movimiento.x || m->act.x - 2 == m->m->movimiento.x)) {

	}
	t[m->act.y][m->act.x] = 0;
	t[m->m->movimiento.y][m->m->movimiento.x] = m->pieza;
}
/*
	cont = contador de profundidad
	color blanco =-1 negro =1
*/
float fBackTraking(int cont,int tJuegoSec[N][N],int color){
	if (cont == 0) {
		return 0.0;
	}
	else {
		int num = numPiezas(color, tJuegoSec);
		if (num > 1) {
			lPiezas l = new movpiezas[num];
			lPiezas mayor = new movpiezas;
			mayor->m = NULL;
			TabP t;
			//adaptar obtener movimientos
			for (int i = 0; i < num; i++) {
				if (l[i].m != NULL) {
					if (mayor == NULL) {
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
				realizarMov(tJuegoSec, mayor);
				//liberar la memoria
				float res = t.getValor(tJuegoSec, color, mayor->pieza, mayor->m->movimiento.x, mayor->m->movimiento.y);
				delete l;
				delete mayor;
				//devolver la funcion con cont--, tablero actualizado, color*-1
				return res + fBackTraking(cont--,tJuegoSec,color*-1);
			}
			else {
				return -9000.0;
			}
		}
		else {
			return -9000.0;
		}
		
	}
}
movpiezas fGeneral() {

}
