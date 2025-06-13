#pragma once
#include <iostream>
#include <vector>
#include <string>
class Video
{
protected:
	/* Se declaran todos los atributos de la clase base video en protected para que sus clases hijas
	puedan acceder también
	*/
	int id;
	std::string nombre;
	double duracion;
	std::string genero;
	// Vector para manejar de manera mas dinamica las calificaciones
	std::vector<int> calificaciones;

// Se declaran los metodos de la clase
public:
	// Constructor
	Video(int id_, const std::string& nombre_, double duracion_, const std::string& genero_);
	// Fucnion para agregar una calificacion
	void virtual agregarCalificacion(int cali);
	// Funcion puramente virtual para que se convierta en una clase abstracta
	void virtual mostrar() const=0;
	// Funcion para calcular el promedio
	double virtual calcularPromedio() const;

	// Destructor
	virtual ~Video() = default;

	// Funciones set/get
	void setId(int id_);
	void setNombre(std::string nom);
	void setDuracion(double dur);
	void setGenero(std::string gen);
	int getId() const;
	std::string getNombre() const;
	double getDuracion() const;
	std::string getGenero() const;
};

