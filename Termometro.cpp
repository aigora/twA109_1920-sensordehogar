#include<stdio.h>
#include<windows.h>
#define N 100
typedef struct
{
	float temp;
	float humidity;
}temperatura;
float sensor(temperatura*, int, float);
void humedad(temperatura*, int, float, float*);
int main()
{
	temperatura *temp;
	int i, medidas;
	float avg = 0.0;
	float medias = 0.0;
	float media = 0.0;
	float suma = 0.0;
	int opc, ventilador = 0;
	printf("introduzca el numero de medidas:\n");
	scanf_s("%d", &medidas);
	temp = (temperatura*)malloc(medidas * sizeof(temperatura));
	for (i = 0; i < medidas; i++)
	{
		printf("introduzca las temperaturas:\n");
		scanf_s("%f", &temp[i].temp);
		printf("introduzca tambien la humedad en tanto por 100:\n");
		scanf_s("%f", &temp[i].humidity);
	}
	avg = sensor(temp, medidas, medias);
	printf("la media de temperaturas es:%f\n", avg);
	if (avg > 25)
	{
		printf("desea activar el ventilador?\n");
		printf("si\nno\n");
		scanf_s("%d", &opc);
		switch (opc)
		{
		case 1:
			ventilador = 1;
			printf("activando ventilador\n");
			break;
		case 0:
			ventilador = 0;
			printf("stand_by mode: ON\n");
			break;
		}
		
	}
	humedad(temp, medidas,suma, &media);
	
		

	system("pause");
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
	printf("la humedad del aire es %f\n", *media);
	if (*media < 50)
	{
		printf("error, fallo en el sistema de regulacion del ambiente, contacte con el servicio técnico\n");
	}
	return;
}
