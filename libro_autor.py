import csv

def libros_autor(nombre_archivo):
	dicc = {}
	with open(nombre_archivo,"r") as archivo:
		lectura = csv.reader(archivo)
		for row in lectura:
			libro = row[1]
			autores = row[2].split("-")
			for autor in autores:
				if autor in dicc:
					dicc[autor] += [libro]
				else:
					dicc[autor] = [libro]
	print(dicc)
