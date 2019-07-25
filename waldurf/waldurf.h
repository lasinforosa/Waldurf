/*
 * waldurf.h- part of the waldurf chess program
 * 24/5/19 Consola 
 *
 * (C) Natalia Pares Vives (natalia@paresvives.net)
 *
 * This file can be freely copied, changed, redistributed, etc. as long as
 * this copyright notice stays intact.
 */


#define VERSION_STRING "Waldurf 0.1"

#define CERT     1
#define FALS     0

#define COLUMNA_0       ((entero64)0x101010101010101)
#define COLUMNA_1       ((entero64)0x202020202020202)
#define COLUMNA_2       ((entero64)0x404040404040404)
#define COLUMNA_3       ((entero64)0x808080808080808)
#define COLUMNA_4       ((entero64)0x1010101010101010)
#define COLUMNA_5       ((entero64)0x2020202020202020)
#define COLUMNA_6       ((entero64)0x4040404040404040)
#define COLUMNA_7       ((entero64)0x8080808080808080)

#define FILA_0          ((entero64)0xff)
#define FILA_1          ((entero64)0xff00)
#define FILA_2          ((entero64)0xff0000)
#define FILA_3          ((entero64)0xff000000)
#define FILA_4          ((entero64)0xff00000000)
#define FILA_5          ((entero64)0xff0000000000)
#define FILA_6          ((entero64)0xff000000000000)
#define FILA_7          ((entero64)0xff00000000000000)

#define REY_B_ENRQ_CORTO    0x0400U
#define REY_B_ENRQ_LARGO    0x0800U
#define REY_N_ENRQ_CORTO    0x1000U
#define REY_N_ENRQ_LARGO    0x2000U

#define MAXMOV                    500

#define INFINITO          32767
#define MAX_PROF            (100+MAX_QUIESCE)
#define MAX_QUIESCE          30

#define ES_NEGRA                  8
#define VACIA                     0
#define PEON_B                    1
#define CABALLO_B                 2
#define ALFIL_B                   3
#define TORRE_B                   4
#define DAMA_B                    5
#define REY_B                     6

#define PEON_N                    7
#define CABALLO_N                 8
#define ALFIL_N                   9
#define TORRE_N                  10
#define DAMA_N                   11
#define REY_N                    12

#define REY_VAL                 5000
#define DAMA_VAL                 950
#define TORRE_VAL                480
#define ALFIL_VAL                300
#define CABALLO_VAL              300
#define PEON_VAL                 100

#define E_CORTO_B                  1
#define E_LARGO_B                  2
#define E_CORTO_N                  4
#define E_LARGO_N                  8
#define ALGUN_ENROQUE            0xf


typedef enum
  {
    A8, B8, C8, D8, E8, F8, G8, H8,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1
  } casillas;

typedef struct
  {
     char tab[64];
     int alpaso;
     int turno;
     int num_jug;

     unsigned short pos_status;    /*
                                    ---------------1     posibilidad de enroque corto blancas
                                    --------------1-          "      "      "   largo   "
                                    -------------1--          "      "      "   corto negras
                                    ------------1---          "      "      "   largo   "
                                    ------XXXXXX----     casilla de posible captura al paso
                                    -----1----------     rey blanco enrocado corto
                                    ----1-----------      "    "       "     largo
                                    ---1------------     rey negro enrocado corto
                                    --1-------------      "    "       "    largo
                                 */

     entero64        hash_peones;
     entero64        hash_global;

     entero64 piezascolor[2];
     entero64 *pos_piezas;
     entero64 rotado45;
     entero64 rotado315;
     entero64 rotado90;

     int reyblanco;
     int reynegro;
     int material[2];
     int piezas[2];
     int peones[2];
  } posicion;


typedef struct
{
  entero32 jug;
  long valor;
} list_jug;


typedef struct
  {
    posicion pos;
    int jug_limit;
    int opp_bk_limit, my_bk_limit;
    int rnum_jug, rturno;
    int profmax;
    int time_up;
    int pondering, guessed;
    jugada_ext ponder_mv;
    int rpiezasB, rpiezasN;
    int rmat_diff;
	entero32 time_limit;
    int have_book_move;
    int book_retry;
    int analyzing;

    time_t t_inicio;

    unsigned long egtb_probes, egtb_hits, eval_hits;
    unsigned long nodos_buscados, nodos_quies, nodos_jug_raiz, nodos_control;
    unsigned long last_report, null_cuts;
    unsigned long null_attempts, internal_iter;
    unsigned long hash_hits, hash_used, hash_trys, p_hash_hits, p_hash_trys;

    unsigned long fut_cuts;
    unsigned long first_succ;
    unsigned long beta_cutoffs;
    unsigned long chk_extensions;
    unsigned long moreland_extensions;
    unsigned long recap_extensions;
    unsigned long evals;
    unsigned long lazy_evals;

    list_jug jug_stack[MOV_STACK_SIZE];
    list_jug *max_stack[MAX_PROF];

    unsigned int jug_hash[MAX_PROF];
    
    historial hist[MAXMOV];

    killer_type killer[MAX_PROF][2];
    char jaque[MAX_PROF];
    char purge_list[MAX_PROF];
    char proxima_fase[MAX_PROF];
    int extensiones[MAX_PROF];
    int poda[MAX_PROF];
    
    unsigned long history[4096][2];

    int edad;    
    entrada_hash *trans_tab;
    entrada_hash_p *trans_tab_p;
    ecache *eval_cache;
  } partida;

typedef struct {

    char *str;
    int  (*exec)(int argc);

} command_t;

typedef struct {

    int ncommands;
    const command_t *cmnd;

} command_group_t;






