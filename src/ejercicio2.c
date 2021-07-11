/*=============================================================================
 * Ejercicio 2
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/

#include "ejercicio2.h"

/* FUNCION PRINCIPAL */
int main( void )
{
	// INICIALIZAR Y CONFIGURAR PLATAFORMA
    boardInit();

    /* Verificación TICK_RATE rango permitido de tiempo: 1 a 50 ms */
    if ( ( TICK_RATE < TICK_RATE_MIN ) || ( TICK_RATE > TICK_RATE_MAX ) )  blinkError( ERROR_TIME );
    if ( !tickConfig ( TICK_RATE ) )  blinkError( ERROR_TIME );

    // DEFINICION DE VARIABLES
    // Se define la estructura para el control de la secuencia de LEDs
    controlSequence_t controlSequenceLeds = { NULL, 0, 0, false, NULL};

#ifdef PUNTO_2
    const gpioMap_t sequence1[] = {LED1, LED2, LED3};
    uint16_t onTimeSequence1[] = {ON_TIME_LED1, ON_TIME_LED2, ON_TIME_LED3, OFF_TIME};

    // Se inicializan los parametros de la estructura
    controlSequenceLeds.ledSequence = sequence1;
    controlSequenceLeds.lastLed = sizeof ( sequence1 ) / sizeof ( gpioMap_t );
    controlSequenceLeds.onTime = onTimeSequence1;
#endif

#ifdef PUNTO_3
    const gpioMap_t sequence2[] = {RED_LED, YELOW_LED, GREEN_LED};
    uint16_t onTimeSequence2[] = {NORMAL_ON_TIME_RED, NORMAL_ON_TIME_YELOW, NORMAL_ON_TIME_GREEN};

    // Se inicializan los parametros de la estructura
    controlSequenceLeds.ledSequence = sequence2;
    controlSequenceLeds.lastLed = sizeof ( sequence2 ) / sizeof ( gpioMap_t );
    controlSequenceLeds.onTime = onTimeSequence2;
#endif

	/* Apagado de leds y captura de errores de apagado */
    if ( !ledsOff( controlSequenceLeds.ledSequence, controlSequenceLeds.lastLed) ) blinkError ( ERROR_OFF );

   // ----- Repeat for ever -------------------------
    while( true ) {
    	/* Se activa la secuencia correspondiente. En caso de error el programa se bloquea quedando el led rojo parpadeando. */
    	if(!ledSequenceOn(&controlSequenceLeds)) blinkError ( ERROR_SEQ );
    }

    return 0;
}
