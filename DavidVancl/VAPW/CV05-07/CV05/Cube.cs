using System;

namespace CV05_CV07 {
    class Cube : Shape
    {
        public override double getContent() {
            return 6 * Math.Pow(this.getEdgeLength(), 2);
        }
        public override double getVolume(double edge)
        {
            return Math.Pow(edge, 3);
        }
    }
}
