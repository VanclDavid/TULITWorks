using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni8
{
    public class Node
    {
        public int key;
        public Node left;
        public Node right;
        public int height;
        public Node(int key)
        {
            height = 1;
            this.key = key;
        }
        //IMPLEMENOVAT SI INTERFACE - 3 metody
    }
}
