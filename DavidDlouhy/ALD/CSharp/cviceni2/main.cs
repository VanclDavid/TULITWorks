using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Sample;

namespace Sample
{
    class Test
    {
        public static void Main(string[] args)
        {
            Tree tree = new Tree();
            char line;
            //while ((line = Console.ReadKey().KeyChar) != null)
            string [] lineOfNumbers = (Console.ReadLine()).Split(' ');
            foreach(string num in lineOfNumbers)
            {
                tree.add(int.Parse(num));
            }
            Console.WriteLine("preorder");
            tree.preorderRead(tree.root);
            Console.WriteLine("inorder");
            tree.inorderRead(tree.root);
            Console.WriteLine("postorder");
            tree.postorderRead(tree.root);
            Console.ReadKey();
        }
    }

    public class Node
    {
        public int value; //Hodnota kolečka
        public Node left;
        public Node right;
        public Node(int value)
        {
            this.value = value;
        }

        public Node add(int value)
        {
            if (value > this.value)
            {
                if (this.right == null)//pokud je pravý potomek prázný -> ulož
                {
                    this.right = new Node(value);
                    return this.right;
                }
                else
                {
                    return this.right.add(value);//dej požadavek potomkovi
                }
            }
            else
            {
                if (this.left == null)
                {
                    this.left = new Node(value);
                    return this.left;
                }
                else
                {
                    return this.left.add(value);
                }
            }
        }
    }

    public class Tree
    {
        public Node root;
        public void add(int value)
        {
            if (root == null)
            {
                root = new Node(value);
            }
            else
            {
                root.add(value);
            }
        }

        public void preorderRead(Node node)
        {
            int value = node.value;
            if (value != null)
            {
                Console.WriteLine(value);
                if (node.left != null)
                {
                    this.preorderRead(node.left);
                }
                if (node.right != null)
                {
                    if (node.right != null)
                    {
                        this.preorderRead(node.right);
                    }
                }
            }
        }

        public void inorderRead(Node node)
        {
            int value = node.value;
            if (value != null)
            {
                if (node.left != null)
                {
                    this.inorderRead(node.left);
                }
                Console.WriteLine(value);
                if (node.right != null)
                {
                    if (node.right != null)
                    {
                        this.inorderRead(node.right);
                    }
                }
            }
        }

        public void postorderRead(Node node)
        {
            int value = node.value;
            if (value != null)
            {
                if (node.left != null)
                {
                    this.postorderRead(node.left);
                }

                if (node.right != null)
                {
                    if (node.right != null)
                    {
                        this.postorderRead(node.right);
                    }
                }
                Console.WriteLine(value);
            }

        }
    }
}
