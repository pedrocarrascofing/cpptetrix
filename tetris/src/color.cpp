#include "color.h"

Color &Color::operator=(const Color &c)
{
	if(this!=&c)
	{
		r=c.r;
		g=c.g;
		b=c.b;
	}
	return *this;
}
