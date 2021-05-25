using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace eshop
{
    public partial class Form2 : Form
    {
        Eshop shop;
        public Form2(Eshop shop)
        {
            this.shop = shop;
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            shop.add_user(new User(textBox2.Text, textBox1.Text));
            shop.show_users();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
