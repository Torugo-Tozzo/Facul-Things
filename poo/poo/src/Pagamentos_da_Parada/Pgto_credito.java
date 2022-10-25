package Pagamentos_da_Parada;

public class Pgto_credito extends Pgto_cartoes {
	private String issuer;
	
	public String getIssuer() {
		return issuer;
	}

	public void setIssuer(String issuer) {
		this.issuer = issuer;
	}

	public Pgto_credito(double total,String issuer,String nomeBanco, String numeroCartao) {
		super(total,nomeBanco,numeroCartao);
		this.issuer=issuer;
		
	}
	public String detalhes() {
		String x = super.detalhes()+"Issuer "+this.getIssuer()+"\n";
		return x;
	} 

}
