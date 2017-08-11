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
    public partial class SubForm2Bt1 : Form
    {
        public SubForm2Bt1()
        {
            InitializeComponent();
        }
        public string FIO;
        public string N;
        int RN;  //must be uint64_t
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
                              
            FIO = textBox1.Text;
            getTenant();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            N = textBox2.Text;
            RN = N.Trim; //?
        }
    }
}
