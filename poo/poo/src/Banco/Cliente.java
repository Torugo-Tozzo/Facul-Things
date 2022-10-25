package Banco;
import java.util.*;

public class Cliente {
	private String nome;
	private String sobrenome;
	private ArrayList<Conta> conta;

	public Cliente(String nome, String sobrenome) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.conta = new ArrayList<>();
		
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getsobreNome() {
		return sobrenome;
	}

	public void setSobrenome(String sobreNome) {
		this.sobrenome = sobreNome;
	}

	public Conta getConta(int indice) {
		return conta.get(indice);
	}
	
	public int numeroDeContas() {
		return conta.size();
	}

	public void addConta(Conta conta) {
		this.conta.add(conta);
	}
}
