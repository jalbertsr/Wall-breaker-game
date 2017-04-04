#include "Joc.h"


void Taulell(HANDLE hScreen)
{
	system("cls");
	//PAINT VERTICAL WALL 1

	int i = INICI_Y;

	for (i; i <= FI_Y; i++)
	{
		PintarObjecte(INICI_X, i, MUR, LIGHTGREY, hScreen);
	}

	//PAINT VERTICAL WALL 2

	int j = INICI_Y;

	for (j; j <= FI_Y; j++)
	{
		PintarObjecte(FI_X, j, MUR, LIGHTGREY, hScreen);
	}
	
	//PAINT HORIZONTAL WALL

	int x = INICI_X;

	for (x; x< FI_X; x++)
	{
		PintarObjecte(x, INICI_Y, MUR, LIGHTGREY, hScreen);
	}
}
void PintarPunts(int Punts, HANDLE hScreen)
{
	TextColor(LIGHTGREY, BLACK, hScreen);
	GotoXY(INICI_X + 2, INICI_Y - 4, hScreen);
	printf("Points: %d", Punts);
}
void PintarNivell(int Nivell, HANDLE hScreen)
{
	TextColor(LIGHTGREY, BLACK, hScreen);
	GotoXY(FI_X - 8, INICI_Y - 4, hScreen);
	printf("Level: %d", Nivell);
}
void PintarVides(int Vides, HANDLE hScreen)
{
	TextColor(LIGHTGREY, BLACK, hScreen);
	GotoXY(INICI_X + 2, INICI_Y - 2, hScreen);
	printf("Lives: %d ",Vides);
}
void GameOver(HANDLE hScreen)
{
	//GAME OVER
	TextColor(RED, BLACK, hScreen);
	GotoXY(INICI_X + 12, FI_Y / 1.5, hScreen);
	printf("GAME OVER");

	//AMAGAR SYSTEM PAUSE
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(INICI_X, FI_Y + 2, hScreen);
	system("pause");
}
void NivellSuperat(HANDLE hScreen)
{
	TextColor(LIGHTGREEN, BLACK, hScreen);
	GotoXY(INICI_X + 12, FI_Y / 1.5, hScreen);
	printf("Level complete!");

	TextColor(BLACK, BLACK, hScreen);
	GotoXY(INICI_X, FI_Y + 2, hScreen);
	system("pause");
}

void InicialitzarJoc(int &RaquetaX, int &PilotaX, int &PilotaY, int &DirX, int &DirY, HANDLE hScreen)
{
	RaquetaX = Aleatori(INICI_X + 3, FI_X-3);
	PilotaX = Aleatori(INICI_X + 1, FI_X-1);
	PilotaY = FI_Y - 2;
	/*while (DirY == 0)
	{
		DirY = Aleatori(-1, 1);
	}*/
	DirY = -1;
	DirX = Aleatori(-1, 1);

	PintarRaqueta(RaquetaX, hScreen);
	PintarPilota(PilotaX, PilotaY, hScreen);
}

