using System;

namespace CV10 {
    class Cube : Shape {
        public override double getContent() {
            return 6 * Math.Pow(this.getEdgeLength(), 2);
        }
        public override double getVolume(double edge) {
            return Math.Pow(edge, 3);
        }
        public override string ToString() {
            return this.get_format_to_string("Cube");
        }
    }
}
