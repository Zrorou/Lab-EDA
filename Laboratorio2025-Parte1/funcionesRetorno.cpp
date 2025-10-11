#include<iostream>
#include "string.h"
#include "estructuras.h"
#include "prototipos.h"
using namespace std;


void muestroRetorno(TipoRet retorno){
	switch(retorno){
	case OK:
		cout << "OK";
		break;
	case ERROR:
		cout << "ERROR";
		break;
	case NO_IMPLEMENTADO:
		cout << "NO_IMPLEMENTADO";
		break;
	}
	cout << endl;
}
	
TipoRet insertarLinea(Archivo &a, char * version, char * linea, unsigned int nroLinea) {
	if (nroLinea == 0 || nroLinea > cantLineas(a)+1) {
		return ERROR;
	}
	
	//creo la linea
	Linea l = new _linea;
	strcpy(l->texto, linea);
	l->sig = NULL;
	
	//inserta al principio
	if (nroLinea == 1) {
		l->sig = a->contenido;
		a->contenido = l;
		actualizarLineas(a);
		return  OK;
	}
	
	//el for recorre la lista hasta encontrar la posicion de nroLinea
	// linea anterior es para no perder la lista al insertar en el medio
	Linea anterior = a->contenido;
	for (unsigned int i = 1; i < nroLinea-1; i++) {
		anterior = anterior->sig;
	}
	
	l->sig = anterior->sig;
	anterior->sig = l;
	actualizarLineas(a);
	return OK;
}
	
TipoRet borrarLinea(Archivo &a, char * version, unsigned int nroLinea){

	return NO_IMPLEMENTADO;
}

TipoRet borrarArchivo(Archivo &a, char *version){ 
	
	if(a == NULL){
		return ERROR;
	}
	
	Archivo anterior = NULL;
	Archivo actual = a;
	
	while(actual != NULL){
		if(strcmp(actual->version, version)== 0){
			if(anterior == NULL){
				a = actual->sig;
			}else{
				anterior->sig = actual -> sig;
			}
			delete actual->version;
			delete actual->contenido;
			delete actual;
			
			return OK;
		}
		anterior = actual;
	}
	return ERROR;
}

TipoRet mostrarTexto(Archivo a, char * version){
	if(esVacioArchivo(a)){
		return ERROR;
	}
	//esto nikk es para buscar la version que se pide
	Archivo actual = a;
	while(actual != NULL && strcmp(a->version, version)!= 0){
		actual = actual->sig;
	}
	if(actual == NULL){
		cout << "No se ha encontrado una version" << endl;
		return ERROR;
	}
	cout << a->titulo << " - " << a->version << endl;
	
	if(esVaciaLinea(actual->contenido)){
		cout << "No contiene lineas" << endl;
		return OK;
	}
	//esto te lo copie de tu main ajsdashdjhajs 
	Linea aux = a->contenido;
	while (aux != NULL) {
		cout << aux->nroLinea << '\t' << aux->texto << endl;
		aux = aux->sig;
	}
	
	return OK;
}
