
namespace CV05_CV07
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
            this.exec = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.ball_output = new System.Windows.Forms.Label();
            this.cube_output = new System.Windows.Forms.Label();
            this.dodecahedron_output = new System.Windows.Forms.Label();
            this.icosahedron_output = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // exec
            // 
            this.exec.Location = new System.Drawing.Point(32, 35);
            this.exec.Name = "exec";
            this.exec.Size = new System.Drawing.Size(139, 70);
            this.exec.TabIndex = 0;
            this.exec.Text = "Execute";
            this.exec.UseVisualStyleBackColor = true;
            this.exec.Click += new System.EventHandler(this.exec_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(65, 212);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Cube";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(200, 212);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Dodecahedron";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(354, 212);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "Icosahedron";
            // 
            // ball_output
            // 
            this.ball_output.AutoSize = true;
            this.ball_output.Location = new System.Drawing.Point(501, 239);
            this.ball_output.Name = "ball_output";
            this.ball_output.Size = new System.Drawing.Size(35, 13);
            this.ball_output.TabIndex = 4;
            this.ball_output.Text = "label5";
            // 
            // cube_output
            // 
            this.cube_output.AutoSize = true;
            this.cube_output.Location = new System.Drawing.Point(65, 239);
            this.cube_output.Name = "cube_output";
            this.cube_output.Size = new System.Drawing.Size(35, 13);
            this.cube_output.TabIndex = 5;
            this.cube_output.Text = "label5";
            // 
            // dodecahedron_output
            // 
            this.dodecahedron_output.AutoSize = true;
            this.dodecahedron_output.Location = new System.Drawing.Point(200, 239);
            this.dodecahedron_output.Name = "dodecahedron_output";
            this.dodecahedron_output.Size = new System.Drawing.Size(35, 13);
            this.dodecahedron_output.TabIndex = 6;
            this.dodecahedron_output.Text = "label5";
            // 
            // icosahedron_output
            // 
            this.icosahedron_output.AutoSize = true;
            this.icosahedron_output.Location = new System.Drawing.Point(354, 239);
            this.icosahedron_output.Name = "icosahedron_output";
            this.icosahedron_output.Size = new System.Drawing.Size(35, 13);
            this.icosahedron_output.TabIndex = 7;
            this.icosahedron_output.Text = "label5";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(501, 212);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(24, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Ball";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.icosahedron_output);
            this.Controls.Add(this.dodecahedron_output);
            this.Controls.Add(this.cube_output);
            this.Controls.Add(this.ball_output);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.exec);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button exec;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label ball_output;
        private System.Windows.Forms.Label cube_output;
        private System.Windows.Forms.Label dodecahedron_output;
        private System.Windows.Forms.Label icosahedron_output;
        private System.Windows.Forms.Label label4;
    }
}

