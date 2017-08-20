def lista_a_dicc(lista1,lista2):

	dicc = {}
	len1 = len(lista1)
	len2 = len(lista2)

	if len1 <= len2:
		menor,mayor = len1,len2
	else:
		menor,mayor = len2,len1
		
	for n in range(mayor):
		if n < menor:
			clave,valor = lista1[n],lista2[n]
		if n >= menor:
			if mayor == len2:
				clave = "Sin Clave"
				valor = lista2[n]
			else:
				valor = "Sin Valor"
				clave = lista1[n]

		if clave in dicc:
			dicc[clave] += [valor]
		else:
			dicc[clave] = [valor]
	print(dicc)

lista_a_dicc([1,2,3],["a","b","c","d","e"])