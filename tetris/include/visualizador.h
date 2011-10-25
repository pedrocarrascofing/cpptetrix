#ifndef __VISUALIZADOR_H__
#define __VISUALIZADOR_H__

#include "color.h"
#include "graficos.h"
#include "imagen.h"

class Visualizador{
	public:
	/**
	   @brief Constructor por defecto
   	*/
	Visualizador();

	/**
	   @brief Constructor de copia
   	*/
	Visualizador(const Visualizador &v1);

	/**
	   @brief Constructor con parametros
	   @param ancho ancho del nuevo visualizador
	   @param alto alto del nuevo visualizador

	   Crea un visualizador de tamaño ancho, alto
   	*/
	Visualizador(int ancho, int alto);

	/**
	   @brief Destructor
   	*/
	~Visualizador();

	/**
	   @brief Cambia el color de fondo
	   @param c nuevo color del fondo
   	*/
	void SetColorFondo(const Color c);

	/**
	   @brief Cambia el color del borde
	   @param c nuevo color del borde
   	*/
	void SetColorBorde(const Color c);


	/**
	   @brief Cambia la posicion en la ventana del visualizador
	   @param x posicion en el eje x de la ventana
	   @param y posicion en el eje y de la ventana

	   Cambia las coordenadas del visualizador en la ventana
   	*/
	void SetPosicion(int x, int y);

	/**
	   @brief Cambia las dimensiones del visualizador
	   @param ancho nueva dimension del visualizador
	   @param alto nueva dimension del visualizador
   	*/
	void SetDimensiones(int ancho, int alto);

	/**
	   @brief Cambia el grosor del borde
	   @pram borde nuevo grosor de borde
   	*/
	void SetGBorde(int borde);

	/**
	   @brief Devuelve la dimension en el eje x del visualizador
	   @return alto del visualizador
   	*/	
	int GetAlto()const;

	/**
	   @brief Devuelve la dimension en el eje y del visualizador
	   @return ancho del visualizador
   	*/	
	int GetAncho()const;
	
	/**
	   @brief Operador de asignacion
   	*/	
	Visualizador& operator=(const Visualizador &v1);
	
	/**
	   @brief Imprime en pantalla el visualizador
   	*/	
	void Mostrar()const;

	/**
	   @brief Imprime en pantalla el fondo del visualizador
   	*/	
	void ActualizarFondo()const;
	
	private:

	friend class Vis_cola;
	friend class Vis_txt;
	friend class Vis_tablero;

	Color c_fondo;
	Color c_borde;
	unsigned int x, y, g_borde, ancho, alto;

};





#endif
