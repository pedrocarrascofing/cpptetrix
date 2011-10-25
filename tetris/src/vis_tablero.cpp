#include "vis_tablero.h"
Vis_tablero::Vis_tablero()
{}

Vis_tablero::Vis_tablero(const Vis_tablero &vt)
{	
	im=vt.im;
	tablero=vt.tablero;
	vis=vt.vis;
}
	
Vis_tablero::Vis_tablero(const Visualizador &vis, Tablero* t, Imagen* imagen)
{
	im=imagen;
	this->vis=vis;
	tablero=t;
}

void Vis_tablero::RefreshVis()const
{
	vis.Mostrar();
}

void Vis_tablero::RefreshFondo()const
{
	vis.ActualizarFondo();
}

bool Vis_tablero::RefreshTablero()const
{
	int aux, p_x=im[0].AnchoImagen(), p_y=im[0].AltoImagen();
	for(int i=0; i<tablero->Alto(); i++)
		for(int j=0; j<tablero->Ancho(); j++)
		{
			aux=tablero->GetTabElem(i, j);
			if(aux>0)
				im[aux-1].DibujarImagen((j*p_x)+vis.g_borde, (i*p_y)+vis.g_borde);		
		}
}

bool Vis_tablero::RefreshPieza()const
{
	int p_x, p_y, aux;
	p_x=im[0].AnchoImagen();
	p_y=im[0].AltoImagen();
	for(int i=0; i<tablero->AltoPieza(); i++)
		for(int j=0; j<tablero->AnchoPieza(); j++)
		{
			aux=tablero->GetPiezaElem(i, j);
			if(aux>0)
			{
			im[aux-1].DibujarImagen((j*p_x)+vis.g_borde+(tablero->PosXPieza()*p_x),  (i*p_y)+vis.g_borde +(tablero->PosYPieza()*p_y));	
			}			
		}
}	


