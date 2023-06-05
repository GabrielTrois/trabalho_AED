#include "lista.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE * file = fopen ("pokemon.csv", "r");
    if (! file ) {
        printf (" Erro ao abrir o arquivo .\n");
        return 1;
    }

    Pokemon pokedex [1000];

    //Pokemon* lista = malloc(1000 * sizeof(struct Pokemon));

    struct Pokemon* lista = criarLista();

    int read = 0;
    int records = 0;

    int i;

    do{
        read = fscanf(file,
                            "%d,%50[^,],%20[^,],%20[^,],%d,%d,%d,%d,%d,%d,%d,%d,%6[^\n]",
                            &pokedex[records].id,
                            pokedex[records].name,
                            pokedex[records].type1,
                            pokedex[records].type2,
                            &pokedex[records].total,
                            &pokedex[records].hp,
                            &pokedex[records].attack,
                            &pokedex[records].defense,
                            &pokedex[records].sp_atk,
                            &pokedex[records].sp_def,
                            &pokedex[records].speed,
                            &pokedex[records].gen,
                            pokedex[records].legendary);

        if(read == 13){
            if(strcmp(pokedex[records].type2, "none") == 0) strcpy(pokedex[records].type2, "");
            records++;
        }

        if (read != 13 && !feof(file)){
            printf("Formato de arquivo incorreto.\n");
            return 1;
        }

        if (ferror(file)){
            printf("Erro ao ler o arquivo.\n");
        }

    } while (!feof(file));

    fclose(file);

    /*---------------------------------------------------------------------------------*/

    /*Cria Lista Encadeada*/
    for(i = 0; i < records; i++){
        adicionarNo(&lista, pokedex[i].id, pokedex[i].name, pokedex[i].type1, pokedex[i].type2, pokedex[i].total, pokedex[i].hp, pokedex[i].attack, pokedex[i].defense, pokedex[i].sp_atk, pokedex[i].sp_def, pokedex[i].speed, pokedex[i].gen, pokedex[i].legendary);
    }

    return 0;
}
