%{
#include "sintatico.h"
char atomo[100];
int nlin = 1;
int yyerror (char *s);
%}

identificador [_a-zA-Z]([a-zA-Z0-9])*
numero [0-9]+
espaco [\t]+
novalinha[\n]

%x coment

%%
programa        return T_PROGRAMA;
inicio          return T_INICO;
fimprograma     return T_FIM;
leia            return T_LEIA;
escreva         return T_ESCREVA;
se              return T_SE;
entao           return T_ENTAO;
senao           return T_SENAO;
fimse           return T_FIMSE;
enquanto        return T_ENQTO;
faca            return T_FACA;
fimenquanto     return T_FIMENQUANTO;

inteiro         return T_INTEIRO;
logico          return T_LOGICO;

"+"             return T_MAIS;
"-"             return T_MENOS;
"*"             return T_VEZES;
"div"           return T_DIV;
">"             return T_MAIOR;
"<"             return T_MENOR;
"="             return T_IGUAL;
"nao"           return T_NAO;
"ou"            return T_OU;
"e"             return T_E;
"<-"            return T_ATRIBUI;

"("             return T_ABRE; 
")"             return T_FECHA;

"V"             return T_V;
"F"             return T_F;

"//".*          ;
"/*"            BEGIN(coment);
<coment>"*/"    BEGIN(INITIAL);
<coment>.       ;
<coment>\n      nlin++;

{identificador}     {strcpy(atomo, yytext); return T_IDENTIF;}
{numero}            {strcpy(atomo, yytext); return T_NUMERO;}
{espaco}            ;
{novalinha}         nlin++;
.                   yyerror("erro lexico");
%%

int yyerror (char * s){
    printf("ERRO ");
    exit(10);
}

int yywrap(){
    return 1;
}

