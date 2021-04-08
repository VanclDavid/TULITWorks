using System;
using System.IO;

namespace STINcv01
{
    class FileWriter : IWriter
    {
        private String path;
        private String breakType;
        public FileWriter(String path, String breakType) {
            this.path = path;
            this.breakType = breakType;
        }

        public void Write(dynamic line)
        {
            File.AppendAllText(path, Convert.ToString(line));
        }

        public void WriteLine(string line)
        {
            File.AppendAllText(path, Convert.ToString(line) + "" + breakType);
        }
    }
}
