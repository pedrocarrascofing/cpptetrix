
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
        CrearVentana(ancho*4+20,alto*4+20,"Test bitmap 2");
        GRF_Imagen img = LeerImagen(argv[1]);
        int posx=10, posy=10;
        TTecla tec=SDLK_UNKNOWN;
        while (tec!=SDLK_ESCAPE) {  // Pulsar Escape para terminar
            DibujarImagen(img,posx,posy);
            tec = ObtenerTecla();
            RectanguloR(posx,posy,posx+ancho,posy+alto,0,0,0);  // Borrar
            if (tec==SDLK_UP && posy>10) posy--;
            if (tec==SDLK_DOWN && posy<alto*3+10) posy++;
            if (tec==SDLK_LEFT && posx>10) posx--;
            if (tec==SDLK_RIGHT && posx<ancho*3+10) posx++;
        }
        LiberarImagen(img);
    } else
        cout << "Error al abrir el fichero " << argv[1] << endl;
}
