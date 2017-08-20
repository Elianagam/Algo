from enum import Enum

class Color(Enum):
	rojo = 1
	azul = 2
	verde = 3
	amarillo = 4
	sin_color = 5
	
	def __str__(self):
		if(self == Color.sin_color):
			return "sin color"
		
		return self.name
			
	def listar_colores():
		return list(filter(colores_validos, Color))
		
class EfectosCartas(Enum):
	Sin_Efecto = 1
	Robar_Dos = 2
	Cambiar_Color = 3
	Saltear_Jugador = 4
	Invertir_Sentido = 5
	Robar_Cuatro = 6
	Ronda_Entera_Roba_Una = 7
	
	def __str__(self):
		return self.name.replace('_', ' ')
		
class CartaOrdinaria(Enum):
	# (valor, cantidad_por_color)
	CERO = (0, 1)
	UNO = (1, 2)
	DOS = (2, 2)
	TRES = (3, 2)
	CUATRO = (4, 2)
	CINCO = (5, 2)
	SEIS = (6, 2)
	SIETE = (7, 2)
	OCHO = (8, 2)
	NUEVE = (9, 2)

	def __init__(self, numero, cantidad_por_color):
		self.numero = numero
		self.cantidad_por_color = cantidad_por_color

class CartaEspecial(Enum):
	# (efecto, cantidad_por_color)
	ROBAR_DOS = (EfectosCartas.Robar_Dos, 2)
	INVERTIR_SENTIDO = (EfectosCartas.Invertir_Sentido, 2)
	SALTEAR_JUGADOR = (EfectosCartas.Saltear_Jugador, 2)
	RONDA_ROBA = (EfectosCartas.Ronda_Entera_Roba_Una, 1)
	
	def __init__(self, efecto, cantidad_por_color):
		self.efecto = efecto
		self.cantidad_por_color = cantidad_por_color
	
class Comodin(Enum):
	# (efecto, cantidad total)
	ROBAR_CUATRO = (EfectosCartas.Robar_Cuatro, 4)
	CAMBIAR_COLOR = (EfectosCartas.Cambiar_Color, 4)
	
	def __init__(self, efecto, cantidad):
		self.efecto = efecto
		self.cantidad = cantidad
		
def colores_validos(color):
	return color != Color.sin_color