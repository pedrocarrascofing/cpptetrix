#include <iostream>
#include <cstdlib> // atoi
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
  if (argc==3) {
    CrearVentana(200,100,"Ejemplo");
    GRF_Fuente tletra;
    int tam= atoi(argv[2]);
    tletra = CargarFuente(argv[1],tam); // Por defecto, estilo normal
    if (tletra!=0) {
      int alto,ancho;
      TamanoTexto(tletra,"Hola",ancho,alto);
      CrearVentana(ancho+100,alto+40,"Ejemplo");
      RectanguloR(50, 20, 50+ancho, 20+alto, 255,255,255);
      EscribirTexto(50,20,"Hola",tletra,255,0,0);
      cout << "Esta cadena ocupa " << ancho << " x " << alto << " píxeles" << endl;
      LiberarFuente(tletra);
      ObtenerTecla();
    }
    else {
      cerr << "Error en la lectura de la fuente" << endl;
      return 1;
    }
  }
  else {
    cerr << "Uso: " << argv[0] << " <fuente> <tamaño>" << endl;
    return 1;
  }
}
