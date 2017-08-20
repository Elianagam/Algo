import manejo_archivo
 
CANTIDAD_MAXIMA_PALABRAS_ETIQUETA = 1
CARACTER_SALIDA = "0"
SEPARADOR = "-" * 15
 
def agregar_notas(notas):
	'''devuelve creacion de diccionario con notas por etiquetas'''
	etiqueta = ""
	print("Ha decidido agregar nuevas notas. Puede opcionalmente agregar una etiqueta [una sola palabra, sin espacios]")
	while True:
		etiqueta = input("Etiquetar como ({} para terminar): ".format(CARACTER_SALIDA)).strip().lower()
		if etiqueta == CARACTER_SALIDA:
			break
		if(not etiqueta_valida(etiqueta)):
			print("Ha ingresado una etiqueta no válida. Recuerde, la etiqueta debe tener una sola palabra, sin espacios.")
			continue
		nota = input("Escribir nota: ")
		if etiqueta in notas:
			notas[etiqueta].append(nota)
		else:
			notas[etiqueta] = [nota]
	manejo_archivo.guardar_notas(notas) 

def etiqueta_valida(etiqueta):
	''' valida que la etiqueta sea correcta (que tenga una sola palabra o menos) '''
	palabras_etiqueta = etiqueta.split()
	return len(palabras_etiqueta) <= CANTIDAD_MAXIMA_PALABRAS_ETIQUETA
	
def buscar_nota(notas):
	''' pide al usuario un termino e imprime por pantalla todas las notas que lo contienen '''
	termino_busqueda = input("Ingrese el texto a buscar en las notas: ").lower()
	resultados = {}
	for etiqueta in notas.keys():
		notas_con_termino = [nota for nota in notas[etiqueta] if termino_busqueda in nota.lower()]
		if len(notas_con_termino) > 0:
			resultados[etiqueta] = notas_con_termino
			
	imprimir_notas(resultados)
			 
def eliminar_nota(notas):
	''' elimina la nota segun lo indicado por el usuario '''
	imprimir_notas(notas)
	etiqueta, notas_etiqueta = pedir_etiqueta(notas)
	
	lista_enumerada(notas_etiqueta)
	que_eliminar = pregunta_que_eliminar(notas_etiqueta)
	if que_eliminar == "":
		print("No se eliminará nada.")
		return
	que_eliminar = int(que_eliminar)
	confirmar_eliminar(notas, etiqueta, notas_etiqueta, que_eliminar)
	manejo_archivo.guardar_notas(notas)
	
def pedir_etiqueta(notas):
	''' pide una etiqueta al usuario para que pueda decidir que nota borrar '''
	que_etiqueta = input("Ingrese una etiqueta: ").lower()
	while not que_etiqueta in (notas.keys()):
		print("Ha ingresado una etiqueta no existente. Intente nuevamente.")
		que_etiqueta = input("Ingrese una etiqueta: ").lower()
		
	notas_etiqueta = list(notas.get(que_etiqueta))
	return que_etiqueta, notas_etiqueta
	
def lista_enumerada(notas_etiqueta):
	''' imprime lista enumerada de notas '''
	print("Seleccione una nota:")
	for n,nota in enumerate(notas_etiqueta,1):
		print("{}- {}".format(n,nota))
	print(SEPARADOR)
		
def pregunta_que_eliminar(notas_etiqueta):
	'''pregunta que nota se quiere eliminar'''
	que_eliminar = input("Cuál desea eliminar? ")
	while not respuesta_que_eliminar_valida(que_eliminar, len(notas_etiqueta)):
		print("Ha ingresado una opción no válida. Intente nuevamente.")
		que_eliminar = input("Cuál desea eliminar? ")
	
	return que_eliminar

def respuesta_que_eliminar_valida(respuesta, cantidad_notas):
	''' Chequea la validez de la respuesta sobre que nota eliminar '''
	return respuesta == "" or (respuesta.isdigit() and 0 < int(respuesta) <= cantidad_notas)
	
def confirmar_eliminar(notas, que_etiqueta, notas_etiqueta, que_eliminar):
	'''confirma que se quiere eliminar la nota y elimina'''
	index_nota_a_eliminar = que_eliminar - 1
	print("\n{}-{}\n{}".format(que_eliminar, notas_etiqueta[index_nota_a_eliminar], (SEPARADOR)))
	confirmar_eliminar = input("Eliminar <SI/NO>? ")
	while True:
		if confirmar_eliminar.upper() == "SI":
			print("Se eliminará la nota '{}'".format(notas_etiqueta[index_nota_a_eliminar]))
			notas[que_etiqueta].pop(index_nota_a_eliminar)
			break
		if confirmar_eliminar.upper() == "NO":
			print("La nota no se eliminará.")
			break
	
		print("Ha ingresado una opción no válida. Intente nuevamente.")
		confirmar_eliminar = input("Eliminar <SI/NO>? ")

def imprimir_notas(notas):
	''' imprime por pantalla el diccionario recibido '''
	if(len(notas.keys()) == 0):
		print("No existe ninguna nota.")
	
	for etiqueta in notas.keys():
		print("[{}]".format(etiqueta if etiqueta else "Sin Etiqueta"))
		for nota in notas[etiqueta]:
			print("- {}".format(nota))
			
def guardar_notas(notas):
	guardar_notas = input("Eliminar <SI/NO>? ")
	while True:
		if guardar_notas.upper() == "SI":
			print("Guardando notas...")
			manejo_archivo.guardar_notas(notas)
			break
		elif guardar_notas.upper() == "NO":
			print("Grabado de notas cancelado.")
			break
			
		print("Ha ingresado una opcion inválida. Intente nuevamente.")
		guardar_notas = input("Eliminar <SI/NO>? ")
	
	
		 