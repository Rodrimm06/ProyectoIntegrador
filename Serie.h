
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#pragma once
#include "Video.h"
#include "Episodio.h"
class Serie: public Video
{
private:
	std::vector<Episodio> episodios;
public:
	// Constructor
	Serie(int id_, const std::string& nombre_, double duracion_, const std::string& genero_);
	// Para agregar episodios
	void agregarEpisodio(const Episodio& episodio);
	// Para visualizar todos los episodios
	void mostrarEpisodios() const;
	// Funcion de mostrar
	void mostrar() const override;
	// Para sacar el promedio de toda la serie
	double calcularPromedio() const override;
	// Sobrecarga de operador para mayor eficiencia
	friend std::ostream& operator<<(std::ostream& os, const Serie& serie);
	// Funcion para obtener episodio
        const std::vector<Episodio>& getEpisodios() const { return episodios; }

};
