
#include <iostream>
#include "graficos.h"
using namespace std;
using namespace graficos;

int main()
{
  TBotonRaton bot;
  int x,y;

  CrearVentana(460,60,"Ventana de ejemplo");
  Texto(10,10,"Cada vez que pulses el boton izqdo o central del raton",0,255,0);
  Texto(10,20,"veras en consola las coordenadas del puntero",0,255,0);
  Texto(10,40,"Pulsa el boton derecho para terminar",255,0,0);

  do {
    // Esperamos a que se pulse el ratón
    bot = ObtenerClick(x,y);
    cout << "Has pulsado el botón ";
    switch (bot) {
      case SDL_BUTTON_LEFT:
        cout << "izquierdo";
        break;
      case SDL_BUTTON_MIDDLE:
        cout << "central";
        break;
      case SDL_BUTTON_RIGHT:
        cout << "derecho";
        break;
   }
   cout << " en (" << x << "," << y << ")" << endl;
  } while (bot!=SDL_BUTTON_RIGHT);
}
