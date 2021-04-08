using System;
using System.Collections.Generic;
using System.Text;

namespace STINcv01
{
    interface IWriter
    {
        void WriteLine(String line);
        void Write(dynamic line);
    }
}
