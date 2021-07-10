Cohorte 15va
# Programación de microprocesadores
## Practica 2

Repositorio para la segunda práctica de la materia Programación de Microcontroladores.

Autores: Martin Rios jrios@fi.uba.ar - Lucas Zalazar lucas.zalazar6@gmail.com

### Resumen
Modularización de funciones, archivos y capas de un proyecto de controlador de leds.
Implementación de un programa que controle la lógica de funcionamiento de una secuencia arbitraria de LEDs de la EDU-CIAA-NXP.

#### Condiciones de funcionamiento
###### Dependencias externas:
 - sAPI.h;
 - Usar delay no bloqueantes;

#### Modularización
![](https://github.com/lucascsd/practicoDos/blob/main/image/Capas%20Ejercicio%202.svg)

###### Archivos de modularización
| File name | hearders                    |
| ------------- | ------------------------------ |
| [ejercicio2.c](https://github.com/martinjrios/Practica2/blob/main/src/ejercicio2.c)|[ejercicio2.h](https://github.com/martinjrios/Practica2/blob/main/inc/ejercicio2.h)|
| [secuencias.c](https://github.com/martinjrios/Practica2/blob/main/src/secuencias.c)|[secuencias.h](https://github.com/martinjrios/Practica2/blob/main/inc/secuencias.h)|
| [led.c](https://github.com/martinjrios/Practica2/blob/main/src/led.c)|[led.h](https://github.com/martinjrios/Practica2/blob/main/inc/led.h)|
| [teclas.c](https://github.com/martinjrios/Practica2/blob/main/src/teclas.c)|[teclas.h](https://github.com/martinjrios/Practica2/blob/main/inc/teclas.h)|


