using System;

namespace STINcv01
{
    class ConsoleWriter : IWriter
    {
        public void Write(dynamic line)
        {
            Console.Write(line);
        }

        public void WriteLine(string line)
        {
            Console.WriteLine(line);
        }
    }
}
