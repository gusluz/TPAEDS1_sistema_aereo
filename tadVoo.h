typedef struct {
    int vid;
    char hrDecolagem[6], hrPrevPouso[6], aeroportoDecolagem[6], aeroportoPrevPouso[6];
    int pistaDecolagem;
} tadVoo;

void inicializa(tadVoo* voo);
int getVid(tadVoo* voo);
int setVid(tadVoo* voo, int vid);
char* getHrDecolagem(tadVoo* voo);
int setHrDecolagem(tadVoo* voo, char hrDecolagem[]);
char* getHrPrevPouso(tadVoo* voo);
int setHrPrevPouso(tadVoo* voo, char hrPrevPouso[]);
char* getAeroportoDecolagem(tadVoo* voo);
int setAeroportoDecolagem(tadVoo* voo, char aeroportoDecolagem[]);
char* getAeroportoPrevPouso(tadVoo* voo);
int setAeroportoPrevPouso(tadVoo* voo, char aeroportoPrevPouso[]);
int getPistaDecolagem(tadVoo* voo);
int setPistaDecolagem(tadVoo* voo, int pistaDecolagem);
int horasParaMinutos(char *horario);
