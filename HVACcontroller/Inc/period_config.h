


#ifndef __period_config_h
#define __period_config_h



/* Inputs scan period in milliseconds
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_INPUTS_SCAN_MS					(100)


/* Encoder scan period in milliseconds
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_ENCODER_SCAN_MS					(4)



/* Sensors scan period in milliseconds
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_SENSORS_SCAN_MS					(200)



/* AM2320 sensor scan period in milliseconds
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_AM2320_SCAN_MS					(2200)



/* Heating process period
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_HEATING							(PERIOD_CONF_SENSORS_SCAN_MS)



/* Ventilation process period
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_VENTILATION						(PERIOD_CONF_SENSORS_SCAN_MS)



/* The time to return display to the initial state in seconds
 *
 * @lower limit None
 * @upper limit None
 */
#define PERIOD_CONF_DISPLAY_RETURN_S				(300)



#endif /* __period_config_h */

/* end of period_config.h */
