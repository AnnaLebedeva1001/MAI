using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab7
{
    public partial class Form1 : Form
    {
        public double function(double x, double y)
        {
            return x * x * x + y;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.chart2.Series[0].Points.Clear();
            double a = 0, b = 1, h = 0.1, n = (b - a) / h;
            double[] X = new double[(int)n+1];
            double[] Y = new double[(int)n+1];
            X[0] = a; Y[0] = -6;
            for (int i = 1; i <=(int) n; i++)
            {
                X[i] = a + i * h;
                Y[i] = Y[i - 1] + h * function(X[i - 1], Y[i - 1]);
            }
            for (int i = 0; i <= (int)n; i++)
            {
                this.chart2.Series[0].Points.AddXY(X[i], Y[i]);
            }
            dataGridView1.RowCount = (int)n+1;
            dataGridView1.ColumnCount= 2;
            for (int i = 0; i <= (int)n; i++)
            {
                dataGridView1.Rows[i].Cells[0].Value = X[i];
                dataGridView1.Rows[i].Cells[1].Value = Y[i];
            }







        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.chart1.Series[0].Points.Clear();
            double a = 0, b = 1, h = 0.1, n = (b - a) / h;
            double[] X = new double[(int)n+1];
            double[] Y = new double[(int)n+1];
            double[] Y1 = new double[(int)n + 1];
            double[] Y2 = new double[(int)n + 1];
            double[] Y3 = new double[(int)n + 1];
            double[] Y4 = new double[(int)n + 1];
            X[0] = a; Y[0] = -6;
            for (int i = 1; i <= (int)n; i++)
            {
                X[i] = a + i * h;
                Y1[i] = h * function(X[i - 1], Y[i - 1]);
                Y2[i] = h * function(X[i - 1] + h / 2.0, Y[i - 1] + Y1[i] / 2.0);
                Y3[i] = h * function(X[i - 1] + h / 2, Y[i - 1] + Y2[i] / 2);
                Y4[i] = h * function(X[i - 1] + h, Y[i - 1] + Y3[i]);
                Y[i] = Y[i - 1] + (Y1[i] + 2 * Y2[i] + 2 * Y3[i] + Y4[i]) / 6;
            }
            for (int i = 0; i <= (int)n; i++)
            {
                this.chart1.Series[0].Points.AddXY(X[i], Y[i]);

            }
            dataGridView2.RowCount = (int)n+1;
            dataGridView2.ColumnCount = 2;
            for (int i = 0; i <= (int)n; i++)
            {
                dataGridView2.Rows[i].Cells[0].Value = X[i];
                dataGridView2.Rows[i].Cells[1].Value = Y[i];
            }
        }
    }
}
