#include <iostream>
#include "Range.h"

Range::Range(int st, int ed, int wght) :
	start{st},
	end{ed},
	weight{wght}
{
	
}

void Range::descrb() const
{
	std::cout << "'" << (char)start << "'(" << start << ") - '"
	          << (char)end << "'(" << end << ") wght: " << weight
	          << std::endl;
}
