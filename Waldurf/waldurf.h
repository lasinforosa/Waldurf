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

#define MAX_RCD 8
#define MAX_TA  4
#define MAX_PX  2

const static int MOVS_TORRE [] = {1,12,-1,-12};     //4 MAX_TA
const static int MOVS_ALFIL [] = {-11,13,11,-13};   //4 MAX_TA
const static int MOVS_CAVALL [] = {-23,-10,14,25,23,10,-14,-25};    //8 MAX_RCD
const static int MOVS_PEOB [] = {-24,-12};      //2 MAX_PX
const static int MOVS_PEOB_CAPT [] = {-11,-13}; //2 MAX_PX
const static int MOVS_PEON [] = {24,12};        //2 MAX_PX
const static int MOVS_PEON_CAPT [] = {11,13};   //2 MAX_PX
const static int MOVS_REI [] = {-11,1,13,12,11,-1,-13,-12};         //8 MAX_RCD
const static int MOVS_DAMA  [] = {1,12,-1,-12,-11,13,11,-13};       //8 MAX_RCD
const static int MAX_DESPL = 7;

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
    int corona;
    int figMou;
    int figCapt;
    int plyN;
    TpValor value;
} TpJugada;

typedef struct TipusPosicio{
    int escaquer[144];
    int colorCasselles[64];
    int board[64];
    int pecesBlanques[16];
    int pecesNegres[16];
    int enrocs;
    int alPas;
    int ply;
    int quiMou;
    int rep3jug;
    int reg50jug;
    double hashPos;
    TpValor valorPos;
    TpJugada jugAnterior;
    int alfa, beta, kill;
    TpJugada pseudoJUG[255];

} TpPosicio;


/*
** VARS
*/

char nomPeces[] = "KQRBNPkqrbnp";
TpPosicio posPPAL; posInicial;
TpJugada jugada;
TpJugada Partida[1000];


int numPseudoJugades;

int aturarBucle = FALSE;


/*  funcions */
void imprimeixEscaquer(void);
void posicioInicial(void);
void entradaJugades(void);
void updatePos (TpPosicio *pPos, TpJugada *pJug);
int generaJugada (TpPosicio *pPosicio, TpJugada *pPseudoJugades);
int generaCapt(TpPosicio *pPosicio, TpJugada *pPseudoJugades);
int generaNoCapt(TpPosicio *pPosicio, TpJugada *pPseudoJugades);
TpPosicio posClone (TpPosicio *posPPAL);


#endif
