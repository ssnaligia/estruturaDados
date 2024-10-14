#ifndef PRODUTO_h
    #define PRODUTO_h
    void cadastroProduto();               
    void produtosCadastrados();           
    void baixaEstoque();                  
    void produtosAVencer(int dias);       
    void produtosVencidos();              
    void vendas();
    void registrarVenda(float total, const char *dataVenda);
    void totalVendas(const char *dataInicio, const char *dataFim); 
#endif