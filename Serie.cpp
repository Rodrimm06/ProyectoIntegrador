#include "Serie.h"

// Constructor
Serie::Serie(int id_, const std::string& nombre_, double duracion_, const std::string& genero_)
    : Video(id_, nombre_, duracion_, genero_) {
    // Validación ya hecha en Video
}

// Para agregar episodios
void Serie::agregarEpisodio(const Episodio& episodio) {
    episodios.push_back(episodio);
}

// Para visualizar todos los episodios
void Serie::mostrarEpisodios() const {
    for (int i = 0; i < (int)episodios.size(); i++) {
        std::cout << episodios[i];
    }
}

// Se calcula el promedio de todos los episodios de la serie y es el que se devuelve
double Serie::calcularPromedio() const {
    if (episodios.empty()) throw "No hay episodios para calcular promedio";
    
    double promedio = 0;
    int contador = 0;
    for (int i = 0; i < (int)episodios.size(); i++) {
        double epPromedio = episodios[i].calcularPromedio();
        promedio += epPromedio;
        contador++;
    }
    if (contador == 0) throw "No hay calificaciones para calcular promedio";
    
    return promedio / contador;
}

// Funcion de mostrar
void Serie::mostrar() const {
    std::cout << "Serie: " << getNombre() << std::endl
              << "Duracion: " << getDuracion() << std::endl
              << "Genero: " << getGenero() << std::endl
              << "ID: " << getId() << std::endl;

    std::cout << "Calificacion Promedio: " << calcularPromedio() << std::endl;
    std::cout << "Episodios:" << std::endl;

    mostrarEpisodios();
}

// Sobrecarga de operador para mayor eficiencia
std::ostream& operator<<(std::ostream& os, const Serie& serie) {
    os << "Serie: " << serie.getNombre() << std::endl
       << "Duracion: " << serie.getDuracion() << std::endl
       << "Genero: " << serie.getGenero() << std::endl
       << "ID: " << serie.getId() << std::endl;

    os << "Calificacion Promedio: " << serie.calcularPromedio() << std::endl;
    os << "Episodios:" << std::endl;

    for (int i = 0; i < (int)serie.getEpisodios().size(); i++) {
        os << serie.getEpisodios()[i];
    }
    return os;
}


