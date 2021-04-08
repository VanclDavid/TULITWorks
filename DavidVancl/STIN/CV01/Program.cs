using System;

namespace STINcv01
{
    class Program
    {
        static void Main(string[] args)
        {
            IWriter writer = new MultipleWriter(new ConsoleWriter(), new FileWriter("I:\\test.txt", "\r\n"));

            writer.WriteLine("Hello world!");
            writer.Write("Value is ");
            writer.Write(3.14f);
        }
    }
}
