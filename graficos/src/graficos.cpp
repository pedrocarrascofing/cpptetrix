/**
  * @file graficos.cpp
  * @brief Fichero con definiciones para la gestión simplificada de gráficos
  *
  * Implementa la interfaz de graficos.h
  *
  */

/* ***************************************** */
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "graficos.h"

/* ***************************************** */

using namespace std;

namespace graficos {

//-----------------------------------------------------------------------------
// Variables y funciones privadas del módulo

namespace { // namespace anónimo
	// Variable que representa la pantalla (ventana) donde vamos a dibujar
	static GRF_Imagen ventana;
	
	// Variable que controla si la pantalla se refresca tras cada dibujo o no
	static bool dibujo_activo;
	
	// Variable para control de cronómetro
	static long int cronometro;
	
	// Función privada del módulo
	
	static void Finalizar_SDL()
	{
	  TTF_Quit(); // Seguro que fué inicializada
	  SDL_Quit();
	}
}

//-----------------------------------------------------------------------------
/* ***************************************** */
/* *********  Funciones de Ventana  ******** */
/* ***************************************** */
//-----------------------------------------------------------------------------


void CrearVentana(int ancho, int alto, const char *titulo)
{
    // Ponemos el modo de video:
    // Dimensiones de la ventana: filas x columnas
    // Profundidad de color: número de bits para representar el color de un pixel
    ventana=SDL_SetVideoMode(ancho,alto,32,SDL_SWSURFACE|SDL_ANYFORMAT);
    if (ventana==0) {
        cerr << "No se puede iniciar el modo gráfico seleccionado ("
             << SDL_GetError() << ")" << endl;
        SDL_Quit();
        exit(-1);
    }

    // Ponemos el título de la ventana
    SDL_WM_SetCaption(titulo,0);

    // Por defecto, cada operación refresca la pantalla tras dibujar
    dibujo_activo = true;
}

/* ***************************************** */

int AltoVentana()
{ return AltoImagen(ventana); };

/* ***************************************** */

int AnchoVentana()
{ return AnchoImagen(ventana); };

/* ***************************************** */

void LimpiarVentana() 
{ LimpiarImagen(ventana); };

/* ***************************************** */

void ActivarDibujo()
{
    dibujo_activo = true;
    SDL_UpdateRect(ventana,0,0,0,0);
}

/* ***************************************** */

void DesactivarDibujo()
{
    dibujo_activo = false;
}

//-----------------------------------------------------------------------------
/* ***************************************** */
/* *********  Funciones de Imágenes  ******* */
/* ***************************************** */
//-----------------------------------------------------------------------------

GRF_Imagen CrearImagen(int ancho, int alto)
{
    return SDL_CreateRGBSurface(SDL_SWSURFACE,ancho,alto,32,0,0,0,0);
}

/* ***************************************** */

GRF_Imagen ObtenerCopiaImagen(GRF_Imagen orig)
{
    GRF_Imagen p;
    if (orig==0)
      p=0;
    else {
      p = SDL_CreateRGBSurface(SDL_SWSURFACE,orig->w,orig->h,32,0,0,0,0);
      SDL_BlitSurface(const_cast<GRF_Imagen>(orig),0,p,0);
    }
    return p;
}

/* ***************************************** */

void LimpiarImagen(GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    int i;
    /* Poner la imagen en negro */
    if ( SDL_LockSurface(ptr) == 0 ) {
        Uint32 black;
        Uint8 *pixels;
        black = SDL_MapRGB(ptr->format, 0, 0, 0);
        pixels = (Uint8 *)ptr->pixels;
        for ( i=0; i<ptr->h; ++i ) {
            memset(pixels, black,ptr->w*ptr->format->BytesPerPixel);
            pixels += ptr->pitch;
        }
        SDL_UnlockSurface(ptr);
        if (dibujo_activo) SDL_UpdateRect(ptr, 0, 0, ptr->w, ptr->h);
    }
}

/* ***************************************** */

int AltoImagen(GRF_Imagen img)
{
    //GRF_Imagen ptr = ((img==0) ? ventana : img);
    if (img==0) return 0;
    return img->h;
}

/* ***************************************** */

int AnchoImagen(GRF_Imagen img)
{
    //GRF_Imagen ptr = ((img==0) ? ventana : img);
    if (img==0) return 0;
    return img->w;
}
/* ***************************************** */

GRF_Imagen LeerImagen(const char *fich)
{
    GRF_Imagen img;
    if (!(img=SDL_LoadBMP(fich))) {
        cerr << "No es posible cargar el fichero "<<fich<<endl;
        cerr << SDL_GetError() << endl;
        return 0;
    }
    return img;
}

bool GrabarImagen(const char *fich, GRF_Imagen img)
{
    //GRF_Imagen ptr = ((img==0) ? ventana : img);
    return !SDL_SaveBMP(img,fich);
}

/* ***************************************** */

void LiberarImagen(GRF_Imagen img)
{
    if (img)
        SDL_FreeSurface(img);
}

/* ***************************************** */

bool DimensionesImagenFichero(const char *fich, int& ancho, int& alto)
{
    GRF_Imagen img = LeerImagen(fich);
    ancho = alto = 0;
    if (img!=0) {
        ancho = img->w;
        alto = img->h;
        LiberarImagen(img);
    }
    return (img!=0);
}

/* ***************************************** */

void DibujarImagen(GRF_Imagen img, int x, int y, GRF_Imagen imgdest)
{
    GRF_Imagen ptr = ((imgdest==0) ? ventana : imgdest);
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = img->w;
    dest.h = img->h;
    //SDL_SetAlpha(img, SDL_SRCALPHA, SDL_ALPHA_OPAQUE);
    //SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 255, 255, 255));
    SDL_BlitSurface(img, NULL, ptr, &dest);
    if (imgdest==0 && dibujo_activo) SDL_UpdateRect(ptr, x, y, img->w, img->h);
}


//-----------------------------------------------------------------------------
/* ***************************************** */
/* *********  Funciones de dibujo  ********* */
/* ***************************************** */
//-----------------------------------------------------------------------------

void Punto(int x, int y, unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    pixelRGBA(ptr, x, y, r, g, b, 255);
    if (img==0 && dibujo_activo) SDL_UpdateRect(ptr, x, y, 1, 1);
}

/* ***************************************** */

void Linea(int x1, int y1, int x2, int y2,
           unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    lineRGBA(ptr, x1, y1, x2, y2, r, g, b, 255);
    if (img==0 && dibujo_activo) 
      SDL_UpdateRect(ptr, min(x1,x2), min(y1,y2), abs(x1-x2)+1, abs(y1-y2)+1);
}

/* ***************************************** */

void Circulo(int x, int y, int rad,
             unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    circleRGBA(ptr, x, y, rad, r, g, b,255);
    if (img==0 && dibujo_activo) SDL_UpdateRect(ptr, x-rad, y-rad, rad*2+1, rad*2+1);
}

/* ***************************************** */

void CirculoR(int x, int y, int rad,
              unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    filledCircleRGBA(ptr, x, y, rad, r, g, b,255);
    if (img==0 && dibujo_activo) SDL_UpdateRect(ptr, x-rad, y-rad, rad*2+1, rad*2+1);
}

/* ***************************************** */

void Rectangulo(int x1, int y1, int x2, int y2,
              unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    rectangleRGBA(ptr, x1, y1, x2, y2, r, g, b, 255);
    if (img==0 && dibujo_activo) 
      SDL_UpdateRect(ptr, min(x1,x2), min(y1,y2), abs(x1-x2)+1, abs(y1-y2)+1);
}

/* ***************************************** */

void RectanguloR(int x1, int y1, int x2, int y2,
              unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    boxRGBA(ptr, x1, y1, x2, y2, r, g, b, 255);
    if (img==0 && dibujo_activo) 
      SDL_UpdateRect(ptr, min(x1,x2), min(y1,y2), abs(x1-x2)+1, abs(y1-y2)+1);
}

/* ***************************************** */

void Elipse(int x, int y, int radx, int rady,
             unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    ellipseRGBA(ptr, x, y, radx, rady, r, g, b,255);
    if (img==0 && dibujo_activo) 
      SDL_UpdateRect(ptr, x-radx, y-rady, radx*2+1, rady*2+1);
}

/* ***************************************** */

void ElipseR(int x, int y, int radx, int rady,
             unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    filledEllipseRGBA(ptr, x, y, radx, rady, r, g, b,255);
    if (img==0 && dibujo_activo) SDL_UpdateRect(ptr, x-radx, y-rady, radx*2+1, rady*2+1);
}

/* ***************************************** */


void Texto(int x, int y, const char *c,
             unsigned char r, unsigned char g, unsigned char b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    stringRGBA(ptr, x, y, c, r, g, b, 255);
    if (img==0 && dibujo_activo) 
      SDL_UpdateRect(ptr, 0, 0, 0, 0);
}

/* ***************************************** */


//-----------------------------------------------------------------------------
/* ******************************************* */
/* *********  Funciones de Consulta  ********* */
/* ******************************************* */
//-----------------------------------------------------------------------------

void ObtenerPunto(int x, int y,
                  unsigned char &r, unsigned char &g, unsigned char &b, GRF_Imagen img)
{
    GRF_Imagen ptr = ((img==0) ? ventana : img);
    int bpp = ptr->format->BytesPerPixel;
    Uint8 *p = (Uint8*)ptr->pixels + y*ptr->pitch + x*bpp;
    Uint32 color=0;

    // Bloqueamos la ventana si es necesario
    if (SDL_MUSTLOCK(ptr)) {
        if (SDL_LockSurface(ptr)<0) {
            cerr << "Error al bloquear la ventana ("<<SDL_GetError()<<")"<<endl;
            SDL_Quit();
            exit(-1);
        }
    }

    // Obtenemos punto
    switch (bpp) {
        case 1:
            color = *p;
            break;
        case 2:
            color = *(Uint16*)p;
            break;
        case 3:
            if (SDL_BYTEORDER==SDL_BIG_ENDIAN)
                color = p[0]<<16 | p[1]<<8 | p[2];
            else
                color = p[0] | p[1]<<8 | p[2]<<16;
            break;
        case 4:
            color = *(Uint32*)p;
            break;
    }

    // Desbloqueamos la ventana si es necesario
    if (SDL_MUSTLOCK(ptr)) {
        SDL_UnlockSurface(ptr);
    }

    // Decodificamos el color en sus 3 componentes R, G y B
    SDL_GetRGB(color,ptr->format,&r,&g,&b);
}


/* ***************************************** */

TBotonRaton ObtenerClick(int &x, int &y)
{
    SDL_Event evento;
    TBotonRaton boton;
    bool fin=false;
    while (!fin) {
        if (SDL_WaitEvent(&evento)==1) {
            switch (evento.type) {
                case SDL_MOUSEBUTTONDOWN:    // Pulsamos botón del ratón
                    boton = (TBotonRaton)(evento.button.button);
                    x = evento.button.x;
                    y = evento.button.y;
                    fin = true;
                    break;
                case SDL_QUIT:               // Pulsar X de ventana
                    exit(1);
            }
        }
    }
    return boton;
}

/* ***************************************** */

TTecla ObtenerTecla()
{
    SDL_Event evento;
    //int tecla;
    TTecla tecla;
    bool fin=false;
    while (!fin) {
        if (SDL_WaitEvent(&evento)==1) {
            switch (evento.type) {
                    case SDL_KEYDOWN:     // Pulsamos una tecla
                    //tecla = (int)(evento.key.keysym.sym);
                    tecla = evento.key.keysym.sym;
                    fin = true;
                    break;
                case SDL_QUIT:        // Pulsar X de ventana
                    exit(1);
            }
        }
    }
    return tecla;
}

/* ***************************************** */

TEventoEntrada ObtenerEntrada(TTecla &pulsa, TBotonRaton& boton, int &x, int &y)
{
    SDL_Event evento;
    TEventoEntrada tipo;
    bool fin=false;
    while (!fin) {
        if (SDL_WaitEvent(&evento)==1) {
            switch (evento.type) {
                case SDL_MOUSEBUTTONDOWN:    // Pulsamos botón del ratón
                    boton = (TBotonRaton) (evento.button.button);
                    x = evento.button.x;
                    y = evento.button.y;
                    fin = true;
                    tipo = GRF_RATON;
                    break;
                case SDL_KEYDOWN:            // Pulsamos una tecla
                    pulsa = evento.key.keysym.sym;
                    x = y = -1;
                    tipo = GRF_TECLADO;
                    fin = true;
                    break;
                case SDL_QUIT:               // Pulsar X de ventana
                    exit(1);
            }
        }
    }
    return tipo;
}

/*bool TeclaPresionada(int tecla)
{
    SDL_Event evento;
    bool pulsada=false;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
                case SDL_KEYDOWN:     // Pulsamos una tecla
                cout << tecla << "-" << (int)(evento.key.keysym.scancode) << endl;
                if (tecla == (int)(evento.key.keysym.sym))
                    return true;

                break;
            case SDL_QUIT:        // Pulsar X de ventana
                exit(1);
        }
    }
    return pulsada;



    SDL_Event evento;
    while(SDL_PollEvent(&evento));
    Uint8 *estado = SDL_GetKeyState(0);
    SDL_Delay(1);
    return (estado[tecla]);
}*/

TTecla QueTeclaHayPulsada()
{
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
                case SDL_KEYDOWN:     // Pulsamos una tecla
                //cout << tecla << "-" << (int)(evento.key.keysym.scancode) << endl;
                //if (tecla == (int)(evento.key.keysym.sym))
                //    return true;
                return evento.key.keysym.sym;
                break;
            case SDL_QUIT:        // Pulsar X de ventana
                exit(1);
        }
    }
    //return 0;
    return SDLK_UNKNOWN;
}


