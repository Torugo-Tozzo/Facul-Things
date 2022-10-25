

public class PagamentoCartao extends Pagamento implements Juros {
    private int quantidadeParcelas;
    private CalculadoraFinanceira calculadora;
    private Operadora operadora;
    private int quantidade;

    public PagamentoCartao(double quantia, Operadora operadora, int quantidadeParcelas) {
        super();
        this.operadora = operadora;
        this.quantidadeParcelas = quantidadeParcelas;


    }

    @Override
    public float consultarTaxaJuros() {

        return 0;
    }

    public double simularParcelas(double quantia, int quantidadeParcelas) {

        return quantia;
    }

    @Override
    public String toString() {
        return "PagamentoCartao{" +
                "calculadora=" + calculadora +
                ", operadora=" + operadora +
                ", quantidade=" + quantidade +
                '}';
    }
}


