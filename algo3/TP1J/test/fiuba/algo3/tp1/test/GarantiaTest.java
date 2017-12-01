package fiuba.algo3.tp1.test;

import org.junit.Assert;
import org.junit.Test;

import fiuba.algo3.tp1.Garantia;
import fiuba.algo3.tp1.NumeroNegativoError;
import fiuba.algo3.tp1.Compra;
import fiuba.algo3.tp1.Producto;


public class GarantiaTest {

	@Test
	public void testGarantiaSeAdicionaElCostoYElValorEs10Porciento() throws NumeroNegativoError {
		
		Compra compra = new Compra();
		Producto producto = new Producto("Notebook",8000) ;
		compra.agregarProducto(producto);
		
		Garantia garantia = new Garantia(compra);
		
		Assert.assertEquals(garantia.obtenerValor(), producto.obtenerPrecio() * 10/100, 1e-15);
	}
}
