#include "graficos.h"
using namespace graficos;                 // Usamos el espacio de nombres
int main(int argc, char *argv[])
{
    CrearVentana(800,600,"Ejemplo Dibujo");   // Abrimos la ventana

    // Dibujamos algunos puntos (tonos azules)
    for (int i=0; i<100; ++i)
        Punto(10+i*2,10+i*2,i*2,i*2,250);

    // Dibujamos líneas rectas (tonos violeta)
    for (int i=0; i<10; ++i)
        Linea(10,100+i*10,100,200+i*30,100+i*10,0,100+i*10);

    // Dibujamos rectángulos sin relleno (tonos rojos)
    for (int i=0; i<20; ++i)
        Rectangulo(250+i*3,20+i*3,450-i*2,300-i*2,255-i*10,0,0);

    // Dibujamos rectángulos con relleno (tonos verdes)
    RectanguloR(150,350,350,500,0,255,0);
    RectanguloR(250,310,450,400,0,200,0);
    RectanguloR(300,370,400,550,0,160,0);

    // Dibujamos círculos sin relleno (tonos amarillos)
    for (int i=0; i<20; ++i)
        Circulo(600,150,50+i*2,255-i*10,255-i*10,0);

    // Dibujamos elipses con relleno (tonos azules)
    for (int i=20; i>0; --i)
        ElipseR(600,350,50+i*4,30+i*2,0,0,255-i*10);

    // Esperamos a que se pulse una tecla
    ObtenerTecla();
}
