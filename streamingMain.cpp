
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include "Pelicula.h"
#include "Serie.h"
void mostrarPorGenero(const std::vector<Video*>& videos, const std::string& generoBuscado) {
    std::cout << "Videos del genero: " << generoBuscado << std::endl;
    for (int i = 0;i<size(videos);i++) {
        if (videos[i]->getGenero() == generoBuscado) {
            videos[i]->mostrar();
            std::cout << std::endl;
        }
    }
}

int main()
{
    // Para el manejo de errores
    try {
        std::vector<Video*> videos;

        // Crear y agregar una película
        Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
        peli->agregarCalificacion(5);
        peli->agregarCalificacion(4);
        videos.push_back(peli);

        // Crear episodios para la serie
        Episodio ep1("Pilot", 1);
        ep1.agregarCalificacion(4);
        ep1.agregarCalificacion(5);

        Episodio ep2("Second Episode", 1);
        ep2.agregarCalificacion(3);
        ep2.agregarCalificacion(4);

        Episodio ep3("Third Episode", 1);
        ep3.agregarCalificacion(5);
        ep3.agregarCalificacion(5);

        // Crear una serie y agregar episodios
        Serie* serie = new Serie(2, "One drama story", 10.0, "Drama");
        serie->agregarEpisodio(ep1);
        serie->agregarEpisodio(ep2);
        serie->agregarEpisodio(ep3);

        // También podemos agregar calificaciones directamente a la serie
        serie->agregarCalificacion(5);
        serie->agregarCalificacion(4);

        videos.push_back(serie);

        // Mostrar todos los videos usando polimorfismo
        for (Video* video : videos) {
            video->mostrar();
        }

        // Usar la sobrecarga de operador <<
        for (Video* video : videos) {
            // Intentar hacer cast para llamar operador <<
            if (Pelicula* p = dynamic_cast<Pelicula*>(video)) {
                std::cout << *p;
            }
            else if (Serie* s = dynamic_cast<Serie*>(video)) {
                std::cout << *s;
            }
        }
        //Probar funcion de mostrar por genero
        std::cout << std::endl;
        mostrarPorGenero(videos, "Drama");
        // Liberar memoria
        for (Video* video : videos) {
            delete video;
        }
        videos.clear();
    }
    catch (const char* msg) {
        std::cerr<<msg<<std::endl;
    }
}
