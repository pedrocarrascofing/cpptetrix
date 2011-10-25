/*
Copyright 2011 Jose Luis Robles Urquiza


This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>

*/
#ifndef __MATRIZ_H__
#define __MATRIZ_H__

class Matriz
{	
   public:
   	/**
   	  @brief Constructor por defecto
   	*/
   	Matriz ();

	/**
	  @brief Constructor de copia
	*/
	Matriz(const Matriz &M);

	/**
	  @brief Constructor con parametros
	  @param f numero de filas
	  @param c numero de columnas
	  @pre c > 0, f>0
	  
	  Crea una matriz con f filas y c columnas
	*/
	Matriz(int f, int c);	

	/**
     	  @brief Destructor
	*/
	~Matriz ();  

	/**
	  @brief operador de asignacion
	*/
	Matriz &operator=(const Matriz &M);

	/**
	  @brief Devuelve el numero de filas de la matriz
	  @return nº de filas de la matriz
	*/
        inline int FilasMatriz()const {return fil;};

	/**
	  @brief Devuelve el numero de columnas de la matriz
	  @return nº de columnas de la matriz
	*/
        inline int ColumnasMatriz()const {return col;};

	/**
	  @brief Devuelve un elemento de la matriz
	  @param fil fila en la que se encuentra el elemento
	  @param col columna en la que se encuentr el elemento
	  @return elemento situado en la fila fil, columna col
	  @pre fil>0 y col>0

	  Devuelve el elemento situado en la fila fil, columna col
	*/
        inline int GetMatriz (int fil, int col)const {return mat[fil][col];};

	/**
	  @brief Cambia un elemento de la matriz
	  @param fil fila del elemento a modificar
	  @param col columna del elemento a modificar
	  @param v nuevo elemento 
	  @pre fil>0, col>0

	  Modifica el elemento situado en la fila fil, columna col
	*/
        inline void SetMatriz(int fil, int col, int v){mat[fil][col]=v;};


	/**
	  @brief Realiza la matriz traspuesta
	  @return Matriz traspuesta de la original

	  Devuelve la matriz traspuesta
	*/
	Matriz Traspuesta()const;

	/**
	  @brief Traspone las filas de una matriz
	  @return Matriz con filas traspuesta

	  Devuelve una matriz con las filas traspuestas
	*/
	Matriz TrasFil()const;

	/**
	  @brief Traspone las columnas de una matriz
	  @return Matriz con columnas traspuesta

	  Devuelve una matriz con las columnas traspuestas
	*/
	Matriz TrasCol()const;

	private:
	int **mat;
	int fil, col;
};
#endif
