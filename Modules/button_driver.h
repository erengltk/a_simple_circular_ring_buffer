/*
 * button_driver.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Eren
 */

#ifndef MODULES_BUTTON_DRIVER_H_
#define MODULES_BUTTON_DRIVER_H_
int a;
enum button_state {pressed,notPressed};
typedef enum button_state state;
void user_button_driver_init(void);
state user_button_driver_get_state(void);
void onboard_button_int_init(void);


#endif /* MODULES_BUTTON_DRIVER_H_ */
