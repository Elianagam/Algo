def ar(archivo):
	dicc = {}
	with open(archivo,"r") as archivo:
		for linea in archivo:
			linea = linea.rstrip("\n").split()
			for palabra in linea:
				if palabra in dicc:
					dicc[palabra] += 1
		
				else:
					dicc[palabra] = 1
	return dicc

def mayor(numero,dicc):
	lista = []
	#lista2 = []
	#n = 0
	for key,value in dicc.items():
		dos = (value,key)
		lista.append(dos)

	lista.sort()
	lista.reverse()

	while len(lista) > numero:
		lista.pop()

	return lista


def main(archivo,numero):
	dicc = ar(archivo)
	print(dicc)
	lis = mayor(numero,dicc)
	print(lis)

main("ar.txt",3)