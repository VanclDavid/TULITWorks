using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CV04
{
    public partial class Form1 : Form
    {
        private int index = 1;
        private int indexX = 1;
        private int indexY = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void start_Click(object sender, EventArgs e)
        {
            Button button = new Button();
            button.Size = new Size(70, 40);
            int posX = (sender as Button).Location.X + (indexX * 75);
            int posY = (sender as Button).Location.Y + (indexY * 45);
            button.Location = new Point(posX,posY);
            button.Click += new EventHandler(generic_button_click);
            button.Text = index.ToString();
            index++;
            indexX++;
            if (indexX >= 10) {
                indexX = 0;
                indexY++;
            }
            if (index > 99) {
                (sender as Button).Enabled = false;
            }
            this.Controls.Add(button);
        }

        private void generic_button_click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Text is: " + (sender as Button).Text, "Genmeric message", MessageBoxButtons.YesNo);
        }
    }
}
