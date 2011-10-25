/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef __VIS_TABLERO_H__
#define __VIS_TABLERO_H__

#include <iostream>
#include "visualizador.h"
#include "tablero.h"
#include "imagen.h"

using namespace std;

class Vis_tablero{
	
	public:
	/**
	  @brief Constructor por defecto
	*/
   	Vis_tablero();

	/**
	  @brief Constructor de copia
	*/
	Vis_tablero(const Vis_tablero &vt);

	/**
	  @brief Constructor con parametros
	  @param vis visualizador 
	  @param t puntero al tablero
	  @param imagen puntero a imagen
	*/
	Vis_tablero(const Visualizador &vis, Tablero *t, Imagen *imagen);

	/**
	  @brief Dibuja el visualizador en pantalla
	*/
	void RefreshVis()const;

	/**
	  @brief Dibuja el fondo de visualizador en pantalla
	*/
	void RefreshFondo()const;

	/**
	  @brief Muestra el tablero
	*/
	bool RefreshTablero()const;

	/**
	  @brief Muestra la pieza
	*/
	bool RefreshPieza()const;


	private:
	Visualizador vis;
	Tablero *tablero;
	Imagen *im;
};

#endif
