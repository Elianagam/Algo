package fiuba.algo3.tp1;

public class Garantia extends CostoAdicional {
	
	private Compra compra;

	public Garantia(Compra compra) {
		this.compra = compra;
	}
	
	@Override
	public double obtenerValor() {
		return this.compra.obtenerCostodeProductos() * 10/100;
	}

}
