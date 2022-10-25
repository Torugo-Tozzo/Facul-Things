package Banco;

public class ContaCorrente extends Conta {
	private double chequeEspecial;

	public double getChequeEspecial() {
		return chequeEspecial;
	}

	public void setChequeEspecial(double chequeEspecial) {
		this.chequeEspecial = chequeEspecial;
	}

	public ContaCorrente(double saldoInicial, double chequeEspecial) {
		super(saldoInicial);
		this.chequeEspecial = chequeEspecial;
	}

	public ContaCorrente(double saldoInicial) {
		super(saldoInicial);
	}

	public boolean sacar(double valor) {
		if (this.saldo + this.chequeEspecial > valor) {
			this.saldo -= valor;
			return true;
		} else
			return false;
	}

}
