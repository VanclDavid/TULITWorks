
namespace CV03_04
{
    partial class FightArena
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
            this.generate = new System.Windows.Forms.Button();
            this.hero_name = new System.Windows.Forms.TextBox();
            this.fight_button = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.name_label = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.hero_name_label = new System.Windows.Forms.Label();
            this.hero_attack_label = new System.Windows.Forms.Label();
            this.herro_health_label = new System.Windows.Forms.Label();
            this.enemy_name_label = new System.Windows.Forms.Label();
            this.enemy_attack_label = new System.Windows.Forms.Label();
            this.enemy_health_label = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.hero_turn_label = new System.Windows.Forms.Label();
            this.enemy_turn_label = new System.Windows.Forms.Label();
            this.winner_label = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // generate
            // 
            this.generate.Location = new System.Drawing.Point(35, 77);
            this.generate.Name = "generate";
            this.generate.Size = new System.Drawing.Size(170, 51);
            this.generate.TabIndex = 0;
            this.generate.Text = "Generate Hero";
            this.generate.UseVisualStyleBackColor = true;
            this.generate.Click += new System.EventHandler(this.generate_Click);
            // 
            // hero_name
            // 
            this.hero_name.Location = new System.Drawing.Point(35, 51);
            this.hero_name.Name = "hero_name";
            this.hero_name.Size = new System.Drawing.Size(170, 20);
            this.hero_name.TabIndex = 1;
            // 
            // fight_button
            // 
            this.fight_button.Enabled = false;
            this.fight_button.Location = new System.Drawing.Point(35, 134);
            this.fight_button.Name = "fight_button";
            this.fight_button.Size = new System.Drawing.Size(170, 56);
            this.fight_button.TabIndex = 2;
            this.fight_button.Text = "Fight";
            this.fight_button.UseVisualStyleBackColor = true;
            this.fight_button.Click += new System.EventHandler(this.fight_button_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.name_label);
            this.groupBox1.Controls.Add(this.fight_button);
            this.groupBox1.Controls.Add(this.hero_name);
            this.groupBox1.Controls.Add(this.generate);
            this.groupBox1.Location = new System.Drawing.Point(261, 24);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(247, 218);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Input form";
            // 
            // name_label
            // 
            this.name_label.AutoSize = true;
            this.name_label.Location = new System.Drawing.Point(32, 35);
            this.name_label.Name = "name_label";
            this.name_label.Size = new System.Drawing.Size(62, 13);
            this.name_label.TabIndex = 3;
            this.name_label.Text = "Hero name:";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = global::CV03_04.Properties.Resources.hero;
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Location = new System.Drawing.Point(72, 267);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(150, 150);
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackgroundImage = global::CV03_04.Properties.Resources.enemy;
            this.pictureBox2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox2.Location = new System.Drawing.Point(540, 267);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(150, 150);
            this.pictureBox2.TabIndex = 5;
            this.pictureBox2.TabStop = false;
            // 
            // hero_name_label
            // 
            this.hero_name_label.AutoSize = true;
            this.hero_name_label.Location = new System.Drawing.Point(237, 285);
            this.hero_name_label.Name = "hero_name_label";
            this.hero_name_label.Size = new System.Drawing.Size(35, 13);
            this.hero_name_label.TabIndex = 6;
            this.hero_name_label.Text = "label1";
            // 
            // hero_attack_label
            // 
            this.hero_attack_label.AutoSize = true;
            this.hero_attack_label.Location = new System.Drawing.Point(237, 320);
            this.hero_attack_label.Name = "hero_attack_label";
            this.hero_attack_label.Size = new System.Drawing.Size(35, 13);
            this.hero_attack_label.TabIndex = 7;
            this.hero_attack_label.Text = "label1";
            // 
            // herro_health_label
            // 
            this.herro_health_label.AutoSize = true;
            this.herro_health_label.Location = new System.Drawing.Point(237, 356);
            this.herro_health_label.Name = "herro_health_label";
            this.herro_health_label.Size = new System.Drawing.Size(35, 13);
            this.herro_health_label.TabIndex = 8;
            this.herro_health_label.Text = "label1";
            // 
            // enemy_name_label
            // 
            this.enemy_name_label.AutoSize = true;
            this.enemy_name_label.Location = new System.Drawing.Point(696, 285);
            this.enemy_name_label.Name = "enemy_name_label";
            this.enemy_name_label.Size = new System.Drawing.Size(35, 13);
            this.enemy_name_label.TabIndex = 9;
            this.enemy_name_label.Text = "label1";
            // 
            // enemy_attack_label
            // 
            this.enemy_attack_label.AutoSize = true;
            this.enemy_attack_label.Location = new System.Drawing.Point(696, 320);
            this.enemy_attack_label.Name = "enemy_attack_label";
            this.enemy_attack_label.Size = new System.Drawing.Size(35, 13);
            this.enemy_attack_label.TabIndex = 10;
            this.enemy_attack_label.Text = "label1";
            // 
            // enemy_health_label
            // 
            this.enemy_health_label.AutoSize = true;
            this.enemy_health_label.Location = new System.Drawing.Point(696, 356);
            this.enemy_health_label.Name = "enemy_health_label";
            this.enemy_health_label.Size = new System.Drawing.Size(35, 13);
            this.enemy_health_label.TabIndex = 11;
            this.enemy_health_label.Text = "label1";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "label1";
            // 
            // hero_turn_label
            // 
            this.hero_turn_label.AutoSize = true;
            this.hero_turn_label.Location = new System.Drawing.Point(357, 320);
            this.hero_turn_label.Name = "hero_turn_label";
            this.hero_turn_label.Size = new System.Drawing.Size(35, 13);
            this.hero_turn_label.TabIndex = 13;
            this.hero_turn_label.Text = "label2";
            // 
            // enemy_turn_label
            // 
            this.enemy_turn_label.AutoSize = true;
            this.enemy_turn_label.Location = new System.Drawing.Point(453, 320);
            this.enemy_turn_label.Name = "enemy_turn_label";
            this.enemy_turn_label.Size = new System.Drawing.Size(35, 13);
            this.enemy_turn_label.TabIndex = 14;
            this.enemy_turn_label.Text = "label2";
            // 
            // winner_label
            // 
            this.winner_label.AutoSize = true;
            this.winner_label.ForeColor = System.Drawing.Color.Red;
            this.winner_label.Location = new System.Drawing.Point(357, 428);
            this.winner_label.Name = "winner_label";
            this.winner_label.Size = new System.Drawing.Size(0, 13);
            this.winner_label.TabIndex = 15;
            // 
            // FightArena
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.winner_label);
            this.Controls.Add(this.enemy_turn_label);
            this.Controls.Add(this.hero_turn_label);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.enemy_health_label);
            this.Controls.Add(this.enemy_attack_label);
            this.Controls.Add(this.enemy_name_label);
            this.Controls.Add(this.herro_health_label);
            this.Controls.Add(this.hero_attack_label);
            this.Controls.Add(this.hero_name_label);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.groupBox1);
            this.Name = "FightArena";
            this.Text = "FightArena";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button generate;
        private System.Windows.Forms.TextBox hero_name;
        private System.Windows.Forms.Button fight_button;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label name_label;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label hero_name_label;
        private System.Windows.Forms.Label hero_attack_label;
        private System.Windows.Forms.Label herro_health_label;
        private System.Windows.Forms.Label enemy_name_label;
        private System.Windows.Forms.Label enemy_attack_label;
        private System.Windows.Forms.Label enemy_health_label;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label hero_turn_label;
        private System.Windows.Forms.Label enemy_turn_label;
        private System.Windows.Forms.Label winner_label;
    }
}

