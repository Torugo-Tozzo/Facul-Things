package Pagamentos_da_Parada;

public class Pgto_debito extends Pgto_cartoes {
	private String nomeBanco;
	
	public Pgto_debito(double total, String nomeBanco, String numeroCartao, String nomeCartao ) {
		super(total, numeroCartao, nomeCartao);
		this.nomeBanco=nomeBanco;
	}

	public String getNomeBanco() {
		return nomeBanco;
	}

	public void setNomeBanco(String nomeBanco) {
		this.nomeBanco = nomeBanco;
	}
	public String detalhes() {
		String x = super.detalhes()+"Banco "+this.getNomeBanco()+"\n";
		return x;
	}

}
