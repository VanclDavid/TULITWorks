using System.Collections.Generic;

namespace CV08_10 {
    class Cart {
        private List<CartItem> cart_items = new List<CartItem>();
        public void add_to_cart(CartItem item) {
            int result = exist_item(item);
            if (result != -1) {
                this.cart_items[result].add_pieces(1);
            } else {
                this.cart_items.Add(item);
                item.add_pieces(1);
            }
        }
        private int exist_item(CartItem item) {
            for (int i = 0; i < this.cart_items.Count; i++) {
                if (item.get_name() == this.cart_items[i].get_name()) {
                    return i;
                }
            }
            return -1;
        }
        public void take_from_cart(CartItem item) {
            item.take_pieces(1);
            if (item.get_pieces() == 0) {
                this.cart_items.Remove(item);
            }
        }
        public List<CartItem> get_item_list() {
            return this.cart_items;
        }
        public CartItem get_item(int index) {
            if (index < this.cart_items.Count) {
                return this.cart_items[index];
            }
            return null;
        }
    }
    
}
