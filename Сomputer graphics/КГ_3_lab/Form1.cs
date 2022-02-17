using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace КГ_3_lab
{
    public partial class Form1 : Form
    {

        private List<string> custom_data = new List<string>();
        private GraphicsPath[] graphics_paths = new GraphicsPath[2];
        public Form1()
        {
            InitializeComponent();

            toolTip1.SetToolTip(textBox1, "Перечислите дополнительные данные через запятую. Данные используются в соответствии с порядком ключевых слов в текущем действии.");

            int half_height = pictureBox1.Height / 2, half_width = pictureBox1.Width / 2;
            int size_x = 50, size_y = 100;

            Point[] p1 =
             {
                 new Point(half_width - size_x, half_height),
                 new Point(half_width + size_x, half_height),
                 new Point(half_width + size_x, half_height - size_y),
                 new Point(half_width - size_x, half_height - size_y),
             };
            Point[] p2 =
             {
                 new Point(half_width, half_height + size_x),
                 new Point(half_width - size_x, half_height),
                 new Point(half_width + size_x, half_height)
             };

            for (int i = 0; i < graphics_paths.Length; i++)
                graphics_paths[i] = new GraphicsPath();

            graphics_paths[0].AddPolygon(p1);
            graphics_paths[1].AddPolygon(p2);
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.Paint += new PaintEventHandler(pictureBox1_Paint);
            PreviewKeyDown += new PreviewKeyDownEventHandler(Form1_PreviewKeyDown);
            Shown += new EventHandler(Form1_Shown);
        }

        private void Form1_Shown(Object sender, EventArgs e)
        {
            textBox1.Focus();
        }

        private bool get_custom_data(uint number_of_parameters)
        {
            string str = textBox1.Text, buf = "";

            int length_minus_one = str.Length - 1;
            custom_data.Clear();
            for (int i = 0; i < str.Length; i++)
            {
                if ((Char.IsDigit(str[i]) || str[i] == '.') && str[i] != ' ' && str[i] != ',' && str[i] != '-')
                    buf += str[i];
                else if(str[i] != '.' && str[i] != ' ' && str[i] != ',' && str[i] != '-')
                {
                    MessageBox.Show("Данные введены в неверном формате.");
                    return false;
                }
                if (buf.Length != 0 && (str[i] == ',' || i == length_minus_one))
                    custom_data.Add(buf);
            }

            if (custom_data.Count != number_of_parameters)
            {
                MessageBox.Show("Данные не введены или введены неверно.");
                return false;
            }

            return true;
        }

        private void Form1_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                case Keys.Down:
                case Keys.Left:
                case Keys.Right:
                    e.IsInputKey = true;
                    break;
            }
        }

        public void Form1_AxisShiftKeyDown(object sender, KeyEventArgs e)
        {
            int offset = 20;
            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(1, 0, 0, 0, 1, 0, 0, -offset, 1);
                    break;
                case Keys.Down:
                    transform_shape(1, 0, 0, 0, 1, 0, 0, offset, 1);
                    break;
                case Keys.Left:
                    transform_shape(1, 0, 0, 0, 1, 0, -offset, 0, 1);
                    break;
                case Keys.Right:
                    transform_shape(1, 0, 0, 0, 1, 0, offset, 0, 1);
                    break;
            }
        }
        public void Form1_AxisMirroringKeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(1, 0, 0, 0, -1, 0, 0, 400, 1);
                    break;
                case Keys.Down:
                    transform_shape(1, 0, 0, 0, -1, 0, 0, 700, 1);
                    break;
                case Keys.Left:
                    transform_shape(-1, 0, 0, 0, 1, 0, 500, 0, 1);
                    break;
                case Keys.Right:
                    transform_shape(-1, 0, 0, 0, 1, 0, 1000, 0, 1);
                    break;
            }
        }
        public void Form1_EquationMirroringKeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(0, 1, 0, 1, 0, 0, 0, 0, 1);
                    break;
            }
        }
        public void Form1_ScalingKeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(1, 0, 0, 0, 1.4, 0, 0, -110, 1);
                    break;
                case Keys.Down:
                    transform_shape(1, 0, 0, 0, 0.4, 0, 0, 160, 1);
                    break;
                case Keys.Left:
                    transform_shape(0.4, 0, 0, 0, 1, 0, 210, 0, 1);
                    break;
                case Keys.Right:
                    transform_shape(1.4, 0, 0, 0, 1, 0, -140, 0, 1);
                    break;
            }
        }
        public void Form1_CenterRotationKeyDown(object sender, KeyEventArgs e)
        {
            double angle, n, m;
            Double.TryParse(custom_data[0], out angle);

            angle = angle * Math.PI / 180;
            m = 371;
            n = 270;

            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(Math.Cos(angle), Math.Sin(angle), 0, -Math.Sin(angle), Math.Cos(angle), 0, -m*(Math.Cos(angle)-1)+n* Math.Sin(angle), -n * (Math.Cos(angle) - 1) - m * Math.Sin(angle), 0.01);
                    break;
                case Keys.Down:
                    transform_shape(Math.Cos(-angle), Math.Sin(-angle), 0, -Math.Sin(-angle), Math.Cos(-angle), 0, -m * (Math.Cos(-angle) - 1) + n * Math.Sin(-angle), -n * (Math.Cos(-angle) - 1) - m * Math.Sin(-angle), 0.01);
                    break;
            }
        }
        public void Form1_CustomRotationKeyDown(object sender, KeyEventArgs e)
        {
            double angle, n, m;
            Double.TryParse(custom_data[0], out angle);
            Double.TryParse(custom_data[1], out m);
            Double.TryParse(custom_data[2], out n);

            angle = angle * Math.PI / 180;

            switch (e.KeyCode)
            {
                case Keys.Up:
                    transform_shape(Math.Cos(angle), Math.Sin(angle), 0, -Math.Sin(angle), Math.Cos(angle), 0, -m * (Math.Cos(angle) - 1) + n * Math.Sin(angle), -n * (Math.Cos(angle) - 1) - m * Math.Sin(angle), 0.01);
                    break;
                case Keys.Down:
                    transform_shape(Math.Cos(-angle), Math.Sin(-angle), 0, -Math.Sin(-angle), Math.Cos(-angle), 0, -m * (Math.Cos(-angle) - 1) + n * Math.Sin(-angle), -n * (Math.Cos(-angle) - 1) - m * Math.Sin(-angle), 0.01);
                    break;
            }
        }

        private void pictureBox1_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
        {
            int half_height = pictureBox1.Height / 2, half_width = pictureBox1.Width / 2;
            Graphics gr = e.Graphics;

            gr.Clear(Color.White);

            gr.DrawLine(Pens.BlueViolet, half_width, 0, half_width, pictureBox1.Height);
            gr.DrawLine(Pens.BlueViolet, 0, half_height, pictureBox1.Width, half_height);

            for (int i = 0; i < graphics_paths.Length; i++)
                gr.DrawPath(Pens.CadetBlue, graphics_paths[i]);

            Region reg = new Region(graphics_paths[0]);
            for (int i = 1; i < graphics_paths.Length; i++)
                reg.Intersect(graphics_paths[i]);
            gr.FillRegion(Brushes.CadetBlue, reg);
        }
        private void matrix_multiply(ref PointF[] points, in double[,] transform_matrix)
        {
            double[,] result = new double[points.Length, 3];
            for (int i = 0; i < points.Length; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    result[i, j] += points[i].X * transform_matrix[0, j];
                    result[i, j] += points[i].Y * transform_matrix[1, j];
                    result[i, j] += 1 * transform_matrix[2, j];
                }
                points[i].X = (float)result[i, 0];
                points[i].Y = (float)result[i, 1];
            }
        }
        private void transform_shape(double a, double b, int p, double c, double d, double q, double m, double n, double s)
        {
            double[,] transform_matrix = new double[3, 3]
            {
                {a,b,p},
                {c,d,q},
                {m,n,s}
            };

            PointF[] points;
            for (int i=0; i<graphics_paths.Length; i++)
            {
                points = graphics_paths[i].PathPoints;
                matrix_multiply(ref points, in transform_matrix);
                graphics_paths[i] = new GraphicsPath(points, graphics_paths[i].PathTypes);
            }

            pictureBox1.Invalidate();
        }
        private void restore_defaults()
        {
            textBox1.Text = "";
            label4.Text = "—";

            int half_height = pictureBox1.Height / 2, half_width = pictureBox1.Width / 2;
            int size_x = 50, size_y = 100;

            Point[] p1 =
             {
                 new Point(half_width - size_x, half_height),
                 new Point(half_width + size_x, half_height),
                 new Point(half_width + size_x, half_height - size_y),
                 new Point(half_width - size_x, half_height - size_y),
             };
            Point[] p2 =
             {
                 new Point(half_width, half_height + size_x),
                 new Point(half_width - size_x, half_height),
                 new Point(half_width + size_x, half_height)
             };

            for (int i = 0; i < graphics_paths.Length; i++)
                graphics_paths[i] = new GraphicsPath();

            graphics_paths[0].AddPolygon(p1);
            graphics_paths[1].AddPolygon(p2);

            pictureBox1.Invalidate();
        }
        private void unsubscribeFromKeyEvent()
        {
            KeyDown -= Form1_AxisShiftKeyDown;
            KeyDown -= Form1_AxisMirroringKeyDown;
            KeyDown -= Form1_EquationMirroringKeyDown;
            KeyDown -= Form1_ScalingKeyDown;
            KeyDown -= Form1_CenterRotationKeyDown;
            KeyDown -= Form1_CustomRotationKeyDown;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.Focus();
            unsubscribeFromKeyEvent();
            KeyPreview = true;
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    label4.Text = "Стрелки: вверх, вниз, влево,\nвправо.";
                    KeyDown += Form1_AxisShiftKeyDown;
                    break;
                case 1:
                    label4.Text = "Стрелки: вверх, вниз, влево,\nвправо.";
                    KeyDown += Form1_AxisMirroringKeyDown;
                    break;
                case 2:
                    label4.Text = "Стрелки: вверх.";
                    KeyDown += Form1_EquationMirroringKeyDown;
                    break;
                case 3:
                    label4.Text = "Стрелки: вверх, вниз, влево,\nвправо.";
                    KeyDown += Form1_ScalingKeyDown;
                    break;
                case 6:
                    restore_defaults();
                    break;
                default:
                    MessageBox.Show("Введите дополнительные данные и нажмите \"Принять\".");
                    label4.Text = "—";
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex)
            {
                case 4:
                    if (get_custom_data(1))
                    {
                        label4.Text = "Стрелки: вверх, вниз.";
                        KeyDown += Form1_CenterRotationKeyDown;
                    }
                    else
                        KeyDown -= Form1_CenterRotationKeyDown;
                    break;
                case 5:
                    if (get_custom_data(3))
                    {
                        label4.Text = "Стрелки: вверх, вниз.";
                        KeyDown += Form1_CustomRotationKeyDown;
                    }
                    else
                        KeyDown -= Form1_CustomRotationKeyDown;
                    break;
            }
        }
    }
}
