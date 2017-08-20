from Grafo import Grafo
import heapq
from collections import deque
import sys

N_SIMILAR = 3
POS_ID = 1
POS_CANT = 2
MODO_ENTRADA = "r"
MAX_COMUNIDADES = 2000
MIN_COMUNIDADES = 4
MAX_ITERACION = 5
#Factores de random walks. Deciden el largo y el total de iteraciones basado en la cantidad necesaria
FAC_LARGO = 2
FAC_N = 5

def validar_cant_comandos(comandos, cant_requerida):
	len = len(comandos)
	if len != cant_requerida:
		print("Error en la cantidad de comandos")
		return False
	return True

def main():
	if len(sys.argv) < 2:
		print("Error en numero de argumentos")
	grafo = Grafo(False)
	archivo = argv[1]
	abrir_archivo(grafo,archivo)
	
	comando = input().lower().split()
	if comando[0] == "estadisticas":
		estadisticas(grafo)
	if comando[0] == "comunidades":
		label_propagation(grafo)
	if comando[0] == "distancias":
		if validar_cant_comandos(comandos,2):
			distancias(grafo,comando[POS_ID])
	if comando[0] == "caminos":
		if validar_cant_comandos(comandos,3):
			caminos(grafo, comando[POS_ID], comando[POS_CANT])
	if comando[0] == "centralidad":
		if validar_cant_comandos(comandos,3):
			centralidad_exacta(grafo, comando[POS_ID], comando[POS_CANT])
	if comando[0] == "recomendar":
		if validar_cant_comandos(comandos,3):
			recomendar(grafo, comando[POS_ID], comando[POS_CANT])
	if comando[0] == "similares":
		if validar_cant_comandos(comandos,3):
			similares(grafo, comando[POS_ID], comando[POS_CANT])
	else:
		print("ARGUMENTO INVALIDO")
	
	
	
	
def abrir_archivo(grafo,archivo):
	with open (archivo,MODO_ENTRADA) as archivo:
		for linea in archivo:
			if linea[0] != "#":
				v1,v2 = linea.rstrip("\n").split("\t")
				if not grafo.existe_vertice(v1):
					grafo.agregar_vertice(v1)
				if not grafo.existe_vertice(v2):
					grafo.agregar_vertice(v2)
				if not grafo.son_adyacentes(v1,v2):
					grafo.agregar_arista(v1,v2)

def estadisticas(grafo):
	cant_vertices = grafo.cantidad_vertices()
	cant_aristas = grafo.cantidad_aristas()
	print("Cantidad de vertices: {}, Cantidad de Aristas: {}".format(cant_vertices,cant_aristas))
	promedio = 0
	if not cant_vertices == 0:
		promedio = cant_aristas / cant_vertices
	print("Promedio de grado de entrada de cada vertice: {}".format(promedio))
	print("Promedio de grado de salida de cada vertice: {}".format(promedio))
	densidad = 0
	if not cant_vertices == 0:
		#si el grado es dirigido
		densidad = cant_aristas/(vertices* (vertices-1))
		if not grafo.es_dirigido():
			densidad *= 2
	print("densidad: ",densidad)

#Devuelve una lista con un recorrido al azar de un largo dado, desde un origen pasando por sus adyacentes y asi.
#Si el origen no existe(None) el recorrido comienza desde un vertice al azar
def walk (grafo, origen, largo):
	recorrido = []
	i = 0
	if not origen == None:
		recorrido.append(origen)
		i = 1
	actual = origen
	while i < largo:
		actual = grafo.vertice_ady_aleatorio(actual)
		recorrido.append(actual)
		i += 1
	return recorrido

#devuelve un diccionario que almacena la cantidad de vertices que aparecieron en una iteracion de random walks.
#Desde un vertice origen (que puede ser None para iniciar en cualquier lado), efectua n random walks de largo dado.
def iterar_walks (grafo, origen, largo, n):
	visitados = {}
	for i in range(0, n):
		camino = walk(grafo,origen,largo)
		for v in camino:
			if not v in visitados:
				visitados[v] = 0
			visitados[v] += 1
	return visitados

def similares(grafo, actual, cant):
	if not grafo.existe_vertice(actual):
		print("No existe vertice")
		return
	similares = iterar_walks(grafo, actual, cant*FAC_LARGO, cant*FAC_N)
	#crear lista con mas similares
	lista_mas_similares = []
	i = 0
	while i < cant:
		maximo = max(similares.iterkeys(), key= lambda clave: similares[clave])
		lista_mas_similares.append(maximo)
		del similares[maximo]
		i += 1
	return lista_mas_similares
	
