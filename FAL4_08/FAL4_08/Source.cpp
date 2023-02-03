// Nombre del alumno ..... Jorge Medina Carretero
// Usuario del Juez ...... F46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int> &datos, int ini, int fin, int &prodI, int &sumI, int &prodD, int &sumD) {
    if (fin - ini == 1) 
        return true;
    else if (fin - ini == 2){
        if (datos[ini] % 2 == 1) {
            sumI = 0;
            prodI = datos[ini];
        }    
        else {
            sumI = datos[ini];
            prodI = 1;
        }
        
        if (datos[fin - 1] % 2 == 0) {
            sumD = 0;
            prodD = datos[fin - 1]; 
        }
        else {
            sumD = datos[fin - 1];
            prodD = 1;
        }
        return sumI + prodI <= sumD + prodD;
    }
        
    int mitad = (fin + ini) / 2;
    int prodII, prodID, sumaII, sumaID, prodDI, prodDD, sumaDI, sumaDD;
    bool izq = resolver(datos, ini, mitad, prodII, sumaII, prodID, sumaID);
    bool der = resolver(datos, mitad, fin, prodDI, sumaDI, prodDD, sumaDD);

    if (sumaID == 0)
        sumaID = 1;
    prodI *= prodII * sumaID;
    sumI += sumaII + prodID;

    if (sumaDD == 0)
        sumaDD = 1;
    prodD *= prodDI * sumaDD;
    sumD += sumaDI + prodDD;

    return (sumI + prodI <= sumD + prodD) && (izq || der);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sumaI = 0, sumaD = 0, prodI = 1, prodD = 1;
    bool sol = resolver(v, 0, v.size(), prodI, sumaI, prodD, sumaD);
    // escribir sol
    sol ? cout << "SI" : cout << "NO"; cout << '\n';
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