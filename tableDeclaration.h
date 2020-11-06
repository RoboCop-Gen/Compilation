#ifndef TABLE_DECLARATION
#define TABLE_DECLARATION

#define LENGTH 5000

typedef char* string;
typedef struct declaration declaration;
typedef struct tableDeclaration tableDeclaration;

typedef enum
{
  NATURE_VIDE,
  NATURE_STRUCTURE,
  NATURE_TABLEAU,
  NATURE_VARIABLE,
  NATURE_PARAMETRE,
  NATURE_PROCEDURE,
  NATURE_FONCTION
} champ_nature;

struct declaration
{
    champ_nature nature;
    int suivant;
    int region;
    int description;
    int exec;
};

struct tableDeclaration
{
  struct declaration tab[LENGTH];
  int taille;
};

#endif
