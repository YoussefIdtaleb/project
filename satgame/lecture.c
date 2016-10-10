#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"lecture.h"


/*********************************************recuperer nbvar et nbclause***************************************************************/

int nbVar=0;       
int nbClauses=0; 

lit** clauses;

int getChaine(char* fichier){  // le fichier qui est dans argv[1]
    
    char c=' ';
    ch =(char*)malloc(sizeof(char) * MAXCHAINE);
    FILE *file=NULL;
    file = fopen(fichier,"r");
    if ( file != NULL ){
    
        while( (fgets (ch,MAXCHAINE,file) ) && ( (*ch=='c') || (*ch=='\n') ));
        if (*ch=='p'){ 
        
            sscanf(ch, "%c %c %c %c %d %d ",&c,&c,&c,&c,&nbVar,&nbClauses);
        
         }
   
        else{printf("Erreur :le fichier ne contient pas le format cnf\n");} 
    } 
    else printf("erreur de lecture de fichier");
    fclose(file);
}



/********************************************recuperer chaque nombre de la matrice********************************************************/


int recupValeur(FILE* file){
   
    int nbre=0;
   
    while(fscanf(file,"%d",&nbre) == 1){              //  on lit toute la matrice 
  
            return nbre;
        } 
    return 0;
}


