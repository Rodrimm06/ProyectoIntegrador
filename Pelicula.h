
/*
 * Copyright (C) 2025 Tec de Monterrey
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#pragma once
#include "Video.h"
/**
Esta clase simula ser una pelicua dentro de una plataforma de streaming
*/
class Pelicula: public Video
{
public:
        /** 
        Constructor
        */
        Pelicula(int id_,const std::string& nombre_, double duracion_,const std::string& genero_);
        /** 
        Funcion de mostrar
        */
        void Mostrar() const override;
        /**
        Sobrecarga de operador para mayor eficiencia
        */
        friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);
};
