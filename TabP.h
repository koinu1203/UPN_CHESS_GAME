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
	1.5, 1.5, 1.5, 2.5, 1.5, 1.5, 1.5, 1.5, 
	1.0, 1.0, 1.5, 1.5, 1.5, 1.0, 1.0, 1.0, 
	0.5, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, 0.5, 
	0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0, 
	0.5,-0.5,-1.0, 0.0, 0.0,-1.0,-0.5, 0.5, 
	0.5, 1.0, 1.0,-2.0,-2.0, 1.0, 1.0, 0.5, 
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

	float vcaballo[N][N]{
   -1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,
   -3.0,-2.0, 0.0, 0.0, 0.0, 0.0,-2.0,-3.0,
   -2.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0,-2.0,
   -2.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5,-2.0,
   -2.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0.0,-2.0,
   -2.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5,-2.0,
   -3.0,-2.0, 0.0, 0.5, 0.5, 0.0,-2.0,-3.0,
   -1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0 };

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
	0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9,
	0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.7, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
   -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,-0.5,
	0.6, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.6 };

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
		son de -1 donde como la pieza y +10/vPieza en la posicion original (mPieza[y][x])
	*/
	void clavarpeon(float mPieza[N][N], int x, int y,int vPieza,int color) {
		if (x != 0 && x != N - 1) {
			mPieza[y + color][x+1] -= -3.0; //derecha
			mPieza[y + color][x-1] -= -3.0; //izquierda
		}
		else {
			if (x == 0) {
				mPieza[y + color][(x + 1)] -= 3.0;
			}
			if (x == N - 1) {
				mPieza[y + color][x - 1] -= 3.0;
			}
		}
		mPieza[y][x] += (10.0 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +50/vPieza en la posicion original(mPieza[y][x])
	*/
	void clavarTorre(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		for (int i = x; i < N; i++) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 2.5;
				}
				else {
					mPieza[y][i] -= 1.5;
					break;
				}
			}
		}
		for (int i = x; i >= 0; i--) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -=  2.5;
				}
				else {
					mPieza[y][i] -= 1.5;
					break;
				}
			}
		}
		for (int i = y; i < N; i++) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 2.5;
				}
				else {
					mPieza[i][x] -= 1.5;
					break;
				}
			}
		}
		for (int i = y; i >=0; i--) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 2.5;
				}
				else {
					mPieza[i][x] -= 1.5;
					break;
				}
			}
		}
		mPieza[y][x] +=  (50 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +30/vPieza en la posicion original(mPieza[y][x])
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
		son de -1 donde como la pieza y +30/vPieza en la posicion original(mPieza[y][x])
	*/
	void clavarAlfil(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		int s = x;
		for (int i = y; i < N; i++) {
			if (i != y&&s<N) {
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
			if (i != y && s>=0) {
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
			if (i != y&& s<N) {
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
			if (i != y && s>=0) {
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
		son de -1 donde como la pieza y +90/vPieza en la posicion original(mPieza[y][x])
	*/
	void clavarReina(float mPieza[N][N], int x, int y, int vPieza, int mJuego[N][N]) {
		for (int i = x; i < N; i++) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 0.5;
				}
				else {
					mPieza[y][i] -= 0.5;
					break;
				}
			}
		}
		for (int i = x; i >= 0; i--) {
			if (x != i) {
				if (mJuego[y][i] == 0) {
					mPieza[y][i] -= 0.5;
				}
				else {
					mPieza[y][i] -= 0.5;
					break;
				}
			}
		}
		for (int i = y; i < N; i++) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 0.5;
				}
				else {
					mPieza[i][x] -= 0.5;
					break;
				}
			}
		}
		for (int i = y; i >= 0; i--) {
			if (y != i) {
				if (mJuego[i][x] == 0) {
					mPieza[i][x] -= 0.5;
				}
				else {
					mPieza[i][x] -= 0.5;
					break;
				}
			}
		}
		int s = x;
		for (int i = y; i < N; i++) {
			if (i != y && s<N) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 0.5;
				}
				else {
					mPieza[i][s] -= 0.5;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i < N; i++) {
			if (i != y && s>=0) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 0.5;
				}
				else {
					mPieza[i][s] -= 0.5;
					break;
				}
			}
			s--;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y && s<N) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 0.5;
				}
				else {
					mPieza[i][s] -= 0.5;
					break;
				}
			}
			s++;
		}
		s = x;
		for (int i = y; i >= 0; i--) {
			if (i != y && s>=0) {
				if (mJuego[i][s] == 0) {
					mPieza[i][s] -= 0.5;
				}
				else {
					mPieza[i][s] -= 0.5;
					break;
				}
			}
			s--;
		}
		mPieza[y][x] += (150 / (float)vPieza);
	}
	/*
		agrega si puede a la matriz mPiezas valores segun la posicion x, y estos valores
		son de -1 donde como la pieza y +900/vPieza en la posicion original(mPieza[y][x])
	*/
	void clavarRey(float mPieza[N][N], int x, int y, int vPieza) {
		if (x + 1 >= 0) {
			mPieza[y][x + 1] -= 1.0;
			if(y-1>=0)
				mPieza[y -1][x + 1] -= 0.5;//
		}
		if (x - 1 >= 0) {
			mPieza[y][x - 1] -= 1.0;
			if (y + 1 < N)
				mPieza[y + 1][x - 1] -= 0.5;
		}
		if (y + 1 >= 0) {
			mPieza[y+1][x] -= 1.0;
			if(x+1<N)
				mPieza[y + 1][x+1] -= 0.5;
		}
		if (y - 1 >= 0) {
			mPieza[y - 1][x] -= 1.0;
			if(x-1>=0)
				mPieza[y - 1][x-1] -= 0.5;
		}
		mPieza[y][x] += (900/(float)vPieza);
	}
	/*
		La funcion genera segun las posiciones de las fichas enemigas un mapa de flotantes donde los valores negativos 
		mPieza=MapadeValores a Mejorar "Recomendable usar una matriz alternativa para no modificar las matrize iniciales" 
		mJuego=MaparActualDeJuego
		color enemigo a registrar posiciones 1=negro -1=blanco
		Valor de la pieza tomada
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
	void copiarMatriz(int n[N][N], int v[N][N]) {
		for (int i = 0; i < N; i++)
			for (int s = 0; s < N; s++)
				n[i][s] = v[i][s];
	}
	void revertirMatriz(float t[N][N]) {
		float temp = 0;
		for (int i = 0; i < N; i++) {
			for (int s = 0; s < N; s++) {
				if (i!=N/2){
					temp = t[i][s];
					t[i][s] = t[N - i - 1][N - s - 1];
					t[N - i - 1][N - s - 1] = temp;
				}
				else {
					break;
				}
			}
			if (i == N/2) {
				break;
			}
		}
	}

	/*
		pieza del tablero de juego valor de -6 a 6 menos 0
		para la tabla de blancos =1 | negro -1
	*/
	float getValor(int mJuego[N][N], int color, int pieza,int x, int y) {
		float temp[N][N];
		
		int vPieza = 0;
		switch (abs(pieza))
		{
		case 1: {vPieza=10; copiarMatriz(temp,vpeon); break; }
		case 2: {vPieza = 50; copiarMatriz(temp, vtorre); break;}
		case 3: {vPieza = 30; copiarMatriz(temp, vcaballo); break; }
		case 4: {vPieza = 30; copiarMatriz(temp, valfil); break; }
		case 5: {vPieza = 90; copiarMatriz(temp, vreina); break; }
		case 6: {vPieza = 900; copiarMatriz(temp, vrey); break; }
		default: 
			break;
		}
		if (color > 0)
			revertirMatriz(temp);
		mejorarMapa(temp, mJuego, color, vPieza);
		return (float)temp[y][x]*(float)vPieza;
	}

};

