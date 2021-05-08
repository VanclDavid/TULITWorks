namespace CV10 {
    abstract class Shape : IMesh {
        private double edge_length = 5;
        public abstract double getVolume(double edge);
        public abstract double getContent();
        public void setEdgeLength(double new_legnth) {
            this.edge_length = new_legnth;
        }
        public double getEdgeLength() {
            return this.edge_length;
        }
        protected string get_format_to_string(string type) {
            return string.Format("T: {0} E:{1} C:{2} V: {3}", type, this.edge_length, this.getContent(), this.getVolume(this.edge_length));
        }
        public override abstract string ToString();
    }
}
