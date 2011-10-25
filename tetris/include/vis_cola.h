/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef __VISUALIZADOR_COLA__
#define __VISUALIZADOR_COLA__


#include "graficos.h"
#include "cola_piezas.h"
#include "visualizador.h"
#include "imagen.h"
#include <iostream>

using namespace std;

class Vis_cola
{
	public:
	
	/**
   	   @brief Constructor por defecto
	*/
	Vis_cola();

	/**
   	   @brief Constructor de copia
	*/
	Vis_cola(const Vis_cola & v1);

	/**
   	   @brief Constructor con parametros
	   @param cola puntero a la cola de vis_cola
	*/
	Vis_cola(Cola_p* cola);

	/**
   	   @brief Constructor con parametros
	   @param cola puntero a la cola
	   @param vis visualizador
	   @param im puntero al vector de imagenes
	*/
	Vis_cola(Cola_p* cola, const Visualizador & vis, Imagen* im);

	/**
   	   @brief Modifica el visualizador
	   @param v1 nuevo visualizador
	*/
	void SetVisualizador(const Visualizador &v1);

	/**
   	   @brief Modifica la cola
	   @param cp puntero a la nueva cola
	*/
	void SetCola(Cola_p * cp);

	/**
   	   @brief Modifica la el vector de imagenes
	   @param im puntero al nuevo vector
	*/
	void SetImagen(Imagen * im);

	/**
   	   @brief Muestra el visualizador
	*/
	void RefreshVis()const;

	/**
   	   @brief Muestra el fondo del visualizador
	*/
	void RefreshFondo()const;

	/**
   	   @brief Muestra la cola de piezas
	*/
	void RefreshCola()const;
	
	private:
	Cola_p *cola;
	Visualizador vis;
	Imagen* im;

};

#endif
