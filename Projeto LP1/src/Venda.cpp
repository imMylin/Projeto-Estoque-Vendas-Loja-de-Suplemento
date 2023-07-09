#include "Venda.h"

Venda::Venda()
{
    //ctor
}

Venda::~Venda()
{
    //dtor
}

bool Venda::realizaVendas(Estoque& estoque, string nome, int quantidade){

    Produto produto;
    produto = estoque.pesquisarProduto(nome);
    bool vendaRealizada = false;

    if(produto.getQuantidade() >= quantidade){
        total += produto.getPreco() * quantidade;
        produtos.push_back(Produto(produto.getNome(), produto.getPreco(), quantidade, produto.getDescri()));
        produto.setQuantidade(produto.getQuantidade() - quantidade);
        estoque.alterarProduto(nome, produto);
        vendaRealizada = true;
    }
    return vendaRealizada;
}

void Venda::verificaVenda(Estoque& estoque, string nome, int quantidade) {
    Produto produto;
    produto = estoque.pesquisarProduto(nome);
    bool vendaRealizada = realizaVendas(estoque, nome, quantidade);

    if (vendaRealizada) {
       // produto.setQuantidade(produto.getQuantidade() - quantidade);
        estoque.alterarProduto(nome, produto);
    } else {
        cout << "Estoque insuficiente para venda. Por favor, insira uma quantidade menor." << endl;
        cout << "Quantidade atual em estoque: " << produto.getQuantidade() << endl;
    }
}

void Venda::exibirTotalDeVendas(){

    for (auto& produto : produtos) {
        cout << endl <<"Nome: " << produto.getNome() << endl;
        cout << "Preço: " << produto.getPreco() << endl;
        cout << "Quantidade: " << produto.getQuantidade() << endl;
        cout << "Descrição: " << produto.getDescri() << endl << endl;
    }
    cout << "Total: " << total << endl;
}

void Venda::geraRelatorioVendas(){
    cout << "Relatorio de Vendas" << endl;
    cout << "-------------------" << endl;
    for (auto& produto : produtos) {
        cout << produto.getNome() << " - " << produto.getQuantidade() << " unidades - R$ " << produto.getPreco() * produto.getQuantidade() << endl;
    }
    cout << "Total: R$ " << total << endl;
}

list <Produto> Venda::getProdutos(){
    return produtos;
}
