namespace CV06
{
    class Employee : Person {
        private int payment;
        public Employee(string name, int payment) : base (name){
            this.payment = payment;
        }
        public int getPayment() {
            return this.payment;
        }
        public override string ToString() {
            return "Name: " + this.getName() + " Payment: " + this.getPayment();
        }
    }
}
