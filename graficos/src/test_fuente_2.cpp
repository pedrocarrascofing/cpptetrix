
#include <iostream>
#include "graficos.h"

using namespace std;
using namespace graficos;

void CargarFuentes(GRF_Fuente f[5], const char *nombre, TEstiloFuente estilo)
{
  for (int i=0; i<5; i++) {
    f[i]=CargarFuente(nombre,10+i*10,estilo);
    if (f[i]==0) {
      cerr<< "La fuente " << nombre << " no se puede cargar" << endl;
      exit(1);
    }
  }
}


int main(int argc, char *argv[])
{
    // Comprobamos sintaxis de la línea de órdenes
    if (argc!=3) {
        cout << "La sintaxis es:" << endl;
        cout << "   " << argv[0] << "  directorio_fuentes  nombre_fuente" << endl;
        cout << "      (El nombre de la fuente no incluye la extensión .ttf" << endl;
        exit(1);
    }
    char *dirf = argv[1];
    char *nomfuen = argv[2];

    // Abrimos la ventana
    CrearVentana(800,600,"Test: Tipos de letra (2)");

    // Creamos nombre de la fuente (carpeta/fuente.ttf)
    char nomf[1000];
    sprintf(nomf,"%s/%s.ttf",dirf,nomfuen);

    GRF_Fuente fuente[3][5];
    CargarFuentes(fuente[0],nomf,TTF_STYLE_NORMAL);  // Estilo normal
    CargarFuentes(fuente[1],nomf,TTF_STYLE_BOLD);    // Estilo Bold
    CargarFuentes(fuente[2],nomf,TTF_STYLE_ITALIC);  // Estilo itálica


    // Dibujamos algo de fondo
    CirculoR(100,100,90,0,0,128);
    CirculoR(300,200,150,0,0,255);
    CirculoR(600,400,190,0,0,190);
    CirculoR(700,100,90,0,0,170);

    // Mostramos cadenas de prueba (normal)
    int fil=10;
    for (int i=0; i<5; i++) {
        char cad[1000];
        sprintf(cad,"%s %d",nomfuen,10+i*10);
        EscribirTexto(10,fil,cad,fuente[0][i],0,255-i*3,0);
        fil += AltoFuente(fuente[0][i]);
    }

    // Mostramos cadenas de prueba (negrita)
    for (int i=0; i<5; i++) {
        char cad[1000];
        sprintf(cad,"%s Negrita %d",nomfuen,10+i*10);
        EscribirTexto(10,fil,cad,fuente[1][i],0,255-i*3,255-i*3);
        fil += AltoFuente(fuente[1][i]);
    }

    // Mostramos cadenas de prueba (itálica)
    for (int i=0; i<5; i++) {
        char cad[1000];
        sprintf(cad,"%s Itálica %d",nomfuen,10+i*10);
        EscribirTexto(10,fil,cad,fuente[2][i],255-i*3,255-i*3,0);
        fil += AltoFuente(fuente[2][i]);
    }

    // Liberamos fuentes
    for (int j=0;j<3;++j)
      for (int i=0; i<5; i++)
          LiberarFuente(fuente[j][i]);

    ObtenerTecla();
}
