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

    struct no * prox;
    struct no * prox_id;
}Pokemon;

void criarLista();

void adicionarNo(struct Pokemon**, int, char*, char*, char*, int, int, int, int, int, int, int, int, char*);

bool checkPokemonById(struct Pokemon*, int);

void removerNo(struct Pokemon*);

void imprimirNo(struct Pokemon*);

#endif