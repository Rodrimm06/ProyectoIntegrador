Plataforma de videos en C++

Este proyecto implementa un sistema para gestionar una plataforma de videos en C++, incluyendo películas y series con capítulos.

El proyecto está elaborado con programación orientada a objetos, herencia, polimorfismo y uso de vectores.

Clases del proyecto

Se compone por cuatro clases:

Video

Clase base y abstracta.

Atributos:

id

nombre

duración

género

calificaciones del video (1-5)

Métodos:

agregarCalificacion(int calificacion)


calcularPromedio()

mostrar() (función virtual pura)

getters y setters


Pelicula

Subclase de Video.

Hereda todos los atributos de video y solo tiene de extra los siguientes métodos:

mostrar()

operator<< (sobrecarga del operador para imprimir más fácilmente)


Serie

Subclase de Video.

Además de heredar lo de la clase Video, tiene un atributo extra que es un vector de episodios.

Métodos:

agregarEpisodio(episodio)

mostrarEpisodios()

calcularPromedio()

mostrar()

operator<< (sobrecarga para imprimir más fácilmente)


Episodio

Clase que representa un episodio de una serie.

Atributos:

nombre

temporada

calificaciones del episodio (1-5)

Métodos:

agregarCalificacion(int)

calcularPromedio()

mostrar()

operator<< (sobrecarga para imprimir más fácilmente)


En el main se hace uso de un vector<Video*> para guardar tanto películas como series y trabajar con ellas usando polimorfismo.
