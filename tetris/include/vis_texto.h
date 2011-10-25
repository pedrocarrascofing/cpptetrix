/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef __VIS_TEXTO_H__
#define __VIS_TEXTO_H__

#include "visualizador.h"
#include "color.h"
#include "graficos.h"
#include <iostream>

using namespace std;


class Vis_txt{
	
	public:

	/**
	  @brief Constructor por defecto
	*/
	Vis_txt();

	/**
	  @brief Constructor de copia
	*/
	Vis_txt(const Vis_txt &vt);	

	/**
	  @brief Destructor
	*/
	~Vis_txt();

	/**
	  @brief Operador asignacion
	*/
	Vis_txt& operator=(const Vis_txt &v1);

	/**
	  @brief Dibuja el visualizdor de vis_txt en pantalla
	*/
	void RefreshVis()const;

	/**
	  @brief Dibuja el fondo del visualizador de vis_txt
	*/
	void RefreshFondo()const;

	/**
	  @brief Dibuja el texto de vist_txt
	*/
	void RefreshTxt()const;

	/**
	  @brief Muestra el texto t_aux en pantalla
	  @param t_aux texto a mostrar en pantalla
	
	  Muestra en pantalla t_aux y modifica el texto de vis_txt
	*/
	void RefreshTxt(const string &t_aux);


	/**
	  @brief Devuelve el visualizador de vis_txt
	  @return Visualizador de vis_txt
	*/
	Visualizador GetVisual()const;

	/**
	  @brief Devuelve la fuente
	  @return Fuente de vis_txt
	*/
	graficos::GRF_Fuente GetFuente()const;

	/**
	  @brief Escribe el mensaje text en pantalla en la posicion x, y con color color
	  @param x columna en pixel a escribir el texto
	  @param y fila en pixel a escribir el texto
	  @param text texto a escribir
	  @param color color del texto

	  Escribe text en pantalla usando la fuente y el tamaño del vis_tx que se le pasa
	*/
	void Mensaje(int x, int y, const string &text, const Color &color)const;

	/**
	  @brief Crea una rectangulo de dimensiones x2-x, y2-y en negro en el cual se visuliaza txt en movimiento mientras no se pulse una tecla
	  @param x columna del primer punto
	  @param y fila del primer punto
	  @param x2 columna del segundo punto
	  @param y2 fila del segundo punto
  	  @param txt texto a mostrar
	  @param c color inicial del texto
	  @return tecla pulsada

	  Muestra txt en pantalla con colores aleatorios mientras no se pulse una tecla, devuelve la tecla pulsada
	*/
	SDLKey MensajeGameOver(int x, int y, int x2, int y2, string txt, Color c)const;


	/**
	  @brief Cambia el visualizador de vis_txt
	  @param v1, nuevo visualizador
	*/	
	void SetVisualizador(const Visualizador& v1);

	/**
	  @brief Cambia el texto de vis_txt
	  @param txt nuevo texto
	*/	
	void SetTexto(const string &txt);

	/**
	  @brief Cambia la fuente de vis_txt
	  @param f nueva fuente
	*/	
	void SetFuente(const graficos::GRF_Fuente& f);

	/**
	  @brief Carga la fuente de vis_txt
	  @param fichero nombre del fichero con la fuente
	  @param tamano tamaño del texto
	  @param estilo estilo del texto, 0 normal
	*/	
	void CargarFuente(const char *fichero, int tamano, int estilo=0);

	/**
	  @brief Cambia el color del texto de vis_txt
	  @param col nuevo color
	*/	
	void SetColor(const Color &col);

	/**
	  @brief Devuelve el ancho del visualizador de vis_txt
	  @return Ancho del visualizador
	*/	
	int Ancho()const;

	/**
	  @brief Devuelve el alto del visualizador de vis_txt
	  @return Alto del visualizador
	*/	
	int Alto()const;
	
	private:
	Visualizador vis;
	string texto;
	graficos::GRF_Fuente fuente;
	Color color;
};



#endif
