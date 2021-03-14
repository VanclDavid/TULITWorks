using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace triangle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (isTriangular(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value), Convert.ToInt32(numericUpDown3.Value)))
            {
                label1.Text = Convert.ToString(obsah(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value), Convert.ToInt32(numericUpDown3.Value)));
            } else
            {
                label1.Text = "není trojúhelník";
            }
        }
        double obsah(int a, int b, int c)
        {
            return Math.Sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) * (a + (b - c))) / 4;
        }
        bool isTriangular(int a, int b, int c)
        {
            if (a + b >= c && a + c >= b && c + b >= a)
            { 
                return true; 
            }
            return false;
        }
    }
}
