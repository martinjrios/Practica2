/*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/

#ifndef EJERCICIOPROPUESTO_PRACTICA2_INC_TECLAS_H_
#define EJERCICIOPROPUESTO_PRACTICA2_INC_TECLAS_H_

#include "sapi.h"

// TIEMPOS DE REBOTE (ms)
#define DEBOUNCE_TIME	100

// TECLAS
#define KEY1			0
#define KEY2			1
#define KEY3			2
#define KEY4			3

#define LAST_KEY		4

// DEFINICION DE TIPOS DATOS ENUM
typedef enum
{
	PRESSED,
	RELEASED,
}keyStatus_t;

typedef enum
{
	WAITING_PRESS,
	DEBOUNCING,
	WAITING_RELEASE,
}dbSt_t;

// DEFINICION DE FUNCIONES DE TECLAS
bool_t keyPressed ( uint8_t key );
static bool_t readKey ( const gpioMap_t *_keyArray, uint8_t keyIndex );

#endif /* EJERCICIOPROPUESTO_PRACTICA2_INC_TECLAS_H_ */
