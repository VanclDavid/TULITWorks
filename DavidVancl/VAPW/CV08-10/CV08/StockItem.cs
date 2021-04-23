namespace CV08_10 {
    class StockItem : ItemBase {
        public StockItem(string name, double piece_price) : base(name, piece_price) { }

        public override string ToString() {
            return string.Format("Name: {0}... | Price: {1} Kc | Pieces: {2}", this.get_name().Substring(0,5), this.get_piece_price(), this.get_pieces());
        }
    }
}
