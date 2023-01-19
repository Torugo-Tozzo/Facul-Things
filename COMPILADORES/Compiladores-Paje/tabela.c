//tabela de simbolos

#include <string.h>
#include <stdio.h>

int pos_tab = 0;
void msg (char *);

int busca_simbolo (char *id){
    int i = pos_tab - 1;
    for(; strcmp(TabSimb[i].id, id) && i >= 0; i--)                         
    ;
    return i;
}

void insere_simbolo(struct elem_tab_simbolos elem){
    int i;
    if(pos_tab == TAM_TAB)
        msg("Tabela de simbolos cheio");
    i = busca_simbolo(elem.id);
    if(i != -1 && elem_tab.escopo == 'G')                                   
        msg("Identificador ja esta na tabela");
    TabSimb[pos_tab] = elem;
   pos_tab++; 
}

void mostraLista(lista aux){
    lista i = aux;
    while(i != NULL){
        printf("(t=%d,m=%d) ",i->tipo,i->mec);
        i = i->prox;
    }
}

void mostra_tabela (){
        int i;
        puts("                                   Tabela de simbolos");
        puts("                         ----------------------------------------------------------------");
        printf("%30s\t|%5s\t|%5s\t|%5s\t|%5s\t|%5s\t|%5s\t|%5s","ID","DSL", "TIP", "ESC", "MEC", "ROT", "CAT", "LPA");
        puts("\n                         ----------------------------------------------------------------");
        for(i = 0; i < pos_tab; i++){
            if(TabSimb[i].cat == 'F'){
                printf("%30s\t|%3d\t|%3d\t|%3c\t|%3d\t|%3d\t|%3c\t|%4d", TabSimb[i].id, TabSimb[i].endereco, TabSimb[i].tipo, TabSimb[i].escopo, TabSimb[i].mec, TabSimb[i].rotulo, TabSimb[i].cat,TabSimb[i].npar);
                printf("  => [ ");
                mostraLista(TabSimb[i].listapar);
                printf(" ]\n");
            }
            else
            printf("%30s\t|%3d\t|%3d\t|%3c\t|%3d\t|%3d\t|%3c\t|\n", TabSimb[i].id, TabSimb[i].endereco, TabSimb[i].tipo, TabSimb[i].escopo, TabSimb[i].mec, TabSimb[i].rotulo, TabSimb[i].cat);
        }
        printf("\n\n");
}

void insereLista(int pos, int mec, int tipo){
    lista no = (lista)malloc(sizeof(lista));
    no->mec = mec;
    no->tipo = tipo;
    no->prox = NULL;
    if(TabSimb[pos].listapar == NULL){
        TabSimb[pos].listapar = no;
    }
    else{
        no->prox = TabSimb[pos].listapar;
        TabSimb[pos].listapar = no;
    }
}

void arruma_deslocamento (int pos, int npar){
    int aux = -3;
    int endtab = pos - npar - 1;
    for(int i = npar; i > 0; i--){                      //arruma os deslocamentos da variavel
        pos--;
        TabSimb[pos].endereco = aux;
        insereLista(endtab,TabSimb[pos].mec, TabSimb[pos].tipo);
        aux--;
    }
    TabSimb[endtab].endereco = aux;
    TabSimb[endtab].npar = npar;  
}

int remove_local(){
    int i = pos_tab - 1, cont = 0;
    while(TabSimb[i].escopo != 'G'){                    //remove as variaveis locais
        pos_tab--;
        i--;
        cont++;
    }
    return cont;
}

void desaloca(){
    int i = 0;
    for(i = 0; i < pos_tab; i++){
        if(TabSimb[i].listapar != NULL){
            lista aux = TabSimb[i].listapar;
            while(aux != NULL){
                lista j = aux;
                aux = aux->prox;
                free(j);
            }
            TabSimb[i].listapar = NULL;
        }
    }
}

int buscaTipoParametro (int endereco, int pos){
    lista aux = TabSimb[endereco].listapar;
    while(aux != NULL && pos != 0){
        aux = aux->prox;
        pos--;
    }
    if(pos == 0)
        return aux->tipo;
    else
        return -1;
}