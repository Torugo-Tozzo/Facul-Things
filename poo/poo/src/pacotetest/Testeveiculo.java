package pacotetest;

public class Testeveiculo {
	
	public static void main(String[] args) {
		Veiculo carro1 = new Veiculo(1000.0*9.8);
		
		System.out.println("colocando 800 N no carro ........" + carro1.addBox(800*9.8));
		System.out.println("colocando 10 N no carro ....." + carro1.addBox(10*9.8));
		System.out.println("colocando 50 N no carro....." + carro1.addBox(50*9.8));
		System.out.println("colocando 175 N no carro......." + carro1.addBox(175*9.8));
		
		System.out.println("carga do bangui = " + carro1.getCarga() + "Newtons" );
		
		
		
		
		
	}

}
