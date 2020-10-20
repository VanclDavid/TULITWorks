package com.binarytree;

import java.util.Scanner;

public class Main {
    public static Scanner scanner = new Scanner(System.in);

    public static void main (String[] args) {
        Tree tree = new Tree();

        while (scanner.hasNextInt()) {
            tree.add(scanner.nextInt());
        }

        System.out.println("preorder");
        tree.printPreorderData(tree.root);

        System.out.println("inorder");
        tree.printInorderData(tree.root);

        System.out.println("postorder");
        tree.printPostorderData(tree.root);
        System.out.println();
    }

    public static class Node {
        public int value;
        public Node left;
        public Node right;

        public Node(int value) {
            this.value = value;
        }

        public void add(int value) {
            if (value > this.value) {
                if (this.right == null) {
                    this.right = new Node(value);
                } else {
                    this.right.add(value);
                }
            } else {
                if (this.left == null) {
                    this.left = new Node(value);
                } else {
                    this.left.add(value);
                }
            }
        }
    }

    public static class Tree {
        public Node root;

        public void add(int value) {
            if (root == null) {
                root = new Node(value);
            } else {
                root.add(value);
            }
        }

        public void printPreorderData(Node actualNode){
            System.out.format("%d \n",actualNode.value);
            if(actualNode.left != null){
                printPreorderData(actualNode.left);
            }
            if(actualNode.right != null) {
                printPreorderData(actualNode.right);
            }
        }

        public void printInorderData(Node actualNode){
            if(actualNode.left != null){
                printInorderData(actualNode.left);
            }
            System.out.format("%d \n",actualNode.value);
            if(actualNode.right != null) {
                printInorderData(actualNode.right);
            }
        }

        public void printPostorderData(Node actualNode){
            if(actualNode.left != null){
                printPostorderData(actualNode.left);
            }
            if(actualNode.right != null) {
                printPostorderData(actualNode.right);
            }
            System.out.format("%d \n",actualNode.value);
        }
    }
}