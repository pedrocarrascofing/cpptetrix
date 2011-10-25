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
