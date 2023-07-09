#ifndef VENDA_H
#define VENDA_H
#include "Estoque.h"

class Venda : public Produto
{
    public:
        Venda();
        virtual ~Venda();
        bool realizaVendas(Estoque& estoque, string nome, int quantidade);
        void verificaVenda(Estoque& estoque, string nome, int quantidade);
        void exibirTotalDeVendas();
        float total = 0;
        void geraRelatorioVendas();
        list <Produto> getProdutos();


    protected:
        list <Produto> produtos;


    private:
};

#endif // VENDA_H
