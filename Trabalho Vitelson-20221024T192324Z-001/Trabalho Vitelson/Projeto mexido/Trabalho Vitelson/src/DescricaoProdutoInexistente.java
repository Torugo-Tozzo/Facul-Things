public class DescricaoProdutoInexistente {

    private String id;

    public DescricaoProdutoInexistente() {

    }

    public DescricaoProdutoInexistente(String string) {

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
