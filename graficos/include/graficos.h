/**
  * @file graficos.h
  * @brief Fichero cabecera para la gestión simplificada de gráficos
  *
  * Ofrece una interfaz simple para crear una ventana y dibujar en ella
  * así como el uso básico de E/S y bitmaps
  *
  */


/* ***************************************** */

#ifndef __GRAFICOS__H__
#define __GRAFICOS__H__

/* ***************************************** */

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>


/** 
  * @brief Contiene todos los tipos y funciones para la biblioteca @e graficos
  */
namespace graficos {

/** 
  * @brief Tipo de dato para almacenar imágenes (Bitmaps)
  *
  * Las imágenes se manejarán con un puntero no nulo. En caso de que el valor 
  * sea 0, se asumirá la imagen correspondiente a la ventana.
  */
typedef SDL_Surface* GRF_Imagen;

/**
  * @brief Tipo de evento recibido
  *
  * Al solicitar una entrada sin especificar el dispositivo, estos valores indicarán
  * a cuál de ellos corresponde.
  */
enum TEventoEntrada {
      GRF_RATON=1,  /**< Indica que la entrada corresponde al ratón */
      GRF_TECLADO=2 /**< Indica que la entrada corresponde al teclado */
};

/**
  * @brief Botones del ratón
  *
  * Cuando hay que indicar un botón del ratón, usaremos este nuevo tipo, para el que
  * consideraremos los siguientes valores:
  *
  * -# SDL_BUTTON_LEFT: Botón izquierdo.
  * -# SDL_BUTTON_MIDDLE: Botón central.
  * -# SDL_BUTTON_RIGHT: Botón Derecho.
  */
typedef Uint8 TBotonRaton;

/**
  * @brief Teclas
  *
  * Cuando hay que indicar una tecla, usaremos este nuevo tipo, para el que
  * consideraremos los valores que puede consultar en la documentación de la SDL, o
  * directamente en la sección @ref refcodigoteclas. Algunos ejemplos son:
  *
  * -# SDLK_q: Tecla q
  * -# SDLK_w: Tecla w
  * -# SDLK_DOWN: Tecla flecha abajo.
  * -# etc...
  */
typedef SDLKey TTecla;


/**
  * @brief Tipo de dato para almacenar tipografías
  *
  * Nos permite disponer de distintos tipos de fuentes TTF de manera que el texto dibujado en
  * pantalla pueda tener distintas apariencias.
  */
typedef TTF_Font* GRF_Fuente;


/**
  * @brief Estilos de fuentes
  *
  * Al cargar una fuente le asociamos el estilo con el que deseamos que aparezca.
  * Consideraremos los siguientes valores:
  *
  * -# TTF_STYLE_NORMAL: Estilo normal.
  * -# TTF_STYLE_BOLD: Estilo negrita.
  * -# TTF_STYLE_ITALIC: Estilo itálica.
  */
typedef int TEstiloFuente;


/* ***************************************** */
/* ***************************************** */
/* ***************************************** */




/**
  * @brief Inicializar la biblioteca SDL y crear/abrir una ventana
  * @param ancho Número de columnas (en píxeles) de la ventana a crear.
  * @param alto Número de filas (en píxeles) de la ventana a crear.
  * @param titulo Cadena con el título de la ventana a crear.
  * @pre  @a ancho y @a alto deben ser positivos.
  */
void CrearVentana(int ancho, int alto, const char *titulo);

/**
  * @brief Alto de la ventana
  * @return El alto de la ventana creada, en píxeles.
  * @pre Se debe haber creado una ventana previamente con CrearVentana
  */
int AltoVentana();

/**
  * @brief Ancho de la ventana
  * @return El ancho de la ventana creada, en píxeles.
  * @pre Se debe haber creado una ventana previamente con CrearVentana
  */
int AnchoVentana();


/**
  * @brief Borra (pone negro) el contenido de la ventana
  * @pre Se debe haber creado una ventana previamente con CrearVentana
  */
void LimpiarVentana();

/**
  * @brief Activa la actualización del dibujo
  * @post Se actualiza el contenido de la ventana. Además, las funciones de dibujo 
  * actualizarán el contenido de la ventana inmediatamente después de dibujar.
  * @see DesactivarDibujo
  * @see Sección @ref refactivadesactiva
  */

void ActivarDibujo();
/**
  * @brief Desactiva la actualización del dibujo
  * @post Las funciones de dibujo no actualizarán el contenido de la ventana mientras que
  * esté desactivado el dibujo.
  * @see ActivarDibujo
  * @see Sección @ref refactivadesactiva
  */
void DesactivarDibujo();


//-----------------------------------------------------------------------------
/* ***************************************** */
/* *********  Funciones de Imágenes  ******* */
/* ***************************************** */
//-----------------------------------------------------------------------------


/**
  * @brief Crea una imagen (bitmap)
  * @param ancho Número de columnas (en píxeles) de la imagen a crear.
  * @param alto Número de filas (en píxeles) de la imagen a crear.
  * @pre  @a ancho y @a alto deben ser positivos.
  * @see LiberarImagen
  */
GRF_Imagen CrearImagen(int ancho, int alto);


/**
  * @brief Crea una copia de una imagen (bitmap)
  * @param orig Imagen original que deseamos copiar.
  * @return Una nueva copia de la imagen orig.
  * @post La nueva imagen también deberá ser liberada con LiberarImagen
  * @see LiberarImagen
  */
GRF_Imagen ObtenerCopiaImagen(GRF_Imagen orig);


/**
  * @brief Consulta del alto de la imagen
  * @param img Imagen sobre la que deseamos consultar.
  * @return  Las filas (alto) de la imagen en píxeles

  */
int AltoImagen(GRF_Imagen img);


/**
  * @brief Consulta del ancho de la imagen
  * @param img Imagen sobre la que deseamos consultar. 
  * @return  Las columnas (ancho) de la imagen en píxeles
  */
int AnchoImagen(GRF_Imagen img);

/**
  * @brief Limpia el contenido de una imagen
  * @param img Imagen limpiar. Debe haber sido previamente creada.
  * @post El contenido de @ img se modifica para que todos sus puntos tengan el
  *       color negro (0,0,0)
  */
void LimpiarImagen(GRF_Imagen img);


/**
  * @brief Cargar desde un fichero en disco una imagen BMP
  * @param fich nombre del archivo con la imagen
  * @return Un puntero a la imagen cargada, 0 si no es posible cargarla. 
  *         Si ocurre un error, se describe el problema en la salida estándar de error
  * @post Si se realiza la lectura con éxito, la imagen deberá finalmente ser liberada con
  *       LiberarImagen
  * @see LiberarImagen, DimensionesImagenFichero
  */
GRF_Imagen LeerImagen(const char *fich);



/**
  * @brief Salva una imagen a fichero BMP en disco
  * @param fich nombre del archivo donde salvar la imagen
  * @param img imagen a salvar
  * @return Si ha tenido éxito.
  */
bool GrabarImagen(const char *fich, GRF_Imagen img);


/**
  * @brief Liberar la memoria ocupada por una imagen BMP
  * @param img puntero a la imagen previamente cargada
  * @pre La imagen ha sido previamente creada
  * @see CrearImagen, ObtenerCopiaImagen, LeerImagen
  */
void LiberarImagen(GRF_Imagen img);


/**
  * @brief Obtener las dimensiones (filas y columnas) de una imagen que 
           está almacenada en un fichero
  * @param fich cadena que contiene el nombre del fichero
  * @param ancho tamaño en columnas de la imagen
  * @param alto tamaño en filas de la imagen
  * @post Si el fichero no se puede leer, las dimensiones serán cero
  * @return Si ha tenido éxito.
  * @see LeerImagen
  */
bool DimensionesImagenFichero(const char *fich, int& ancho, int& alto);


/**
  * @brief Dibuja en la ventana gráfica, a partir de las coordenadas (@a x, @a y), 
           la imagen almacenada en @a img
  * @param img puntero a la imagen que dibujar
  * @param x coordenada horizontal (columna) a partir de la cual pintar la imagen @a img
  * @param y coordenada vertical (fila) a partir de la cual pintar la imagen  @a img
  * @param imgdest indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre imgdest debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre La imagen debe caber completa en el área delimitada por el destino
  */
void DibujarImagen(GRF_Imagen img, int x, int y, GRF_Imagen imgdest=0);


//-----------------------------------------------------------------------------
/* ***************************************** */
/* *********  Funciones de dibujo  ********* */
/* ***************************************** */
//-----------------------------------------------------------------------------

/**
  * @brief Dibuja un punto de color (@a r, @a g, @a b) en (@a x, @a y)
  * @param x columna del punto
  * @param y fila del punto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre 0<= @a x < columnas del destino && 0<= @a y < filas del destino
  * @see ObtenerPunto
  */
void Punto(int x, int y, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja una línea desde (@a x1,@a y1) a (@a x2,@a y2) de color (@a r, @a g, @a b)
  * @param x1 columna del primer punto
  * @param y1 fila del primer punto
  * @param x2 columna del segundo punto
  * @param y2 fila del segundo punto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre Los puntos (@a x1,@a y1) (@a x2,@a y2) están dentro del destino
  */
void Linea(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja una circunferencia centrada en (@a x,@a y) con radio @a rad de color (@a r, @a g, @a b)
  * @param x columna del punto centro de la circunferencia
  * @param y fila del punto centro de la circunferencia
  * @param rad radio de la circunferencia
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre Los puntos que dibujan la circunferencia están dentro del destino
  * @see CirculoR
  */
void Circulo(int x, int y, int rad, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja un rectángulo definido por las esquinas (@a x1,@a y1) a (@a x2,@a y2) de color (@a r, @a g, @a b)
  * @param x1 columna del primer punto
  * @param y1 fila del primer punto
  * @param x2 columna del segundo punto
  * @param y2 fila del segundo punto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre Los puntos (@a x1,@a y1) (@a x2,@a y2) están dentro del destino
  * @see RectanguloR
  */
void Rectangulo(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja una elipse centrada en (@a x,@a y) con radios @a radx y @a rady de color (@a r, @a g, @a b)
  * @param x columna del punto centro de la elipse
  * @param y fila del punto centro de la elipse
  * @param radx radio horizontal de la elipse
  * @param rady radio vertical de la elipse
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre Los puntos que dibujan la elipse están dentro del destino
  * @see ElipseR
  */
void Elipse(int x, int y, int radx, int rady, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja un rectángulo relleno
  * @param x1 columna del primer punto
  * @param y1 fila del primer punto
  * @param x2 columna del segundo punto
  * @param y2 fila del segundo punto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, 
         o que apunte a una imagen creada.
  * @pre Los puntos (@a x1,@a y1) (@a x2,@a y2) están dentro del destino
  * @see Rectangulo
  */
void RectanguloR(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja un círculo relleno
  * @param x columna del punto centro de la circunferencia
  * @param y fila del punto centro de la circunferencia
  * @param rad radio de la circunferencia
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre Los puntos que dibujan la circunferencia están dentro del destino
  * @see Circulo
  */
void CirculoR(int x, int y, int rad, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Dibuja una elipse rellena
  * @param x columna del punto centro de la elipse
  * @param y fila del punto centro de la elipse
  * @param radx radio horizontal de la elipse
  * @param rady radio vertical de la elipse
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre Los puntos que dibujan la elipse están dentro del destino
  * @see ElipseR
  */
void ElipseR(int x, int y, int radx, int rady, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);


/**
  * @brief Escribe un texto en la ventana
  * @param x columna donde se sitúa la esquina superior izquierda del bloque donde se dibuja el texto
  * @param y fila donde se sitúa la esquina superior izquierda del bloque donde se dibuja el texto
  * @param c texto a escribir
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre Los puntos que dibujan el texto están dentro del destino
  * @post El texto se dibuja en el rectángulo de alto 8 y ancho longitud(c)*8 y con esquina
          superior izquierda situada en (@a x,@a y)
  */
void Texto(int x, int y, const char *c,  unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img=0);

//-----------------------------------------------------------------------------
/* ******************************************* */
/* *********  Funciones de Consulta  ********* */
/* ******************************************* */
//-----------------------------------------------------------------------------


/**
  * @brief Obtiene el color del pixel de la posición (@a x, @a y) en (@a r, @a g, @a b)
  * @param x columna del punto
  * @param y fila del punto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param img indica la imagen que consultar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre 0<= @a x < Columnas del destino && 0<= @a y < Filas del destino
  * @post El color del punto  (@a x,@a y) de img se obtiene en  (@a r, @a g, @a b)
  * @see Punto
  */
void ObtenerPunto(int x, int y, unsigned char &r, unsigned char &g, unsigned char &b, GRF_Imagen img=0);



/**
  * @brief Espera hasta que se pulsa uno de los botones del ratón en la ventana
  * @param x coordenada horizontal (columna) del ratón en el momento de la pulsación
  * @param y coordenada vertical (fila) del ratón en el momento de la pulsación
  * @return uel botón pulsado
  * @post Las coordenadas del ratón en el momento de la pulsación se obtienen en (@a x, @a y)
  * @see TBotonRaton
  */
TBotonRaton ObtenerClick(int &x, int &y);


/**
  * @brief Espera hasta que se pulsa una tecla
  * @return un entero que codifica la tecla que se ha pulsado
  * @see TTecla
  */
TTecla ObtenerTecla();


/**
  * @brief Espera hasta que se pulsa una tecla o el raton
  * @param pulsa código de la tecla que ha sido pulsada (si devuelve GRF_TECLADO)
  * @param boton código del botón que se ha pulsado (si devuelve GRF_RATON)
  * @param x coordenada horizontal (columna) del ratón en el momento de la pulsación
           (si devuelve GRF_RATON)
  * @param y coordenada vertical (fila) del ratón en el momento de la pulsación
           (si devuelve GRF_RATON)
  * @return el tipo de evento que ha producido la entrada  (RATON o TECLADO)
  * @see TBotonRaton, TTecla, TEventoEntrada
  */
TEventoEntrada ObtenerEntrada(TTecla &pulsa, TBotonRaton& boton, int &x, int &y);

/**
  * @brief Consulta, y si hay una tecla pulsada, devuelve su código
  * @return Un valor que codifica la tecla que se ha pulsado. En caso de que no haya ninguna
    tecla pulsada, devuelve SDLK_UNKNOWN.
  * @note Observe que esta función no detiene la ejecución en espera de que se pulse una tecla.
  * @see TTecla
  */
TTecla QueTeclaHayPulsada();


//-----------------------------------------------------------------------------
/* ******************************************* */
/* *********  Funciones de Tiempo  *********** */
/* ******************************************* */
//-----------------------------------------------------------------------------


/**
  * @brief Espera durante un instante de tiempo
  * @param ms número de milisegundos a esperar
  */
void Esperar(int ms);


/**
  * @brief Pone el cronómetro a cero
  * @see CronometroValor
  */
void CronometroInicio();

/**
  * @brief Valor del cronómetro
  * @return El valor del cronómetro en milisegundos
  * @see CronometroInicio
  */
long int CronometroValor();

//-----------------------------------------------------------------------------
/* ********************************************** */
/* *********  Gestión de Fuentes TTF  *********** */
/* ********************************************** */
//-----------------------------------------------------------------------------

/**
  * @brief Carga una fuente ttf
  * @param fichero Nombre del archivo que contiene la fuente ttf
  * @param tamano Tamaño que se establece en la fuente cargada
  * @param estilo Estilo que se establece para la fuente cargada
  * @return La fuente que se ha cargado, 0 en caso de que no haya sido posible.
  * @see TEstiloFuente
  */
GRF_Fuente CargarFuente(const char *fichero, int tamano, TEstiloFuente estilo=TTF_STYLE_NORMAL);


/**
  * @brief Libera una fuente previamente cargada
  * @param fuente Puntero que indica la fuente cargada
  * @pre La fuente se ha cargado previamente
  */
void LiberarFuente(GRF_Fuente fuente);

/**
  * @brief Escribir texto ttf
  * @param x columna donde se sitúa la esquina superior izquierda del bloque donde se dibuja el texto
  * @param y fila donde se sitúa la esquina superior izquierda del bloque donde se dibuja el texto
  * @param cadena texto a escribir
  * @param fuente La fuente que se usará para crear el texto
  * @param r componente rojo del color
  * @param g componente verde del color
  * @param b componente azul del color
  * @param imgdest indica la imagen donde pintar. Si vale cero, se asume la ventana.
  * @pre img debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0,
         o que apunte a una imagen creada.
  * @pre El texto a dibujar debe estar dentro del destino. 
  * @see TamanoTexto
*/
void EscribirTexto(int x, int y, const char *cadena, GRF_Fuente fuente,
                   unsigned char r, unsigned char g, unsigned char b, GRF_Imagen imgdest=0);


/**
  * @brief Altura de una fuente ttf
  * @param fuente Fuente a la que calcular la altura máxima
  * @return La altura máxima posible que puede alcanzar un texto de la fuente
  * @pre La fuente se ha cargado previamente
  */
int AltoFuente(GRF_Fuente fuente);

/**
  * @brief Calcula el tamaño de un texto
  * @param fuente La fuente que se usará para crear el texto
  * @param mensaje El texto al que se quiere consultar las dimensiones.
  * @param ancho El ancho (columnas) que ocupa el texto
  * @param alto El alto (filas) que ocupa el texto
  * @note Observe que un texto se dibujará en un rectángulo de tamaño @a ancho x @a alto
*/
void TamanoTexto(GRF_Fuente fuente, const char *mensaje, int &ancho, int &alto);


};

#endif

