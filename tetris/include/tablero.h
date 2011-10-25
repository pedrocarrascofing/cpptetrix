#ifndef __TABLERO_H__
#define __TABLERO_H__
#include "pieza.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


class Tablero
{
public:
	
	/**
	  @brief Constructor por defecto
	*/
	Tablero();
	
	/**
	  @brief Constructor de copia
	*/
	Tablero(const Tablero &t);

	/**
	  @brief Constructor con parametros
	  @param m Matriz con la que se creara el tablero
	
	  Crea un tablero con la matriz, la posicion en el eje x de la pieza queda centrada en el tablero
	*/
	Tablero(const Matriz &m);	

	/**
	  @brief Constructor con parametros
	  @param m Matriz con la que se creara el tablero
	  @param p Pieza con la que se creara el tablero
	  @param a Posicion en el eje x de la pieza en el tablero
	  @param b Posicion en el eje y de la pieza en el tablero
	*/
	Tablero(const Matriz &m, const Pieza &p, int a, int b);

	/**
	  @brief Constructor con parametros
	  @param m Matriz con la que se creara el tablero
	  @param p Pieza con la que se creara el tablero
	  

	  La pieza queda centrada en el eje x en el tablero
	*/
	Tablero(const Matriz &m, const Pieza &p);
	
	/**
	  @brief Destructor
	*/
	~Tablero(){};
	
	/**
	  @brief Operador asignacion
	*/
	Tablero &operator=(const Tablero &t);
		

	/**
	  @brief Devuelve el tamaño en el eje x del tablero
	  @return Ancho del tablero
	*/
	int Ancho()const;

	/**
	  @brief Devuelve el tamaño en el eje y del tablero
	  @return Altura del tablero
	*/
	int Alto()const;


	/**
	  @brief Devuelve la posicion en el eje x de la pieza
	  @return Posicion de la pieza pieza en el tablero
	*/
	int PosXPieza()const;

	/**
	  @brief Devuelve la posicion en el eje y de la pieza
	  @return Posicion de la pieza pieza en el tablero
	*/
	int PosYPieza()const;	

	/**
	  @brief Devuelve un elemento del tablero
	  @param posx posicion en el eje x 
	  @param posy posicion en el eje y
	  @return Elemento situado en posx, posy

	  Devuelve el elemnto de la posicion posx, posy del tablero
	*/
	int GetTabElem(int posx, int posy)const;
	
	/**
	  @brief Devuelve la pieza del tablero
	  @return Pieza del tablero
	*/
	Pieza GetPieza()const;

	/**
	  @brief Devuelve un elemento de la pieza
	  @param posx posicion en el eje x 
	  @param posy posicion en el eje y
	  @return Elemento situado en posx, posy

	  Devuelve el elemnto de la posicion posx, posy de la pieza
	*/
	int GetPiezaElem(int posx, int posy)const;

	/**
	  @brief Devuelve el tamaño en el eje x de la pieza
	  @return Ancho de la pieza
	*/
	int AnchoPieza()const;
	
	/**
	  @brief Devuelve el tamaño en el eje y de la pieza
	  @return Alto de la pieza
	*/
	int AltoPieza()const;
		
	
	
	/**
	  @brief Comprueba si es posible girar la pieza a la derecha
	  @return true si es posible girar la pieza a la derecha, false en otro caso

	  Comprueba si es posible realizar el giro de la pieza a la derecha en el tablero
	*/
	bool CompGiroRight()const;	

	/**
	  @brief Comprueba si es posible girar la pieza a la izquierda
	  @return true si es posible girar la pieza a la izquierda, false en otro caso

	  Comprueba si es posible realizar el giro de la pieza a la izquierda en el tablero
	*/
	bool CompGiroLeft()const;	


	/**
	  @brief Comprueba si es posible mover la pieza a la derecha
	  @return true si es posible mover la pieza a la derecha, false en otro caso

	  Comprueba si es posible mover la pieza a la derecha en el tablero
	*/
	bool CompMovRight()const;

	/**
	  @brief Comprueba si es posible mover la pieza a la izquierda
	  @return true si es posible mover la pieza a la izquierda, false en otro caso

	  Comprueba si es posible mover la pieza a la izquierda en el tablero
	*/
	bool CompMovLeft()const;

