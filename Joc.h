#include "Graphics_Console.h"
#include <stdio.h>	//printf
#include <conio.h>	//_getch
#include <stdlib.h>//funcio rand()
#include <time.h>//utilitzar 'time' en Aleatori()

//=====================================================================
// Inici del taulell respecte la cantonada superior esquerra
#define INICI_X 4
#define INICI_Y 5
//=====================================================================
// Fi del taulell respecte la cantonada superior esquerra
#define FI_X 36
#define FI_Y 25
// Codi del simbol utilitzat com a bloc de disseny de les parets del camp de joc
#define MUR 219 // Codi simbol MUR
#define PILOTA 64 // Codi símbol PILOTA
#define OFFSET 2 // Amplada de la raqueta respecte el punt central
//======================================================================
#define TECLA_ESTESA 224
#define TECLA_ESC 27
#define TECLA_ESQUERRA 75
#define TECLA_DRETA 77
//======================================================================
#define COL_X (FI_X-INICI_X)-1


int Joc(int Nivell);

void Taulell(HANDLE hScreen);
void PintarPunts(int Punts, HANDLE hScreen);
void PintarNivell(int Nivell, HANDLE hScreen);
void PintarVides(int Vides, HANDLE hScreen);
void GameOver(HANDLE hScreen);
void NivellSuperat(HANDLE hScreen);

void InicialitzarJoc(int &RaquetaX, int &PilotaX, int &PilotaY, int &DirX, int &DirY, HANDLE hScreen);

void PintarMur(HANDLE hScreen);
void EsborrarMur(int X, HANDLE hScreen);

void PintarRaqueta(int X, HANDLE hScreen);
void EsborrarRaqueta(int X, HANDLE hScreen);
int MoureRaqueta(int X, int Dir, HANDLE hScreen);

void PintarObjecte(int X, int Y, char Obj, int ColorObj, HANDLE hScreen);
void EsborrarObjecte(int X, int Y, char Obj, HANDLE hScreen);

void PintarPilota(int X, int Y, HANDLE hScreen);
void EsborrarPilota(int X, int Y, HANDLE hScreen);
void MourePilota(int &X, int &Y, int &DirX, int &DirY, HANDLE hScreen);

int LlegirEvent();
void TractarEvent(int tecla, int&X, HANDLE hScreen);

int Aleatori(int min, int max);

void InicialitzarMur(int Mur[]);
int ArribadaMur(int X, int Mur[]);

int Guanyar(int Mur[]);