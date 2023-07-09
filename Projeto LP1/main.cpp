#include <iostream>
#include "Estoque.h"
#include "Venda.h"
#include "Menus.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void salvarEstoque(Estoque estoque) {
    ofstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        for (auto produto : estoque.getProdutos()) {
            arquivo << produto.getNome() << "," <<produto.getQuantidade() << "," << produto.getPreco() << "," << produto.getDescri()  << endl;
        }
        arquivo.close();
        cout << "Dados do estoque salvos com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo de estoque." << endl;
    }
}

void salvarVendas(Venda& venda) {
    ofstream arquivo("vendas.txt");
    if (arquivo.is_open()) {
        for ( auto& produto : venda.getProdutos()) {
            arquivo << produto.getNome() << "," <<produto.getQuantidade() << "," << produto.getPreco() << endl;
        }
        arquivo.close();
        cout << "Dados de vendas salvos com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo de vendas." << endl;
    }
}

void carregarDadosEstoque(Estoque& estoque) {
    ifstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        string linha;
        string nome, descri;
        int quantidade;
        float preco;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            getline(ss, nome, ',');
            ss >> quantidade;
            ss.ignore();
            ss >> preco;
            ss.ignore();
            getline(ss,descri);

            Produto produto(nome, preco, quantidade, descri);
            estoque.cadastrarProduto(produto);
        }
        arquivo.close();
    }
}

void carregarDadosVendas(Venda& venda, Estoque& estoque) {
    ifstream arquivo("vendas.txt");
    if (arquivo.is_open()) {
        string linha;
        string nome;
        int quantidade;
        float preco;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            getline(ss, nome, ',');
            ss >> quantidade;
            ss.ignore();
            ss >> preco;
            //venda.realizaVendas(estoque, nome, quantidade);
            venda.verificaVenda(estoque, nome, quantidade);
        }
        arquivo.close();
    }
}

int main()
{
    //declaração dos objetos
    Menus m;

    Estoque estoque;
    Venda venda;

    carregarDadosEstoque(estoque);
    carregarDadosVendas(venda, estoque);

    //declaração das variaveis
    int escolha, opcao = 0;
    string nome, descricao, nomeProcurado;
    float preco;
    int quantidade;

    //declaração de variaveis novas

    string novoNome, novaDescricao;
    float novoPreco;
    int novaQuantidade, qt;



   m.menuEscolha();

do {
    cin >> escolha;

    switch(escolha){
        case 1:
            do {
                m.menuEstoque();
                cin >> opcao;
                getchar();

                if(opcao == 1 ){
                    cout << "Informe o nome do produto: " << endl;
                getline(cin, nome);
                cout << "Informe a descrição do produto: " << endl;
                getline(cin, descricao);
                cout << "Informe a quantidade do produto: " << endl;
                cin >> quantidade;
                cout << "Informe o preço do produto: " << endl;
                cin >> preco;
        	estoque.cadastrarProduto(Produto(nome, preco, quantidade, descricao));

                }
                else if(opcao == 2){
                    cout << "Informe o nome do produto que deseja alterar: " << endl;
                    getline(cin, nomeProcurado);

                    cout << "Informe o novo nome: " << endl;
                    getline(cin, novoNome);
                    cout << "Informe a nova descrição: " << endl;
                    getline(cin, novaDescricao);
                    cout << "Informe a nova quantidade: " << endl;
                    cin >> novaQuantidade;
                    cout << "Informe o novo preço: " << endl;
                    cin >> novoPreco;

                    estoque.alterarProduto(nomeProcurado, Produto(novoNome, novoPreco, novaQuantidade, novaDescricao));
                }
                else if(opcao == 3){
                    cout << "Informe o nome do produto que deseja: " << endl;
                    getline(cin, nomeProcurado);
                    estoque.exibirProduto(nomeProcurado);
                }
                else if(opcao == 4){
                    cout << "Informe o nome do produto que deseja remover: " << endl;
                    getline(cin, nomeProcurado);
                    estoque.removerProdutos(nomeProcurado);
                }
                else if(opcao == 5){
                    estoque.listarProdutos();
                }
                else if(opcao == 6){
                    estoque.gerarRelatorioEstoque(estoque);
                }
                else if(opcao == 7){
                    m.menuEscolha();
                    break; // sai do loop interno e volta ao loop externo
                }
            } while(opcao != 7);

            break;
        case 2:
            do {
                m.menuVenda();
                cin >> opcao;
                getchar();

                if(opcao == 1){
                    cout << "Informe o nome do produto e a quantidade: " << endl;
            		getline(cin, nomeProcurado);
            		cin >> qt;

                    venda.realizaVendas(estoque, nomeProcurado, qt);
                }
                else if(opcao == 2){
                    venda.exibirTotalDeVendas();
                }
                else if(opcao == 3){
                    venda.geraRelatorioVendas();
                }
                else if(opcao == 4){
                    m.menuEscolha();
                    break; // sai do loop interno e volta ao loop externo
                }
            } while(opcao != 4);
            break;
        default:
            if(escolha > 0){
            cout << "Opcao invalida, por favor escolha uma opcao valida." << endl << endl;
            }
    }
} while(escolha != 0); // sai do loop quando escolha for 0


salvarEstoque(estoque);
salvarVendas(venda);
    return 0;
}
