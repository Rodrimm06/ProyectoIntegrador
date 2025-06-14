
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
/**
Esta clase esta creada para simular una serie en una plataforma de streaming
*/
class Serie: public Video
{
private:
	std::vector<Episodio> episodios;
public:
	/** 
        Constructor
        */
	Serie(int id_, const std::string& nombre_, double duracion_, const std::string& genero_);
	/** 
        Para agregar episodios
        */
	void AgregarEpisodio(const Episodio& episodio);
	/**
        Para visualizar todos los episodios
        */
	void MostrarEpisodios() const;
	/** 
        Funcion de mostrar
        */
	void Mostrar() const override;
	/** 
        Para sacar el promedio de toda la serie
        */
	double CalcularPromedio() const override;
	/** 
        Sobrecarga de operador para mayor eficiencia
        */
	friend std::ostream& operator<<(std::ostream& os, const Serie& serie);
	/** 
        Funcion para obtener episodio
        */
        const std::vector<Episodio>& GetEpisodios() const { return episodios; }

};
