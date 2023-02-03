// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct tDatos {
    int supermercados, productos;
    vector<vector<int>> precios;
    vector<int> prodmismosuper;
    int precioTotal = 0, minimo = INT_MAX;
};

// función que resuelve el problema
void resolver(tDatos &datos, int k) {
    for (int pos = 0; pos < datos.supermercados; pos++) {
        if (datos.prodmismosuper[pos] < 3) {

            datos.prodmismosuper[pos]++;
            datos.precioTotal += datos.precios[pos][k];
            //suma -= coste[col];

            if (datos.precioTotal < datos.minimo) {
                cout << 1;
                if (k == datos.productos - 1) 
                    datos.minimo = datos.precioTotal;
                else
                    resolver(datos, k + 1);
            }

            datos.prodmismosuper[pos]--;
            datos.precioTotal -= datos.precios[pos][k];
            //suma += coste[col];
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;

    cin >> datos.supermercados >> datos.productos;

    vector<vector<int>> precios(datos.supermercados, vector<int>(datos.productos));
    for (auto &productos : precios) {
        for (auto &precio : productos) {
            cin >> precio;
        }
    }
    datos.precios = precios;

    vector<int> prodmismosuper(datos.supermercados, 0);
    datos.prodmismosuper = prodmismosuper;

    resolver(datos, 0);

    // escribir sol
    cout << datos.minimo << "\n";

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