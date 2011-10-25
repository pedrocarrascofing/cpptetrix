/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef	__IMAGEN_H__
#define __IMAGEN_H__
#include "graficos.h"

class Imagen{
	public:

	/**
	   @brief Constructor por defecto
	*/
	Imagen();

	/**
	   @brief Constructor de copia
	*/
	Imagen(const Imagen &im);
	
	/**
	   @brief Destructor
	*/
	~Imagen();

	/**
	   @brief Operador asignacion
	*/
	Imagen & operator=(const Imagen &im);
	
	/**
	   @brief Cargar desde un fichero en disco una imagen BMP en la Imag
	   @param fich nombre del archivo con la imagen 
	*/
	void LeerFichero(const char* fichero);

	/**
	   @brief Borra la imagen (la libera)
	*/
	void BorrarImagen();

	/**
	   @brief Devuelve el alto de la imagen en pixel
	*/
	int AltoImagen()const;

	/**
	   @brief Devuelve el ancho de la imagen en pixel
	*/
	int AnchoImagen()const;


	/**
	   @brief Dibuja la imagen en ventana
	   @param x posicion en x en la que dibujar
	   @param y posicion en y en la que dibujar
	*/
	void DibujarImagen(int x, int y)const;

private:
	graficos::GRF_Imagen Imag;
};
#endif
