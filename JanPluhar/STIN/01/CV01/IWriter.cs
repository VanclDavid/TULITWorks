using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CV01
{
    interface IWriter
    {
        void Write(string content);
        void WriteLine(string content);
        void Write(float number);
        void WriteLine(float number);
    }

}
