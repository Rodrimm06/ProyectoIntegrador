#include <gtest/gtest.h>
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"
#include <gtest/gtest.h>
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"

TEST(VideoTest1, ConstructorGeneroValido) {
    EXPECT_NO_THROW(Serie s(1, "Nombre", 50, "Misterio"));
    EXPECT_NO_THROW(Pelicula p(2, "Nombre", 50, "Accion"));
    EXPECT_NO_THROW(Serie s2(3, "Nombre", 50, "Drama"));
}

TEST(VideoTest2, ConstructorGeneroInvalidoLanzaExcepcion) {
    EXPECT_THROW(Serie s(4, "Nombre", 50, "Comedia"), const char*);
    EXPECT_THROW(Pelicula p(5, "Nombre", 50, "Romance"), const char*);
}

TEST(VideoTest3, ConstructorDuracionValida) {
    EXPECT_NO_THROW(Serie s(6, "Nombre", 10, "Misterio"));
}

TEST(VideoTest4, ConstructorDuracionInvalidaLanzaExcepcion) {
    EXPECT_THROW(Pelicula p(7, "Nombre", 0, "Misterio"), const char*);
    EXPECT_THROW(Serie s(8, "Nombre", -5, "Accion"), const char*);
}

TEST(VideoTest5, AgregarCalificacionValida) {
    Serie s(100, "Serie Test", 120, "Misterio");
    EXPECT_NO_THROW(s.AgregarCalificacion(3));
    EXPECT_NO_THROW(s.AgregarCalificacion(1));
    EXPECT_NO_THROW(s.AgregarCalificacion(5));
}

TEST(VideoTest6, AgregarCalificacionInvalidaLanzaExcepcion) {
    Pelicula p(101, "Pelicula Test", 90, "Accion");
    EXPECT_THROW(p.AgregarCalificacion(0), const char*);
    EXPECT_THROW(p.AgregarCalificacion(6), const char*);
    EXPECT_THROW(p.AgregarCalificacion(-1), const char*);
    EXPECT_THROW(p.AgregarCalificacion(10), const char*);
}
