package fiuba.algo3.tp1.test;

import org.junit.Assert;
import org.junit.Test;

import fiuba.algo3.tp1.Envio;

public class EnvioTest {

	@Test
	public void testEnvioSeAdicionaElCostoElValorEs100() {
		
		Envio envio = new Envio();
		
		Assert.assertEquals(envio.obtenerValor(), 100,  1e-15);
	}
}
