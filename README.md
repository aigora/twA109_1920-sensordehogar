# Título del trabajo: SENSOR DE HOGAR
Intentaremos replicar algunos ejemplos de lo que podría ser la domótica en casa, con la automatización de varios gestos que realizamos durante nuestra vida en los hogares

# Integrantes del equipo
- Pablo Moreno Martin 54116

## Objetivos del trabajo

Aprender a utilizar el Arduino y a conocer su lenguaje de programación en C, llevar a cabo un programa de automatización aplicable a algún aspecto de la vida cotidiana. 

# SENSORES Y ACTUADORES
TEMPERATURA: 
un sensor de temperatura, a partir de cierta temperatura se activará un motor eléctrico que nos imaginamos que pertenece a un ventilador
para la temperatura usaremos un sensor de temperatura y humedad DHT11.

GARAJE:
tres sensores ultra sonidos. Dos unidos a un servomotor. el servomotor se posicionará según una distancia umbral que nosotros colocaremos. Cuando se activa 1 de ellos la puerta se abre (el servo se mueve a un lado) y permanecerá abierta hasta que los dos sensores vuelvan a no detectar nada, entonces se cerrará (el servo vuelve a su posición original)
Para la ayuda de aparcamiento, usaremos el sensor restante que, estableciendo unos rangos de distancias, iremos encendiendo leds (hasta tener los 4), haciendoles parpadear a mayores frecuencias (aumento por cada led encendido). Lo mismo para el altavoz, irá variando el pitch del sonido así como la frecuencia de los pitidos (ambas aumentan a medida que se enciende un nuevo led) El final consistirá en los cuatro leds encendidos sin parpadear y el altavoz sonando de manera continua
la frecuencia de parpadeo de los leds siempre irá acompañada de la de los pitidos del speaker

OTROS ACTUADORES



# CONCLUSIONES
la plataforma abierta que es arduino da muchísima libertad a la hora de programar cualquier automatismo y darle un enfoque práctico a cualquier programa que hagamos en clase. Gracias a trabajos así podemos observar que la diferencia entre dos programas aparentemente tan diferentes no es tan abismal como podría parecer en un principio. 
