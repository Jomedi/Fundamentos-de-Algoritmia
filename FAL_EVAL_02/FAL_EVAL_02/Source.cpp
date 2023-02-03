// Nombre del alumno ..... Jorge Medina Carretero
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

    if (n == 0)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    int sum = v[v.size() - 1];
    bool encontrado = false;
    if (sum == 0)
        encontrado = true;
    for (int i = 1; i < n && !encontrado; i++) {
        if (v[n - i - 1] == sum)
            encontrado = true;
        else
            sum += v[n - i - 1];
    }


    // escribir sol
    if (encontrado)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

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