	/**
	  @brief Comprueba si es posible mover la pieza hacia abajo
	  @return true si es posible mover la pieza hacia abajo, false en otro caso

	  Comprueba si es posible mover la pieza hacia abajo en el tablero
	*/
	bool CompMovDown()const;

	/**
	  @brief Comprueba si es posible mover la pieza hacia arriba
	  @return true si es posible mover la pieza hacia arriba, false en otro caso

	  Comprueba si es posible mover la pieza hacia arriba en el tablero
	*/
	bool CompMovUp()const;

	/**
	  @brief Comprueba una linea está completa
	  @param n linea a comprobar
	  @return false si algun elemento de la linea es igual a cero, true en otro caso
	*/
	bool LineaCompleta(int n)const;

	/**
	  @brief Comprueba si hay algun elemento en la primera fila del tablero
	  @return true si hay algun elemento en la primera fila del tablero, false en otro caso
	*/
	bool FinJuego()const;


	/**
	  @brief Gira la pieza a la derecha si es posible
	  @return true si se ha realizado el giro, false en otro caso

	  Gira la pieza a la derecha si es posible, devuelve true si se ha realizado el giro
	*/
	bool GirarDer();


	/**
	  @brief Gira la pieza a la izquierda si es posible
	  @return true si se ha realizado el giro, false en otro caso

	  Gira la pieza a la izquierda si es posible, devuelve true si se ha realizado el giro
	*/
	bool GirarIz();	

	/**
	  @brief Muevle la pieza a la derecha si es posible
	  @return true si se ha realizado el movimiento, false en otro caso

	  Mueve la pieza a la derecha si es posible, devuelve true si se ha realizado el movimiento
	*/
	bool MovRight();

	/**
	  @brief Muevle la pieza a la izquierda si es posible
	  @return true si se ha realizado el movimiento, false en otro caso

	  Mueve la pieza a la izquierda si es posible, devuelve true si se ha realizado el movimiento
	*/
	bool MovLeft();


	/**
	  @brief Muevle la pieza hacia arriba si es posible
	  @return true si se ha realizado el movimiento, false en otro caso

	  Mueve la pieza hacia arriba si es posible, devuelve true si se ha realizado el movimiento
	*/
	bool MovDown();


	/**
	  @brief Muevle la pieza hacia abajo si es posible
	  @return true si se ha realizado el movimiento, false en otro caso

	  Mueve la pieza hacia abajo si es posible, devuelve true si se ha realizado el movimiento
	*/
	bool MovUp();

	/**
	  @brief Introduce una linea aleatoria en el tablero en la ultima fila
	  @param n rango de valores, entr 0 y max-1

	  Introduce en el tablero una linea aleatoria cuyos valores pueden estar entre 0 ó max-1
	*/
	void LineaAleatoria(int max);

	/**
	  @brief Pone todos los elementos del tablero a cero
	*/
	void InicializaTablero();

	/**
	  @brief Suprime una linea
	  @param n linea a eliminar

	  Desplaza todo el contenido del tablero quedando la linea n eliminada
	*/	
	void SuprLinea(int n);

	/**
	  @brief Elimina todas las lineas completas
	  @return n de lineas eliminadas
	*/
	int Barrido();


	/**
	  @brief Deja fija la pieza en el tablero
	*/
	void Apilar();

	/**
	  @brief Cambia la pieza
	  @param p nueva pieza

	  Cambia la pieza y la posicion de la anterior
	*/
	void ResetPieza(const Pieza &p);

	/**
	  @brief Pone todos los elementos del tablero a cero
	*/
	void ResetTablero();

	/**
	  @brief Cambia la pieza
	  @param p nueva pieza

	  Cambia la pieza, se conserva la posicion anterior
	*/
	void SetPieza(const Pieza &p1);

	/**
	  @brief Cambia posicion de la pieza
	  @param x nueva posicion en el eje x de la pieza en el tablero
	  @param y nueva posicion en el eje y de la pieza en el tablero
	*/
	void SetPosPieza(int x, int y);


private:
	Pieza pz;
	Matriz tab;
	unsigned int x, y;
		
};

#endif	
