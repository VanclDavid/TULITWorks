
namespace CV10 {
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
            this.edge_length = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.type_box = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.add_mesh = new System.Windows.Forms.Button();
            this.result_box = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.edge_length)).BeginInit();
            this.SuspendLayout();
            // 
            // edge_length
            // 
            this.edge_length.Location = new System.Drawing.Point(73, 49);
            this.edge_length.Maximum = new decimal(new int[] {
            50,
            0,
            0,
            0});
            this.edge_length.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.edge_length.Name = "edge_length";
            this.edge_length.Size = new System.Drawing.Size(120, 20);
            this.edge_length.TabIndex = 0;
            this.edge_length.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(70, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Edge";
            // 
            // type_box
            // 
            this.type_box.Location = new System.Drawing.Point(73, 99);
            this.type_box.Name = "type_box";
            this.type_box.Size = new System.Drawing.Size(120, 20);
            this.type_box.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(70, 83);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Mesh type";
            // 
            // add_mesh
            // 
            this.add_mesh.Location = new System.Drawing.Point(73, 149);
            this.add_mesh.Name = "add_mesh";
            this.add_mesh.Size = new System.Drawing.Size(120, 39);
            this.add_mesh.TabIndex = 4;
            this.add_mesh.Text = "Add mesh";
            this.add_mesh.UseVisualStyleBackColor = true;
            this.add_mesh.Click += new System.EventHandler(this.add_mesh_Click);
            // 
            // result_box
            // 
            this.result_box.FormattingEnabled = true;
            this.result_box.Location = new System.Drawing.Point(253, 12);
            this.result_box.Name = "result_box";
            this.result_box.Size = new System.Drawing.Size(507, 199);
            this.result_box.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 267);
            this.Controls.Add(this.result_box);
            this.Controls.Add(this.add_mesh);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.type_box);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.edge_length);
            this.Name = "Form1";
            this.Text = "Geometrické tvary";
            ((System.ComponentModel.ISupportInitialize)(this.edge_length)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown edge_length;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox type_box;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button add_mesh;
        private System.Windows.Forms.ListBox result_box;
    }
}

