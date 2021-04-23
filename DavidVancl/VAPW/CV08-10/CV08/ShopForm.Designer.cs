
namespace CV08_10 {
    partial class ShopForm {
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
            this.cart_sum_label = new System.Windows.Forms.Label();
            this.check_cart_sum = new System.Windows.Forms.Button();
            this.add_user = new System.Windows.Forms.Button();
            this.remove = new System.Windows.Forms.Button();
            this.add = new System.Windows.Forms.Button();
            this.shopping_cart = new System.Windows.Forms.ListBox();
            this.users = new System.Windows.Forms.ListBox();
            this.store_items = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // cart_sum_label
            // 
            this.cart_sum_label.AutoSize = true;
            this.cart_sum_label.Location = new System.Drawing.Point(497, 296);
            this.cart_sum_label.Name = "cart_sum_label";
            this.cart_sum_label.Size = new System.Drawing.Size(35, 13);
            this.cart_sum_label.TabIndex = 15;
            this.cart_sum_label.Text = "label1";
            // 
            // check_cart_sum
            // 
            this.check_cart_sum.Location = new System.Drawing.Point(407, 183);
            this.check_cart_sum.Name = "check_cart_sum";
            this.check_cart_sum.Size = new System.Drawing.Size(233, 51);
            this.check_cart_sum.TabIndex = 14;
            this.check_cart_sum.Text = "Count cart";
            this.check_cart_sum.UseVisualStyleBackColor = true;
            this.check_cart_sum.Click += new System.EventHandler(this.check_cart_sum_Click);
            // 
            // add_user
            // 
            this.add_user.Location = new System.Drawing.Point(407, 126);
            this.add_user.Name = "add_user";
            this.add_user.Size = new System.Drawing.Size(233, 51);
            this.add_user.TabIndex = 13;
            this.add_user.Text = "Add user";
            this.add_user.UseVisualStyleBackColor = true;
            this.add_user.Click += new System.EventHandler(this.add_user_Click);
            // 
            // remove
            // 
            this.remove.Location = new System.Drawing.Point(407, 69);
            this.remove.Name = "remove";
            this.remove.Size = new System.Drawing.Size(233, 51);
            this.remove.TabIndex = 12;
            this.remove.Text = "Remove from cart";
            this.remove.UseVisualStyleBackColor = true;
            this.remove.Click += new System.EventHandler(this.remove_Click);
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(407, 12);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(233, 51);
            this.add.TabIndex = 11;
            this.add.Text = "Add to cart";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // shopping_cart
            // 
            this.shopping_cart.FormattingEnabled = true;
            this.shopping_cart.Location = new System.Drawing.Point(646, 12);
            this.shopping_cart.Name = "shopping_cart";
            this.shopping_cart.Size = new System.Drawing.Size(189, 420);
            this.shopping_cart.TabIndex = 10;
            // 
            // users
            // 
            this.users.FormattingEnabled = true;
            this.users.Location = new System.Drawing.Point(252, 12);
            this.users.Name = "users";
            this.users.Size = new System.Drawing.Size(149, 420);
            this.users.TabIndex = 9;
            this.users.SelectedIndexChanged += new System.EventHandler(this.users_SelectedIndexChanged);
            // 
            // store_items
            // 
            this.store_items.FormattingEnabled = true;
            this.store_items.Location = new System.Drawing.Point(17, 12);
            this.store_items.Name = "store_items";
            this.store_items.Size = new System.Drawing.Size(229, 420);
            this.store_items.TabIndex = 8;
            // 
            // ShopForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(861, 450);
            this.Controls.Add(this.cart_sum_label);
            this.Controls.Add(this.check_cart_sum);
            this.Controls.Add(this.add_user);
            this.Controls.Add(this.remove);
            this.Controls.Add(this.add);
            this.Controls.Add(this.shopping_cart);
            this.Controls.Add(this.users);
            this.Controls.Add(this.store_items);
            this.Name = "ShopForm";
            this.Text = "E-shop";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label cart_sum_label;
        private System.Windows.Forms.Button check_cart_sum;
        private System.Windows.Forms.Button add_user;
        private System.Windows.Forms.Button remove;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.ListBox shopping_cart;
        private System.Windows.Forms.ListBox users;
        private System.Windows.Forms.ListBox store_items;
    }
}

