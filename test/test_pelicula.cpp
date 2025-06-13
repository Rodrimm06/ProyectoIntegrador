#include <gtest/gtest.h>
#include "Pelicula.h"

TEST(PeliculaTest1, ConstructorYSetGet)
{
Pelicula p(11182,"El cardenal",159,"Drama");
    EXPECT_EQ(p.getNombre(), "El cardenal");
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

    std::stringstream esperado;
    esperado<<"Pelicula: " << p.getNombre() << std::endl <<
	"Duracion: " << p.getDuracion() << std::endl <<
	"Genero: " << p.getGenero() << std::endl <<
	"ID: " << p.getId() << std::endl <<
	"Calificacion Promedio: " << p.calcularPromedio() << std::endl;
    EXPECT_EQ(flujo.str(), esperado.str());
}

TEST(PeliculaTest5, ProbarErrorDelConstructor){
	EXPECT_THROW({Pelicula p(9224,"El animalito", -12,"Misterio")}, const char*);
}

TEST(PeliculaTest6, ProbarErrorGenero){
	EXPECT_THROW(Pelicula p(9224,"El juguete bailarin", 93,"Niños"), const char*);
}
TEST(PeliculaTest7, ProbarAgregrarCalificacionErronea){
		Pelicula p(5522,"La granja",108,"Misterio");
		EXPECT_THROW(p.agregarCalificacion(-23),const char*);
	}
TEST(PeliculaTest8, ProbarGetSet){
		Pelicula p(5522,"La granja",108,"Misterio");
		p.setNombre("El campo");
		p.setDuracion(200);
		p.setGenero("Drama");
		p.setId(1244);
		EXPECT_EQ(p.getNombre(),"El campo");
		EXPECT_EQ(p.getDuracion(),200);
		EXPECT_EQ(p.getGenero(),"Drama");
		EXPECT_EQ(p.getId(),1244);
	}
