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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public static Eshop eshop;
        private void Form1_Load(object sender, EventArgs e)
        {
            eshop = new Eshop(listBox1, listBox2, listBox3, label1);
            eshop.add_product(new Product("ananas", 24, 15.3));
            eshop.add_product(new Product("dřevo", 8, 12));
            eshop.add_product(new Product("klíč", 7, 5));
            eshop.add_product(new Product("auto", 2, 40000));
            eshop.add_product(new Product("brokolice", 1, 0.5));
            eshop.add_user(new User("pepa", "pepa@mail.com"));
            eshop.show_users();
            eshop.show_products();
            eshop.show_basket();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            Form2 secondForm = new Form2(eshop);
            secondForm.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            eshop.add_user_product();
            eshop.show_products();
            eshop.show_basket();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            eshop.remove_user_product();
            eshop.show_products();
            eshop.show_basket();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            eshop.show_total_price();
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            eshop.show_basket();
            label1.Text = "";
        }
    }
}
