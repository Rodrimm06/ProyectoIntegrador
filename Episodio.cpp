
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Episodio.h"
// Constructor
Episodio::Episodio(const std::string& nombre_, int temporada_) :
    nombre(nombre_), temporada(temporada_) {
    if (temporada <= 0) {
        throw "Error, numero de temporada invalido";
    }
}
// Se hace la funcion mostrar para ver la informacion de cada episodio
void Episodio::MostrarEpisodio() const {
    std::cout << "Episodio: " << std::endl << "Nombre: " << nombre << std::endl <<
        "Temporada: " << temporada << std::endl << "Calificacion Promedio: " << CalcularPromedioEpisodio() << std::endl;
}
// Funcion para agregar una calificacion al vector de calificaciones
void Episodio::AgregarCalificacionEpisodio(int cali) {
    // Se asegura que la calificacion este dentro del rango
    if (cali > 0 && cali < 6) {
        calificaciones.push_back(cali);
    }
    else {
        throw "Error, calificacion fuera de rango";
    }
}
// Para calcular el promedio de calificaciones
double Episodio::CalcularPromedioEpisodio() const {
    double promedio = 0;
    // For para recorrer el vector de calificaciones
    for (int i = 0; i < calificaciones.size(); i++) {
        promedio = promedio + calificaciones[i];
    }
    // Se verifica que no se divida entre cero
    if (calificaciones.size() > 0) {
        return promedio / calificaciones.size();
    }
    else {
        throw "Error, no se puede promediar sin calificaciones";
    }

}
// Se sobrecarga el operador para mayor comodidad y mas dinamismo
std::ostream& operator<<(std::ostream& os, const Episodio& episodio) {
    os << "Episodio: " << episodio.nombre << std::endl<< "Temporada: " << episodio.temporada << std::endl<<
        "Calificacion Promedio: " << episodio.CalcularPromedioEpisodio() << std::endl;
    return os;
}
