from carta import Carta
from enum import Enum
import enums
import random

class Mazo:
	
	def __init__(self):
		self.mazo = []

	def __iter__(self):
		return iter(self.mazo)
		
	def __str__(self):
		return str(list(map(str, self.mazo)))
		
	def __len__(self):
		return len(self.mazo)
		
	def mezclar(self):
		''' Mezcla el mazo de cartas con un orden aleatorio '''
		return random.shuffle(self.mazo)

	def agregar_carta(self, carta):
		''' Agrega una carta al final del mazo. '''
		return self.mazo.append(carta)
		
	def levantar_carta(self):
		''' Toma la última carta del mazo y la retira de la colección '''
		if self.esta_vacio():
			#dejar la ultima carta del mazo de descarte, agregarlas al mazo y mezclar
			# este check lo tiene que hacer el Juego, no el Mazo
			raise IndexError("El mazo no tiene cartas!")
		return self.mazo.pop()
		
	def esta_vacio(self):
		''' Chequea si el mazo no tiene cartas. '''
		return len(self.mazo) == 0
		
	def ver_ultima_carta(self):
		''' Muestra cual es la última carta del mazo '''
		return self.mazo[-1]

	def remove(self,valor):
		''' Elimina una carta del mazo según el valor. '''
		if not valor in self.mazo:
			raise ValueError("El mazo no contiene esa carta")
		return self.mazo.remove(valor)

	def dar_vuelta(self, pila_descarte):
		''' Cuando un mazo no tiene más cartas, se toma otra pila y se intercambian los mazos.
			Pila de descarte termina con una sola carta y el mazo con las cartas del descarte. '''
		print("Dando vuelta el mazo, no hay suficientes cartas.")
		ultima_carta_descartada = pila_descarte.levantar_carta()
		# print("Carta a agregar en nueva pila de descarte: [{}]".format(ultima_carta_descartada))
		self = pila_descarte
		self.mezclar()
		pila_descarte = Mazo()
		pila_descarte.agregar_carta(ultima_carta_descartada)
		return self, pila_descarte
	
		
	def inicializar_mazo_uno(self):
		''' Crea un mazo de UNO en base a las reglas del juego. '''
		if not self.esta_vacio():
			raise ValueError("El mazo ya fue creado.")
		
		# Cartas comunes.
		for carta in enums.CartaOrdinaria:
			for ronda in range(carta.cantidad_por_color):
				# una por cada color.
				for color in enums.Color.listar_colores():
					self.mazo.append(Carta(carta.numero, color, enums.EfectosCartas.Sin_Efecto))

		# Cartas Especiales
		for carta in enums.CartaEspecial:
			for ronda in range(carta.cantidad_por_color):
				for color in enums.Color.listar_colores():
					self.mazo.append(Carta(None, color, carta.efecto))

		# Comodines
		for comodin in enums.Comodin:
			for cantidad in range(comodin.cantidad):
				self.mazo.append(Carta(None, enums.Color.sin_color, comodin.efecto))