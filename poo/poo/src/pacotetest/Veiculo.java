package pacotetest;

public class Veiculo {
	private double carga;
	private double cargaMax;

	public Veiculo(double cargaMax) {
		this.cargaMax = cargaMax;
	}

	public double getCarga() {
		return carga;
	}

	public void setCarga(double carga) {
		this.carga = carga;
	}

	public double getCargaMax() {
		return cargaMax;
	}

	public void setCargaMax(double cargaMax) {
		this.cargaMax = cargaMax;
	}

	public boolean addBox(double peso) {

		double temp = this.carga + peso;
		if ((temp) > (this.cargaMax))
			return false;
		this.carga += peso;
		return true;
	
	}

}