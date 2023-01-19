/*------------------------------------------------------------
  |                  UNIFAL - Universidade Federal de Alfenas
  |                  BACHARELADO EM CIENCIA DA COMPUTACAO
  |   Trabalho....: Compilador Simples - Funcao
  |   Disciplina..: Teoria de Linguagens e Compiladores
  |   Professor...: Luiz Eduardo da Silva
  |   Aluno.......: Lucas da Silva Justino
  |   Data........: 30/03/2021
  +----------------------------------------------------------*/

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #include "estruturas.h"
    #include "lexico.c"
    #include "pilha.c"
    #include "tabela.c"

    #define DEBUG(x) x
    //int yylex();
    //int msg (char *);
    int yyerror (char *);
    void empilha(int, char);
    int desempilha();
    void mostra_pilha(char *);
    void insere_simbolo (struct elem_tab_simbolos);
    int busca_simbolo(char *);
    void mostra_tabela();
    extern char atomo [];
    int contaVar = 0;
    int rotulo = 0;
    int tipo;
    int mecanismo = 10;
    char escopo = 'G';
    extern FILE *yyin;
    extern FILE *yyout;
    extern char atomo[80];
    int npar = 0;
    int avar = 0;
    int gvar;
    int qtdtabela = 0;
    
%}


%token T_PROGRAMA
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E
%token T_OU
%token T_NAO
%token T_V
%token T_F
%token T_NUMERO
%token T_ABRE
%token T_FECHA
%token T_INTEIRO
%token T_LOGICO
%token T_REPITA
%token T_ATE
%token T_FIMREPITA
%token T_FUNC
%token T_FIMFUNC
%token T_REF

%start programa

//Precendencia para tratar ambiguidade
%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV

%%
programa: cabecalho 
            {fprintf(yyout,"\tINPP\n"); }
        variaveis 
            {
               gvar = avar; //quantidade de variáveis declaradas globalmente
            }
        rotinas T_INICIO lista_comandos T_FIM 
            {
                 fprintf(yyout,"\tDMEM\t%d\n", gvar); //imprime a quantidade de variaveis globais que foram desalocadas
                 fprintf(yyout,"\tFIMP\n"); } ;

cabecalho: T_PROGRAMA T_IDENTIF;

rotinas: |
          {
               fprintf(yyout,"\tDSVS\tL0\n");  // imprime o desvio sempre
          } lista_funcoes
          {
               fprintf(yyout,"L0\tNADA\n"); //imprime o caminho que vai o desvio sempre
          }
          ;

lista_funcoes: funcao lista_funcoes | funcao;

funcao: T_FUNC tipo T_IDENTIF 
     {
          avar = 0;
          rotulo++;
          strcpy(elem_tab.id, atomo);
          elem_tab.endereco = contaVar;
          elem_tab.tipo = tipo;
          elem_tab.escopo = escopo;
          elem_tab.mec = -1;
          elem_tab.rotulo = rotulo;
          fprintf(yyout,"L%d\tENSP\n", rotulo);                   //insere uma função na tabela de simbolos
          elem_tab.cat = 'F';
          contaVar++;
          insere_simbolo(elem_tab);
          escopo = 'L';
     }
      T_ABRE lista_parametros T_FECHA 
      {
          arruma_deslocamento(contaVar, npar);                 //deslocamento do ultimo parametro no valor de -3
      }variaveis T_INICIO
        lista_comandos T_FIMFUNC
        {
             int removeVariavelLocal = remove_local();
             fprintf(yyout,"\tDMEM\t%d\n", removeVariavelLocal - npar); //remove as variaveis declaradas, retirando as variaveis do parametro
             contaVar = contaVar - removeVariavelLocal;
             DEBUG (mostra_tabela(); )                             
             escopo = 'G';
             fprintf(yyout,"\tRTSP\t%d\n", npar); 
             npar = 0;

        };

lista_parametros: | lista_parametros parametro;

parametro: mecanismo tipo T_IDENTIF
     {
          npar++;
          strcpy(elem_tab.id, atomo);
          elem_tab.endereco = contaVar;
          elem_tab.tipo = tipo;
          elem_tab.escopo = escopo;                    //insere na tabela de simbolo as variaveis declaradas no parametro da funcao 
          elem_tab.mec = mecanismo;
          elem_tab.rotulo = -1;
          elem_tab.cat = 'P';
          insere_simbolo(elem_tab);
          contaVar++;
          DEBUG (mostra_tabela(); )  
     };
mecanismo: {mecanismo = VAL;} | T_REF {mecanismo = REF;} ;

variaveis:  | declaracao_variaveis
            {
               DEBUG (mostra_tabela(); )
               fprintf(yyout,"\tAMEM\t%d\n",avar);     //mostra a quantidade variaveis alocada globalmente
            };

declaracao_variaveis: tipo lista_variaveis declaracao_variaveis
                    | tipo lista_variaveis;

tipo: T_LOGICO { tipo = LOG; }| T_INTEIRO {tipo = INT; };

