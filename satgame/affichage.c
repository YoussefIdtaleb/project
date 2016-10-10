#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include"struct.h"
#include"lecture.h"
#include"affichage.h"


/*******************************************initialisation d'un literal****************************************************************/
lit* init_lit(int val, char signe){
    lit * _case;
	_case = (lit*)malloc(sizeof(lit));
	_case->val = val;
	_case->signe = signe;
	_case->col = WHITE;
	_case->next = NULL;
	_case->bas=NULL;
	return _case;

}



/*************************************** relier chaque literal avec le literal qui est en bas  ***************************************/

/*
void relier_literal_bas(){
    int j;
    int i;
    lit* actuel;
    lit* oc;
    //tabVariable = (lit **)malloc(sizeof(lit) * cpt);
    for( i=0 ; i < nbClauses-1 ; i++){
        actuel = clauses[i];
        oc = clauses[i+1];
       
        do { 
            actuel->bas = oc;
            actuel = actuel->next;
            oc =  oc->next;
             } while ( (actuel != NULL) && (oc != NULL) );
                
        if ( i == nbClauses-1 ) {
            oc = clauses[i+1] ;
            
            do {
                oc->bas = NULL;
                oc = oc->next; } while( oc != NULL );
        }
    }
    
   
        
        
}

*/
void relier_literal_bas(){
    int j;
    int i;
    lit* actuel;
    lit* oc;
    for( i=0 ; i < nbClauses-1 ; i++){
        actuel = clauses[i];
        oc = clauses[i+1];
       
        do { 
            actuel->bas = oc;
            actuel = actuel->next;
            oc =  oc->next;
             } while ( (actuel != NULL) && (oc != NULL) );
                
        if ( i == nbClauses-1 ) {
            oc = clauses[i+1] ;
            
            do {
                oc->bas = NULL;
                oc = oc->next; } while( oc != NULL );
        }
    }
    
   
        
        
}

/***********************************************initialisation de la matrice***********************************************************/

/*void initialiserTableau(char *f){    // fichier se trouvant dans argv[1]
  
    lit* litActuel;
    lit* litFinal;
    int nbreRecup;
    int i;
    int c;
    FILE *file;
    int tmp;
    
    file = fopen(f,"r");// on ouvre le fichier en lecture
    
    if ( file != NULL) {
        clauses = (lit **)malloc(sizeof(lit) * nbClauses);
        chRec =(char*)malloc(sizeof(char) * MAXCHAINE);
        while ( (fgets(chRec,MAXCHAINE,file))  && (*chRec == 'c') || (*chRec=='\n')) ;
   
            for(i = 0; i < nbClauses; i++) {
                tmp=0;
                litFinal = NULL;
      
                while((nbreRecup=recupValeur(file)) != 0) {
                       
                    if(nbreRecup > 0) {
                        litActuel = init_lit(nbreRecup,'+');  
                    }
        
                    else {
	                    litActuel = init_lit(nbreRecup,'-'); 
                    }
      
                    if(litFinal == NULL) {
	                    clauses[i] = litActuel;
                    }
        
                    else  {
	                    litFinal->next = litActuel;
                    }

                    litFinal= litActuel;
                    tmp++;
            
                }//fin du while
          
            if (cpt < tmp){
            cpt=tmp;
            } 
      }// fin du for
  
  printf("la longueur de la plas grande ligne:%d\n",cpt);
  }// fin du if 
  
  else 
        printf( "erreur de lecture de fichier");
        
  fclose(file);
  
  relier_literal_bas();
}
*/
void initialiserTableau(char *f){   
  
    lit* litActuel;
    lit* litFinal;
    int nbreRecup;
    int i;
    int c;
    FILE *file;
    int tmp;
    
    file = fopen(f,"r");
    
    if ( file != NULL) {
        clauses = (lit **)malloc(sizeof(lit) * nbClauses);
        chRec =(char*)malloc(sizeof(char) * MAXCHAINE);
        while ( (fgets(chRec,MAXCHAINE,file))  && (*chRec == 'c') || (*chRec=='\n')) ;
   
            for(i = 0; i < nbClauses; i++) {
                tmp=0;
                litFinal = NULL;
      
                while((nbreRecup=recupValeur(file)) != 0) {
                       
                    if(nbreRecup > 0) {
                        litActuel = init_lit(nbreRecup,'+');  
                    }
        
                    else {
	                    litActuel = init_lit(nbreRecup,'-'); 
                    }
      
                    if(litFinal == NULL) {
	                    clauses[i] = litActuel;
                    }
        
                    else  {
	                    litFinal->next = litActuel;
                    }

                    litFinal= litActuel;
                    tmp++;
            
                }//fin du while
          
            if (cpt < tmp){
            cpt=tmp;
            } 
      }// fin du for
  
  
  }// fin du if 
  
  else 
        printf( "erreur lors de la  lecture du fichier");
        
  fclose(file);
  
  relier_literal_bas();
}


