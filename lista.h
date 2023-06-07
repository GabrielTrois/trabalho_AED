#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct{
    int id;
    char name[50];
    char type1[20];
    char type2[20];
    int total;
    int hp;
    int attack;
    int defense;
    int sp_atk;
    int sp_def;
    int speed;
    int gen;
    char legendary[5];
}Pokemon;

typedef struct {
    void* data;
    struct no* prev;
    struct no* next;
} no;

typedef struct {
    no* head;
    no* tail;
} Lista;

struct Lista* lista criarLista();

void adicionarNo(struct Pokemon** head, int id, char* nome, char* tipo1, char* tipo2, int total, int hp, int ataque, int defesa, int ataque_sp, int defesa_sp, int velocidade, int ger, char* lendario);

bool checkPokemonById(struct Pokemon* head, int id);

void removerNo(struct Pokemon* head);

void imprimirNo(struct Pokemon* head);

#endif
