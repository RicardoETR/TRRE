%{
  #include "trre.tab.h"
%}
letras  [a-zA-Z0-9]
dospuntos [:]
comillas ["]
diagonal [/]
punto [.]
formato "jpg"|"jpg"|"JPEG"|"jpeg"|"png"|"PNG"
cadena  {letras}({letras})*
espacio [ \t]
img "IMAGEN"|"imagen"|"img"|"IMG"
salir   "salir"|"SALIR"|"exit"|"EXIT"
archivo {cadena}{punto}{formato}
ubicacione {comillas}({letras}{dospuntos}({diagonal}{cadena})*{diagonal})*{archivo}{comillas}
ubicacions ({comillas}{comillas})|({comillas}{letras}{dospuntos}({dospuntos}{cadena})*{diagonal}{comillas})
rotar "rotar"|"ROTAR"|"ROTATE"|"rotate"
escalagrises "EG"|"eg"|"gs"|"GS"
negativo "negativo"|"NEGATIVO"|"negative"|"NEGATIVE"
blanconegro "BN"|"bn"|"bw"|"BW"
importar "importar"|"IMPORTAR"|"import"|"IMPORT"
exportar "exportar"|"EXPORTAR"|"export"|"EXPORT"
%%
[\n] return '\n';
[.] return '.';
{importar}  {
            return IMPORTAR;  
            }
{img} {return IMG;}
{salir} {return SALIDA;}
{ubicacione} {
              yylval=yytext;
              return UBICACIONE;
              }
{ubicacions} {
              yylval=yytext;
              return UBICACIONS;
              }
{rotar} {return ROTAR;}
{escalagrises} {return EG;}
{negativo} {return NEGATIVO;}
{blanconegro} {return BN;}
{exportar} {
            return EXPORTAR; 
            }
%%