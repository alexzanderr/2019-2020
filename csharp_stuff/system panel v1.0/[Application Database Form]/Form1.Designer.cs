namespace _Application_Database_Form_
{
    partial class AppForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AppForm));
            this.b1 = new System.Windows.Forms.Button();
            this.b2 = new System.Windows.Forms.Button();
            this.b3 = new System.Windows.Forms.Button();
            this.b4 = new System.Windows.Forms.Button();
            this.b5 = new System.Windows.Forms.Button();
            this.b6 = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.indepButton = new System.Windows.Forms.Button();
            this.pgb1 = new System.Windows.Forms.ProgressBar();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.loadB1 = new System.Windows.Forms.Button();
            this.newWindow = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.exitB = new System.Windows.Forms.Button();
            this.clock1 = new System.Windows.Forms.Label();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // b1
            // 
            resources.ApplyResources(this.b1, "b1");
            this.b1.Name = "b1";
            this.b1.UseVisualStyleBackColor = true;
            this.b1.Click += new System.EventHandler(this.b1_Click);
            // 
            // b2
            // 
            resources.ApplyResources(this.b2, "b2");
            this.b2.Name = "b2";
            this.b2.UseVisualStyleBackColor = true;
            this.b2.Click += new System.EventHandler(this.b2_Click);
            // 
            // b3
            // 
            resources.ApplyResources(this.b3, "b3");
            this.b3.Name = "b3";
            this.b3.UseVisualStyleBackColor = true;
            this.b3.Click += new System.EventHandler(this.b3_Click);
            // 
            // b4
            // 
            resources.ApplyResources(this.b4, "b4");
            this.b4.Name = "b4";
            this.b4.UseVisualStyleBackColor = true;
            // 
            // b5
            // 
            resources.ApplyResources(this.b5, "b5");
            this.b5.Name = "b5";
            this.b5.UseVisualStyleBackColor = true;
            this.b5.Click += new System.EventHandler(this.b5_Click);
            // 
            // b6
            // 
            resources.ApplyResources(this.b6, "b6");
            this.b6.Name = "b6";
            this.b6.UseVisualStyleBackColor = true;
            this.b6.Click += new System.EventHandler(this.b6_Click);
            // 
            // listBox1
            // 
            this.listBox1.BackColor = System.Drawing.SystemColors.InfoText;
            resources.ApplyResources(this.listBox1, "listBox1");
            this.listBox1.ForeColor = System.Drawing.Color.Lime;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Name = "listBox1";
            this.listBox1.SelectionMode = System.Windows.Forms.SelectionMode.None;
            // 
            // indepButton
            // 
            resources.ApplyResources(this.indepButton, "indepButton");
            this.indepButton.Name = "indepButton";
            this.indepButton.UseVisualStyleBackColor = true;
            this.indepButton.Click += new System.EventHandler(this.indepButton_Click);
            // 
            // pgb1
            // 
            resources.ApplyResources(this.pgb1, "pgb1");
            this.pgb1.Name = "pgb1";
            this.pgb1.Click += new System.EventHandler(this.pgb_Click);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // loadB1
            // 
            resources.ApplyResources(this.loadB1, "loadB1");
            this.loadB1.Name = "loadB1";
            this.loadB1.UseVisualStyleBackColor = true;
            this.loadB1.Click += new System.EventHandler(this.loadB_Click);
            // 
            // newWindow
            // 
            resources.ApplyResources(this.newWindow, "newWindow");
            this.newWindow.Name = "newWindow";
            this.newWindow.UseVisualStyleBackColor = true;
            this.newWindow.Click += new System.EventHandler(this.newWindow_Click);
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.BackColor = System.Drawing.Color.LightSeaGreen;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label1.ForeColor = System.Drawing.SystemColors.Info;
            this.label1.Name = "label1";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.BackColor = System.Drawing.Color.LightSeaGreen;
            this.label2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label2.ForeColor = System.Drawing.SystemColors.Info;
            this.label2.Name = "label2";
            // 
            // exitB
            // 
            this.exitB.ForeColor = System.Drawing.Color.Firebrick;
            resources.ApplyResources(this.exitB, "exitB");
            this.exitB.Name = "exitB";
            this.exitB.UseVisualStyleBackColor = true;
            this.exitB.Click += new System.EventHandler(this.exitB_Click);
            // 
            // clock1
            // 
            resources.ApplyResources(this.clock1, "clock1");
            this.clock1.BackColor = System.Drawing.SystemColors.Desktop;
            this.clock1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.clock1.ForeColor = System.Drawing.Color.Lime;
            this.clock1.Name = "clock1";
            // 
            // timer2
            // 
            this.timer2.Interval = 1000;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // AppForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Desktop;
            this.Controls.Add(this.clock1);
            this.Controls.Add(this.exitB);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.newWindow);
            this.Controls.Add(this.loadB1);
            this.Controls.Add(this.pgb1);
            this.Controls.Add(this.b2);
            this.Controls.Add(this.indepButton);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.b6);
            this.Controls.Add(this.b5);
            this.Controls.Add(this.b4);
            this.Controls.Add(this.b3);
            this.Controls.Add(this.b1);
            this.ForeColor = System.Drawing.SystemColors.InfoText;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "AppForm";
            this.Load += new System.EventHandler(this.AppForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button b1;
        private System.Windows.Forms.Button b2;
        private System.Windows.Forms.Button b3;
        private System.Windows.Forms.Button b4;
        private System.Windows.Forms.Button b5;
        private System.Windows.Forms.Button b6;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button indepButton;
        private System.Windows.Forms.ProgressBar pgb1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button loadB1;
        private System.Windows.Forms.Button newWindow;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button exitB;
        private System.Windows.Forms.Label clock1;
        private System.Windows.Forms.Timer timer2;
    }
}

