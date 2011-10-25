/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef __COLA_PIEZAS_H__
#define __COLA_PIEZAS_H__
#include "pieza.h"

struct lista_nodo{
	lista_nodo * sig;
	lista_nodo * ant;
	Pieza elem;
	};

class Cola_p
{
	public:
	/**
	  @brief Constructor por defecto
	*/
	Cola_p();

	/**
	  @brief Constructor de copia
	*/
	Cola_p(const Cola_p &c);

	/**
	  @brief Destructor
	*/
	~Cola_p();

	/**
	  @brief Operador asignacion
	*/
	Cola_p & operator=(const Cola_p &c);

	/**
	  @brief Comprueba si la cola esta vacia
	  @return true si la el nº de elementos es mayor que cero, false en otro caso
	*/
        inline bool empty()const {return(num_elem==0);};

	/**
	  @brief Elimina todos los elementos de la cola
	*/
	void clear();
	
	/**
	  @brief Devuelve el primer elemento de la cola
	  @return Primer elemento de la cola
	*/
	Pieza& front()const;

	/**
	  @brief Inserta un elemento al final de la cola
	*/
	void push(const Pieza &p);
	
	/**
	  @brief Devuelve el tamaño de la cola
	  @return Tamaño de la cola
	*/
        inline int size()const {return num_elem;};

	/**
	  @brief Elimina el primer elemento de la cola
	*/
	void pop();

	private:
	/**
	  @brief Devuelve la pieza de la posicion n
	  @param n posicion de la pieza
	  @return pieza situada en la posicion n
	  @pre n>0
	*/
	Pieza GetPieza(int n)const;
	friend class Vis_cola;	
	lista_nodo * cab;
	int num_elem;
};
#endif
