%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int ligne = 1;
int colonne = 1;
%}

%%
program                          {colonne += strlen(yytext); return(PROG);}
\+                               {colonne += strlen(yytext); return(PLUS);}
\-                               {colonne += strlen(yytext); return(MOINS);}
\*                               {colonne += strlen(yytext); return(MULT);}
\/                               {colonne += strlen(yytext); return(DIV);}
\%                               {colonne += strlen(yytext); return(MOD);}
\>                               {colonne += strlen(yytext); return(SUP);}
\>=                              {colonne += strlen(yytext); return(SUP_EGL);}
\<                               {colonne += strlen(yytext); return(INF);}
\<=                              {colonne += strlen(yytext); return(INF_EGL);}
\=                               {colonne += strlen(yytext); return(EGAL);}
\!=                              {colonne += strlen(yytext); return(DIFF);}
\:=                              {colonne += strlen(yytext); return(OPAFF);}
!                                {colonne += strlen(yytext); return(NOT); }
\,                               {colonne += strlen(yytext); return(VIRGULE);}
\;                               {colonne += strlen(yytext); return(POINT_VIRGULE);}
\:                               {colonne += strlen(yytext); return(DEUX_POINTS);}
\.                               {colonne += strlen(yytext); return(POINT);}
\(                               {colonne += strlen(yytext); return(PARENTHESE_OUVRANTE);}
\)                               {colonne += strlen(yytext); return(PARENTHESE_FERMANTE);}
\[                               {colonne += strlen(yytext); return(CROCHET_OUVRANT);}
\]                               {colonne += strlen(yytext); return(CROCHET_FERMANT);}
&&                               {colonne += strlen(yytext); return(AND);}
\|\|                             {colonne += strlen(yytext); return(OR);}
of                               {colonne += strlen(yytext); return(DE);}
is                               {colonne += strlen(yytext); return(EST);}
type                             {colonne += strlen(yytext); return(TYPE);}
var                              {colonne += strlen(yytext); return(VARIABLE);}
int                              {colonne += strlen(yytext); return(ENTIER);}
float                            {colonne += strlen(yytext); return(REEL);}
char                             {colonne += strlen(yytext); return(CARACTERE);}
bool                             {colonne += strlen(yytext); return(BOOLEEN);}
true                             {colonne += strlen(yytext); return(TRUE);}
false                            {colonne += strlen(yytext); return(FALSE);}
null                             {colonne += strlen(yytext); return(VIDE);}
tab                              {colonne += strlen(yytext); return(TABLEAU);}
begin                            {colonne += strlen(yytext); return(DEBUT);}
end                              {colonne += strlen(yytext); return(FIN);}
struct                           {colonne += strlen(yytext); return(STRUCT);}
\end\struct                      {colonne += strlen(yytext); return(FSTRUCT);}
procedure                        {colonne += strlen(yytext); return(PROCEDURE);}
function                         {colonne += strlen(yytext); return(FONCTION);}
return                           {colonne += strlen(yytext); return(RETOURNE);}
if                               {colonne += strlen(yytext); return(SI);}
then                             {colonne += strlen(yytext); return(ALORS);}
else                             {colonne += strlen(yytext); return(SINON);}
while                            {colonne += strlen(yytext); return(TANT_QUE);}
do                               {colonne += strlen(yytext); return(FAIRE);}
0|[1-9][0-9]*                    {colonne += strlen(yytext); return(CSTE_ENTIERE);}
(0|[1-9][0-9]*)\.[0-9]+          {colonne += strlen(yytext); return(CSTE_REELE);}
\'.\'                            {colonne += strlen(yytext); return(CSTE_CARACTERE);}
\[^]*\                           {colonne += strlen(yytext); return(CSTE_CHAINE);}
[a-zA-Z][a-zA-Z0-9]*             {colonne += strlen(yytext); return(IDF);}
\n                               {colonne = 1;  ligne++;}
[[:blank:]]                      {colonne += strlen(yytext);}
\/\/.*                           {}
\/\*([^\*]|\**[^\*\/])*\*+\/     {}
.                                {fprintf(stderr,"Erreur : %s l.%dc.%d\n", yytext, ligne, colonne); exit(-1);}
%%




