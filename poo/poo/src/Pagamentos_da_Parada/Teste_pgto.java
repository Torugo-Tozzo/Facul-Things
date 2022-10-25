package Pagamentos_da_Parada;

import Banco.Cliente;

public class Teste_pgto {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Teste_pgto pt = new Teste_pgto();

		Pgto_debito cliente1 = new Pgto_debito(100, "Santander", "123.123.123-7", "Jober S. Saintiana");
		System.out.println(cliente1.detalhes());

		System.out.println("=================================================\n");

		Pgto_credito cliente2 = new Pgto_credito(5000, "Aron Badow", "123,12345,6-8", "Jorge Luis Fraududdo");
		System.out.println(cliente2.detalhes());

		System.out.println("\n================ Chamando metodos de Payment ===================\n");
		Pgto_credito pc = new Pgto_credito(327.75, "MasterCard", "543218975-5", "Joao Kleber");
		pt.processaPgto(pc);

		Pgto_debito pd = new Pgto_debito(800, "do Brasil", "12345678910", "Joao Paulo do Kumanso");
		pt.processaPgto(pd);

		System.out.println("\n=================================================\n");

	}

	public void processaPgto(Pgto_cartoes pn) {
		// System.out.println(pn.detalhes());
		if (pn instanceof Pgto_credito) {
			Pgto_credito pc = (Pgto_credito) pn;
			System.out.println(pc.detalhes());
		} else if (pn instanceof Pgto_debito) {
			Pgto_debito pd = (Pgto_debito) pn;
			System.out.println(pd.detalhes());
		}
	}

}
