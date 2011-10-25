#include <fstream>
#include <sstream>
#include "vis_texto.h"
#include "vis_tablero.h"
#include "vis_cola.h"
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;
/**
  @brief Ignora comentarios precedidos del simbolo #, espacios, tabulaciones ...
  @param f flujo del que ignorar los comentarios

  Si ocurre algun problema en la lectura del fichero assert(f), rompe el progrma
*/
void IgnorarComentarios(ifstream & f);

/**
  @brief Consigue los datos correspondientes a un visualizador dado por un flujo de entrada f
  @param f flujo del que conseguir el visualizador
  @return visuailzador con los datos obtenidos
*/
Visualizador ConseguirVisualizador(ifstream &f);

/**
  @brief Consigue los datos correspondientes a un visualizador de texto dados por un flujo de entrada f
  @param f flujo del que conseguir el visualizador de texto
  @return visualizador de texto con los dato obtenidos
*/
Vis_txt ConseguirVis_txt(ifstream & f);

/**
  @brief Consigue los datos correspondientes a una pieza dados por un flujo de entrada f 
  @param f flujo del que conseguir la pieza
  @param n_imagenes indica los valores entre los que deben estar comprendidos los datos de la pieza
  @return Pieza con los datos obtenidos del flujo

  Si n_imagenes==-1 tras finalizar el modulo, indica que ha habido un error durante la lectura
*/
Pieza ConseguirPieza(ifstream &f, int &n_imagenes);

/**
  @brief Consigue los datos correspondientes a una matriz dados por un flujo de entrada f
  @param f flujo del que conseguir la matriz
  @return matriz con los datos obtenidos del flujo
*/
Matriz ConseguirMatriz(ifstream &f);

/**
  @brief Consigue los datos correspondientes a un vector de imagenes y el n_imagenes de dicho vector dados por un flujo de entrada f
  @param f flujo del que conseguir los datos
  @param img vector de imagenes, el contenido anterior es borrado
  @param n_imagenes variable en la que almacenar el nº de imagenes del vector
  @param dir_imagenes directorio en el que se encuentran las imagenes
  @return true si no hay ningun fallo en la lectura o el tipo de dato proporcionado por el flujo, false en otro caso
*/
bool ConseguirVecImagenes(ifstream &f, Imagen* &img, int &n_imagenes, string &dir_imagenes);

/**
  @brief Consigue los datos correspondientes a un vector de piezas dados por un flujo de entrada f
  @param f flujo del que conseguir los datos
  @param v_piezas vector de piezas, el contenido anterior es borrado
  @param n_piezas variable en la que almacenar el nº de piezas del vector
  @param max indica los valores entre los que deben estar comprendidos los elementos de las piezas entre 0 y max-1 
  @return true si no hay ningun fallo en la lectura o el tipo de dato proporcionado por el flujo, false en otro caso
*/
bool ConseguirVecPiezas(ifstream &f, Pieza* &v_piezas, int &n_piezas, int max);

/**
   @brief Si es posible mueve abajo la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
bool MoverAbajo(Tablero &tablero, Vis_tablero & visual_tab);

/**
   @brief Si es posible mueve a la derecha la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
void MoverDerecha(Tablero &tablero, Vis_tablero & visual_tab);

/**
   @brief Si es posible mueve a la izquierda la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
void MoverIzquierda(Tablero &tablero, Vis_tablero & visual_tab);

/**
   @brief Si es posible gira a la derecha la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
void GirarPiezaDer(Tablero &tablero, Vis_tablero & visual_tab);

/**
   @brief Si es posible Gira a la izquierda la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
void GirarPiezaIz(Tablero &tablero, Vis_tablero & visual_tab);

/**
   @brief Si es posible mueve hacia arriba la pieza de tablero y actualiza visual_tab
   @param tablero tablero en el que realizar el movimiento, queda modificado
   @param visual_tab visualizador del tablero
   @return true si se ha realizado el movimiento, false en otro caso
*/
bool MoverArriba(Tablero &tablero, Vis_tablero & visual_tab, int &n_respiros);

