#define TAM 20

struct Node{
    int num;
    struct Node *prox;
};

typedef struct Node fila;

fila* ini();

fila *push(fila *fnl, int num);

fila *pop(fila *inc);

int cheio(int filas);

int vazio(int filas);
