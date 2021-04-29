using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Cube : Utvar
    {
        public Cube(float edge_length) : base(edge_length)
        {
            
        }
        public override float Get_Surface()
        {
            return 6 * edge_length * edge_length;
        }

        public override float Volume()
        {
            return (float)Math.Pow(edge_length, 3);
        }
    }
}
