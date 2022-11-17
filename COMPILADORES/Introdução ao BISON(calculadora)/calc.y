%{
#include "lex.c"
%}

%token NUM
%token MAIS
%token MENOS
%token ENTER
%token VEZES

%start comando

%left MAIS MENOS VEZES

%%
comando : expr ENTER { printf("resultado = %d\n" , $1);};

expr : NUM              { $$ = $1;}
    | expr MAIS expr    {$$ = $1 + $3;}
    | expr MENOS expr   {$$ = $1 - $3;}
    | expr VEZES expr   {$$ = $1 * $3;}
    ;
%%

void yyerror (char *s) {
    printf("erro: %s\n\n", s);
}

int main (void) {
    if (yyparse())
        puts("rejeita");
    else
        puts("aceita");
    return 0;
}
