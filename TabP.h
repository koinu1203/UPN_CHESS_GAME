#pragma once
#define N 8
#include <stdlib.h>
#include <iostream>
class TabP
{
public:

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
		Mejora el mapa de la pieza mediante el uso del mapa del juego actual
		ambas matrizes son de 8x8
	*/
	void clavarpeon(float mPieza[N][N], int x, int y,int vPieza) {

		if (x != 0 || x != N - 1) {
			mPieza[y - 1][x + 1] -= 1.0;
			mPieza[y - 1][x - 1] -= 1.0; 
		}
		mPieza[y][x] += (10 / vPieza);
	}
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
		mPieza[y][x] = mPieza[y][x] + (50 / vPieza);
	}
	void clavarCaballo(float mPieza[N][N], int x, int y, int vPieza) {
		if (x + 2 < N) {
			mPieza[y + 1][x + 2] -= 1.0;
			mPieza[y - 1][x + 2] -= 1.0;
		}
		if (x - 2 > 0 ) {
			mPieza[y + 1][x - 2] -= 1.0;
			mPieza[y - 1][x - 2] -= 1.0;
		}
		if (y + 2 < N) {
			mPieza[y + 2][x + 1] -= 1.0;
			mPieza[y + 2][x - 1] -= 1.0;
		}
		if (y - 2 >= 0) {
			mPieza[y - 2][x + 1] -= 1.0;
			mPieza[y - 2][x - 1] -= 1.0;
		}
		mPieza[y][x] += (30/vPieza);
	}
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
		mPieza[y][x] += (30/vPieza);
	}
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
		mPieza[y][x] += (90 / vPieza);
	}
	void clavarRey(float mPieza[N][N], int x, int y, int vPieza) {
		if (x + 1 >= 0) {
			mPieza[y][x + 1] -= 1.0;
		}
		if (x - 1 >= 0) {
			mPieza[y][x - 1] -= 1.0;
		}
		if (y + 1 >= 0) {
			mPieza[y+1][x] -= 1.0;
		}
		if (y - 1 >= 0) {
			mPieza[y - 1][x] -= 1.0;
		}
		mPieza[y][x] += (900/vPieza);
	}
	void mejorarMapa(float mPieza[N][N], int mJuego[N][N],int color,int vPieza) {
		for (int i = 0; i < N; i++) {
			for (int s = 0; s < N; s++) {
				if (mJuego[s][i] * color > 0) {
					//tablero[y][x];
					switch (mJuego[s][i] * color) {
					case 1: {
						if (mJuego[s][i]>0) { //negro
							clavarpeon(mPieza, abs(i - N - 1), abs(s - N - 1),vPieza);
						}
						else { //blanco
							clavarpeon(mPieza, i, s, vPieza);
						}
						break;
					};
					case 2: {
						if (mJuego[s][i] > 0) { //negro
							clavarTorre(mPieza, abs(i - N - 1), abs(s - N - 1), vPieza,mJuego);
						}
						else { //blanco
							clavarTorre(mPieza, i, s, vPieza,mJuego);
						}
						break;
					};
					case 3: {
						if (mJuego[s][i] > 0) { //negro
							clavarCaballo(mPieza, abs(i - N - 1), abs(s - N - 1), vPieza);
						}
						else { //blanco
							clavarCaballo(mPieza, i, s, vPieza);
						}
						break;
					};
					case 4: {
						if (mJuego[s][i] > 0) { //negro
							clavarAlfil(mPieza, abs(i - N - 1), abs(s - N - 1), vPieza, mJuego);
						}
						else { //blanco
							clavarAlfil(mPieza, i, s, vPieza, mJuego);
						}
						break;
					};
					case 5: {
						if (mJuego[s][i] > 0) { //negro
							clavarReina(mPieza, abs(i - N - 1), abs(s - N - 1), vPieza, mJuego);
						}
						else { //blanco
							clavarReina(mPieza, i, s, vPieza, mJuego);
						}
						break;
					};
					case 6: {
						if (mJuego[s][i] > 0) { //negro
							clavarRey(mPieza, abs(i - N - 1), abs(s - N - 1), vPieza);
						}
						else { //blanco
							clavarRey(mPieza, i, s, vPieza);
						}
						break;
					};
					}
				}
			}
		}
	}

	void copiarMatriz(float n[N][N], float v[N][N]) {
		for (int i = 0; i < N; i++) 
			for (int s = 0; s < N; s++)
				n[i][s] = v[i][s];
	}

	/*
		Blanco =-1 | Negro =1
	*/
	float valorPieza(int x, int y, int color, int mJuego[N][N], float mvPieza[N][N], int vPieza) {
		float temp[N][N];
		copiarMatriz(temp, mvPieza);
		mejorarMapa(temp, mJuego, color, vPieza);
		if (color > 0) {
			return temp[abs(y - N - 1)][abs(x - N - 1)];
		}
		else {
			return temp[y][x];
		}
	}
};

