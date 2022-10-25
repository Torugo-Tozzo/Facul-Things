package Banco;

public class Conta {
	
	protected double saldo;

	public double getSaldo() {
		return saldo;
	}

	public Conta(double saldoInicial) {
		saldo = saldoInicial;
	}
	
	public void depositar(double valor) {
		saldo = saldo + valor;
	}
	public boolean sacar(double valor) {
		double tira = this.saldo - valor;
		if(tira < 0)
			return false;
		this.saldo -= 0;
		return true;
	}
	
	
}