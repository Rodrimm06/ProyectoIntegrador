#include <gtest/gtest.h>
#include "Pelicula.h"

TEST(PeliculaTest1, ConstructorYSetGet)
{
Pelicula p("El cardenal",159,"Drama")
    EXPECT_EQ(p.getTitulo(), "El cardenal");
    EXPECT_EQ(p.getDuracion(), 159);
    EXPECT_EQ(p.getGenero(), "Drama");
    
}

TEST(PeliculaTest2, ProbarCalcularPromedio)
{
    Pelicula p("El marciano", 165, "Misterio");
    p.agregarCalificacion(4);
    p.agregarCalificacion(5);

    EXPECT_DOUBLE_EQ(p.calcularPromedio(), 4.5);

}
TEST(PeliculaTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Pelicula p("El marciano", 100, "Drama");
    EXPECT_THROW(p.calcularPromedio(), const char*);
}
