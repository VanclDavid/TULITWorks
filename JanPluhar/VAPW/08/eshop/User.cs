using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eshop
{
    public class User
    {
        public string name;
        public string email;
        public Basket basket;
        public User(string name,string email)
        {
            this.name = name;
            this.email = email;
            basket = new Basket();
        }
        public override string ToString()
        {
            return name;
        }
    }
}
