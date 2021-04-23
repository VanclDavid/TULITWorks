using System;
using System.Windows.Forms;

namespace CV08_10 {
    public partial class NewUserForm : Form {
        public NewUserForm() {
            InitializeComponent();
        }
        private void close_Click(object sender, EventArgs e) {
            this.Close();
        }
        private void ok_Click(object sender, EventArgs e) {
            Program.shop.users.add_user(new User(this.name_input.Text, this.surname_input.Text, this.email_input.Text));
            this.Close();
        }
    }
}
