using System;

namespace CV05_CV07
{
    class Ball : Shape {
        public override double getContent() {
            return 4 * Math.PI * Math.Pow(this.getEdgeLength(), 2);
        }

        public override double getVolume(double edge) {
            return (4 / 3) * Math.PI * Math.Pow(edge, 3);
        }
    }
}
