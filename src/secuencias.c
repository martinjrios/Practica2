/*=============================================================================
 * Ejercicio 2
 * file: secuencias.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/05
 * Version: 1.0
 *===========================================================================*/

#include "secuencias.h"

//***** FUNCIÓN PARA ACTIVAR EL LED CORRESPONDIENTE DE LA SECUENCIA DE LEDS ********************
// Recibe: un puntero a la estructura de la secuencia de LEDs que se quiere activar.
// Devuelve: TRUE en caso de encender correctamente el LED o FALSE en caso contrario.
// *********************************************************************************************
bool_t ledSequenceOn(controlSequence_t *controlSequence)
{

	if(controlSequence->ledSequence == NULL) return FALSE;  					/* Se comprueba que se haya asignado algo al puntero de la secuencia */
	if(controlSequence->tiempoDestello == NULL) return FALSE;  					/* Se comprueba que se haya asignado algo al puntero del tiempo de destello */

	/* Definicion de variables */
	int8_t ledIndex = controlSequence->ledIndex;
	static delay_t ledDelay;
	bool_t sentidoSeq = controlSequence->inverted;

	controlSequence->inverted = pressKey ( sentidoSeq );						/* Lecutra de teclas para sentido de secuncia */

	if( ledIndex >= controlSequence->lastLed ) return FALSE;  					/* Se comprueba indice del LED dentro de valores posibles */

	if ( delayRead ( &ledDelay ) )
	{

		if ( controlSequence->inverted ) ledIndex--;  							/* Secuencia invertida */
		else ledIndex++;  														/* Secuencia normal */

		if ( ledIndex >= controlSequence->lastLed ) ledIndex = 0;				/* ledIndex no debe exceder limite superior lastLed */

		else if ( ledIndex < 0 ) ledIndex = controlSequence->lastLed - 1;		/* ledIndex no debe exceder limite inferior 0 */

		delayWrite ( &ledDelay, controlSequence->tiempoDestello[ledIndex] );	/* Cambiar la duración de delay del retardo no bloqueante en tiempo de ejecución */

	}

	/* Se apagan todos los LEDs de la secuencia*/
	if ( !ledsOff(controlSequence->ledSequence, controlSequence->lastLed) ) return FALSE;

	if ( !ledOn ( controlSequence->ledSequence[ledIndex] ) ) return FALSE;		/* Se enciende el LED correspondiente de la secuencia */

	controlSequence->ledIndex = ledIndex;  										/* Se actualiza el indice del led que fue activado */

	return TRUE;
}
