from mazo import Mazo
import enums

PRIMERA_CARTA = 0
UNICA_CARTA = 1
SEPARADOR = "=" * 15

class Jugador:
	'''instancia de Jugador'''
	def __init__(self, nombre, humano):
		'''constructor de la clase jugador '''
		self.nombre = nombre
		self.humano = humano 
		self.mano_cartas = Mazo()
		
	def __str__(self):
		return self.nombre
	
	def es_humano(self):
		return self.humano

	def accion(self, pila_cartas, pila_descarte):
		'''se evalua si el jugador tiene cartas que puede descartar, si las tiene:
			para humano pregunta cual descartar, para maquina tira la primera que sea posible.
			si no las tiene levanta una carta'''
		ultima_carta = pila_descarte.ver_ultima_carta()
		lista_cartas_validas = self.cartas_mano_validas(self.mano_cartas,ultima_carta)
		if self.es_humano():
			print(self.mano_cartas)
		
		if len(lista_cartas_validas):
			if self.es_humano():
				self.imprimir_cartas(lista_cartas_validas)

				if len(lista_cartas_validas) == UNICA_CARTA:
					eleccion = lista_cartas_validas[PRIMERA_CARTA]
					print("Se descartara la carta [{}] por ser la unica posible".format(eleccion))
				else:
					eleccion = self.elegir_carta_tirar(lista_cartas_validas)

				self.mano_cartas.remove(eleccion)
				return eleccion

			else:
				carta_a_tirar = lista_cartas_validas[PRIMERA_CARTA] #tira la primera carta del mazo de la maquina, no importa cual sea
				self.mano_cartas.remove(carta_a_tirar)
				#pila_descarte.agregar_carta(a_tirar)
				return carta_a_tirar
				
		else:
			try:
				nueva_carta = pila_cartas.levantar_carta()
			except IndexError:
				# la pila de cartas no tiene más cartas y tiene que darse vuelta
				pila_cartas, pila_descarte = pila_cartas.dar_vuelta(pila_descarte)
				nueva_carta = pila_cartas.levantar_carta()

			print("{} levanta una carta de la pila".format(self.nombre))
			carta_a_tirar = self.chequeo_si_descarto(nueva_carta, ultima_carta)
			return carta_a_tirar

	def chequeo_si_descarto(self, nueva_carta, ultima_carta): 
		''' si la carta que se levanta de la pila_cartas se puede tirar la agrega a la pila_descarte
			de lo contrario la agrega al mazo del jugador '''
		if self.validar_carta_a_descartar(nueva_carta, ultima_carta):
			print("La carta levantada será descartada por ser jugable.")
			return nueva_carta
		else:
			print("La carta levantada del mazo no puede ser jugada. El turno terminó!")
			self.mano_cartas.agregar_carta(nueva_carta)
			return None

	def chequeo_si_gane(self):
		return self.mano_cartas.esta_vacio()

	def cartas_mano_validas(self, mano_cartas,carta_pila_descarte):
		'''evalua que cartas del jugador posibles de tirar en la pila_descarte y crea una lista con ellas'''
		cartas = []
		for carta in mano_cartas:
			if self.validar_carta_a_descartar(carta, carta_pila_descarte):
				cartas.append(carta)
		return cartas

	def imprimir_cartas(self, cartas):
		'''imprime cartas que son posibles superponer al mazo'''
		print("De las cartas de su mazo, estas son las que puede tirar: \n")
		for i, carta in enumerate(cartas, 1):
			print("{} - {}".format(i,carta))

	def elegir_carta_tirar(self, cartas):
		'''pregunta que carta quiere tirar entre las opciones validas'''
		eleccion = input("Ingrese numero de carta que quiera descartar: ")
		if not eleccion.isdigit() or not 0 < int(eleccion) <= len(cartas):
			print("Elección inválida.")
			self.elegir_carta_tirar(cartas)
		carta_eleccion = cartas[int(eleccion) - 1]

		return carta_eleccion

	def validar_carta_a_descartar(self, carta_elegida, carta_pila_descarte):
		''' Según las reglas del juego, chequea si una carta es descartable o no '''
		if carta_elegida.color is carta_pila_descarte.color or carta_elegida.color is enums.Color.sin_color:
			# color o comodín
			return True
		
		if carta_elegida.numero == carta_pila_descarte.numero and carta_elegida.efecto is enums.EfectosCartas.Sin_Efecto:
			return True
		
		if carta_elegida.efecto != enums.EfectosCartas.Sin_Efecto and carta_elegida.efecto == carta_pila_descarte.efecto:
			return True
			
		return False