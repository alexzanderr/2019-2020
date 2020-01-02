using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace _Application_Database_Form_
{
    public partial class Extention1 : Form
    {
        private bool verif = false;
        private int forIncrement = 0;
        private int index = 0;
        private const string gglUrl = "https://www.google.com/";
        public Extention1() {
            InitializeComponent();
        }  

        private void searchBtt_Click(object sender, EventArgs e)
        {
            web.Navigate(search.Text);
            index = forIncrement;
            history.Items.Add(search.Text.ToString());
        }
       
        private void Extention1_Load(object sender, EventArgs e)
        {
            index = forIncrement;
            history.Items.Add("<History>");
            history.Items.Add(gglUrl);
            web.Navigate(gglUrl);
            search.Text = gglUrl;
        }
         
        private void history_SelectedIndexChanged(object sender, EventArgs e)
        {
            //var link = new Uri(history.SelectedIndex);
            web.Navigate(new Uri(history.Items[history.SelectedIndex].ToString()));
            search.Text = history.Items[history.SelectedIndex].ToString();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}