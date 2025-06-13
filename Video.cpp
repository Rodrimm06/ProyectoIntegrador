#include "Video.h"
// Constructor
Video::Video(int id_, const std::string& nombre_, double duracion_, const std::string& genero_):id(id_),nombre(nombre_),
duracion(duracion_),genero(genero_){
	if (genero != "Misterio" && genero != "Accion" && genero != "Drama") {
		throw "Error, genero no reconocido";
	}
	if (duracion <= 0) {
		throw "Error, duracion invalida";
	}
}
// Funcion para agregar una calificacion al vector
void Video::agregarCalificacion(int cali) {
	if (cali > 0 && cali < 6) {
		calificaciones.push_back(cali);
	}
	else {
		throw "Error, calificacion fuera de rango";
	}
}
// Funcion para calcular el promedio
double Video::calcularPromedio() const{
	double promedio=0;
	// For para recorrer el vector de calificaciones
	for (int i = 0;i < calificaciones.size();i++) {
		promedio = promedio + calificaciones[i];
	}
	if (calificaciones.size() > 0) {
		return promedio / calificaciones.size();
	}
	else {
		throw "Error, no se puede promediar sin calificaciones";
	}
}


// Funciones set/get
void Video::setId(int id_) {
	id = id_;
}
void Video::setNombre(std::string nom) {
	nombre = nom;
}
void Video::setDuracion(double dur) {
	duracion = dur;
}
void Video::setGenero(std::string gen) {
	genero = gen;
}
int Video::getId() const {
	return id;
}
std::string Video::getNombre() const {
	return nombre;
}
double Video::getDuracion() const {
	return duracion;
}
std::string Video::getGenero() const {
	return genero;
}
