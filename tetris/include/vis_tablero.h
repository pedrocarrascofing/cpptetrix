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
