#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef char *cadena;

enum _retorno{
	OK, ERROR, NO_IMPLEMENTADO
};
typedef enum _retorno TipoRet;

struct _linea{
	unsigned int nroLinea;
	cadena texto = new char[100];
	_linea *sig;
};
typedef struct _linea *Linea;

struct _archivo{
	cadena titulo;
	cadena version;
	_linea *contenido;
	_archivo *sig;
};
typedef struct _archivo *Archivo;


typedef enum _acciones{
	crearArch, insertarLin, eliminarLin, borrarLin, borrarArch, mostrar, limpiar, ayuda, error
}accion;

#endif
