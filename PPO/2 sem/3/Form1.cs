using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3
{
    public partial class Form1 : Form
    {
        TextBox tb;
        public double pix = 15;
        int N = 3;
        public const double arrow_len = 15;
        public Form1()
        {
            InitializeComponent();
            SetupDataGridView();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Invalidate();
        }

        private void DG_KeyPress(object sender, KeyPressEventArgs e)
        {

            if (!(Char.IsDigit(e.KeyChar)) || (tb.Text.Length > 3 && radioButton2.Checked) ||
                    ((tb.Text.Length > 2) && radioButton1.Checked))
                if (e.KeyChar != (char)Keys.Back)
                    e.Handled = true;

        }


        private void dataGridView1_EditingControlShowing_1(object sender, DataGridViewEditingControlShowingEventArgs e)
        {
            tb = (TextBox)e.Control;
            tb.KeyPress += new KeyPressEventHandler(DG_KeyPress);
        }

        private void SetupDataGridView()
        {
            this.Controls.Add(dataGridView1);

            dataGridView1.ColumnCount = N;
            dataGridView1.RowCount = 3;

            dataGridView1.Name = "dataGridView1";
            dataGridView1.GridColor = Color.Black;
            dataGridView1.RowHeadersVisible = true;
            if (radioButton1.Checked)
                for (int i = 0; i < N; i++)
                {
                    dataGridView1[i, 0].Value = i;
                    dataGridView1[i, 1].Value = i;
                    dataGridView1[i, 2].Value = i;
                }
            else
                for (int i = 0; i < N; i++)
                {
                    dataGridView1[i, 0].Value = i * (int)pix;
                    dataGridView1[i, 1].Value = i * (int)pix;
                    dataGridView1[i, 2].Value = i * (int)pix;
                }

            if (N == 10)
            {
                dataGridView1[0, 1].Value = -5;
                dataGridView1[0, 2].Value = -5;

                dataGridView1[1, 1].Value = 0;
                dataGridView1[1, 2].Value = 3;

                dataGridView1[2, 1].Value = 4;
                dataGridView1[2, 2].Value = -3;

                dataGridView1[3, 1].Value = 6;
                dataGridView1[3, 2].Value = -5;

                dataGridView1[4, 1].Value = 5;
                dataGridView1[4, 2].Value = 0;

                dataGridView1[5, 1].Value = 5;
                dataGridView1[5, 2].Value = 5;

                dataGridView1[6, 1].Value = 0;
                dataGridView1[6, 2].Value = 5;

                dataGridView1[7, 1].Value = -6;
                dataGridView1[7, 2].Value = 5;

                dataGridView1[8, 1].Value = 3;
                dataGridView1[8, 2].Value = 0;

                dataGridView1[9, 1].Value = -3;
                dataGridView1[9, 2].Value = -4;
            }
            dataGridView1.Rows[0].HeaderCell.Value = "Point";
            dataGridView1.Rows[1].HeaderCell.Value = "X";
            dataGridView1.Rows[2].HeaderCell.Value = "Y";
            dataGridView1.Rows[0].ReadOnly = true;
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            int w = pictureBox1.Width;
            int h = pictureBox1.Height;
            if (radioButton1.Checked)
            {
                e.Graphics.TranslateTransform(w / 2, h / 2);
                DrawXAxis(new System.Drawing.Point(-w / 2, 0), new System.Drawing.Point(w / 2, 0), e.Graphics);
                DrawYAxis(new System.Drawing.Point(0, h / 2), new System.Drawing.Point(0, -h / 2), e.Graphics);
                e.Graphics.FillEllipse(Brushes.Red, -2, -2, 4, 4);
                DrawFunct(new System.Drawing.Point(-w / 2, h / 2), new System.Drawing.Point(w / 2, h / 2), w, e.Graphics);
            }
            else
            {
                DrawXAxis(new System.Drawing.Point(0, 0), new System.Drawing.Point(w, 0), e.Graphics);
                DrawYAxis(new System.Drawing.Point(0, 0), new System.Drawing.Point(0, h), e.Graphics);
                e.Graphics.FillEllipse(Brushes.Red, 0, 0, 4, 4);
                DrawFunct(new System.Drawing.Point(-w / 2, h / 2), new System.Drawing.Point(w / 2, h / 2), w, e.Graphics);
            }
        }

        private void DrawFunct(Point start, Point end, int w, Graphics g)
        {
            Point[] basic_curve = new Point[N];
            if (radioButton1.Checked)
                for (int i = 0; i < N; i++)
                    basic_curve[i] = new
                        Point(Convert.ToInt32(dataGridView1[i, 1].Value) * (int)pix,
                        Convert.ToInt32(dataGridView1[i, 2].Value) * (int)(pix));
            else
                for (int i = 0; i < N; i++)
                    basic_curve[i] = new
                        Point(Convert.ToInt32(dataGridView1[i, 1].Value),
                        Convert.ToInt32(dataGridView1[i, 2].Value));
            switch (N)
            {
                case 3:
                    MyDrawBezier3(g, basic_curve);
                    break;
                case 4:
                    MyDrawBezier4(g, basic_curve);
                    break;
                case 7:
                    DrawBezierPoly(g, basic_curve);
                    break;
                case 10:
                    Point[] line = new Point[3];
                    Point[] curve = new Point[4];

                    Array.Copy(basic_curve, 0, curve, 0, 4);
                    MyDrawBezier4(g, curve);

                    Array.Copy(basic_curve, 3, line, 0, 3);
                    MyDrawBezier3(g, line);

                    Array.Copy(basic_curve, 5, line, 0, 3);
                    MyDrawBezier3(g, line);

                    Array.Copy(basic_curve, 7, curve, 0, 3);
                    Array.Copy(basic_curve, 0, curve, 3, 1);
                    MyDrawBezier4(g, curve);
                    break;
            }
        }

        private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            switch (e.Node.Index)
            {
                case 0:
                    N = 3;
                    SetupDataGridView();
                    dataGridView1.Show();
                    break;
                case 1:
                    N = 4;
                    SetupDataGridView();
                    dataGridView1.Show();
                    break;
                case 2:
                    N = 7;
                    SetupDataGridView();
                    dataGridView1.Show();
                    break;
                case 3:
                    N = 10;
                    SetupDataGridView();
                    dataGridView1.Hide();
                    break;
            }
        }

        int fuctorial(int n)
        {
            int res = 1;
            for (int i = 1; i <= n; i++)
                res *= i;
            return res;
        }

        float polinom(int i, int n, float t)// полином Бернштейна
        {
            return (fuctorial(n) / (fuctorial(i) * fuctorial(n - i))) * (float)Math.Pow(t, i) * (float)Math.Pow(1 - t, n - i);
        }
        
        void DrawBezierPoly(Graphics gr, Point[] Arr)
        {
            int j = 0;
            float step = 0.01f;// шаг 0.01
            Point[] points = new Point[101];
            for (float t = 0; t < 1; t += step)
            {
                float ytmp = 0;
                float xtmp = 0;
                for (int i = 0; i < Arr.GetLength(0); i++)
                {
                    float b = polinom(i, Arr.GetLength(0) - 1, t);
                    xtmp += Arr[i].X * b;
                    ytmp += Arr[i].Y * b;
                }
                points[j] = new Point((int)xtmp, (int)ytmp);
                j++;
            }
            Pen MyPen = new Pen(Color.BlueViolet, 3);
            gr.DrawLines(MyPen, points);
        }
        void MyDrawBezier4(Graphics gr, Point[] Arr)
        {
            double Step = 1.034 / (double)(Arr[3].X - Arr[0].X);
            Point[] points = new Point[2];
            double t = 0;
            points[0] = new Point(Arr[0].X, Arr[0].Y);
            for (int i = Arr[0].X; i < Arr[3].X; i++)
            {
                t = (double)(i - Arr[0].X) * Step;
                double q1 = t * t * t * (-1) + t * t * 3 + t * (-3) + 1;
                double q2 = t * t * t * 3 + t * t * (-6) + t * 3;
                double q3 = t * t * t * (-3) + t * t * 3;
                double q4 = t * t * t;
                double qx = q1 * Arr[0].X + q2 * Arr[1].X + q3 * Arr[2].X + q4 * Arr[3].X;
                double qy = q1 * Arr[0].Y + q2 * Arr[1].Y + q3 * Arr[2].Y + q4 * Arr[3].Y;
                points[1].X = (int)qx;
                points[1].Y = (int)qy;
                Pen MyPen = new Pen(Color.BlueViolet, 3);
                gr.DrawLines(MyPen, points);
                points[0] = points[1];
            }
        }
        void MyDrawBezier3(Graphics gr, Point[] Arr)
        {
            if (Arr[0].X > Arr[2].X) { Point swap = Arr[0]; Arr[0] = Arr[2]; Arr[2] = swap; }
            double Step = 1.0 / (double)(Arr[2].X - Arr[0].X);
            Point[] points = new Point[2];
            double t = 0;
            points[0] = new Point(Arr[0].X, Arr[0].Y);
            for (int i = Arr[0].X; i < Arr[2].X; i++)
            {
                t = (double)(i - Arr[0].X) * Step;
                double q1 = Math.Pow(1 - t, 2);
                double q2 = 2 * t * (1 - t);
                double q3 = t * t;
                double qx = q1 * Arr[0].X + q2 * Arr[1].X + q3 * Arr[2].X;
                double qy = q1 * Arr[0].Y + q2 * Arr[1].Y + q3 * Arr[2].Y;
                points[1].X = (int)qx;
                points[1].Y = (int)qy;
                Pen MyPen = new Pen(Color.BlueViolet, 3);
                gr.DrawLines(MyPen, points);
                points[0] = points[1];
            }
        }

        private void DrawXAxis(System.Drawing.Point start, System.Drawing.Point end, Graphics g)
        {
            if (radioButton1.Checked)
            {
                for (double i = pix; i < end.X - Form1.arrow_len; i += pix)
                {
                    g.DrawLine(Pens.Black, (int)i, -5, (int)i, 5);
                    DrawText(new System.Drawing.Point((int)i, 5), (i / pix).ToString(), g);
                }
                for (double i = -pix; i > start.X; i -= pix)
                {
                    g.DrawLine(Pens.Black, (int)i, -5, (int)i, 5);
                    DrawText(new System.Drawing.Point((int)i, 5), (i / pix).ToString(), g);
                }
            }
            else
            {
                for (double i = 40; i < end.X - Form1.arrow_len; i += 40)
                {
                    g.DrawLine(Pens.Black, (int)i, -5, (int)i, 5);
                    DrawText(new System.Drawing.Point((int)i, 5), (i).ToString(), g);
                }
            }
            g.DrawLine(Pens.Black, start, end);
            g.DrawLines(Pens.Black, GetArrow(start.X, start.Y, end.X, end.Y, (int)Form1.arrow_len));
            DrawText(new System.Drawing.Point(end.X * 98 / 100, end.Y), "x", g, false);
        }

        private void DrawYAxis(System.Drawing.Point start, System.Drawing.Point end, Graphics g)
        {
            if (radioButton1.Checked)
            {
                for (double i = pix; i < start.Y; i += pix)
                {
                    g.DrawLine(Pens.Black, -5, (int)i, 5, (int)i);
                    DrawText(new System.Drawing.Point(5, (int)i), (-i / pix).ToString(), g, true);
                }
                for (double i = -pix; i > end.Y + Form1.arrow_len; i -= pix)
                {
                    g.DrawLine(Pens.Black, -5, (int)i, 5, (int)i);
                    DrawText(new System.Drawing.Point(5, (int)i), (-i / pix).ToString(), g, true);
                }
            }
            else
            {
                for (double i = 40; i < end.Y + Form1.arrow_len; i += 40)
                {
                    g.DrawLine(Pens.Black, -5, (int)i, 5, (int)i);
                    DrawText(new System.Drawing.Point(5, (int)i), (i).ToString(), g, true);
                }
            }
            g.DrawLine(Pens.Black, start, end);
            g.DrawLines(Pens.Black, GetArrow(start.X, start.Y, end.X, end.Y, (int)Form1.arrow_len));
            DrawText(new System.Drawing.Point(end.X * 110 / 100, end.Y * 98 / 100), "y", g, true);
        }
        private void DrawText(System.Drawing.Point Point, string text, Graphics g, bool isYAxis = false)
        {
            Font f = new Font(System.Drawing.FontFamily.GenericMonospace, 12.0F,
                                System.Drawing.FontStyle.Italic, GraphicsUnit.Pixel);
            var size = g.MeasureString(text, f);
            var pt = isYAxis
                ? new PointF(Point.X + 1, Point.Y - size.Height / 2)
                : new PointF(Point.X - size.Width / 2, Point.Y + 1);
            var rect = new RectangleF(pt, size);
            g.DrawString(text, f, Brushes.Black, rect);
        }

        private static PointF[] GetArrow(float x1, float y1, float x2, float y2, float len = 10, float width = 4)
        {
            PointF[] result = new PointF[3];
            var n = new PointF(x2 - x1, y2 - y1);
            var l = (float)Math.Sqrt(n.X * n.X + n.Y * n.Y);
            var v1 = new PointF(n.X / l, n.Y / l);
            n.X = x2 - v1.X * len;
            n.Y = y2 - v1.Y * len;
            result[0] = new PointF(n.X + v1.Y * width, n.Y - v1.X * width);
            result[1] = new PointF(x2, y2);
            result[2] = new PointF(n.X - v1.Y * width, n.Y + v1.X * width);
            return result;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                pictureBox1.Invalidate();
                for (int i = 0; i < N; i++)
                {
                    dataGridView1[i, 1].Value = Convert.ToInt32(dataGridView1[i, 1].Value) / (int)pix - 12;
                    dataGridView1[i, 2].Value = Convert.ToInt32(dataGridView1[i, 2].Value) / (int)pix - 5;
                }
            }
        }
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked)
            {
                pictureBox1.Invalidate();
                for (int i = 0; i < N; i++)
                {
                    dataGridView1[i, 1].Value = Convert.ToInt32(dataGridView1[i, 1].Value) * (int)pix + pictureBox1.Width / 2;
                    dataGridView1[i, 2].Value = Convert.ToInt32(dataGridView1[i, 2].Value) * (int)pix + pictureBox1.Height / 2;
                }
            }
        }
    }
}
