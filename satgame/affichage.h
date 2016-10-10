

int cpt;
char* chRec;

/*******************************************initialisation d'un literal****************************************************************/
lit* init_lit(int val, char signe);

/*************************************** relier chaque literal avec le literal qui est en bas  ***************************************/
void relier_literal_bas();


/***********************************************initialisation de la matrice***********************************************************/
void initialiserTableau(char *f);

/*************************************afficher un literal ,on prend en compte l'allignement *******************************************/
void afficher_lit(lit* liter);

/****************************************************** afficher la table **************************************************************/
void afficher_table();
