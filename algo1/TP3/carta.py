from enum import Enum
import enums

class Carta:
	def __init__(self, numero, color, efecto):
		if not isinstance(color, enums.Color):
			raise TypeError("Color no existente")
		if numero is not None and not isinstance(numero, int):
			raise ValueError("Número erróneo.")
		self.numero = numero
		self.color = color
		self.efecto = efecto
		
	def __str__(self):
		texto = ""
		if not self.numero and self.color is enums.Color.sin_color:
			texto = "Comodin: {}".format(self.efecto)
		elif self.numero is None:
			texto = "{} - {}".format(self.color, self.efecto)
		else:
			texto = "{} - {}".format(self.color, self.numero)
			
		return texto
		
	def aplicar_color(self, color):
		self.color = color