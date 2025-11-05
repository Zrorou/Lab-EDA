#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

enum _retorno{
	OK, ERROR, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRet;

/********************************************/
typedef char* Cadena;

struct _linea {
	unsigned int nroLinea;
	Cadena texto = new char[100];
	_linea* sig;
};

typedef _linea* Linea;

struct _version{
	Cadena nombreVers;
	_linea* contenido;
	_version *hijo = NULL;
	_version *hermano = NULL;
};

typedef struct _version *Version;

struct _archivo{
	Cadena titulo;
	Version version;
	_archivo* sig;
};

typedef enum _opciones{
	insertar, borrarL, mostrarT, mostrarV, ayuda, error, limpiar, salir
}opciones;

