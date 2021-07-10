/*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/05
 * Version: 1.0
 *===========================================================================*/

#ifndef EJERCICIOPROPUESTO_PRACTICA2_INC_SECUENCIAS_H_
#define EJERCICIOPROPUESTO_PRACTICA2_INC_SECUENCIAS_H_

#include "led.h"
#include "teclas.h"
#include "sapi.h"

// TIEMPOS DE SECUENCIA (ms)
#define DELAYPULL		125
#define DELAY150		150
#define DELAY750		750

/* Estructura para controlar la secuencia de LEDs */
typedef struct{
	const gpioMap_t *ledSequence;		/* Puntero a la secuencia de LEDs que se quiere activar 		*/
	uint8_t lastLed;					/* Cantidad de elementos en la secuencia de LEDs 				*/
	uint8_t ledIndex;					/* Posicion en la secuencia del LED que esta siendo activado 	*/
	bool_t inverted;					/* Sentido de la secuencia 										*/
	uint16_t * tiempoDestello;			/* tiempos en ms para LED 										*/
} controlSequence_t;

// FUNCION DE CONTROL DE SECUENCIA DE LEDS
bool_t ledSequenceOn ( controlSequence_t *controlSequence );

#endif /* EJERCICIOPROPUESTO_PRACTICA2_INC_SECUENCIAS_H_ */
