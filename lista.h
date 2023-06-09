#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct Pokemon{
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
};
typedef struct descritor Lista;

struct Node{
    struct Pokemon data;
    struct Node* prev;
    struct Node* prox;
};
typedef struct Node Elem;

Lista* criarLista();

void apagaLista(Lista* lista);

bool isListaCheia(Lista* lista);

bool isListaVazia(Lista* lista);

int sizeofLista(Lista* lista);

void imprimeNo(Elem* no);

int adicionarNo(Lista* lista, struct Pokemon pokedex);

int adicionaNoOutraLista(Lista* lista, Lista* time, char* name);

void imprimeLista(Lista* lista);

int getPositionByName(Lista* lista, char* name);

void removeNo(Lista* lista, int position);

void imprimeNoByPosition(Lista* lista, int position);

void imprimeMinMaxTotal(Lista* lista, int caso);

void adicionarNoManual(Lista* lista, int id, char* name, char* type1, char* type2, int total, int hp, int attack, int defense, int sp_atk, int sp_def, int speed, int gen, char* legendary);

#endif // LISTA_H //
