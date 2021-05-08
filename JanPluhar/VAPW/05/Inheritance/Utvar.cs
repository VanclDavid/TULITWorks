using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    abstract class Utvar
    {
        protected float edge_length;

        protected Utvar(float edge_length)
        {
            this.edge_length = edge_length;
        }

        public abstract float Volume();
        public abstract float Get_Surface();

    }
}
