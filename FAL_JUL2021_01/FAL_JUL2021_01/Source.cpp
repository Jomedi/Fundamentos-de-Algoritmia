// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(int &longMax, int &p, int &q, int &tramos, const vector<int> & v) {
    int longitud = 0;
    int pMax = 0, qMax = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] <= v[i + 1]) {
            if (longitud == 0) {
                tramos++;
                longitud = 2;
                p = i;
                q = i + 1;
            }   
            else {
                longitud++;
                q = i + 1;
            }   
        }
        else {
            longitud = 0;
            p = i + 1;
            q = i + 1;
        }
        if (longitud > longMax)
            longMax = longitud;
        if (q - p > qMax - pMax) {
            pMax = p;
            qMax = q;
        }   
    }
    p = pMax;
    q = qMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    
    int longMax = 0, p = 0, q = 0, tramos = 0;
    resolver(longMax, p , q, tramos, v);

    // escribir sol
    cout << longMax << " " << p << " " << q << " " << tramos << endl;
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