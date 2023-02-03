// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool caucasico(const vector<int> &v, int ini, int fin, int &pares) {
    if (fin - ini <= 1)
        return true;
    else if (fin - ini == 2) {
        pares = (v[fin - 1] + 1) % 2 + (v[ini] + 1) % 2;
        return true;
    }

    int paresI, paresD, mitad = (fin + ini) / 2;
    bool c1 = caucasico(v, ini, mitad, paresI);
    bool c2 = caucasico(v, mitad, fin, paresD);

    int resta = abs(paresI - paresD);

    pares = paresI + paresD;

    return resta <= 2 && c1 && c2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int pares = 0;
    bool sol = caucasico(v, 0, v.size(), pares);

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
