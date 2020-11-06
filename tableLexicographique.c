#include <stdio.h>
#include <stdlib.>
#include <string.h>
#include "tableLexicographique.h"


// Fonction pour hasher le lexeme en un numero
unsigned int hash(string lexeme)
{
  int n = strlen(lexeme);
  unsigned int hash_value = 0;

  for(int i = 0; i < n; i++)
  {
    hash_value += lexeme[i];
    hash_value = (hash_value * lexeme[i]) % LENGTH;
  }

  return hash_value;
}

// Initialisation a -1 dans la table de hachage
void initialisationHashTable(tableSymbole ts)
{
  for(int i = 0; i < LENGTH; i++)
  {
    ts->hashtable[i] = -1;
  }
}

// Initialisation a -1 dans la table Lexico
void initialisationTableLexico(tableSymbole ts)
{
  for(int i = 0; i < DATA_LENGTH; i++)
  {
    ts->data[i].long = 0;
    ts->data[i].lexeme = NULL;
    ts->data[i].suivant = -1;
  }
}
