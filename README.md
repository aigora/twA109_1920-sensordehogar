# Título del trabajo: SENSOR DE HOGAR
Intentaremos replicar algunos ejemplos de lo que podría ser la domótica en casa, con la automatización de varios gestos que realizamos durante nuestra vida en los hogares
trabajaremos dos casos:
TERMOMETRO: mediremos la temperatura y la humedad, junto con 3 leds que se irán encenciendo y apagando en función de los datos que reciba un sensor de temperatura
GARAJE: 3 sensores de ultrasonido, 2 que actuarán sobre un servo, y otro dará servicio a una ayuda al aparcamiento, que nos avisa de nuestra distancia a la pared mediante leds y alertas sonoras que varían en función de la distancia medida
El servo se mueve hacia un lado u otro en funcón de que sensor se active. En caso de que se activen los 2 sensores a la vez SIN ACTIVAR EL DEDICADO AL APARCAMIENTO actuará de una manera diferente a que si se activase éste último también. 

# Integrantes del equipo
- Pablo Moreno Martin 54116

## Objetivos del trabajo

Aprender a utilizar el Arduino y a conocer su lenguaje de programación en C, llevar a cabo un programa de automatización aplicable a algún aspecto de la vida cotidiana. 

# SENSORES Y ACTUADORES
Sensor DHT22: en un unico pin nos mostrará la temperatura en celsius.
Este pin solo se podría utilizar en interiores.
Tiene 4 pin( 2 de alimentacion y uno de datos) el otro no valdría.
La temperatura que mediría sería entre -40 y 125 grados y requiere un voltaje de 3 a 5.5 V

ULTRASONIDOS
4 patas, dos para alimentacion, las otras 2:
ECHO-emite pulsos mediante subidas y bajadas de tension, programadas por el usuario
TRIG-se activa cuando el pulso vuelve al sensor tras rebotar en un objeto,
mediante la función "pulseIn" sabemos cuanto ha tardado el pulso desde su emisión hasta su regreso. Así podemos calcular la distancia

OTROS ACTUADORES
DIODOS- los leds, les entra corriente en un solo sentido

SERVOMOTOR-utilizado para mover elementos alrededor de un eje, en este caso actua de bisagra para una puerta. 3 pines. Uno de alimentación, otro de tierra y otro por el cual le entran los datos para su ángulo de movimiento

CAPACITOR-encargado de suministrar corriente extra necesária para el arranque del servo

BUZZER-alerta sonora, funcionamiento parecido al led, se modifica su sonido y la duración del mismo con la función "TONE", conexión parecida a un led, con la salvedad que el buzzer no necesita de una resistencia para no fundirse

PANTALLA LCD-una pantalla por la cual mediante funciones y librerías específicas podemos modificar su contraste y los datos que imprimimos en ella.

# FUNCIONES Y LIBRERIAS

#include <stdio.h>
#include <stdlib.h>
servo.h
DHT.h
LiquidCrystal.h
Adafruit_ADXL343.h
//arduino
float sensor_cable_verde(void)
float sensor_cable_naranja(void)
float dist_park(void)
//visual
void puerta_parking(float, float, int*);
void sensores_servo(float, float, float, int*);
void sensor_parking(PARKING *casa, int);
float sensor(temperatura*, int, float);
void humedad(temperatura*, int, float, float*);

# CONCLUSIONES
la plataforma abierta que es arduino da muchísima libertad a la hora de programar cualquier automatismo y darle un enfoque práctico a cualquier programa que hagamos en clase. Gracias a trabajos así podemos observar que la diferencia entre dos programas aparentemente tan diferentes no es tan abismal como podría parecer en un principio. 
