#ifndef __PIEZA_H__
#define __PIEZA_H__
#include"matriz.h"


class Pieza
{
	public:
	/**
	  @biref Constructor por defecto
	*/	
	Pieza();

	/**
	  @biref Constructor de copia
	*/		
	Pieza(const Pieza &p);

	/**
	  @biref Constructor con parametros
	  @param m Matriz con la que construir la pieza
	*/		
	Pieza(const Matriz &m);

	/**
	  @biref Constructor con parametros
	  @param fil tamaño en el eje y con el que se creara la pieza
	  @param col tamaño en el eje x con el que se creara la pieza
	  @pre fil>0, col>0
	*/		
	Pieza(int fil, int col);

	/**
	  @brief Operador de asignacion
	*/
	Pieza& operator=(const Pieza &p);

	/**
	  @brief Destructor
	*/
	~Pieza(){};
		
	/**
	  @brief Modifica un elemnto de la pieza
	  @param i posicion en el eje y del elemento a cambiar
	  @param j posicion en el eje x del elemento a cambiar
	  @param n nuevo elemento
	  @pre i>0, j>0
	  
	  Modifica el element de la pieza situado en la posicion i, j 
	*/
        inline void SetPieza(int i, int j, int n){pza.SetMatriz(i, j, n);};
	
	/**
	  @brief Devuelve el elemnto situado en la posicion i, j
	  @param i posicion en el eje y del elemento
	  @param j posicion en el eje x del elemento
	  @return elemento situado en la posicion i, j
	  @pre i>0, j>0
	*/
        inline int GetPieza(int i, int j)const{return pza.GetMatriz(i, j);};
		
	/**
	  @brief Devuelve el tamaño en el eje y de la pieza
	  @return Alto de la pieza 
	*/
        inline int Alto()const{return (pza.FilasMatriz());};

	/**
	  @brief Devuelve el tamaño en el eje x de la pieza
	  @return Ancho de la pieza 
	*/
        int Ancho()const {return (pza.ColumnasMatriz());};

	/**
	  @brief Gira la pieza a la derecha

	  La pieza es modificada
	*/
	void GiroDer();

	/**
	  @brief Gira la pieza a la izquierda

	  La pieza es modificada
	*/
	void GiroIz();

	private:
	Matriz pza;
};
#endif
