namespace _Application_Database_Form_
{
    partial class Extention1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Extention1));
            this.web = new System.Windows.Forms.WebBrowser();
            this.search = new System.Windows.Forms.TextBox();
            this.title = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.searchBtt = new System.Windows.Forms.Button();
            this.history = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // web
            // 
            this.web.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.web.Location = new System.Drawing.Point(320, 81);
            this.web.MaximumSize = new System.Drawing.Size(5000, 5000);
            this.web.MinimumSize = new System.Drawing.Size(20, 20);
            this.web.Name = "web";
            this.web.Size = new System.Drawing.Size(807, 664);
            this.web.TabIndex = 0;
            this.web.Url = new System.Uri("", System.UriKind.Relative);
            // 
            // search
            // 
            this.search.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.search.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.search.ForeColor = System.Drawing.Color.DarkGray;
            this.search.Location = new System.Drawing.Point(98, 47);
            this.search.Name = "search";
            this.search.Size = new System.Drawing.Size(747, 23);
            this.search.TabIndex = 1;
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.BackColor = System.Drawing.Color.Lime;
            this.title.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.title.Location = new System.Drawing.Point(345, 9);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(120, 22);
            this.title.TabIndex = 2;
            this.title.Text = "Web Browser";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Lime;
            this.label1.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 47);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 22);
            this.label1.TabIndex = 3;
            this.label1.Text = "Search:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // searchBtt
            // 
            this.searchBtt.Font = new System.Drawing.Font("Consolas", 14.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.searchBtt.Location = new System.Drawing.Point(851, 45);
            this.searchBtt.Name = "searchBtt";
            this.searchBtt.Size = new System.Drawing.Size(145, 25);
            this.searchBtt.TabIndex = 4;
            this.searchBtt.Text = "Find";
            this.searchBtt.UseVisualStyleBackColor = true;
            this.searchBtt.Click += new System.EventHandler(this.searchBtt_Click);
            // 
            // history
            // 
            this.history.FormattingEnabled = true;
            this.history.ItemHeight = 15;
            this.history.Location = new System.Drawing.Point(12, 81);
            this.history.Name = "history";
            this.history.Size = new System.Drawing.Size(302, 664);
            this.history.TabIndex = 7;
            this.history.SelectedIndexChanged += new System.EventHandler(this.history_SelectedIndexChanged);
            // 
            // Extention1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(1139, 753);
            this.Controls.Add(this.history);
            this.Controls.Add(this.searchBtt);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.title);
            this.Controls.Add(this.search);
            this.Controls.Add(this.web);
            this.Font = new System.Drawing.Font("Consolas", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Extention1";
            this.Text = "Extention1";
            this.Load += new System.EventHandler(this.Extention1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.WebBrowser web;
        private System.Windows.Forms.TextBox search;
        private System.Windows.Forms.Label title;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button searchBtt;
        private System.Windows.Forms.ListBox history;
    }
}