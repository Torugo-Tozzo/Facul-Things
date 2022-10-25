package Points;

public class TestePontos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pontos primeiroPonto = new Pontos(200, 200);
		Pontos segundoPonto = new Pontos(400, 230);
		System.out.println("Coords do ponto 2:  (" + primeiroPonto.getx() + ") , (" + primeiroPonto.gety() + ")");
		System.out.println("Coords do ponto 2:  (" + segundoPonto.getx() + ") , (" + segundoPonto.gety() + ")");

		System.out.println("===========================================");
		System.out.println("criando novo ponto");
		Pontos outraRefSegundoPonto = new Pontos(400, 230);

		System.out.println("Coords do ponto 1:  (" + primeiroPonto.getx() + ") , (" + primeiroPonto.gety() + ")");
		System.out.println("Coords do ponto 2:  (" + segundoPonto.getx() + ") , (" + segundoPonto.gety() + ")");
		System.out.println("Coords do ponto ref do 2:  (" + outraRefSegundoPonto.getx() + ") , ("
				+ outraRefSegundoPonto.gety() + ")");
		System.out.println("====================================");
		System.out.println("mudando as coords do ponto 2 para --> (840,350)");
		segundoPonto.setx(840);
		segundoPonto.sety(350);
		System.out.println("========================");
		System.out.println("Coords do ponto 1:  (" + primeiroPonto.getx() + ") , (" + primeiroPonto.gety() + ")");
		System.out.println("Coords do ponto 2:  (" + segundoPonto.getx() + ") , (" + segundoPonto.gety() + ")");
		System.out.println("Coords do ponto ref do 2:  (" + outraRefSegundoPonto.getx() + ") , ("
				+ outraRefSegundoPonto.gety() + ")");
		
	}

}
