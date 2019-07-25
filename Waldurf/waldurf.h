#ifndef WALDURF_H
#define WALDURF_H

// WALDURF_H
/*
 * waldurf.h- part of the waldurf chess program
 * 24/5/19 Consola
 *
 * (C) Natalia Pares Vives (natalia@paresvives.net)
 *
 */


#define REI     1
#define DAMA    2
#define TORRE   3
#define ALFIL   4
#define CAVALL  5
#define PEO     6

#define BUIT    0
#define BLANC   1
#define NEGRE   -1

#define TRUE    1
#define FALSE   0
#define EOF     -1

/*
** ESTRUCTURES DE DADES
*/

typedef struct TipusValor{
    int valor;
    int segur;
} TpValor;

typedef struct TipusJugada{
    int inici;
    int acaba;
    int CorOCapt;
} TpJugada;

typedef struct TipusPosicio{
    int escaquer[64];
    int enrocs;
    int alPas;
    int ply;
    int quiMou;
    double hashPos;
    TpValor valorPos;
    int pecesBlanques[16];
    int pecesNegres[16];
    int colorCasselles[64];
} TpPosicio;

typedef struct TipusLlistaJugades{
    TpJugada jugadaFeta;
    int plyN;
    TpValor valor;
} TpLlistaMovs;


/*
** VARS
*/
int pecesBlanques[16];
int pecesNegres[16];
char nomPeces[] = "KQRBNPkqrbnp";
int colorCasselles [64];
TpPosicio posPPAL;
TpPosicio posCALC;
TpJugada jugada;
TpLlistaMovs Partida[1000];
TpLlistaMovs pseudoJUG[255];

int numPseudoJugades;

int aturarBucle = FALSE;


/*
** de FirstChess
** matriu de movs posibles de cada figura
*/
int movsCavall[8] = {  };



/*  funcions */
void imprimeixEscaquer(void);
void posicioInicial(void);
void entradaJugades(void);
void updatePos (TpPosicio *pPos, TpJugada *pJug);
int generaJugada (TpPosicio *pPosicio, TpLlistaMovs *pPseudoJugades);
int generaCapt(TpPosicio *pPosicio, TpLlistaMovs *pPseudoJugades);
int generaNoCapt(TpPosicio *pPosicio, TpLlistaMovs *pPseudoJugades);


#endif
