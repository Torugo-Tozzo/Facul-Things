import java.util.ArrayList;
import java.util.List;

public class Loja {
    private Endereco endereco;
    private String nome;
    private List<Registradora>registradoras = new ArrayList<>();
    private List<Venda>vendas = new ArrayList<>();

    public Loja(String nome, Endereco endereco) {
    }

    public void adicionarRegistradora(Registradora r) {

    }
    public void adicionarVenda(Venda v){

    }

    public Registradora getRegistradora() {
        return null;
    }

    public Venda getUltimaVenda() {
        return null;
    }
}
