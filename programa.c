#include "lista.h"
#include "lista.c"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*XXX*/

int main() {

    FILE * file = fopen ("pokemon.csv", "r");
    if (! file ) {
        printf (" Erro ao abrir o arquivo .\n");
        return 1;
    }

    struct Pokemon pokedex[1000];

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
    Lista *lista = criarLista();

    for(i = records-1; i >= 0; i--){
        adicionarNo(lista, pokedex[i]);
    }
    free(pokedex);
    /*--------------------*/

    Lista* time = criarLista();

    while(1){
        int op;
        printf("Gerencie seus Pokemons:\n\n");
        printf("Ver Equipe - 1\n");
        printf("Adicionar Pokemon - 2\n");
        printf("Remover pokemon - 3\n");
        printf("Limpar sua Equipe - 4\n");
        printf("Checar mais forte - 5\n");
        printf("Checar mais forte - 6\n");
        printf("Crie seu Pokemon - 7\n");
        printf("&@#*&($&@ - 8\n");
        printf("Va para sua Aventura! - 9\n\n");

        scanf("%d", &op);

        printf("\n");

        char nome[50];

        switch(op){
            case 1:
                if(time->qtd == 0){
                    printf("Voce nao tem nenhum Pokemon\n");
                    break;
                }
                imprimeLista(time);
                break;
            case 2:
                if(time->qtd >= 6){
                    printf("Sua equipe esta cheia\n");
                    break;
                }
                printf("Digite o nome do Pokemon: ");
                scanf("%s", nome);
                adicionaNoOutraLista(lista, time, nome);
                break;
            case 3:
                if(time->qtd == 0){
                    printf("Voce nao tem nenhum Pokemon\n");
                    break;
                }
                printf("Digite o nome do Pokemon: ");
                scanf("%s", nome);
                removeNo(time, getPositionByName(time, nome));
                break;
            case 4:
                if(time->qtd == 0){
                    printf("Voce nao tem nenhum Pokemon\n");
                    break;
                }
                for(i = 0; i < 6; i++){
                   removeNo(time, 1);
                }
                printf("Equipe limpa\n");
                break;
            case 5:
                if(time->qtd == 0){
                    printf("Voce nao tem nenhum Pokemon\n");
                    break;
                }
                printf("Seu Pokemon mais forte eh: \n");
                imprimeMinMaxTotal(time, 1);
                break;
            case 6:
                if(time->qtd == 0){
                    printf("Voce nao tem nenhum Pokemon\n");
                    break;
                }
                printf("Seu Pokemon mais fraco eh: \n");
                imprimeMinMaxTotal(time, 2);
                break;
            case 7:
                if(time->qtd >= 6){
                    printf("Sua equipe esta cheia\n");
                    break;
                }
                char tipo1[20], tipo2[20];
                int total, hp, attack, defense, sp_atk, sp_def, speed, gen;

                printf("Escreva o nome do seu Pokemon: ");
                scanf("%s", nome);
                printf("\nEscreva os tipos do seu Pokemon(Escreva none para nenhum tipo): ");
                scanf("%s %s", tipo1, tipo2);
                printf("\nEscreva a vida do seu Pokemon: ");
                scanf("%d", &hp);
                printf("\nEscreva os status de ataque, defesa, ataque especial, defesa especial e velocidade do seu Pokemon: ");
                scanf("%d %d %d %d %d", &attack, &defense, &sp_atk, &sp_def, &speed);
                printf("\nEscreva a geracao do seu pokemon: ");
                scanf("%d", &gen);

                total = attack + defense + sp_atk + sp_def + speed;

                adicionarNoManual(time, 0, nome, tipo1, tipo2, total, hp, attack, defense, sp_atk, sp_def, speed, gen, "TRUE");

                printf("Seu Pokemon foi criado\n");

                break;
            case 8:
                if(time->qtd >= 6){
                    removeNo(time, 1);
                }
                adicionarNoManual(time, 152, "Missingno", "Bird", "Normal", 204, 33, 136, 0, 6, 6, 29, 1, "TRUE");
                printf("PoK3m0n Ad1CioNado cOm susucessOO!!@!?\n");
                break;
            case 9:
                printf("\nVoce sai em sua aventura!\n");
                return 0;
            }
        system("pause");
        system("cls");
    }

    return 0;
}
