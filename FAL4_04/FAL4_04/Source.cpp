// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int complementario(int datos) {
    int sol = 9 - (datos % 10);

    if (datos >= 10)
        sol += 10 * complementario(datos / 10);

    return sol;
}

int inverso(int datos, int pot) {
    int sol = datos % 10;

    if (pot >= 10)
        sol = sol * pot + inverso(datos / 10, pot / 10);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int num = n, pot = 1;
    while (num >= 10) {
        pot *= 10;
        num /= 10;
    }

    // escribir sol
    cout << complementario(n) << " " << inverso(complementario(n), pot) << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}