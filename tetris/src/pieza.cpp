#include "pieza.h"

Pieza::Pieza() :pza()
{}

Pieza::Pieza(const Matriz &m) :pza(m)
{}

Pieza::Pieza(int fil, int col) :pza(fil, col)
{}
	
Pieza::Pieza(const Pieza &p) :pza(p.pza)
{}

Pieza& Pieza::operator=(const Pieza &p)
{
	if(this!=&p)
		pza=p.pza;
	return *this;
}

void Pieza::GiroDer()
{
	pza=pza.TrasFil();
	pza=pza.Traspuesta();
}

void Pieza::GiroIz()
{	
	pza=pza.TrasCol();
	pza=pza.Traspuesta();
}
