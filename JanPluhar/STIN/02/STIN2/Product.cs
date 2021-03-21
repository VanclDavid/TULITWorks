using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STIN2
{
    class Product
    {
        /// <summary>
        /// object created from one line of input string
        /// </summary>
        private string type;
        private string manufacturer;
        private int price;
        private int quantity;
        private int weight;
        private int width;
        private int height;
        private int depth;
        public Product(string type, string manufacturer, int price, int weight, int width, int height, int depth)
        {
            this.Type = type;
            this.Manufacturer = manufacturer;
            this.Price = price;
            Quantity = 0;
            this.Weight = weight;
            this.Width = width;
            this.Height = height;
            this.Depth = depth;
        }

        public string Type { get => type; set => type = value; }
        public string Manufacturer { get => manufacturer; set => manufacturer = value; }
        public int Price { get => price; set => price = value; }
        public int Quantity { get => quantity; set => quantity = value; }
        public int Weight { get => weight; set => weight = value; }
        public int Width { get => width; set => width = value; }
        public int Height { get => height; set => height = value; }
        public int Depth { get => depth; set => depth = value; }
    }
}