//-----------------------------------------------------------------------------
/* ******************************************* */
/* *********  Funciones de Tiempo  *********** */
/* ******************************************* */
//-----------------------------------------------------------------------------


void Esperar(int ms)
{
    SDL_Delay(ms);
}

void CronometroInicio()
{
    cronometro=SDL_GetTicks();
}

long int CronometroValor()
{
    return SDL_GetTicks()-cronometro;
}

//-----------------------------------------------------------------------------
/* ********************************************** */
/* *********  Gestión de Fuentes TTF  *********** */
/* ********************************************** */
//-----------------------------------------------------------------------------


GRF_Fuente CargarFuente(const char *fichero, int tamano, TEstiloFuente estilo)
{
    GRF_Fuente font;
    if (!TTF_WasInit()) {
        cerr << "Ups... pues no se ha inicializado la gestión de fuentes" << endl;
        exit(-1);
    }
    font = TTF_OpenFont(fichero,tamano);
    if (!font) { // Modificar para que devuelva un cero!!!!
        cerr << "No se puede cargar la fuente del fichero " << fichero << " ("<<TTF_GetError()<<")"<<endl;
    }
    else TTF_SetFontStyle(font, estilo);
    return font;
}

/* ***************************************** */

void EscribirTexto(int x, int y, const char *cadena, GRF_Fuente fuente,
                   unsigned char r, unsigned char g, unsigned char b, GRF_Imagen imgdest)
{
    assert(fuente&&cadena);
    SDL_Color color={r,g,b};
    GRF_Imagen imagen=TTF_RenderUTF8_Blended(fuente,cadena,color);
    DibujarImagen(imagen, x, y, imgdest);
    LiberarImagen(imagen);
}

