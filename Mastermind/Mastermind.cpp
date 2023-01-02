#include <iostream>

using namespace std;

int main()
{
	int optionJuego = 0;
	int puntajeCPU = 0;
	int puntajeP1 = 0;

	cout << "Bienvenido a Mastermind!, que desea hacer?" << endl;

	do
	{	
	 
		do
		{
			cout << "1_ Jugar." << endl;
			cout << "2_ Salir." << endl;
			cin >> optionJuego;
			cout << "------------------------------------------------------------------" << endl;

		} while (optionJuego < 1 || optionJuego > 2);
		

		if (optionJuego == 1)
		{

			puntajeP1 = 0;
			puntajeCPU = 0;
			int const tClave = 4;
			int colores = 0;
			int clave[tClave];
			int clave2[tClave];
			int claveJugador[tClave];
			int claveJugador2[tClave];
			int coloresAcertados[tClave];
			int totalDeFallos = 0;
			int totalDeAciertos = 0;
			int intentosRestantes = 10;
			int num = 1;
			

			srand(time(0));

			do
			{
			
				do
				{

						if (intentosRestantes == 0)
						{
							cout << "Sus 10 intentos para encontrar la clave han sido superados. Intentelo de nuevo con una nueva clave." << endl;
							intentosRestantes = 10;
							totalDeAciertos = 0;
							totalDeFallos = 0;
						}
						

						for (int i = 0; i < tClave; i++)
						{
							clave2[i] = 21; //inicializar las variables para 
							claveJugador2[i] = 21; //poder comparararlas
							coloresAcertados[i] = 0;
						}

						for (int i = 0; i < tClave; i++)
						{
							clave[i] = rand() % 8 + 1;

							//la máquina da un número al azar, y se 
							//verifica que no se repitan
							for (int j = 0; j < tClave; j++)
							{
								
								if (clave2[j] == clave[i])
								{
									clave[i] = rand() % 8 + 1;
									j = 0;
								}
								
							}

							clave2[i] = clave[i];
							
						}

						for (int i = 0; i < tClave; i++)
						{

							//que la máquina imprima los colores que eligió para yo 
							//saber cuales son
							switch (clave[i])
							{
							case 1: cout << "Rojo"; break;

							case 2: cout << "Magenta"; break;

							case 3: cout << "Naranja"; break;

							case 4: cout << "Amarillo"; break;

							case 5: cout << "Verde"; break;

							case 6: cout << "Cian"; break;

							case 7: cout << "Azul"; break;

							case 8: cout << "Violeta"; break;
							}

							cout << "|";
						}
						
						cout << "" << endl;

						do
						{
							//averiguar los colores restantes que falten
							if (intentosRestantes != 10)
							{
								if (totalDeAciertos != 0)
								{
									cout << "Felicidades!, tuvo un total de " + totalDeAciertos;
									cout << " aciertos. n/ Los colores acertados fueron: ";

									for (int i = 0; i < totalDeAciertos; i++)
									{
										
										if (coloresAcertados[i] != 0) 
										{
											switch (coloresAcertados[i])
											{
												
											case 1: cout << "Rojo"; break;

											case 2: cout << "Magenta"; break;

											case 3: cout << "Naranja"; break;

											case 4: cout << "Amarillo"; break;

											case 5: cout << "Verde"; break;

											case 6: cout << "Cian"; break;

											case 7: cout << "Azul"; break;

											case 8: cout << "Violeta"; break;
											}
											cout << "|";
										}
									}

									cout << "" << endl;

								}
								else
								{
									cout << "No ha acertado ninguna pocisión" << endl;
								}

								cout << "Ahora elija otros colores:" << endl;
								
								for (int i = 0; i < tClave; i++)
								{
									if (coloresAcertados[i] == 0) 
									{
									
										cout << "1. Rojo" << endl;

										cout << "2. Magenta" << endl;

										cout << "3. Naranja" << endl;

										cout << "4. Amarillo" << endl;

										cout << "5. Verde" << endl;

										cout << "6. Cian" << endl;

										cout << "7. Azul" << endl;

										cout << "8. Violeta" << endl;

										cin >> claveJugador[i];

										if (claveJugador[i] < 1 || claveJugador[i] > 8)
										{
											cout << "Ese número no se encuentra en las opciones. Por favor elija un número del 1 al 8." << endl;
											cout << "---------------------------------------------------------------------------------" << endl;
											i--;//restarle uno al contador para que no se guarde
											//el numero de clave erroneo
										}
										else 
										{
											for (int j = 0; j < tClave; j++)
											{
												if (coloresAcertados[j] == claveJugador[i])
												{
													cout << "Ese color ya está elegido. Por favor escoja otro.";
													cout << "---------------------------------------------------------------------------------" << endl;
													i--;
													j = 4;

												}
											}
										}
									}
								}

								intentosRestantes --;

							}
							else
							{
								
								num = 1;

								//averiguar los colores
								for (int i = 0; i < tClave; i++)
								{
									
									cout << "Ingrese el color número " << num;
									cout << " que considere se encuentra en la clave." << endl;

									cout << "1. Rojo" << endl; 

									cout << "2. Magenta" << endl;

									cout << "3. Naranja" << endl;

									cout << "4. Amarillo" << endl;

									cout << "5. Verde" << endl;

									cout << "6. Cian" << endl;

									cout << "7. Azul" << endl;

									cout << "8. Violeta" << endl;

									cin >> claveJugador[i];
									num++;
									

									if (claveJugador[i] < 1 || claveJugador[i] > 8)
									{
										cout << "Ese número no se encuentra en las opciones. Por favor elija un número del 1 al 8." << endl;
										cout << "---------------------------------------------------------------------------------" << endl;
										i--;
										num--;//restarle uno al contador para que no se guarde
										//el numero de clave erroneo
									}
									else
									{
										for (int k = 0; k < tClave; k++)
										{
											if (claveJugador[i] == claveJugador2[k])
											{
												cout << "Ese color ya está elegido.	Por favor escoja otro." << endl;
												cout << "---------------------------------------------------------------------------------" << endl;
												i--;
												num--;
												k = 4;
											}
										}
											
									}

									claveJugador2[i] = claveJugador[i];
									
								}

								intentosRestantes --;
							}
							
							cout << "Su elección fue: ";

							for (int i = 0; i < tClave; i ++)
							{

								switch (claveJugador[i])
								{
								case 1: cout << "Rojo";
									break;

								case 2: cout << "Magenta";
									break;

								case 3: cout << "Naranja";
									break;

								case 4: cout << "Amarillo";
									break;

								case 5: cout << "Verde";
									break;

								case 6: cout << "Cian";
									break;

								case 7: cout << "Azul";
									break;

								case 8: cout << "Violeta";
									break;
								}

								cout << "|";
								
							}

							cout << "" << endl;


							/*chequear que todos los colores sean iguales
							usar la variable coloresAcertados para guardar los colores
							correctos del jugador*/

							for (int i = 0; i < tClave; i++)
							{
								
								for (int j = 0; j < tClave; j++)
								{
									if (claveJugador[i] == clave[j])
									{
										coloresAcertados[i] = claveJugador[i];
										totalDeAciertos++;
										cout << "O";
										cout << "|";
										puntajeP1++;
									}
								}
							}

							//chequear los colores erroneos
							for (int i = 0; i < tClave; i++)
							{
								if (coloresAcertados[i] == 0)
								{
									cout << "X";
									cout << "|";
									puntajeCPU++;
									totalDeFallos++;
								}
								
							}

							cout << "" << endl;

						} while (totalDeAciertos != tClave || intentosRestantes != 0);

				} while (totalDeAciertos != tClave || puntajeCPU < 25 || puntajeP1 < 25);


				

				//averiguar las posiciones
				if (puntajeCPU < 25 || puntajeP1 < 25)
				{
					totalDeAciertos = 0;
					totalDeFallos = 0;
					intentosRestantes = 10;
					int posicion[4];
					int chequeoPosicion[4];
					

					do
					{
					
						if (intentosRestantes != 10) 
						{
							if (totalDeAciertos != 0)
							{
								cout << "Felicidades!, tuvo un total de " + totalDeAciertos;
								cout << " aciertos. r/ Esas pocisiones fueron: Posición número";

								for (int i = 0; i < totalDeAciertos; i++)
								{
									if (posicion [i] != 0)
									{
										cout<<  posicion[i];
										cout << "|";
									
									}									
								}
								
								cout << ""<< endl;
								
								
							}
							else
							{
								cout << "No ha acertado ninguna pocisión" << endl;
							}

							cout << "Ahora elija las pocisiones de los colores que le faltan descubrir, esas son: " << endl;

							
							for (int i = 0; i < totalDeFallos; i++)
							{
								if (posicion[i] == 0)
								{
									switch (claveJugador[i])
									{
									case 1: cout << "Rojo" << endl; break;

									case 2: cout << "Magenta" << endl; break;

									case 3: cout << "Naranja" << endl; break;

									case 4: cout << "Amarillo" << endl; break;

									case 5: cout << "Verde" << endl; break;

									case 6: cout << "Cian" << endl; break;

									case 7: cout << "Azul" << endl; break;

									case 8: cout << "Violeta" << endl; break;
									}
									cout << "Elija una opción del 1 al 4."<< endl;
									cin >> posicion[i];

									//chequear que no se elijan 2 veces la misma pocisión
									//y guardar las pocisiones correctas
									if (posicion[i] < 1 || posicion[i] > 4)
									{
										cout << "Ese número no se encuentra en las opciones. Por favor elija un número del 1 al 4." << endl;
										cout << "---------------------------------------------------------------------------------" << endl;										i--; //restarle uno al contador para que no se guarde el numero
										i--;
									}
									else
									{
										for (int j = 0; j < tClave; j++)
										{
											if (chequeoPosicion[i] == posicion[j])
											{
												cout << "Ya ha escogido esa posición. Por favor elija otra." << endl;
												cout << "---------------------------------------------------------------------------------" << endl;												i--;
												j = 4;
												i--;
											}
										}

									}

									chequeoPosicion[i] = posicion[i];
								}
							
							}
							
						}
						else 
						{
						
							for (int i = 0; i < tClave; i++)
							{

								cout << "Ingrese la pocisión en la que cree se encuentra ubicado el siguiente color" << endl;

								switch (claveJugador[i])
								{
									case 1: cout << "Rojo" << endl; break;

									case 2: cout << "Magenta" << endl; break;

									case 3: cout << "Naranja" << endl; break;

									case 4: cout << "Amarillo" << endl; break;

									case 5: cout << "Verde" << endl; break;

									case 6: cout << "Cian" << endl; break;

									case 7: cout << "Azul" << endl; break;

									case 8: cout << "Violeta" << endl; break;
								}

								cout << "Ingrese una pocisión del 1 al 4." << endl;
								cin >> posicion[i];

								//chequear que no se elijan 2 veces la misma pocisión
								//y guardar las pocisiones correctas
								if (posicion[i] < 1 || posicion[i] > 4)
								{
									cout << "Ese número no se encuentra en las opciones. Por favor elija un número del 1 al 4." << endl;
									cout << "---------------------------------------------------------------------------------" << endl;										i--; //restarle uno al contador para que no se guarde el numero
										//de pocision erroneo
								}
								else
								{
									for (int j = 0; j < tClave; j++)
									{
										if (chequeoPosicion[i] == posicion[j])
										{
											cout << "Ya ha escogido esa posición. Por favor elija otra." << endl;
											cout << "---------------------------------------------------------------------------------" << endl;												i--;
											j = 4;
										}
									}

								}

								chequeoPosicion[i] = posicion[i];
							}

							for (int i = 0; i < tClave; i++)
							{

								cout << "Su elección de las posiciones fue: " + posicion[i];
								cout << ". ";

								switch (claveJugador[i])
								{
									case 1: cout << "Rojo";
										break;

									case 2: cout << "Magenta";
										break;

									case 3: cout << "Naranja";
										break;

									case 4: cout << "Amarillo";
										break;

									case 5: cout << "Verde";
										break;

									case 6: cout << "Cian";
										break;

									case 7: cout << "Azul";
										break;

									case 8: cout << "Violeta";
										break;
								}

								cout << "|";
							}

								cout << "" << endl;

							for (int k = 0; k < tClave; k++)
							{

								if (posicion[k] == clave[k])
								{
									cout << "O";
									cout << "|";
									puntajeP1++;
									totalDeAciertos++;
								}
								else
								{
									cout << "X";
									cout << "|";
									puntajeCPU++;
									posicion[k] = 0;
									totalDeFallos++;
								}

							}

							cout << "" << endl;

							//va afuera porque cuenta un intento 
							intentosRestantes--; //cada elección

						}
						
					}while (intentosRestantes != 0 || totalDeAciertos != tClave || puntajeCPU < 25 || puntajeP1 < 25);

				} 

			}while (puntajeCPU < 25 || puntajeP1 < 25 || intentosRestantes != 0);

			if (puntajeP1 == 25)
			{
				cout << "¡Felicidades! Ha ganado el juego.";
			}
			else
			{
				cout << "Lástima, usted ha perdido el juego. " << endl;
				cout << "¿Desea volver a intentarlo?" << endl;
				
			}
			//limpiar la pantalla acá
		}
		else
		{
			cout << "¡Hasta pronto!";
			return 0;
		}
		
	} while (optionJuego != 2);

}
