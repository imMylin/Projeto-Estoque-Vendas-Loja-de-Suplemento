#ifndef PRODUTO_H
#define PRODUTO_H
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Produto
{
    public:
        Produto(string nome, float preco, int quantidade, string descricao);
        Produto();
        virtual ~Produto();
        string getNome();
        string getDescri();
        float getPreco();
        int getQuantidade();

        void setQuantidade(int q);

    protected:
        string nome;
        float preco;
        int quantidade;
        string descricao;


    private:
};

#endif // PRODUTO_H
