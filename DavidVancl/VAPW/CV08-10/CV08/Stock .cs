using System.Collections.Generic;

namespace CV08_10 {
    class Stock {
        private List<StockItem> stored_items = new List<StockItem>();
        public Stock() { }
        public void add_item(StockItem[] array_of_new_items) {
            foreach (StockItem item in array_of_new_items) {
                this.stored_items.Add(item);
            }
        }
        public void add_item(CartItem item) {
            int res = this.get_index(item);
            if (res == -1) {
                StockItem si = new StockItem(item.get_name(), item.get_piece_price());
                si.add_pieces(1);
                this.add_item(si);     
            } else {
                this.stored_items[res].add_pieces(1);
            }
        }
        private int get_index(CartItem item) {
            for (int i = 0; i < this.stored_items.Count; i++) {
                if (this.stored_items[i].get_name() == item.get_name()) return i;
            }
            return -1;
        }
        public void add_item(StockItem item) {
            this.stored_items.Add(item);
        }
        public void remove_item(StockItem item) {
            this.stored_items.Remove(item);
        }
        public List<StockItem> get_item_list() {
            return this.stored_items;
        }
        public StockItem get_item(int index) {
            if (index < stored_items.Count) {
                return this.stored_items[index];
            }
            return null;
        }
    }
}
