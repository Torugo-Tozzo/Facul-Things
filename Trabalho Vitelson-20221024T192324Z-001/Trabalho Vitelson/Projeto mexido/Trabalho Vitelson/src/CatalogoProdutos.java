import java.util.ArrayList;
import java.util.List;

public class CatalogoProdutos {
    private List<DescricaoProduto> descricoesProdutos;
    private int contadorDescricoesProdutos;
    List<DescricaoProduto> descricoesProduto = new ArrayList<>();

    public CatalogoProdutos() {
        //descricoesProdutos = new DescricaoProduto[10];
        DescricaoProduto d1 = new DescricaoProduto("01", 3.75, "Chocolate Talento");
        DescricaoProduto d2 = new DescricaoProduto("02", 1.50, "Chiclete Trident");
        DescricaoProduto d3 = new DescricaoProduto("03", 2.50, "Lata de Coca-cola");
        DescricaoProduto d4 = new DescricaoProduto("04", 2.00, "Agua Mineral Caxambu");
        DescricaoProduto d5 = new DescricaoProduto("05", 5.99, "Cerveja Corona extra");

        DescricaoProduto d6 = new DescricaoProduto("06", 2.50, "Biscoito cream cracker");
        DescricaoProduto d7 = new DescricaoProduto("07", 4.50, "Leite condensado");
        DescricaoProduto d8 = new DescricaoProduto("08", 18.00, "Cafe Prima Qualitat");
        DescricaoProduto d9 = new DescricaoProduto("09", 2.00, "Danete");
        DescricaoProduto d10 = new DescricaoProduto("10", 1.00, "Bombril");

        descricoesProdutos.add(d1);

    }

    public DescricaoProduto getDescricaoProduto(String id) {

        return null;
    }
}
