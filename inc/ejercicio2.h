 /*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/

#ifndef __EJERCICIO2_H__
#define __EJERCICIO2_H__

#include "secuencias.h"
#include "sapi.h"

//#define PUNTO_2	// Descomentar para correr el punto 2 del ejercicio
#define PUNTO_3

#define TICK_RATE		1 // Default 1ms

#define TICK_RATE_MIN	1  // ms
#define TICK_RATE_MAX	50 // ms

// Tiempos de encendido en ms
#define ON_TIME_LED1	1000
#define ON_TIME_LED2	2000
#define ON_TIME_LED3	3000

#define OFF_TIME		500

#define RED_LED					LED2
#define YELOW_LED				LED1
#define GREEN_LED				LED3
#define NORMAL_ON_TIME_RED		3000
#define NORMAL_ON_TIME_YELOW	500
#define NORMAL_ON_TIME_GREEN	1000

#endif /* __EJERCICIO2_H__ */
