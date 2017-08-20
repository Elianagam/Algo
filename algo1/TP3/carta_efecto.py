import jugador_con_mazo
from mazo import Mazo
import enums

UNA = 1
DOS = 2
CUATRO = 4



def sumar_cartas(juego,jugador,cartas_sumar):
	'''el jugador actual agrega a su mazo la cantidad de cartas indicada'''
	mostrar = []
	jugador = juego.ronda.saltar_jugador(jugador)
	print("\n{} tiene que levantar {} cartas\n".format(jugador.nombre,cartas_sumar))
	try:
		for i in range(cartas_sumar):
			carta = juego.pila_cartas.levantar_carta()
			jugador.mano_cartas.agregar_carta(carta)
			mostrar.append(carta)
	except IndexError:
		juego.pila_cartas.dar_vuelta(juego.pila_descarte)
		for i in range(cartas_sumar - len(mostrar)):
			carta = juego.pila_cartas.levantar_carta()
			jugador.mano_cartas.agregar_carta(carta)

def sumar_cuatro(juego,jugador):
	'''el jugador levanta 4 cartas del mazo'''
	sumar_cartas(juego, jugador, CUATRO)

def sumar_dos(juego,jugador):
	'''el jugador levanta 2 cartas del mazo'''
	sumar_cartas(juego, jugador, DOS)
	
def sumar_una(juego, jugador):
	'''el jugador levanta 1 carta del mazo'''
	sumar_cartas(juego, jugador, UNA)