#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include "estructuras.h"


Archivo crearArchivo(char *nombre);//esta permanece inalterada por eso la de tipo ret abajo

//funciones tipo retorno
TipoRet muestroArchivo(Archivo &a, char *nombre); //lo puse para que ande el coso pero no se si entendi bien
TipoRet insertarLinea(Archivo &a, char *version, char *linea, unsigned int nroLinea);
TipoRet borrarLinea(Archivo &a, char * version, unsigned int nroLinea);
TipoRet borrarArchivo(Archivo &a, char *version);
TipoRet mostrarTexto(Archivo a, char * version);

void help();
void muestroRetorno(TipoRet retorno);
bool esVaciaLinea(Linea l);
bool esVacioArchivo(Archivo a);
int cantLineas(Archivo a);
void actualizarLineas(Archivo &a);
#endif
