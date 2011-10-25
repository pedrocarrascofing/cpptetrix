#include "imagen.h"
Imagen::Imagen()
{
	Imag=0;
}

Imagen::Imagen(const Imagen &im)
{
	Imag=graficos::ObtenerCopiaImagen(im.Imag);
}

Imagen::~Imagen()
{
	graficos::LiberarImagen(Imag);
}

Imagen & Imagen::operator=(const Imagen &im)
{
	Imag=im.Imag;
}


void Imagen::LeerFichero(const char* fichero)
{
	Imag=graficos::LeerImagen(fichero);
}

void Imagen::BorrarImagen()
{
	graficos::LiberarImagen(Imag);
}

int Imagen::AltoImagen()const
{
	return graficos::AltoImagen(Imag);
}
int Imagen::AnchoImagen()const
{
	return graficos::AnchoImagen(Imag);
}

void Imagen::DibujarImagen(int x, int y)const
{
	graficos::DibujarImagen(Imag, x, y);
}
