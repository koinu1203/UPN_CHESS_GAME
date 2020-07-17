#include <iostream>
#include "IA.h" //libreria donde están todas las funciones 

//las variables empiezan en 'i' para identificar que es el entero, ya que hay 
//otra variable con el mismo nombre pero de tipo 'pos'.
int iTransformBlanco = 0, iTransformNegro = 0;

int main()
{
	RenderWindow ventana(VideoMode(800, 800), "Proyect Glagos (UpN cHeSs GaMe)");
	Image icon;
	icon.loadFromFile("images/icon.png"); //cargar un icono a la ventana
	Vector2u iconSize = icon.getSize();
	ventana.setIcon(iconSize.x, iconSize.y, icon.getPixelsPtr()); //cambiar icono de la ventana
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("images/tablero.png");
	t2.loadFromFile("images/peon_n.png");
	t3.loadFromFile("images/peon_b.png");
	t4.loadFromFile("images/torre_n.png");
	t5.loadFromFile("images/torre_b.png");
	t6.loadFromFile("images/cab_b.png");
	t7.loadFromFile("images/cab_n.png");
	t8.loadFromFile("images/alfil_n.png");
	t9.loadFromFile("images/alfil_b.png");
	t10.loadFromFile("images/reina_b.png");
	t11.loadFromFile("images/reina_n.png");
	t12.loadFromFile("images/rey_n.png");
	t13.loadFromFile("images/rey_b.png");
	t14.loadFromFile("images/reclamar_pieza_b.png");
	t15.loadFromFile("images/reclamar_pieza_n.png");

	Sprite sTabla(t1);
	Sprite sPeonNegro(t2);
	Sprite sPeonBlanco(t3);
	Sprite sTorreNegra(t4);
	Sprite sTorreBlanca(t5);
	Sprite sCaballoBlanco(t6);
	Sprite sCaballoNegro(t7);
	Sprite sAlfilNegro(t8);
	Sprite sAlfilBlanco(t9);
	Sprite sReinaBlanca(t10);
	Sprite sReinaNegra(t11);
	Sprite sReyNegro(t12);
	Sprite sReyBlanco(t13);
	Sprite sReclamo;
	Sprite sOpcionesDeReclamoBlanco(t14);
	Sprite sOpcionesDeReclamoNegro(t15);

	float dx = 0, dy = 0;
	int numPiezaReclamada = 0;

	while (ventana.isOpen())
	{
		Vector2i pos = Mouse::getPosition(ventana);
		x = pos.x / tamanio;
		y = pos.y / tamanio;
		Event e; //evento dentro de la ventana
		while (ventana.pollEvent(e)) //pila de eventros 
		{
			if (e.type == Event::Closed) //si el eventro es de tipo closed cerramos la ventana 
			{
				ventana.close();
			}
			ventana.clear();
			//si el mouse es presionado
			if (e.type == Event::MouseButtonPressed)
			{
				//si el boton izquierdo del mouse es presionado
				if (e.key.code == Mouse::Left)
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "board[y][x]=" << board[y][x] << "\n";
					//std::cout << "\n";
					if (iTransformBlanco == 1)
					{
						if (pos.y >= transformBlanco.y * tamanio && pos.y <= (transformBlanco.y + 1) * tamanio && pos.x >= transformBlanco.x * tamanio && pos.x <= (transformBlanco.x + 1) * tamanio)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								tablero[transformBlanco.y][transformBlanco.x] = TORRE_BLANCA;
								iTransformBlanco = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								tablero[transformBlanco.y][transformBlanco.x] = REINA_BLANCA;
								iTransformBlanco = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								tablero[transformBlanco.y][transformBlanco.x] = CABALLO_BLANCO;
								iTransformBlanco = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								tablero[transformBlanco.y][transformBlanco.x] = ALFIL_BLANCO;
								iTransformBlanco = 0;
							}
							if (iTransformBlanco == 0)
							{
								copReyNegro();
								int h = verifReyNegroJaque(posReyNegro.x, posReyNegro.y);
								if (h == 0)
								{
									jackeNegro = 1;
								}
							}
						}
					}
					if (iTransformNegro == 1)
					{
						if (pos.y >= transformNegro.y * tamanio && pos.y <= (transformNegro.y + 1) * tamanio && pos.x >= transformNegro.x * tamanio && pos.x <= (transformNegro.x + 1) * tamanio)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								tablero[transformNegro.y][transformNegro.x] = TORRE_NEGRA;
								iTransformNegro = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								tablero[transformNegro.y][transformNegro.x] = REINA_NEGRA;
								iTransformNegro = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								tablero[transformNegro.y][transformNegro.x] = CABALLO_NEGRO;
								iTransformNegro = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								tablero[transformNegro.y][transformNegro.x] = ALFIL_NEGRO;
								iTransformNegro = 0;
							}
							if (iTransformNegro == 0)
							{
								copPosReyBlanco();
								int h = verifReyBlancoJaque(posReyBlanco.x, posReyBlanco.y);
								if (h == 0)
								{
									jackeBlanco = 1;
								}
							}
						}
					}
					if (tablero[y][x] != 0) //si el espacion en el tablero contiene una pieza | turno 1=negro, 0=blanco 
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						//turno de blancas
						if (turno == 0) {
							if (tablero[y][x] == PEON_BLANCO)
							{
								numPiezaReclamada = PEON_BLANCO;
								sReclamo = sPeonBlanco;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == TORRE_BLANCA)
							{
								numPiezaReclamada = TORRE_BLANCA;
								sReclamo = sTorreBlanca;
								tablero[y][x] = 0;

							}
							if (tablero[y][x] == CABALLO_BLANCO)
							{
								numPiezaReclamada = CABALLO_BLANCO;
								sReclamo = sCaballoBlanco;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == ALFIL_BLANCO)
							{
								numPiezaReclamada = ALFIL_BLANCO;
								sReclamo = sAlfilBlanco;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == REINA_BLANCA)
							{
								numPiezaReclamada = REINA_BLANCA;
								sReclamo = sReinaBlanca;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == REY_BLANCO)
							{
								numPiezaReclamada = REY_BLANCO;
								sReclamo = sReyBlanco;
								tablero[y][x] = 0;
							}
						}
						//turno de negras
						if (turno == 1) {
							if (tablero[y][x] == PEON_NEGRO)
							{
								numPiezaReclamada = PEON_NEGRO;
								sReclamo = sPeonNegro;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == TORRE_NEGRA)
							{
								numPiezaReclamada = TORRE_NEGRA;
								sReclamo = sTorreNegra;
								tablero[y][x] = 0;

							}
							if (tablero[y][x] == CABALLO_NEGRO)
							{
								numPiezaReclamada = CABALLO_NEGRO;
								sReclamo = sCaballoNegro;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == ALFIL_NEGRO)
							{
								numPiezaReclamada = ALFIL_NEGRO;
								sReclamo = sAlfilNegro;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == REINA_NEGRA)
							{
								numPiezaReclamada = REINA_NEGRA;
								sReclamo = sReinaNegra;
								tablero[y][x] = 0;
							}
							if (tablero[y][x] == REY_NEGRO)
							{
								numPiezaReclamada = REY_NEGRO;
								sReclamo = sReyNegro;
								tablero[y][x] = 0;
							}
						}

						if (tablero[y][x] == 0)
						{
							movimientos = 1;
							prevPos.x = x;
							prevPos.y = y;
						}
					}
				}
			}
			//si el mouse termina de pulsarse
			if (e.type == Event::MouseButtonReleased)
			{
				//si el boton que termina de pulsarse es el izquierdo
				if (e.key.code == Mouse::Left)
				{
					int ok = 2;
					if (numPiezaReclamada == PEON_BLANCO && movimientos == 1)
					{
						ok = movPeonBlanco(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == PEON_NEGRO && movimientos == 1)
					{
						ok = movPeonNegro(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == TORRE_BLANCA && movimientos == 1)
					{
						ok = movTorreBlanca(prevPos.x, prevPos.y, x, y);
						if (ok == 1 && torreBlancaIzq == 0 && prevPos.y == 7 && prevPos.x == 0)
						{
							torreBlancaIzq = 1;
							//std::cout << turnAlbStanga << "\n";
						}
						if (ok == 1 && torreBlancaDer == 0 && prevPos.y == 7 && prevPos.x == 7)
						{
							torreBlancaDer = 1;
							//std::cout << turnAlbDreapta << "\n";
						}
					}
					if (numPiezaReclamada == TORRE_NEGRA && movimientos == 1)
					{
						ok = movTorreNegra(prevPos.x, prevPos.y, x, y);
						if (ok == 1 && torreNegraDer == 0 && prevPos.y == 0 && prevPos.x == 7)
						{
							torreNegraDer = 1;
							//std::cout << turnNegruDreapta<< "\n";
						}
						if (ok == 1 && torreNegraIzq == 0 && prevPos.y == 0 && prevPos.x == 0)
						{
							torreNegraIzq = 1;
							//std::cout << turnNegruStanga << "\n";
						}
					}
					if (numPiezaReclamada == ALFIL_BLANCO && movimientos == 1)
					{
						ok = movAlfilBlanco(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == ALFIL_NEGRO && movimientos == 1)
					{
						ok = movAlfilNegro(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == REINA_BLANCA && movimientos == 1)
					{
						ok = movReinaBlanca(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == REINA_NEGRA && movimientos == 1)
					{
						ok = movReinaNegra(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == CABALLO_BLANCO && movimientos == 1)
					{
						ok = movCaballoBlanco(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == CABALLO_NEGRO && movimientos == 1)
					{
						ok = movCaballoNegro(prevPos.x, prevPos.y, x, y);
					}
					if (numPiezaReclamada == REY_NEGRO && movimientos == 1)
					{
						ok = fiReyNegro(prevPos.x, prevPos.y, x, y);
						if (ok == 1 && reyNegro == 0)
						{
							reyNegro = 1;
							//	std::cout << regeNegru << "\n";
						}
					}
					if (numPiezaReclamada == REY_BLANCO && movimientos == 1)
					{
						ok = fiReyBlanco(prevPos.x, prevPos.y, x, y);
						if (ok == 1 && reyBlanco == 0)
						{
							reyBlanco = 1;
							//std::cout << "primaMutareREGEalb=" << regeAlb << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = tablero[y][x];
						tablero[y][x] = numPiezaReclamada;
						if (y == 0 && numPiezaReclamada == PEON_BLANCO)
						{
							iTransformBlanco = 1;
							transformBlanco.x = x;
							transformBlanco.y = y;
							tablero[y][x] = 0;
						}
						if (y == 7 && numPiezaReclamada == PEON_NEGRO)
						{
							iTransformNegro = 1;
							transformNegro.x = x;
							transformNegro.y = y;
							tablero[y][x] = 0;
						}
						if (turno == 0) // el blanco se ha movido y el negro sigue
						{
							if (jackeBlanco == 1)
							{
								copPosReyBlanco();
								int s = verifReyBlancoJaque(posReyBlanco.x, posReyBlanco.y);
								if (s == 0)
								{
									tablero[prevPos.y][prevPos.x] = numPiezaReclamada;
									tablero[y][x] = nr;
								}
								else
								{
									jackeBlanco = 0;
									copReyNegro();
									int sah = verifReyNegroJaque(posReyNegro.x, posReyNegro.y);
									if (sah == 0)
									{
										jackeNegro = 1;
									}
									turno = 1;
								}
							}
							else
							{
								copPosReyBlanco();
								int sa = verifReyBlancoJaque(posReyBlanco.x, posReyBlanco.y);
								if (sa == 0)
								{
									tablero[prevPos.y][prevPos.x] = numPiezaReclamada;
									tablero[y][x] = nr;
								}
								else
								{
									copReyNegro();
									int sah = verifReyNegroJaque(posReyNegro.x, posReyNegro.y);
									if (sah == 0)
									{
										jackeNegro = 1;
									}
									turno = 1;
								}
							}
						}
						else // el negro se ha movido y el blanco sigue
						{
							if (jackeNegro == 1)
							{
								copReyNegro();
								int s = verifReyNegroJaque(posReyNegro.x, posReyNegro.y);
								if (s == 0)
								{
									tablero[prevPos.y][prevPos.x] = numPiezaReclamada;
									tablero[y][x] = nr;
								}
								else
								{
									jackeNegro = 0;
									copPosReyBlanco();
									int sah = verifReyBlancoJaque(posReyBlanco.x, posReyBlanco.y);
									if (sah == 0)
									{
										jackeBlanco = 1;
									}
									turno = 0;
								}
							}
							else
							{
								copReyNegro();
								int sa = verifReyNegroJaque(posReyNegro.x, posReyNegro.y);
								if (sa == 0)
								{
									tablero[prevPos.y][prevPos.x] = numPiezaReclamada;
									tablero[y][x] = nr;
								}
								else
								{
									copPosReyBlanco();
									int sah = verifReyBlancoJaque(posReyBlanco.x, posReyBlanco.y);
									if (sah == 0)
									{
										jackeBlanco = 1;
									}
									turno = 0;
								}
							}
						}
					}
					else if (ok == 0)
					{
						tablero[prevPos.y][prevPos.x] = numPiezaReclamada;
					}
					movimientos = 0;
				}
			}
		}
		// borrar y dibujar //
		ventana.clear();
		ventana.draw(sTabla);
		if (iTransformBlanco == 1)
		{
			sOpcionesDeReclamoBlanco.setPosition(transformBlanco.x * tamanio, transformBlanco.y * tamanio);
			ventana.draw(sOpcionesDeReclamoBlanco);
		}
		if (iTransformNegro == 1)
		{
			sOpcionesDeReclamoNegro.setPosition(transformNegro.x * tamanio, transformNegro.y * tamanio);
			ventana.draw(sOpcionesDeReclamoNegro);
		}
		if (movimientos == 1)
		{
			sReclamo.setPosition(pos.x - dx, pos.y - dy);
			ventana.draw(sReclamo);
		}
		for (int i = 0; i < LONGITUD; i++)
		{
			for (int j = 0; j < LONGITUD; j++)
			{

				if (tablero[i][j] != 0)
				{
					if (tablero[i][j] == PEON_NEGRO)
					{
						sPeonNegro.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sPeonNegro);
					}
					if (tablero[i][j] == PEON_BLANCO)
					{
						sPeonBlanco.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sPeonBlanco);
					}
					if (tablero[i][j] == TORRE_NEGRA)
					{
						sTorreNegra.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sTorreNegra);

					}
					if (tablero[i][j] == TORRE_BLANCA)
					{
						sTorreBlanca.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sTorreBlanca);

					}
					if (tablero[i][j] == CABALLO_BLANCO)
					{
						sCaballoBlanco.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sCaballoBlanco);
					}
					if (tablero[i][j] == CABALLO_NEGRO)
					{
						sCaballoNegro.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sCaballoNegro);
					}
					if (tablero[i][j] == ALFIL_NEGRO)
					{
						sAlfilNegro.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sAlfilNegro);
					}
					if (tablero[i][j] == ALFIL_BLANCO)
					{
						sAlfilBlanco.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sAlfilBlanco);
					}
					if (tablero[i][j] == REINA_BLANCA)
					{
						sReinaBlanca.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sReinaBlanca);
					}
					if (tablero[i][j] == REINA_NEGRA)
					{
						sReinaNegra.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sReinaNegra);
					}
					if (tablero[i][j] == REY_NEGRO)
					{
						sReyNegro.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sReyNegro);
					}
					if (tablero[i][j] == REY_BLANCO)
					{
						sReyBlanco.setPosition(j * tamanio, i * tamanio);
						ventana.draw(sReyBlanco);
					}
				}
			}
		}
		ventana.display(); //mostrar ventana
	}
	return 0;
}//holamnudi