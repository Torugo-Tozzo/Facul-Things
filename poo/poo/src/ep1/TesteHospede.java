package ep1;

//import java.util.*;

public class TesteHospede {
	/*
	 * empty space empty space empty space empty space empty space empty space empty
	 * space empty space empty space empty space empty space empty space empty space
	 * empty space empty space empty space empty space
	 */

	public static void main(String[] args) {

		Endereco end1 = new Endereco("rua pqp", "477", "jardim joao russo", "Itaponga");
		// Hospede hosp4 = new Hospede("Thiago", "Ventura");

		Hospede hosp1 = criarHospede("Guardinha", "Gordo", end1);
		hosp1.setEndereco(end1);
		mostraDados(hosp1);

		// Endereco end2 = new Endereco("rua poop", "123", "jardim porco doido",
		// "Itaquatininga");

//		String nome = "jobinha";
//		String comprimento = nome.replace("a", "o");
//		System.out.println(comprimento);

//		Escowpow metodo = new Escowpow();
//		metodo.metUm();

		// System.out.println(end1.mostraBairro());
	}

	public static Hospede criarHospede(String nome, String sobrenome, Endereco x) {
		if (x == null) {
			return new Hospede(nome, sobrenome);
		} else {
			return new Hospede(nome, sobrenome, x);
		}

	}

	public static void mostraDados(Hospede hosp4) {
		System.out.println(hosp4.getNome()+" "+hosp4.getSobreome());
		System.out.println(hosp4.getEndereco().mostraBairro()+" , "+hosp4.getEndereco().mostraCidade());
	}

}
