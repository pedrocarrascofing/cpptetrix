
#include <iostream>
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
    // Comprobamos sintaxis de la línea de órdenes
    if (argc!=2) {
        cout << "La sintaxis es:" << endl;
        cout << "   " << argv[0] << "  directorio_fuentes" << endl;
        exit(1);
    }
    char *dirf = argv[1];

    // Abrimos la ventana
    CrearVentana(1100,600,"Test: Tipos de letra");

    // Nombres de las fuentes suministradas en este módulo
    const int numf = 15;
    const char *nombres[numf]={"Aerosol.ttf",
                         "Astrolyte.ttf",
                         "Candles.ttf",
                         "CandlesChrome.ttf",
                         "DejaVuSans.ttf",
                         "DejaVuSerif.ttf",
                         "Disko.ttf",
                         "DottyShadow.ttf",
                         "EricssonGA628.ttf",
                         "Freebooter.ttf",
                         "Kredit.ttf",
                         "KreepshowFrigid.ttf",
                         "Moonstar.ttf",
                         "SF_Chaerilidae_Shaded.ttf",
                         "TransponderAOE.ttf"};

    // Cargamos las fuentes
    GRF_Fuente f[numf];
    for (int i=0; i<numf; i++) {
        char nomf[1000];
        sprintf(nomf,"%s/%s",dirf,nombres[i]);
        f[i]=CargarFuente(nomf,30);
        if (f[i]==0) {
          cerr << "La fuente: " << nomf << " no se ha podido cargar." << endl;
          for (int j=0;j<i;++j) 
            LiberarFuente(f[i]);
          exit(1);
        }
    }

    // Dibujamos algo de fondo
    CirculoR(100,100,90,0,0,128);
    CirculoR(300,200,150,0,0,255);
    CirculoR(700,400,190,0,0,190);
    CirculoR(700,100,90,0,0,170);

    // Mostramos cadenas de prueba
    const char *cadena="ABCIJK abcijk 135790 !#$ ñÑ áíóú";
    for (int i=0; i<numf; i++) {
        char cad[1000];
        sprintf(cad,"%s: %s",nombres[i],cadena);
        EscribirTexto(10,10+i*40,cad,f[i],0,255-i*3,0);
    }

    // Liberamos fuentes
    for (int i=0; i<numf; i++)
        LiberarFuente(f[i]);

    ObtenerTecla();
}
