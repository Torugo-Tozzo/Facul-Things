package Banco;

public class ContaPoupanca extends Conta {
	private double taxaRendimento;

	public double getTaxaRendimento() {
		return taxaRendimento;
	}

	public void setTaxaRendimento(double taxaRendimento) {
		this.taxaRendimento = taxaRendimento;
	}

	public ContaPoupanca(double saldoInicial, double rendimento) {
		super(saldoInicial);
		this.taxaRendimento = rendimento;
		
	}
}
