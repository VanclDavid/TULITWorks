using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CV01
{
    class FileWriter : IWriter
    {
        private FileWriter fw;
        private String path;
        private String lineSeparator;
        public FileWriter(String path, String lineSeparator)
        {
            this.path = path;
            this.lineSeparator = lineSeparator;
        }
        public void Write(string content)
        {
            File.AppendAllText(path, content);
        }

        public void Write(float number)
        {
            WriteLine(number.ToString());
        }

        public void WriteLine(string content)
        {
            File.AppendAllText(path, content+lineSeparator);
        }

        public void WriteLine(float number)
        {
            WriteLine(number.ToString());
        }
    }
}
