import manejo_archivo
import notas
import sys

SEPARADOR = "-" * 15
OPCIONES_SIN_PARAMETRO = ["7"]
MENU_OPCIONES = {
	"1": ("Agregar Notas", notas.agregar_notas),
	"2": ("Ver todo", notas.imprimir_notas),
	"3": ("Buscar nota", notas.buscar_nota),
	"4": ("Eliminar nota", notas.eliminar_nota),
	"5": ("Guardar notas", notas.guardar_notas),
	"6": ("Convertir a HTML", manejo_archivo.convertir_html),
	"7": ("Salir", sys.exit)
}
OPCION_TEXTO = 0
FUNCION = 1
			
def menu_principal():
	'''se pide al usuario una opcion de que hacer'''
	while True:
		print(SEPARADOR)
		for opcion in sorted(MENU_OPCIONES):
			print("[{}] {}".format(opcion, MENU_OPCIONES[opcion][OPCION_TEXTO]))
		print(SEPARADOR)
		diccionario_notas = manejo_archivo.traer_notas()
		que_hacer = input("Elija opción: ")
		while not que_hacer in MENU_OPCIONES:
			print("Ha elegido una opción incorrecta. Intente nuevamente.")
			que_hacer = input("Elija opción: ")
		
		if que_hacer in OPCIONES_SIN_PARAMETRO:
			MENU_OPCIONES[que_hacer][FUNCION]()
		else:
			MENU_OPCIONES[que_hacer][FUNCION](diccionario_notas)
		
menu_principal()