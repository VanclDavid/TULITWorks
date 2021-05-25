using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eshop
{
    public class Product
    {
        public Product(string name, int quantity, double cost)
        {
            this.name = name;
            this.quantity = quantity;
            this.cost = cost;
        }
        public string name { get; private set; }
        public int quantity { get; set;}
        public double cost { get; private set; }
        public override string ToString()
        {
            return name+" "+quantity;
        }
    }
}
