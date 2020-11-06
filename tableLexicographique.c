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
