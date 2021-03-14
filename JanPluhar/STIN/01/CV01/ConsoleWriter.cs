using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CV01
{
    class ConsoleWriter : IWriter
    {
        public void Write(string content)
        {
            System.Console.Write(content);
        }

        public void Write(float number)
        {
            Write(number.ToString());
        }

        public void WriteLine(string content)
        {
            System.Console.WriteLine(content);
        }

        public void WriteLine(float number)
        {
            WriteLine(number.ToString());
        }
    }
}
