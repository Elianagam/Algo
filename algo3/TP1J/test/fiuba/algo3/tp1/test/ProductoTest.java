package fiuba.algo3.tp1.test;

import org.junit.Assert;
import org.junit.Test;

import fiuba.algo3.tp1.NumeroNegativoError;
import fiuba.algo3.tp1.Producto;

public class ProductoTest {
	
	@Test
	public void testCrearProductoConPrecioYNombre() throws NumeroNegativoError {
		
		Producto producto =  new Producto("Notebook", 9000);
		
		Assert.assertEquals(producto.obtenerNombre(), "Notebook");
		
		Assert.assertEquals(producto.obtenerPrecio(), 9000);
	}
	
	@Test(expected = NumeroNegativoError.class)
	public void testCrearProductoConPrecioNegativoLanzaError() throws NumeroNegativoError {
	    new Producto("MOTOG",-90);
	}
	
}

