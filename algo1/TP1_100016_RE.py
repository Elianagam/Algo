NIVEL = [
	[[1,1,0,1,1],[1,0,1,0,1],[0,1,1,1,0],[1,0,1,0,1],[1,1,0,1,1]],
	[[0,1,0,1,0],[1,1,0,1,1],[0,1,0,1,0],[1,0,1,0,1],[1,0,1,0,1]],
	[[1,0,0,0,1],[1,1,0,1,1],[0,0,1,0,0],[1,0,1,0,0],[1,0,1,1,0]],
	[[1,1,0,1,1],[0,0,0,0,0],[1,1,0,1,1],[0,0,0,0,1],[1,1,0,0,0]],
	[[0,0,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[1,1,0,0,0],[1,1,0,0,0]]
]
MAX_TABLERO = 10
MIN_TABLERO = 5
ENCENDIDO = 1
APAGADO = 0
P_GANAR = 500
P_PERDER = -300
P_REINICIAR = -50
ASCII_NUMBER = 65
MODO = ["1","2","3"]
FILA_LETRAS = ["A","B","C","D","E","F","G","H","I","J"]
MENSAJE_BIENVENIDA = "Bienvenido al juego.\nMENU:\n1- Predeterminado\n2- Aleatorio\n3- Salir "
MENSAJE_INPUT = "\nIngrese numero segun el modo de juego que quiera jugar.: "
MENSAJE_REGLAS = """El objetivo del juego es apagar todas las luces del tablero. Los 1 = encenedido y 0= apagado. 
		Para apagar las luces cuenta con una cantidad limitada de intentos (el triple de las dimensiones del tablero)
		y se pedira que ingrese las cordenadas del casillero que se desee, y las luces de esas casillas y las cercanas
		se cambiaran de encendido a apagado o viceversa. Se podra reiniciar el juego en cualquier momento de la partida
		y se tendra en cuenta los puntos al finalizar."""
MENSAJE_FIN = "Fin del juego"
MENSAJE_FILA = "Ingrese un numero de fila o R para reiniciar: "
MENSAJE_COLUMNA = "Ingrese columna: "
MODO_PREDETERMINADO = "1"
MODO_ALEATORIO = "2"
import random
import copy

def elegir_modo():
	print(MENSAJE_BIENVENIDA)
	modo_juego = "0"
	while not modo_juego in MODO:
		modo_juego = input(MENSAJE_INPUT)
	return modo_juego

def inicio_juego():
	'''Imprime mensaje de bienvenida y pide modo de juego o salir'''
	modo_juego = elegir_modo()
	if modo_juego == MODO_PREDETERMINADO:
		reglas(modo_juego)
		juego_predeterminado()
	elif modo_juego == MODO_ALEATORIO:
		reglas(modo_juego)
		juego_aleatorio()
	else:
		print(MENSAJE_FIN)

def reglas(modo_juego):
	'''Imprime las reglas del juego'''
	if modo_juego == MODO_PREDETERMINADO or modo_juego == MODO_ALEATORIO:
		print(MENSAJE_REGLAS)

def elige_fila(tablero):
	'''pide n? fila o r para reiniciar y seguira preguntando hasta validar condicion, devuelve el fila'''
	fila = input(MENSAJE_FILA)
	while ((not fila.isdigit()) or int(fila) > len(tablero) or int(fila) <= 0) and fila.upper() != "R":
		fila = input(MENSAJE_FILA)
	if fila.isdigit() and 0 < int(fila) <= len(tablero):
		fila = int(fila)
	else:
		fila = fila.upper()
	return fila

def elige_columna(tablero):
	'''pide columna y hace cambio de letra a n?. sigue preguntando hasta que el n? es del rango del tablero y lo devuelve'''
	columna = ""
	while not columna.isalpha() or not len(columna) == 1 or not 0 <= ord(columna.upper()) - 65 < len(tablero):
		columna = input(MENSAJE_COLUMNA)
		if len(columna) == 1 and 0 <= ord(columna.upper()) - ASCII_NUMBER < len(tablero):
			break
	return ord(columna.upper()) - ASCII_NUMBER
	
def imprimir_tablero(tablero):
	'''imprime tablero'''
	print("   ","   ".join(FILA_LETRAS[:len(tablero)]),"\n")
	for i, elem in enumerate(tablero,1):
		elem = "   ".join(str(num) for num in elem)
		print(i," ", elem,"\n")
		
def apagar_prender(tablero,fila,columna):
	'''devuelve tablero con cambio de luces'''
	posiciones = [(fila - 1, columna),(fila - 1,columna - 1),(fila - 1,columna + 1),(fila - 2,columna),(fila,columna)]
	for posicion in posiciones:
		fil, col = posicion
		if 0 <= fil < len(tablero) and 0 <= col < len(tablero):
			tablero[fil][col] = APAGADO if tablero[fil][col] == ENCENDIDO else ENCENDIDO	
	return tablero
	
def hay_luces_encendidas(tablero):
	'''chequea que haya luces encendidas en tablero'''
	for fila in tablero:
		for col in fila:
			if(col == ENCENDIDO):
				return True
	return False

def obtener_nivel(niv):
	return copy.deepcopy(NIVEL[niv])
		
def juego_predeterminado():
	''''tableros consatantes, durante cantidad de intentos, suma puntos. 
	imprime puntos y mensaje de fin de juego'''
	intentos = 0
	puntos = 0
	niv = 0
	tablero = obtener_nivel(niv)
	while intentos <= (3 * len(tablero)) and niv < len(NIVEL):
		intentos += 1
		imprimir_tablero(tablero)
		fila = elige_fila(tablero)
		if fila != "R":
			columna = elige_columna(tablero)
			tablero = apagar_prender(tablero,fila,columna)
			if not hay_luces_encendidas(tablero):
				puntos += P_GANAR
				niv += 1
				tablero = obtener_nivel(niv)
				intentos = 0
		else:
			puntos += P_REINICIAR
			tablero = obtener_nivel(niv)
			
	gana_pierde(tablero,puntos,intentos)
	
def juego_aleatorio():
	'''Juega de modo aleatorio, con un maximo de intentos, suma puntos y los imprime junto con mensaje de fin de juego'''
	puntos = 0
	intentos = 0
	niv = 0
	tablero = tablero_aleatorio()
	while intentos <= (3 * len(tablero)):
		intentos += 1
		imprimir_tablero(tablero)
		fila = elige_fila(tablero)
		if fila != "R":
			columna = elige_columna(tablero)
			tablero = apagar_prender(tablero,fila,columna)
			if not hay_luces_encendidas(tablero):
				break
		else:
			puntos += P_REINICIAR
			tablero = tablero_aleatorio()
	
	gana_pierde(tablero,puntos,intentos)

def gana_pierde(tablero,puntos,intentos):
	'''imprime ultima modificacion tablero chequea que intentos no supere max y no haya luces encendidas
	imprime mensaje y suma de puntos si gana o pierde, vuelve inicio juego'''
	imprimir_tablero(tablero)
	if intentos > (3 * len(tablero)) and (ENCENDIDO in elem):
		puntos += P_PERDER
		print("Perdiste. Puntos: ",puntos)
	if intentos <= (3 * len(tablero)) and (not ENCENDIDO in elem):
		puntos += P_GANAR
		print("Ganaste. Puntos: ",puntos)
	inicio_juego() 
			
def ingrese_dimension():
	'''pide dimension al usuario que este dentro del rango y devuelve un numero'''
	dim = input("Ingrese la dimension que desee de 5 a 10: ")
	while not (dim.isdigit()) or not MIN_TABLERO <= int(dim) <= MAX_TABLERO:
		dim = input("Ingrese dimension valida: ")
		if dim.isdigit() and MIN_TABLERO <= int(dim) <= MAX_TABLERO:
			break
	return int(dim)

def tablero_aleatorio():
	'''devuelve creacion de tablero, con las dimensiones que pide al usuario, con luces prendidas o apagados aleatoriamente'''
	tablero = []
	fila = []
	dim = ingrese_dimension()				
	while len(fila) < dim:
		num = random.randint(0,1) #crea tablero aleatorio con 0 y 1
		fila.append(num)
		if len(fila) == dim and len(tablero) < dim:
			tablero.append(fila)
			fila = []
	return tablero
	
	
def main():
	'''la composicion total del juego funciona cuando se llama a esta funcion'''
	inicio_juego()
	
main()
