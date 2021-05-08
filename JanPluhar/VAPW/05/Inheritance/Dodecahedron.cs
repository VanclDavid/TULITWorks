using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Dodecahedron : Utvar
    {
        public Dodecahedron(float edge_length) : base(edge_length)
        {

        }
        public override float Get_Surface()
        {
            return (float)(3 * Math.Sqrt(25 + 10 * Math.Pow(5, 0.5)) * edge_length * edge_length);
        }

        public override float Volume()
        {
            return (float)(0.25 * (15 + 7 * Math.Pow(5, 0.5)) * Math.Pow(edge_length, 3));
        }
    }
}
