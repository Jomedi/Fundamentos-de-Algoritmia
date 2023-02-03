// Nombre del alumno: Jorge Medina Carretero
// Usuario del Juez F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v, r, a;
    char color;
    int aux;

    for (int i = 0; i < n; i++) {
        cin >> color;
        cin >> aux;
        if (color == 'a')
            a.push_back(aux);
        else if (color == 'v')
            v.push_back(aux);
        else
            r.push_back(aux);
    }
    sort(a.begin(), a.end());
    sort(v.begin(), v.end());
    sort(r.begin(), r.end());
    
    // escribir sol
    cout << "Azules: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    cout << "Verdes: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
    cout << "Rojas: ";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
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