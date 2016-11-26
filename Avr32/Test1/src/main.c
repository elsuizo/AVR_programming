/* -------------------------------------------------------------------------
@file main.c

@date 10/24/15 14:18:47
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include "../inc/main.h"

int main(void)
{
    DDRB |= (1 << PB4); // make pin4 PORTB output
    while(1)
    {
        PORTB ^= (1 << PB4);
        _delay_ms(7000);
    }
    return 0 ;
}



