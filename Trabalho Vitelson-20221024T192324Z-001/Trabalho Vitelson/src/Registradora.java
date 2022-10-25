import java.util.ArrayList;
import java.util.List;

public class Registradora {

    private CatalogoProdutos catalogo;
    private int contador;
    private String id;
    private List<Venda> vendas = new ArrayList<>();

    public Registradora(String id) {
        this.id = id;
    }

    public void criarNovaVenda(){

    }

    public void entrarItem(String id, int quantidade){

    }

    public double fazerPagamento(double quantiaFornecida){

        return 0;
    }

    public void fazerPagamento(double quantiaFornecida, Operadora operadora, int quantidadeParcelas){

    }

    public void fazerPagamento(double quantiaFornecida, String banco){

    }

    public void finalizarVenda(){

    }

    public CatalogoProdutos getCatalogo(){
        return catalogo;
    }

    public String getId(){
        return id;
    }

    public Venda getVendaCorrente(){
        return vendas.get(0);
    }

    public void setCatalogo(CatalogoProdutos catalogo){
        this.catalogo = catalogo;
    }

}
