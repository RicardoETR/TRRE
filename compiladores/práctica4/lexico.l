%{
  #include<stdio.h>
%}
palabraReservada        "importar"|"etiqueta"|"exportar"
funciones               "rotar"|"negativo"|"escalagrises"
letra                   [a-zA-Z:] 
cadena                  {letra}({letra})*
jpg                     {letra}({letra})*{punto}{letra}({letra})*
digito                  [0-9]
numero                  {digito}({digito})*
espacio                 [ \t]
igual                   [=]
comillas                ["]
diagonal                [/]
punto                   [.]
abreParentesis          [(]
cieraParentesis         [)]
sumar                   [+] 

%%
{jpg}                   {printf(">>es una imagen jpg\n");}
{palabraReservada}      {printf(">>es una palabra reservada\n");}
{funciones}             {printf(">>es una funcion\n");}
{letra}                 {printf(">>es una letra\n");}
{cadena}({numero}{cadena}|{cadena}{numero})*                {printf(">>es una cadena\n");}
{numero}                {printf(">>es un digito\n");}
{digito}                {printf(">>es un digito\n");}
{espacio}              {printf(">>es un espacio\n");}
{igual}                 {printf(">>es un igual\n");}
{comillas}              {printf(">>comillas\n");}
{diagonal}              {printf(">>es una diagonal\n");}
{punto}                 {printf(">>es un punto\n");}
{abreParentesis}        {printf(">>abre parentesis\n");}
{cieraParentesis}       {printf(">>cierra parentesis\n");}
{sumar}                 {printf(">>es una suma\n");}
{palabraReservada}({espacio})*{igual}({espacio})*{cadena} {printf(">>es una asignacion de etiqueta\n");}
{palabraReservada}({espacio})*{comillas}({cadena}{diagonal})*{jpg}{comillas} {printf(">>importar imagen\n");}
%%




