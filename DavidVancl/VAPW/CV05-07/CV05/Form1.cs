using System;
using System.Windows.Forms;

namespace CV05_CV07 {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }
        private void exec_Click(object sender, EventArgs e) {
            Cube cube = new Cube();
            this.cube_output.Text = this.getFormat(cube.getVolume(cube.getEdgeLength()), cube.getContent());

            Dodecahedron dodecahedron = new Dodecahedron();
            this.dodecahedron_output.Text = this.getFormat(dodecahedron.getVolume(dodecahedron.getEdgeLength()), dodecahedron.getContent());

            Icosahedron icosahedron = new Icosahedron();
            this.icosahedron_output.Text = this.getFormat(icosahedron.getVolume(icosahedron.getEdgeLength()), icosahedron.getContent());

            Ball ball = new Ball();
            this.ball_output.Text = this.getFormat(ball.getVolume(ball.getEdgeLength()), ball.getContent());
        }

        private string getFormat(double volume, double content) {
            return "V: " + volume.ToString("#.##") + " S: " + content.ToString("#.##");
        }
    }
}
