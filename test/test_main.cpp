#include <gtest/gtest.h>
#include <sstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "streaming_main.cpp" 

TEST(MainTest1, CrearVideosEjemplo) {
    std::vector<Video*> videos;

    // Crear película
    Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
    peli->AgregarCalificacion(5);
    peli->AgregarCalificacion(4);
    videos.push_back(peli);

    // Crear episodios
    Episodio ep1("Pilot", 1);
    ep1.AgregarCalificacionEpisodio(4);
    ep1.AgregarCalificacionEpisodio(5);

    Episodio ep2("Second Episode", 1);
    ep2.AgregarCalificacionEpisodio(3);
    ep2.AgregarCalificacionEpisodio(4);

    Episodio ep3("Third Episode", 1);
    ep3.AgregarCalificacionEpisodio(5);
    ep3.AgregarCalificacionEpisodio(5);

    // Crear serie y agregar episodios
    Serie* serie = new Serie(2, "One drama story", 10, "Drama");
    serie->AgregarEpisodio(ep1);
    serie->AgregarEpisodio(ep2);
    serie->AgregarEpisodio(ep3);
    serie->AgregarCalificacion(5);
    serie->AgregarCalificacion(4);
    videos.push_back(serie);

    EXPECT_EQ(videos.size(), 2);

    // Liberar memoria
    for (Video* v : videos) {
        delete v;
    }
}

TEST(MainTest2, MostrarTodosLosVideos) {
    std::vector<Video*> videos;

    Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
    peli->AgregarCalificacion(5);
    peli->AgregarCalificacion(4);
    videos.push_back(peli);

    Episodio ep1("Pilot", 1);
    ep1.AgregarCalificacionEpisodio(4);
    ep1.AgregarCalificacionEpisodio(5);

    Episodio ep2("Second Episode", 1);
    ep2.AgregarCalificacionEpisodio(3);
    ep2.AgregarCalificacionEpisodio(4);

    Episodio ep3("Third Episode", 1);
    ep3.AgregarCalificacionEpisodio(5);
    ep3.AgregarCalificacionEpisodio(5);

    Serie* serie = new Serie(2, "One drama story", 10, "Drama");
    serie->AgregarEpisodio(ep1);
    serie->AgregarEpisodio(ep2);
    serie->AgregarEpisodio(ep3);
    serie->AgregarCalificacion(5);
    serie->AgregarCalificacion(4);
    videos.push_back(serie);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    for (Video* video : videos) {
        video->Mostrar();
    }

    std::cout.rdbuf(old);

    std::string salida = buffer.str();
    EXPECT_NE(salida.find("Fast and furious"), std::string::npos);
    EXPECT_NE(salida.find("One drama story"), std::string::npos);

    for (Video* v : videos) {
        delete v;
    }
}

TEST(MainTest3, OperadorSalidaConDynamicCast) {
    std::vector<Video*> videos;

    Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
    peli->AgregarCalificacion(5);
    peli->AgregarCalificacion(4);
    videos.push_back(peli);

    Episodio ep1("Pilot", 1);
    ep1.AgregarCalificacionEpisodio(4);
    ep1.AgregarCalificacionEpisodio(5);

    Episodio ep2("Second Episode", 1);
    ep2.AgregarCalificacionEpisodio(3);
    ep2.AgregarCalificacionEpisodio(4);

    Episodio ep3("Third Episode", 1);
    ep3.AgregarCalificacionEpisodio(5);
    ep3.AgregarCalificacionEpisodio(5);

    Serie* serie = new Serie(2, "One drama story", 10, "Drama");
    serie->AgregarEpisodio(ep1);
    serie->AgregarEpisodio(ep2);
    serie->AgregarEpisodio(ep3);
    serie->AgregarCalificacion(5);
    serie->AgregarCalificacion(4);
    videos.push_back(serie);

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

    for (Video* v : videos) {
        delete v;
    }
}

TEST(MainTest4, MostrarGenero) {
    std::vector<Video*> videos;

    Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
    peli->AgregarCalificacion(5);
    peli->AgregarCalificacion(4);
    videos.push_back(peli);

    Episodio ep1("Pilot", 1);
    ep1.AgregarCalificacionEpisodio(4);
    ep1.AgregarCalificacionEpisodio(5);

    Episodio ep2("Second Episode", 1);
    ep2.AgregarCalificacionEpisodio(3);
    ep2.AgregarCalificacionEpisodio(4);

    Episodio ep3("Third Episode", 1);
    ep3.AgregarCalificacionEpisodio(5);
    ep3.AgregarCalificacionEpisodio(5);

    Serie* serie = new Serie(2, "One drama story", 10, "Drama");
    serie->AgregarEpisodio(ep1);
    serie->AgregarEpisodio(ep2);
    serie->AgregarEpisodio(ep3);
    serie->AgregarCalificacion(5);
    serie->AgregarCalificacion(4);
    videos.push_back(serie);

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

    for (Video* v : videos) {
        delete v;
    }
}

TEST(MainTest5, LiberarVideos) {
    std::vector<Video*> videos;

    Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
    peli->AgregarCalificacion(5);
    peli->AgregarCalificacion(4);
    videos.push_back(peli);

    Episodio ep1("Pilot", 1);
    ep1.AgregarCalificacionEpisodio(4);
    ep1.AgregarCalificacionEpisodio(5);

    Episodio ep2("Second Episode", 1);
    ep2.AgregarCalificacionEpisodio(3);
    ep2.AgregarCalificacionEpisodio(4);

    Episodio ep3("Third Episode", 1);
    ep3.AgregarCalificacionEpisodio(5);
    ep3.AgregarCalificacionEpisodio(5);

    Serie* serie = new Serie(2, "One drama story", 10, "Drama");
    serie->AgregarEpisodio(ep1);
    serie->AgregarEpisodio(ep2);
    serie->AgregarEpisodio(ep3);
    serie->AgregarCalificacion(5);
    serie->AgregarCalificacion(4);
    videos.push_back(serie);

    // Simular liberar videos
    for (Video* v : videos) {
        delete v;
    }
    videos.clear();

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
    double promedio = ep.CalcularPromedioEpisodio(); 
    EXPECT_DOUBLE_EQ(promedio, 4.5);
}

