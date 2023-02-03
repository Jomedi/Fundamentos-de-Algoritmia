// Nombre del alumno Jorge Medina Carretero
// Usuario del Juez F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<string> datos, string pais) {
    int i = datos.size() - 1;
    while (i >= 0) {
        if (datos[i] == pais)
            return i;
        else
            i--;
    }
    return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    string pais;
    cin >> pais;

    vector<string> paises;
    string dato;

    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        cin >> dato;
        if (dato == pais)
            encontrado = true;
        paises.push_back(dato);
    }

    // escribir sol
    if (encontrado) {
        auto sol = resolver(paises, pais);
        cout << paises.size() - sol << '\n';
    }else
        cout << "NUNCA" << '\n';
        
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
