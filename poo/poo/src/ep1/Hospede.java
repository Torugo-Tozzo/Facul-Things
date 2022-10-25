package ep1;

public class Hospede {
	private String nome;
	private String sobrenome;
	private Endereco endereco;
	private double salario;

	public Hospede(String nome, String sobrenome) {
		this.nome = nome;
		this.sobrenome = sobrenome;
	}

	public Hospede(String nome, String sobrenome, Endereco endereco) {
		this.nome = nome;
		this.endereco = endereco;
		this.sobrenome = sobrenome;
		this.setSalario(salario);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSobreome() {
		return sobrenome;

	}

	public void setSobreome(String sobrenome) {
		this.sobrenome = sobrenome;
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

}
