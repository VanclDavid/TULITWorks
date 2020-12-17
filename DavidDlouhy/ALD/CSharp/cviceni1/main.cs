using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cviceni1
{
    class main
    {
        public static void Main(string [] args)
        {
            string text = Console.ReadLine();
            int n = Convert.ToInt32(text);
            if(n>=0)
            { 
                for(int i =0; i<n; i++)
                {
                    Console.WriteLine("Hello world!");
                }
            }
            Console.Read();
        }
    }
}
