#include <conio.h>
#include <stdio.h>
#include "Menu.h"
#include "Joc.h"
#include "GestioResultats.h"

#define JUGAR '1'
#define CONFIGURAR '2'
#define PUNTUACIO '3'
#define SORTIR '4'

void main()
{
	TipusJugador TMillorsJugadors[MAX_MILLORSJUGADORS];

	char opcio;
	char nivell = '1';
	int punts = 0;
	int posicio = -1;

	InicialitzarTaulaMillorJugadors(TMillorsJugadors);


	do {

		MenuPrincipal();

		opcio = _getch();

		switch (opcio)
		{
		case JUGAR:
			punts = Joc(nivell-'0');
			posicio = EsMillorPuntuacio(TMillorsJugadors, punts);

			if (posicio >= 0)
			{
				DesplacarArray(TMillorsJugadors, posicio);
				system("cls");
				EmplenarPosicioTaula(TMillorsJugadors[posicio], punts);
			}
			break;
		case CONFIGURAR:
			do {
				MenuNivellDificultat();
				nivell = _getch();
				if ((nivell != '1') && (nivell != '2') && (nivell != '3')) 
				{
					printf("Incorrect option.\n");
					Sleep(200);
				}
			} while ((nivell != '1') && (nivell != '2') && (nivell != '3'));

			break;
		case PUNTUACIO:
			system("cls");
			EscriuRanking(TMillorsJugadors);
			printf("Press any key to go back");
			_getch();
			break;
		}

	} while (opcio != SORTIR);

}