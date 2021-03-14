using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Modus
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            int[] array = new int[5];
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = rnd.Next(10);
            }
            Array.Sort(array);
            int[] max = new int[2];
            int[] temp = new int[2];
            temp[0] = array[0];
            temp[1] = 1;
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] == temp[0])
                {
                    temp[1]++;
                } 
                else
                {
                    changeMax(ref max,ref temp);
                    temp[0] = array[i];
                    temp[1] = 1;
                }
            }
            label1.Text =Convert.ToString(max[0]);
            label2.Text = "";
            for (int i = 0; i < array.Length; i++)
            {
                label2.Text+= Convert.ToString(array[i]+", ");
            }
        }
       void changeMax(ref int[] max,ref int[] tmp)
        {
            if (max[1] < tmp[1])
            {
                max[0] = tmp[0];
                max[1] = tmp[1];
            }
        }
    }

}

