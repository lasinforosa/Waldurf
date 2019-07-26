/*
 * waldurf.c - part of the waldurf chess program
 * 2019-05-27 00:28:56
 *
 * (C) Natalia Pares Vives (natalia@paresvives.net)
 *
 * Chess Engine
 * interface with WinBoard, UCI
 */

#include <stdlib.h>
#include <stdio.h>
#include "waldurf.h"


/* STEPS:
** 01: Definir vars, mostrar escaquer a la pantalla ->          FET
** 02: Entrar jugades (c2c4 ENTER),quit ->                      FET
** 03: Generar jugades ->                                       PART
** 04: Valorar jugades / posicio ->                             PENDENT
** 05: Cercar jugades (minimax alfa/beta)->                     PENDENT
** 06: Generar enrocs, alpas,verificar-ho ->                    PENDENT
** 07: Establir posicio->                                       PENDENT
** 08: Mostrar la planilla ->                                   PENDENT
** 09: Control de temps ->                                      PENDENT
** 10: Interface WInboard. UCI->                                PENDENT
** 11: END versio 1 ->                                          PENDENT
*/

/*
** MAIN PROGRAM
*/




int main()
{
    posicioInicial();
    imprimeixEscaquer();
    entradaJugades();

    return 0;
}


/*  FUNCIONS  */
/*  inicia tots els valors */
void posicioInicial(void)
{
    int i=0;
    numPseudoJugades= 0;

    posPPAL.pecesBlanques[0]=61;        posPPAL.pecesBlanques[1]=60;    posPPAL.pecesBlanques[2]=57;
    posPPAL.pecesBlanques[3]=64;        posPPAL.pecesBlanques[4]=59;    posPPAL.pecesBlanques[5]=62;
    posPPAL.pecesBlanques[6]=58;        posPPAL.pecesBlanques[7]=63;    posPPAL.pecesBlanques[8]=49;
    posPPAL.pecesBlanques[9]=50;        posPPAL.pecesBlanques[10]=51;   posPPAL.pecesBlanques[11]=52;
    posPPAL.pecesBlanques[12]=53;       posPPAL.pecesBlanques[13]=54;   posPPAL.pecesBlanques[14]=55;
    posPPAL.pecesBlanques[15]=56;

    posPPAL.pecesNegres[0]=5;           posPPAL.pecesNegres[1]=4;       posPPAL.pecesNegres[2]=1;
    posPPAL.pecesNegres[3]=8;           posPPAL.pecesNegres[4]=3;       posPPAL.pecesNegres[2]=6;
    posPPAL.pecesNegres[6]=2;           posPPAL.pecesNegres[7]=7;       posPPAL.pecesNegres[2]=9;
    posPPAL.pecesNegres[9]=10;          posPPAL.pecesNegres[10]=11;     posPPAL.pecesNegres[2]=12;
    posPPAL.pecesNegres[12]=13;         posPPAL.pecesNegres[13]=14;     posPPAL.pecesNegres[2]=15;
    posPPAL.pecesNegres[15]=16;

    posPPAL.colorCasselles[0]=NEGRE;    posPPAL.colorCasselles[1]=NEGRE;
    posPPAL.colorCasselles[2]=NEGRE;    posPPAL.colorCasselles[3]=NEGRE;
    posPPAL.colorCasselles[4]=NEGRE;    posPPAL.colorCasselles[5]=NEGRE;
    posPPAL.colorCasselles[6]=NEGRE;    posPPAL.colorCasselles[7]=NEGRE;
    posPPAL.colorCasselles[8]=NEGRE;    posPPAL.colorCasselles[9]=NEGRE;
    posPPAL.colorCasselles[10]=NEGRE;   posPPAL.colorCasselles[11]=NEGRE;

    posPPAL.colorCasselles[12]=BUIT;    posPPAL.colorCasselles[13]=BUIT;
    posPPAL.colorCasselles[14]=BUIT;    posPPAL.colorCasselles[15]=BUIT;
    posPPAL.colorCasselles[16]=BUIT;    posPPAL.colorCasselles[17]=BUIT;
    posPPAL.colorCasselles[18]=BUIT;    posPPAL.colorCasselles[19]=BUIT;
    posPPAL.colorCasselles[20]=BUIT;    posPPAL.colorCasselles[21]=BUIT;
    posPPAL.colorCasselles[22]=BUIT;    posPPAL.colorCasselles[23]=BUIT;
    posPPAL.colorCasselles[24]=BUIT;    posPPAL.colorCasselles[25]=BUIT;
    posPPAL.colorCasselles[26]=BUIT;    posPPAL.colorCasselles[27]=BUIT;
    posPPAL.colorCasselles[28]=BUIT;    posPPAL.colorCasselles[29]=BUIT;
    posPPAL.colorCasselles[30]=BUIT;    posPPAL.colorCasselles[31]=BUIT;
    posPPAL.colorCasselles[32]=BUIT;    posPPAL.colorCasselles[33]=BUIT;
    posPPAL.colorCasselles[34]=BUIT;    posPPAL.colorCasselles[35]=BUIT;
    posPPAL.colorCasselles[36]=BUIT;    posPPAL.colorCasselles[37]=BUIT;
    posPPAL.colorCasselles[38]=BUIT;    posPPAL.colorCasselles[39]=BUIT;
    posPPAL.colorCasselles[40]=BUIT;    posPPAL.colorCasselles[41]=BUIT;
    posPPAL.colorCasselles[42]=BUIT;    posPPAL.colorCasselles[43]=BUIT;
    posPPAL.colorCasselles[44]=BUIT;    posPPAL.colorCasselles[45]=BUIT;
    posPPAL.colorCasselles[46]=BUIT;    posPPAL.colorCasselles[47]=BUIT;

    posPPAL.colorCasselles[48]=BLANC;   posPPAL.colorCasselles[49]=BLANC;
    posPPAL.colorCasselles[50]=BLANC;   posPPAL.colorCasselles[51]=BLANC;
    posPPAL.colorCasselles[52]=BLANC;   posPPAL.colorCasselles[53]=BLANC;
    posPPAL.colorCasselles[54]=BLANC;   posPPAL.colorCasselles[55]=BLANC;
    posPPAL.colorCasselles[56]=BLANC;   posPPAL.colorCasselles[57]=BLANC;
    posPPAL.colorCasselles[58]=BLANC;   posPPAL.colorCasselles[59]=BLANC;
    posPPAL.colorCasselles[60]=BLANC;   posPPAL.colorCasselles[61]=BLANC;
    posPPAL.colorCasselles[62]=BLANC;   posPPAL.colorCasselles[63]=BLANC;

    /* situem la posicio inicial */
    for (i=16; i<48; i++) {
        posPPAL.escaquer[0]=BUIT;
    }

        posPPAL.escaquer[0]=-TORRE;             posPPAL.escaquer[1]=-CAVALL;
        posPPAL.escaquer[2]=-ALFIL;             posPPAL.escaquer[3]=-DAMA;
        posPPAL.escaquer[4]=-REI;               posPPAL.escaquer[5]=-ALFIL;
        posPPAL.escaquer[6]=-CAVALL;            posPPAL.escaquer[7]=-TORRE;
        posPPAL.escaquer[8]=-PEO;               posPPAL.escaquer[9]=-PEO;
        posPPAL.escaquer[10]=-PEO;              posPPAL.escaquer[11]=-PEO;
        posPPAL.escaquer[12]=-PEO;              posPPAL.escaquer[13]=-PEO;
        posPPAL.escaquer[14]=-PEO;              posPPAL.escaquer[15]=-PEO;

        posPPAL.escaquer[48]=PEO;               posPPAL.escaquer[49]=PEO;
        posPPAL.escaquer[50]=PEO;               posPPAL.escaquer[51]=PEO;
        posPPAL.escaquer[52]=PEO;               posPPAL.escaquer[53]=PEO;
        posPPAL.escaquer[54]=PEO;               posPPAL.escaquer[55]=PEO;
        posPPAL.escaquer[56]=TORRE;             posPPAL.escaquer[57]=CAVALL;
        posPPAL.escaquer[58]=ALFIL;             posPPAL.escaquer[59]=DAMA;
        posPPAL.escaquer[60]=REI;               posPPAL.escaquer[61]=ALFIL;
        posPPAL.escaquer[62]=CAVALL;            posPPAL.escaquer[63]=TORRE;

        posPPAL.enrocs=11;              /* 1 + 2 + 3 + 5 */
        posPPAL.alPas=0;
        posPPAL.ply=1;
        posPPAL.quiMou= BLANC;
        posPPAL.hashPos=0;
        posPPAL.valorPos.valor=10;            /* valorant tenir la sortida */
        posPPAL.valorPos.segur=100;           /* a ull  */

        numPseudoJugades = generaJugada(&posPPAL, &pseudoJUG);

}


