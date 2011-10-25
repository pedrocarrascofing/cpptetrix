#include "graficos.h"
using namespace graficos;                 // Usamos el espacio de nombres
int main(int argc, char *argv[])
{
    CrearVentana(300,200,"Hola Mundo");   // Abrimos la ventana
    Rectangulo(75,75,225,120,255,0,0);    // Dibujamos un rectángulo
    Texto(100,95,"Hola mundo !",0,255,0); // Mostramos un mensaje
    ObtenerTecla();                       // Esperamos a que se pulse una tecla
}
