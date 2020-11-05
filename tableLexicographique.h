#ifndef TABLE_LEXICOGRAPHIQUE
#define TABLE_LEXICOGRAPHIQUE

#define LENGTH 32; 
#define DATA_LENGTH 500;

typedef char* string;
typedef struct tableLexico *tableLexico;

struct tableLexico
{
  int long; 
  string lexeme;
  int suivant;
}



#endif
