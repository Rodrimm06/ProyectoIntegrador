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
    Serie s(1432, "Historias de terror", 100, "Terror");
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
    // Crear la serie
    Serie s(1001, "Cosas extrañas", 45, "Suspenso");

    // Agregar episodios
    s.agregarEpisodio(Episodio("El principio", 1));
    s.agregarEpisodio(Episodio("El medio", 2));
    s.agregarEpisodio(Episodio("El final", 3));

    // Redirigir std::cout a un stringstream
    std::stringstream buffer;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    // Llamar a mostrar()
    s.mostrar();

    // Restaurar std::cout
    std::cout.rdbuf(originalCout);

    // Crear salida esperada
    std::stringstream esperado;
    esperado << "Serie: " << s.getNombre() << std::endl
             << "Duracion: " << s.getDuracion() << std::endl
             << "Genero: " << s.getGenero() << std::endl
             << "ID: " << s.getId() << std::endl
             << "Episodios:" << std::endl;

    for (const auto& episodio : s.getEpisodios()) {
        esperado << "  Titulo: " << episodio.getTitulo() << std::endl;
        esperado << "  Temporada: " << episodio.getTemporada() << std::endl;
    }

    // Comparar la salida
    EXPECT_EQ(buffer.str(), esperado.str());
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

