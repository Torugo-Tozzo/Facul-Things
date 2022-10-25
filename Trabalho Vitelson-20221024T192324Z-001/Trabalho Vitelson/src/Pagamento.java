public class Pagamento {

    private double quantiaFornecida;

    public Pagamento(double quantiaFornecida) {
        this.quantiaFornecida = quantiaFornecida;
    }

    public double getQuantiaFornecida() {
        return quantiaFornecida;
    }

    public void setQuantiaFornecida(double quantiaFornecida) {
        this.quantiaFornecida = quantiaFornecida;
    }

    public String toString() {
        return "Pagamento{" +
                "quantiaFornecida=" + quantiaFornecida +
                '}';
    }
}
