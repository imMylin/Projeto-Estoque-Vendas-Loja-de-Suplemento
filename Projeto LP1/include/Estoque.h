#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "Produto.h"


class Estoque : public Produto
{
    public:

        Estoque();
        Estoque(string nome, float preco, int quantidade, string descri);
        virtual ~Estoque();

        void cadastrarProduto(Produto produto);
        void alterarProduto(string nome, Produto produto);
        Produto exibirProduto(string nome);
        Produto pesquisarProduto(string nome);
        void removerProdutos(string nome);
        void listarProdutos();
        void gerarRelatorioEstoque(Estoque estoque);

        list <Produto> getProdutos();
    protected:
        list <Produto> produtos;

    private:
};

#endif // ESTOQUE_H
