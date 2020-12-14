using System;

namespace Uloha_08_AVL
{
    class Program
    {
        static void Main(string[] args)
        {
            Tree myTree = new Tree();


            String[] Line = Console.ReadLine().Split(" ");
            foreach (String item in Line)
            {
                myTree.add(Convert.ToInt32(item));
                if (Convert.ToInt32(item) < 0)
                {
                    break;
                }
            }

            Console.WriteLine("PREORDER");
            Console.WriteLine(myTree.Preorder());
            Console.WriteLine("INORDER");
            Console.WriteLine(myTree.Inorder());
            Console.WriteLine("POSTORDER");
            Console.WriteLine(myTree.Postorder());
        }
    }
}
