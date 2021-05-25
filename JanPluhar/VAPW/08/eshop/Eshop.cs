using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace eshop
{
    public class Eshop
    {
        System.Windows.Forms.ListBox products_box;
        System.Windows.Forms.ListBox users_box;
        System.Windows.Forms.ListBox basket_box;
        System.Windows.Forms.Label total_cost;
        List<User> users;
        List<Product> products;
        public Eshop(System.Windows.Forms.ListBox products_box, System.Windows.Forms.ListBox users_box, System.Windows.Forms.ListBox basket_box, System.Windows.Forms.Label total_cost)
        {
            this.products_box = products_box;
            this.users_box = users_box;
            this.basket_box = basket_box;
            this.total_cost = total_cost;
            users = new List<User>();
            products = new List<Product>();
        }
        public void show_products()
        {
            products_box.DataSource = products.ToArray();
        }
        public void show_users()
        {
            users_box.DataSource = users.ToArray();
        }
        public void show_basket()
        {
            basket_box.DataSource = ((User)users_box.SelectedItem).basket.get_products().ToArray(); 
        }
        public void show_total_price()
        {
            total_cost.Text = ((User)users_box.SelectedItem).basket.total_cost()+"";
        }
        public void add_user(User user)
        {
            users.Add(user);
        }
        public void add_product(Product product)
        {
            products.Add(product);
        }
        public void add_user_product()
        {
            products[products_box.SelectedIndex].quantity-=1;
            users[users_box.SelectedIndex].basket.add_product(new Product(products[products_box.SelectedIndex].name, products[products_box.SelectedIndex].quantity, products[products_box.SelectedIndex].cost));
        }
        public void remove_user_product()
        {
            foreach (Product item in products){
                if (item.name == users[users_box.SelectedIndex].basket.get_product(basket_box.SelectedIndex).name)
                {
                    item.quantity++;
                    break;
                }
            }
            users[users_box.SelectedIndex].basket.remove_product(basket_box.SelectedIndex);
        }
    }
}
