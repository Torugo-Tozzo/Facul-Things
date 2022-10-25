package Pagamentos_da_Parada;

public class Pgto_cartoes {
	private double total;
	private String numeroCartao;
	private String nomeCartao;
	
	public Pgto_cartoes(double total, String numeroCartao, String nomeCartao) {
		this.total=total;
		this.numeroCartao=numeroCartao;
		this.nomeCartao=nomeCartao;
	}
//	public Pgto_cartoes() {
//		
//	}
	
	public double getTotal() {
		return total;
	}
	public void setTotal(double total) {
		this.total = total;
	}
	public String getNumeroCartao() {
		return numeroCartao;
	}
	public void setNumeroCartao(String numeroCartao) {
		this.numeroCartao = numeroCartao;
	}
	public String getNomeCartao() {
		return nomeCartao;
	}
	public void setNomeCartao(String nomeCartao) {
		this.nomeCartao = nomeCartao;
	}
	public String detalhes() {
		String x = "Pagamento no valor de "+this.getTotal()+"\n"+
					"Propietario do cartao "+this.getNomeCartao()+"\n"+
					"Numero do cartao "+this.getNumeroCartao()+"\n";
		return x;
	} 
	

}
