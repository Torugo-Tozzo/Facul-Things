%{
    int ncar, npal, nlin;
%}

%%
\n           {ncar++; nlin++;}
[^ \t\n]+    {npal++;ncar += yyleng;}
.            {ncar++;}
%%

int yywrap (void) {return 1; }
int main (void) {
    yylex();
    printf("caracteres: %d, linhas: %d, palavras: %d",ncar,nlin,npal);

}