void imprimeixEscaquer(void)
{
    int i;
    int compta=0;

    printf("   +---+---+---+---+---+---+---+---+\n");
    printf("   +");

    for (i=0; i<64; i++) {

        switch (posPPAL.escaquer[i]) {

            case REI:
                printf(" %c +", nomPeces[0]);
                break;
            case -REI:
                printf(" %c +", nomPeces[6]);
                break;
            case DAMA:
                printf(" %c +", nomPeces[1]);
                break;
            case -DAMA:
                printf(" %c +", nomPeces[7]);
                break;
            case TORRE:
                printf(" %c +", nomPeces[2]);
                break;
            case -TORRE:
                printf(" %c +", nomPeces[8]);
                break;
            case ALFIL:
                printf(" %c +", nomPeces[3]);
                break;
            case -ALFIL:
                printf(" %c +", nomPeces[9]);
                break;
            case CAVALL:
                printf(" %c +", nomPeces[4]);
                break;
            case -CAVALL:
                printf(" %c +", nomPeces[10]);
                break;
            case PEO:
                printf(" %c +", nomPeces[5]);
                break;
            case -PEO:
                printf(" %c +", nomPeces[11]);
                break;

            default:
                printf("   +");
                break;
        }

        if (( i&7)==7) {
            compta++;
            printf(" %d",9-compta);
            printf("\n");
            printf("   +---+---+---+---+---+---+---+---+\n");
            printf("   +");
        }
    }

    printf(" a   b   c   d   e   f   g   h   \n");

}


