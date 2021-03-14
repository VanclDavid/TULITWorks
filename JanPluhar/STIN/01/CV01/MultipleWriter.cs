using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CV01
{
    class MultipleWriter : IWriter
    {

        private List<IWriter> writers;
        public MultipleWriter(params IWriter[] array)
        {
            writers = new List<IWriter>(array);
        }
        public void Write(string content)
        {
            foreach (IWriter writer in writers){
                writer.Write(content);
            }
        }

        public void Write(float number)
        {
            Write(number.ToString());
        }

        public void WriteLine(string content)
        {
            foreach (IWriter writer in writers)
            {
                writer.WriteLine(content);
            }
        }

        public void WriteLine(float number)
        {
            WriteLine(number.ToString());
        }
    }
}
