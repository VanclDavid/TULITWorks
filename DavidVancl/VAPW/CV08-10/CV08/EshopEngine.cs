namespace CV08_10 {
    class EshopEngine {
        public Stock stock = new Stock();
        public UserList users = new UserList();
        public EshopEngine() {
            this.add_items();
            this.add_users();
        }
        private void add_items() {
            StockItem iphone = new StockItem("Apple iPhone 11 64GB Black", 15639);
            iphone.add_pieces(2);
            StockItem samsung = new StockItem("Samsung Galaxy A12 64GB černá", 4799);
            samsung.add_pieces(8);
            StockItem xiaomi = new StockItem("Xiaomi Redmi Note 9 128 GB zelený", 4599);
            xiaomi.add_pieces(4);
            StockItem nokia = new StockItem("Nokia 8.3 5G modrý", 12990);
            nokia.add_pieces(1);
            StockItem motorola = new StockItem("Motorola Moto G Pro", 5290);
            motorola.add_pieces(10);
            this.stock.add_item(new StockItem[] { iphone, samsung, xiaomi, nokia, motorola });
        }
        private void add_users() {
            this.users.add_user(new User[] {
                new User("Adam", "Skomolenina", "test@test.cz"),
                new User("Pavel", "Jedle", "test2@test.cz"),
                new User("Lukas", "Jahoda", "test3@test.cz"),
                new User("Jan", "Zelenina", "tes4@test.cz"),
                new User("Jirka", "Bahnival", "tes5@test.cz"),
                new User("Petr", "Studna", "test5@test.cz"),
                new User("Tele", "Huboumele", "test6@test.cz")});
        }
        public void add_process(int user_index, int item_index) {
            Program.shop.users.get_user(user_index).add_to_cart(Program.shop.stock.get_item(item_index));
            StockItem item = Program.shop.stock.get_item(item_index);
            item.take_pieces(1);
            if (item.get_pieces() == 0) {
                Program.shop.stock.remove_item(item);
            }
        }
        public void remove_process(int user_index, int cart_item_index) {
            User selected_user = Program.shop.users.get_user(user_index);
            Program.shop.stock.add_item(selected_user.get_cart_item(cart_item_index));
            selected_user.take_from_cart(selected_user.get_cart_item(cart_item_index));
        }
    }
}