void entradaJugades (void) {

    char s[256];
    int orig, desti;

    printf("\n");
    printf("p: mostra l'escaquer\n");
    printf("x: surt\n");
    printf("Introdueix la teva jugada e2e4 o g1f3 o h7h8D\n");
    printf("ENTRADA DE JUGADES\n");


    for (;;) {

    /* de FirstChess i/o TSCP */
    printf("tu: ");
    if (scanf("%s",s) == EOF)   /*  acaba el programa */
    {
        return;
    }

    if (!strcmp(s, "p")) {
        imprimeixEscaquer();
        continue;
    }

    if (!strcmp(s, "x")) {
        printf("a reveure!\n");
        return;
    }

    /* TSCP */
    if (s[0] < 'a'  ||  s[0] > 'h'  ||
        s[1] < '0'  ||  s[1] > '9'  ||
        s[2] < 'a'  ||  s[2] > 'h'  ||
        s[3] < '0'  ||  s[3] > '9')
        {
            printf("Jugada il·legal\n");
            continue;

        }

    /* FirstChess i TSCP */
    orig = s[0] - 'a';
    orig += 8 * (8 - (s[1] -'0'));
    desti = s[2] - 'a';
    desti += 8 * (8 - (s[3] -'0'));

    printf("\n");
    printf("La teva jugada es: %c%c%c%c ",s[0],s[1],s[2],s[3]);
    printf("o %d%d\n",orig,desti);

    jugada.inici= orig;
    jugada.acaba= desti;
    jugada.corona=0;
    /* reste elements Jugada */


    /* genera pseudoJugades */
    numPseudoJugades = generaJugada(&posPPAL, &pseudoJUG[0]);
    updatePos(&posPPAL,&jugada);
    printf("Nombre de pseudo jugades = %d \n",numPseudoJugades);
    imprimeixEscaquer();

    } /* del for */
}



