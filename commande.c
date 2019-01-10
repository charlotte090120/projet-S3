#include <stdio.h>
#include <stdlib.h>
#include <sting.h>


int main(int argc,char **argv){
    
    printf("nombre d'arguments : %d\n"argc);
    
    for (int i=0 ; i<argc ; i++){
        //argv[i] qui prends chaque argument
        
        if (argv[i]!="-i" || argv[i]!="-d" || argv[i]!="-l" ||argv[i]!="-m" ||argv[i]!="cm" ||argv[i]!="cp" ||argv[i]!="cs" ||argv[i]!="va" || argv[i]!=//fichier text )
        {   printf("erreur : vous avez entré une ou plusieurs balise(s)/paramètre(s) de la balise inconnue");
            exit(EXIT_FAILURE);
            
            }//verif que les balise/param soient valides.
            
        else if ( argv[i]=="-i"){
            if (argv[i]=="-d"){
                printf("erreur : balises incompatibles");
            }
        }
        else if
            
    }
}


// pour atoi : int
// si -i : ensemble de ballots
//si -v : matrice de duels
//-l fichier de log
//-m ce qui suit cest la methode associé
