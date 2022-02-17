using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;


namespace КГ_2_lab
{
    public partial class Form1 : Form
    {
        private static Bitmap bmp;
        private Graphics g;
        public static UInt32[,] pixel;
        Point startPoint;
        Point endPoint;
        Rectangle selectedArea;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog(); 
            dialog.Filter = "Image files (*.BMP, *.JPG, *.GIF, *.TIF, *.PNG, *.ICO," +
                " *.EMF, *.WMF)| *.bmp; *.jpg; *.gif; *.tif; *.png; *.ico; *.emf; *.wmf";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                bmp = new Bitmap(dialog.FileName);
                pictureBox1.Image = bmp;

                pixel = new UInt32[bmp.Height, bmp.Width];
                for (int y = 0; y < bmp.Height; y++)
                    for (int x = 0; x < bmp.Width; x++)
                        pixel[y, x] = (UInt32)(bmp.GetPixel(x, y).ToArgb());

                startPoint = endPoint = Point.Empty;
                selectedArea = Rectangle.Empty;
                pictureBox1.Invalidate(); ;
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog savedialog = new SaveFileDialog();
            savedialog.Title = "Сохранить картинку как ...";
            savedialog.OverwritePrompt = true;
            savedialog.CheckPathExists = true;
            savedialog.Filter =
            "Bitmap File(*.bmp)|*.bmp|" +
            "GIF File(*.gif)|*.gif|" +
            "JPEG File(*.jpg)|*.jpg|" +
            "TIF File(*.tif)|*.tif|" +
            "PNG File(*.png)|*.png";
            savedialog.ShowHelp = true;
            if (savedialog.ShowDialog() == DialogResult.OK)
            {
                string fileName = savedialog.FileName;
                string strFilExtn = fileName.Remove(0, fileName.Length - 3);
                switch (strFilExtn)
                {
                    case "bmp":
                        bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Bmp);
                        break;
                    case "jpg":
                        bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                        break;
                    case "gif":
                        bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Gif);
                        break;
                    case "tif":
                        bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Tiff);
                        break;
                    case "png":
                        bmp.Save(fileName, System.Drawing.Imaging.ImageFormat.Png);
                        break;
                    default:
                        break;
                }
            }
        }


        private void rhombus_filter()
        {
            Graphics gr = Graphics.FromImage(pictureBox1.Image);
            Pen p1 = new Pen(Color.LightSeaGreen, 3);
            PointF[] rhomb = new PointF[4];
            rhomb[0].X = bmp.Width / 2;
            rhomb[0].Y = (bmp.Height / 2) - 100;
            rhomb[1].X = (bmp.Width / 2) - 55;
            rhomb[1].Y = bmp.Height / 2;
            rhomb[2].X = bmp.Width / 2;
            rhomb[2].Y = (bmp.Height / 2) + 100;
            rhomb[3].X = (bmp.Width / 2) + 55;
            rhomb[3].Y = bmp.Height / 2;
            gr.DrawPolygon(p1, rhomb);

            Color color;
            float res1, res2, res3, res4;
            int grey;
            for (int i = 0; i < bmp.Width; i++)
                for (int j = 0; j < bmp.Height; j++)
                {
                    color = bmp.GetPixel(i, j);
                    res1 = (rhomb[0].X - i) * (rhomb[1].Y - rhomb[0].Y) - (rhomb[0].Y - j) * (rhomb[1].X - rhomb[0].X);
                    res2 = (rhomb[1].X - i) * (rhomb[2].Y - rhomb[1].Y) - (rhomb[1].Y - j) * (rhomb[2].X - rhomb[1].X);
                    res3 = (rhomb[2].X - i) * (rhomb[3].Y - rhomb[2].Y) - (rhomb[2].Y - j) * (rhomb[3].X - rhomb[2].X);
                    res4 = (rhomb[3].X - i) * (rhomb[0].Y - rhomb[3].Y) - (rhomb[3].Y - j) * (rhomb[0].X - rhomb[3].X);
                    if((res1 > 0 && res2 > 0 && res3 > 0 && res4 > 0) || (res1 < 0 && res2 < 0 && res3 < 0 && res4 < 0))
                    {
                        bmp.SetPixel(i, j, Color.FromArgb(255, 0, color.G, 0));
                    }
                    else
                    {
                        grey = (color.R + color.G + color.B) / 3;
                        bmp.SetPixel(i, j, Color.FromArgb(255, grey, grey, grey));
                    }
                }

        }


        private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            switch (e.Node.Index)
            {
                case 0:
                    if (pictureBox1.Image != null)
                    {
                        pixel = Filtres.matrix_filtration(bmp.Width, bmp.Height, pixel, Filtres.N1, Filtres.laplas);
                        for (int y = 0; y < bmp.Height; y++)
                            for (int x = 0; x < bmp.Width; x++)
                                bmp.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));
                        pictureBox1.Image = bmp;
                    }
                    break;
                case 1:
                    if (pictureBox1.Image != null)
                    {
                        pixel = Filtres.matrix_filtration(bmp.Width, bmp.Height, pixel, Filtres.N2, Filtres.sobel);
                        for (int y = 0; y < bmp.Height; y++)
                            for (int x = 0; x < bmp.Width; x++)
                                bmp.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));
                        pictureBox1.Image = bmp;
                    }
                    break;
                case 2:
                    if (pictureBox1.Image != null)
                    {
                        rhombus_filter();
                        pictureBox1.Image = bmp;
                    }
                    break;
            }
        }

    }


}
