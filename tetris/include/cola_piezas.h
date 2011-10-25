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
	bool empty()const;

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
	int size()const;

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
