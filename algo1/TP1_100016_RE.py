NIVEL = [[[1,1,0,1,1],[1,0,1,0,1],[0,1,1,1,0],[1,0,1,0,1],[1,1,0,1,1]],
[[0,1,0,1,0],[1,1,0,1,1],[0,1,0,1,0],[1,0,1,0,1],[1,0,1,0,1]],
[[1,0,0,0,1],[1,1,0,1,1],[0,0,1,0,0],[1,0,1,0,0],[1,0,1,1,0]],
[[1,1,0,1,1],[0,0,0,0,0],[1,1,0,1,1],[0,0,0,0,1],[1,1,0,0,0]],
[[0,0,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[1,1,0,0,0],[1,1,0,0,0]]]
MAX_TABLERO = 10
MIN_TABLERO = 5
ENCENDIDO = 1
APAGADO = 0
P_GANAR = 500
P_PERDER = -300
P_REINICIAR = -50
import random
import copy

def inicio_juego():
	'''Imprime mensaje de bienvenida y pide modo de juego o salir'''
	modo = ["1","2","3"]
	print("Bienvenido al juego.\nMENU:\n1- Predeterminado\n2- Aleatorio\n3- Salir ")
	modo_juego = input("\nIngrese numero segun el modo de juego que quiera jugar.: ")
	while not modo_juego in modo:
		modo_juego = input("Ingrese una opcion valida: ")
		if modo_juego in modo:
			break
	if modo_juego == "1":
		reglas(modo_juego)
		juego_predeterminado()
	elif modo_juego == "2":
		reglas(modo_juego)
		juego_aleatorio()
	else:
		print("Fin del juego")

def reglas(modo_juego):
	'''Imprime las reglas del juego'''
	if modo_juego == "1" or modo_juego == "2":
		print("El objetivo del juego es apagar todas las luces del tablero. Los 1 = encenedido y 0= apagado. Para apagar las luces cuenta con una cantidad limitada de intentos (el triple de las dimensiones del tablero) y se pedira que ingrese las cordenadas del casillero que se desee, y las luces de esas casillas y las cercanas se cambiaran de encendido a apagado o viceversa. Se podra reiniciar el juego en cualquier momento de la partida y se tendra en cuenta los puntos al finalizar.")

def elige_fila(tablero):
	'''pide n? fila o r para reiniciar y seguira preguntando hasta validar condicion, devuelve el fila'''
	fila = input("Ingrese un numero de fila o R para reiniciar: ")
	while ((not fila.isdigit()) or int(fila) > len(tablero) or int(fila) <= 0) and fila.upper() != "R":
		fila = input("Ingrese n? fila nuevamente o R para reiniciar: ")
	if fila.isdigit() and 0 < int(fila) <= len(tablero):
		fila = int(fila)
	else:
		fila = fila.upper()
	return fila

def elige_columna(tablero):
	'''pide columna y hace cambio de letra a n?. sigue preguntando hasta que el n? es del rango del tablero y lo devuelve'''
	columna = ""
	while not columna.isalpha() or not len(columna) == 1 or not 0 <= ord(columna.upper()) - 65 < len(tablero):
		columna = input("Ingrese columna nuevamente: ")
		if len(columna) == 1 and 0 <= ord(columna.upper()) - 65 < len(tablero):
			break
	return ord(columna.upper()) - 65
	
def imprimir_tablero(tablero):
	'''imprime tablero'''
	fila_letras = ["A","B","C","D","E","F","G","H","I","J"]
	print("   ","   ".join(fila_letras[:len(tablero)]),"\n")
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
