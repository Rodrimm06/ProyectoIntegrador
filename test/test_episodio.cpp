#include <gtest/gtest.h>
#include "Episodio.h"

TEST(EpisodioTest1, ConstructorExcepcion)
{
    // Quitar las llaves {} en EXPECT_THROW
    EXPECT_THROW(Episodio("Piloto",-11), const char*);
}

TEST(EpisodioTest2, ProbarCalcularPromedio)
{
    Episodio e("Llamada", 12);
    e.AgregarCalificacionEpisodio(4);
    e.AgregarCalificacionEpisodio(5);

    EXPECT_DOUBLE_EQ(e.CalcularPromedioEpisodio(), 4.5);
}

TEST(EpisodioTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Episodio e("La llegada", 3);
    EXPECT_THROW(e.CalcularPromedioEpisodio(), const char*);
}

TEST(EpisodioTest4, ProbarMetodoMostrar){
    Episodio e("Paloma",18);
    e.AgregarCalificacionEpisodio(3);

    std::stringstream flujo;
    std::streambuf* oldCout = std::cout.rdbuf(flujo.rdbuf());

    e.MostrarEpisodio();

    std::cout.rdbuf(oldCout);

    std::stringstream esperado;
    esperado << "Episodio: " << std::endl
             << "Nombre: " << "Paloma" << std::endl
             << "Temporada: " << 18 << std::endl
             << "Calificacion Promedio: " << 3 << std::endl;

    EXPECT_EQ(flujo.str(), esperado.str());
}

TEST(EpisodioTest5, ProbarAgregarCalificacionErronea){
    Episodio e("Jamaica",3);
    EXPECT_THROW(e.AgregarCalificacionEpisodio(-23), const char*);
}

