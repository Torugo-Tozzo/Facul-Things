digito  [0-9]
%{
    int conta = 0;
%}
%%
{digito}+   conta++;
.       ;
\n      ;
%%
int yywrap () {return 1; }
int main () {
    yylex();
    printf("a quantidade de numeros no arquivo é: %d", conta);

}