/************************************ fonction qui retourne la longueur d'un int **************************************************/

int longInt(int entier){
    
    int j=0;
    do{
        entier = entier/10;
        j++;
        } while (entier);
    return j+1;
}





/*************************************afficher un literal ,on prend en compte l'allignement *******************************************/

/*void afficher_lit(lit* liter){
    
	char signe = liter->signe;
	int val = liter->val;
	int lenNbVar = longInt(nbVar); // la longueur  de nbVar 
	int lenNombre = longInt(val);  // la longueur d'un chiffre de la matrice
	int diff = lenNbVar - lenNombre ; // pour alligner à gauche les nombres 
	int i;
	 
 
   if (liter->col == GREEN)
       VERT ;
	else if ( liter->col == RED)
	    ROUGE;
	else if ( liter->col == YELLOW)
	    JAUNE;
	else 
	     NORMAL;
	
	
	if (val > 0 ){
	    signe= '+' ;
	    printf("%c%d",signe,val);  
	   
	}
	
	 
	else { 
	    
	    printf("%d",val);
	    
	    }
	
	    
	        
    if (diff){
        for(  i=0 ; i < diff ; i++ )
           printf(" ");
    }
    
   
}
*/
void afficher_lit(lit* liter){
	char signe = liter->signe;
	int val = liter->val;
	int lenNbVar = longInt(nbVar); // la longueur  de nbVar 
	int lenNombre = longInt(val);  // la longueur d'un chiffre de la matrice
	int diff = lenNbVar - lenNombre ; // pour alligner à gauche les nombres 
	int i;
	 
 
   if (liter->col == GREEN)
       VERT ;
	else if ( liter->col == RED)
	    ROUGE;
	else if ( liter->col == YELLOW)
	    JAUNE;
	else 
	     NORMAL;
	
	
	if (val > 0 ){
	    signe= '+' ;
	    printf("%c%d",signe,val);  
	   
	}
	
	 
	else { 
	    
	    printf("%d",val);
	    
	    }
	
	    
	        
    if (diff){
        for(  i=0 ; i < diff ; i++ )
           printf(" ");
    }
    
   
}




/****************************************************** afficher la table **************************************************************/

/*void afficher_table(){
    
    lit * unliteral;
    int i;
    int j;
    int lenNbVar = longInt(nbVar);
    int v;
    for ( i = 0 ; i < nbClauses ; i++ ){
       
        unliteral = clauses[i] ;
        
        j=0;
        do {
            
            afficher_lit(unliteral);
            printf(" ");
            unliteral = unliteral->next;
            j++;
 
        }while ( unliteral != NULL);
        
        if(j<cpt){
            for(; j < cpt; j++){
                
                for(v=0; v < lenNbVar; v++){
                    printf(" ");
                }
                printf(" ");
            }
        }
        NORMAL;
        printf("| ");
        
        printf("\n"); // pour afficher la clause suivante sur la ligne suivante
   }
   
   printf("\n");
  
  
  
}
*/
void afficher_table(){
    
    lit * unliteral;
    int i;
    int j;
    int lenNbVar = longInt(nbVar);
    int v;
    
    struct winsize w;
    ioctl(0, TIOCGWINSZ,&w);
   // printf("lines %d\n",w.ws_row);
    //printf("columns %d\n",w.ws_col);
     
     
     
     
    int longNbVar=longInt(nbVar);
    int lenClause=cpt*longNbVar+cpt;//longueur d'une clause:nombre de chiffre*la longueur du plus grand chiffre + nbre d'espaces
    
    int cmp=(w.ws_col/lenClause)-1;
        for ( i = 0 ; i < nbClauses; i++ ){
            
            unliteral = clauses[i] ;
            
            j=0;
            do {
                
                afficher_lit(unliteral);
                printf(" ");
                unliteral = unliteral->next;
                j++;
     
            }while ( unliteral != NULL);
            
            if(j<cpt){
                for(; j < cpt; j++){
                    
                    for(v=0; v < lenNbVar; v++){
                        printf(" ");
                    }
                    printf(" ");
                }
            }
            NORMAL;
            printf("| ");
          cmp--;
          if( cmp<=0){
            printf("\n"); // pour afficher la clause suivante sur la ligne suivante
            cmp=(w.ws_col/lenClause)-1;
            }
         }
 
   printf("\n");
  

}
