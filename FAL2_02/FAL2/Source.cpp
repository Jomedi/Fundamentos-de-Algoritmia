// Nombre del alumno Jorge Medina Carretero
// Usuario del Juez F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> v1, vector<int> v2) {
    vector<int> sol;
    int j1 = 0, j2 = 0;
    int size = v1.size() + v2.size();
    for (int i = 0; i < size; i++) {
        if (j1 < v1.size() && j2 < v2.size()) {
            if (v1[j1] < v2[j2]) {
                sol.push_back(v1[j1]);
                j1++;
            }
            else if (v1[j1] > v2[j2]) {
                sol.push_back(v2[j2]);
                j2++;
            }
            else {
                sol.push_back(v2[j2]);
                j1++; j2++;
            }
        }
        else if (j1 < v1.size()) {
            sol.push_back(v1[j1]);
            j1++;
        }
        else if(j2 < v2.size()){
            sol.push_back(v2[j2]);
            j2++;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1, v2;

    int dato;

    for (int i = 0; i < n1; i++) {
        cin >> dato;
        v1.push_back(dato);
    }
    for (int i = 0; i < n2; i++) {
        cin >> dato;
        v2.push_back(dato);
    }

    auto sol = resolver(v1,v2);

    // escribir sol
    for (int i = 0; i < sol.size(); i++) 
        cout << sol[i] << " ";

    cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int casos;
    cin >> casos;

    for (int i = 0; i < casos; i++) {
        resuelveCaso();
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
