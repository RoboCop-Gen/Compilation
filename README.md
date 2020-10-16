# compilation



Vous pouvez compiler avec yacc/bison et lex/flex, ça ne change rien à part le nom des tables.

  - fichier de tables bison.y
  - fichier lex flex.l
  - Makefile

# Si vous avez des erreurs de compilation, dites-le moi!

  - Si vous compilez avec Bison, il faut changer le nom de la table dans lex également.


Pour l'instant ça ne doit retourner rien, tant qu'on a pas créé un fichier de test. ...


### Todos

 >  Il faut deux personnes pour les tables des déclarations et une personne pour les tables lexico, puis une également pour les tables de hashcodes.
 > Décidez donc qui prend quoi.

### Modifications 

 > Enlevé les is dans les procedures, structures et tableaux, laissé le "==" et "enif" à la place des ";" pour la fin de "if", mais rajouté les guimmets  sur les mots clés.
 > Plusieurs test effectués, à rajouter d'autres si vous voulez.



Les extensions peuvent être .l/.lex et .y/.yacc (ça ne change rien non plus)
