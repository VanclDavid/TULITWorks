using System;

namespace ALD_cv_03_tree
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
            }

            Console.WriteLine("preorder");
            Console.Write(myTree.Preorder());
            Console.WriteLine("inorder");
            Console.Write(myTree.Inorder());
            Console.WriteLine("postorder");
            Console.Write(myTree.Postorder());
        }
    }
}
