// Nombre del alumno Jorge Medina Carretero
// Usuario del Juez F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> datos) {
    bool creciente = true;
    bool decreciente = true;
    for (int i = 0; i < datos.size() - 1; i++) {
        if (datos[i] < datos[i + 1])
            decreciente = false;
        else if (datos[i] > datos[i + 1])
            creciente = false;
        else {
            creciente = false;
            decreciente = false;
        }
    }
    return creciente || decreciente;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    
    if (n == 0)
        return false;

    vector<int> datos;
    int altura;

    for (int i = 0; i < n; i++) {
        cin >> altura;
        datos.push_back(altura);
    }

    bool dalton = resolver(datos);

    // escribir sol
    if (dalton)
        cout << "DALTON\n";
    else
        cout << "DESCONOCIDOS\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
