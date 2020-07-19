#pragma once
#include <SFML/Graphics.hpp>

#define LONGITUD 8
#define PEON_NEGRO 1
#define PEON_BLANCO -1
#define TORRE_NEGRA 2
#define TORRE_BLANCA -2
#define CABALLO_NEGRO 3
#define CABALLO_BLANCO -3
#define ALFIL_NEGRO 4
#define ALFIL_BLANCO -4
#define REINA_BLANCA -5
#define REINA_NEGRA 5
#define REY_NEGRO 6
#define REY_BLANCO -6

using namespace sf;

struct pos
{
	int x, y;
}prevPos, posReyBlanco, posReyNegro, transformBlanco, transformNegro;

int tamanio = 100, movimientos = 0, x, y;
int tablero[8][8] =
{ 2, 3, 4, 5, 6, 4, 3, 2,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
 -1,-1,-1,-1,-1,-1,-1,-1,
 -2,-3,-4,-5,-6,-4,-3,-2, }; //ez tablero 1=peon, 2=torre, 3=caballo, 4=alfil, 5=reina, 6=rey  tablero[y][x];

//estos valores, sirven para poder validar el enrroque del rey.
int torreBlancaDer = 0, torreBlancaIzq = 0, reyBlanco = 0;
int torreNegraDer = 0, torreNegraIzq = 0, reyNegro = 0;

int turno = 0; // 0 turno de blancas, 1 turno de negras.

//para saber si los reyes de estos está en jaque
int jackeBlanco = 0, jackeNegro = 0;




int movPeonBlanco(int prevX, int prevY, int nuevoX, int nuevoY)
{
	if (prevPos.y == 6)
	{
		if ((nuevoY == prevY - 1 && nuevoX == prevX && tablero[prevY - 1][prevX] == 0) || (nuevoY == prevY - 2 && nuevoX == prevX && tablero[prevY - 1][prevX] == 0 && tablero[prevY - 2][prevX] == 0))
		{
			return 1;
		}
	}
	else if (nuevoY == prevY - 1 && nuevoX == prevX && tablero[prevY - 1][prevX] == 0)
	{
		return 1;
	}
	if (tablero[prevY - 1][prevX - 1] > 0)
	{
		if (nuevoY == prevY - 1 && nuevoX == prevX - 1)
		{
			return 1;
		}
	}
	if (tablero[prevY - 1][prevX + 1] > 0)
	{
		if (nuevoY == prevY - 1 && nuevoX == prevX + 1)
		{
			return 1;
		}
	}
	return 0;
}

int movPeonNegro(int prevX, int prevY, int nuevoX, int nuevoY)
{
	if (prevPos.y == 1)
	{
		if ((nuevoY == prevY + 1 && nuevoX == prevX && tablero[prevY + 1][prevX] == 0) || (nuevoY == prevY + 2 && nuevoX == prevX && tablero[prevY + 1][prevX] == 0 && tablero[prevY + 2][prevX] == 0))
		{
			return 1;
		}
	}
	else if (nuevoY == prevY + 1 && nuevoX == prevX && tablero[prevY + 1][prevX] == 0)
	{
		return 1;
	}
	if (tablero[prevY + 1][prevX - 1] < 0)
	{
		if (nuevoY == prevY + 1 && nuevoX == prevX - 1)
		{
			return 1;
		}
	}
	if (tablero[prevY + 1][prevX + 1] < 0)
	{
		if (nuevoY == prevY + 1 && nuevoX == prevX + 1)
		{
			return 1;
		}
	}
	return 0;
}

