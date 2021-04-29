using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Sphere : Utvar
    {
        public Sphere(float edge_length) : base(edge_length)
        {

        }
        public override float Get_Surface()
        {
            return (float)(4 * Math.PI * edge_length * edge_length);
        }

        public override float Volume()
        {
            return (float)(4 / 3 * Math.PI * Math.Pow(edge_length, 3));
        }
    }
}
