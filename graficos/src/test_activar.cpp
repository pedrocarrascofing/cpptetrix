
#include <iostream>
#include <cstdlib>
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
    if (argc!=2) {
        cout << "Sintaxis: " << argv[0] << " n" << endl;
        cout << "          n = número de círculos que hay que dibujar (por ejemplo 10000)" << endl;
        exit(0);
    }
    int ncir = atoi(argv[1]);
    srand(time(0));

    CrearVentana(800,600,"Dibujando círculos ...");

    cout << "Dibujamos " << ncir << " círculos con acceso constante al hardware de vídeo" << endl;
    CronometroInicio();
    for (int i=0; i<ncir; i++)
        CirculoR(50+rand()%690,100+rand()%440,rand()%49,rand()%256,rand()%256,rand()%256);
    cout << "Han pasado " << CronometroValor() << " milisegundo(s)" << endl;

    Texto(1,1,"Pulsa una tecla para continuar ...",255,0,0);
    ObtenerTecla();
    LimpiarVentana();

    cout << "Dibujamos " << ncir << " círculos SIN acceso constante al hardware de vídeo" << endl;
    DesactivarDibujo();
    CronometroInicio();
    for (int i=0; i<ncir; i++)
        CirculoR(50+rand()%690,50+rand()%490,rand()%49,rand()%256,rand()%256,rand()%256);
    ActivarDibujo();
    cout << "Han pasado " << CronometroValor() << " milisegundo(s)" << endl;

    Texto(1,1,"Pulsa una tecla para acabar ...",255,0,0);
    ObtenerTecla();
}
