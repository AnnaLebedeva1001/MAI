
namespace КГ_4_lab
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Moving_Left = new System.Windows.Forms.Button();
            this.Moving_Right = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.Reduce = new System.Windows.Forms.Button();
            this.Increase = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Reflection_Z = new System.Windows.Forms.Button();
            this.Reflection_Y = new System.Windows.Forms.Button();
            this.Reflection_X = new System.Windows.Forms.Button();
            this.Isometric_Projection = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.Length = new System.Windows.Forms.TextBox();
            this.Angle = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.Central_Angle = new System.Windows.Forms.TextBox();
            this.Colorize = new System.Windows.Forms.Button();
            this.Restore_Position = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.Rotation_X = new System.Windows.Forms.TextBox();
            this.Rotation_Y = new System.Windows.Forms.TextBox();
            this.Rotation_Z = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(225, 11);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(641, 458);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            // 
            // Moving_Left
            // 
            this.Moving_Left.BackColor = System.Drawing.Color.LightPink;
            this.Moving_Left.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Moving_Left.Font = new System.Drawing.Font("Arial Black", 12F, System.Drawing.FontStyle.Bold);
            this.Moving_Left.Location = new System.Drawing.Point(75, 32);
            this.Moving_Left.Margin = new System.Windows.Forms.Padding(2);
            this.Moving_Left.Name = "Moving_Left";
            this.Moving_Left.Size = new System.Drawing.Size(46, 30);
            this.Moving_Left.TabIndex = 1;
            this.Moving_Left.Text = "-";
            this.Moving_Left.UseVisualStyleBackColor = false;
            this.Moving_Left.Click += new System.EventHandler(this.Moving_Left_Click);
            // 
            // Moving_Right
            // 
            this.Moving_Right.BackColor = System.Drawing.Color.LightPink;
            this.Moving_Right.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Moving_Right.Font = new System.Drawing.Font("Arial Black", 12F, System.Drawing.FontStyle.Bold);
            this.Moving_Right.Location = new System.Drawing.Point(139, 32);
            this.Moving_Right.Margin = new System.Windows.Forms.Padding(2);
            this.Moving_Right.Name = "Moving_Right";
            this.Moving_Right.Size = new System.Drawing.Size(46, 30);
            this.Moving_Right.TabIndex = 2;
            this.Moving_Right.Text = "+";
            this.Moving_Right.UseVisualStyleBackColor = false;
            this.Moving_Right.Click += new System.EventHandler(this.Moving_Right_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(2, 11);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(193, 19);
            this.label1.TabIndex = 3;
            this.label1.Text = "Перемещение по оси:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(2, 62);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(171, 19);
            this.label2.TabIndex = 4;
            this.label2.Text = "Масштабирование:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // comboBox1
            // 
            this.comboBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.comboBox1.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "X",
            "Y",
            "Z"});
            this.comboBox1.Location = new System.Drawing.Point(7, 32);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(2);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(55, 25);
            this.comboBox1.TabIndex = 5;
            // 
            // Reduce
            // 
            this.Reduce.BackColor = System.Drawing.Color.LightPink;
            this.Reduce.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Reduce.Font = new System.Drawing.Font("Arial Black", 12F, System.Drawing.FontStyle.Bold);
            this.Reduce.Location = new System.Drawing.Point(4, 83);
            this.Reduce.Margin = new System.Windows.Forms.Padding(2);
            this.Reduce.Name = "Reduce";
            this.Reduce.Size = new System.Drawing.Size(46, 30);
            this.Reduce.TabIndex = 6;
            this.Reduce.Text = "-";
            this.Reduce.UseVisualStyleBackColor = false;
            this.Reduce.Click += new System.EventHandler(this.Reduce_Click);
            // 
            // Increase
            // 
            this.Increase.BackColor = System.Drawing.Color.LightPink;
            this.Increase.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Increase.Font = new System.Drawing.Font("Arial Black", 12F, System.Drawing.FontStyle.Bold);
            this.Increase.Location = new System.Drawing.Point(76, 83);
            this.Increase.Margin = new System.Windows.Forms.Padding(2);
            this.Increase.Name = "Increase";
            this.Increase.Size = new System.Drawing.Size(46, 30);
            this.Increase.TabIndex = 7;
            this.Increase.Text = "+";
            this.Increase.UseVisualStyleBackColor = false;
            this.Increase.Click += new System.EventHandler(this.Increase_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Tahoma", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(-1, 125);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(169, 19);
            this.label3.TabIndex = 8;
            this.label3.Text = "Отражение на оси:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Reflection_Z
            // 
            this.Reflection_Z.BackColor = System.Drawing.Color.LightPink;
            this.Reflection_Z.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Reflection_Z.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Reflection_Z.Location = new System.Drawing.Point(149, 146);
            this.Reflection_Z.Margin = new System.Windows.Forms.Padding(2);
            this.Reflection_Z.Name = "Reflection_Z";
            this.Reflection_Z.Size = new System.Drawing.Size(46, 30);
            this.Reflection_Z.TabIndex = 9;
            this.Reflection_Z.Text = "Z";
            this.Reflection_Z.UseVisualStyleBackColor = false;
            this.Reflection_Z.Click += new System.EventHandler(this.Reflection_Z_Click);
            // 
            // Reflection_Y
            // 
            this.Reflection_Y.BackColor = System.Drawing.Color.LightPink;
            this.Reflection_Y.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Reflection_Y.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Reflection_Y.Location = new System.Drawing.Point(75, 146);
            this.Reflection_Y.Margin = new System.Windows.Forms.Padding(2);
            this.Reflection_Y.Name = "Reflection_Y";
            this.Reflection_Y.Size = new System.Drawing.Size(46, 30);
            this.Reflection_Y.TabIndex = 10;
            this.Reflection_Y.Text = "Y";
            this.Reflection_Y.UseVisualStyleBackColor = false;
            this.Reflection_Y.Click += new System.EventHandler(this.Reflection_Y_Click);
            // 
            // Reflection_X
            // 
            this.Reflection_X.BackColor = System.Drawing.Color.LightPink;
            this.Reflection_X.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Reflection_X.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Reflection_X.Location = new System.Drawing.Point(3, 146);
            this.Reflection_X.Margin = new System.Windows.Forms.Padding(2);
            this.Reflection_X.Name = "Reflection_X";
            this.Reflection_X.Size = new System.Drawing.Size(46, 30);
            this.Reflection_X.TabIndex = 11;
            this.Reflection_X.Text = "X";
            this.Reflection_X.UseVisualStyleBackColor = false;
            this.Reflection_X.Click += new System.EventHandler(this.Reflection_X_Click);
            // 
            // Isometric_Projection
            // 
            this.Isometric_Projection.BackColor = System.Drawing.Color.LightPink;
            this.Isometric_Projection.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Isometric_Projection.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Isometric_Projection.Location = new System.Drawing.Point(2, 379);
            this.Isometric_Projection.Margin = new System.Windows.Forms.Padding(2);
            this.Isometric_Projection.Name = "Isometric_Projection";
            this.Isometric_Projection.Size = new System.Drawing.Size(201, 49);
            this.Isometric_Projection.TabIndex = 13;
            this.Isometric_Projection.Text = "Изометрическая проекция";
            this.Isometric_Projection.UseVisualStyleBackColor = false;
            this.Isometric_Projection.Click += new System.EventHandler(this.Isometric_Projection_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Tahoma", 10.8F);
            this.label6.Location = new System.Drawing.Point(3, 263);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(55, 18);
            this.label6.TabIndex = 15;
            this.label6.Text = "Длина:";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Tahoma", 10.8F);
            this.label7.Location = new System.Drawing.Point(1, 295);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(44, 18);
            this.label7.TabIndex = 16;
            this.label7.Text = "Угол:";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Length
            // 
            this.Length.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Length.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Length.Location = new System.Drawing.Point(62, 257);
            this.Length.Margin = new System.Windows.Forms.Padding(2);
            this.Length.Name = "Length";
            this.Length.Size = new System.Drawing.Size(97, 24);
            this.Length.TabIndex = 17;
            this.Length.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Length.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Length_KeyDown);
            // 
            // Angle
            // 
            this.Angle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Angle.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Angle.Location = new System.Drawing.Point(62, 289);
            this.Angle.Margin = new System.Windows.Forms.Padding(2);
            this.Angle.Name = "Angle";
            this.Angle.Size = new System.Drawing.Size(97, 24);
            this.Angle.TabIndex = 18;
            this.Angle.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Tahoma", 10.8F);
            this.label8.Location = new System.Drawing.Point(3, 326);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(55, 18);
            this.label8.TabIndex = 19;
            this.label8.Text = "Центр:";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Central_Angle
            // 
            this.Central_Angle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Central_Angle.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Central_Angle.Location = new System.Drawing.Point(62, 320);
            this.Central_Angle.Margin = new System.Windows.Forms.Padding(2);
            this.Central_Angle.Name = "Central_Angle";
            this.Central_Angle.Size = new System.Drawing.Size(97, 24);
            this.Central_Angle.TabIndex = 20;
            this.Central_Angle.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Central_Angle.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Central_Angle_KeyDown);
            // 
            // Colorize
            // 
            this.Colorize.BackColor = System.Drawing.Color.LightPink;
            this.Colorize.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Colorize.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Colorize.Location = new System.Drawing.Point(2, 348);
            this.Colorize.Margin = new System.Windows.Forms.Padding(2);
            this.Colorize.Name = "Colorize";
            this.Colorize.Size = new System.Drawing.Size(202, 27);
            this.Colorize.TabIndex = 21;
            this.Colorize.Text = "Раскрасить";
            this.Colorize.UseVisualStyleBackColor = false;
            this.Colorize.Click += new System.EventHandler(this.Colorize_Click);
            // 
            // Restore_Position
            // 
            this.Restore_Position.BackColor = System.Drawing.Color.LightPink;
            this.Restore_Position.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Restore_Position.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.Restore_Position.Location = new System.Drawing.Point(2, 436);
            this.Restore_Position.Margin = new System.Windows.Forms.Padding(2);
            this.Restore_Position.Name = "Restore_Position";
            this.Restore_Position.Size = new System.Drawing.Size(202, 33);
            this.Restore_Position.TabIndex = 22;
            this.Restore_Position.Text = "Исходная позиция";
            this.Restore_Position.UseVisualStyleBackColor = false;
            this.Restore_Position.Click += new System.EventHandler(this.Restore_Position_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Tahoma", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(-2, 191);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(197, 19);
            this.label9.TabIndex = 23;
            this.label9.Text = "Вращение вокруг оси:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.label10.Font = new System.Drawing.Font("Tahoma", 12F);
            this.label10.Location = new System.Drawing.Point(3, 220);
            this.label10.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(24, 19);
            this.label10.TabIndex = 24;
            this.label10.Text = "X:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.label11.Font = new System.Drawing.Font("Tahoma", 12F);
            this.label11.Location = new System.Drawing.Point(72, 220);
            this.label11.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(25, 19);
            this.label11.TabIndex = 25;
            this.label11.Text = "Y:";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.label12.Font = new System.Drawing.Font("Tahoma", 12F);
            this.label12.Location = new System.Drawing.Point(145, 220);
            this.label12.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(24, 19);
            this.label12.TabIndex = 26;
            this.label12.Text = "Z:";
            // 
            // Rotation_X
            // 
            this.Rotation_X.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Rotation_X.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Rotation_X.Location = new System.Drawing.Point(31, 215);
            this.Rotation_X.Margin = new System.Windows.Forms.Padding(2);
            this.Rotation_X.Name = "Rotation_X";
            this.Rotation_X.Size = new System.Drawing.Size(31, 24);
            this.Rotation_X.TabIndex = 27;
            this.Rotation_X.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Rotation_X.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Rotation_X_KeyDown);
            // 
            // Rotation_Y
            // 
            this.Rotation_Y.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Rotation_Y.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Rotation_Y.Location = new System.Drawing.Point(101, 215);
            this.Rotation_Y.Margin = new System.Windows.Forms.Padding(2);
            this.Rotation_Y.Name = "Rotation_Y";
            this.Rotation_Y.Size = new System.Drawing.Size(31, 24);
            this.Rotation_Y.TabIndex = 28;
            this.Rotation_Y.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Rotation_Y.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Rotation_Y_KeyDown);
            // 
            // Rotation_Z
            // 
            this.Rotation_Z.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.Rotation_Z.Font = new System.Drawing.Font("Tahoma", 10.2F);
            this.Rotation_Z.Location = new System.Drawing.Point(173, 215);
            this.Rotation_Z.Margin = new System.Windows.Forms.Padding(2);
            this.Rotation_Z.Name = "Rotation_Z";
            this.Rotation_Z.Size = new System.Drawing.Size(31, 24);
            this.Rotation_Z.TabIndex = 29;
            this.Rotation_Z.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Rotation_Z.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Rotation_Z_KeyDown);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.LightBlue;
            this.ClientSize = new System.Drawing.Size(877, 480);
            this.Controls.Add(this.Rotation_Z);
            this.Controls.Add(this.Rotation_Y);
            this.Controls.Add(this.Rotation_X);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.Restore_Position);
            this.Controls.Add(this.Colorize);
            this.Controls.Add(this.Central_Angle);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.Angle);
            this.Controls.Add(this.Length);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.Isometric_Projection);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.Moving_Right);
            this.Controls.Add(this.Moving_Left);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Increase);
            this.Controls.Add(this.Reduce);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Reflection_X);
            this.Controls.Add(this.Reflection_Y);
            this.Controls.Add(this.Reflection_Z);
            this.Controls.Add(this.pictureBox1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Лабораторная 4";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button Moving_Left;
        private System.Windows.Forms.Button Moving_Right;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Button Reduce;
        private System.Windows.Forms.Button Increase;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Reflection_Z;
        private System.Windows.Forms.Button Reflection_Y;
        private System.Windows.Forms.Button Reflection_X;
        private System.Windows.Forms.Button Isometric_Projection;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox Length;
        private System.Windows.Forms.TextBox Angle;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox Central_Angle;
        private System.Windows.Forms.Button Colorize;
        private System.Windows.Forms.Button Restore_Position;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox Rotation_X;
        private System.Windows.Forms.TextBox Rotation_Y;
        private System.Windows.Forms.TextBox Rotation_Z;
    }
}

