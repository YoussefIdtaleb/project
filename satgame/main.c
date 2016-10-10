#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
#include"affichage.h"
#include"lecture.h"
#include"jeu.h"



/********************************************* Variables globales **********************************************************************/
/*char* ch;          
char* chRec;        
int nbVar=0;       
int nbClauses=0;    
*/


/**************************************************Main***********************************************************************************/
int main(int argc, char * argv[]){
   
    
    getChaine(argv[1]);
    initialiserTableau(argv[1]);
    
    afficher_table();
    jouer();
    
    return 0;
}
































































































/*char* recup(char* chaine){

    char* res;
    int i=0;
    
    while(chaine[i] != '\0'){
        if(( chaine[i]!=' ' )|| (chaine[i]!= '\t'))
            strcat(res,chaine[i]);
        i++;
    }  
    return res;
}
*/
/***************************************recuperer nbvar et nbclause*******************************************************/

/*void recupnbVarNbClause(char* Ligne) {
  int nbVar=0;
  int nbClause=0;
  
  while((c = getc(file)) != EOF) {                 //recupere un caractere tant quon atteint pas la fin du fichier
    if(c == 'f') {                              //on a passe tous les caracteres inutiles 
      sscanf(Ligne," %d %d ",&nbvar, &nbclauses);//on recupere les 2 int sur la ligne
      return ;
    }
  }
  
  //scanf(chaine,"%d %d,&longueur,&largeur);

  printf("votre fichier n'est pas au bon format !!!");//le fichier n'est pas correct(ne contient pas cnf)
  exit(1);
}
*/


