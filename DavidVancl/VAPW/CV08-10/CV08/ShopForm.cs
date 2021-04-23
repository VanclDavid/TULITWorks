using System;
using System.Windows.Forms;

namespace CV08_10 {
    public partial class ShopForm : Form {
        public ShopForm() {
            InitializeComponent();
            this.render_stock();
            this.render_users();
        }
        private void render_stock() {
            this.store_items.DataSource = null;
            this.store_items.DataSource = Program.shop.stock.get_item_list();
        }
        private void render_users() {
            this.users.DataSource = null;
            this.users.DataSource = Program.shop.users.get_user_list();
        }
        private void render_cart() {
            this.shopping_cart.DataSource = null;
            if (this.users.SelectedIndex >= 0) {
                this.shopping_cart.DataSource = Program.shop.users.get_user(this.users.SelectedIndex).get_cart_list();
            }
        }
        private void add_user_Click(object sender, EventArgs e) {
            NewUserForm add_user_form = new NewUserForm();
            add_user_form.FormClosed += new FormClosedEventHandler(on_form_close);
            add_user_form.Show();
        }
        private void on_form_close(object sender, FormClosedEventArgs e) {
            this.render_users();
        }

        private void add_Click(object sender, EventArgs e) {
            int user_index = this.users.SelectedIndex;
            int item_index = this.store_items.SelectedIndex;

            if (item_index >= 0) {
                Program.shop.add_process(user_index, item_index);
                this.render_stock();
                this.render_cart();
            }
        }

        private void users_SelectedIndexChanged(object sender, EventArgs e) {
            this.render_cart();
        }

        private void remove_Click(object sender, EventArgs e) {
            int user_index = this.users.SelectedIndex;
            int cart_item_index = this.shopping_cart.SelectedIndex;

            if (cart_item_index >= 0) {
                Program.shop.remove_process(user_index, cart_item_index);
                this.render_stock();
                this.render_cart();
            }
        }

        private void check_cart_sum_Click(object sender, EventArgs e) {
            User user = Program.shop.users.get_user(this.users.SelectedIndex);
            this.cart_sum_label.Text = user.get_cart_price().ToString() + " Kc";
        }
    }
}
