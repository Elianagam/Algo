from jugador_con_mazo import Jugador

class RondaJugadores:
	''' la ronda de jugadores es una lista circular, doblemente enlazada '''
	class _NodoDoble:
		'''define clase de Nodo Doblemente Enlazado'''
		def __init__(self, jugador):
			'''constructor de nodo, con el  nombre de jugador y referencia nula de prox y anterior'''
			if not isinstance(jugador, Jugador):
				# aplicar para todos los 'nodos'
				raise TypeError("No se usa un jugador")
				
			self.jugador = jugador
			self.prox = None
			self.ant = None
	
	class _IteradorCircularDoble:
		def __init__(self, primero):
			self.actual = primero
			
		def __next__(self):
			# no hay stop iteration porque es circular 
			# arranco por el siguiente, para que al invertir el sentido se haga inmediatamente
			self.actual = self.actual.prox
			nodo = self.actual			
			return nodo.jugador
			
	def __init__(self):
		'''constructor de lista vacia con referencia al ultimo y primer nodo e inicio de contador'''
		self.primero = None
		self.ultimo = None
		self.len = 0
		
	def __iter__(self):
		return self._IteradorCircularDoble(self.primero)
		
	def __len__(self):
		return self.len
	
	def agregar_jugador(self, nombre, es_humano):
		'''agrega un jugador a la ronda de jugadores'''
		nodo = self._NodoDoble(Jugador(nombre, es_humano))
		if not self.primero:
			self.primero = nodo
			self.ultimo = nodo
			
		# el ultimo tiene que referenciar al nuevo como sig, y el primero tambien pero como anterior
		# y el nodo que inserto tiene que referenciar al último y al primero
		nodo.ant = self.ultimo
		nodo.prox = self.primero
		
		self.ultimo.prox = nodo
		self.primero.ant = nodo
		
		self.ultimo = nodo
		self.len += 1

	def invertir_sentido(self):
		'''invierte el sentido de la ronda'''
		anterior = self.primero.ant
		actual = self.primero
		siguiente = self.primero.prox
		for i in range(self.len):
			actual.prox = anterior
			actual.ant = siguiente
			actual = siguiente
			anterior = actual.ant
			siguiente = actual.prox

	def saltar_jugador(self, jugador_a_cambiar):
		''' saltea al siguiente jugador de la ronda '''
		actual = self.primero
		for i in range(len(self)):
			if jugador_a_cambiar is actual.jugador:
				return actual.prox.jugador
			actual = actual.prox