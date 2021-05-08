using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Collections_and_Listboxes
{
    public partial class Form1 : Form
    {
        List<Person> persons = new List<Person>();
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Person person;
            if (radioButton1.Checked)
            {
                person = new Person(textBox1.Text);
            }
            else {
                if (radioButton2.Checked)
                {
                    person = new Employee(textBox1.Text, 10);
                } else
                {
                    return;
                }
            }
            persons.Add(person);
            listBox1.DataSource = persons.ToArray();
        }

        int order = 0;
        private void button2_Click(object sender, EventArgs e)
        {
            if (order > 0)
            {
                order--;
                Show_single_person();
            }
        }
        public void Show_single_person()
        {
            label1.Text = persons[order].ToString();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (order < persons.Count-1)
            {
                order++;
                Show_single_person();
            }
        }
    }
}
