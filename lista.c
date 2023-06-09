#include "lista.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct descritor{
    struct Node* head;
    struct Node* tail;
    int qtd;
};

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    if(lista != NULL){
        lista->head = NULL;
        lista->tail = NULL;
        lista->qtd = 0;
    }

    return lista;
}

void apagaLista(Lista* lista){
    if(lista != NULL){
        Elem* no;
        while ((lista->head) != NULL){
            no = lista->head;
            lista->head = lista->head->prox;
            free(no);
        }
        free(lista);
    }
}

bool isListaCheia(Lista* lista){
    if(lista->qtd > 1000) return true;
    else return false;
}

bool isListaVazia(Lista* lista){
    if(lista->head == NULL) return true;
    else return false;
}

int sizeofLista(Lista* lista){
    if(lista == NULL) return 0;

    return lista->qtd;
}

void imprimeNo(Elem* no){
    printf("\n");
    printf("id: %d\n",no->data.id);
    printf("Nome: %s\n",no->data.name);
    printf("Tipo 1: %s\n",no->data.type1);
    printf("Tipo 2: %s\n",no->data.type2);
    printf("Total: %d\n",no->data.total);
    printf("Vida: %d\n",no->data.hp);
    printf("Ataque: %d\n",no->data.attack);
    printf("Defesa: %d\n",no->data.defense);
    printf("Ataque Especial: %d\n",no->data.sp_atk);
    printf("Defesa Especial: %d\n",no->data.sp_def);
    printf("Velocidade: %d\n",no->data.speed);
    printf("Geracao: %d\n",no->data.gen);
    printf("Lendario: %s\n",no->data.legendary);
    printf("\n");
}

int adicionarNo(Lista* lista, struct Pokemon pokedex){
    if (lista == NULL) return 0;

    if(isListaCheia(lista)) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL) return 0;
    no->data = pokedex;
    no->prox = lista->head;

    if(lista->head == NULL) lista->tail = no;

    lista->head = no;
    lista->qtd++;

    return 1;
}

int adicionaNoOutraLista(Lista* lista, Lista* time, char* name){
    if (lista == NULL) return 0;
    if (time == NULL) return 0;

    if(isListaCheia(lista)) return 0;
    if(isListaCheia(time)) return 0;

    Elem* no = lista->head;
    Elem* noTime = (Elem*) malloc(sizeof(Elem));

    if(no == NULL) return 0;

    int end;

    if (getPositionByName(lista, name) != -1) end = getPositionByName(lista, name) - 1;
    else {
        printf("Nome incorreto\n");
        return 0;
    }

    for(int i = 0; i < end; i++){
        no = no->prox;
    }

    noTime->data = no->data;
    noTime->prox = time->head;

    if(time->head == NULL) time->tail = noTime;

    time->head = noTime;
    time->qtd++;

    return 1;

}

void imprimeLista(Lista* lista){
    if(lista == NULL || lista->head == NULL)
        return;
    Elem* no = lista->head;
    while(no != NULL){
        imprimeNo(no);
        no = no->prox;
    }
}

int getPositionByName(Lista* lista, char* name) {
    int i = 1;
    Elem *no = lista->head;

    while (no != NULL) {
        if(strcmp(no->data.name, name) == 0) {
            return i;
        }
        i++;
        no = no->prox;
    }

    return -1;
}

void removeNo(Lista* lista, int position) {
    if (lista == NULL) {
        printf("A lista est� vazia.\n");
        return;
    }

    if (position == -1){
        printf("Nome incorreto\n");
        return;
    }

    Elem* no = lista->head;
    Elem* prev = NULL;
    int i = 1;

    if (position == 1) {
        lista->head = no->prox;
        free(no);
        lista->qtd--;
        return;
    }

    while (no != NULL && i < position) {
        prev = no;
        no = no->prox;
        i++;
    }

    if (no == NULL) {
        printf("A posi��o fornecida excede o tamanho da lista.\n");
        return;
    }

    prev->prox = no->prox;
    free(no);
    lista->qtd--;
}

void imprimeNoByPosition(Lista* lista, int position){
    if(lista == NULL || lista->head == NULL) return;

    if(position > sizeofLista(lista)) return;

    if(position < 0) return;

    Elem* no = (Elem*) malloc(sizeof(Elem));

    no = lista->head;

    for(int i = 0; i < position; i++){
        no = no->prox;
    }

    imprimeNo(no);
}

void imprimeMinMaxTotal(Lista* lista, int caso){
    if(lista == NULL || lista->head == NULL) return;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    Elem* noMaior = (Elem*) malloc(sizeof(Elem));
    Elem* noMenor = (Elem*) malloc(sizeof(Elem));

    no = lista->head;

    noMaior = no;
    noMenor = no;

    while(no->prox != NULL){
        if(no->data.total < no->prox->data.total){
            noMaior = no->prox;
        }
        if(no->data.total > no->prox->data.total){
            noMenor = no->prox;
        }
        no = no->prox;
    }

    switch(caso){
    case 1:
        imprimeNo(noMaior);
        break;
    case 2:
        imprimeNo(noMenor);
        break;
    }
}

void adicionarNoManual(Lista* lista, int id, char* name, char* type1, char* type2, int total, int hp, int attack, int defense, int sp_atk, int sp_def, int speed, int gen, char* legendary){
     Elem* novoNo = (Elem*)malloc(sizeof(Elem));

     novoNo->data.id = id;

     strcpy(novoNo->data.name, name);
     strcpy(novoNo->data.type1, type1);
     strcpy(novoNo->data.type2, type2);

     novoNo->data.total = total;
     novoNo->data.hp = hp;
     novoNo->data.attack = attack;
     novoNo->data.defense = defense;
     novoNo->data.sp_atk = sp_atk;
     novoNo->data.sp_def = sp_def;
     novoNo->data.speed = speed;
     novoNo->data.gen = gen;

     strcpy(novoNo->data.legendary, legendary);

     novoNo->prox = NULL;

     if (lista->head == NULL) {
        lista->head = novoNo;
    } else {
        Elem* no = lista->head;
        while (no->prox != NULL) {
            no = no->prox;
        }
        no->prox = novoNo;
    }
    lista->qtd++;
}
