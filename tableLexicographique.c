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

// Initialisation a -1 dans la table de hashage
void initialisationHashTable(tableSymbole ts)
{
  for(int i = 0; i < LENGTH; i++)
  {
    ts->hashtable[i] = -1;
  }
}

// Initialisation a -1 dans la table Lexico/ Initialisation a -1 dans la table Lexico et le champ cpt dans la table symbole a 0
void initialisationTable(tableSymbole ts)
{
  ts->cpt = 0;
  for(int i = 0; i < DATA_LENGTH; i++)
  {
    ts->data[i].long = 0;
    ts->data[i].lexeme = NULL;
    ts->data[i].suivant = -1;
  }
}

void stockageTableSymbole(tableSymbole ts, string lexeme)
{
  unsigned int hc = hash(lexeme);
  int n = strlen(lexeme);

  if(ts->cpt != DATA_LENGTH)
  {
    ts->data[ts->cpt].long = n;
    ts->data[ts->cpt].lexeme = lexeme;
  

    if(ts->hashtable[hc] == -1)
    {
      ts->hashtable[hc] = ts->cpt;
    }
    else
    {
      int tmp = ts->hashtable[hc];

      while(ts->data[tmp].suivant != -1)
      {
        tmp = ts->data[tmp].suivant;
      }
      ts->data[tmp].suivant = ts->cpt; 
    }

    ts->cpt++;
  }
  else
  {
    fprintf(stderr, "Table de Symboles pleine\n");
  }
 }
