package fiuba.algo3.tp1;

public class Producto {
	
	private String nombre;
	private int precio;

	public Producto(String nombre, int precio) throws NumeroNegativoError {
		if (precio <= 0)
			throw new NumeroNegativoError("El precio no puede ser Negativo");
		this.nombre = nombre;
		this.precio = precio;
	}
	
	public String obtenerNombre() {
		return this.nombre;
	}
	
	public int obtenerPrecio() {
		return this.precio;
	}
}
