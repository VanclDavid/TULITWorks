using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eshop
{
    public class Basket
    {
        List<Product> products;
        public Basket()
        {
            products = new List<Product>();
        }
        public void add_product(Product product)
        {
            foreach (Product item in products)
            {
                if (product.name == item.name)
                {
                    item.quantity++;
                    return;
                }
            }
            product.quantity = 1;
            products.Add(product);
        }
        public Product get_product(int index)
        {
            return products[index];
        }
        public void remove_product(int index)
        {
            if (products[index].quantity>1)
            {
                products[index].quantity--;
            } else
            {
                products.RemoveAt(index);
            }
        }
        public List<Product> get_products()
        {
            return products;
        }
        public double total_cost()
        {
            double sum = 0;
            foreach (Product product in products)
            {
                sum += product.cost * product.quantity;
            }
            return sum;
        }
    }
}
