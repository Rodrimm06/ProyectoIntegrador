#include "Serie.h"
// Constructor
Serie::Serie(int id_, const std::string& nombre_, double duracion_, const std::string& genero_)
	:Video(id_, nombre_, duracion_, genero_) {

}
// Para agregar episodios
void Serie::agregarEpisodio(const Episodio& episodio) {
	episodios.push_back(episodio);
}
// Para visualizar todos los episodios
void Serie::mostrarEpisodios() const {
	for (int i = 0;i < size(episodios);i++) {
		std::cout << episodios[i];
	}
}
// Se calcula el promedio de todos los episodios de la serie y es el que se devuelve
double Serie::calcularPromedio() const{
	double promedio = 0;
	// For para recorrer el vector de calificaciones
	for (int i = 0;i < episodios.size();i++) {
		promedio = promedio + episodios[i].calcularPromedio();
	}
	// Se verifica que no se divida entre cero
	if (episodios.size() > 0) {
		return promedio / episodios.size();
	}
	else {
		throw "Error, no se puede promediar sin calificaciones";
	}
}
// Funcion de mostrar
void Serie::mostrar() const {
    std::cout << "Serie: " << getNombre() << std::endl
              << "Duracion: " << getDuracion() << std::endl
              << "Genero: " << getGenero() << std::endl
              << "ID: " << getId() << std::endl;
    if (episodios.empty()) {
        throw "No hay episodios para calcular promedio";
    }
    std::cout << "Calificacion Promedio: " << calcularPromedio() << std::endl;
    std::cout << "Episodios: " << std::endl;
    for (const auto& ep : episodios) {
        std::cout << ep;
    }
}
// Sobrecarga de operador para mayor eficiencia
std::ostream& operator<<(std::ostream& os, const Serie& serie) {
	os << "Serie: " << serie.getNombre() << std::endl
		<< "Duracion: " << serie.getDuracion() << std::endl
		<< "Genero: " << serie.getGenero() << std::endl
		<< "ID: " << serie.getId() << std::endl
		<< "Calificacion Promedio: " << serie.calcularPromedio() << std::endl;
	// Se recorre el vector de episodios y se guarda cada uno
	for (int i = 0;i < size(serie.episodios);i++) {
		os <<"Episodio "<<i+1<<std::endl<< serie.episodios[i];
	}
	return os;
}
