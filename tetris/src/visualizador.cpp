#include "visualizador.h"

Visualizador::Visualizador()
{
	x=y=ancho=alto=g_borde=0;
	c_borde.r=c_fondo.r=0;
	c_borde.g=c_fondo.g=0;
	c_borde.b=c_fondo.b=0;
}
			

Visualizador::Visualizador(const Visualizador &v1)
{
	x=v1.x;
	y=v1.y;
	ancho=v1.ancho;
	alto=v1.alto;
	c_borde=v1.c_borde;
	c_fondo=v1.c_fondo;
}
	
Visualizador::Visualizador(int ancho, int alto)
{
	x=y=g_borde=0;
	this->ancho=ancho;
	this->alto=alto;
	c_borde.r=c_fondo.r=0;
	c_borde.g=c_fondo.g=0;
	c_borde.b=c_fondo.b=0;
}	

Visualizador::~Visualizador()
{
}
	
//Operator=
Visualizador& Visualizador::operator=(const Visualizador &v1)
{
	if(this!=&v1)
	{
		x=v1.x;
		y=v1.y;
		ancho=v1.ancho;
		alto=v1.alto;
		g_borde=v1.g_borde;
		c_borde=v1.c_borde;
		c_fondo=v1.c_fondo;
	}
	return *this;
}

void Visualizador::Mostrar()const
{
	graficos::RectanguloR(x, y, x+ancho-1, y+alto-1, c_borde.r, c_borde.g, c_borde.b);
	graficos::RectanguloR(x+g_borde, y+g_borde, x+ancho-g_borde-1, y+alto-g_borde-1, c_fondo.r, c_fondo.g, c_fondo.b);
}	

void Visualizador::ActualizarFondo()const
{
	graficos::RectanguloR(x+g_borde, y+g_borde, x+ancho-g_borde-1, y+alto-g_borde-1, c_fondo.r, c_fondo.g, c_fondo.b);
}

void Visualizador::SetColorFondo(const Color c)
{
	c_fondo=c;
}

void Visualizador::SetColorBorde(const Color c)
{
	c_borde=c;
}

void Visualizador::SetPosicion(int x, int y)
{
	this->x=x;
	this->y=y;
}

void Visualizador::SetDimensiones(int ancho, int alto)
{
	this->ancho=ancho;
	this->alto=alto;
}
void Visualizador::SetGBorde(int borde)
{
	g_borde=borde;
}

int Visualizador::GetAlto()const
{
	return alto;
}

int Visualizador::GetAncho()const
{
	return ancho;
}
