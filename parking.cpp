#include<stdio.h>
#include<windows.h>
typedef struct
{
	int led;
	int buzz;
}PARKING;
void puerta_parking(float, float, int*);
void sensores_servo(float, float, float, int*);
void sensor_parking(PARKING *casa, int);
int main()
{
	PARKING *casa;
	int dist1 = 0, dist2 = 0, elementos, posicion;
	int puerta = 0;
	printf("numero de leds:\n");
	scanf_s("%d", &elementos);
	casa = (PARKING*)malloc(elementos * sizeof(PARKING));
	int dist_parking;
	sensores_servo(dist1, dist2, &puerta);
	
	sensor_parking(casa, elementos);
	system("pause");
}

void sensores_servo(float dist1, float dist2, int *puerta)
{
	printf("distancias:");
	scanf_s("%d%d", &dist1,&dist2);
	while (dist2 < 0 || dist1<0)
	{
		printf("fallo en algun sensor, error ul5F");
		*puerta = 1;
		if (dist1 < 0)
		{
			printf("introduzca la distancia 1 de nuevo");
			scanf_s("%d", &dist1);
		}
		if (dist2 < 0)
		{
			printf("introduzca la distancia 2 de nuevo");
			scanf_s("%d", &dist2);
		}
		if (dist1 < 0 && dist2 < 0)
		{
			printf("introduzca las 2 distancias de nuevo");
			scanf_s("%d%d", &dist1, &dist2);
		}
		puerta_parking(dist1, dist2, puerta);
	}
	return;
}
void sensor_parking(PARKING *casa, int elementos)
{
	int dist_park;
	do
	{
		printf("metros restantes...\n");
		scanf_s("%d", &dist_park);
		int i;
		for (i = 0; i < elementos; i++)
		{
			casa[i].led = 0;
		}
		if (dist_park < 30 && dist_park >= 20)
		{
			casa[0].led = 1;
		}
		if (dist_park < 20 && dist_park >= 15)
		{
			casa[0].led = casa[1].led = 1;
		}
		if (dist_park < 15 && dist_park > 5)
		{
			casa[0].led = casa[1].led = casa[2].led = 1;
		}
		if (dist_park < 5)
		{
			for (i = 0; i < elementos; i++)
			{
				casa[i].led = 1;
			}
			casa[0].buzz = 1;
		}
	} while (dist_park > 2);
	puerta_parking(dist1, dist2, dist_park, &puerta);
	return;

}
void puerta_parking(float dist1, float dist2, float dist_park, int *puerta)
{
	if (dist1 < 5 && dist2>5)
	{
		*puerta = 1;
	}
	if (dist1 > 5)
	{
		if (dist2 > 5)
		{
			*puerta = 0;
			printf("puerta cerrada");
		}
		else
		{
			*puerta = 1;
			printf("puerta abierta\n");
		}
	}
	if (dist1 < 5 && dist2 < 5)
	{
		*puerta = 1;
		if (dist_park < 30)
		{
			*puerta = 1;
			printf("obstaculo, la puerta se mantiene abierta\n");
		}
		else
		{
			printf("averia\n");
		}
	}
	return;
}