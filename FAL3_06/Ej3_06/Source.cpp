// Nombre del alumno ..... Jorge Medina Carrtero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v(n);
    int aux;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        v[i] = aux;
    }

    //TipoSolucion sol = resolver(datos);
    int max = 0, cont = 0, numMax = 0, contMax = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            contMax++;
            if (contMax > max) {
                max = contMax;
                numMax = 1;
                cont = 0;
            }
            else if (contMax == max) {
                numMax++;
                cont = 0;
            }   
            else
                cont++;
        }
        else {
            contMax = 0;
            cont++;
        }     
    }

    // escribir sol
    cout << max << " " << numMax << " " << cont << '\n';


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}