int main(int argc, char* argv[])
{

	if(argc!=2)	
	{
		cerr<<"Necesario fichero de configuracion " << endl;
		return 1;
	}
	ifstream f(argv[1], ios::in);

	if(!f)
	{
		cerr<<"Error leyendo fichero";
		return 1;
	}
	
	
	string dir_imagenes, mens_titulo;
	int semilla, t_inicial_espera, line_nivel, n_piezas_cola, n_imagenes, n_piezas, pieza;
	Vis_txt v_titulo, v_nivel, v_lineas, v_marcador, v_estado;
	Visualizador vis_for_tab, vis_for_cola, vis_for_txt;
	Pieza *v_piezas=0;
	Imagen *v_imagenes=0;
	Cola_p cola;
	
////////Parámetros relacionados con la dinámica del juego//////////////

	IgnorarComentarios(f);
	f>> semilla;

	IgnorarComentarios(f);
	f>> t_inicial_espera;
	if(t_inicial_espera<0)
	{
		cerr << "Problema con el tiempo inicial de bajada " << endl;
		return -1;
	}

	IgnorarComentarios(f);
	f>> line_nivel;
	if(line_nivel<0)
	{
		cerr << "Problema con el numero de lineas por nivel " << endl;
		return -1;
	}
	
	IgnorarComentarios(f);
	f>>n_piezas_cola;
	if(n_piezas_cola < 0 )
	{
		cerr << "Problema con el numero de piezas en cola " << endl;
		return -1;
	}

////////Parámetros relacionados con la presentación en Pantalla/////////

	if(! ConseguirVecImagenes(f, v_imagenes, n_imagenes, dir_imagenes) )
		return 1;
	
	vis_for_tab=ConseguirVisualizador(f);
	vis_for_cola=ConseguirVisualizador(f);

	IgnorarComentarios(f);
	getline(f, mens_titulo);

	v_titulo=ConseguirVis_txt(f);
	v_nivel=ConseguirVis_txt(f);
	v_lineas=ConseguirVis_txt(f);
	v_marcador=ConseguirVis_txt(f);
	v_estado=ConseguirVis_txt(f);
	
////////Vector de piezas///////////////////

	if( !( ConseguirVecPiezas(f, v_piezas, n_piezas, n_imagenes) ) )
	{
		cerr << "Problema con las piezas" << endl;
		return -1;
	}


	time_t t;
	if(semilla!=0)
		t=semilla;
	srandom(t);
	pieza=random()%n_piezas;
////////Construccion de tablero y visualizador tablero////////////////

	Tablero tablero( ConseguirMatriz(f), v_piezas[pieza]);
	
	f.close();

	Vis_tablero visual_tab(vis_for_tab, &tablero, v_imagenes);

////////Construccion de la cola y visualizador cola///////////////////

	for(int i=0; i<n_piezas_cola+1; i++)
	{
		cola.push(v_piezas[pieza]);
		pieza=random()%n_piezas;
	}

	Vis_cola v_cola(&cola, vis_for_cola, v_imagenes);

////////Creacion de la ventana y de los visualizadores ////////////////

	int alto_tot=vis_for_tab.GetAlto();
	int ancho_tot=vis_for_tab.GetAncho() + vis_for_cola.GetAncho() + v_titulo.Ancho();

	graficos::CrearVentana(ancho_tot, alto_tot, mens_titulo.c_str());	

	graficos::DesactivarDibujo();
	visual_tab.RefreshVis();

	v_titulo.RefreshVis();
	v_titulo.RefreshTxt("Tetris MP2");
	v_nivel.RefreshVis();
	v_nivel.RefreshTxt("Nivel 0");
	v_lineas.RefreshVis();
	v_lineas.RefreshTxt("Lineas 0");
	v_marcador.RefreshVis();
	v_marcador.RefreshTxt("Piezas 1");
	v_estado.RefreshVis();
	v_estado.RefreshTxt("Jugando...");
	v_cola.RefreshVis();
	v_cola.RefreshCola();
	visual_tab.RefreshTablero();

	graficos::ActivarDibujo();

////////Desarrollo del juego//////////////////
	
	int cont_lineas=0, cont_piezas=1, aux_l=0, t_espera=t_inicial_espera, nivel, nivel_anterior=0;
	string aux;
	stringstream conver;
	bool GameOver=false, posible_abajo=true;
	Color c_aux;

	SDLKey tec=SDLK_DOWN;

	graficos::CronometroInicio();
	do{
		graficos::DesactivarDibujo();
		
		switch(tec)
		{
			case SDLK_DOWN: posible_abajo=MoverAbajo(tablero, visual_tab);
					break;
			case SDLK_RIGHT: MoverDerecha(tablero, visual_tab);				
					break;
			case SDLK_LEFT:	MoverIzquierda(tablero, visual_tab);
					break;
			case SDLK_w:	GirarPiezaDer(tablero, visual_tab);
					break;
			case SDLK_q:	GirarPiezaIz(tablero, visual_tab);
					break;
			case SDLK_SPACE: graficos::ObtenerTecla();
					 graficos::CronometroInicio();
					break;
			default:	break;
		}

		if(graficos::CronometroValor() > t_espera)
		{
			graficos::CronometroInicio();
			posible_abajo=MoverAbajo(tablero, visual_tab);
		}

		if(!posible_abajo)
		{
			if(tablero.FinJuego())
				GameOver=true;
			else
			{
				tablero.Apilar();
				aux_l=tablero.Barrido();
				cola.pop();
				pieza=random()%n_piezas;
				cola.push(v_piezas[pieza]);
				tablero.ResetPieza(cola.front());
				cont_piezas++;
				conver << cont_piezas;
				conver >> aux;
				conver.clear();
				v_marcador.RefreshFondo();
				v_marcador.RefreshTxt("Piezas "+ aux);
				v_cola.RefreshVis();
				v_cola.RefreshCola();

			}
			posible_abajo=true;
		}	
		
		
		if(aux_l>0)
		{
			cont_lineas +=aux_l;
			aux_l=0;
			nivel=static_cast<int>(cont_lineas/line_nivel);
			if(nivel!=nivel_anterior)
			{
				t_espera-=(nivel-nivel_anterior)*25;
				nivel_anterior=nivel;
				conver << nivel;
				conver >> aux;
				conver.clear();
				v_nivel.RefreshFondo();
				v_nivel.RefreshTxt("Nivel " + aux);
			}
			
			conver << cont_lineas;
			conver >> aux;
			conver.clear();
			v_lineas.RefreshFondo();
			v_lineas.RefreshTxt("Lineas " + aux);
		}

		graficos::ActivarDibujo();

		if(GameOver)
		{
			v_estado.RefreshFondo();
			v_estado.RefreshTxt("GAME OVER");
			c_aux.r=255;
			c_aux.g=255;
			c_aux.b=255;
			tec=v_titulo.MensajeGameOver(ancho_tot/4, alto_tot/4, 3*ancho_tot/4, 3*alto_tot/4, "Perdiste" , c_aux);
			if(tec==SDLK_n)
			{
				tablero.ResetTablero();
				GameOver=false;
				cont_lineas=0;
				cont_piezas=1;
				nivel=0;
				v_titulo.RefreshVis();
				v_titulo.RefreshTxt("Tetris MP2");
				v_nivel.RefreshVis();
				v_nivel.RefreshTxt("Nivel 0");
				v_lineas.RefreshVis();
				v_lineas.RefreshTxt("Lineas 0");
				v_marcador.RefreshVis();
				v_marcador.RefreshTxt("Piezas 1");
				v_estado.RefreshVis();
				v_estado.RefreshTxt("Jugando...");
				v_cola.RefreshVis();
				v_cola.RefreshCola();
				visual_tab.RefreshVis();
				visual_tab.RefreshTablero();
			}

		}
		else 
			tec=graficos::QueTeclaHayPulsada();
			
	}while(tec!=SDLK_ESCAPE && !GameOver);	

	delete[] v_imagenes;
	delete[] v_piezas;


}

