
namespace CV07
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.generate = new System.Windows.Forms.Button();
            this.field = new System.Windows.Forms.GroupBox();
            this.field_size = new System.Windows.Forms.NumericUpDown();
            this.clear_timer = new System.Windows.Forms.Timer(this.components);
            this.restart = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.field_size)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(39, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Field size:";
            // 
            // generate
            // 
            this.generate.Location = new System.Drawing.Point(42, 61);
            this.generate.Name = "generate";
            this.generate.Size = new System.Drawing.Size(120, 62);
            this.generate.TabIndex = 2;
            this.generate.Text = "Generate";
            this.generate.UseVisualStyleBackColor = true;
            this.generate.Click += new System.EventHandler(this.generate_Click);
            // 
            // field
            // 
            this.field.Location = new System.Drawing.Point(12, 129);
            this.field.Name = "field";
            this.field.Size = new System.Drawing.Size(691, 255);
            this.field.TabIndex = 3;
            this.field.TabStop = false;
            this.field.Text = "Pexeso";
            // 
            // field_size
            // 
            this.field_size.Location = new System.Drawing.Point(42, 35);
            this.field_size.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.field_size.Name = "field_size";
            this.field_size.Size = new System.Drawing.Size(120, 20);
            this.field_size.TabIndex = 4;
            this.field_size.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.field_size.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.field_size_KeyPress);
            // 
            // clear_timer
            // 
            this.clear_timer.Interval = 3000;
            this.clear_timer.Tick += new System.EventHandler(this.clear_timer_Tick);
            // 
            // restart
            // 
            this.restart.Location = new System.Drawing.Point(252, 19);
            this.restart.Name = "restart";
            this.restart.Size = new System.Drawing.Size(451, 94);
            this.restart.TabIndex = 5;
            this.restart.Text = "Restart";
            this.restart.UseVisualStyleBackColor = true;
            this.restart.Visible = false;
            this.restart.Click += new System.EventHandler(this.restart_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(720, 399);
            this.Controls.Add(this.restart);
            this.Controls.Add(this.field_size);
            this.Controls.Add(this.field);
            this.Controls.Add(this.generate);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.field_size)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button generate;
        private System.Windows.Forms.GroupBox field;
        private System.Windows.Forms.NumericUpDown field_size;
        private System.Windows.Forms.Timer clear_timer;
        private System.Windows.Forms.Button restart;
    }
}

