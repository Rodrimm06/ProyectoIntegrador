#include <gtest/gtest.h>
#include "Serie.h"
#include "Episodio.h"

TEST(SerieTest1, ConstructorYSetGet)
{
    Serie s(11182,"Historias de noche",2098,"Misterio");
    EXPECT_EQ(s.getNombre(), "Historias de noche");
    EXPECT_EQ(s.getDuracion(), 2098);
    EXPECT_EQ(s.getGenero(), "Misterio");
}

TEST(SerieTest2, ProbarCalcularPromedio)
{
    Serie s(1432, "Historias de terror", 100, "Misterio");
    Episodio e1("Intro", 1);
    Episodio e2("Final", 2);
    e1.agregarCalificacion(5);
    e2.agregarCalificacion(3);
    s.agregarEpisodio(e1);
    s.agregarEpisodio(e2);
    EXPECT_EQ(s.calcularPromedio(), 4); // (5 + 3) / 2
}

TEST(SerieTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Serie s(1432,"Sin ti", 200, "Drama");
    EXPECT_THROW(s.calcularPromedio(), const char*);
}

TEST(SerieTest4, ProbarMetodoMostrar) {
    Serie s(1001, "Cosas extrañas", 45, "Misterio");

    Episodio e1("El principio", 1);
    e1.agregarCalificacion(4);
    Episodio e2("El medio", 2);
    e2.agregarCalificacion(5);
    Episodio e3("El final", 3);
    e3.agregarCalificacion(3);

    s.agregarEpisodio(e1);
    s.agregarEpisodio(e2);
    s.agregarEpisodio(e3);

    std::stringstream buffer;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    s.mostrar();

    std::cout.rdbuf(originalCout);

    std::stringstream esperado;
    esperado << "Serie: " << s.getNombre() << std::endl
             << "Duracion: " << s.getDuracion() << std::endl
             << "Genero: " << s.getGenero() << std::endl
             << "ID: " << s.getId() << std::endl
             << "Calificacion Promedio: " << s.calcularPromedio() << std::endl
             << "Episodios:" << std::endl;

    for (int i = 0; i < s.getEpisodios().size(); i++) {
        const auto& episodio = s.getEpisodios()[i];
        esperado << "Episodio: " << episodio.getNombre() << std::endl
                << "Temporada: " << episodio.getTemporada() << std::endl
                << "Calificacion Promedio: " << episodio.calcularPromedioEpisodio() << std::endl;
    }

    EXPECT_EQ(buffer.str(), esperado.str());
}




TEST(SerieTest5, ProbarErrorDelConstructor)
{
    EXPECT_THROW(Serie s(9224,"Los misterios de Albert", -12,"Misterio"), const char*);
}

TEST(SerieTest6, ProbarErrorGenero)
{
    EXPECT_THROW(Serie s(9224,"Los policias", 93,"Crimen"), const char*);
}

TEST(SerieTest7, ProbarAgregarEpisodio)
{
    Serie s(5522,"La granja",108,"Misterio");
    Episodio e("El puerco",1);
    e.agregarCalificacion(3);
    s.agregarEpisodio(e);
    EXPECT_EQ(s.calcularPromedio(),3);
}

TEST(SerieTest8, ProbarGetSet)
{
    Serie s(5522,"La granja",108,"Misterio");
    s.setNombre("La cabaña");
    s.setDuracion(20);
    s.setGenero("Drama");
    s.setId(144);
    EXPECT_EQ(s.getNombre(),"La cabaña");
    EXPECT_EQ(s.getDuracion(),20);
    EXPECT_EQ(s.getGenero(),"Drama");
    EXPECT_EQ(s.getId(),144);
}

