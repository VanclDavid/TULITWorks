﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections_and_Listboxes
{
    class Person
    {
        protected string name;
        public Person(string name)
        {
            this.name = name;
        }
        public override string ToString()
        {
            return name;
        }
    }
}
