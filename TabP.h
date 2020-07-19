#pragma once
#define N 8
#include <stdlib.h>
#include <iostream>
class TabP
{
public:
	/*
		Matrices iniciales
	*/


	float vpeon[N][N]{
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 
	1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0, 
	0.5, 0.5, 1.0, 2.5, 2.5, 1.0, 0.5, 0.5, 
	0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0, 
	0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5, 
	0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5, 
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	float vcaballo[N][N]{
   -5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0,
   -4.0,-2.0, 0.0, 0.0, 0.0, 0.0,-2.0,-4.0,
   -3.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0,-3.0,
   -3.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5,-3.0,
   -3.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0.0,-3.0,
   -3.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5,-3.0,
   -4.0,-2.0, 0.0, 0.5, 0.5, 0.0,-2.0,-4.0,
   -5.0,-3.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0 };

	float valfil[N][N]{
	-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0,
	-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-1.0,
	-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0,-1.0,
	-1.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5,-1.0,
	-1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0,-1.0,
	-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,-1.0,
	-1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5,-1.0,
	-2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0 };

	float vtorre[N][N]{
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	float vreina[N][N]{
   -2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0,
   -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-1.0,
   -1.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0,-1.0,
   -0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0,-0.5,
    0.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0,-0.5,
   -1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0,-1.0,
   -1.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,-1.0,
   -2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0, };

	float vrey[N][N]{
   -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0,
   -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0,
   -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0,
   -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0,
   -2.0,-3.0,-3.0,-4.0,-4.0,-3.0,-3.0,-2.0,
   -1.0,-2.0,-2.0,-2.0,-2.0,-2.0,-2.0,-1.0,
	2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0,
	2.0, 3.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0, };
	/*
		fin de matrizes Iniciales
	*/

	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores 
		son de -1 donde como la pieza y +10/vPieza en la posicion original 
	*/
	void clavarpeon(float mPieza[N][N], int x, int y,int vPieza,int color) {
		if (x != 0 && x != N - 1) {
			mPieza[y + color][x+1] -= 1.0; //derecha
			mPieza[y + color][x-1] -= 1.0; //izquierda
		}
		else {
			if (x == 0) {
				mPieza[y + color][(x + 1)] -= 1.0;
			}
			if (x == N - 1) {
				mPieza[y + color][x - 1] -= 1.0;
			}
		}
		mPieza[y][x] += (10.0 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +50/vPieza en la posicion original
	*/
	void clavarTorre(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		for (int i = x; i < N; i++) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 1.0;
				}
				else {
					mPieza[y][i] -= 1.0;
					break;
				}
			}
		}
		for (int i = x; i >= 0; i--) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -=  1.0;
				}
				else {
					mPieza[y][i] -= 1.0;
					break;
				}
			}
		}
		for (int i = y; i < N; i++) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 1.0;
				}
				else {
					mPieza[i][x] -= 1.0;
					break;
				}
			}
		}
		for (int i = y; i < N; i--) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 1.0;
				}
				else {
					mPieza[i][x] -= 1.0;
					break;
				}
			}
		}
		mPieza[y][x] +=  (50 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +30/vPieza en la posicion original
	*/
	void clavarCaballo(float mPieza[N][N], int x, int y, int vPieza) {
		if (y - 2 >= 0) {
			if(x + 1 < N)
				mPieza[y - 2][x + 1] -= 1.0;
			if (x - 1 >= 0)
				mPieza[y - 2][x - 1] -= 1.0;
		}

		if (x + 2 < N) {
			if(y+1<N)
				mPieza[y + 1][x + 2] -= 1.0;
			if(y-1>0)
				mPieza[y - 1][x + 2] -= 1.0;
		}
		if (x - 2 > 0 ) {
			if(y+1<N)
				mPieza[y + 1][x - 2] -= 1.0;
			if(y-1>0)
				mPieza[y - 1][x - 2] -= 1.0;
		}
		if (y + 2 < N) {
			if(x+1<N)
				mPieza[y + 2][x + 1] -= 1.0;
			if(x-1>0)
				mPieza[y + 2][x - 1] -= 1.0;
		}
		mPieza[y][x] += (30/(float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +30/vPieza en la posicion original
	*/
	void clavarAlfil(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		int s = x;
		for (int i = y; i < N; i++) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i < N; i++) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s--;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s--;
		}
		mPieza[y][x] += (30/(float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +90/vPieza en la posicion original
	*/
	void clavarReina(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		for (int i = x; i < N; i++) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 1.0;
				}
				else {
					mPieza[y][i] -= 1.0;
					break;
				}
			}
		}
		for (int i = x; i >= 0; i--) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 1.0;
				}
				else {
					mPieza[y][i] -= 1.0;
					break;
				}
			}
		}
		for (int i = y; i < N; i++) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 1.0;
				}
				else {
					mPieza[i][x] -= 1.0;
					break;
				}
			}
		}
		for (int i = y; i < N; i--) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 1.0;
				}
				else {
					mPieza[i][x] -= 1.0;
					break;
				}
			}
		}
		int s = x;
		for (int i = y; i < N; i++) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i < N; i++) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s--;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 1.0;
				}
				else {
					mPieza[i][s] -= 1.0;
					break;
				}
			}
			s--;
		}
		mPieza[y][x] += (90 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +900/vPieza en la posicion original
	*/
	void clavarRey(float mPieza[N][N], int x, int y, int vPieza) {
		if (x + 1 >= 0) {
			mPieza[y][x + 1] -= 1.0;
			if(y-1>=0)
				mPieza[y -1][x + 1] -= 1.0;//
		}
		if (x - 1 >= 0) {
			mPieza[y][x - 1] -= 1.0;
			if (y + 1 < N)
				mPieza[y + 1][x - 1] -= 1.0;
		}
		if (y + 1 >= 0) {
			mPieza[y+1][x] -= 1.0;
			if(x+1<N)
				mPieza[y + 1][x+1] -= 1.0;
		}
		if (y - 1 >= 0) {
			mPieza[y - 1][x] -= 1.0;
			if(x-1>=0)
				mPieza[y - 1][x-1] -= 1.0;
		}
		mPieza[y][x] += (900/(float)vPieza);
	}
	/*
		La funcion genera segun las posiciones de las fichas enemigas un mapa de flotantes donde los valores negativos 
		mPieza=MapadeValores a Mejorar | mJuego=MaparActualDeJuego | color 1=negro -1=blanco | Valor de la pieza en el tablero
	*/
	void mejorarMapa(float mPieza[N][N], int mJuego[N][N],int color,int vPieza) {
		for (int i = 0; i < N; i++) {
			for (int s = 0; s < N; s++) {
				//multiplica la pieza, recordando que en el tablero original -blanco/+negro
				if (mJuego[i][s]*color > 0) {
					//tablero[y][x];
					switch (abs(mJuego[i][s])) {
					case 1: {
						clavarpeon(mPieza, s, i, vPieza, color);
						break;
					};
					case 2: {
						clavarTorre(mPieza, s, i, vPieza, mJuego);
						break;
					};
					case 3: {
						clavarCaballo(mPieza, s, i, vPieza);
						break;
					};
					case 4: {
						clavarAlfil(mPieza, s, i, vPieza, mJuego);
						break;
					};
					case 5: {
						clavarReina(mPieza, s, i, vPieza, mJuego);
						break;
					};
					case 6: {
						clavarRey(mPieza, s, i, vPieza);
						break;
					};
					}
				}
			}
		}
	}
	/*
		copia una matriz de 8x8(v) en otra de 8x8(n)
	*/
	void copiarMatriz(float n[N][N], float v[N][N]) {
		for (int i = 0; i < N; i++) 
			for (int s = 0; s < N; s++)
				n[i][s] = v[i][s];
	}

};

