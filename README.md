# Título del trabajo: SENSOR DE HOGAR
Intentaremos replicar algunos ejemplos de lo que podría ser la domótica en casa, con la automatización de varios gestos que realizamos durante nuestra vida en los hogares

# Integrantes del equipo
- Alejandro Palomo de la Peña 55393
- Daniel Sato Leandro
- Pablo Moreno Martin 54116

## Objetivos del trabajo

Aprender a utilizar el Arduino y a conocer su lenguaje de programación en C, llevar a cabo un programa de automatización aplicable a algún aspecto de la vida cotidiana. 

# SENSORES Y ACTUADORES
dos sensores ultra sonidos unidos a un servomotor. según el sensor que detecte la presencia de un objeto o persona, el servomotor se moverá hacia el lado opuesto, es decir, hacia el lado del sensor que no ha detectado nada. Unido a ello tenemos un sensor de aparcamiento con leds y una alerta sonora. Ésta incrementa su tono, su frecuencia de parpadeo. También aumenta a la vez el número de leds encendidos (hasta 4, los cuales se encienden de manera progresiva) hasta la posición final. En la cual se quedan TODOS los leds encendidos de forma fija en conjunto con la alerta sonora la cual ahora suena sin interrupción.

#CODIGO EN C
#include <stdlib.h>
#include <stdio.h>
#include "SerialPort.h"
#define MAX_DATA_LENGTH 255
#define N 100
typedef struct
{
	float distancia;
	float duracion;
}puerta;

typedef struct
{
	float temp;
	float humidity;
}temperatura;

float sensor(temperatura*, int, float);
void humedad(temperatura*, int, float, float*);
void autoConnect (SerialPort *arduino,char*);

int main(void)
{
	//Arduino SerialPort object
	SerialPort *arduino;
	//Puerto serie en el que esta Arduino
	char* portName= "\\\\.\\COM3";
	// Buffer para datos procedentes de Arduino
	char incomingData [MAX_DATA_LENGTH];
	temperatura *temp;
	float distancia;
	int i, medidas;
	float avg = 0.0;
	float medias = 0.0;
	float media = 0.0;
	float suma = 0.0;
	int opc, ventilador = 0;
		//Crear estructura de datos del puerto serie
		arduino=(SerialPort *)malloc(sizeof(SerialPort));
		//Apertura del puerto serie
		Crear_Conexion(arduino,portName);
		autoConnect(arduino,incomingData);
	printf("introduzca el numero de medidas:\n");
	scanf("%d", &medidas);
	temp = (temperatura*)malloc(medidas * sizeof(temperatura));
	for (i = 0; i < medidas; i++)
	{
		printf("introduzca las temperaturas:\n");
		scanf("%f", &temp[i].temp);
		printf("introduzca tambien la humedad en tanto por 100:\n");
		scanf("%f", &temp[i].humidity);
	}
	avg = sensor(temp, medidas, medias);
	printf("la media de temperaturas es:%f\n", avg);
	if (avg > 25)
	{
		printf("desea activar el ventilador?\n");
		printf("si\no\n");
		scanf_("%d", &opc);
		switch (opc)
		{
		case 1:
			ventilador = 1;
			printf("activando ventilador");
			break;
		case 0:
			ventilador = 0;
			printf("stand_by mode: ON");
			break;
		}
		
	}
	humedad(temp, medidas,suma, &media);
	printf("la humedad del aire es %f", &media);
	if (media < 50)
	{
		printf("error, fallo en el sistema de regulacion del ambiente, contacte con el servicio técnico\n");
	}
		

	system("PAUSE");
	return 0;
}
float sensor1(puerta*, float distancia)
{
	int i=0;
}
float sensor2(puerta*, int, float)
{
	int i=0;
}
float sensor(temperatura *temp, int medidas,float media)
{
	int i;
	float sum = 0.0;
	float mediaa = 0.0;
	for (i = 0; i < medidas; i++)
	{
		sum = sum + temp[i].temp;
	}
	mediaa = sum / medidas;
	return mediaa;
}
void humedad(temperatura *temp, int medidas, float suma,float *media)
{
	int i;
	float sum = 0.0;
	float average = 0.0;
	*media=0.0;
	for (i = 0; i < medidas; i++)
	{
		sum = sum + temp[i].humidity;
	}
	average = sum / medidas;
	*media = average;
}
void autoConnect (SerialPort *arduino, char *incomingData)
{
	char sendData = 0;
	
	//Espera la conexion con arduino
	while (!isConnected(arduino))
	{
		Sleep(100);
		Crear_Conexion(arduino, arduino->portName);
	}
	// Comprueba si arduino esta conectado
	if (isConnected(arduino))
	{
		printf("Conectado con Arduino en el puerto %s\n", arduino->portName);
	}
	
	//Bucle de la aplicacion
	printf("0- LED OFF, 1-LED ON, 9-SALIR");
		while(isConnected(arduino) && sendData!='9')
		{
			sendData=getch();
			writeSerialPort(arduino,&sendData, sizeof(char));
		}
		
		if(!isConnected(arduino))
			printf("Se ha perdido la conexion con Arduino\n")
}
