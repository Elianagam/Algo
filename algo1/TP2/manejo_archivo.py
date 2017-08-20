import csv
import os

ARCHIVO_NOTAS = "notas.csv"
ARCHIVO_HTML = "notas.html"
ARCHIVO_ESTILOS = "html-style.txt"
MODO_LECTURA = "r"
MODO_ESCRITURA = "w"
HEADER_KEY_DICT = "etiqueta"
HEADER_VALUE_DICT = "nota"

def guardar_notas(notas):
	''' Guarda el diccionario de notas en el archivo ARCHIVO_NOTAS '''
	headers = [HEADER_KEY_DICT, HEADER_VALUE_DICT]	
	csv.Dialect.delimiter = "|"
	
	with open(ARCHIVO_NOTAS, MODO_ESCRITURA, newline = '') as archivo:
		writer = csv.DictWriter(archivo, fieldnames = headers, delimiter = csv.Dialect.delimiter)
		for etiqueta, notas_etiqueta in notas.items():
			for nota in notas_etiqueta:
				writer.writerow({HEADER_KEY_DICT: etiqueta, HEADER_VALUE_DICT: nota})
	
def traer_notas():
	''' Abre el archivo en modo lectura y devuelve un diccionario de notas '''
	diccionario = {}
	if not os.path.exists(ARCHIVO_NOTAS):
		return diccionario
	
	csv.Dialect.delimiter = "|"
	with open(ARCHIVO_NOTAS, MODO_LECTURA) as archivo:
		csv_reader = csv.DictReader(archivo, delimiter = csv.Dialect.delimiter, fieldnames=[HEADER_KEY_DICT, HEADER_VALUE_DICT])
		for row in csv_reader:
			if row[HEADER_KEY_DICT] in diccionario:
				diccionario[row[HEADER_KEY_DICT]].append(row[HEADER_VALUE_DICT])
			else:
				diccionario[row[HEADER_KEY_DICT]] = [row[HEADER_VALUE_DICT]]
		
	return diccionario
		
def convertir_html(notas):
	'''convierte arhivo csv a html'''
	with open(ARCHIVO_HTML, MODO_ESCRITURA) as archivo_html, open(ARCHIVO_ESTILOS, MODO_LECTURA) as str_html:
		archivo_html.write("".join(str_html.readlines()))
		for etiqueta in notas:
			cada_nota = notas.get(etiqueta)
			if etiqueta == "":
				archivo_html.write("<div class=etiqueta>[Sin Etiqueta]</div>")
			if etiqueta != "":
				archivo_html.write("<div class=etiqueta>[{}]</div>".format(etiqueta))
			for nota in cada_nota:
				archivo_html.write("<li>{}</li><br>".format(nota))
		archivo_html.write("</body>")
		
	print("Notas procesadas correctamente. Se puede encontrar en {}".format(ARCHIVO_HTML))