// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &v, int ini, int fin) {
    if (fin - ini == 1)
        return 0;
    else if (fin - ini == 2) {
        if (v[ini] > v[fin - 1]) {
            int aux = v[fin - 1];
            v[fin - 1] = v[ini];
            v[ini] = aux;
            return 1;
        }
        else
            return 0;
    }

    int m = (fin + ini) / 2;

    int cambiosR = resolver(v, m, fin);
    int cambiosL = resolver(v, ini, m);
    int cambios = 0;

    for (int i = m; i < fin - 1; i++) {
        if (v[i] > v[i + 1]) {
            int aux = v[i+1];
            v[i+1] = v[i];
            v[i] = aux;
            cambios++;
        }
    }
    for (int i = ini; i <= m; i++) {
        if (v[i] > v[i + 1]) {
            int aux = v[i + 1];
            v[i + 1] = v[i];
            v[i] = aux;
            cambios++;
        }
    }

    return cambios + cambiosR + cambiosL;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    int sol = resolver(v,0,n);

    // escribir sol
    cout << sol << "\n";

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