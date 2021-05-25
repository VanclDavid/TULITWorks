using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BackgroundWorker_pi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            backgroundWorker1.WorkerReportsProgress = true;
            backgroundWorker1.WorkerSupportsCancellation = true;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (backgroundWorker1.IsBusy)
            {
                button1.Text = "start";
                backgroundWorker1.CancelAsync();
            } else
            {
                button1.Text = "cancel";
                backgroundWorker1.RunWorkerAsync();
            }
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker worker = sender as BackgroundWorker;
            long circle_points = 0;
            long square_points = 0;
            Random rnd = new Random();
            int iter = 0;
            while (true)
            {
                for (int i = 0; i < 10000; i++)
                {
                    double x = rnd.NextDouble();
                    double y = rnd.NextDouble();
                    double d = x * x + y * y;
                    if (d <= 1)
                    {
                        circle_points++;
                    }
                    square_points++;
                }
                if (worker.CancellationPending == true)
                {
                    e.Cancel = true;
                    break;
                }
                worker.ReportProgress(iter++,4 * (circle_points / (double)square_points));
            }
        }

        private void backgroundWorker1_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            label1.Text = (e.ProgressPercentage.ToString()+" "+(e.UserState));
        }

        private void backgroundWorker1_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled == true)
            {
                label1.Text = "Canceled!";
            }
            else if (e.Error != null)
            {
                label1.Text = "Error: " + e.Error.Message;
            }
            else
            {
                label1.Text = "Done!";
            }
        }
    }
}
