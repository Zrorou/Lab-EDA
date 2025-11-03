#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

void muestroRetorno(TipoRet retorno);
TipoRet inserto(Archivo &a, Cadena parametros[]);
TipoRet borroL(Archivo &a, Cadena parametros[]);
TipoRet muestroT(Archivo a, Cadena parametros[]);

Archivo CrearArchivo(char * nombre);
TipoRet BorrarArchivo(Archivo &a);
TipoRet InsertarLinea(Archivo &a, char * version, char * linea, unsigned int nroLinea);
TipoRet BorrarLinea(Archivo &a, char * version, unsigned int nroLinea);
TipoRet MostrarTexto(Archivo a, char * version);

//las tiporet de esta segunda entrega
TipoRet CrearVersion(Archivo &a, char * version);
TipoRet MostrarVersiones(Archivo a);
TipoRet MostrarCambios(Archivo a, char * version);
TipoRet Iguales(Archivo a, char * version1, char * version2,bool &iguales);

//funciones auxiliares
Version creoVersion(Version padre, Cadena nombre);
void muestroVersion(Version v, int espacio);

void help();


#endif
