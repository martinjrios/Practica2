/*=============================================================================
 * Ejercicio 2
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/05
 * Version: 1.0
 *===========================================================================*/

#include "ejercicio2.h"

/* FUNCION PRINCIPAL */
int main( void )
{
	// INICIALIZAR Y CONFIGURAR PLATAFORMA
    boardInit();

    // DEFINICION DE VARIABLES

    /* Definicion de Leds para la estructura */
    const gpioMap_t sequence1[] = { LED1, LED2, LED3 };

    /* Tiempos en ms para LED1, LED2 y LED3, respectivamente*/
    uint16_t tiempoSecuencia1[] = { 1000, 2000, 3000 };

    /* Se declara la estructura para el control de la secuencia con el LED 1, 2 y 3*/
    controlSequence_t controlSequence = {
    	NULL,
		0,
		0,
		false,
		0,
    };

    /* Asignación de secuencia y tiempos de secuencia a la estructura */
    controlSequence.ledSequence = sequence1;
    controlSequence.lastLed = sizeof ( sequence1 ) / sizeof ( gpioMap_t );
    controlSequence.tiempoDestello = tiempoSecuencia1;

    /* Variables del tipo tick para retardos */
    delay_t pullSequenceDelay;

    /* Verificación TICK_RATE rango permitido de tiempo: 1 a 50 ms */
    if ( ( TICK_RATE < TICK_RATE_MIN ) || ( TICK_RATE > TICK_RATE_MAX ) )  blinkError( ERROR_TIME );
    if ( !tickConfig ( TICK_RATE ) )  blinkError( ERROR_TIME );

	/* Apagado de leds y captura de errores de apagado */
	if ( !ledsOff( controlSequence.ledSequence, controlSequence.lastLed) ) blinkError ( ERROR_OFF );

    /*Configuración del retardo no bloqueante que determina el tiempo de transicion entre un led y el siguiente en la secuencia*/
    delayConfig ( &pullSequenceDelay, DELAYPULL );

   // ----- Repeat for ever -------------------------
    while( true ) {

    	/* Retardo no bloqueando para pedido de estado de secuencia */
    	if ( delayRead ( &pullSequenceDelay ) ) {
    		if ( !ledSequenceOn ( &controlSequence ) ) blinkError ( ERROR_SEQ );
    	}
    }
    return 0;
}
