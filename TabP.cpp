
/*
#include <iostream>
int main() {
	int tablero[8][8] =
	{ 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 9, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, };
	//actTabV();

	int s = 5;
	int i = 5;
	int cont = 0;
	int x = s - 1;
	for (int y = i - 1; y >= 0; y--) // diagonal der. arriba
	{
		if (tablero[y][x] <= 0 && (x < LONGITUD && y < LONGITUD))
		{
			tablero[y][x] = 1;
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
			tablero[y][x] = 2;
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
			tablero[y][x] = 3;
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
			tablero[y][x] = 4;
		}
		else if (tablero[y][x] != 0)
		{
			break;
		}
		x++;
	}


	/////////////////////////////////////////////////
	for (int i = 0; i < N; i++) {
		for (int s = 0; s < N; s++) {
			std::cout << tablero[i][s] << "	  ";
		}
		std::cout << std::endl;
	}
	std::cout << cont << std::endl;

	for (int i = 0; i < LONGITUD; i++) {
		for (int s = 0; s < LONGITUD; s++) {
			if (i == 1 && (s == 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8))
				std::cout << "Soy i: " << i << " - Soy s: " << s << std::endl;
		}
	}
	std::cout << -LONGITUD;
	return 0;
}
*/