public class DescricaoProduto {

    private String descricao;
    private String id;
    private double preco;

    public DescricaoProduto(String descricao, String id) {
        this.descricao = descricao;
        this.id = id;
    }

    public DescricaoProduto(String id, double preco,String descricao) {
        this.descricao = descricao;
        this.id = id;
        this.preco = preco;
    }

    public boolean equals(Object obj){
        return false;
    }

    public String getId() {
        return id;
    }

    public double getPreco() {
        return preco;
    }

    public String toString() {
        return "DescricaoProduto{" +
                "descricao='" + descricao + '\'' +
                ", id='" + id + '\'' +
                ", preco=" + preco +
                '}';
    }
}
