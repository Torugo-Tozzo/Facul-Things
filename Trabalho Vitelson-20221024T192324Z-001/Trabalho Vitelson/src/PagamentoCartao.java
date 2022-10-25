

public class PagamentoCartao implements Juros{
    private CalculadoraFinanceira calculadora;
    private Operadora operadora;
    private int quantidade;

    public PagamentoCartao(double quantia, Operadora operadora, int quantidadeParcelas) {

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


