public class DescricaoProdutoInexistente {

    private String id;

    public DescricaoProdutoInexistente() {

    }

    public DescricaoProdutoInexistente(String id) {
        this.id = id;
    }

    public DescricaoProdutoInexistente(String mensagem, String id) {
        this.id = id;
    }

    public String toString() {
        return "DescricaoProdutoInexistente{" +
                "id='" + id + '\'' +
                '}';
    }
}
