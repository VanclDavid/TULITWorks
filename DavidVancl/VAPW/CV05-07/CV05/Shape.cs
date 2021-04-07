namespace CV05_CV07 {
    abstract class Shape {
        private double edge_length = 5;
        public abstract double getVolume(double edge);
        public abstract double getContent();
        public void setEdgeLength(double new_legnth) {
            this.edge_length = new_legnth;
        }
        public double getEdgeLength() {
            return this.edge_length;
        }
    }
}
