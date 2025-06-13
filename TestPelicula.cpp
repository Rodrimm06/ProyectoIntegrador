#include <gtest/gtest.h>
#include "Pelicula.h"

TEST(PeliculaTest1, ConstructorYSetGet)
{
Pelicula p(11182,"El cardenal",159,"Drama")
    EXPECT_EQ(p.getTitulo(), "El cardenal");
    EXPECT_EQ(p.getDuracion(), 159);
    EXPECT_EQ(p.getGenero(), "Drama");
    
}

TEST(PeliculaTest2, ProbarCalcularPromedio)
{
    Pelicula p(342,"El marciano", 165, "Misterio");
    p.agregarCalificacion(4);
    p.agregarCalificacion(5);

    EXPECT_DOUBLE_EQ(p.calcularPromedio(), 4.5);

}

TEST(PeliculaTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Pelicula p(9024,"El marciano 2", 100, "Drama");
    EXPECT_THROW(p.calcularPromedio(), const char*);
}

TEST(PeliculaTest4, ProbarMetodoMostrar){
    Pelicula p(1342,"El cardenal",159,"Drama");
    std::stringstream flujo;

    p.mostrar(flujo);

    std::string esperado;
    esperado<<"Pelicula: " << p.getNombre() << std::endl <<
	"Duracion: " << p.getDuracion() << std::endl <<
	"Genero: " << p.getGenero() << std::endl <<
	"ID: " << p.getId() << std::endl <<
	"Calificacion Promedio: " << p.calcularPromedio() << std::endl;
    EXPECT_EQ(flujo.str(), esperado);
}
