/*
NOMBRE: ANTHONY AVILA PAZ
CARNET: 9941-19-4080
PROGRA 1, INGENIERIA EN SISTEMAS


Realizar el siguiente ejercicio utilizando funciones, estructuras y punteros:


La Unicef desea obtener información estadística sobre las guarderias ubicadas en el territorio guatemalteco,
dado que por cada niño se ingresa la siguiente información: Nombre, Sexo, Edad, Nombre de Guarderia, Departamento (ubicacion geográfica)

Para lo cual se debe generar los siguientes reportes:
a) Porcentaje de niños ubicados en el departamento de guatemala, respecto al total del país.
b) Número de niños por grupo, los cuales se definen con base en la edad, teniendo en cuenta lo siguiente:

Grupo 1: Edad menor a 1 año
Grupo 2: Edad comprendida entre 1 y 3 años
Grupo 3: Edad comprendida entre 4 y 6 años
Grupo 4: Edad mayor de 6 años
c) Establecer el grupo que tiene la mayor cantidad de niños.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// declaracion de estructura
struct unicef{
	int edad;
	string nombre,sexo;
	string guarderia,depto,grupo;
};

void estadistica(){ 
	int total_ninhos,sur=0,total;
	int grupo1=0,grupo2=0,grupo3=0,grupo4=0;
	float promedio;
	//declaracion de puntero tipo estructura
	//estructura *putnero
	unicef *punterounicef;	//para hacer dinamica la esctructura y poder llenar nuevos datos 
	
	//asignacion de espacio a puntero.
	int j, opcion;
	cout<<"cuantos niños desea registrar."<<endl; // nunmero de empleados a registrar.
	cin>>j;
	punterounicef= new unicef[j]; //aparta espacios para ingresar datos
	
	// registro de empleados, asignar datos a variables
	for(int i=0;i<j;i++){
		system("CLS");
		fflush(stdin);
		cin.clear();
	
		//ingreso de datas a estrucura punterounicef
		cout<<"ingrese nombre del ninho #"<<i+1<<": "<<endl;
		getline(cin,punterounicef[i].nombre);
		cin.ignore();
		fflush(stdin);	
		
		cout<<"ingrese edad del ninho #"<<i+1<<": "<<endl;
		cin>> punterounicef[i].edad;
		cin.ignore();
		fflush(stdin);
		
		if(punterounicef[i].edad==0){
			punterounicef[i].grupo= "grupo 1";
			grupo1+=1;
		}
		else if((punterounicef[i].edad>=1)&&(punterounicef[i].edad<=3)){
			punterounicef[i].grupo= "grupo 2";
			grupo2+=1;
		}
		else if((punterounicef[i].edad>3)&&(punterounicef[i].edad<=6)){
			punterounicef[i].grupo= "grupo 3";
			grupo3+=1;
		}
		else if(punterounicef[i].edad>6){
			punterounicef[i].grupo= "grupo 4";
			grupo4+=1;
		}
		cout<<"ingrese genero del niño F o M #"<<i+1<<": "<<endl;
		getline(cin,punterounicef[i].sexo);
		fflush(stdin);
		cin.ignore();
		
		//menu para seleccionar departamento
		cout<<"--------SELECCION DE DEPARTAMENTO UBICACIÓN GEOGRÁFICA---------"<<endl;
		cout<<"1.- NORTE "<<endl;
		cout<<"2.- SUR "<<endl;
		cout<<"3.- ESTE "<<endl;
		cout<<"4.- OESTE "<<endl;
		cout<<"SELECCIONE UN DEPARTAMENTO: "<<endl;
		cin>>opcion;
		fflush(stdin);
		cin.ignore();
		
		if (opcion==1){
			punterounicef[i].depto="Norte";
		}
		else if(opcion==2){
			punterounicef[i].depto="Sur";
			sur+=1;
		}
		else if(opcion==3){
			punterounicef[i].depto="Este";
		}
		else if(opcion==4){
			punterounicef[i].depto="Oeste";
		}
		else {
			cout<<" OPCION INVALIDA. El niño # "<<i+1<<" N/A"<<endl;
			punterounicef[i].depto = "error en regisro de departamento.";
		}
		cout<<"ingrese el nombre de la guarderia del ninho #"<<i+1<<": " <<endl;
		cin>> punterounicef[i].guarderia;
		fflush(stdin);
		cin.ignore();	
		//haciendo la sumatoria de salario de todos los empleadsos registrados
		total_ninhos += 1;
		promedio= 100/total_ninhos;
		total=promedio * sur;
		cout<<"registro completo"<<endl;
	
		system("pause");
		
	}
	system("CLS");
	//mostrar reporte ciclo for para mostrar todos los registro en el puntero estructura

	for(int i=0; i<j;i++){
		cout<<"---------------------DATOS DEL NIÑO #"<<i+1<<"----------------------"<<endl;
		cout<<"NOMBRE       : "<< punterounicef[i].nombre<<endl;
		cout<<"EDAD         : "<< punterounicef[i].edad<<endl;
		cout<<"SEXO         : "<< punterounicef[i].sexo<<endl;
		cout<<"GUARDERIA    : "<<punterounicef[i].guarderia<<endl;
		cout<<"DEPARTAMENTO : "<< punterounicef[i].depto<<endl;
		cout<<"GRUPO        : "<< punterounicef[i].grupo<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
	}
	//mostrar total en planilla
	cout<<"-----------------------------------------------------------"<<endl;
	cout<< "\n\n EL TOTAL DE NIÑOS ES DE: "<<total_ninhos<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<< "\n\n EL PROMEDIO DE NIÑOS EN EL SUR ES: "<<total<<"%"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"el total de niños en el grupo 1 es de:"<<grupo1<<endl;
	cout<<"el total de niños en el grupo 2 es de:"<<grupo2<<endl;
	cout<<"el total de niños en el grupo 3 es de:"<<grupo3<<endl;
	cout<<"el total de niños en el grupo 4 es de:"<<grupo4<<endl;	
}
int main(){
	//mandar a llamar a la función
	estadistica();
}
