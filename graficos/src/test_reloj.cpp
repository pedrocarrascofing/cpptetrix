
#include <iostream>
#include "graficos.h"

using namespace std;
using namespace graficos;

int main(int argc, char *argv[])
{
    if (argc!=2) {
        cout << "Sintaxis: " << argv[0] << " n" << endl;
        cout << "          n = número de milisegundos que hay que esperar" << endl;
        exit(0);
    }
    int nms = atoi(argv[1]);
    CronometroInicio();
    Esperar(nms);
    cout << "Han pasado " << CronometroValor() << " milisegundo(s)" << endl;

    CronometroInicio();
    for (int i=0; i<100000; ++i)
        for (int j=0; j<1000; ++j)
           ;
    cout << "Los bucles han tardado " << CronometroValor() << " milisegundo(s)" << endl;
}
