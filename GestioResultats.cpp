#include "GestioResultats.h"
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>


void InicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[])
{
	int i;
	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		strcpy(TMillorsJugadors[i].Nom, "--------------");
		TMillorsJugadors[i].puntuacio = 0;
	}
}

int EsMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts)
{
	int i = 0;
	int trobat = 0;

	do{
		if (TMillorsJugadors[i].puntuacio < punts)
		{
			trobat = 1;	
		}
		i++;

	} while ((i < MAX_MILLORSJUGADORS) && (trobat != 1));

	if (trobat == 1)
	{
		return (i - 1);
	}
	else
	{
		return -1;
	}
}

void DesplacarArray(TipusJugador TMillorsJugadors[], int posicio)
{
	int i;
	for	(i = MAX_MILLORSJUGADORS - 1; i > posicio; i--)
	{
		strcpy(TMillorsJugadors[i].Nom,TMillorsJugadors[i-1].Nom);
		TMillorsJugadors[i].puntuacio = TMillorsJugadors[i-1].puntuacio;
	}
}

void EmplenarPosicioTaula(TipusJugador &TMillorsJugadors, int punts)
{
	printf("Enter your nickname: \n");
	fgets(TMillorsJugadors.Nom,15,stdin); //scanf("%s", &TMillorsJugadors.Nom);
	TMillorsJugadors.puntuacio = punts;
}

void EscriuRanking(TipusJugador TMillorsJugadors[])
{
	int i;
	for (i = 0; i < MAX_MILLORSJUGADORS; i++)
	{
		printf("%d.- %s  %d\n", i + 1, TMillorsJugadors[i].Nom, TMillorsJugadors[i].puntuacio );
	}
}
