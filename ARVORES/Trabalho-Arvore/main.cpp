# include <iostream>
# include "avl.cpp"
#include "lista.cpp"

using namespace std;

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->value = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Inserção sem balanceamento
Node* insertBI(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data <= root->value) {
        root->left = insertBI(root->left, data);
    } else {
        root->right = insertBI(root->right, data);
    }
    return root;
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");

    Cabecalho *cabeca = new Cabecalho;
    Cabecalho *placas = new Cabecalho;
    Cabecalho *pilha  = new Cabecalho;
    pilha->tam = 0;
    Cabecalho *fila   = new Cabecalho;
    fila->tam = 0;

    Veiculo *bd;
    cabeca->inicio = new Veiculo;
    bd = cabeca->inicio;
    if(myfile.is_open()){
        while (!myfile.eof()){
            bd->prox = new Veiculo;
            bd = bd->prox;

            myfile >> bd->modelo;
            myfile >> bd->marca;
            myfile >> bd->versao;
            myfile >> bd->ano;
            myfile >> bd->kilometragem; 
            myfile >> bd->motor; 
            myfile >> bd->consumo; 
            myfile >> bd->moua; 
            myfile >> bd->direcao; 
            myfile >> bd->cor;
            myfile >> bd->portas;
            myfile >> bd->placa; 
            myfile >> bd->preco;
            
            cabeca->tam++;
        }
        myfile.close();

    int resp, caso, caso1, caso3;
    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa;
    float preco;

    do{
        cout << " Digite : (1) para buscar\n Digite : (2) para adicionar\n Digite : (3) para relatórios\n Digite : (4) para empilhar carros (hidraulico add, eletrico rm)\n Digite : (5) para enfileirar carros (automatico add, manual rm)\n Digite : (6) para sair\n";
        cin >> caso;
        switch (caso){
        case 1:
            cout << "Digite a placa a ser buscada\n";
            cin >> placa;
            busca(cabeca,placa);
            cout << "Deseja excluir?\n Sim ! exclui essa lata velha - digite(1).\n Não, nuca, não exlua, pf! - digite(2)\n";
            cin >> caso1;
            if(caso1 == 1){
                exclui(cabeca,placa);
            }
            break;
        case 2:
            cout << "Digite modelo\n";
                     cin >> modelo;
            cout << "Digite marca\n";
                     cin >> marca;
            cout << "Digite versao\n";
                     cin >> versao;
            cout << "Digite ano\n";
                     cin >> ano;
            cout << "Digite kilometragem\n";
                     cin >> kilometragem;
            cout << "Digite motor\n";
                     cin >> motor;
            cout << "Digite consumo\n";
                     cin >> consumo;
            cout << "Digite moua\n";
                     cin >> moua;
            cout << "Digite direcao\n";
                     cin >> direcao;
            cout << "Digite cor\n";
                     cin >> cor;
            cout << "Digite portas\n";
                     cin >> portas;
            cout << "Digite placa\n";
                     cin >> placa;
            cout << "Digite preco (em float, ex: 12345.00)\n";
                     cin >> preco;

            cout << "adicionando......\n";
            insere_fim(cabeca,modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco);
        break;
        case 3:
            cout << "Mostrar os veiculos = digite (1)\nOrdenar os veiculos pelas placas = digite (2)\n";
            cin >> caso3;
            if(caso3 == 1){
                imprime(cabeca);
                }else 
                ordena_placa(cabeca,placas);
                imprime_placa(placas);
        break;
        case 4:
        cria_pilha(cabeca,pilha);
        break;
        case 5:
        cria_fila(cabeca,fila);
        break;
        case 6:
            salva(cabeca);
            resp = 1;
        break;
        default:
            break;
        }
    } while (resp != 1);
    encerra_lista(cabeca); encerra_lista(placas);encerra_lista(pilha); encerra_lista(fila);
    }else
        cout << "unable to open the file";
/*
  Node *rootAVL = nullptr;

  rootAVL = insertAVL(rootAVL, 1928);
  rootAVL = insertAVL(rootAVL, 1700);
  rootAVL = insertAVL(rootAVL, 1500);
  rootAVL = insertAVL(rootAVL, 1444);
  rootAVL = insertAVL(rootAVL, 2001);
  rootAVL = insertAVL(rootAVL, 3000);

  inorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  postorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  preorder(rootAVL);
  std::cout << "\n---------" << std::endl;
  
  printTree(rootAVL, 0);

  Node *root = nullptr;
    // antes do balancemento AVL
    root = insertBI(root,2);
    insertBI(root, 3);
    insertBI(root, 5);
    insertBI(root, 4);
    insertBI(root, 7);
    insertBI(root, 11);
    insertBI(root, 1);

    std::cout << root->value << std::endl;
    std::cout << root->right->value << std::endl;

    printf("\n em ordem \n");

    inorder(root);

    printf("\n pre ordem \n");

    preorder(root);

    printf("\n pos ordem \n");

    postorder(root);

    printf("\n --------- \n");

    printTree(root,0);
*/
}

