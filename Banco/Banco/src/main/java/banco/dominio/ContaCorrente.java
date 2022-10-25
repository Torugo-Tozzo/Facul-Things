package banco.dominio;

import banco.dominio.excecoes.ExcecaoChequeEspecial;

public class ContaCorrente extends Conta{

    private double chequeEspecial;

    public ContaCorrente(double saldoInicial, double chequeEspecial) {
        super(saldoInicial);
        this.chequeEspecial = chequeEspecial;
    }

    public ContaCorrente(double saldoInicial) {
        super(saldoInicial);
    }

    public void sacar(double valor) throws ExcecaoChequeEspecial {
         // Saldo + valor cheque especial suficientes para cobrir o saque
        if (this.saldo + this.chequeEspecial >= valor) {
            this.saldo -= valor;
         } else {
            double deficit = valor - this.saldo;
            if (this.chequeEspecial == 0) {
                throw new ExcecaoChequeEspecial("Não há cheque especial", deficit);
            } else {
                throw new ExcecaoChequeEspecial("Saldo insuficiente no cheque especial", deficit);
            }
        }
     }

    public double getChequeEspecial() {
        return chequeEspecial;
    }

    public void setChequeEspecial(double chequeEspecial) {
        this.chequeEspecial = chequeEspecial;
    }


}
