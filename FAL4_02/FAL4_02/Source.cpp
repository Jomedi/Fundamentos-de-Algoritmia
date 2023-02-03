// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool ordenParcial(const vector<int> &v, int ini, int fin, int &maxim, int &minim) {
    if (fin - ini <= 1) {
        maxim = v[ini]; minim = v[ini];
        return true;
    }   
    else if (fin - ini == 2) {
        maxim = max(v[ini], v[fin - 1]);
        minim = min(v[ini], v[fin - 1]);
        return v[fin - 1] >= v[ini];
    }
        
    int maxI, maxD, minI, minD;
    bool izq = ordenParcial(v, ini, (fin + ini) / 2, maxI, minI);
    bool der = ordenParcial(v, (fin + ini) / 2, fin, maxD, minD);

    maxim = max(maxI, maxD);
    minim = min(minI, minD);

    return izq && der && maxI <= maxD && minI <= minD;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, max, min;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v;
    
    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }

    bool sol = ordenParcial(v,0,v.size(),max,min);

    // escribir sol
    if (sol)
        cout << "SI";
    else
        cout << "NO";
    cout << '\n';

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
