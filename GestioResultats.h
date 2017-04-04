#define MAX_MILLORSJUGADORS 5

typedef struct
{
	char Nom[15];
	int puntuacio;
}TipusJugador;

void InicialitzarTaulaMillorJugadors(TipusJugador TMillorsJugadors[]);
int EsMillorPuntuacio(TipusJugador TMillorsJugadors[], int punts);
void DesplacarArray(TipusJugador TMillorsJugadors[], int posicio);
void EmplenarPosicioTaula(TipusJugador &TMillorsJugadors, int punts);
void EscriuRanking(TipusJugador TMillorsJugadors[]);
