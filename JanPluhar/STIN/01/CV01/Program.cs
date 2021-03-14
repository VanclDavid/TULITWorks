using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CV01
{
    class Program
    {
        static void Main(string[] args)
        {
            IWriter mw = new MultipleWriter(new ConsoleWriter(), new FileWriter("d:\\out.txt", "\r\n"));
            mw.WriteLine("Ahoj!");
            mw.Write("hodnota: ");
            mw.Write(3.14f);
        }
    }
}
