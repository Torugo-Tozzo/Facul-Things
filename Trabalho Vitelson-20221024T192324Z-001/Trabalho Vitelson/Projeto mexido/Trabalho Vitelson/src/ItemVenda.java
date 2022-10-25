public class ItemVenda {

    private DescricaoProduto descricaoProduto;
    private int quantidade;

    public ItemVenda(DescricaoProduto descricaoProduto, int quantidade) {
        this.descricaoProduto = descricaoProduto;
        this.quantidade = quantidade;
    }

    public DescricaoProduto getDescricaoProduto() {
        return descricaoProduto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getSubTotal(){

        return 0;
    }

    public String toString() {
        return "ItemVenda{" +
                "descricaoProduto=" + descricaoProduto +
                ", quantidade=" + quantidade +
                '}';
    }
}
