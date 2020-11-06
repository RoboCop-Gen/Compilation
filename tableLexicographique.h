#ifndef TABLE_LEXICOGRAPHIQUE
#define TABLE_LEXICOGRAPHIQUE

#define LENGTH 32; // Longueur de la table de hashcode 
#define DATA_LENGTH 500;

typedef char* string;
typedef struct tableLexico tableLexico;
typedef struct hashtable hashtable;
typedef struct tableSymbole *tableSymbole;

struct tableLexico
{
  int long; 
  string lexeme;
  int suivant;
};

struct tableSymbole
{
  tableLexico data[DATA_LENGTH]; 
  int hashtable[32];
};

unsigned int hash(string lexeme); // Fonction pour hasher le lexeme en un numero
void initialisationHashTable(tableSymbole ts); // Initialisation a -1 dans la table de hachage
void initialisationTableLexico(tableSymbole ts); // Initialisation a -1 dans la table Lexico

#endif
