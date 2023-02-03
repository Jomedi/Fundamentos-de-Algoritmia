// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

// función que resuelve el problema
char resolver(const string &datos, int ini, int fin) {
    if (fin - ini == 1)
        return datos[ini] + 1;

    int medio = (fin + ini) / 2;
    if (datos[ini] - ini != datos[medio] - medio)
        return resolver(datos, ini, medio);
    else
        return resolver(datos, medio, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char c1, c2, aux;
    cin >> c1 >> c2;

    string datos;
    for (int i = 0; i < c2 - c1; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    // escribir sol
    if (datos[0] != c1)
        cout << c1 << '\n';
    else if (datos[datos.size() - 1] != c2)
        cout << c2 << '\n';
    else
        cout << resolver(datos, 0, datos.size() - 1) << '\n';


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