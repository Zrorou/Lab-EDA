#include<iostream>
using namespace std;
#include "string.h"
#include <iomanip>
#include "estructuras.h"
#include "prototipos.h"


TipoRet inserto(Archivo &a, Cadena parametros[]) {
	if (a==NULL)
		return ERROR;
	
	Cadena version = new char[100];
	strcpy(version, parametros[2]);
	
	Cadena linea= new char[100];
	strcpy(linea, parametros[3]);
	
	unsigned int nroLinea = atoi(parametros[4]);
	
	return InsertarLinea(a,version,linea,nroLinea);
}

TipoRet borroL(Archivo &a, Cadena parametros[]) {
	if (a==NULL)
		return ERROR;
	Cadena version = new char[100];
	strcpy(version, parametros[2]);
	
	
	unsigned int nroLinea = atoi(parametros[3]);
	
	return BorrarLinea(a, version, nroLinea);
}

TipoRet muestroT(Archivo a, Cadena parametros[]) {
	if (a->contenido==NULL) {
		cout << "No contiene lineas" << endl;
		return OK;
	}
	if (parametros[1]==NULL) {
		return ERROR;
	}
	Cadena version = new char[10];
	strcpy(version, parametros[2]);
	return MostrarTexto(a,version);
}

TipoRet CrearVersion(Archivo &a, char * version){
	
	return NO_IMPLEMENTADA;
}

TipoRet MostrarVersiones(Archivo a){
	cout << a->titulo << endl;
	
	if(a->version == NULL){
		cout << "No hay versiones creadas" << endl;
		return OK;
	}
	muestroVersion(a->version, 0);
	return OK;
}
	
TipoRet MostrarCambios(Archivo a, char * version){
	return NO_IMPLEMENTADA;
}
	
TipoRet Iguales(Archivo a, char * version1, char * version2,bool &iguales){
	return NO_IMPLEMENTADA;
}
	
void muestroRetorno(_retorno ret){
	switch (ret){
	case OK:
		cout << "OK"<< endl;
		break;
	case ERROR:
		cout << "ERROR" << endl;
		break;
	case NO_IMPLEMENTADA:
		cout << "NO IMPLEMENTADA"<<endl;
	}
}
