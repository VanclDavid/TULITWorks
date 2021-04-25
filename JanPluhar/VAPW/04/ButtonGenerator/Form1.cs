using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ButtonGenerator
{
    public partial class Form1 : Form
    {
        int index = 1;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            generateButton(sender, e);
        }
        private void generateButton(object sender, EventArgs e)
        {
            Button newButton = new Button();
            this.Controls.Add(newButton);
            newButton.Text = Convert.ToString(index++);
            newButton.Location = new Point(70, 70);
            newButton.Size = new Size(50, 20);
            newButton.Location = new Point(20, 20+(index-1)*20);
            newButton.Click += buttons_click;
        }
       private void buttons_click(object sender, EventArgs e)
        {
            MessageBox.Show((sender as Button).Text);
        }
    }
}
