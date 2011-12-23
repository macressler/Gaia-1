/*
 * main.c
 *
 *  Gaia (example) userspace kernel
 *
 *  Created on: 17/12/2011
 *      Author: piranna
 */


#include "eventmanager.h"
#include "syscall.h"

#include "drivers/PIT.h"
#include "drivers/VGA.h"
#include "drivers/keyboard.h"

void init(void)
{
	// Let the exokernel know where the event manager is
	set_eventmanager_send(eventmanager_send);

	// Drivers
    PIT_init(100);	// Initialise the PIT to 100Hz
    VGA_init();
    keyboard_init();
}

void main(void)
{
	init();
}
