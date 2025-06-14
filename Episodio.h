
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#pragma once
#include <iostream>
#include <vector>
class Episodio
{
private:
    std::string nombre;
    int temporada;
    std::vector<int> calificaciones;
public:
    // Constructor
    Episodio(const std::string& nombre_, int temporada_);
    // Para ver informacion de los episodios
    void mostrar() const;
    // Para ver el promedio de la calificacion de los episodios
    double calcularPromedio() const;
    // Funcion para agregar una calificacion al vector
    void agregarCalificacion(int cali);
    // Sobrecarga de operador para mayor eficiencia
    friend std::ostream& operator<<(std::ostream& os, const Episodio& episodio);
    // Getters episodio
    std::string getNombre() const { return nombre; }
    int getTemporada() const { return temporada; }
};