void updatePos(TpPosicio *pPos, TpJugada *pJug) {

    pPos->escaquer[pJug->acaba]=pPos->escaquer[pJug->inici];
    pPos->escaquer[pJug->inici]=BUIT;
    pPos->ply++;
    pPos->quiMou=pPos->quiMou*NEGRE;
    /*
        enrocs, alPas, hashPos i valorPos  -> PENDENT
    */

    /* actualitzem els registres de posPPAL */
    if (pPos->quiMou == BLANC) {
        if (pPos->colorCasselles[pJug->acaba] == NEGRE) {
            pPos->pecesNegres[pPos->escaquer[pJug->acaba]] = BUIT;
            pPos->colorCasselles[pJug->acaba] = BUIT;
        }
        pPos->pecesBlanques[pPos->escaquer[pJug->inici]]= pJug->acaba;
    }
    else {
        if (pPos->colorCasselles[pJug->acaba] == BLANC) {
            pPos->pecesBlanques[pPos->escaquer[pJug->acaba]] = BUIT;
            pPos->colorCasselles[pJug->acaba] = BUIT;
        }
        pPos->pecesNegres[pPos->escaquer[pJug->inici]]= pJug->acaba;
    }
    /* canvia el torn de joc */
    pPos->quiMou = pPos->quiMou * NEGRE;
}


/*
** fa i ordena per
** generaCapt
** generaNoCapt
*/

int generaJugada (TpPosicio *pPosicio, TpJugada *pPseudoJugades) {

    int captures = 0;
    int normals = 0;

    captures = generaCapt(&pPosicio, &pPseudoJugades[0]);
    normals = generaNoCapt(&pPosicio, &pPseudoJugades[0]);

    return captures + normals;
}


int generaNoCapt (TpPosicio *pPosicio, TpJugada *pPseudoJugades) {

    int normals = 0;
    int i,j;
    int from =0;
    int to =0;


		int origen;
		int desti;
		int compta;
		int numJugades =0;

		for (int i=0; i<16; i++) {
			origen = pPosicio->pecesNegres[i];

			switch (i) {

				case 0:		/* REI */
					for (int j=0; j<8;  j++) {

							desti = origen + MOVS_REI[j];
							if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
							} else {

								// anota jugada
								numJugades++;
								printf("%3d-%3d\n",origen,desti);
							}

						}
						break;

				case 1:		/* DAMA */
					for (int j=0; j<8;  j++) {
						compta = 1;
						do {
							desti = origen + compta* MOVS_DAMA[j];
							if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
								compta=100;
							} else {

								// anota jugada
								numJugades++;
								printf("%3d-%3d\n",origen,desti);
							}
							compta++;
						} while (compta<=MAX_DESPL);

					}
					break;

				case 2:		/* TORRE */
				case 3:
					for (int j=0; j<4;  j++) {
						compta = 1;
						do {
							desti = origen + compta* MOVS_TORRE[j];
							if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
								compta=100;
							} else {

								// anota jugada
								numJugades++;
								printf("%3d-%3d\n",origen,desti);
							}
							compta++;
						} while (compta<=MAX_DESPL);

					}
					break;

				case 4:
				case 5:
					for (int j=0; j<4;  j++) {
						compta = 1;
						do {
							desti = origen + compta* MOVS_ALFIL[j];
							if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
								compta=100;
							} else {

								// anota jugada
								numJugades++;
								printf("%3d-%3d\n",origen,desti);
							}
							compta++;
						} while (compta<=MAX_DESPL);

					}
					break;

				case 6:		/* CAVALL */
				case 7:
					for (int j=0; j<8;  j++) {

						desti = origen + MOVS_CAVALL[j];
						if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
						} else {

							// anota jugada
							numJugades++;
							printf("%3d-%3d\n",origen,desti);
						}

					}
					break;

				default: /* PEO */
						for (int j=0; j<2;  j++) {

						desti = origen + MOVS_PEON[j];
						if (desti<26 || desti>117 || pPosicio->escaquer[desti]==99 || pPosicio->escaquer[desti]!=0) {
						} else {

							// anota jugada
							numJugades++;
							printf("%3d-%3d\n",origen,desti);
						}

					}
					break;

			} // switch
		} // for

		return numJugades;
	}



int generaCapt (TpPosicio *pPosicio, TpJugada *pPseudoJugades) {

    int captures = 0;

    return captures;
}
