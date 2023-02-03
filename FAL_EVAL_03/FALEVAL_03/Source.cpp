// Nombre del alumno ..... Jorge Medina Carretero y Miriam Choy Castillo
// Usuario del Juez ...... F46 y F13


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int resolver(int datos, int ant) {
    int sol = datos % 10;
    int solucion;
    if (datos >= 10) {
        if (sol >= ant) 
            sol = sol + 10 * resolver(datos / 10, sol);
        else 
            sol = resolver(datos/10, ant);
    }

    if (sol >= ant)
        return sol;
    else
        return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, max = -1;
    cin >> n;

    int sol = resolver(n, max);
    // escribir sol
    cout << sol << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}