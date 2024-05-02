
#include "stdint.h"



#ifndef __pt100_h
#define __pt100_h

/* Function to calculate temperature by resistance
 *
 * @param	resistance in ohms*1000000
 *
 * @retval	temperature * 100
 *
 * @note    This function returns the temperature in degrees Celsius multiplied by 100.
 *          In order to get value in degrees Celsius, divide by 100
 *
 * @example if returned value = -2563, then value in degrees Celsius = -2563 / 100 = -25.63
 * 		    if returned value = +2341, then value in degrees Celsius = +2341 / 100 = +23.41
 */
int32_t PT100_CalcTemperature(uint32_t resistance1000000);

#endif /* __pt100_h */

/* end of pt100.h */