void IgnorarComentarios(ifstream & f)
{
	string a;
	while(f.peek()=='#' || isspace(f.peek() ) )
	{
		if(f.peek()=='#')
			getline(f, a);
		else
			f.ignore();
	}
	if(!f)
		cerr << "Error con la lectura del fichero de configuracion " << endl;
	assert(f);
	
}

Visualizador ConseguirVisualizador(ifstream &f)
{
	Visualizador vaux;
	int  aux, x, y, g_borde, ancho, alto;
	Color c_fondo, c_borde;

	IgnorarComentarios(f);	
	f>>y;
	IgnorarComentarios(f);	
	f>>x;
	IgnorarComentarios(f);	
	f>>ancho;
	IgnorarComentarios(f);	
	f>>alto;
	IgnorarComentarios(f);	
	f>>g_borde;
	IgnorarComentarios(f);	
	f>>aux;
	c_borde.r=(unsigned char)aux;
	IgnorarComentarios(f);	
	f>>aux;
	c_borde.g=(unsigned char)aux;
	IgnorarComentarios(f);	
	f>>aux;
	c_borde.b=(unsigned char)aux;
	IgnorarComentarios(f);	
	f>>aux;
	c_fondo.r=(unsigned char)aux;
	IgnorarComentarios(f);	
	f>>aux;
	c_fondo.g=(unsigned char)aux;
	IgnorarComentarios(f);	
	f>>aux;
	c_fondo.b=(unsigned char)aux;
	
	vaux.SetPosicion(x, y);
	vaux.SetGBorde(g_borde);
	vaux.SetDimensiones(ancho, alto);
	vaux.SetColorBorde(c_borde);
	vaux.SetColorFondo(c_fondo);
	return vaux;
}
	
