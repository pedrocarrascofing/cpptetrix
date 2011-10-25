#include "vis_texto.h"

Vis_txt::Vis_txt()
	:vis(), texto(), fuente()
{
}
Vis_txt::Vis_txt(const Vis_txt &vt)
{
	vis=vt.vis;
	texto=vt.texto;
	fuente=vt.fuente;
	color=vt.color;
}

Vis_txt::~Vis_txt()
{
}

Vis_txt& Vis_txt::operator=(const Vis_txt & v1)
{
	if(this!=&v1)
	{
		vis=v1.vis;
		texto=v1.texto;
		fuente=v1.fuente;
		color=v1.color;
	}
	return *this;	
}

void Vis_txt::SetVisualizador(const Visualizador &v1)
{
	vis=v1;
}

void Vis_txt::SetTexto(const string &txt)
{
	texto=txt;
}
void Vis_txt::SetFuente(const graficos::GRF_Fuente &f)
{
	fuente=f;
}

void Vis_txt::CargarFuente(const char *fichero, int tamano, int estilo)
{
	fuente=graficos::CargarFuente(fichero, tamano, estilo);
}

void Vis_txt::SetColor(const Color &col)
{
	color=col;
}

int Vis_txt::Ancho()const
{
	return vis.ancho;
}

int Vis_txt::Alto()const
{
	return vis.alto;
}

void Vis_txt::RefreshVis()const
{
	vis.Mostrar();
}

void Vis_txt::RefreshFondo()const
{
	vis.ActualizarFondo();
}

void Vis_txt::RefreshTxt()const
{
	int ancho, alto;
	graficos::TamanoTexto(fuente, texto.c_str(), ancho, alto);
	int x=vis.x + vis.ancho/2 -ancho/2;
	int y=vis.y + vis.alto/2 - alto/2;
	graficos::EscribirTexto(x, y, texto.c_str(), fuente, color.r, color.g, color.b);
}

void Vis_txt::RefreshTxt(const string &t_aux)
{
	texto=t_aux;
	int ancho, alto;
	graficos::TamanoTexto(fuente, texto.c_str(), ancho, alto);
	int x=vis.x + vis.ancho/2 -ancho/2;
	int y=vis.y + vis.alto/2 - alto/2 ;
	graficos::EscribirTexto(x, y, texto.c_str(), fuente, color.r, color.g, color.b);
}




Visualizador Vis_txt::GetVisual()const
{
	return vis;
}

void Vis_txt::Mensaje(int x, int y, const string &text, const Color &color)const
{
	graficos::EscribirTexto(x, y, text.c_str(), fuente, color.r, color.g, color.b);
}


graficos::GRF_Fuente Vis_txt::GetFuente()const
{
	return fuente;
}

SDLKey Vis_txt::MensajeGameOver(int x, int y, int x2, int y2, string txt, Color c)const
{

	int ancho_car, alto_car, tam_txt=txt.size(), a, b;
	graficos::TamanoTexto(fuente, txt.c_str(), ancho_car, alto_car);
	a=x+(x2-x)/2 - ancho_car/2 ;
	b=y+ (y2-y)/2 - alto_car/2;
	SDLKey tec;
	bool camp1=true, camp2=true;
	
	graficos::RectanguloR(x-4, y-4, x2+4, y2+4, 0, 255, 0);
	graficos::RectanguloR(x, y, x2, y2, 0, 0, 0);


	do{
		graficos::DesactivarDibujo();
		graficos::RectanguloR(x, y, x2, y2, 0, 0, 0);
		graficos::EscribirTexto(x, y, "Pulse ESC para salir", fuente, (c.r++)%256, (c.g--)%256, c.b);
		graficos::EscribirTexto(x, y+20, "Pulse N para nueva partida", fuente, (c.r++)%256, (c.g--)%256, c.b);


		if(a< (x2 - ancho_car) && camp1 )
			a++;
		else 
		{
			if(a>x )
			{
				camp1=false;
				a--;
				c.r=0;
			}
			else
				camp1=true;
		}

		if(b< (y2 - alto_car) && camp2 )
		{
			b++;
			c.b=0;
		}
		else 
		{
			if(b>y )
			{
				camp2=false;
				b--;
				c.g=0;
			}
			else
				camp2=true;
		}

		c.b+=3;
		graficos::EscribirTexto(a, b, txt.c_str(), fuente, (c.r++)%256, (c.g--)%256, c.b);
		graficos::ActivarDibujo();	
		graficos::Esperar(10);
		tec=graficos::QueTeclaHayPulsada();
	}while(tec==SDLK_UNKNOWN);
}


