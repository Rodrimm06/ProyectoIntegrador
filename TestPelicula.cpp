#include <gtest/gtest.h>
#include "Pelicula.h"

TEST(Pelicula, ConstructorYSetGet)
{
Pelicula p("El cardenal",159,"Drama")
    EXPECT_EQ(p.getTitulo(), "El cardenal");
    EXPECT_EQ(p.getDuracion(), 159);
    EXPECT_EQ(p.getGenero(), "Drama");
}

TEST(DivTest, HandlesZeroInput)
{
int result = divide(9, 0);

EXPECT_EQ(result, 0);
}
