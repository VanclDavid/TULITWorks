using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STIN2
{
    class Order
    {/// <summary>
    /// containts Product objects
    /// </summary>
        private List<Product> productList;
        private string id;
        public Order(string id)
        {
            this.id = id;
            productList = new List<Product>();
        }
        public void AddProduct(Product product, int quantity)
        {
            product.Quantity = quantity;
            productList.Add(product);
        }
        public List<Product> getProductList()
        {
            return productList;
        }
        public string getId()
        {
            return id;
        }
    }
}
