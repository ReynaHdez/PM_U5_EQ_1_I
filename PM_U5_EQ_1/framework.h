#pragma once

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows
#include <windows.h>

extern "C" __declspec(dllexport) int __stdcall suma(int a, int b);
extern "C" __declspec(dllexport) int __stdcall resta(int a, int b);
extern "C" __declspec(dllexport) int __stdcall multi(int a, int b);

extern "C" __declspec(dllexport) int __stdcall largo_cadena(const char* str);
extern "C" __declspec(dllexport) int __stdcall escribir_cadena(char* str, int len_buffer);

extern "C" __declspec(dllexport) int __stdcall promedioDeUsuario(char* nombre, int cal1, int cal2, int cal3);
extern "C" __declspec(dllexport) int __stdcall promUsuario(char* cadRes, char* nombre, int cal1, int cal2, int cal3);

extern "C" __declspec(dllexport) int __stdcall fibunacci(int t0, int t1);

extern "C" __declspec(dllexport) int __stdcall velocidad(char* cadRes, char* nombre, int distancia, int tiempo);
extern "C" __declspec(dllexport) int __stdcall addNum2Cadena(char* cadRes, int indice, int numero);
extern "C" __declspec(dllexport) int __stdcall addCadena2Cadena(char* cadRes, int indice, const char* cadena);

extern "C" __declspec(dllexport) int __stdcall comparaNumeros(char* cadRes, char* nombre, int numero1, int numero2, int totdigitos);