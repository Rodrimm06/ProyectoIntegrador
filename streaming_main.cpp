
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

void mostrar_genero(const std::vector<Video*>& videos, const std::string& generoBuscado) {
    std::cout << "Videos del genero: " << generoBuscado << std::endl;
    for (int i = 0; i < size(videos); i++) {
        if (videos[i]->GetGenero() == generoBuscado) {
            videos[i]->Mostrar();
            std::cout << std::endl;
        }
    }
}

int main()
{
        std::vector<Video*> videos;

        // Crear y agregar una película
        Pelicula* peli = new Pelicula(1, "Fast and furious", 148, "Accion");
        peli->AgregarCalificacion(5);
        videos.push_back(peli);

        // Crear episodios para la serie
        Episodio ep1("Pilot", 1);
        ep1.AgregarCalificacionEpisodio(4);

        // Crear una serie y agregar episodios
        Serie* serie = new Serie(2, "One drama story", 10.0, "Drama");
        serie->AgregarEpisodio(ep1);

        // Agregar calificaciones directamente a la serie
        serie->AgregarCalificacion(5);

        videos.push_back(serie);

        // Mostrar todos los videos usando polimorfismo
        for (Video* video : videos) {
            video->Mostrar();
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

        // Probar funcion de mostrar por genero
        std::cout << std::endl;
        mostrar_genero(videos, "Drama");

        // Liberar memoria
        for (Video* video : videos) {
            delete video;
        }
        videos.clear();
    
   
}

