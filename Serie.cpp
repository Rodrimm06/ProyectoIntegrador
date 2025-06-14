
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Serie.h"

// Constructor
Serie::Serie(int id_, const std::string& nombre_, double duracion_, const std::string& genero_)
    : Video(id_, nombre_, duracion_, genero_) {
    // Validación ya hecha en Video
}

// Para agregar episodios
void Serie::AgregarEpisodio(const Episodio& episodio) {
    episodios.push_back(episodio);
}

// Para visualizar todos los episodios
void Serie::MostrarEpisodios() const {
    for (int i = 0; i < (int)episodios.size(); i++) {
        std::cout << episodios[i];
    }
}

// Se calcula el promedio de todos los episodios de la serie y es el que se devuelve
double Serie::CalcularPromedio() const {
    if (episodios.empty()) throw "No hay episodios para calcular promedio";
    
    double promedio = 0;
    int contador = 0;
    for (int i = 0; i < (int)episodios.size(); i++) {
        double epPromedio = episodios[i].CalcularPromedioEpisodio();
        promedio += epPromedio;
        contador++;
    }
    if (contador == 0) throw "No hay calificaciones para calcular promedio";
    
    return promedio / contador;
}

// Funcion de mostrar
void Serie::Mostrar() const {
    std::cout << "Serie: " << GetNombre() << std::endl
              << "Duracion: " << GetDuracion() << std::endl
              << "Genero: " << GetGenero() << std::endl
              << "ID: " << GetId() << std::endl;

    std::cout << "Calificacion Promedio: " << CalcularPromedio() << std::endl;
    std::cout << "Episodios:" << std::endl;

    MostrarEpisodios();
}

// Sobrecarga de operador para mayor eficiencia
std::ostream& operator<<(std::ostream& os, const Serie& serie) {
    os << "Serie: " << serie.GetNombre() << std::endl
       << "Duracion: " << serie.GetDuracion() << std::endl
       << "Genero: " << serie.GetGenero() << std::endl
       << "ID: " << serie.GetId() << std::endl;

    os << "Calificacion Promedio: " << serie.CalcularPromedio() << std::endl;
    os << "Episodios:" << std::endl;

    for (int i = 0; i < (int)serie.GetEpisodios().size(); i++) {
        os << serie.GetEpisodios()[i];
    }
    return os;
}
