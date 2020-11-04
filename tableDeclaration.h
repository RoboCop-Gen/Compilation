#ifndef TABLE_DECLARATION
#define TABLE_DECLARATION

typedef struct tableDeclaration *tableDeclaration; 

struct tableDeclaration
{
    int id;
    char *nature;
    struct tableDeclaration *suivant;
    int region;
    int description;
    int execution;
};

#endif