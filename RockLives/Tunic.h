//Author: Marco Duran
//Piece of armor called a tunic, it is a light piece of armor

#ifndef _TUNIC_
#define _TUNIC_

#include "Armor.h"

class Tunic : public Armor{
	private:
		//defense value of the armor
		int value;

	public:
		//Initialize tunic with its inventory tag
		Tunic(df::Position position);

		~Tunic();

		void apply(const ApplyEvent *p_apply_event);
};

#endif