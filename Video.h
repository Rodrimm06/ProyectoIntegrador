#pragma once
#include <iostream>
#include <vector>
#include <string>

/**
 Esta clase simula ser un video dentro de una plataforma de streaming
 Es una clase abstracta
*/
class Video
{
protected:
	/** 
	 ID para identificar el video
	*/
	int id;

	/** 
	 Nombre del video
	*/
	std::string nombre;

	/** 
	 Duracion en minutos
	*/
	double duracion;

	/** 
	 Genero al que pertenece
	*/
	std::string genero;

	/** 
	 Vector para manejar de manera mas dinamica las calificaciones
	*/
	std::vector<int> calificaciones;

public:
	/** 
	 Constructor
	*/
	Video(int id_, const std::string& nombre_, double duracion_, const std::string& genero_);

	/** 
	 Funcion para agregar una calificacion
	*/
	void virtual AgregarCalificacion(int cali);

	/** 
	 Funcion puramente virtual para que se convierta en una clase abstracta
	*/
	void virtual Mostrar() const = 0;

	/** 
	 Funcion para calcular el promedio
	*/
	double virtual CalcularPromedio() const;

	/** 
	 Destructor
	*/
	virtual ~Video() = default;

	/** 
	 Funcion set de ID
	*/
	void SetId(int id_);

	/** 
	 Funcion set de nombre
	*/
	void SetNombre(std::string nom);

	/** 
	 Funcion set de duracion
	*/
	void SetDuracion(double dur);

	/** 
	 Funcion set de genero
	*/
	void SetGenero(std::string gen);

	/** 
	 Funcion get de ID
	*/
	int GetId() const;

	/** 
	 Funcion get de nombre
	*/
	std::string GetNombre() const;

	/** 
	 Funcion get de duracion
	*/
	double GetDuracion() const;

	/** 
	 Funcion get de genero
	*/
	std::string GetGenero() const;
};
