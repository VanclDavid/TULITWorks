import java.util.Random;
import java.util.Scanner;

public class Main {

    public static int counter = 1;
    public static void main (String[] args) {
        Tree tree = new Tree();
        Random rng = new Random();

        for (int i = 0; i < 1000; i++) {
            tree.add(rng.nextInt(10000));
            // tree.add(i);
        }
        Node uzel = tree.find(10001);
        System.out.println(uzel);
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

        public Node find(int value) {
            System.out.format("Find: %d%n", counter++);

            if (value == this.value) {
                return this;
            }
            if (value > this.value) {
                return this.right == null
                        ? null
                        : this.right.find(value);
            } else {
                return this.left == null
                        ? null
                        : this.left.find(value);
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

        public Node find(int value) {
            if(this.root == null) {
                return null;
            }

            return this.root.find(value);
        }
    }
}