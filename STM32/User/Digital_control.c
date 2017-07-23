#include "board.h"


void digital_out_put_controler(void) {
		if(sys.Relay1_out) {
					RELAY1_ON;
		}
		else {
			RELAY1_OFF;
		}
}