void PintarMur(HANDLE hScreen) 
{
	int x = INICI_X+1;
	for (x; x < FI_X; x++)
	{
		TextColor(RED, BLACK, hScreen);
		GotoXY(x, INICI_Y+1, hScreen);
		printf("%c", MUR);
	}
}
void PintarRaqueta(int X, HANDLE hScreen) 
{
	int i;
	for (i = X - 2; i <= X + 2; i++)
	{
		PintarObjecte(i, FI_Y, MUR, RED, hScreen);
	}
}
void PintarPilota(int X, int Y, HANDLE hScreen) //dibuixa la pilota
{
	TextColor(GREEN, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", PILOTA);
}
void PintarObjecte(int X, int Y, char Obj, int ColorObj, HANDLE hScreen)
{
	TextColor(ColorObj, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", Obj);
}

int MoureRaqueta(int X, int Dir, HANDLE hScreen)
{
	EsborrarRaqueta(X, hScreen);
	X += Dir;
	PintarRaqueta(X, hScreen);
	return X;
}
void MourePilota(int &X, int &Y, int &DirX, int &DirY, HANDLE hScreen)
{
	EsborrarPilota(X, Y, hScreen);

	if ((X == FI_X - 1) || (X == INICI_X + 1))
	{
		DirX = DirX * -1;
	}

	if (Y == INICI_Y + 1)
	{
		DirY = DirY * -1;
	}

	Y += DirY;
	X += DirX;
	PintarPilota(X, Y, hScreen);
}

void EsborrarObjecte(int X, int Y, char Obj, HANDLE hScreen)
{
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", Obj);
}
void EsborrarPilota(int X, int Y, HANDLE hScreen)
{
	TextColor(BLACK, BLACK, hScreen);
	GotoXY(X, Y, hScreen);
	printf("%c", PILOTA);
}
void EsborrarRaqueta(int X, HANDLE hScreen)
{
	int i;
	for (i = X - 2; i <= X + 2; i++)
	{
		EsborrarObjecte(i, FI_Y, MUR, hScreen);
	}
}
void EsborrarMur(int X, HANDLE hScreen)
{
	int i;
	if((X>INICI_X+1)&&(X<FI_X-1))
	{
		for (i = X; i - 1 <= X + 1; i++)
		{
			EsborrarObjecte(i, INICI_Y + 1, MUR, hScreen);
		}
	}
}

int Aleatori(int min, int max)
{
	int aleatori;
	aleatori = min + rand() % ((max - min) + 1);
	return aleatori;
}

int LlegirEvent()
{
	int tecla = 0;
	tecla = _getch();	
	if (tecla == TECLA_ESTESA)
	{
		tecla = _getch();
	}
	return tecla;
}
void TractarEvent(int tecla, int &X, HANDLE hScreen)
{
	if ((X-3 > INICI_X)&&(tecla == TECLA_ESQUERRA))
	{
		X = MoureRaqueta(X, -1, hScreen);
	}
	if ((X+3 < FI_X)&&(tecla == TECLA_DRETA))
	{
		X = MoureRaqueta(X, 1, hScreen);
	}
}
 
void InicialitzarMur(int Mur[])
{
	int i;
	for (i = 0; i < COL_X; i++)
	{
		Mur[i] = 1;
	}
}
int ArribadaMur(int X, int Mur[])
{
	int punts = 0;
	int posMur = X - (INICI_X + 1);

	punts += Mur[posMur];
	Mur[posMur] = 0;
	
	if (posMur - 1 >= 0)
	{
		punts += Mur[posMur - 1];
		Mur[posMur - 1] = 0;
	}
	if (posMur + 1 < COL_X)
	{
		punts += Mur[posMur + 1];
		Mur[posMur + 1] = 0;
	}
	return punts;
}

int Guanyar(int Mur[])
{
	int i, sum = 0;
	for (i = 0; i < COL_X; i++)
	{
		sum += Mur[i];
	}
	return sum;
}
int Joc(int Nivell)
{
	HANDLE hScreen;
	int RaquetaX, PilotaX, DirX = 0;
	int PilotaY, DirY = 0;
	int tecla = 0;
	int Vides = 3;
	int Punts = 0;
	int Mur[COL_X];

	srand((unsigned)time(NULL));

	hScreen = GetStdHandle(STD_OUTPUT_HANDLE);
	InitScreen(hScreen);

	Taulell(hScreen);
	PintarPunts(Punts, hScreen);
	PintarNivell(Nivell, hScreen);
	PintarVides(Vides, hScreen);

	int Meta = 0;
	int VelocitatJoc = 8000;
	int contVPilota = VelocitatJoc / Nivell;

	InicialitzarJoc(RaquetaX, PilotaX, PilotaY, DirX, DirY, hScreen);
	PintarMur(hScreen);
	InicialitzarMur(Mur);

	do{
		tecla = 0;
		if (_kbhit())
		{
			tecla = LlegirEvent();
			TractarEvent(tecla, RaquetaX, hScreen);
		}

		contVPilota--;

		if (!contVPilota)
		{
			MourePilota(PilotaX, PilotaY, DirX, DirY, hScreen);
			contVPilota = VelocitatJoc / Nivell;
			if (PilotaY == INICI_Y + 1)
			{
				EsborrarMur(PilotaX, hScreen);
				Punts += ArribadaMur(PilotaX, Mur);
				PintarPunts(Punts, hScreen);
			}
			if (Guanyar(Mur) == 0)
			{
				Punts += 100 * Nivell;
				Nivell++;
				NivellSuperat(hScreen);
				Meta = 1;
			}

			if (PilotaY == FI_Y - 1)
			{
				if ((RaquetaX - 2 <= PilotaX) && (RaquetaX + 2 >= PilotaX))
				{
					DirX = Aleatori(-1, 1);
					DirY *= -1;
				}
				else
				{
					Vides--;
					PintarVides(Vides, hScreen);
					EsborrarRaqueta(RaquetaX, hScreen);
					EsborrarPilota(PilotaX, PilotaY, hScreen);
					InicialitzarJoc(RaquetaX, PilotaX, PilotaY, DirX, DirY, hScreen);
				}
			}
		}
	} while ((tecla != TECLA_ESC) && (Vides > 0) && (!Meta));

	TextColor(LIGHTGREY, BLACK, hScreen);

	if (Vides == 0)
	{
		GameOver(hScreen);
	}

	return Punts;
}