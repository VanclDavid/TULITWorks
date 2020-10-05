using System;
using System.Linq.Expressions;

namespace Uloha_01
{
    class Program
    {
        static void Main(string[] args)
        {
            int inputCount = 0;
            try
            {
                inputCount = Convert.ToInt32(Console.ReadLine());
            }
            catch (FormatException)
            {

                inputCount = 0;
            }

            for (int i = 1; i <= inputCount; i++)
            {
                Console.WriteLine("Hello world!");
            }
        }
    }
}
