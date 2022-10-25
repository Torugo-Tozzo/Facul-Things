package Banco;

public class TesteBanco {

	public static void main(String[] args) {
		
		Banco banco = new Banco();
		Cliente cliente;
		
		//=================================================//
		
		Cliente arrombado = new Cliente("Arrombado","Jr");
		banco.adicionarCliente(arrombado);
		cliente = banco.getCliente(0);
		cliente.addConta(new ContaCorrente(500.00,200.00));
		
		//================================================//
		
		Cliente bruno = new Cliente("Bruno", "Henrique");
		banco.adicionarCliente(bruno);
		cliente = banco.getCliente(1);
		cliente.addConta(new ContaCorrente(300,400));
		cliente.addConta(new ContaPoupanca(20000,1));
		
		//==============================================//
		
		Cliente jorge = new Cliente("Jorge","Mal Jor");
		banco.adicionarCliente(jorge);
		cliente = banco.getCliente(2);
		cliente.addConta(new ContaPoupanca(20458733.00,1.00));
		
		//==============================================//
//		bruno.setConta(contabruno);
//		System.out.println("Saldo do bruno "+bruno.getConta().saldo);
		
//		Conta contaBruno = new Conta(50000);
//		System.out.println("Criando uma conta para " + bruno.getNome() + " " + bruno.getsobreNome()
//				+ " com saldo inicial de " + contaBruno.getSaldo());
//		System.out.println("sacando 1200......" + contaBruno.sacar(1200));
//		contaBruno.depositar(8525);
//		System.out.println("depositando 8525....true" + contaBruno.getSaldo());
//		System.out.println("sacando 12000........" + contaBruno.sacar(12000));
//		System.out.println("sacando 50k........" + contaBruno.sacar(50000));
//		System.out.println("saldo.........." + contaBruno.getSaldo());
		
		System.out.println("\t\t\tRELATÓRIO DE CLIENTES");
	    System.out.println("\t\t\t====================");
	    
	  

	    for (int i = 0; i < banco.getNumeroDeClientes(); i++ ){
	      cliente = banco.getCliente(i);
	      System.out.println();
	      System.out.println("Cliente: " + cliente.getNome() + " "+ cliente.getsobreNome()+" Numero de contas = "+cliente.numeroDeContas());
	      for (int j = 0; j < cliente.numeroDeContas(); j++ ) {
	      	Conta conta = cliente.getConta(j);
		    String  tipoConta = "";

		    
		    if (conta instanceof ContaCorrente) {
		    	tipoConta = "Conta Corrente";
		    }else{
		    	tipoConta = "Conta Poupança";
		    }

		    // Exibe o saldo da conta

		    System.out.println("O saldo da " + tipoConta + " é de R$ " + conta.getSaldo());
	      }
	    }
	}
}
