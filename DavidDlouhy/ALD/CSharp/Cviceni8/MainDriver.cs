using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni8
{
    class MainDriver
    {
        public static void Main(String[] args)
        {
            AVLTree avl = new AVLTree();
            string  [] num  = (Console.ReadLine().Split(' '));
            for(int i=0; i<num.Length;i++)
            {
                int numer = Convert.ToInt32(num[i]);
                avl.insert(numer);
            }
            avl.preorder();
            avl.inorder();
            avl.postorder();
            Console.ReadKey();
        }

    
    }
}
