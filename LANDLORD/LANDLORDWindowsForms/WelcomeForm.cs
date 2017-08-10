using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LANDLORDWindowsForms
{
    public partial class WelcomeForm : Form
    {
        
        public WelcomeForm()
        {
            InitializeComponent();
            Form2 = new SubFormBt1();
            
        }
        SubFormBt1 Form2;
        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2.Show();
            
        }
    }
}
