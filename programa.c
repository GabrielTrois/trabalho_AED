#include "lista.h"

#include <stdio.h>
#include <stdbool.h>

int main() {

    FILE * file = fopen ("pokemon.csv", "r");
    if (! file ) {
        printf (" Erro ao abrir o arquivo .\n");
        return 1;
    }

    char buffer [ 1000 ];
    Pokemon pokedex [ 1000 ];

    int i = 0;

    fgets ( buffer , sizeof ( buffer ) , file );

    while ( fgets ( buffer , sizeof ( buffer ) , file ) != NULL ) {
        char * id_str , * nome , * tipo1 , * tipo2 , * total_str , * hp_str , * attack_str , *
        defense_str , * sp_atk_str , * sp_def_str , * speed_str , * gen_str , * legend_str ;

        id_str = strtok ( buffer , ",") ;
        nome = strtok ( NULL , ",");
        tipo1 = strtok ( NULL , ",");
        tipo2 = strtok ( NULL , ",");
        total_str = strtok ( NULL , ",") ;
        hp_str = strtok ( NULL , ",") ;
        attack_str = strtok ( NULL , ",");
        defense_str = strtok ( NULL , ",") ;
        sp_atk_str = strtok ( NULL , ",");
        sp_def_str = strtok ( NULL , ",");
        speed_str = strtok ( NULL , ",") ;
        gen_str = strtok ( NULL , ",") ;
        legend_str = strtok ( NULL , ",");

        int id = atoi ( id_str );
        int total = atoi ( total_str ) ;
        int hp = atoi ( hp_str );
        int attack = atoi ( attack_str );
        int defense = atoi ( defense_str );
        int sp_atk = atoi ( sp_atk_str );
        int sp_def = atoi ( sp_def_str );
        int speed = atoi ( speed_str ) ;
        int gen = atoi ( gen_str );

        char* legend;
        if ( strcmp ( legend_str , " False ")) {
            legend = "false" ;
        } else {
            legend = "true" ;
        }

        pokedex [ i ]. name = malloc ( sizeof ( char ) * ( strlen ( nome ) + 1) ) ;
        pokedex [ i ]. type1 = malloc ( sizeof ( char ) * ( strlen ( tipo1 ) + 1) );
        pokedex [ i ]. type2 = malloc ( sizeof ( char ) * ( strlen ( tipo2 ) + 1) );
        pokedex [ i ]. legendary = malloc ( sizeof ( char ) * ( strlen ( legend ) + 1) );
        strcpy ( pokedex [i]. name , nome );
        strcpy ( pokedex [i]. type1 , tipo1 );
        strcpy ( pokedex [i]. type2 , tipo2 != "" ? tipo2 : "s");
        strcpy ( pokedex [i]. legendary , legend );

        pokedex [ i ]. id = id ;
        pokedex [ i ]. total = total ;
        pokedex [ i ]. hp = hp ;
        pokedex [ i ]. attack = attack ;
        pokedex [ i ]. defense = defense ;
        pokedex [ i ]. sp_atk = sp_atk ;
        pokedex [ i ]. sp_def = sp_def ;
        pokedex [ i ]. speed = speed ;
        pokedex [ i ]. gen = gen ;
        imprimeNo (& pokedex [i]) ;
        getchar () ;
        i++;
    }
    fclose(file);

    return 0;
}
