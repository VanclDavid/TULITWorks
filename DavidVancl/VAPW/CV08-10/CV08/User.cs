using System.Collections.Generic;

namespace CV08_10 {
    class User {
        private Cart cart = new Cart();
        private string name = "";
        private string surname = "";
        private string email = "";
        public User(string name, string surname, string email) {
            this.name = name;
            this.surname = surname;
            this.email = email;
        }
        public string get_email() {
            return this.email;
        }
        public string get_name() {
            return this.name;
        }
        public string get_surname() {
            return this.surname;
        }
        public void add_to_cart(StockItem cart_item) {
            this.cart.add_to_cart(new CartItem(cart_item.get_name(), cart_item.get_piece_price()));
        }
        public void take_from_cart(CartItem item) {
            this.cart.take_from_cart(item);
        }
        public CartItem get_cart_item(int index) {
            return this.cart.get_item(index);
        }
        public List<CartItem> get_cart_list() {
            return this.cart.get_item_list();
        }
        public double get_cart_price() {
            double sum = 0;
            foreach (CartItem item in this.cart.get_item_list()) {
                sum += item.get_price();
            }
            return sum;
        }
        public override string ToString() {
            return string.Format("{0} {1}", this.get_name(), this.get_surname());
        }
    }
}
