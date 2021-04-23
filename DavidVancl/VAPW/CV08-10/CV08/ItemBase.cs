namespace CV08_10 {
    class ItemBase {
        private int pieces = 0;
        private string name = "";
        private double piece_price = 0;
        public ItemBase(string input_name, double input_piece_price) {
            this.name = input_name;
            this.piece_price = input_piece_price;
        }
        public void add_pieces(int pieces) {
            this.pieces += pieces;
        }
        public void take_pieces(int pieces) {
            this.pieces -= pieces;
        }
        public int get_pieces() {
            return this.pieces;
        }
        public string get_name() {
            return this.name;
        }
        public double get_piece_price() {
            return this.piece_price;
        }
        public double get_price() {
            return this.piece_price * this.pieces;
        }
    }
}
