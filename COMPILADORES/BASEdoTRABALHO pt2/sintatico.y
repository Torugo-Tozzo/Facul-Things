%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexico.c"
%}

%token T_PROGRAMA
%token T_INICO
%token T_FIM
%token T_LEIA
%token T_ESCREVA
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ENQTO
%token T_FACA
%token T_FIMENQUANTO
%token T_INTEIRO
%token T_LOGICO
%token T_MAIS
%token T_MENOS
%token T_VEZES
%token T_DIV
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_NAO
%token T_OU
%token T_E
%token T_ATRIBUI
%token T_ABRE
%token T_FECHA
%token T_V
%token T_F
%token T_IDENTIF
%token T_NUMERO

%start programa

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_VEZES T_DIV
%left T_MAIS T_MENOS

%%

programa 
    : cabecalho variaveis 
        { printf("\tAMEM\tx\n"); }
      T_INICO lista_comandos T_FIM
        { printf("\tDMEN\tx\n\tFIMP\n"); }
    ;

cabecalho
    : T_PROGRAMA T_IDENTIF
        { printf("\tINPP\n"); }
    ;

variaveis
    : /*vazio*/
    | declaracao_variaveis;
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;

tipo
    : T_LOGICO
    | T_INTEIRO
    ;

lista_variaveis
    : T_IDENTIF lista_variaveis
    | T_IDENTIF
    ;

lista_comandos
    : /*vazio*/
    | comando lista_comandos
    ;

comando
    : entrada_saida
    | repeticao
    | selecao
    |atribuicao
    ;

entrada_saida
    : leitura
    | escrita
    ;

leitura
    : T_LEIA T_IDENTIF
        { printf("\tLEIA\n\tARZG\tx\n");}
    ;

escrita
    : T_ESCREVA expressao
        { printf("\tESCR\n");}
    ;

repeticao
    : T_ENQTO 
        { printf("Lx\tNADA\n");}
    expressao T_FACA
        { printf("\tDSF\tLy\n");} 
    lista_comandos 
    T_FIMENQUANTO
        { printf("\tDSF\tLx\nLy\tNADA\n");}
    ;

selecao
    : T_SE expressao T_ENTAO
        { printf("\tDSF\tLx\n");}
    lista_comandos T_SENAO
        { printf("\tDSVS\tLy\nLx\tNADA\n");}
    lista_comandos T_FIMSE
        { printf("Ly\tNADA\n");}
    ;

atribuicao
    : T_IDENTIF T_ATRIBUI expressao
        { printf("\tARZG\tx\n");}
    ;

expressao
    : expressao T_MAIS expressao
        { printf("\tMAIS\n");}
    | expressao T_MENOS expressao
        { printf("\tMENOS\n");}
    | expressao T_VEZES expressao
        { printf("\tMULT\n");}
    | expressao T_DIV expressao
        { printf("\tDIVI\n");}
    | expressao T_MAIOR expressao
        { printf("\tCMMA\n");}
    | expressao T_MENOR expressao
        { printf("\tCMME\n");}
    | expressao T_IGUAL expressao
        { printf("\tCMMIG\n");}
    | expressao T_NAO expressao
        { printf("\tNEGA\n");}
    | expressao T_OU expressao
        { printf("\tDISJ\n");}
    | expressao T_E expressao
        { printf("\tCONJ\n");}
    | termo
    ;

termo
    :T_V
        { printf("\tCRCT\n");}
    |T_F
        { printf("\tCRCT\tx\n");}
    |T_IDENTIF
        { printf("\tCRVG\tx\n");}
    |T_NUMERO
        { printf("\tCRVG\tx\n");}
    |T_NAO termo
        { printf("\tNEGA\n");}
    |T_ABRE expressao T_FECHA
    ;
%%

int main() {
yyparse() ;
puts ("prog ok");
}