lista_variaveis: lista_variaveis T_IDENTIF 
                    {    
                         strcpy (elem_tab.id, atomo) ;
                         elem_tab.endereco = avar;  
                         elem_tab.tipo = tipo;
                         elem_tab.escopo = escopo;
                         elem_tab.mec = -1;
                         elem_tab.rotulo = -1;
                         elem_tab.cat = 'V';
                         insere_simbolo (elem_tab);                   //insere as variaveis na tabela simbolo
                         contaVar++;    
                         avar++;
                    }
               
               | T_IDENTIF
                   {    
                         strcpy (elem_tab.id, atomo) ;
                         elem_tab.endereco = avar;  
                         elem_tab.tipo = tipo;
                         elem_tab.escopo = escopo;
                         elem_tab.mec = -1;
                         elem_tab.rotulo = -1;
                         elem_tab.cat = 'V';
                         insere_simbolo (elem_tab);
                         contaVar++;     
                         avar++;
                    };

lista_comandos:  | comando lista_comandos;

comando: entrada_saida | repeticao | selecao | atribuicao | repetir;

entrada_saida: leitura | escrita;

identificador: T_IDENTIF
          {
               int i = busca_simbolo (atomo);
               if(i == -1)
                    msg("Identificador desconhecido");
               empilha(i,'i');
          };

leitura: T_LEIA identificador
         {
              fprintf(yyout,"\tLEIA\n"); 
              int pos = busca_simbolo(atomo);
              if(pos == -1)
                  msg("Variavel nao declarada\n");
               if(TabSimb[pos].escopo == 'G')
                    fprintf(yyout,"\tARZG\t%d\n",TabSimb[pos].endereco); 
               else
                    if(TabSimb[pos].escopo == 'L' || TabSimb[pos].mec == VAL)
                         fprintf(yyout,"\tARZL\t%d\n",TabSimb[pos].endereco); 
                    else
                         fprintf(yyout,"\tARZI\t%d\n",TabSimb[pos].endereco); 
         } ;

escrita: T_ESCREVA expressao
            {
                 fprintf(yyout,"\tESCR\n"); 
                 desempilha();
            };


repeticao: T_ENQTO 
            {rotulo++;
            fprintf(yyout,"L%d\tNADA\n", rotulo); 
            empilha(rotulo, 'r'); }
        expressao T_FACA 
            {
                 DEBUG (mostra_pilha("repeticao"); )
                 int t1 = desempilha();
                 if(t1 != LOG)
                    msg("Incompatibilidade de tipos");
                 rotulo++;
                 fprintf(yyout,"\tDSVF\tL%d\n", rotulo); 
                 empilha(rotulo, 'r') ;}
        lista_comandos T_FIMENQTO
            {    int r1 = desempilha();
                 int r2 = desempilha();
                 fprintf(yyout,"\tDSVS\tL%d\n", r2); 
                 fprintf(yyout,"L%d\tNADA\n", r1); 
            } ;

repetir: T_REPITA lista_comandos T_ATE expressao T_FIMREPITA;

selecao: T_SE expressao T_ENTAO 
            {
               DEBUG (mostra_pilha("selecao"); )
               int t1 = desempilha();
               if(t1 != LOG)
                  msg("Incompatibilidade de tipos");  
               rotulo++;
               fprintf(yyout,"\tDSVF\tL%d\n", rotulo);
               empilha(rotulo, 'r');
           }
        lista_comandos T_SENAO 
            {
                 int r = desempilha();
                 rotulo++;
                 fprintf(yyout,"\tDSVS\tL%d\n", rotulo); 
                 fprintf(yyout,"L%d\tNADA\n", r); 
                 empilha(rotulo, 'r');
            }
        lista_comandos T_FIMSE
            {    int r = desempilha();
                 fprintf(yyout,"L%d\tNADA\n", r); 
            } ;

atribuicao: identificador
          {    
               int pos = desempilha();
               empilha(pos,'i');
               empilha(TabSimb[pos].tipo, 't');
          }              
            
            T_ATRIB expressao 
            {  
                 DEBUG (mostra_pilha("atribuicao"); )
                 int texp = desempilha();
                 int tvar = desempilha(); 
                 int end = desempilha();
                 if(texp != tvar)
                    msg("Incompatibilidade de tipos");
                 if(TabSimb[end].escopo == 'G')
                    fprintf(yyout,"\tARZG\t%d\n",TabSimb[end].endereco); 
               else                                                                  //Armazena a variavel com base no tipo dela
                    if(TabSimb[end].escopo == 'L' || TabSimb[end].mec == VAL)
                         fprintf(yyout,"\tARZL\t%d\n",TabSimb[end].endereco); 
                    else
                         fprintf(yyout,"\tARZI\t%d\n",TabSimb[end].endereco); 
            };

