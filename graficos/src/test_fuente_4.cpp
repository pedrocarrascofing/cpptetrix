
#include <iostream>
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
    CrearVentana(140,180,"Ejemplo");
    GRF_Fuente tletra1,tletra2,tletra3;
    tletra1 = CargarFuente("data/fuentes/Disko.ttf",40,TTF_STYLE_NORMAL);
    tletra2 = CargarFuente("data/fuentes/Disko.ttf",40,TTF_STYLE_BOLD);
    tletra3 = CargarFuente("data/fuentes/Disko.ttf",40,TTF_STYLE_ITALIC);
    if (tletra1 && tletra2 && tletra3) {
      EscribirTexto(20,10,"Hola",tletra1,255,0,0);
      EscribirTexto(20,50,"Hola",tletra2,0,255,0);
      EscribirTexto(20,90,"Hola",tletra3,255,255,0);
      LiberarFuente(tletra1);
      LiberarFuente(tletra2);
      LiberarFuente(tletra3);
    }
    ObtenerTecla();
}
