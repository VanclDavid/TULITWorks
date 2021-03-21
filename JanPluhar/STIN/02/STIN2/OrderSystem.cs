using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STIN2
{
    class OrderSystem
    {
        /// <summary>
        /// contains Order class objects
        /// </summary>
        private string name;
        private int id;
        private List<Order> orders;
        public OrderSystem(int id, string name){
            this.id = id;
            this.name = name;
            orders = new List<Order>();
        }
        public void addOrder(Order order)
        {
            ///adds Order object into orders list
            orders.Add(order);
        }
        public void printBill()
        {
            ///print data for every Order item in orders list into console
            StringBuilder result = new StringBuilder();
            foreach (Order order in orders)
            {
                double sum = 0;
                result.Append(order.getId()).Append("\n");
                List<Product> products = order.getProductList();
                foreach (Product product in products)
                {
                    double value = calculate(product);
                    sum += value;
                    result.Append("polozka: ").Append(product.Quantity).Append(" x ").Append(product.Type).Append(" (").Append(product.Manufacturer).Append(") ").Append(value).Append('\n');
                }
                result.Append("suma: ").Append(sum).Append("\n\n");
            }
            Console.WriteLine(result.ToString());
        }
        private double calculate(Product product)
        {
            int[] array = { product.Width, product.Height, product.Depth };
            int max = new int[]{ product.Width, product.Height, product.Depth}.Max();
            if (max > 100)
                {
                    if (product.Weight < 20)
                    {
                        return product.Quantity * 10;
                    }
                    else
                    {
                        double result = product.Quantity * product.Weight * 0.2;
                        if (product.Type.Equals("lednice"))
                        { result *= 2; }
                        return result;
                    }
                }
                else
                {
                    return product.Quantity * 5;
                }
        }
    }
}
