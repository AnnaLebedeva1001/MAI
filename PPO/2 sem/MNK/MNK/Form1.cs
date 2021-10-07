using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MNK
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() != DialogResult.OK) return;
            string[] lines = File.ReadAllLines(openFileDialog.FileName);
            dgv.Rows.Clear();
            dgv.Rows.Add(lines.Length);
            for (int line = 0; line < lines.Length; line++)
            {
                string[] xy = lines[line].Split(new char[] { ' ', '\t', ';' }, StringSplitOptions.RemoveEmptyEntries);
                dgv.Rows[line].Cells[0].Value = xy[0];
                dgv.Rows[line].Cells[1].Value = xy[1];
            }
            ReadValues();
            Approximate();
            ShowGraphs();
        }

        double[] xt = null;
        double[] yt = null;
        double[] x = null;
        double[] y1 = null;
        double[] y2 = null;
        double[] y3 = null;

        void ReadValues()
        {
            xt = new double[dgv.Rows.Count];
            yt = new double[dgv.Rows.Count];

            for (int row = 0; row < xt.Length; row++)
            {
                double.TryParse(dgv.Rows[row].Cells[0].Value.ToString(), out xt[row]);
                double.TryParse(dgv.Rows[row].Cells[1].Value.ToString(), out yt[row]);
            }
        }

        double f1_1(double x)
        {
            return 1;
        }
        double f1_2(double x)
        {
            return x;
        }
        double f1_3(double x)
        {
            return x * x;
        }

        double f1(double x, double[] K)
        {
            return f1_1(x) * K[0] +
                   f1_2(x) * K[1] +
                   f1_3(x) * K[2];
        }

        double f2_1(double x)
        {
            return 1;
        }
        double f2_2(double x)
        {
            return 1 / x;
        }
        double f2_3(double x)
        {
            return 1 / x / x;
        }
        double f2(double x, double []K)
        {
            return f2_1(x) * K[0] +
                   f2_2(x) * K[1] +
                   f2_3(x) * K[2];
        }
        double f3_1(double x)
        {
            return 1;
        }
        double f3_2(double x)
        {
            return x;
        }
        double f3_3(double x)
        {
            return Math.Log(x);
        }
        double f3(double x, double[] K)
        {
            return f3_1(x) * K[0] +
                   f3_2(x) * K[1] +
                   f3_3(x) * K[2];
        }

        void Approximate()
        {
            ClassMNK A = new ClassMNK();

            double[] K1;
            A.DataX = xt;
            A.DataY = yt;
            A.Phi = new ClassMNK.Function[] { f1_1, f1_2, f1_3 };
            A.Approximate(out K1);

            double[] K2;
            A.Phi = new ClassMNK.Function[] { f2_1, f2_2, f2_3 }; 
            A.Approximate(out K2);

            double[] K3;
            A.Phi = new ClassMNK.Function[] { f3_1, f3_2, f3_3 }; 
            A.Approximate(out K3);

            int N = 200;
            x = new double[N];
            y1 = new double[N];
            y2 = new double[N];
            y3 = new double[N];

            double x0 = xt[0];
            double h = (xt[xt.Length - 1] - x0) / (N - 1);

            for (int n=0; n< N; n++)
            {
                x[n] = x0 + h * n;
                y1[n] = f1(x[n],K1);
                y2[n] = f2(x[n],K2);
                y3[n] = f3(x[n],K3);
            }

            int best = 1;
            textBox.Text = "Статистика" + Environment.NewLine;
            double value = Statistics(1, y1);
            if (Statistics(2, y2) < value) best = 2;
            if (Statistics(3, y3) < value) best = 3;
            textBox.Text += Environment.NewLine;
            textBox.Text += "Лучшая аппроксимация - номер " + best.ToString() + Environment.NewLine;
            textBox.Text += chart.Series[best].LegendText;
        }

        double Statistics(int index, double[]y)
        {
            textBox.Text += Environment.NewLine;
            textBox.Text += chart.Series[index].LegendText + Environment.NewLine;
            double max = 0, sqrt = 0;
            int ikt = 0;
            while (ikt < xt.Length)
            {
                for (int k = 0; k < x.Length; k++)
                {
                    if (x[k]<=xt[ikt] && (k+1>=x.Length || x[k+1]>xt[ikt]))
                    {
                        double d = Math.Abs(yt[ikt] - y[k]);
                        sqrt += d * d;
                        if (d > max) max = d;
                        ikt++;
                        break;
                    }
                }
            }
            sqrt = Math.Sqrt(sqrt);
            textBox.Text += "Отклонение" + Environment.NewLine;
            textBox.Text += "Максимум "+ max.ToString("0.00")+ Environment.NewLine;
            textBox.Text += "Среднее " + sqrt.ToString("0.00") + Environment.NewLine;
            return sqrt;
        }

        void ShowGraphs()
        {
            
            if (xt != null)
            {
                chart.Series[0].Points.Clear();
                for (int row = 0; row < xt.Length; row++)
                    chart.Series[0].Points.AddXY(xt[row], yt[row]);
            }

            int seria = 1;
            if (y1 != null)
            {
                chart.Series[seria].Points.Clear();
                for (int row = 0; row < x.Length; row++)
                    chart.Series[seria].Points.AddXY(x[row], y1[row]);
            }

            seria++;
            if (y2 != null)
            {
                chart.Series[seria].Points.Clear();
                for (int row = 0; row < x.Length; row++)
                    chart.Series[seria].Points.AddXY(x[row], y2[row]);
            }
            seria++;
            if (y3 != null)
            {
                chart.Series[seria].Points.Clear();
                for (int row = 0; row < x.Length; row++)
                    chart.Series[seria].Points.AddXY(x[row], y3[row]);
            }
        }


    }
}
