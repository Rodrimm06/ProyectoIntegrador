
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "Pelicula.h"
// Constructor, esta subclase solo tiene de atributos los de la clase base Video
Pelicula::Pelicula(int id_, const std::string& nombre_, double duracion_,  const std::string& genero_)
	:Video(id_,nombre_,duracion_,genero_){
	
}
// Funcion para mostrar informacion de la pelicula
void Pelicula::	Mostrar() const {
	std::cout << "Pelicula: " << GetNombre() << std::endl <<
		"Duracion: " << GetDuracion() << std::endl <<
		"Genero: " << GetGenero() << std::endl <<
		"ID: " << GetId() << std::endl <<
		"Calificacion Promedio: " << CalcularPromedio() << std::endl;
}
// Sobrecarga de operadores para mayor eficiencia
std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
	os << "Pelicula: " << pelicula.GetNombre() << std::endl
		<< "Duracion: " << pelicula.GetDuracion() << std::endl
		<< "Genero: " << pelicula.GetGenero() << std::endl
		<< "ID: " << pelicula.GetId() << std::endl
		<< "Calificacion Promedio: " << pelicula.CalcularPromedio() << std::endl;
	return os;
}
