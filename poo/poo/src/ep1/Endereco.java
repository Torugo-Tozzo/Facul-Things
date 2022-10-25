package ep1;

//import java.util.*;
public class Endereco {
	private String rua;
	private String numero;
	private String bairro;
	private String cidade;

	public Endereco(String rua, String numero, String bairro, String cidade) {
		this.rua = rua;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
	}

	public String mostraRua() {
		return rua;
	}

	public String mostraNumero() {
		return numero;
	}

	public String mostraBairro() {
		return bairro;
	}

	public String mostraCidade() {
		return cidade;
	}

}
