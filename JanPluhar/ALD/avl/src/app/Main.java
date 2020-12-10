package app;

import java.util.Scanner;

public class Main {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        AvlTree tree = new AvlTree();
        while (sc.hasNextInt()) {
            int inputNumber = sc.nextInt();
            tree.add(inputNumber);
            if (inputNumber == -1) {
                break;
            }
        }
        System.out.println("PREORDER");
        tree.printPreOrder(tree.root);
        System.out.println();
        System.out.println("INORDER");
        tree.printInOrder(tree.root);
        System.out.println();
        System.out.println("POSTORDER");
        tree.printPostOrder(tree.root);
    }

    public static class Node {
        public int key;
        public int height = 1;
        public Node left;
        public Node right;

        public Node(int key) {
            this.key = key;
        }
    }

    public static class AvlTree {
        public Node root;

        Node add(int key) {
            root = add(root, key);
            return root;
        }

        private int height(Node node) {
            return node == null ? 0 : node.height;
        }

        private int balance(Node node) {
            return node == null ? 0 : height(node.left) - height(node.right);
        }

        Node add(Node node, int key) {
            if (node == null) {
                return new Node(key);
            }
            if (key <= node.key) {
                node.left = add(node.left, key);
            } else {
                node.right = add(node.right, key);
            }

            node.height = 1 + Math.max(height(node.left), height(node.right));
            int balance = balance(node);

            if (balance >= 2 && key < node.left.key) {
                return rightRotate(node);
            }
            if (balance <= -2 && key > node.right.key) {
                return leftRotate(node);
            }
            if (balance >= 2 && key > node.left.key) {
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
            if (balance <= -2 && key < node.right.key) {
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }

            return node;
        }

        private Node leftRotate(Node A) {
            Node B = A.right;
            Node temp = B.left;
            B.left = A;
            A.right = temp;

            A.height = Math.max(height(A.left), height(A.right)) + 1;
            B.height = Math.max(height(B.left), height(B.right)) + 1;
            return B;
        }

        private Node rightRotate(Node B) {
            Node A = B.left;
            Node temp = A.right;

            A.right = B;
            B.left = temp;

            B.height = Math.max(height(B.left), height(B.right)) + 1;
            A.height = Math.max(height(A.left), height(A.right)) + 1;
            return A;
        }

        public void printPostOrder(Node node) {
            if (node == null) {
                return;
            }
            printPostOrder(node.left);
            printPostOrder(node.right);
            System.out.format("%d,", node.key);
        }

        public void printInOrder(Node node) {
            if (node == null) {
                return;
            }
            printInOrder(node.left);
            System.out.format("%d,", node.key);
            printInOrder(node.right);
        }

        public void printPreOrder(Node node) {
            if (node == null) {
                return;
            }
            System.out.format("%d,", node.key);
            printPreOrder(node.left);
            printPreOrder(node.right);
        }
    }
}

