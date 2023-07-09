#include "Estoque.h"

Estoque::Estoque()
{
    //ctor
}

Estoque::~Estoque()
{
    //dtor
}
Estoque::Estoque(string nome, float preco, int quantidade, string descri) : Produto(nome, preco, quantidade, descri){


}

void Estoque::cadastrarProduto(Produto produto){
    produtos.push_back(produto);
}
void Estoque::alterarProduto(string nome, Produto produto){
    for (auto& p : produtos) {
            if (p.getNome() == nome) {
                p = produto;
                return;
            }
        }
}
Produto Estoque::pesquisarProduto(string nome){
        for (auto& produto : produtos) {
            if (produto.getNome() == nome) {
                return produto;
            }
        }
}
Produto Estoque::exibirProduto(string nome){
    for (auto& produto : produtos) {
            if (produto.getNome() == nome) {
                cout << endl <<"Nome: " << produto.getNome() << endl;
                cout << "Preço: " << produto.getPreco() << endl;
                cout << "Quantidade: " << produto.getQuantidade() << endl;
                cout << "Descrição: " << produto.getDescri() << endl << endl;

                    return produto;
            }
        }

}
void Estoque::removerProdutos(string nome){
    for (auto it = produtos.begin(); it != produtos.end(); it++) {
            if (it->getNome() == nome) {
                produtos.erase(it);
                return;
            }
        }
}
void Estoque::listarProdutos(){
    for (auto& produto : produtos) {

        cout << "Nome: " << produto.getNome() << endl;
        cout << "Preço: " << produto.getPreco() << endl;
        cout << "Quantidade: " << produto.getQuantidade() << endl;
        cout << "Descrição: " << produto.getDescri() << endl;
        cout << endl << endl;


        }
}

void Estoque::gerarRelatorioEstoque(Estoque estoque) {
    cout << "Relatorio de Estoque" << endl;
    cout << "--------------------" << endl;
    for (auto& produto : estoque.produtos) {
        cout << produto.getNome() << " - " << produto.getQuantidade() << " unidades - R$ " << produto.getPreco() << endl;
    }
}
list <Produto> Estoque::getProdutos(){
    return produtos;
}

