using System;
using System.Collections.Generic;
using System.Text;

namespace Uloha_08_AVL
{
    class Tree
    {
        public Node rootNode;


        public void add(int val)
        {
            if (rootNode == null)
            {
                rootNode = new Node(val);
            }
            else
            {
                rootNode = Node.add(rootNode, val);
            }
        }

        public string Preorder()
        {
            return Preorder(this.rootNode);
        }
        public string Inorder()
        {
            return Inorder(this.rootNode);
        }
        public string Postorder()
        {
            return Postorder(this.rootNode);
        }
        private string Preorder(Node currentNode)
        {
            String result = "";
            if (currentNode == null) return result;
            result += currentNode.getVal() + ",";
            //result += currentNode.getVal() + "\r\n";
            result += Preorder(currentNode.getLeftNode());
            result += Preorder(currentNode.getRightNode());
            return result;
        }
        private string Inorder(Node currentNode)
        {
            String result = "";
            if (currentNode == null) return result;
            result += Inorder(currentNode.getLeftNode());
            result += currentNode.getVal() + ",";
            //result += currentNode.getVal() + "\r\n";
            result += Inorder(currentNode.getRightNode());
            return result;
        }
        private string Postorder(Node currentNode)
        {
            String result = "";
            if (currentNode == null) return result;
            result += Postorder(currentNode.getLeftNode());
            result += Postorder(currentNode.getRightNode());
            result += currentNode.getVal() + ",";
            //result += currentNode.getVal() + "\r\n";
            return result;
        }
    }

    class Node
    {
        private int height = 1;
        private int val;
        private Node LeftNode, RightNode;

        public Node(int val)
        {
            this.val = val;
        }
        public int getVal()
        {
            return this.val;
        }
        public static int getHeight(Node node)
        {
            return node == null ? 0 : node.height;
        }

        public int setHeight(int height)
        {
            return this.height = height;
        }

        public Node getLeftNode()
        {
            return this.LeftNode;
        }
        public Node getRightNode()
        {
            return this.RightNode;
        }

        private static int getBalance(Node node)
        {
            return node == null ? 0 : getHeight(node.LeftNode) - getHeight(node.RightNode);
        }

        public static Node add(Node node, int val)
        {
            if (val <= node.val)
            {
                if (node.LeftNode == null)
                {
                    node.LeftNode = new Node(val);
                }
                else
                {
                    node.LeftNode = Node.add(node.LeftNode, val);
                }
            }
            else
            {
                if (node.RightNode == null)
                {
                    node.RightNode = new Node(val);
                }
                else
                {
                    node.RightNode = Node.add(node.RightNode, val);
                }
            }

            node.setHeight(1 + Math.Max( getHeight(node.LeftNode), getHeight(node.RightNode)));

            int balance = getBalance(node);

            if (balance >= 2 && val < node.LeftNode.getVal())
            {
                return rightRotate(node);
            }
            if (balance <= -2 && val > node.RightNode.getVal())
            {
                return leftRotate(node);
            }
            if (balance >= 2 && val > node.LeftNode.getVal())
            {
                node.LeftNode = leftRotate(node.LeftNode);
                return rightRotate(node);
            }
            if (balance <= -2 && val < node.RightNode.getVal())
            {
                node.RightNode = rightRotate(node.RightNode);
                return leftRotate(node);
            }

            return node;
        }

        private static Node leftRotate(Node A)
        {
            Node B = A.RightNode;
            Node temp = B.LeftNode;
            B.LeftNode = A;
            A.RightNode = temp;

            A.setHeight(Math.Max( getHeight(A.LeftNode), getHeight(A.RightNode)) + 1);
            B.setHeight(Math.Max( getHeight(B.LeftNode), getHeight(B.RightNode)) + 1);

            return B;
        }

        private static Node rightRotate(Node B)
        {
            Node A = B.LeftNode;
            Node temp = A.RightNode;

            A.RightNode = B;
            B.LeftNode = temp;

            B.setHeight(Math.Max( getHeight(B.LeftNode), getHeight(B.RightNode)) + 1);
            A.setHeight(Math.Max( getHeight(A.LeftNode), getHeight(A.RightNode)) + 1);
            return A;
        }
    }
}
