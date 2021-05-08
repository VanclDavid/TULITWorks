using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections_and_Listboxes
{
    class Employee : Person
    {
        public float pay;
        public Employee(string name, float pay) : base(name)
        {
            this.pay = pay;
        }
        public override string ToString()
        {
            return name + " " + pay;
        }
    }
}
