#include "TabP.h"
#include <iostream>

using namespace std;
int secundarimain() {
	int aux[8][8]{
		0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 4, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};
	TabP t;
	t.mejorarMapa(t.vtorre,aux,1,50);

	for (int i = 0; i < N; i++) {
		for (int s = 0; s < N; i++) {
			cout <<t.vtorre[i][s] << " ";
		}
		cout << endl;
	}
	return 0;
}