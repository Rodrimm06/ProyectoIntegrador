#include <gtest/gtest.h>
#include "Pelicula.h"

TEST(PeliculaTest1, ConstructorYSetGet)
{
Pelicula p(11182,"El cardenal",159,"Drama");
    EXPECT_EQ(p.GetNombre(), "El cardenal");
    EXPECT_EQ(p.GetDuracion(), 159);
    EXPECT_EQ(p.GetGenero(), "Drama");
    
}

TEST(PeliculaTest2, ProbarCalcularPromedio)
{
    Pelicula p(342,"El marciano", 165, "Misterio");
    p.AgregarCalificacion(4);
    p.AgregarCalificacion(5);

    EXPECT_DOUBLE_EQ(p.CalcularPromedio(), 4.5);

}

TEST(PeliculaTest3, PromedioSinCalificacionesLanzaExcepcion) {
    Pelicula p(9024,"El marciano 2", 100, "Drama");
    EXPECT_THROW(p.CalcularPromedio(), const char*);
}

TEST(PeliculaTest4, ProbarMetodoMostrar) {
    Pelicula p(1342, "El cardenal", 159, "Drama");
    // Agregar calificaciones
    p.AgregarCalificacion(4);
    p.AgregarCalificacion(5);

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    p.Mostrar(); 

    std::cout.rdbuf(oldCout);

    std::stringstream esperado;
    esperado << "Pelicula: " << p.GetNombre() << std::endl
             << "Duracion: " << p.GetDuracion() << std::endl
             << "Genero: " << p.GetGenero() << std::endl
             << "ID: " << p.GetId() << std::endl
             << "Calificacion Promedio: " << p.CalcularPromedio() << std::endl;

    EXPECT_EQ(buffer.str(), esperado.str());
}

TEST(PeliculaTest5, ProbarErrorDelConstructor){
	EXPECT_THROW(Pelicula p(9224,"El animalito", -12,"Misterio"), const char*);
}

TEST(PeliculaTest6, ProbarErrorGenero){
	EXPECT_THROW(Pelicula p(9224,"El juguete bailarin", 93,"Niños"), const char*);
}
TEST(PeliculaTest7, ProbarAgregrarCalificacionErronea){
		Pelicula p(5522,"La granja",108,"Misterio");
		EXPECT_THROW(p.AgregarCalificacion(-23),const char*);
	}
TEST(PeliculaTest8, ProbarGetSet){
		Pelicula p(5522,"La granja",108,"Misterio");
		p.SetNombre("El campo");
		p.SetDuracion(200);
		p.SetGenero("Drama");
		p.SetId(1244);
		EXPECT_EQ(p.GetNombre(),"El campo");
		EXPECT_EQ(p.GetDuracion(),200);
		EXPECT_EQ(p.GetGenero(),"Drama");
		EXPECT_EQ(p.GetId(),1244);
	}

TEST(PeliculaTest9, AgregarCalificacionMayorQueMax) {
    Pelicula p(1234, "Test", 100, "Drama");
    EXPECT_THROW(p.AgregarCalificacion(7), const char*);
}

TEST(PeliculaTest10, AgregarCalificacionesEnLimites) {
    Pelicula p(4321, "Test Limites", 90, "Accion");
    p.AgregarCalificacion(1);
    p.AgregarCalificacion(5);
    EXPECT_DOUBLE_EQ(p.CalcularPromedio(), 3.0);
}

TEST(PeliculaTest11, MostrarSinCalificaciones) {
    Pelicula p(5678, "El cohete", 120, "Drama");
   EXPECT_THROW(p.Mostrar(),const char*);
}

TEST(PeliculaTest12, MultiplesCalificaciones) {
    Pelicula p(6789, "El Oso", 110, "Accion");
    for (int i = 1; i <= 5; ++i) {
        p.AgregarCalificacion(i);
    }
    EXPECT_DOUBLE_EQ(p.CalcularPromedio(), 3.0);
}
TEST(PeliculaTest13, OperadorStreamOutCompleto) {
    Pelicula p(1001, "El Gran Viaje", 120, "Accion");
    p.AgregarCalificacion(4);
    p.AgregarCalificacion(5); // promedio 4.5

    std::stringstream buffer;
    buffer << p;

    std::stringstream esperado;
    esperado << "Pelicula: El Gran Viaje" << std::endl
             << "Duracion: 120" << std::endl
             << "Genero: Accion" << std::endl
             << "ID: 1001" << std::endl
             << "Calificacion Promedio: 4.5" << std::endl;

    EXPECT_EQ(buffer.str(), esperado.str());
}
TEST(PeliculaTest14, MostrarCompleto) {
    Pelicula p(2002, "Drama Interno", 90, "Drama");
    p.AgregarCalificacion(3);
    p.AgregarCalificacion(4); // promedio 3.5

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); // redirige cout

    p.Mostrar();

    std::cout.rdbuf(oldCout); // restaura cout

    std::stringstream esperado;
    esperado << "Pelicula: Drama Interno" << std::endl
             << "Duracion: 90" << std::endl
             << "Genero: Drama" << std::endl
             << "ID: 2002" << std::endl
             << "Calificacion Promedio: 3.5" << std::endl;

    EXPECT_EQ(buffer.str(), esperado.str());
}


