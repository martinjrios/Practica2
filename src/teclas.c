/*=============================================================================
 * Ejercicio 2
 * file: teclas.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/05
 * Version: 1.0
 *===========================================================================*/
#include "teclas.h"

/*Arreglo del tipo gpioMap_t para teclas */
const gpioMap_t keyArray[] = { TEC1, TEC2, TEC3, TEC4 };

//***** LECTURA DE TECLAS PARA INDICAR SENTIDO DE SECUENCIA*************************************
// Recibe: el estado actual del sentido de la secuencia
// Devuelve: el nuevo sentido de la secuencia
// *********************************************************************************************
bool_t pressKey ( bool_t inverted )
{

	/* Lectura de pulsadores para seleccionar el sentido de la secuencia */
	if ( readKey ( keyArray, KEY1 ) ) inverted = FALSE;
	else if ( readKey(keyArray, KEY4 ) ) inverted = TRUE;

	return inverted;

}

//***** LECTURA DE TECLAS CON FUNCION ANTIRREBOTE **********************************************
// Recibe: el arreglo de teclas y el indice correspondiente de la tecla dentro del arreglo
// Devuelve: TRUE si la tecla fue presionada o FALSE en caso contrario
// *********************************************************************************************
static bool_t readKey ( const gpioMap_t *_keyArray, uint8_t keyIndex )
{
	//DEFINICION DE VARIABLES LOCALES
	/* Array de estados para asignarle un estado a cada tecla */
	static dbSt_t debounceState[LAST_KEY] = {WAITING, WAITING, WAITING, WAITING};
	/* Array de retardos para poder asignarle un tiempo antirrebote a cada tecla presionada*/
	static delay_t debounceDelay[LAST_KEY];

	/* Variable que indica si la tecla fue efectivamente presionada */
	bool_t keyPressed = false;

	/* Cambio del estado de las teclas */
	switch(debounceState[keyIndex]){

	/* WAITING: */
	/* Si fue presionada alguna tecla, pasa al estado de DEBOUNCING */
	case WAITING:

		/* Se consulta por la tecla presionada */
		if(gpioRead(_keyArray[keyIndex]) == PRESSED){
			/* Cambio de estado de tecla */
			debounceState[keyIndex] = DEBOUNCING;
			/* Se configura tiempo de antirrebote */
			delayInit(&debounceDelay[keyIndex], DEBOUNCE_TIME);
		}
		break;

	/* DEBOUNCING: */
	/* Comfirma si se presiono una tecla, vuelve al estado de WAITING */
	case DEBOUNCING:
		/* Se consulta si se cumplio el tiempo de antirrebote */
		if(delayRead(&debounceDelay[keyIndex])){
			/* Si la tecla sigue presionada entonces se concluye que fue efectivamente presionada */
			if(gpioRead(_keyArray[keyIndex]) == PRESSED) keyPressed = TRUE;
			/* Cambio de estado de tecla */
			debounceState[keyIndex] = WAITING;
		}
		break;
	}

	return keyPressed;
}
