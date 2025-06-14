#include <gtest/gtest.h>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "streaming_main.cpp"
TEST(MainTest1, CrearVideosEjemplo) {
    std::vector<Video*> videos;
    EXPECT_NO_THROW(videos = crearVideosEjemplo());
    EXPECT_EQ(videos.size(), 2);  // Una película y una serie
}

TEST(MainTest2, MostrarTodosLosVideos) {
    std::vector<Video*> videos = crearVideosEjemplo();

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    for (Video* video : videos) {
        video->Mostrar();
    }

    std::cout.rdbuf(old);

    std::string salida = buffer.str();
    EXPECT_NE(salida.find("Fast and furious"), std::string::npos);
    EXPECT_NE(salida.find("One drama story"), std::string::npos);

}

TEST(MainTest3, OperadorSalidaConDynamicCast) {
    std::vector<Video*> videos = crearVideosEjemplo();

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    for (Video* video : videos) {
        if (Pelicula* p = dynamic_cast<Pelicula*>(video)) {
            std::cout << *p;
        } else if (Serie* s = dynamic_cast<Serie*>(video)) {
            std::cout << *s;
        }
    }

    std::cout.rdbuf(old);

    std::string salida = buffer.str();
    EXPECT_NE(salida.find("Fast and furious"), std::string::npos);
    EXPECT_NE(salida.find("One drama story"), std::string::npos);

}

TEST(MainTest4, MostrarGenero) {
    std::vector<Video*> videos = crearVideosEjemplo();

    {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        mostrar_genero(videos, "Drama");

        std::cout.rdbuf(old);
        std::string salida = buffer.str();

        EXPECT_NE(salida.find("Videos del genero: Drama"), std::string::npos);
        EXPECT_NE(salida.find("One drama story"), std::string::npos);
        EXPECT_EQ(salida.find("Fast and furious"), std::string::npos);
    }

    {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        mostrar_genero(videos, "Comedia");

        std::cout.rdbuf(old);
        std::string salida = buffer.str();

        EXPECT_NE(salida.find("Videos del genero: Comedia"), std::string::npos);
        EXPECT_EQ(salida.find("Fast and furious"), std::string::npos);
        EXPECT_EQ(salida.find("One drama story"), std::string::npos);
    }

}

TEST(MainTest5, LiberarVideos) {
    std::vector<Video*> videos = crearVideosEjemplo();
    liberarVideos(videos);
    EXPECT_EQ(videos.size(), 0);
}

TEST(MainTest6, AgregarCalificacionInvalida) {
    Pelicula peli(10, "Test Pelicula", 120, "Accion");
    Serie serie(11, "Test Serie", 20, "Drama");

    EXPECT_THROW(peli.AgregarCalificacion(0), const char*);
    EXPECT_THROW(peli.AgregarCalificacion(6), const char*);
    EXPECT_THROW(serie.AgregarCalificacion(-1), const char*);
    EXPECT_THROW(serie.AgregarCalificacion(10), const char*);
}

TEST(MainTest7, SerieSinEpisodiosMostrar) {
    Serie serie(12, "Serie sin episodios", 15, "Accion");
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    serie.Mostrar();
    std::cout.rdbuf(old);
    std::string salida = buffer.str();
    EXPECT_NE(salida.find("Serie sin episodios"), std::string::npos);
}

TEST(MainTest8, EpisodioCalificaciones) {
    Episodio ep("Test Episodio", 1);
    ep.AgregarCalificacionEpisodio(4);
    ep.AgregarCalificacionEpisodio(5);
    double promedio = ep.calcularPromedio();
    EXPECT_DOUBLE_EQ(promedio, 4.5);
}
