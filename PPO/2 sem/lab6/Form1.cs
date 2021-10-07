using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab6
{
    public partial class Form1 : Form
    {
        int N;
        double start;
        double end;
        double[] x;
        double[] y;
        double[] h;
        double[] l;
        double[] delta;
        double[] lambda;
        double[] c;
        double[] d;
        double[] b;


        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.chart1.Series[1].Points.Clear();
            try
            {
                N = Convert.ToInt32(comboBox1.Text);
            }
            catch
            {
                MessageBox.Show("Неверное значение n, a или b!\n ");
            }
            x = new double[N + 1];
            y = new double[N + 1];
            h = new double[N + 1];
            l = new double[N + 1];
            delta = new double[N + 1];
            lambda = new double[N + 1];
            c = new double[N + 1];
            d = new double[N + 1];
            b = new double[N + 1];
            int i;

            try
            {
                for (i = 0; i < N + 1; i++)
                {

                    x[i] = Convert.ToDouble(dataGridView1.Rows[i].Cells[0].Value);
                    y[i] = Convert.ToDouble(dataGridView1.Rows[i].Cells[1].Value);
                }
            }
            catch { MessageBox.Show("Неверное значение в матрице"); }

            try
            {
                for (i = 1; i <= N; i++)
                {
                    h[i] = x[i] - x[i - 1];
                    l[i] = (y[i] - y[i - 1]) / h[i];
                }
                delta[1] = -h[2] / (2 * (h[1] + h[2]));
                lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);
                for (i = 3; i <= N; i++)
                {
                    delta[i - 1] = -h[i] / (2 * h[i - 1] + 2 * h[i] + h[i - 1] * delta[i - 2]);
                    lambda[i - 1] = (3 * l[i] - 3 * l[i - 1] - h[i - 1] * lambda[i - 2]) / (2 * h[i - 1] + 2 * h[i] + h[i - 1] * delta[i - 2]);
                }
                c[0] = 0;
                c[N] = 0;
                for (i = N; i >= 2; i--)
                {
                    c[i - 1] = delta[i - 1] * c[i] + lambda[i - 1];
                }
                for (i = 1; i <= N; i++)
                {
                    d[i] = (c[i] - c[i - 1]) / (3 * h[i]);
                    b[i] = l[i] + (2 * c[i] * h[i] + h[i] * c[i - 1]) / 3;
                }
            }
            catch { MessageBox.Show("Неверное значение в матрице"); }

            dataGridView2.RowCount = N;
            dataGridView2.ColumnCount = 4;
            for (i = 1; i < N; i++)
            {
                dataGridView2.Rows[i - 1].Cells[0].Value = y[i];
                dataGridView2.Rows[i - 1].Cells[1].Value = b[i];
                dataGridView2.Rows[i - 1].Cells[2].Value = c[i];
                dataGridView2.Rows[i - 1].Cells[3].Value = d[i];
            }

            try
            {
                start = x[0];
                end = x[N - 1];
            }
            catch { MessageBox.Show("Неверное значение n, a или b!\n "); }
            double step = (Math.Abs(end - start)) / N;

            for (double s = start; s <= end; s += step)
            {
                for (i = 1; i <= N; i++)
                {
                    if (s >= x[i - 1] && s <= x[i])
                    {
                        break;
                    }


                }
                double F = y[i] + b[i] * (s - x[i]) + c[i] * Math.Pow(s - x[i], 2) + d[i] * Math.Pow(s - x[i], 3);
                this.chart1.Series[1].Points.AddXY(s, F);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                this.chart1.Series[1].Points.Clear();
                this.chart1.Series[0].Points.Clear();
                int n = Convert.ToInt32(comboBox1.Text);


                double a = Convert.ToDouble(textBox1.Text);
                double b = Convert.ToDouble(textBox2.Text);


                double step = (Math.Abs(a - b)) / n;
                double x, y;
                this.chart1.Series[0].Points.Clear();
                x = a;

                dataGridView1.RowCount = n + 1;
                dataGridView1.ColumnCount = 2;
                int i = 0;
                while (Math.Abs(x - b) > 1e-6)
                {
                    y = (-1) * Math.Sin(x * x);
                    this.chart1.Series[0].Points.AddXY(x, y);
                    dataGridView1.Rows[i].Cells[0].Value = x;
                    dataGridView1.Rows[i].Cells[1].Value = y;
                    i++;
                    x += step;
                }


            }
            catch
            {
                MessageBox.Show("Неверное значение n, a или b!\n ");
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {

            try
            {
                double _x = Convert.ToDouble(textBox3.Text);
                double a_i = Convert.ToDouble(textBox1.Text);
                double b_i = Convert.ToDouble(textBox2.Text);
                if (_x < a_i || _x > b_i) { throw new Exception(); }
                int i;
                for (i = 1; i <= N; i++)
                {
                    if (_x >= x[i - 1] && _x <= x[i])
                    {
                        break;
                    }


                }
                double F = y[i] + b[i] * (_x - x[i]) + c[i] * Math.Pow(_x - x[i], 2) + d[i] * Math.Pow(_x - x[i], 3);
                textBox4.Text = Convert.ToString(F);
                textBox5.Text= Convert.ToString(-Math.Sin(_x * _x));
            }
            catch
            {
                MessageBox.Show("Неверное значение x или еще не построен сплайн");
            }
        }
    }
}
