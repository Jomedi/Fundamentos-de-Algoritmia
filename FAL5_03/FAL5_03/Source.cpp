// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> v, vector<int> v2, int ini, int fin) {
    if (fin - ini == 1) 
        return v[ini];
    else if (fin - ini == 2) {
        if (v[ini] != v2[ini])
            return v[ini];
        else
            return v[ini + 1];
    }
    
    int mitad = (fin + ini) / 2;

    int sol = 0;
    
    if (v[mitad] != v2[mitad]) {
        sol = resolver(v, v2, mitad, fin);
    }
    else
        sol = resolver(v, v2, ini, mitad);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n), v2(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> v2[i];
    }

    //comparar mitad con ini y mitad con fin, si es par comprar mitad - 1 con ini y mitad con fin.
    int sol;
    if (n == 1)
        sol = v[0];
    else if (v[0] != v2[0])
        sol = v[0];
    else if (v[v.size() - 1] != v2[v2.size() - 1])
        sol = v[v.size() - 1];
    else 
        sol = resolver(v, v2, 0, n);
    
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
