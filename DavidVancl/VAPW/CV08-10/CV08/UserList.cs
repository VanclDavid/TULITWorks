using System.Collections.Generic;

namespace CV08_10 {
    class UserList {
        private List<User> users = new List<User>();
        public void add_user(User[] user_list) {
            foreach (User user in user_list) {
                this.users.Add(user);
            }
        }
        public void add_user(User user) {
            this.users.Add(user);
        }
        public User get_user(int index) {
            if (index < users.Count) {
                return this.users[index];
            }
            return null;
        }
        public List<User> get_user_list() {
            return this.users;
        }
    }
}
