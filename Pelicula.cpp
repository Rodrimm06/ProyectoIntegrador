#include "Pelicula.h"
// Constructor, esta subclase solo tiene de atributos los de la clase base Video
Pelicula::Pelicula(int id_, const std::string& nombre_, double duracion_,  const std::string& genero_)
	:Video(id_,nombre_,duracion_,genero_){
	
}
// Funcion para mostrar informacion de la pelicula
void Pelicula::mostrar() const {
	std::cout << "Pelicula: " << getNombre() << std::endl <<
		"Duracion: " << getDuracion() << std::endl <<
		"Genero: " << getGenero() << std::endl <<
		"ID: " << getId() << std::endl <<
		"Calificacion Promedio: " << calcularPromedio() << std::endl;
}
// Sobrecarga de operadores para mayor eficiencia
std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
	os << "Pelicula: " << pelicula.getNombre() << std::endl
		<< "Duracion: " << pelicula.getDuracion() << std::endl
		<< "Genero: " << pelicula.getGenero() << std::endl
		<< "ID: " << pelicula.getId() << std::endl
		<< "Calificacion Promedio: " << pelicula.calcularPromedio() << std::endl;
	return os;
}
