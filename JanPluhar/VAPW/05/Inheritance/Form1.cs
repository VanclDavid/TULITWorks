using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Inheritance
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Cube cube;
        Icosahedron ico;
        Dodecahedron dod;
        Sphere sphere;
        private void button1_Click(object sender, EventArgs e)
        {
            cube = new Cube(5);
            ico = new Icosahedron(5);
            dod = new Dodecahedron(5);
            sphere = new Sphere(5);
            label1.Text = Convert.ToString(cube.Get_Surface());
            label2.Text = Convert.ToString(ico.Get_Surface());
            label3.Text = Convert.ToString(dod.Get_Surface());
            label4.Text = Convert.ToString(sphere.Get_Surface());
        }
    }
}
