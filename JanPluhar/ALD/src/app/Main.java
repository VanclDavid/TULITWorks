package app;

import java.util.Scanner;

public class Main {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        BinaryTree tree=new BinaryTree();
        while (sc.hasNextInt()){
            tree.add(sc.nextInt());
        }
        System.out.println("preorder");
        tree.printPreOrder(tree.root);
        System.out.println("inorder");
        tree.printInOrder(tree.root);
        System.out.println("postorder");
        tree.printPostOrder(tree.root);
    }

    public static class Node {
        public int value;
        public Node left;
        public Node right;

        public Node(int value) {
            this.value = value;
        }

        public Node add(int value) {
            if (value > this.value) {
                if (this.right == null) {
                    this.right = new Node(value);
                    return this.right;
                } else {
                    return this.right.add(value);
                }
            } else {
                if (this.left == null) {
                    this.left = new Node(value);
                    return this.left;
                } else {
                    return this.left.add(value);
                }
            }
        }
    }

    public static class BinaryTree {
        public Node root;
        public void add(int value) {
            if (root==null){
                root=new Node(value);
            } else {
                root.add(value);
            }
        }
        public void printPostOrder(Node node){
            if (node == null){
                return;
            }
            printPostOrder(node.left);
            printPostOrder(node.right);
            System.out.println(node.value);
        }
        public void printInOrder(Node node){
            if (node == null){
                return;
            }
            printInOrder(node.left);
            System.out.println(node.value);
            printInOrder(node.right);
        }
        public void printPreOrder(Node node){
            if (node == null){
                return;
            }
            System.out.println(node.value);
            printPreOrder(node.left);
            printPreOrder(node.right);
        }
    }
}

