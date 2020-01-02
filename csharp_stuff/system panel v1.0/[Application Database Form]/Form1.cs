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
    public partial class AppForm : Form
    {
        private readonly int ZERO = 0;
        private readonly double PI = Math.PI;
        private int forIncrement = 0;

        public AppForm() => InitializeComponent();
        private void b1_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] codeblocks opened";
            listBox1.Items.Add(item);
            System.Diagnostics.Process.Start("C:\\Program Files (x86)\\CodeBlocks\\codeblocks.exe");
        }
        private void b2_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] visualstudio opened";
            listBox1.Items.Add(item);
            System.Diagnostics.Process.Start("C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\devenv.exe");
        }
        private void b3_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] facebook opened";
            listBox1.Items.Add(item);
            System.Diagnostics.Process.Start("https://www.facebook.com/");         
        }
        //private void b4_Click(object sender, EventArgs e)
        //{
        //    System.Diagnostics.Process.Start("link to video"); 
        //}
        private void b5_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] rocket league opened";
            listBox1.Items.Add(item);
            System.Diagnostics.Process.Start("steam://rungameid/252950");
        }
        private void b6_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] command prompt opened";
            listBox1.Items.Add(item);
            System.Diagnostics.Process.Start("C:\\Windows\\System32\\cmd.exe");
        }
        //listBox1.Items[listBox1.SelectedIndex].ToString();
        private void indepButton_Click(object sender, EventArgs e)
        {
            listBox1.Items.Add(forIncrement++);
        }
        
        private void loadB_Click(object sender, EventArgs e)
        {
            if (pgb1.Value.Equals(100))
            {
                var item = "[" + forIncrement++.ToString() + "] progressbar1 loaded";
                listBox1.Items.Add(item);
            }
            else
            {
                var item = "[" + forIncrement++.ToString() + "] progressbar1 loading";
                listBox1.Items.Add(item);
                timer1.Start();
            }            
        }
        private void timer_Tick(object sender, EventArgs e)
        {
            pgb1.Increment(5);
            if (pgb1.Value.Equals(100))
            {
                var item = "[" + forIncrement++.ToString() + "] progressbar1 loaded";
                listBox1.Items.Add(item);
                timer1.Stop();
            }
        }       

        private void pgb_Click(object sender, EventArgs e)
        {
            if(pgb1.Value.Equals(100))
            {
                MessageBox.Show("I'm ready to jump!");
            }
            else if (pgb1.Value > 0 && pgb1.Value < 100)
            {
                MessageBox.Show("Dont touch me!\nI'm loading for jump...");
            }
            else if(pgb1.Value.Equals(0))
            {
                MessageBox.Show("I'm not ready to jump!");
            }
        }

        private void newWindow_Click(object sender, EventArgs e)
        {
            var item = "[" + forIncrement++.ToString() + "] browser opened";
            listBox1.Items.Add(item);
            Extention1 ex1 = new Extention1();
            ex1.Show();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            clock1.Text = DateTime.Now.ToString("T");
        }

        private void AppForm_Load(object sender, EventArgs e)
        {
            System.Timers.Timer timer = new System.Timers.Timer();
            timer.Interval = 1000;
            timer.Elapsed += Timer_Elapsed;
            timer.Start();

            listBox1.Items.Add("[List of actions]");
            listBox1.Items.Add("-----------------");
        }

        private void Timer_Elapsed(object sender, System.Timers.ElapsedEventArgs e)
        {
            Invoke(new MethodInvoker(delegate ()
            {
                clock1.Text = DateTime.Now.ToString();
            }));
        }

        private void exitB_Click(object sender, EventArgs e)
        {
            MessageBox.Show("System Off", "<Info>", 
                MessageBoxButtons.AbortRetryIgnore, 
                MessageBoxIcon.Information);
            this.Close();
        }
   
    }
}

