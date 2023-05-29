#ifndef LISTA_H
#define LISTA_H

typedef struct{
    int id;
    char* name;
    char * type1;
    char * type2;
    int total;
    int hp;
    int attack;
    int defense;
    int sp_atk;
    int sp_def;
    int speed;
    int gen;
    char* legendary;

    struct no * prox;
    struct no * ant;
}Pokemon;

void adicionarNo(struct Pokemon**);

void buscarNo(struct Pokemon*);

void removerNo(struct Pokemon*);

void imprimirNo(struct Pokemon*);

#endif