using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace КГ_4_lab
{
    public partial class Form1 : Form
    {
        int step, xStep, yStep;
        int width, height;
        float[,] figure = new float[12, 4];
        float[,] initialFigure;
        float[,] startCoordinates;
        float[,] matrixOrthogonZ;
        float[,] matrixTransformRotationZ;
        float[,] matrixTransformRotationY;
        float[,] matrixTransformRotationX;
        float[,] matrixTransformation;
        float[,] matrixScale;
        float[,] matrixRotationZ;
        float[,] matrixRotationY;
        float[,] matrixRotationX;
        int[,] drawAxisCoord;
        int[,] drawFigureCoord;
        bool isColored;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
            this.pictureBox1.Size = new System.Drawing.Size(this.Width - 250, this.Height);
            width = pictureBox1.Width;
            height = pictureBox1.Height;
            step = 10;
            xStep = width / (step * 2);
            yStep = height / (step * 2);

            initialFigure = new float[,]
            {
                { 0, 0, 0, 1},
                { 0, 4, 0, 1},
                { 4, 4, 0, 1},
                { 4, 0, 0, 1},
                { 0, 0, 2, 1},
                { 0, 4, 2, 1},
                { 4, 4, 2, 1},
                { 4, 0, 2, 1},
                { 1, 0, 3, 1},
                { 1, 4, 3, 1},
                { 3, 4, 3, 1},
                { 3, 0, 3, 1}
            };

            RestoreFigure();

            UpdateFigure();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            if (isColored)
            {
                var graphics = e.Graphics;
                GraphicsPath gp = new GraphicsPath(FillMode.Winding);
                SolidBrush brush = new SolidBrush(Color.Pink);
                List<PointF> points = new List<PointF>();

                points.Add(new PointF((float)drawFigureCoord[0, 0], (float)drawFigureCoord[0, 1]));
                points.Add(new PointF((float)drawFigureCoord[1, 0], (float)drawFigureCoord[1, 1]));
                points.Add(new PointF((float)drawFigureCoord[2, 0], (float)drawFigureCoord[2, 1]));
                points.Add(new PointF((float)drawFigureCoord[3, 0], (float)drawFigureCoord[3, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[0, 0], (float)drawFigureCoord[0, 1]));
                points.Add(new PointF((float)drawFigureCoord[1, 0], (float)drawFigureCoord[1, 1]));
                points.Add(new PointF((float)drawFigureCoord[5, 0], (float)drawFigureCoord[5, 1]));
                points.Add(new PointF((float)drawFigureCoord[4, 0], (float)drawFigureCoord[4, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[2, 0], (float)drawFigureCoord[2, 1]));
                points.Add(new PointF((float)drawFigureCoord[3, 0], (float)drawFigureCoord[3, 1]));
                points.Add(new PointF((float)drawFigureCoord[7, 0], (float)drawFigureCoord[7, 1]));
                points.Add(new PointF((float)drawFigureCoord[6, 0], (float)drawFigureCoord[6, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[0, 0], (float)drawFigureCoord[0, 1]));
                points.Add(new PointF((float)drawFigureCoord[3, 0], (float)drawFigureCoord[3, 1]));
                points.Add(new PointF((float)drawFigureCoord[7, 0], (float)drawFigureCoord[7, 1]));
                points.Add(new PointF((float)drawFigureCoord[4, 0], (float)drawFigureCoord[4, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[1, 0], (float)drawFigureCoord[1, 1]));
                points.Add(new PointF((float)drawFigureCoord[2, 0], (float)drawFigureCoord[2, 1]));
                points.Add(new PointF((float)drawFigureCoord[6, 0], (float)drawFigureCoord[6, 1]));
                points.Add(new PointF((float)drawFigureCoord[5, 0], (float)drawFigureCoord[5, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[8, 0], (float)drawFigureCoord[8, 1]));
                points.Add(new PointF((float)drawFigureCoord[9, 0], (float)drawFigureCoord[9, 1]));
                points.Add(new PointF((float)drawFigureCoord[10, 0], (float)drawFigureCoord[10, 1]));
                points.Add(new PointF((float)drawFigureCoord[11, 0], (float)drawFigureCoord[11, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[5, 0], (float)drawFigureCoord[5, 1]));
                points.Add(new PointF((float)drawFigureCoord[9, 0], (float)drawFigureCoord[9, 1]));
                points.Add(new PointF((float)drawFigureCoord[10, 0], (float)drawFigureCoord[10, 1]));
                points.Add(new PointF((float)drawFigureCoord[6, 0], (float)drawFigureCoord[6, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[4, 0], (float)drawFigureCoord[4, 1]));
                points.Add(new PointF((float)drawFigureCoord[8, 0], (float)drawFigureCoord[8, 1]));
                points.Add(new PointF((float)drawFigureCoord[11, 0], (float)drawFigureCoord[11, 1]));
                points.Add(new PointF((float)drawFigureCoord[7, 0], (float)drawFigureCoord[7, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[4, 0], (float)drawFigureCoord[4, 1]));
                points.Add(new PointF((float)drawFigureCoord[5, 0], (float)drawFigureCoord[5, 1]));
                points.Add(new PointF((float)drawFigureCoord[9, 0], (float)drawFigureCoord[9, 1]));
                points.Add(new PointF((float)drawFigureCoord[8, 0], (float)drawFigureCoord[8, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                points.Add(new PointF((float)drawFigureCoord[7, 0], (float)drawFigureCoord[7, 1]));
                points.Add(new PointF((float)drawFigureCoord[6, 0], (float)drawFigureCoord[6, 1]));
                points.Add(new PointF((float)drawFigureCoord[10, 0], (float)drawFigureCoord[10, 1]));
                points.Add(new PointF((float)drawFigureCoord[11, 0], (float)drawFigureCoord[11, 1]));
                gp.AddLines(points.ToArray());
                graphics.FillPath(brush, gp);
                points.Clear();

                gp.Dispose();
            }

            DrawAxis(drawAxisCoord, e.Graphics);
            DrawFigure(drawFigureCoord, e.Graphics);
        }

        private void RestoreFigure()
        {
            isColored = false;

            for (int i = 0; i < 12; i++)
                for (int j = 0; j < 4; j++)
                    figure[i, j] = initialFigure[i, j];

            startCoordinates = new float[,]
            {
                { -step, 0, 0, 1 },
                { step, 0, 0, 1 },
                { 0, -step, 0, 1 },
                { 0, step, 0, 1 },
                { 0, 0, -step, 1 },
                { 0, 0, step, 1 }
            };

            matrixOrthogonZ = Matrix.DiagonalMatrix(1, 1, 0, 1);
            matrixTransformation = Matrix.DiagonalMatrix(1, 1, 1, 1);

            matrixTransformRotationZ = Matrix.RotationZ(0);
            matrixTransformRotationY = Matrix.RotationY(0);
            matrixTransformRotationX = Matrix.RotationX(180);

            matrixScale = Matrix.DiagonalMatrix(1, 1, 1, 1);
            matrixRotationZ = Matrix.RotationZ(0);
            matrixRotationY = Matrix.RotationY(0);
            matrixRotationX = Matrix.RotationX(0);

            UpdateFigure();
        }
        private void UpdateFigure()
        {
            float[,] matrixGenTransf = Matrix.CreateTransformationMatrix(matrixTransformRotationZ, matrixTransformRotationY, matrixTransformRotationX, matrixOrthogonZ);
            float[,] matrixAxesEndCords = Matrix.MatrixTransformation(startCoordinates, matrixGenTransf);
            Matrix.ToDecart(ref matrixAxesEndCords);
            drawAxisCoord = Matrix.DisplayCoordinates(matrixAxesEndCords, width, height, xStep, yStep);

            float[,] rotationFig = Matrix.RotateFigure(matrixRotationX, matrixRotationY, matrixRotationZ);
            float[,] matrixFigTransf = Matrix.MatrixFigureTransform(matrixTransformation, matrixScale, matrixGenTransf, figure, rotationFig);
            Matrix.ToDecart(ref matrixFigTransf);
            drawFigureCoord = Matrix.DisplayCoordinates(matrixFigTransf, width, height, xStep, yStep);

            pictureBox1.Invalidate();
        }
        private static void DrawAxis(int[,] MatrixAxes, Graphics gr)
        {
            Pen pen = new Pen(Brushes.SteelBlue, 2);
            Font font = new Font("Microsoft Sans Serif", 10);

            gr.DrawLine(pen, MatrixAxes[0, 0], MatrixAxes[0, 1], MatrixAxes[1, 0], MatrixAxes[1, 1]);
            gr.DrawLine(pen, MatrixAxes[2, 0], MatrixAxes[2, 1], MatrixAxes[3, 0], MatrixAxes[3, 1]);
            gr.DrawLine(pen, MatrixAxes[4, 0], MatrixAxes[4, 1], MatrixAxes[5, 0], MatrixAxes[5, 1]);

            gr.DrawString("X", font, Brushes.MidnightBlue, MatrixAxes[1, 0], MatrixAxes[1, 1]);
            gr.DrawString("Y", font, Brushes.MidnightBlue, MatrixAxes[3, 0], MatrixAxes[3, 1]);
            gr.DrawString("Z", font, Brushes.MidnightBlue, MatrixAxes[5, 0], MatrixAxes[5, 1]);
        }

        public static void DrawFigure(int[,] MatrixFigure, Graphics gr)
        {
            Pen pen = new Pen(Color.HotPink, 3);

            gr.DrawLine(pen, MatrixFigure[0, 0], MatrixFigure[0, 1], MatrixFigure[1, 0], MatrixFigure[1, 1]);
            gr.DrawLine(pen, MatrixFigure[1, 0], MatrixFigure[1, 1], MatrixFigure[2, 0], MatrixFigure[2, 1]);
            gr.DrawLine(pen, MatrixFigure[2, 0], MatrixFigure[2, 1], MatrixFigure[3, 0], MatrixFigure[3, 1]);
            gr.DrawLine(pen, MatrixFigure[3, 0], MatrixFigure[3, 1], MatrixFigure[0, 0], MatrixFigure[0, 1]);

            gr.DrawLine(pen, MatrixFigure[4, 0], MatrixFigure[4, 1], MatrixFigure[5, 0], MatrixFigure[5, 1]);
            gr.DrawLine(pen, MatrixFigure[5, 0], MatrixFigure[5, 1], MatrixFigure[6, 0], MatrixFigure[6, 1]);
            gr.DrawLine(pen, MatrixFigure[6, 0], MatrixFigure[6, 1], MatrixFigure[7, 0], MatrixFigure[7, 1]);
            gr.DrawLine(pen, MatrixFigure[7, 0], MatrixFigure[7, 1], MatrixFigure[4, 0], MatrixFigure[4, 1]);

            gr.DrawLine(pen, MatrixFigure[8, 0], MatrixFigure[8, 1], MatrixFigure[9, 0], MatrixFigure[9, 1]);
            gr.DrawLine(pen, MatrixFigure[9, 0], MatrixFigure[9, 1], MatrixFigure[10, 0], MatrixFigure[10, 1]);
            gr.DrawLine(pen, MatrixFigure[10, 0], MatrixFigure[10, 1], MatrixFigure[11, 0], MatrixFigure[11, 1]);
            gr.DrawLine(pen, MatrixFigure[11, 0], MatrixFigure[11, 1], MatrixFigure[8, 0], MatrixFigure[8, 1]);

            gr.DrawLine(pen, MatrixFigure[0, 0], MatrixFigure[0, 1], MatrixFigure[4, 0], MatrixFigure[4, 1]);
            gr.DrawLine(pen, MatrixFigure[1, 0], MatrixFigure[1, 1], MatrixFigure[5, 0], MatrixFigure[5, 1]);
            gr.DrawLine(pen, MatrixFigure[2, 0], MatrixFigure[2, 1], MatrixFigure[6, 0], MatrixFigure[6, 1]);
            gr.DrawLine(pen, MatrixFigure[3, 0], MatrixFigure[3, 1], MatrixFigure[7, 0], MatrixFigure[7, 1]);

            gr.DrawLine(pen, MatrixFigure[4, 0], MatrixFigure[4, 1], MatrixFigure[8, 0], MatrixFigure[8, 1]);
            gr.DrawLine(pen, MatrixFigure[5, 0], MatrixFigure[5, 1], MatrixFigure[9, 0], MatrixFigure[9, 1]);
            gr.DrawLine(pen, MatrixFigure[6, 0], MatrixFigure[6, 1], MatrixFigure[10, 0], MatrixFigure[10, 1]);
            gr.DrawLine(pen, MatrixFigure[7, 0], MatrixFigure[7, 1], MatrixFigure[11, 0], MatrixFigure[11, 1]);

        }

        private void Moving_Left_Click(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    matrixTransformation[3, 0] -= 1;
                    break;
                case 1:
                    matrixTransformation[3, 1] -= 1;
                    break;
                case 2:
                    matrixTransformation[3, 2] -= 1;
                    break;
            }

            UpdateFigure();
        }

        private void Moving_Right_Click(object sender, EventArgs e)
        {
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    matrixTransformation[3, 0] += 1;
                    break;
                case 1:
                    matrixTransformation[3, 1] += 1;
                    break;
                case 2:
                    matrixTransformation[3, 2] += 1;
                    break;
            }

            UpdateFigure();
        }

        private void Reduce_Click(object sender, EventArgs e)
        {
            matrixScale[3, 3] /= 0.9f;
            UpdateFigure();
        }

        private void Increase_Click(object sender, EventArgs e)
        {
            matrixScale[3, 3] /= (1f / 0.9f);
            UpdateFigure();
        }

        private void Isometric_Projection_Click(object sender, EventArgs e)
        {
            startCoordinates = new float[,]
            {
                { -step, 0, 0, 1 },
                { step, 0, 0, 1 },
                { 0, -step, 0, 1 },
                { 0, step, 0, 1 },
                { 0, 0, -step, 1 },
                { 0, 0, step, 1 }
            };

            matrixTransformRotationZ = Matrix.RotationZ(0);
            matrixTransformRotationY = Matrix.RotationY(0);
            matrixTransformRotationX = Matrix.RotationX(180);

            int a = 45;
            matrixOrthogonZ[0, 0] = (float)Math.Cos(Math.PI * a / 180);
            matrixOrthogonZ[0, 1] = (float)Math.Sin(Math.PI * a / 180) * (float)Math.Sin(Math.PI * a / 180);
            matrixOrthogonZ[1, 1] = (float)Math.Cos(Math.PI * a / 180);
            matrixOrthogonZ[2, 0] = (float)Math.Sin(Math.PI * a / 180);
            matrixOrthogonZ[2, 1] = -(float)Math.Sin(Math.PI * a / 180) * (float)Math.Cos(Math.PI * a / 180);

            UpdateFigure();
        }

        private void Colorize_Click(object sender, EventArgs e)
        {
            isColored = !isColored;
            UpdateFigure();
        }

        private void Restore_Position_Click(object sender, EventArgs e)
        {
            RestoreFigure();
            UpdateFigure();
        }

        private void Reflection_X_Click(object sender, EventArgs e)
        {
            figure = Matrix.MatrixMultiplication(figure, Matrix.DiagonalMatrix(-1, 1, 1, 1));
            matrixTransformation[3, 0] *= -1;

            UpdateFigure();
        }

        private void Reflection_Y_Click(object sender, EventArgs e)
        {
            figure = Matrix.MatrixMultiplication(figure, Matrix.DiagonalMatrix(1, -1, 1, 1));
            matrixTransformation[3, 1] *= -1;

            UpdateFigure();
        }

        private void Reflection_Z_Click(object sender, EventArgs e)
        {
            figure = Matrix.MatrixMultiplication(figure, Matrix.DiagonalMatrix(1, 1, -1, 1));
            matrixTransformation[3, 2] *= -1;

            UpdateFigure();
        }

        private void Rotation_X_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter && Rotation_X.Text.Length != 0)
                matrixRotationX = Matrix.MatrixMultiplication(matrixRotationX, Matrix.RotationX(int.Parse(Rotation_X.Text)));

            UpdateFigure();
        }

        private void Central_Angle_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                int koef = Central_Angle.Text == "" ? 0 : int.Parse(Central_Angle.Text);
                matrixTransformRotationZ[2, 2] = 0;
                matrixTransformRotationZ[2, 3] = 1f / koef;

                UpdateFigure();
            }
        }

        private void Rotation_Y_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter && Rotation_Y.Text.Length != 0)
                matrixRotationY = Matrix.MatrixMultiplication(matrixRotationY, Matrix.RotationY(int.Parse(Rotation_Y.Text)));

            UpdateFigure();
        }

        private void Rotation_Z_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter && Rotation_Z.Text.Length != 0)
                matrixRotationZ = Matrix.MatrixMultiplication(matrixRotationZ, Matrix.RotationZ(int.Parse(Rotation_Z.Text)));

            UpdateFigure();
        }

        private void Length_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                float length = Length.Text == "" ? 0 : float.Parse(Length.Text);
                int angle = Angle.Text == "" ? 0 : int.Parse(Angle.Text);
                matrixTransformRotationZ[2, 0] = (float)Math.Cos(Math.PI * angle / 180) * length;
                matrixTransformRotationZ[2, 1] = (float)Math.Sin(Math.PI * angle / 180) * length;
                matrixTransformRotationZ[2, 2] = 0;

                UpdateFigure();
            }
        }

    }
}