#Recomendar es parecido a similares, salvo que devuelve aquellos que no son adyacentes al actual.
def recomendar(grafo, actual, cant):
	if not grafo.existe_vertice(actual):
		print("No existe vertice")
		return
	ady = grafo.adyacentes(actual)
	lista_recomendar = similares(grafo, actual, cant+len(ady))
	#Empezamos eliminando todos los adyacentes que puedan encontrarse
	for w in ady:
		if w in lista_recomendar:
			lista_recomendar.remove(w)
	#Si tras eliminar los adyacentes el tamano de lista_recomendar sigue siendo mayor a cant
	#eliminamos los ultimos de la lista (los menos recomendables).
	while len(lista_recomendar) > cant:
		lista_recomendar.pop()

	return lista_recomendar

def dfs(grafo, actual, visitados = []):
	"""itera en profundidad"""
	if len(visitados) == grafo.cantidad_vertices():
		return visitados
	visitados.append(actual)
	for w in grafo.adyacentes(actual):
		dfs(grafo, w,visitados,cant_corte,cont +1)

def bfs(grafo, inicio, funcion, extra):
	"""itera en anchura la cantidad de vertices"""
	visitados, pila = {}, [inicio]
	bool = funcion(visitados, inicio, None, extra)
	while len(pila) > 0 and bool:
		actual = pila.pop()
		for w in grafo.adyacentes(actual):
			if not w in visitados:
				bool = funcion(visitados, w, actual, extra)
				if not bool:
					break
				pila.append(w)
	return visitados


def caminos(grafo, origen, final):
	#Es esto posible? Recies estudio esto de lambda
	def funcion(tabla, x, padre, extra) : 
		tabla[x] = padre
		return not x == extra
	
	recorrido = bfs(grafo, origen, funcion, final)

	#luego de hacer todo el recorrido
	camino = []
	actual = final
	while not actual == NULL:
		camino.insert(0, actual) 
		actual == recorrido[actual]
	return camino

def distancias(grafo, origen):
	
	def funcion (hash, x, padre, extra) : 
		if padre == None:
			hash[x] = 0
		else:
			hash[x] = hash[padre] + 1
		return true

	recorrido = bfs(grafo, origen, funcion, None)

	contador = {}
	for v in recorrido:
		if not recorrido[v] in contador:
			contador[recorrido[v]] = 0
		contador[recorrido[v]] += 1

	#Aqui comienza la impresion	
	print("Distancias {}".format(origen))
	int = 1
	while contador.has_key(int):
		print("Distancia {}: {}".format(int,contador[int]))
		int +=1

def centralidad_exacta(grafo, n):	
	recorridos = {} #O(1)
	for v in grafo.vertice: #O(v)*
		for w in grafo.vertice: #O(v)*	
			camino = caminos(grafo, v, w) #T(caminos) = O(v+e)
			for i in camino: #O(len(camino))
				#filtra los extremos
				if i == v or i == w:
	      				continue
				if not i in recorridos:
					recorridos[i] = 0
				recorridos[i] += 1
	#O(v2*(v+e))
	centrales = []
	x = 0
	while x < n: #O(n)*
		maximo = max(recorridos.keys(), key=(lambda clave: recorridos[clave])) #T(max) = O(n)
		centrales.append(maximo)
		del recorridos[maximo]
		x += 1
	#O(n2)
	return centrales

def centralidad_random_walks(grafo, n):
	recorridos = iterar_walks(grafo, None, n*FAC_LARGO, n*FAC_N)
	centrales = []
	i = 0
	while i < cant:
		maximo = max(similares.iterkeys(), key=(lambda clave: similares[clave]))
		centrales.append(maximo)
		del similares[maximo]
		i += 1
	return centrales



def label_propagation (grafo):		
	label = {}	
	#inicializamos
	vertices = grafo.vertices()
	i = 0	
	for v in vertices:	#O(V)
		label[v] = i
		i += 1
	      
	for j in range(MAX_ITERACION): #O(MAX_ITERACION)*
		for v in vertices: #O(V)*
			#Crea una tabla para almacenar las frecuencias de los labels de los adyacentes
			freq = {}
			for w in grafo.adyacentes(v): #O(ady) ~ O(E/V) *
		      		if not label[w] in freq:	
					freq[label[w]] = 0
				freq[label[w]] += 1
			#O(E/V)
			#Devuelve el label con la mayor frecuencia
			lmax = max(freq.iterkeys(), key=(lambda clave: freq[clave])) #O(E/V)
			label[v] = lmax
	#O(V*E/V) = O(E)
	comunidad = {}
	for w in vertices:	#O(V)
		if not label[w] in comunidad:	#hash. O(1)
			comunidad[label[w]] = []
		comunidad[label[w]].append(w)
	#~O(V)
	
	comun = comunidad.keys()
	
	for v in comun: #O(comunidad)
	      lon = len(comunidad[v])
	      if (MIN_COMUNIDADES < lon < MAX_COMUNIDADES):
	      		for elem in comunidad[v]:
	      			print(elem)
	 
	#Las comunidades son aquellos grupos de vertices que tienen el mismo label

