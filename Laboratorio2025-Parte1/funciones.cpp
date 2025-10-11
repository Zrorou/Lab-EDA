#include<iostream>
#include "string.h"
#include "estructuras.h"
#include "prototipos.h"
using namespace std;


void help(){
	cout << "Los comandos que puede utilizar son insertarLin - eliminarLin - borrarLin - borrarArch - limpiar - ayuda" << endl;
}
	
	
Archivo crearArchivo(char *nombre){ //no se si ta bien esto xD
	Archivo nuevoArchivo = new _archivo;
	nuevoArchivo -> titulo = nombre;
	nuevoArchivo -> version = "1";
	nuevoArchivo -> contenido = NULL;
	nuevoArchivo->sig = NULL;
	return nuevoArchivo;
}

int cantLineas(Archivo a) {
	int contador = 0;
	Linea aux = a->contenido;
	while(aux != NULL) {
		contador++;
		aux = aux->sig;
	}
	return contador;
}

void actualizarLineas(Archivo &a) {
	Linea aux = a->contenido;
	unsigned int nL = 1;
	while (aux != NULL) {
		aux->nroLinea = nL++;
		aux = aux->sig;
	}
}

bool esVaciaLinea(Linea l){
	return l = NULL; 
}

bool esVacioArchivo(Archivo a){
	return a == NULL;
}
