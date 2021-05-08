using System.Collections.Generic;
using System.Windows.Forms;

namespace CV10 {
    public partial class Form1 : Form {
        List<IMesh> shapes = new List<IMesh>();
        public Form1() {
            InitializeComponent();
        }
        private void add_mesh_Click(object sender, System.EventArgs e) {
            int edge = (int)this.edge_length.Value;
            string type = this.type_box.Text;
            IMesh mesh = ShapeFactory.shape_factory(type, edge);
            if (mesh != null) {
                this.shapes.Add(mesh);
                result_box.DataSource = null;
                result_box.DataSource = this.shapes;
            }
            this.type_box.Text = "";
        }
    }
}
