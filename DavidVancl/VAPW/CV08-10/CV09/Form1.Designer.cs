
namespace CV09 {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.start_stop = new System.Windows.Forms.Button();
            this.pi_background_counter = new System.ComponentModel.BackgroundWorker();
            this.pi = new System.Windows.Forms.Label();
            this.iter = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // start_stop
            // 
            this.start_stop.Location = new System.Drawing.Point(141, 96);
            this.start_stop.Name = "start_stop";
            this.start_stop.Size = new System.Drawing.Size(224, 100);
            this.start_stop.TabIndex = 0;
            this.start_stop.Text = "Start";
            this.start_stop.UseVisualStyleBackColor = true;
            this.start_stop.Click += new System.EventHandler(this.start_stop_Click);
            // 
            // pi_background_counter
            // 
            this.pi_background_counter.DoWork += new System.ComponentModel.DoWorkEventHandler(this.pi_background_counter_DoWork);
            // 
            // pi
            // 
            this.pi.AutoSize = true;
            this.pi.Location = new System.Drawing.Point(21, 9);
            this.pi.Name = "pi";
            this.pi.Size = new System.Drawing.Size(35, 13);
            this.pi.TabIndex = 1;
            this.pi.Text = "label1";
            // 
            // iter
            // 
            this.iter.AutoSize = true;
            this.iter.Location = new System.Drawing.Point(21, 40);
            this.iter.Name = "iter";
            this.iter.Size = new System.Drawing.Size(35, 13);
            this.iter.TabIndex = 2;
            this.iter.Text = "label2";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(543, 262);
            this.Controls.Add(this.iter);
            this.Controls.Add(this.pi);
            this.Controls.Add(this.start_stop);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "CountPI";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button start_stop;
        private System.ComponentModel.BackgroundWorker pi_background_counter;
        private System.Windows.Forms.Label pi;
        private System.Windows.Forms.Label iter;
    }
}