/* ***************************************** */

void LiberarFuente(GRF_Fuente fuente)
{
    assert(fuente);
    TTF_CloseFont(fuente);
}

/* ***************************************** */

int AltoFuente(GRF_Fuente fuente)
{
    assert(fuente);
    return TTF_FontHeight(fuente);
}

/* ***************************************** */

void TamanoTexto(GRF_Fuente fuente, const char *mensaje, int &ancho, int &alto)
{
    assert(fuente);
    ancho = alto = 0;
    if (mensaje) {
        if (TTF_SizeUTF8(fuente,mensaje,&ancho,&alto)) {
            cerr << "No se puede calcular el tamaño del texto ("<<TTF_GetError()<<")"<<endl;
        }
    }
}

//-----------------------------------------------------------------------------
/* ********************************************************************* */
/* *********  Código privado para inicialización automática  *********** */
/* ********************************************************************* */
//-----------------------------------------------------------------------------

namespace {
  struct InicializacionSubsistemas {
          InicializacionSubsistemas();
  } InstanciaIS;

  InicializacionSubsistemas::InicializacionSubsistemas()
  {
      // Iniciamos el módulo de gráficos de la SDL
      if (SDL_Init(SDL_INIT_VIDEO)<0) {
          cerr << "No se puede iniciar el módulo gráfico de SDL ("<<SDL_GetError()<<")"<<endl;
          exit(-1);
      }

      // Permitimos la repetición de teclas con una única pulsación
      SDL_EnableKeyRepeat(200,20);

      // Inicializamos el cronómetro
      cronometro = SDL_GetTicks();

      // Inicializamos el módulo de gestión de tipos de letra
      if (!TTF_WasInit() && TTF_Init()==-1) { // Inicializa si no se hizo antes
          cerr << "No se puede iniciar el módulo de gestión de fuentes ("
               <<TTF_GetError()<<")"<<endl;
          exit(-1);
      }

      // Antes de finalizar el programa se llamará a la función Finalizar_SDL automáticamente
      atexit(Finalizar_SDL);
  }
};

/* ***************************************** */

};   // Fin de namespace graficos
