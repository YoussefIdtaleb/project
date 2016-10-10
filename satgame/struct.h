#include<stdio.h>


#define  NORMAL   printf("\033[0m")
#define  VERT     printf("\033[01;32m")
#define  ROUGE    printf("\033[01;31m")
#define  JAUNE    printf("\033[40;33m")
#define MAXCHAINE 1000


enum couleur {GREEN, RED, WHITE,YELLOW};

struct literal{
    char signe;
    int val;
    enum couleur col;
    struct literal* next;
    struct literal* bas;
};

typedef struct literal lit;

/***************************************** tableau de variable *********************************************************************/

extern lit** tabVariable;


/****** ***************************************** tableau de clauses ******************************************************   */
extern lit** clauses;

