using System;
using System.Collections.Generic;
using System.Text;

namespace ALD_cv_03_tree
{
    class Tree
    {
        public Node rootNode;
        

        public void add(int val) {
            if (rootNode == null)
            {
                rootNode = new Node(val);
            }
            else {
                rootNode.add(val);
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
            result += currentNode.getVal() + "\r\n";
            result += Preorder(currentNode.getLeftNode());
            result += Preorder(currentNode.getRightNode());
            return result;
        }
        private string Inorder(Node currentNode)
        {
            String result = "";
            if (currentNode == null) return result;
            result += Inorder(currentNode.getLeftNode());
            result += currentNode.getVal() + "\r\n";
            result += Inorder(currentNode.getRightNode());
            return result;
        }
        private string Postorder(Node currentNode)
        {
            String result = "";
            if (currentNode == null) return result;
            result += Postorder(currentNode.getLeftNode());
            result += Postorder(currentNode.getRightNode());
            result += currentNode.getVal() + "\r\n";
            return result;
        }
    }

    class Node
    {
        private int val;
        private Node LeftNode, RightNode;

        public Node(int val)
        {
            this.val = val;
        }

        public int getVal() {
            return this.val;
        }

        public Node getLeftNode()
        {
            return this.LeftNode;
        }
        public Node getRightNode()
        {
            return this.RightNode;
        }

        public void add(int val) {
            if (val <= this.val)
            {
                if (this.LeftNode == null)
                {
                    this.LeftNode = new Node(val);
                }
                else
                {
                    this.LeftNode.add(val);
                }
            }
            else {
                if (this.RightNode == null)
                {
                    this.RightNode = new Node(val);
                }
                else
                {
                    this.RightNode.add(val);
                }
            }
        }
    }
}
