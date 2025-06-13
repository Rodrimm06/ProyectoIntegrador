#pragma once
#include "Video.h"
class Pelicula: public Video
{
public:
	// Constructor
	Pelicula(int id_,const std::string& nombre_, double duracion_,const std::string& genero_);
	// Funcion de mostrar
	void mostrar() const override;
	// Sobrecarga de operador para mayor eficiencia
	friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);
};

