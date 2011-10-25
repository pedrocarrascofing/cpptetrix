#include <iostream>
#include "graficos.h"   // Incluimos la biblioteca gráfica

using namespace std;

int main(int argc, char *argv[])
{
  // Abrimos la ventana gráfica
  graficos::CrearVentana(200,200,"Ventana de ejemplo");

  // Dibujamos algo
  graficos::Rectangulo(10,10,40,80,255,0,0);
  graficos::RectanguloR(20,70,80,90,0,255,0);
  graficos::Circulo(100,100,50,0,0,255);
  graficos::Texto(20,170,"Pulsa una tecla",255,255,0);

  // Esperamos a que se pulse una tecla
  graficos::ObtenerTecla(); // Ignoramos el valor devuelto
}
