using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CV01_02
{
    public partial class CV01_02 : Form
    {
        private Random rnd = new Random();
        public CV01_02()
        {
            InitializeComponent();
        }

        private void generate_button_Click(object sender, EventArgs e)
        {
            int[] generated_array = Enumerable.Repeat(0, rnd.Next(10,20)).Select(i => rnd.Next(0, 10)).ToArray();

            int[] array_numbers = new int[generated_array.Length];
            int[] array_counts = new int[generated_array.Length];
            int index = 0;
            int count = 0;
            for (int i = 0; i < generated_array.Length; i++) {
                if (!array_numbers.Contains(generated_array[i]))
                {
                    array_numbers[index] = generated_array[i];
                    count = 0;
                    for (int j = 0; j < generated_array.Length; j++)
                    {
                        if (generated_array[j] == array_numbers[index]) {
                            count++;
                        }
                    }
                    array_counts[index] = count;
                    index++;
                }
            }
            label1.Text = "\0";
            for (int j = 0; j < generated_array.Length; j++)
            {
                label1.Text += generated_array[j] + ",";
            }

            int[] maxIndexes = array_counts
                .Select((x, i) => new { Index = i, Value = x })
                .Where(x => x.Value == array_counts.Max())
                .Select(x => x.Index)
                .ToArray();

            result.Text = "Result is: ";
            foreach (int i in maxIndexes)
            {
                result.Text += array_numbers[i] + ",";
            }        
        }

        bool checkTringleSides(float a,float b,float c) {
            if (a + b <= c) return false;
            if (b + c <= a) return false;
            if (c + a <= b) return false;
            return true;
        }

        private void compare_count_Click(object sender, EventArgs e)
        {
            if (!checkTringleSides((float)A.Value, (float)B.Value, (float)C.Value)) {
                output.Text = "ERROR";
            } else {
                float a = (float)A.Value;
                float b = (float)B.Value;
                float c = (float)C.Value;
                output.Text = "Result is: " + Math.Sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) * (a + (b - c))) / 4;
            }
        }
    }
}
