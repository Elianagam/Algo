package fiuba.algo3.tp1;

import java.util.ArrayList;

public class AlgoBay {
	
	private ArrayList<Producto> productos = new ArrayList<Producto>();
	private int cantidaddeproductos = 0; 

	public int getCantidadDeProductos() {
		return this.cantidaddeproductos;
	}
	
	public Producto agregarProductoConPrecio(String nombreproducto, int precioproducto) {
		Producto producto = null;
		try {
			producto = new Producto(nombreproducto, precioproducto);
		} catch (NumeroNegativoError exception) {
			exception.getMessage();
			exception.printStackTrace();
		}
		this.cantidaddeproductos++;
		this.productos.add(producto);
		return producto;
	}

	public Producto getProducto(String nombreproducto) {
		Producto producto = null;
		int i;
		try {
			for(i = 0; i < this.cantidaddeproductos; i++) {
				producto = this.productos.get(i);
				if ( producto.obtenerNombre() == nombreproducto) 
					return producto;
			}
			if (this.cantidaddeproductos == 0 || i == this.cantidaddeproductos) {
				throw new InexistenteError("No existe el producto en AlgoBay");
			}
			
		} catch (InexistenteError exception) {
			System.out.println(exception.getMessage());
		}
		return producto;
	}

	public Compra crearNuevaCompra() {
		return new Compra();
	}

	public void agregarProductoEnCompra(Producto producto, Compra compra) {
		compra.agregarProducto(producto);
	}

	public int getPrecioTotalDe(Compra compra) {
		return compra.obtenerTotal();
	}

	public Compra crearNuevaCompraConEnvio() {
		Compra compra = new Compra();
		compra.conEnvio();
		return compra;
	}

	public Compra crearNuevaCompraConGarantia() {
		Compra compra = new Compra();
		compra.conGarantia();
		return compra;
	}

	public Compra crearNuevaCompraConEnvioYGarantia() {
		Compra compra = new Compra();
		compra.conEnvio();
		compra.conGarantia();
		return compra;
	}

	public Cupon crearCuponConPorcentaje(int porcentaje) {
		Cupon cupon = null;
		try {
			cupon = new Cupon(porcentaje);
		} catch (NumeroNegativoError exception) {
			exception.getMessage();
		}
		return cupon;
	}

	public void agregarCuponEnCompra(Cupon cupon, Compra compra) {
		compra.agregarCupon(cupon);
	}

}
