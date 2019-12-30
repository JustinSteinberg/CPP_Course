/* PirateMates.h
 * Justin Steinberg, COMP15 Spring 2019
 * 01/28/2019
 * This is the header file that contains
 * The struct of pirates and their mates
 */

#ifndef __PIRATE_MATES__
#define __PIRATE_MATES__

#include <string>
#include "ArrayList.h"
#include "Pirate.h"
using namespace std;

struct PirateMates {
 
   Pirate pirate;   
   ArrayList mates;

};

#endif
