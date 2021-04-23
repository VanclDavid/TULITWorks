namespace CV08_10 {
    class CartItem : ItemBase {
        public CartItem(string name, double piece_price) : base(name, piece_price) { }

        public override string ToString() {
            return string.Format("{0} {1}", this.get_name(), this.get_pieces());
        }
    }
}
