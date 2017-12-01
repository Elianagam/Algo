package fiuba.algo3.tp1.test;

import org.junit.Assert;
import org.junit.Test;

import fiuba.algo3.tp1.Cupon;
import fiuba.algo3.tp1.NumeroNegativoError;

public class CuponTest {

	@Test
	public void testCrearCuponConPorcentajeYValorDevuelvePorcentaje() throws NumeroNegativoError {
		
		Cupon cupon = new Cupon(20);
		
		Assert.assertEquals(cupon.obtenerPorcentaje(), 20, 1e-15);
	}
	
	@Test(expected = NumeroNegativoError.class)
	public void testCrearCuponConPorcentajeNegativoLanzaError() throws NumeroNegativoError {
		new Cupon(-20);
		}
}
