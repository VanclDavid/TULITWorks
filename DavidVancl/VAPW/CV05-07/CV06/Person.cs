namespace CV06 {
    class Person {
        private string name;
        public Person(string name) {
            this.name = name;
        }
        public string getName() {
            return this.name;
        }
        public override string ToString() {
            return "Name: " + this.getName();
        }
    }
}
