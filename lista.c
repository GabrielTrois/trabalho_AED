#include "lista.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Lista* criarLista(){
    return NULL;
}

void adicionarNo(struct Pokemon** head, int id, char* name, char* type1, char* type2, int total, int hp, int attack, int defense, int sp_atk, int sp_def, int speed, int gen, char* legendary){
     struct Pokemon* novoNo = (struct Pokemon*)malloc(sizeof(Pokemon));

     novoNo->id = id;

     strcpy(novoNo->name, name);
     strcpy(novoNo->type1, type1);
     strcpy(novoNo->type2, type2);

     novoNo->total = total;
     novoNo->hp = hp;
     novoNo->attack = attack;
     novoNo->defense = defense;
     novoNo->sp_atk = sp_atk;
     novoNo->sp_def = sp_def;
     novoNo->speed = speed;
     novoNo->gen = gen;

     strcpy(novoNo->legendary, legendary);

     novoNo->prox = NULL;

     if (*head == NULL) {
        *head = novoNo;
    } else {
        struct Pokemon* current = *head;
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = novoNo;
    }
}

bool checkPokemonById(struct Pokemon *lista, int target) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void removerNo(struct Pokemon* head) {

}

void imprimirNo(struct Pokemon* head) {

}
