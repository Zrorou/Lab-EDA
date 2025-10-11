#include<iostream>
#include "string.h"
#include "estructuras.h"
#include "prototipos.h"
#define COMANDO 100
#define P 4

using namespace std;

int main (int argc, char *argv[]) {
	Archivo a = NULL;
	cadena comando = NULL;
	comando = new char[100];
	accion opcion;
	cadena parametro[P];
	while (strlen(comando)==0){
		cout << ">";
		cin.getline(comando,100);
	}
	
	char delim[] = "(\" ,\")";
	int contador = 0;
	parametro[contador] = strtok(comando, delim);
	contador++;
	parametro[contador] = strtok(NULL, delim);
	char *version = parametro[1];
	char *texto = parametro [2];
	unsigned int nroLinea = atoi(parametro[3]); 
	
	while(parametro[contador] != NULL){
		contador++;
		parametro[contador] = strtok(NULL,delim);
	}
	
	while(strcmp(parametro[0], "fin")!= 0){
		opcion = error;
		if(strcmp(comando, "crearArch") == 0){
			opcion = crearArch;
		}
		
		if(strcmp(parametro[0], "insertarLin") == 0){
			opcion = insertarLin;
		}
		if(strcmp(parametro[0], "eliminarLin") == 0){
			opcion = eliminarLin;
		}
		if(strcmp(parametro[0], "borrarArch") == 0){
			opcion = borrarArch;
		}
		if(strcmp(parametro[0], "mostrar") == 0){
			opcion = mostrar;
		}
		if(strcmp(parametro[0], "ayuda") == 0){
			opcion = ayuda;
		}
		if(strcmp(parametro[0], "limpiar") == 0){
			opcion = limpiar;
		}
		
		switch(opcion){
		case crearArch:
			a = crearArchivo("curriculo.txt");
			if(a != NULL){
				cout << a->titulo << endl;
				cout << "Version: " << a->version << endl;
				muestroRetorno(OK);
			}else{
				muestroRetorno(ERROR);
			}
			break;
		case insertarLin:
			muestroRetorno(insertarLinea(a, version, texto, 1));
			break;
		case eliminarLin:
			//muestroRetorno(borrarLinea(a, version, 1));
			break;
		case borrarArch:
			muestroRetorno(borrarArchivo(a, version));
			break;
		case mostrar:
			muestroRetorno(mostrarTexto(a, version));
			break;
		case limpiar:
			system("cls");
			break;
		case ayuda:
			help();
			break;
		default:
			muestroRetorno(ERROR);
		}
		cout << ">";
		cin >> comando;
	}
	
	return 0;
}
