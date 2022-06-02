namespace ExpertSystem
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.next_b = new System.Windows.Forms.Button();
            this.start_b = new System.Windows.Forms.Button();
            this.back_b = new System.Windows.Forms.Button();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.Qtext = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // next_b
            // 
            this.next_b.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.next_b.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.next_b.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.next_b.FlatAppearance.BorderSize = 2;
            this.next_b.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.next_b.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.next_b.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.next_b.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.next_b.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.next_b.ForeColor = System.Drawing.SystemColors.Desktop;
            this.next_b.Location = new System.Drawing.Point(619, 296);
            this.next_b.Name = "next_b";
            this.next_b.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.next_b.Size = new System.Drawing.Size(107, 41);
            this.next_b.TabIndex = 0;
            this.next_b.Text = "Далее";
            this.next_b.UseVisualStyleBackColor = false;
            this.next_b.Click += new System.EventHandler(this.next_b_Click);
            // 
            // start_b
            // 
            this.start_b.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.start_b.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.start_b.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.start_b.FlatAppearance.BorderSize = 2;
            this.start_b.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.start_b.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.start_b.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.start_b.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.start_b.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.start_b.ForeColor = System.Drawing.SystemColors.Desktop;
            this.start_b.Location = new System.Drawing.Point(140, 296);
            this.start_b.Name = "start_b";
            this.start_b.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.start_b.Size = new System.Drawing.Size(118, 41);
            this.start_b.TabIndex = 1;
            this.start_b.Text = "В начало";
            this.start_b.UseVisualStyleBackColor = false;
            this.start_b.Click += new System.EventHandler(this.start_b_Click);
            // 
            // back_b
            // 
            this.back_b.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.back_b.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.back_b.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.back_b.FlatAppearance.BorderSize = 2;
            this.back_b.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.back_b.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.back_b.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.back_b.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.back_b.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.back_b.ForeColor = System.Drawing.SystemColors.Desktop;
            this.back_b.Location = new System.Drawing.Point(502, 296);
            this.back_b.Name = "back_b";
            this.back_b.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.back_b.Size = new System.Drawing.Size(111, 41);
            this.back_b.TabIndex = 2;
            this.back_b.Text = "Назад";
            this.back_b.UseVisualStyleBackColor = false;
            this.back_b.Click += new System.EventHandler(this.back_b_Click);
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.checkedListBox1.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.checkedListBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.checkedListBox1.CheckOnClick = true;
            this.checkedListBox1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(12, 49);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.checkedListBox1.Size = new System.Drawing.Size(714, 216);
            this.checkedListBox1.TabIndex = 3;
            this.checkedListBox1.SelectedIndexChanged += new System.EventHandler(this.checkedListBox1_SelectedIndexChanged);
            // 
            // Qtext
            // 
            this.Qtext.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Qtext.AutoSize = true;
            this.Qtext.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Qtext.Location = new System.Drawing.Point(12, 12);
            this.Qtext.Name = "Qtext";
            this.Qtext.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Qtext.Size = new System.Drawing.Size(59, 22);
            this.Qtext.TabIndex = 4;
            this.Qtext.Text = "label1";
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button1.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.button1.FlatAppearance.BorderSize = 2;
            this.button1.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button1.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(620, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(106, 31);
            this.button1.TabIndex = 5;
            this.button1.Text = "Помощь";
            this.button1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.button2.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button2.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.button2.FlatAppearance.BorderSize = 2;
            this.button2.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button2.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button2.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button2.Location = new System.Drawing.Point(309, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(305, 31);
            this.button2.TabIndex = 6;
            this.button2.Text = "Подробнее о языке в интернете";
            this.button2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button3.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button3.FlatAppearance.BorderColor = System.Drawing.Color.AliceBlue;
            this.button3.FlatAppearance.BorderSize = 2;
            this.button3.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button3.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button3.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button3.ForeColor = System.Drawing.SystemColors.Desktop;
            this.button3.Location = new System.Drawing.Point(16, 296);
            this.button3.Name = "button3";
            this.button3.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.button3.Size = new System.Drawing.Size(118, 41);
            this.button3.TabIndex = 7;
            this.button3.Text = "Выход";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(738, 349);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Qtext);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.back_b);
            this.Controls.Add(this.start_b);
            this.Controls.Add(this.next_b);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Экспертная система по выбору ЯП";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Button next_b;
        public System.Windows.Forms.Button start_b;
        public System.Windows.Forms.Button back_b;
        public System.Windows.Forms.CheckedListBox checkedListBox1;
        public System.Windows.Forms.Label Qtext;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        public System.Windows.Forms.Button button3;
    }
}

