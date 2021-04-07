using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;

namespace CV06 {
    public partial class Form1 : Form {
        private static Random random = new Random();
        private int list_index = 0;
        private List<Person> characters = new List<Person>();
        public Form1() {
            InitializeComponent();
        }
        private string GenerateString(int length) {
            const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            return new string(Enumerable.Repeat(chars, length)
              .Select(s => s[random.Next(s.Length)]).ToArray());
        }
        private void left_Click(object sender, EventArgs e) {
            this.list_index--;
            if (this.list_index < 0) {
                this.list_index = characters.Count - 1;
            }
            this.printInfo(this.list_index);
        }

        private void right_Click(object sender, EventArgs e) {
            this.list_index++;
            if (this.list_index > characters.Count - 1) {
                this.list_index = 0;
            }
            this.printInfo(this.list_index);
        }
        private void printInfo(int index) {
            this.output.Text = characters.ElementAt(index).ToString();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (name.Text == "") name.Text = this.GenerateString(10);
            if (person.Checked) {
                this.characters.Add(new Person(name.Text));
            } else if (employee.Checked) {
                this.characters.Add(new Employee(name.Text,random.Next(20000,30000)));
            }
            name.Text = "";
            result_box.DataSource = characters.ToArray();
        }
        private void result_box_MouseDoubleClick(object sender, MouseEventArgs e) {
            int index = this.result_box.IndexFromPoint(e.Location);
            if (index != System.Windows.Forms.ListBox.NoMatches) {
                this.printInfo(index);
                this.list_index = index;
            }
        }
    }
}
