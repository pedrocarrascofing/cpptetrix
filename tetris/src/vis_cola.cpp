#include "vis_cola.h"

Vis_cola::Vis_cola()
	:vis()	
{
	im=0;
	cola=0;
}

Vis_cola::Vis_cola(const Vis_cola & v1)
{
	cola=v1.cola;
	vis=v1.vis;
	im=v1.im;
}

Vis_cola::Vis_cola(Cola_p* cola)
	:vis()
{
	im=0;
	this->cola=cola;
}

Vis_cola::Vis_cola(Cola_p* cola, const Visualizador & vis, Imagen* im)
{
	this->cola=cola;
	this->vis=vis;
	this->im=im;
}



void Vis_cola::SetVisualizador(const Visualizador &v1)
{
	vis=v1;
}

void Vis_cola::SetCola(Cola_p * cp)
{
	cola=cp;
}

void Vis_cola::SetImagen(Imagen * im)
{
	this->im=im; 
}

void Vis_cola::RefreshVis()const
{
	vis.Mostrar();
}

void Vis_cola::RefreshFondo()const
{
	vis.ActualizarFondo();
}

void Vis_cola::RefreshCola()const
{

	int ancho_im, x, y;
	int alto_im, aux, mayor_alto=0;
	int alto_pieza, ancho_pieza;
	Pieza p_aux;

	for(int k=1; k < cola->size(); k++)
	{
		p_aux=cola->GetPieza(k);
		alto_pieza=p_aux.Alto();
		if(mayor_alto<alto_pieza)
			mayor_alto=alto_pieza;
		ancho_pieza=p_aux.Ancho();
		for(int j=0; j< alto_pieza; j++)
			for(int i=0; i<ancho_pieza; i++)
			{
				aux=p_aux.GetPieza(j, i);
				if(aux!=0)
				{
					ancho_im=im[aux-1].AnchoImagen();
					alto_im=im[aux-1].AnchoImagen();
					x=ancho_im*i + vis.x+vis.ancho/2 - (ancho_pieza*ancho_im)/2 ;
					y=vis.y + vis.g_borde + alto_im*(j+1) + (mayor_alto+1)*(k-1)*alto_im;
					im[aux-1].DibujarImagen(x, y);
				}
			}
	}


}	

