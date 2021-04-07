
namespace CV06
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
            this.output = new System.Windows.Forms.Label();
            this.left = new System.Windows.Forms.Button();
            this.right = new System.Windows.Forms.Button();
            this.person = new System.Windows.Forms.RadioButton();
            this.employee = new System.Windows.Forms.RadioButton();
            this.result_box = new System.Windows.Forms.ListBox();
            this.name = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // output
            // 
            this.output.AutoSize = true;
            this.output.Location = new System.Drawing.Point(200, 313);
            this.output.Name = "output";
            this.output.Size = new System.Drawing.Size(35, 13);
            this.output.TabIndex = 0;
            this.output.Text = "label1";
            // 
            // left
            // 
            this.left.Location = new System.Drawing.Point(132, 267);
            this.left.Name = "left";
            this.left.Size = new System.Drawing.Size(75, 23);
            this.left.TabIndex = 1;
            this.left.Text = "Left";
            this.left.TextImageRelation = System.Windows.Forms.TextImageRelation.TextAboveImage;
            this.left.UseVisualStyleBackColor = true;
            this.left.Click += new System.EventHandler(this.left_Click);
            // 
            // right
            // 
            this.right.Location = new System.Drawing.Point(230, 267);
            this.right.Name = "right";
            this.right.Size = new System.Drawing.Size(75, 23);
            this.right.TabIndex = 2;
            this.right.Text = "Right";
            this.right.UseVisualStyleBackColor = true;
            this.right.Click += new System.EventHandler(this.right_Click);
            // 
            // person
            // 
            this.person.AutoSize = true;
            this.person.Checked = true;
            this.person.Location = new System.Drawing.Point(247, 55);
            this.person.Name = "person";
            this.person.Size = new System.Drawing.Size(58, 17);
            this.person.TabIndex = 4;
            this.person.TabStop = true;
            this.person.Text = "Person";
            this.person.UseVisualStyleBackColor = true;
            // 
            // employee
            // 
            this.employee.AutoSize = true;
            this.employee.Location = new System.Drawing.Point(247, 87);
            this.employee.Name = "employee";
            this.employee.Size = new System.Drawing.Size(71, 17);
            this.employee.TabIndex = 5;
            this.employee.TabStop = true;
            this.employee.Text = "Employee";
            this.employee.UseVisualStyleBackColor = true;
            // 
            // result_box
            // 
            this.result_box.FormattingEnabled = true;
            this.result_box.Location = new System.Drawing.Point(489, 12);
            this.result_box.Name = "result_box";
            this.result_box.Size = new System.Drawing.Size(299, 420);
            this.result_box.TabIndex = 6;
            this.result_box.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.result_box_MouseDoubleClick);
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(56, 12);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(163, 20);
            this.name.TabIndex = 7;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(56, 55);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(163, 49);
            this.button1.TabIndex = 8;
            this.button1.Text = "Generate";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.name);
            this.Controls.Add(this.result_box);
            this.Controls.Add(this.employee);
            this.Controls.Add(this.person);
            this.Controls.Add(this.right);
            this.Controls.Add(this.left);
            this.Controls.Add(this.output);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label output;
        private System.Windows.Forms.Button left;
        private System.Windows.Forms.Button right;
        private System.Windows.Forms.RadioButton person;
        private System.Windows.Forms.RadioButton employee;
        private System.Windows.Forms.ListBox result_box;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Button button1;
    }
}

