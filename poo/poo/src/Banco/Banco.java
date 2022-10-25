package Banco;

import java.util.ArrayList;

public class Banco {
	private ArrayList<Cliente> cliente;

	public Banco() {
		cliente = new ArrayList<>();
	}

	public void adicionarCliente(Cliente cliente) {
		this.cliente.add(cliente);
	}

	public Cliente getCliente(int indice) {
		return cliente.get(indice);
	}

	public int getNumeroDeClientes() {
		return this.cliente.size();
	}
	
	public ArrayList<Cliente> getCliente(String nome, String sobrenome){
	ArrayList<Cliente> result= new ArrayList<>();
	for(Cliente pessoa: cliente) {
		if(pessoa.getNome().equals(nome) &&
			pessoa.getsobreNome().equals(sobrenome)){
				result.add(pessoa);
			}
	}
	return result;
	}
}