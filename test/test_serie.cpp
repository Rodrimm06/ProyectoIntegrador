#include <gtest/gtest.h>
#include "Serie.h"
#include "Episodio.h"

TEST(SerieTest1, ConstructorYSetGet)
{
    Serie s(11182,"Historias de noche",2098,"Misterio");
    EXPECT_EQ(s.GetNombre(), "Historias de noche");
    EXPECT_EQ(s.GetDuracion(), 2098);
    EXPECT_EQ(s.GetGenero(), "Misterio");
}

TEST(SerieTest2, ProbarCalcularPromedio)
{
    Serie s(1432, "Historias de terror", 100, "Misterio");
    Episodio e1("Intro", 1);
    Episodio e2("Final", 2);
    e1.AgregarCalificacionEpisodio(5);
    e2.AgregarCalificacionEpisodio(3);
    s.AgregarEpisodio(e1);
    s.AgregarEpisodio(e2);
    EXPECT_EQ(s.CalcularPromedio(), 4); // (5 + 3) / 2
}

TEST(SerieTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Serie s(1432,"Sin ti", 200, "Drama");
    EXPECT_THROW(s.CalcularPromedio(), const char*);
}

TEST(SerieTest4, ProbarMetodoMostrar) {
    Serie s(1001, "Cosas extrañas", 45, "Misterio");

    Episodio e1("El principio", 1);
    e1.AgregarCalificacionEpisodio(4);
    Episodio e2("El medio", 2);
    e2.AgregarCalificacionEpisodio(5);
    Episodio e3("El final", 3);
    e3.AgregarCalificacionEpisodio(3);

    s.AgregarEpisodio(e1);
    s.AgregarEpisodio(e2);
    s.AgregarEpisodio(e3);

    std::stringstream buffer;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    s.Mostrar();

    std::cout.rdbuf(originalCout);

    std::stringstream esperado;
    esperado << "Serie: " << s.GetNombre() << std::endl
             << "Duracion: " << s.GetDuracion() << std::endl
             << "Genero: " << s.GetGenero() << std::endl
             << "ID: " << s.GetId() << std::endl
             << "Calificacion Promedio: " << s.CalcularPromedio() << std::endl
             << "Episodios:" << std::endl;

    for (int i = 0; i < s.GetEpisodios().size(); i++) {
        const auto& episodio = s.GetEpisodios()[i];
        esperado << "Episodio: " << episodio.GetNombre() << std::endl
                << "Temporada: " << episodio.GetTemporada() << std::endl
                << "Calificacion Promedio: " << episodio.CalcularPromedioEpisodio() << std::endl;
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
    e.AgregarCalificacionEpisodio(3);
    s.AgregarEpisodio(e);
    EXPECT_EQ(s.CalcularPromedio(),3);
}

TEST(SerieTest8, ProbarGetSet)
{
    Serie s(5522,"La granja",108,"Misterio");
    s.SetNombre("La cabaña");
    s.SetDuracion(20);
    s.SetGenero("Drama");
    s.SetId(144);
    EXPECT_EQ(s.GetNombre(),"La cabaña");
    EXPECT_EQ(s.GetDuracion(),20);
    EXPECT_EQ(s.GetGenero(),"Drama");
    EXPECT_EQ(s.GetId(),144);
}

TEST(SerieTest9, ProbarOperadorStreamOut) {
    Serie s(9876, "Ciencia Extrema", 60, "Documental");

    std::stringstream buffer;
    buffer << s;  // Aquí se usa operator<<

    std::stringstream esperado;
    esperado << "Serie: " << s.GetNombre() << std::endl
             << "Duracion: " << s.GetDuracion() << std::endl
             << "Genero: " << s.GetGenero() << std::endl
             << "ID: " << s.GetId() << std::endl;

    EXPECT_EQ(buffer.str(), esperado.str());
}

