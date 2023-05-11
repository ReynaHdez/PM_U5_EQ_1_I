// pch.h: este es un archivo de encabezado precompilado.
// Los archivos que se muestran a continuación se compilan solo una vez, lo que mejora el rendimiento de la compilación en futuras compilaciones.
// Esto también afecta al rendimiento de IntelliSense, incluida la integridad del código y muchas funciones de exploración del código.
// Sin embargo, los archivos que se muestran aquí se vuelven TODOS a compilar si alguno de ellos se actualiza entre compilaciones.
// No agregue aquí los archivos que se vayan a actualizar con frecuencia, ya que esto invalida la ventaja de rendimiento.

#ifndef PCH_H
#define PCH_H

// agregue aquí los encabezados que desea precompilar
#include "framework.h"

#endif //PCH_H
int __stdcall suma(int a, int b) {
	int resultado;

	_asm {
		mov eax, 0
		mov eax, a
		mov ebx, b
		add eax, ebx

		mov resultado, eax
	}
	return resultado;
}

int __stdcall resta(int a, int b) {
	int resultado2;

	_asm {
		mov eax, 0
		mov eax, a
		mov ebx, b
		sub eax, ebx

		mov resultado2, eax
	}
	return resultado2;
}

int __stdcall multi(int a, int b) {
	int resultado3;

	_asm {
		mov eax, a
		mul b

		mov resultado3, eax
	}
	return resultado3;
}

int __stdcall largo_cadena(const char* str) {

	int len = strlen(str);

	return len;
}

//Reescribir el contenido de una cadena que se obtuvo dessde c#
int __stdcall escribir_cadena(char* str, int len_buffer) {

	const char* aux = ""; //debe ser menor que len_buffer
	int len = strlen(aux);
	for (int i = 0; i < len; i++) {
		str[i] = aux[i];
	}
	return len;
}

#pragma region PROGRAMAS 2023 1


int __stdcall promedioDeUsuario(char* nombre, int cal1, int cal2, int cal3) {
	//a nombre no se le hara ningun cambio en este programa...
	int prom;
	int pDecimal;
	_asm {
		mov eax, 0
		add eax, cal1
		add eax, cal2
		add eax, cal3
		
		mov edx, 0
		mov ecx, 3
		div ecx

		mov pDecimal, edx
		mov prom, eax
	}
	prom += pDecimal / 3;
	return prom;
}

int __stdcall promUsuario(char* cadRes, char* nombre, int cal1, int cal2, int cal3) {
	int prom;
	int pDecimal;

	_asm {
		mov eax, 0
		add eax, cal1
		add eax, cal2
		add eax, cal3

		mov edx, 0
		mov ecx, 3
		div ecx

		mov pDecimal, edx
		mov prom, eax
	}

	prom += pDecimal / 3;

	int c = 0;
	const char* aux = "tienes un promedio de: ";


	//cadRes = ""
	//agregar a cadRes el nombre del alumno
	int len = strlen(nombre);
	for (int i = 0; i < len; i++)
	{
		cadRes[c] = nombre[i];
		c++;
	}

	//cadRes = CadRes + aux
	//agregar el contenido de aux a cadRes...
	len = strlen(aux);
	for (int i = 0; i < len; i++)
	{
		cadRes[c] = aux[i];
		c++;
	}
	//cadRes = cadRes + prom
	if (prom == 10) {
		cadRes[c] = 49;
		c++;
		cadRes[c] = 48;
	}
	else {
		cadRes[c] = prom + 48;
	}

	c++; //retorna la cantidad de caracteres en la palabra...

	return c;
}

int __stdcall fibunacci(int t0, int t1) {

	int tn;

	_asm {
		mov eax, t0 ;Cargar el primer término en eax
		mov ebx, t1 ;Cargar el segundo término en ebx
		mov ecx, 8 ;Establecer el número de iteraciones

		ciclo :
		add eax, ebx ;Sumar los dos términos previos
			mov tn, eax ;Guardar el resultado en tn
			mov eax, ebx ;Actualizar el primer término
			mov ebx, tn ;Actualizar el segundo término
			loop ciclo
	}
	return tn;
}

int __stdcall areatriangulo(int base, int altura) {
	//int resultmult;
	//int resultado;

	_asm{
		mov eax, base
		mul altura



	}

}

int __stdcall velocidad(char* cadRes, char* nombre, int distancia, int tiempo) {
	//a nombre no se le hara ningun cambio en este programa ...
	//velocidad = distancia / tiempo
	int velocidad;
	int pDecimal;

	_asm {
		mov eax, distancia
		mov ebx, tiempo
		mov edx, 0

		div ebx // eax / ebx  => distancia / tiempo

		mov pDecimal, edx
		mov velocidad, eax
	}

	//velocidad += pDecimal / tiempo;
	int c = 0; //inicio de la cadena resultado     
	c += addCadena2Cadena(cadRes, c, nombre);

	const char* aux = " tiene una velociad de: "; //debe ser menor que len_buffer
	c += addCadena2Cadena(cadRes, c, aux);

	//Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar 
	c += addNum2Cadena(cadRes, c, velocidad);
	//retorna la cantidad de caracteres en la palabra ...
	return c;
}



int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena) {

	int len = strlen(cadena);
	for (int i = 0; i < len; i++) //recorre cada caracter del nombre del carrito
	{
		cadRes[indice] = cadena[i];
		indice++;
	}
	return len;
}




int __stdcall addNum2Cadena(char* cadRes, int indice, int numero) {
	//buscar cuantos digitos tiene la variables
	int tempNumero = numero;
	int cont = 0; //almacena el total de digitos-1
	while (tempNumero >= 10) {
		tempNumero /= 10;
		cont++;
	}

	//X  = 1
	//XX =  10
	//XXX = 100
	//XXXX = 1000

	if (cont >= 1) { //se entra solo cuando son dos o mas digitos los que componen al numero
		int div = 10;
		for (int i = 0; i < cont - 1; i++) { //busca encontrar al divisor
			div = div * 10;
		}

		while (numero > 10) { //obtener el digito mas a la izquierda ... 
			int t = numero / div;
			cadRes[indice] = t + 48;
			indice++;
			numero = numero % div;
			div = div / 10;
		}
		cadRes[indice] = numero + 48;
		indice++;
	}
	else { //con  = 0
		cadRes[indice] = numero + 48;
		indice++;
	}
	return cont + 1;
}

int __stdcall comparaNumeros(char* cadRes, char* nombre, int numero1, int numero2, int totdigitos) {
	
	//compracion digito a digito...
	totdigitos = -1;
	int divisor = 0;
	_asm {
		//numero 1 se queda en memoria
		mov ebx, numero2

		mov ecx, totdigitos

		cmp totdigitos, 1
		jnle continuar

		mov ecx, 0
		mov ebx, 10
		mov eax, 10
		ciclo:
			mul ebx
			inc ecx
			cmp ecx, totdigitos
			jl ciclo
		
		continuar:
			mov divisor, eax
	}
	return divisor;
	//velocidad += pDecimal / tiempo;
	int c = 0; //inicio de la cadena resultado     
	c += addCadena2Cadena(cadRes, c, nombre);

	const char* aux = " tiene una velociad de: "; //debe ser menor que len_buffer
	c += addCadena2Cadena(cadRes, c, aux);

	//Params: cadena en la que se concatenara, posicion de inicio del numero, numero a concatenar 
	//c += addNum2Cadena(cadRes, c, velocidad);
	//retorna la cantidad de caracteres en la palabra ...
	return c;
}


#pragma endregion