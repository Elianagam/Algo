package fiuba.algo3.tp1.test;

import org.junit.Assert;
import org.junit.Test;

import fiuba.algo3.tp1.Compra;
import fiuba.algo3.tp1.Producto;
import fiuba.algo3.tp1.Cupon;
import fiuba.algo3.tp1.Envio;
import fiuba.algo3.tp1.NumeroNegativoError;


public class CompraTest {
	
	private Compra compra = new Compra();

	@Test
	public void testCompraConEnvioYGarantiaDeUnProductoEsPrecioDelProductoMas100Mas10Porciento() throws NumeroNegativoError {
		
		Producto producto = new Producto("Notebook", 8000);
		this.compra.agregarProducto(producto);
		
		Assert.assertEquals(this.compra.obtenerTotal(), producto.obtenerPrecio());
	}
	
	@Test
	public void testCompraSimpleYElTotalEsCeroPorqueNoSeComproNada() {
		
		Assert.assertEquals(this.compra.obtenerTotal(), 0);
	}
	
	@Test
	public void testCompraSimpleDeUnProductoConCupon() throws NumeroNegativoError {
		
		Producto producto = new Producto("Notebook", 8000);
		this.compra.agregarProducto(producto);
		
		Cupon cupon = new Cupon(50);
		this.compra.agregarCupon(cupon);
		
		double descuento = producto.obtenerPrecio() * cupon.obtenerPorcentaje()/100;
		
		Assert.assertEquals(this.compra.obtenerTotal(), producto.obtenerPrecio() - descuento, 1e-15);
		
	}
	
	@Test
	public void testCompraConEnvioQueNoSuperaLos5000NoEsBonificado() throws NumeroNegativoError {
		
		this.compra.conEnvio();
		Producto producto = new Producto("Notebook", 4000);
		this.compra.agregarProducto(producto);
		
		Envio envio = new Envio();
		
		Assert.assertEquals(this.compra.obtenerTotal(), producto.obtenerPrecio() + envio.obtenerValor(), 1e-15);
	}
	
	@Test
	public void testCompraConEnvioQueSuperaLos5000NoSeBonifica() throws NumeroNegativoError {
		
		this.compra.conEnvio();
		Producto producto = new Producto("Notebook", 8000);
		this.compra.agregarProducto(producto);
		
		
		Assert.assertEquals(this.compra.obtenerTotal(), producto.obtenerPrecio(), 1e-15);
	}
	
	@Test
	public void testCompraConGarantiaEsCostoProductoMas10Porciento() throws NumeroNegativoError {
		
		this.compra.conGarantia();
		Producto producto = new Producto("Notebook", 8000);
		this.compra.agregarProducto(producto);
		
		Assert.assertEquals(this.compra.obtenerTotal(), producto.obtenerPrecio() * 1.1, 1e-15);
	}
}