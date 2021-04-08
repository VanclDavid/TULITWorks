using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace STINcv01
{
    class MultipleWriter : IWriter
    {
        private FileWriter fWriter;
        private ConsoleWriter cWriter;

        public MultipleWriter(ConsoleWriter cWriter, FileWriter fWriter) {
            this.fWriter = fWriter;
            this.cWriter = cWriter;
        }

        public void Write(dynamic line)
        {
            cWriter.Write(line);
            fWriter.Write(line);
        }

        public void WriteLine(string line)
        {
            cWriter.WriteLine(line);
            fWriter.WriteLine(line);
        }
    }
}