expressao: expressao T_VEZES   expressao   
                 {
                      char tipo2 = desempilha_tipo();            //retorna o tipo do topo da pilha 
                      int t2 = desempilha();                     //retorno o valor do topo da pilha que é o endereço
                                                                           
                      if(tipo2 == 'i')                           //se o tipo do topo da pilha for um identificador, busco o tipo do valor na tabela de simbolos
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();            
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tMULT\n");
                      empilha(INT, 't');
                 }
           |
           expressao T_DIV     expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tDIV\n"); 
                      empilha(INT, 't');
                 }
           |
           expressao T_MAIS    expressao   
                 {
                     char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tSOMA\n"); 
                      empilha(INT, 't');
                 }
           |
           expressao  T_MENOS  expressao   
                 {
                     char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tSUBT\n"); 
                      empilha(INT, 't');
                 }
           |
           expressao  T_MAIOR  expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMMA\n"); 
                      empilha(LOG, 't');
                 }
           |
           expressao  T_MENOR  expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMME\n"); 
                      empilha(LOG, 't');
                 }
           |
           expressao  T_IGUAL  expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCMIG\n"); 
                      empilha(LOG, 't');
                 }
           |
           expressao  T_E      expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tCONJ\n"); 
                      empilha(LOG, 't');
                 }
           |
           expressao T_OU      expressao   
                 {
                      char tipo2 = desempilha_tipo();
                      int t2 = desempilha();

                      if(tipo2 == 'i')       
                         t2 = TabSimb[t2].tipo;
                      
                      char tipo1 = desempilha_tipo();
                      int t1 = desempilha();

                      if(tipo1 == 'i')       
                         t1 = TabSimb[t1].tipo;
                     
                      if(t1 != INT || t2 != INT)
                         msg("Incompatibilidade de tipos!\n");
                      fprintf(yyout,"\tDISJ\n"); 
                      empilha(LOG, 't');
                 } 
           |
           termo ;

argumentos: | lista_argumentos;

lista_argumentos: lista_argumentos argumento | argumento;

argumento: expressao 
          {
               npar++;
               int posArg = desempilha();
               int posFunc = desempilha();         
               int posPar = TabSimb[posFunc].npar - npar;
               int retorno = buscaTipoParametro(posFunc,posPar);           //Compara o tipo do argumento declarado na função com o tipo da chamada da funcao
               if(retorno == -1)
                    msg("Parametro nao encontrado");
               if(TabSimb[posArg].tipo != retorno)
                    msg("ERRO");    
               empilha(posFunc, 'i');

          };
     

termo: identificador 
     {
          int t1 = desempilha();
          if(TabSimb[t1].escopo == 'G' ){
               if(TabSimb[t1].mec == REF)
                    fprintf(yyout,"\tCREG\t%d\n", TabSimb[t1].endereco); 
               else
                    fprintf(yyout,"\tCRVG\t%d\n", TabSimb[t1].endereco);        //Carrega a variavel com base no seu tipo
          }
          else if(TabSimb[t1].escopo == 'L'){
               if(TabSimb[t1].mec == REF)
                    fprintf(yyout,"\tCREL\t%d\n", TabSimb[t1].endereco); 
               else
                    fprintf(yyout,"\tCRVL\t%d\n", TabSimb[t1].endereco); 
          }
          empilha(t1, 'i');
     }
| identificador 

     T_ABRE 
     {
          fprintf(yyout,"\tAMEM\t1\n");
     } argumentos T_FECHA 
     {
          int t1 = desempilha();
          empilha(TabSimb[t1].tipo, 't');
          fprintf(yyout,"\tSVCP\t\n");                                     //Desvio usado para chamar a função
          fprintf(yyout,"\tDSVS\tL%d\n",TabSimb[t1].rotulo);
     };   
       |
       T_NUMERO    
            {
                 fprintf(yyout,"\tCRCT\t%s\n", atomo); 
                 empilha(INT, 't');
                 }
       |
       T_V       
            {
                 fprintf(yyout,"\tCRCT\t1\n"); 
                 empilha(LOG, 't');
            }  
       |
       T_F         
            {
                 fprintf(yyout,"\tCRCT\t0\n"); 
                 empilha(LOG, 't');
            }
       |
       T_NAO termo 
            {
                 int t1 = desempilha();
                 if(t1 != LOG)
                    msg("Incompatibilidade de tipos");
                 fprintf(yyout,"\tNEGA\n"); 
                 empilha(LOG, 't');
            }
       | 
       T_ABRE expressao  T_FECHA;



%%

/*+--------------------------------------------+
  |     Corpo principal do programa COMPILADOR |
  +--------------------------------------------+*/

  int yyerror (char *s){
      msg("ERRO SINTATICO");
  }


  int main (int argc, char *argv[]){
       char *p, nameIn[100], nameOut[100];
       argc--;
       argv++;

       if(argc < 1){
            puts("\nCompilador SIMPLES");
            puts("\tUSO: ./simples <nomefonte>[.simples]\n\n");
            exit(10);
       }
       if(p =strstr (argv[0], ".simples"))
            *p = 0;
        strcpy (nameIn, argv[0]);
        strcat (nameIn, ".simples");
        strcpy (nameOut, argv[0]);
        strcat (nameOut, ".mvs");

        yyin = fopen(nameIn, "r");
        if(!yyin){
             puts("Programa fonte nao encontrado!");
             exit(20);
        }
        yyout = fopen(nameOut, "w");

        if(!yyparse()){
             printf("\nPrograma OK!\n\n");  
        }
        desaloca();
  }