int movTorreBlanca(int prevX, int prevY, int nuevoX, int nuevoY)
{
	for (int i = prevX - 1; i >= 0; i--)
	{ // a la izq.
		if (tablero[prevY][i] >= 0 && (nuevoX == i && nuevoY == prevY))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][prevX] >= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	for (int i = prevX + 1; i <= 7; i++) // a la der.
	{
		if (tablero[prevY][i] >= 0 && (nuevoY == prevY && nuevoX == i))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY + 1; i <= 7; i++) // abajo
	{
		if (tablero[i][prevX] >= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	return 0;
}

int movTorreNegra(int prevX, int prevY, int nuevoX, int nuevoY)
{
	for (int i = prevX - 1; i >= 0; i--) // a la der.
	{
		if (tablero[prevY][i] <= 0 && (nuevoX == i && nuevoY == prevY))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][prevX] <= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	for (int i = prevX + 1; i <= 7; i++) // a la izq.
	{
		if (tablero[prevY][i] <= 0 && (nuevoY == prevY && nuevoX == i))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY + 1; i <= 7; i++) // abajo
	{
		if (tablero[i][prevX] <= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	return 0;
}

int movAlfilBlanco(int prevX, int prevY, int nuevoX, int nuevoY)
{
	int j = prevX - 1;
	for (int i = prevY - 1; i >= 0; i--) // diagonal der. arriba
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY - 1; i >= 0; i--) // diagonal izq. arriba
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = prevX - 1;
	for (int i = prevY + 1; i <= 7; i++) // diagonal izq. abajo
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY + 1; i <= 7; i++)  // diagonal der. abajo
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int movAlfilNegro(int prevX, int prevY, int nuevoX, int nuevoY)
{
	int j = prevX - 1;
	for (int i = prevY - 1; i >= 0; i--) // diagonal der. arriba
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY - 1; i >= 0; i--) // diagonal izq. arriba
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = prevX - 1;
	for (int i = prevY + 1; i <= 7; i++) // diagonal izq. abajo
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY + 1; i <= 7; i++)  // diagonal der. abajo
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int movReinaBlanca(int prevX, int prevY, int nuevoX, int nuevoY)
{
	for (int i = prevX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[prevY][i] >= 0 && (nuevoX == i && nuevoY == prevY))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][prevX] >= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	for (int i = prevX + 1; i <= 7; i++) // a la der.
	{
		if (tablero[prevY][i] >= 0 && (nuevoY == prevY && nuevoX == i))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY + 1; i <= 7; i++) // abajo
	{
		if (tablero[i][prevX] >= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	int j = prevX - 1;
	for (int i = prevY - 1; i >= 0; i--) // arriba a la izq.
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY - 1; i >= 0; i--) // arriba a la der.
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = prevX - 1;
	for (int i = prevY + 1; i <= 7; i++) // abajo a la der.
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY + 1; i <= 7; i++)  // abajo a la izq.
	{
		if (tablero[i][j] >= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int movReinaNegra(int prevX, int prevY, int nuevoX, int nuevoY)
{
	for (int i = prevX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[prevY][i] <= 0 && (nuevoX == i && nuevoY == prevY))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][prevX] <= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	for (int i = prevX + 1; i <= 7; i++) // a la der.
	{
		if (tablero[prevY][i] <= 0 && (nuevoY == prevY && nuevoX == i))
		{
			return 1;
		}
		else if (tablero[prevY][i] != 0)
		{
			break;
		}
	}
	for (int i = prevY + 1; i <= 7; i++) // abajo
	{
		if (tablero[i][prevX] <= 0 && (nuevoY == i && nuevoX == prevX))
		{
			return 1;
		}
		else if (tablero[i][prevX] != 0)
		{
			break;
		}
	}
	int j = prevX - 1;
	for (int i = prevY - 1; i >= 0; i--) // arriba a la izq.
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY - 1; i >= 0; i--) // arriba a la der.
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = prevX - 1;
	for (int i = prevY + 1; i <= 7; i++) // abajo a la izq.
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = prevX + 1;
	for (int i = prevY + 1; i <= 7; i++)  // abajo a la der.
	{
		if (tablero[i][j] <= 0 && (nuevoY == i && nuevoX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

//se comentará los movimientos así: U = arriba, R = derecha, L = izquierda, D = abajo
//ejemplo: para hacer un movimiento así:
//	o <-- posicion antigua , x <-- posicion nueva.
//
//	para que se mueva asi:
//
//	  x
//	o--
//
//  se escribiría así:
//
//  RRU

int movCaballoBlanco(int prevX, int prevY, int nuevoX, int nuevoY)
{
	if (prevY - 2 >= 0 && prevX - 1 >= 0 && nuevoY == prevY - 2 && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // UUR
	}
	if (prevY - 2 >= 0 && prevX + 1 < LONGITUD && nuevoY == prevY - 2 && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // UUL
	}
	if (prevY - 1 >= 0 && prevX + 2 < LONGITUD && nuevoY == prevY - 1 && nuevoX == prevX + 2 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // RRU
	}
	if (prevY + 1 >= 0 && prevX + 2 < LONGITUD && nuevoY == prevY + 1 && nuevoX == prevX + 2 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // RRD
	}
	if (prevY + 2 < LONGITUD && prevX + 1 < LONGITUD && nuevoY == prevY + 2 && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // LLU
	}
	if (prevY + 2 < LONGITUD && prevX - 1 >= 0 && nuevoY == prevY + 2 && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // LLD
	}
	if (prevY + 1 < LONGITUD && prevX - 2 >= 0 && nuevoY == prevY + 1 && nuevoX == prevX - 2 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // DDR
	}
	if (prevY - 1 >= 0 && prevX - 2 >= 0 && nuevoY == prevY - 1 && nuevoX == prevX - 2 && tablero[nuevoY][nuevoX] >= 0)
	{
		return 1; // DDL
	}
	return 0;
}

int movCaballoNegro(int prevX, int prevY, int nuevoX, int nuevoY)
{
	if (prevY - 2 >= 0 && prevX - 1 >= 0 && nuevoY == prevY - 2 && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // UUR
	}
	if (prevY - 2 >= 0 && prevX + 1 < LONGITUD && nuevoY == prevY - 2 && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // UUL
	}
	if (prevY - 1 >= 0 && prevX + 2 < LONGITUD && nuevoY == prevY - 1 && nuevoX == prevX + 2 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // RRU
	}
	if (prevY + 1 >= 0 && prevX + 2 < LONGITUD && nuevoY == prevY + 1 && nuevoX == prevX + 2 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // RRD
	}
	if (prevY + 2 < LONGITUD && prevX + 1 < LONGITUD && nuevoY == prevY + 2 && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // LLU
	}
	if (prevY + 2 < LONGITUD && prevX - 1 >= 0 && nuevoY == prevY + 2 && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // LLD
	}
	if (prevY + 1 < LONGITUD && prevX - 2 >= 0 && nuevoY == prevY + 1 && nuevoX == prevX - 2 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // DDR
	}
	if (prevY - 1 >= 0 && prevX - 2 >= 0 && nuevoY == prevY - 1 && nuevoX == prevX - 2 && tablero[nuevoY][nuevoX] <= 0)
	{
		return 1; // DDL
	}
	return 0;
}


int jaqueABlancoConPeon(int posX, int posY, int reyX, int reyY)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " regex=" << regex << " regey=" << regey << "\n\n\n";
	if (tablero[posY - 1][posX - 1] >= 0)
	{
		if (posY - 1 == reyY && posX - 1 == reyX)
		{
			return 1;
		}
	}
	if (tablero[posY - 1][posX + 1] >= 0)
	{
		//std::cout << "da";
		if (posY - 1 == reyY && posX + 1 == reyX)
		{
			return 1;
		}
	}
	return 0;
}

int jaqueABlancoConTorre(int posX, int posY, int reyX, int reyY)
{
	for (int i = posX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[posY][i] >= 0 && (reyX == i && reyY == posY))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][posX] >= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	for (int i = posX + 1; i < LONGITUD; i++) // a la der.
	{
		if (tablero[posY][i] >= 0 && (reyY == posY && reyX == i))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY + 1; i < LONGITUD; i++) // abajo
	{
		if (tablero[i][posX] >= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	return 0;
}

int jaqueABlancoConAlfil(int posX, int posY, int reyX, int reyY)
{
	int j = posX - 1;
	for (int i = posY - 1; i >= 0; i--) // diagonal arriba izq.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY - 1; i >= 0; i--) // diagonal arriba der.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = posX - 1;
	for (int i = posY + 1; i <= 7; i++) // diagonal abajo izq.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY + 1; i <= 7; i++)  // diagonal abajo der.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int jaqueABlancoConReina(int posX, int posY, int reyX, int reyY)
{
	for (int i = posX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[posY][i] >= 0 && (reyX == i && reyY == posY))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][posX] >= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	for (int i = posX + 1; i < LONGITUD; i++) // a la der.
	{
		if (tablero[posY][i] >= 0 && (reyY == posY && reyX == i))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY + 1; i < LONGITUD; i++) // abajo
	{
		if (tablero[i][posX] >= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	int j = posX - 1;
	for (int i = posY - 1; i >= 0; i--) // arriba a la izq.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY - 1; i >= 0; i--) // arriba a la der.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = posX - 1;
	for (int i = posY + 1; i <= 7; i++) // abajo a la izq.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY + 1; i < LONGITUD; i++)  // abajo a la der.
	{
		if (tablero[i][j] >= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int jaqueABlancoConCaballo(int posX, int posY, int reyX, int reyY)
{
	if (posY - 2 >= 0 && posX - 1 >= 0 && reyY == posY - 2 && reyX == posX - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1; // UUR
	}
	if (posY - 2 >= 0 && posX + 1 < LONGITUD && reyY == posY - 2 && reyX == posX + 1 && tablero[reyY][reyX] >= 0)
	{
		return 1; // UUL
	}
	if (posY - 1 >= 0 && posX + 2 < LONGITUD && reyY == posY - 1 && reyX == posX + 2 && tablero[reyY][reyX] >= 0)
	{
		return 1; // RRU
	}
	if (posY + 1 >= 0 && posX + 2 < LONGITUD && reyY == posY + 1 && reyX == posX + 2 && tablero[reyY][reyX] >= 0)
	{
		return 1; // RRD
	}
	if (posY + 2 < LONGITUD && posX + 1 < LONGITUD && reyY == posY + 2 && reyX == posX + 1 && tablero[reyY][reyX] >= 0)
	{
		return 1; // LLU
	}
	if (posY + 2 < LONGITUD && posX - 1 >= 0 && reyY == posY + 2 && reyX == posX - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1; // LLD
	}
	if (posY + 1 < LONGITUD && posX - 2 >= 0 && reyY == posY + 1 && reyX == posX - 2 && tablero[reyY][reyX] >= 0)
	{
		return 1; // DDR
	}
	if (posY - 1 >= 0 && posX - 2 >= 0 && reyY == posY - 1 && reyX == posX - 2 && tablero[reyY][reyX] >= 0)
	{
		return 1; // DDL
	}
	return 0;
}

int jaqueABlancoConRey(int posX, int posY, int reyX, int reyY)
{
	if (posX - 1 >= 0 && posY - 1 >= 0 && reyY == posY - 1 && reyX == posX - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posY - 1 >= 0 && reyX == posX && reyY == posY - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posY - 1 >= 0 && posX + 1 < LONGITUD && reyX == posX + 1 && reyY == posY - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posX + 1 < LONGITUD && reyY == posY && reyX == posX + 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posX + 1 < LONGITUD && posY + 1 < LONGITUD && reyY == posY + 1 && reyX == posX + 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posY + 1 < LONGITUD && reyY == posY + 1 && reyX == posX && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posX - 1 >= 0 && posY + 1 < LONGITUD && reyX == posX - 1 && reyY == posY + 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	if (posX - 1 >= 0 && reyY == posY && reyX == posX - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1;
	}
	return 0;
}


int jaqueANegroConPeon(int posX, int posY, int reyX, int reyY)
{
	if (tablero[posY + 1][posX - 1] <= 0)
	{
		if (reyY == posY + 1 && reyX == posX - 1)
		{
			return 1;
		}
	}
	if (tablero[posY + 1][posX + 1] <= 0)
	{
		if (reyY == posY + 1 && reyX == posX + 1)
		{
			return 1;
		}
	}
	return 0;
}

int jaqueANegroConTorre(int posX, int posY, int reyX, int reyY)
{
	for (int i = posX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[posY][i] <= 0 && (reyX == i && reyY == posY))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][posX] <= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	for (int i = posX + 1; i < LONGITUD; i++) // a la der.
	{
		if (tablero[posY][i] <= 0 && (reyY == posY && reyX == i))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY + 1; i < LONGITUD; i++) // abajo
	{
		if (tablero[i][posX] <= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	return 0;
}

int jaqueANegroConAlfil(int posX, int posY, int reyX, int reyY)
{
	int j = posX - 1;
	for (int i = posY - 1; i >= 0; i--) // arriba a la izq.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY - 1; i >= 0; i--) // arriba a la der.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = posX - 1;
	for (int i = posY + 1; i <= 7; i++) // abajo a la izq.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY + 1; i <= 7; i++)  // abajo a la der.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int jaqueANegroConReina(int posX, int posY, int reyX, int reyY)
{
	for (int i = posX - 1; i >= 0; i--) // a la izq.
	{
		if (tablero[posY][i] <= 0 && (reyX == i && reyY == posY))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY - 1; i >= 0; i--) // arriba
	{
		if (tablero[i][posX] <= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	for (int i = posX + 1; i < LONGITUD; i++) // a la der.
	{
		if (tablero[posY][i] <= 0 && (reyY == posY && reyX == i))
		{
			return 1;
		}
		else if (tablero[posY][i] != 0)
		{
			break;
		}
	}
	for (int i = posY + 1; i < LONGITUD; i++) // abajo
	{
		if (tablero[i][posX] <= 0 && (reyY == i && reyX == posX))
		{
			return 1;
		}
		else if (tablero[i][posX] != 0)
		{
			break;
		}
	}
	int j = posX - 1;
	for (int i = posY - 1; i >= 0; i--) // arriba izq.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY - 1; i >= 0; i--) // arriba der.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = posX - 1;
	for (int i = posY + 1; i <= 7; i++) // abajo izq.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = posX + 1;
	for (int i = posY + 1; i < LONGITUD; i++)  // abajo der.
	{
		if (tablero[i][j] <= 0 && (reyY == i && reyX == j))
		{
			return 1;
		}
		else if (tablero[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int jaqueANegroConCaballo(int posX, int posY, int reyX, int reyY)
{
	if (posY - 2 >= 0 && posX - 1 >= 0 && reyY == posY - 2 && reyX == posX - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1; // UUR
	}
	if (posY - 2 >= 0 && posX + 1 < LONGITUD && reyY == posY - 2 && reyX == posX + 1 && tablero[reyY][reyX] <= 0)
	{
		return 1; // ULL
	}
	if (posY - 1 >= 0 && posX + 2 < LONGITUD && reyY == posY - 1 && reyX == posX + 2 && tablero[reyY][reyX] <= 0)
	{
		return 1; // RRU
	}
	if (posY + 1 >= 0 && posX + 2 < LONGITUD && reyY == posY + 1 && reyX == posX + 2 && tablero[reyY][reyX] <= 0)
	{
		return 1; // RRD
	}
	if (posY + 2 < LONGITUD && posX + 1 < LONGITUD && reyY == posY + 2 && reyX == posX + 1 && tablero[reyY][reyX] <= 0)
	{
		return 1; // LLU
	}
	if (posY + 2 < LONGITUD && posX - 1 >= 0 && reyY == posY + 2 && reyX == posX - 1 && tablero[reyY][reyX] <= 0)
	{
		return 1; // LLD
	}
	if (posY + 1 < LONGITUD && posX - 2 >= 0 && reyY == posY + 1 && reyX == posX - 2 && tablero[reyY][reyX] <= 0)
	{
		return 1; // DDR
	}
	if (posY - 1 >= 0 && posX - 2 >= 0 && reyY == posY - 1 && reyX == posX - 2 && tablero[reyY][reyX] <= 0)
	{
		return 1; // DDL
	}
	return 0;
}

int jaqueANegroConRey(int posX, int posY, int reyX, int reyY)
{
	if (posX - 1 >= 0 && posY - 1 >= 0 && reyY == posY - 1 && reyX == posX - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posY - 1 >= 0 && reyX == posX && reyY == posY - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posY - 1 >= 0 && posX + 1 < LONGITUD && reyX == posX + 1 && reyY == posY - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posX + 1 < LONGITUD && reyY == posY && reyX == posX + 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posX + 1 < LONGITUD && posY + 1 < LONGITUD && reyY == posY + 1 && reyX == posX + 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posY + 1 < LONGITUD && reyY == posY + 1 && reyX == posX && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posX - 1 >= 0 && posY + 1 < LONGITUD && reyX == posX - 1 && reyY == posY + 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	if (posX - 1 >= 0 && reyY == posY && reyX == posX - 1 && tablero[reyY][reyX] >= 0)
	{
		return 1;
	}
	return 0;
}

int verifReyNegroJaque(int posReyX, int posReyY)
{
	int ok = 0;
	for (int i = 0; i < LONGITUD; i++)
	{
		for (int j = 0; j < LONGITUD; j++)
		{
			if (tablero[i][j] < 0)
			{
				if (tablero[i][j] == PEON_BLANCO)
				{
					ok = jaqueABlancoConPeon(j, i, posReyX, posReyY);
				}
				if (tablero[i][j] == TORRE_BLANCA)
				{
					ok = jaqueABlancoConTorre(j, i, posReyX, posReyY);
				}
				if (tablero[i][j] == CABALLO_BLANCO)
				{
					ok = jaqueABlancoConCaballo(j, i, posReyX, posReyY);
				}
				if (tablero[i][j] == ALFIL_BLANCO)
				{
					ok = jaqueABlancoConAlfil(j, i, posReyX, posReyY);
				}
				if (tablero[i][j] == REINA_BLANCA)
				{
					ok = jaqueABlancoConReina(j, i, posReyX, posReyY);
				}
				if (tablero[i][j] == REY_BLANCO)
				{
					ok = jaqueABlancoConRey(j, i, posReyX, posReyY);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//empieza con 'fi' porque significa 'function int'

int fiReyNegro(int prevX, int prevY, int nuevoX, int nuevoY)
{
	if (prevX - 1 >= 0 && prevY - 1 >= 0 && nuevoY == prevY - 1 && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX - 1, prevY - 1);
		if (ok == 1)
		{
			return 1;  // arriba a la izq.
		}
	}
	if (prevY - 1 >= 0 && nuevoX == prevX && nuevoY == prevY - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX, prevY - 1);
		if (ok == 1)
		{
			return 1; // arriba
		}
	}
	if (prevY - 1 >= 0 && prevX + 1 < LONGITUD && nuevoX == prevX + 1 && nuevoY == prevY - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX + 1, prevY - 1);
		if (ok == 1)
		{
			return 1; // arriba der.
		}
	}
	if (prevX + 1 < LONGITUD && nuevoY == prevY && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX + 1, prevY);
		if (ok == 1)
		{
			return 1; // derecha
		}
	}
	if (prevX + 1 < LONGITUD && prevY + 1 < LONGITUD && nuevoY == prevY + 1 && nuevoX == prevX + 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX + 1, prevY + 1);
		if (ok == 1)
		{
			return 1; // abajo der.
		}
	}
	if (prevY + 1 < LONGITUD && nuevoY == prevY + 1 && nuevoX == prevX && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX, prevY + 1);
		if (ok == 1)
		{
			return 1; // abajo
		}
	}
	if (prevX - 1 >= 0 && prevY + 1 < LONGITUD && nuevoX == prevX - 1 && nuevoY == prevY + 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX - 1, prevY + 1);
		if (ok == 1)
		{
			return 1; // abajo a la izq.
		}
	}
	if (prevX - 1 >= 0 && nuevoY == prevY && nuevoX == prevX - 1 && tablero[nuevoY][nuevoX] <= 0)
	{
		int ok = verifReyNegroJaque(prevX - 1, prevY);
		if (ok == 1)
		{
			return 1; // izquierda
		}
	}
	// enroque a la derecha
	if (torreNegraDer == 0 && reyNegro == 0 && tablero[0][5] == 0 && tablero[0][6] == 0 && nuevoY == 0 && nuevoX == 6)
	{
		int ok = verifReyNegroJaque(4, 0);
		if (ok == 1)
		{
			ok = verifReyNegroJaque(5, 0);
			if (ok == 1)
			{
				ok = verifReyNegroJaque(6, 0);
				if (ok == 1)
				{
					reyNegro = 1;
					torreNegraDer = 1;
					tablero[0][7] = 0;
					tablero[0][5] = TORRE_NEGRA;
					return 1;
				}
			}
		}
	}
	if (torreNegraIzq == 0 && reyNegro == 0 && tablero[0][3] == 0 && tablero[0][2] == 0 && tablero[0][1] == 0 && nuevoY == 0 && nuevoX == 2)
	{
		int ok = verifReyNegroJaque(4, 0);
		if (ok == 1)
		{
			ok = verifReyNegroJaque(3, 0);
			if (ok == 1)
			{
				ok = verifReyNegroJaque(2, 0);
				if (ok == 1)
				{
					ok = verifReyNegroJaque(1, 0);
					if (ok == 1)
					{
						reyNegro = 1;
						torreNegraIzq = 1;
						tablero[0][0] = 0;
						tablero[0][3] = TORRE_NEGRA;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int verifReyBlancoJaque(int posRegex, int posRegey)
{
	int ok = 0;
	for (int i = 0; i < LONGITUD; i++)
	{
		for (int j = 0; j < LONGITUD; j++)
		{
			if (tablero[i][j] > 0)
			{
				if (tablero[i][j] == PEON_NEGRO)
				{
					ok = jaqueANegroConPeon(j, i, posRegex, posRegey);
				}
				if (tablero[i][j] == TORRE_NEGRA)
				{
					ok = jaqueANegroConTorre(j, i, posRegex, posRegey);
				}
				if (tablero[i][j] == CABALLO_NEGRO)
				{
					ok = jaqueANegroConCaballo(j, i, posRegex, posRegey);
				}
				if (tablero[i][j] == ALFIL_NEGRO)
				{
					ok = jaqueANegroConAlfil(j, i, posRegex, posRegey);
				}
				if (tablero[i][j] == REINA_NEGRA)
				{
					ok = jaqueANegroConReina(j, i, posRegex, posRegey);
				}
				if (tablero[i][j] == REY_NEGRO)
				{
					ok = jaqueANegroConRey(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					//	std::cout << "da" << "\n";
					return 0;
				}
			}
		}
	}
	return 1;
}

int fiReyBlanco(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // arriba a la izq.
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // arriba
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LONGITUD && nx == ox + 1 && ny == oy - 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // arriba der.
		}
	}
	if (ox + 1 < LONGITUD && ny == oy && nx == ox + 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // derecha
		}
	}
	if (ox + 1 < LONGITUD && oy + 1 < LONGITUD && ny == oy + 1 && nx == ox + 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // abajo a la der.
		}
	}
	if (oy + 1 < LONGITUD && ny == oy + 1 && nx == ox && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // abajo
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LONGITUD && nx == ox - 1 && ny == oy + 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // abajo a la izq.
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && tablero[ny][nx] >= 0)
	{
		int ok = verifReyBlancoJaque(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // izquierda
		}
	}
	// enroque a la derecha
	if (reyBlanco == 0 && torreBlancaDer == 0 && tablero[7][5] == 0 && tablero[7][6] == 0 && ny == 7 && nx == 6)
	{
		int ok = 1;
		ok = verifReyBlancoJaque(4, 7);
		if (ok == 1)
		{
			ok = verifReyBlancoJaque(5, 7);
			if (ok == 1)
			{
				ok = verifReyBlancoJaque(6, 7);
				if (ok == 1)
				{
					tablero[7][7] = 0;
					tablero[7][5] = TORRE_BLANCA;
					reyBlanco = 1;
					torreBlancaDer = 1;
					return 1;
				}
			}
		}
	}
	// enroque a la izq
	if (reyBlanco == 0 && torreBlancaDer == 0 && tablero[7][3] == 0 && tablero[7][2] == 0 && tablero[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = verifReyBlancoJaque(4, 7);
		if (ok == 1)
		{
			ok = verifReyBlancoJaque(3, 7);
			if (ok == 1)
			{
				ok = verifReyBlancoJaque(2, 7);
				if (ok == 1)
				{
					ok = verifReyBlancoJaque(1, 7);
					if (ok == 1)
					{
						tablero[7][0] = 0;
						tablero[7][3] = TORRE_BLANCA;
						reyBlanco = 1;
						torreBlancaIzq = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


void copPosReyBlanco()
{
	for (int i = 0; i < LONGITUD; i++)
	{
		for (int j = 0; j < LONGITUD; j++)
		{
			if (tablero[i][j] == REY_BLANCO)
			{
				posReyBlanco.x = j;
				posReyBlanco.y = i;
				break;
			}
		}
	}
}

void copReyNegro()
{
	for (int i = 0; i < LONGITUD; i++)
	{
		for (int j = 0; j < LONGITUD; j++)
		{
			if (tablero[i][j] == REY_NEGRO)
			{
				posReyNegro.y = i;
				posReyNegro.x = j;
				break;
			}
		}
	}
}