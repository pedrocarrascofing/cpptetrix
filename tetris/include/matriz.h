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
	int FilasMatriz ()const;

	/**
	  @brief Devuelve el numero de columnas de la matriz
	  @return nº de columnas de la matriz
	*/
	int ColumnasMatriz ()const;  

	/**
	  @brief Devuelve un elemento de la matriz
	  @param fil fila en la que se encuentra el elemento
	  @param col columna en la que se encuentr el elemento
	  @return elemento situado en la fila fil, columna col
	  @pre fil>0 y col>0

	  Devuelve el elemento situado en la fila fil, columna col
	*/
	int GetMatriz (int fil, int col)const;

	/**
	  @brief Cambia un elemento de la matriz
	  @param fil fila del elemento a modificar
	  @param col columna del elemento a modificar
	  @param v nuevo elemento 
	  @pre fil>0, col>0

	  Modifica el elemento situado en la fila fil, columna col
	*/
	void SetMatriz(int fil, int col, int v);        	


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
