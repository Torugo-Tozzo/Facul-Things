package banco.dominio.excecoes;

public class ExcecaoChequeEspecial extends Exception{
    private double deficit;

    public ExcecaoChequeEspecial(String mensagem, double deficit) {
        super(mensagem);
        this.deficit = deficit;
    }

    public double getDeficit() {
        return deficit;
    }
}
