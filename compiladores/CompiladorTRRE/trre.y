/*Definiciones*/
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int yylex(void); /* <--- cabecera*/        
    /*manejador de errores*/
    void yyerror(char *mensaje){
        printf("ERROR: %s", mensaje);
        exit(0);    
    }
    int entro=0;
    char *  falta = "falta stack";
    FILE *python;
%}
%define api.value.type {char *}
%token SALIDA IMG ROTAR EG NEGATIVO BN IMPORTAR EXPORTAR UBICACIONE UBICACIONS
%% /*gramatica*/
programa: 
;
programa: linea programa
;  
linea: '\n' 
;  
linea: importar '\n'    {
                            //formato: importar "C:/Users/erick/Desktop/1.jpg"
                            entro++;
                            python=fopen("programa.py","w");
                            fprintf(python, "from PIL import Image\n");
                            fprintf(python, "import sys\n");
                            fprintf(python, "import numpy as np\n");
                            fprintf(python, "entrada = %s \n", $1);
                            fprintf(python, "try:\n");
                            fprintf(python, "\timg0 = Image.open(entrada)\n") ;                          
                            fprintf(python, "except:\n");
                            fprintf(python, "\tprint(\"no se puedo cargar la imagen\")\n");
                            fprintf(python, "\tsys.exit(1)\n");
                            fprintf(python, "tam = (1000, 1000)\n");
                            fprintf(python, "img = img0.copy()\n");
                            fprintf(python, "img.thumbnail(tam)\n");      
                            fprintf(python, "img1 = img.copy()\n");      
                        }
;
linea: funcion '\n'  { }
;
linea: exportar '\n'    {
                            fprintf(python, "salida = %s \n", $1);
                            fprintf(python, "if len(salida)==0:\n");
                            fprintf(python, "\timg1.save(\"trre.jpg\", \"JPEG\")\n");
                            fprintf(python, "else:\n");
                            fprintf(python, "\tsalida = salida + \"/tree.jpg\"\n");
                            fprintf(python, "\timg1.save(salida, \"JPEG\")\n");
                        }
;
linea: SALIDA '\n'      {
                            if(entro!=0)
                            {
                                printf("\n\n\n\n\n\n\n\n\t\t\t-------------------------------------------\n");
                                printf("\t\t\t|         Se ha crado programa.py  :)      |\n");
                                printf("\t\t\t-------------------------------------------\n\n\n\n\n\n\n\n");
                                fclose(python); exit(0);
                            }
                            else{printf("hasta la vsita, baby!"); exit(0);}
                        }
;
importar: IMPORTAR UBICACIONE   {   
                                    $$=$2;
                                }
;
funcion: IMG '.' ROTAR  {
                            fprintf(python, "img1 = img1.rotate(180)\n"); 
                        }
;
funcion: IMG '.' EG     {
                            fprintf(python, "i=0\n"); 
                            fprintf(python, "while i < img1.size[0]:\n"); 
                            fprintf(python, "\tj = 0\n"); 
                            fprintf(python, "\twhile j< img1.size[1]:\n"); 
                            fprintf(python, "\t\tr, g, b = img1.getpixel((i,j))\n"); 
                            fprintf(python, "\t\tg = (r + g + b) / 3\n"); 
                            fprintf(python, "\t\tgris = int(g)\n"); 
                            fprintf(python, "\t\tpixel = tuple([gris, gris, gris])\n"); 
                            fprintf(python, "\t\timg1.putpixel((i,j), pixel)\n"); 
                            fprintf(python, "\t\tj+=1\n"); 
                            fprintf(python, "\ti+=1\n"); 
                        }
;
funcion: IMG '.' NEGATIVO {
                            fprintf(python, "i=0\n"); 
                            fprintf(python, "while i < img1.size[0]:\n"); 
                            fprintf(python, "\tj = 0\n"); 
                            fprintf(python, "\twhile j< img1.size[1]:\n"); 
                            fprintf(python, "\t\tr, g, b = img1.getpixel((i,j))\n"); 
                            fprintf(python, "\t\trn = 255 - r\n"); 
                            fprintf(python, "\t\tgn = 255 - g\n"); 
                            fprintf(python, "\t\tbn = 255 - b\n"); 
                            fprintf(python, "\t\tpixel = tuple([rn, gn, bn])\n"); 
                            fprintf(python, "\t\timg1.putpixel((i,j), pixel)\n"); 
                            fprintf(python, "\t\tj+=1\n"); 
                            fprintf(python, "\ti+=1\n"); 
                        }
;
funcion: IMG '.' BN     {
fprintf(python, "i=0\n"); 
                            fprintf(python, "while i < img1.size[0]:\n"); 
                            fprintf(python, "\tj = 0\n"); 
                            fprintf(python, "\twhile j< img1.size[1]:\n"); 
                            fprintf(python, "\t\tr, g, b = img1.getpixel((i,j))\n"); 
                            fprintf(python, "\t\tgris = (r + g + b) / 3\n"); 
                            fprintf(python, "\t\tif gris < 140:\n"); 
                            fprintf(python, "\t\t\timg1.putpixel((i,j),(0,0,0))\n"); 
                            fprintf(python, "\t\telse:\n"); 
                            fprintf(python, "\t\t\timg1.putpixel((i,j),(255,255,255))\n"); 
                            fprintf(python, "\t\tj+=1\n"); 
                            fprintf(python, "\ti+=1\n"); 
                        }
; 
exportar: EXPORTAR UBICACIONS   {
                                    $$=$2;
                                }
%% /*auxiliares*/
