using System;

namespace CV05_CV07 {
    class Dodecahedron : Shape
    {
        public override double getContent() {
            return 3 * Math.Sqrt(25 + (10 * Math.Sqrt(5))) * Math.Pow(this.getEdgeLength(), 2);
        }

        public override double getVolume(double edge) {
            return ((15 + 7 * (float)Math.Sqrt(5)) / 4) * Math.Pow(edge, 3);
        }
    }
}
