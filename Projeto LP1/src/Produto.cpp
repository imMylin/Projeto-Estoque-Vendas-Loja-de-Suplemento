#include "Produto.h"

Produto::Produto()
{
    //ctor
}

Produto::~Produto()
{
    //dtor
}


Produto::Produto(string nome, float preco, int quantidade, string descricao){
    this ->nome = nome;
    this ->preco = preco;
    this ->quantidade = quantidade;
    this ->descricao = descricao;

}


string Produto::getNome(){
    return nome;
}
string Produto::getDescri(){
    return descricao;
}
float Produto::getPreco(){
    return preco;
}
int Produto::getQuantidade(){
    return quantidade;
}

void Produto::setQuantidade(int q){
    quantidade = q;
}
