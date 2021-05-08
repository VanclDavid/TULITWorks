using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace CV09 {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
            pi_background_counter.WorkerSupportsCancellation = true;
        }

        private void pi_background_counter_DoWork(object sender, DoWorkEventArgs e) {
            BackgroundWorker worker = sender as BackgroundWorker;
            long iterator = 0;
            long last_print_iter = 0;

            double sum_for_pi = 0;
            while (worker.CancellationPending == false) {
                sum_for_pi += Math.Pow(-1, iterator) * ((4 / Math.Pow(5, 2 * iterator + 1) - (1 / Math.Pow(239, 2 * iterator + 1)) / 2 * iterator + 1));
                
                if (iterator - last_print_iter >= 1e4) {
                    this.iter.Invoke((Action)delegate {
                        iter.Text = iterator.ToString();
                    });
                    this.pi.Invoke((Action)delegate {
                        pi.Text = (4 * sum_for_pi).ToString();
                    });
                    last_print_iter = iterator;
                }
                iterator++;
            }
            e.Cancel = true;
        }

        private void start_stop_Click(object sender, EventArgs e) {
            if (pi_background_counter.IsBusy != true) {
                // Start the asynchronous operation.
                pi_background_counter.RunWorkerAsync();
            }
        }
    }
}
