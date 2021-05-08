using System;

namespace CV10 {
    class Icosahedron : Shape {
        public override double getContent() {
            return 5 * Math.Sqrt(3) * Math.Pow(this.getEdgeLength(), 2);
        }
        public override double getVolume(double edge) {
            return ((5 * (3 + Math.Sqrt(5))) / 12) *  Math.Pow(edge, 3);
        }
        public override string ToString() {
            return this.get_format_to_string("Icosahedron");
        }
    }
}
