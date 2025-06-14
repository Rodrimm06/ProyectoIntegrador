TEST(VideoTest1, ConstructorGeneroValido) {
    EXPECT_NO_THROW(Video v(1, "Nombre", 50, "Misterio"));
    EXPECT_NO_THROW(Video v(2, "Nombre", 50, "Accion"));
    EXPECT_NO_THROW(Video v(3, "Nombre", 50, "Drama"));
}

TEST(VideoTest2, ConstructorGeneroInvalidoLanzaExcepcion) {
    EXPECT_THROW(Video v(4, "Nombre", 50, "Comedia"), const char*);
    EXPECT_THROW(Video v(5, "Nombre", 50, "Romance"), const char*);
}

TEST(VideoTest3, ConstructorDuracionValida) {
    EXPECT_NO_THROW(Video v(6, "Nombre", 10, "Misterio"));
}

TEST(VideoTest4, ConstructorDuracionInvalidaLanzaExcepcion) {
    EXPECT_THROW(Video v(7, "Nombre", 0, "Misterio"), const char*);
    EXPECT_THROW(Video v(8, "Nombre", -5, "Accion"), const char*);
}
