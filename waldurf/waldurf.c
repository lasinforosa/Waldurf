/*
 * waldurf.c - part of the waldurf chess program
 * 24/5/19 Consola 
 *
 * (C) Natalia Pares Vives (natalia@paresvives.net)
 *
 * This file can be freely copied, changed, redistributed, etc. as long as
 * this copyright notice stays intact.
 */

#include <stdlib.h>
#include <stdio.h>
#include "waldurf.h"


int board[10][10];

//----------------------------------------------------------------------------------
void            PosicionInicial()
{
    int             i;
    AlPaso = 64;
    Enroque = E_CORTO_B | E_CORTO_N | E_LARGO_B | E_LARGO_N;
    Turno = 1;

    Tablero[A1] = TORRE_B;
    Tablero[B1] = CABALLO_B;
    Tablero[C1] = ALFIL_B;
    Tablero[D1] = DAMA_B;
    Tablero[E1] = REY_B;
    Tablero[F1] = ALFIL_B;
    Tablero[G1] = CABALLO_B;
    Tablero[H1] = TORRE_B;

    for (i = H2; i > H3; i--)
        Tablero[i] = PEON_B;

    for (i = H3; i > H7; i--)
        Tablero[i] = VACIA;

    for (i = H7; i > H8; i--)
        Tablero[i] = PEON_N;

    Tablero[A8] = TORRE_N;
    Tablero[B8] = CABALLO_N;
    Tablero[C8] = ALFIL_N;
    Tablero[D8] = DAMA_N;
    Tablero[E8] = REY_N;
    Tablero[F8] = ALFIL_N;
    Tablero[G8] = CABALLO_N;
    Tablero[H8] = TORRE_N;
}

