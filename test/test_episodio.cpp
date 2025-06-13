#include <gtest/gtest.h>
#include "Episodio.h"

TEST(EpisodioTest1, ConstructorExcepcion)
{
    EXPECT_THROW({Episodio e("Piloto",-11)}, const char*);
}

TEST(EpisodioTest2, ProbarCalcularPromedio)
{
    Episodio e("Llamada", 12);
    e.agregarCalificacion(4);
    e.agregarCalificacion(5);

    EXPECT_DOUBLE_EQ(e.calcularPromedio(), 4.5);

}

TEST(EpisodioTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Episodio e("La llegada", 3);
    EXPECT_THROW(e.calcularPromedio(), const char*);
}

TEST(EpisodioTest4, ProbarMetodoMostrar){
    Episodio e("Paloma",18);
    e.agregarCalificacion(3);
    std::stringstream flujo;

    e.mostrar(flujo);

    std::stringstream esperado;
    esperado<<"Episodio: " << std::endl <<
    "Nombre: "<<"Paloma" << std::endl <<
	  "Temporada: " << 18 << std::endl <<
	  "Calificacion Promedio: " << 3 << std::endl;
    EXPECT_EQ(flujo.str(), esperado.str());
}

TEST(EpisodioTest5, ProbarAgregrarCalificacionErronea){
		Episodio e("Jamaica",3);
		EXPECT_THROW(e.agregarCalificacion(-23),const char*);
	}
