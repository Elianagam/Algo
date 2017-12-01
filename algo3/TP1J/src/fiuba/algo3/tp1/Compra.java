package fiuba.algo3.tp1;

import java.util.ArrayList;

public class Compra {
	
	private ArrayList<Producto> productos = new ArrayList<Producto>();
	private ArrayList<CostoAdicional> costosadicionales = new ArrayList<CostoAdicional>();
	private double descuento = 0;
	private double bonificacion = 0;

	public int obtenerTotal() {
		int total = 0;
		total += this.obtenerCostodeProductos() + this.obtenerCostosAdicionales();
		
		total -= total * this.descuento;

		if (total >= 5000)
			total -= this.bonificacion;
		return total;
	}

	public void agregarProducto(Producto producto) {
		this.productos.add(producto);
	}

	public void agregarCupon(Cupon cupon) {
		if (this.descuento < cupon.obtenerPorcentaje() ) 
			this.descuento = cupon.obtenerPorcentaje()/100;
	}

	public void conEnvio() {
		Envio envio = new Envio();
		this.costosadicionales.add(envio);
		this.bonificacion = envio.obtenerValor();
	}
	
	public void conGarantia() {
		Garantia garantia = new Garantia(this);
		this.costosadicionales.add(garantia);
	}

	public int obtenerCostodeProductos() {
		int total = 0;
		int cantidad = this.productos.size();
		for (int i = 0; i < cantidad; i++) {
			Producto producto = this.productos.get(i);
			total += producto.obtenerPrecio();
		}
		return total;
	}
	
	public int obtenerCostosAdicionales() {
		int costos = 0;
		int cantidad = this.costosadicionales.size();
		for (int i = 0; i < cantidad; i++) {
			CostoAdicional costo = this.costosadicionales.get(i);
			costos += costo.obtenerValor();
		}
		return costos;
	}

}
