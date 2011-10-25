#include <iostream>
#include "graficos.h"
using namespace std;
using namespace graficos;

int main()
{
  SDLKey tec;

  CrearVentana(400,40,"Ventana de ejemplo");
  Texto(10,10,"Pulsa una tecla y veras su codigo en consola",0,255,0);
  Texto(10,20,"Pulsa escape para terminar",255,0,0);

  do {
    tec = ObtenerTecla(); // Esperamos a que se pulse una tecla
    cout << "La tecla pulsada tiene el código: " << (int)tec << endl;
  } while (tec!=SDLK_ESCAPE);   // hasta pulsar Escape

  return 0;
}
