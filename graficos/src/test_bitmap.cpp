
#include <iostream>
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
    if (argc!=2) {
        cout << "Sintaxis: " << argv[0] << " fichero.bmp" << endl;
        exit(0);
    }

    int ancho,alto;
    if (DimensionesImagenFichero(argv[1],ancho,alto)) {
        CrearVentana(ancho+20,alto+20,"Test bitmap");
        GRF_Imagen img = LeerImagen(argv[1]);
        DibujarImagen(img,10,10);
        ObtenerTecla();
        LiberarImagen(img);
    } else
        cout << "Error al abrir el fichero " << argv[1] << endl;
}
