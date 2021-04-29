using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Icosahedron : Utvar
    {
        public Icosahedron(float edge_length) : base(edge_length)
        {

        }

        public override float Get_Surface()
        {
            return (float)(5*Math.Pow(3, 0.5) * edge_length*edge_length);
        }

        public override float Volume()
        {
            return (float)(5 / 12 * (3 + Math.Pow(5, 0.5)) * Math.Pow(edge_length, 3));
        }
    }
}