Vis_txt ConseguirVis_txt(ifstream & f)
{
	int n1, n2;
	Color c_aux;
	string aux;
	Vis_txt v_txt;

	IgnorarComentarios(f);
	f>> aux;
	IgnorarComentarios(f);
	f>> n1;
	IgnorarComentarios(f);
	f>>n2;
	
	v_txt.CargarFuente(aux.c_str(), n1, n2);

	IgnorarComentarios(f);
	f>>n1;
	c_aux.r=(unsigned char)n1;
	IgnorarComentarios(f);
	f>>n1;
	c_aux.g=(unsigned char)n1;
	IgnorarComentarios(f);
	f>>n1;
	c_aux.b=(unsigned char)n1;

	v_txt.SetColor(c_aux);
	v_txt.SetVisualizador( ConseguirVisualizador(f) );
	return v_txt;
}

Pieza ConseguirPieza(ifstream &f, int &n_imagenes)
{
	int fil, col, elem;

	IgnorarComentarios(f);
	f>>fil;
	IgnorarComentarios(f); 
	f>>col;
	
	bool fin=false;
	Pieza aux(fil, col);
	for(int i=0; i<fil && !fin; i++)
		for(int j=0; j<col && !fin; j++)
		{
			IgnorarComentarios(f);
			f>> elem;
			if(elem>n_imagenes)
				fin = true;
			aux.SetPieza(i, j, elem);
		}
	if (fin)
		n_imagenes=-1;
	return aux;
}

Matriz ConseguirMatriz(ifstream &f)
{
	IgnorarComentarios(f);
	int fil, col, elem;
	f>>fil;
	IgnorarComentarios(f);
	f>> col;

	IgnorarComentarios(f);
	Matriz aux(fil, col);	

	for(int i=0; i<fil; i++)	
		for(int j=0; j<col; j++)
		{
			IgnorarComentarios(f);
			f>> elem;
			aux.SetMatriz(i, j, elem);
		}
	return aux;
}

bool ConseguirVecPiezas(ifstream &f, Pieza* &v_piezas, int &n_piezas, int n_imagenes)
{
	IgnorarComentarios(f);
	f>>n_piezas;
	int aux=n_imagenes;

	if(n_piezas<1)
	{
		cerr << "Error con el numero de piezas " << endl;
		return false;
	}
	delete []v_piezas;
	v_piezas=new Pieza[n_piezas];
	
	for(int i=0; i<n_piezas; i++)
		v_piezas[i]=ConseguirPieza(f, aux);
	if(aux==-1)
		return false;
	return true;
}

bool ConseguirVecImagenes(ifstream &f, Imagen* &img, int &n_imagenes, string &dir_imagenes)
{
	IgnorarComentarios(f);
	f>>n_imagenes;
	IgnorarComentarios(f);
	getline(f, dir_imagenes);

	if(n_imagenes<1)
	{
		cerr << "Error con el nº de imagenes" << endl;
		return false;
	}
	string aux, a;
	IgnorarComentarios(f);
	delete []img;
	img=new Imagen[n_imagenes];
	for(int i=0; i<n_imagenes; i++)
	{
		f>>aux;	
		img[i].LeerFichero( (dir_imagenes + '/' + aux).c_str() );
	}
	return true;
}

bool MoverAbajo(Tablero &tablero, Vis_tablero & visual_tab)
{
	if( tablero.MovDown())
	{
		visual_tab.RefreshFondo();
		visual_tab.RefreshTablero();
		visual_tab.RefreshPieza();
		return true;
	}
	else
		return false;
}

void MoverDerecha(Tablero &tablero, Vis_tablero & visual_tab)
{

	if(tablero.MovRight())
	{
		visual_tab.RefreshFondo();
		visual_tab.RefreshTablero();
		visual_tab.RefreshPieza();
	}

}

void MoverIzquierda(Tablero &tablero, Vis_tablero & visual_tab)
{
	if(tablero.MovLeft())
	{
		visual_tab.RefreshFondo();
		visual_tab.RefreshTablero();
		visual_tab.RefreshPieza();
	}				

}

void GirarPiezaDer(Tablero &tablero, Vis_tablero & visual_tab)
{	
	
	if(tablero.GirarDer())
	{	
		visual_tab.RefreshFondo();
		visual_tab.RefreshTablero();
		visual_tab.RefreshPieza();
	}
	
}
	
void GirarPiezaIz(Tablero &tablero, Vis_tablero & visual_tab)
{	
	
	if(tablero.GirarIz())
	{	
		visual_tab.RefreshFondo();
		visual_tab.RefreshTablero();
		visual_tab.RefreshPieza();
	}
	
}

bool MoverArriba(Tablero &tablero, Vis_tablero & visual_tab, int &n_respiros)
{
	if(n_respiros>0)
	{
		while(tablero.MovUp())
		{}
		n_respiros--;
		return true;
	}
	else
		return false;
}
		

