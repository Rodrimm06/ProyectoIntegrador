
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Video.h"

// Constructor
Video::Video(int id_, const std::string& nombre_, double duracion_, const std::string& genero_)
    : id(id_), nombre(nombre_), duracion(duracion_), genero(genero_) {
    if (genero != "Misterio" && genero != "Accion" && genero != "Drama") {
        throw "Error, genero no reconocido";
    }
    if (duracion <= 0) {
        throw "Error, duracion invalida";
    }
}

// Funcion para agregar una calificacion al vector
void Video::AgregarCalificacion(int cali) {
    if (cali > 0 && cali < 6) {
        calificaciones.push_back(cali);
    } else {
        throw "Error, calificacion fuera de rango";
    }
}

// Funcion para calcular el promedio
double Video::CalcularPromedio() const {
    double promedio = 0;
    // For para recorrer el vector de calificaciones
    for (int i = 0; i < calificaciones.size(); i++) {
        promedio = promedio + calificaciones[i];
    }
    if (calificaciones.size() > 0) {
        return promedio / calificaciones.size();
    } else {
        throw "Error, no se puede promediar sin calificaciones";
    }
}

// Funciones set/get
void Video::SetId(int id_) {
    id = id_;
}
void Video::SetNombre(std::string nom) {
    nombre = nom;
}
void Video::SetDuracion(double dur) {
    duracion = dur;
}
void Video::SetGenero(std::string gen) {
    genero = gen;
}
int Video::GetId() const {
    return id;
}
std::string Video::GetNombre() const {
    return nombre;
}
double Video::GetDuracion() const {
    return duracion;
}
std::string Video::GetGenero() const {
    return genero;
}
