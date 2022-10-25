import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Venda {

    private Date data;
    private boolean estaCompleta;
    private List<ItemVenda> itensVenda = new ArrayList<>();
    private Pagamento pagamento;

    public Venda(Date data){
        this.data = data;
    }

    public double calcularValorVenda(){
        return 0;
    }

    public double calcularTroco(){
        return 0;
    }

    public void criarItemVenda(DescricaoProduto desc, int quantidade){

    }

    public double fazerPagamento(double quantiaFornecida){
        return 0;
    }

    public void fazerPagamento(double quantiaFornecida, Operadora operadora, int quantidadeParcelas){

    }

    public void fazerPagamento(double quantiaFornecida, String banco){

    }

    public void setEstaCompleta(boolean estaCompleta){
        this.estaCompleta = estaCompleta;
    }

    public String toString() {
        return "Venda{" +
                "data=" + data +
                ", estaCompleta=" + estaCompleta +
                ", itensVenda=" + itensVenda +
                ", pagamento=" + pagamento +
                '}';
    }
}
