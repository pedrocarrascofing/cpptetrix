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

void Pieza::SetPieza(int i, int j, int n)
{
	pza.SetMatriz(i, j, n);
}
	
int Pieza::GetPieza(int i, int j)const 
{
	return pza.GetMatriz(i, j);
} 

int Pieza::Alto()const
{
	return (pza.FilasMatriz());
}

int Pieza::Ancho()const
{
	return (pza.ColumnasMatriz());
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

	
