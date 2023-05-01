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