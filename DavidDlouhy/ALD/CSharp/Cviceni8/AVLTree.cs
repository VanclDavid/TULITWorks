using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Cviceni8
{
    public class AVLTree
    {
        Node root;
        public Node insert(int key)
        {
            root = this.insert(root, key);
            return root;
        }
        public Node insert(Node node, int key)
        {
            if (node==null)
            {
                return new Node(key);
            }
            if(key<=node.key)
            {
                node.left = insert(node.left, key);
            }
            else
            {
                node.right = insert(node.right, key);
            }
            node.height = 1 + Math.Max(height(node.left), height(node.right));
            int balanceI = balance(node);

            if (balanceI >= 2 && key < node.left.key)
            {
                return rightRotate(node);
            }

            if (balanceI <= -2 && key > node.right.key)
            {
                return leftRotate(node);
            }

            if (balanceI >= 2 && key > node.left.key)
            {
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }

            if (balanceI <= -2 && key < node.right.key)
            {
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }


                return node;
        }

        private Node leftRotate(Node A)
        {
            Node B = A.right;
            Node y = B.left;
            B.left = A;
            A.right = y;
            
            A.height = Math.Max(height(A.left),height(A.right)) + 1;
            B.height = Math.Max(height(B.left),height(B.right)) + 1;
            return B;

        }
        private Node rightRotate(Node B)
        {
            Node A = B.left;
            Node y = A.right;
            
            A.right = B;
            B.left = y;
            
            B.height = Math.Max(height(B.left),height(B.right)) + 1;
            A.height = Math.Max(height(A.left),height(A.right)) + 1;
            return A;

        }

        private int height(Node node)
        {
            return node == null ?0:node.height;
        }

        private int balance(Node node)
        {
            return node == null ? 0 : height(node.left) - height(node.right);
        }


        public void postorder()
        {
            Console.WriteLine("POSTORDER");
            if(root.left!=null)
            {
                postorder(root.left);
            }
            
            if (root.right != null)
            {
                postorder(root.right);
            }
            
            if (root.key != null)
            {
                Console.Write(root.key + ",");
            }
            
            Console.Write("\n");
        }

        public void postorder(Node activelNode)
        {
            if (activelNode.left != null)
            {
                postorder(activelNode.left);
            }
            if (activelNode.right != null)
            {
                postorder(activelNode.right);
            }
            Console.Write(activelNode.key+",");
        }

        public void preorder()
        {
            Console.WriteLine("PREORDER");
            if(root.key!=null)
            {
                Console.Write(root.key + ",");
            }
            
            if (root.left != null)
            {
                preorder(root.left);
            }
            
            if (root.right != null)
            {
                preorder(root.right);
            }
            
            Console.Write("\n");
        }
        public void preorder(Node activelNode)
        {
            Console.Write(activelNode.key+",");
            if (activelNode.left != null)
            {
                preorder(activelNode.left);
            }
            if (activelNode.right != null)
            {
                preorder(activelNode.right);
            }
        }
        public void inorder()
        {
            Console.WriteLine("INORDER");
            if (root.left != null)
            {
                inorder(root.left);
            }
            
            if (root.key != null)
            {
                Console.Write(root.key + ",");
            }
            
            if (root.right != null)
            {
                inorder(root.right);
            }
            
            Console.Write("\n");
        }
        public void inorder(Node activelNode)
        {
            
            if(activelNode.left != null){
                inorder(activelNode.left);
            }
            Console.Write(activelNode.key + ",");
            if (activelNode.right != null) {
                inorder(activelNode.right);
            }
            
        }

    }
}
