import random
from enums import EfectosCartas
from enums import Color
from mazo import Mazo
from jugador_con_mazo import Jugador
from ronda_jugadores import RondaJugadores
import carta_efecto
import sys

SEPARADOR = "=" * 15
CANTIDAD_MINIMA_JUGADORES = 1
CANTIDAD_MAXIMA_JUGADORES = 3
TAMANIO_MANO_INICIAL = 7
NOMBRES_POSIBLES = ["Juan", "Pepe", "Rodrigo", "Juancito", "Miguel", "Rosana", "Gabriela", "Micaela", "Ahmed", "Amy"]

class JuegoUno:
	def __init__(self):
		self.pila_cartas = Mazo()
		self.pila_descarte = Mazo()
		self.ronda = RondaJugadores()
		self.cantidad_jugadores = 0
			
	def inicializar_juego(self):
		''' Crea el mazo inicial de cartas con el que se va a jugar el juego, pregunta cuantos jugadores participarán
			y los agrega a la ronda '''
		self.pila_cartas.inicializar_mazo_uno()
		self.pila_cartas.mezclar()
		print(SEPARADOR)
		print("Bienvenido al juego de UNO!")
		nombre_jugador = input("Ingrese por favor su nombre para jugar: ").title()
		self.cantidad_jugadores = self._pedir_jugadores()
		print("La cantidad de jugadores total es: {}".format(self.cantidad_jugadores))
		self.inicializar_jugadores(nombre_jugador)
		self.repartir_cartas_iniciales()
		self.pila_descarte.agregar_carta(self.pila_cartas.levantar_carta())
			
	def jugar(self):
		''' Va turno por turno en cada jugador, pidiendo una acción, haciendo lo que haga falta en base a esa acción
			y chequeando ganador de juego antes de pasar al siguiente turno '''
		iterador = iter(self.ronda)
		while True:
			jugador = next(iterador)
			carta_descarte = self.pila_descarte.ver_ultima_carta()
			# empiezo a iterar infinitamente hasta que alguien haya ganado.
			print(SEPARADOR)
			print("Es el turno de {}\n".format(jugador.nombre))
			input("Presione ENTER para proceder con el turno.")
			print("La ultima carta en la pila de descarte es: [{}]\n".format(carta_descarte))
			carta_jugada = jugador.accion(self.pila_cartas, self.pila_descarte)
			print("Cantidad de cartas en mazo: {}\n".format(len(self.pila_cartas)))
			if carta_jugada:
				print("Se agrega a la pila de descarte la carta: [{}]".format(carta_jugada))
				self.pila_descarte.agregar_carta(carta_jugada)
				if jugador.chequeo_si_gane():
					print("GAME OVER!!")
					print("{} descartó su última carta y ha ganado el juego. Woohoo!".format(jugador.nombre))
					sys.exit()
				# para que chequee si ganó antes de, por ejemplo, saltear al siguiente jugador.
				else:
					self.aplicar_efecto(carta_jugada.efecto, jugador, iterador)
			
	def inicializar_jugadores(self, nombre_jugador_humano):
		''' Agrega jugadores a la ronda '''
		self.ronda.agregar_jugador(nombre_jugador_humano, True)
		for i in range(self.cantidad_jugadores - 1):
			nombre = random.choice(NOMBRES_POSIBLES)
			print("Agregando a {}".format(nombre))
			self.ronda.agregar_jugador(nombre, False)
			
	def repartir_cartas_iniciales(self):
		''' Reparte la mano inicial a cada jugador '''
		print("Repartiendo cartas para comenzar a jugar...")
		manos_repartidas = 0
		for jugador in self.ronda:
			for carta_por_repartir in range(TAMANIO_MANO_INICIAL):
				carta = self.pila_cartas.levantar_carta()
				jugador.mano_cartas.agregar_carta(carta)
			manos_repartidas += 1
			if manos_repartidas == self.cantidad_jugadores:
				break
				
	
	def _pedir_jugadores(self):
		''' Pide al usuario cuántos jugadores jugarán con el '''
		cantidad_jugadores = input("Ingrese por favor la cantidad de jugadores no humanos (entre {} y {}): ".format(CANTIDAD_MINIMA_JUGADORES, CANTIDAD_MAXIMA_JUGADORES))
		if cantidad_jugadores.isdigit() and (CANTIDAD_MINIMA_JUGADORES <= int(cantidad_jugadores) <= CANTIDAD_MAXIMA_JUGADORES):
			return int(cantidad_jugadores) + 1 # más el jugador humano
			
		print("Ha ingresado un valor inválido. Intente nuevamente.")
		self._pedir_jugadores()
		
	def cambiar_color(self, jugador_actual):
		''' toma la última carta de la pila de descarte y le "pinta" un nuevo color, 
			para poder cambiar el color de la ronda '''
		ultima_carta_descartada = self.pila_descarte.levantar_carta()
		colores = Color.listar_colores()
		es_humano = jugador_actual.es_humano()
		if es_humano:
			self.mostrar_colores(colores)
		color = self.preguntar_color(jugador_actual.es_humano(), len(colores))
		print("Se cambia el color de la ronda a {}".format(color.name))
		ultima_carta_descartada.aplicar_color(color)
		self.pila_descarte.agregar_carta(ultima_carta_descartada)
			
	def preguntar_color(self, es_humano, cantidad_colores):
		if es_humano:
			eleccion = input("Seleccione un color del listado: ")
			if eleccion.isdigit() and 0 < int(eleccion) <= cantidad_colores:
				return Color(int(eleccion))
			
			print("Selección incorrecta. Intente nuevamente.")
			self.preguntar_color(es_humano, cantidad_colores)
		else:
			return Color(random.randint(1, cantidad_colores))
			
	def mostrar_colores(self, colores):
		for color in colores:
			print("{} - {}".format(color.value, color.name))
		
	def aplicar_efecto(self, efecto, jugador_actual, iterador):
		''' Según la carta jugada, aplica un efecto que modifique el estado de la ronda o los jugadores '''
		if efecto == EfectosCartas.Sin_Efecto:
			pass
		elif efecto == EfectosCartas.Robar_Dos:
			carta_efecto.sumar_dos(self,jugador_actual)
		elif efecto == EfectosCartas.Robar_Cuatro:
			carta_efecto.sumar_cuatro(self,jugador_actual)
			self.cambiar_color(jugador_actual)
		elif efecto == EfectosCartas.Cambiar_Color:
			self.cambiar_color(jugador_actual)		
		elif efecto == EfectosCartas.Invertir_Sentido:
			self.ronda.invertir_sentido()
			print("Se invierte el sentido de la ronda")
		elif efecto == EfectosCartas.Saltear_Jugador:
			jugador_salteado = next(iterador)
			print("Se saltea el turno de {}.".format(jugador_salteado))
		elif efecto == EfectosCartas.Ronda_Entera_Roba_Una:
			for index in range(self.cantidad_jugadores - 1):
				jugador = next(iterador)
				print("{} pierde su turno y roba una carta.".format(jugador))
				carta_efecto.sumar_una(self, jugador)