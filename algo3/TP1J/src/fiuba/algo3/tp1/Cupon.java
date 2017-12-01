package fiuba.algo3.tp1;

public class Cupon {

	private int porcentaje;
	
	public Cupon(int porcentaje) throws NumeroNegativoError {
		if (porcentaje < 0)
			throw new NumeroNegativoError("El porcentaje no puede ser Negativo");
		this.porcentaje = porcentaje;
	}
	public double obtenerPorcentaje() {
		return this.porcentaje;
	}
}
