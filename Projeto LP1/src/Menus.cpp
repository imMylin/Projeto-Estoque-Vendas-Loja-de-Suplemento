#include "Menus.h"

Menus::Menus()
{
    //ctor
}

Menus::~Menus()
{
    //dtor
}
void Menus::menuEstoque(){
            cout << "Bem vindo(a) ao menu de estoque. Estas são nossas opções: " << endl << endl;
            cout << "1 - Inserir um produto" << endl;
            cout << "2 - Alterar um produto" << endl;
            cout << "3 - Pesquisar um produto" << endl;
            cout << "4 - Remover um produto" << endl;
            cout << "5 - Listar todos os produtos" << endl;
            cout << "6 - Relatório de estoque" << endl;
            cout << "7 - Sair" << endl;
}
void Menus::menuVenda(){
            cout << "Bem vindo(a) ao menu de venda. Estas são nossas opções: " << endl << endl;
            cout << "1 - Realizar uma venda" << endl;
            cout << "2 - Exibir total de vendas" << endl;
            cout << "3 - Relatório de vendas" << endl;
            cout << "4 - Sair" << endl;
}
void Menus::menuEscolha(){
            cout << endl <<  "Bem vindo(a) a loja de suplementos CI 105" << endl << endl << endl;
            cout << "Deseja acessar nosso menu de estoque ou venda? (Digite 1 para estoque / 2 para venda / 0 para sair do programa)"<< endl;
}
