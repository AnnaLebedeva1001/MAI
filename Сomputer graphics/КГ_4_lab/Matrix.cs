using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace КГ_4_lab
{
    class Matrix
    {
        private static float Sin(float angle)
        {
            return (float)Math.Sin(Math.PI * angle / 180);
        }

        private static float Cos(float angle)
        {
            return (float)Math.Cos(Math.PI * angle / 180);
        }
        internal static float[,] DiagonalMatrix(float a, float b, float c, float d)
        {
            return new float[,]
            {
                { a, 0, 0, 0 },
                { 0, b, 0, 0 },
                { 0, 0, c, 0 },
                { 0, 0, 0, d }
            };
        }

        internal static float[,] RotationZ(float rotZ)
        {
            return new float[,]
            {
                { Cos(rotZ), Sin(rotZ), 0, 0 },
                { -Sin(rotZ), Cos(rotZ), 0, 0 },
                { 0, 0, 1, 0 },
                { 0, 0, 0, 1 }
            };
        }

        internal static float[,] RotationY(float rotY)
        {
            return new float[,]
            {
                { Cos(rotY), 0, -Sin(rotY), 0 },
                { 0, 1, 0, 0 },
                { Sin(rotY), 0, Cos(rotY), 0 },
                { 0, 0, 0, 1 }
            };
        }

        internal static float[,] RotationX(float rotX)
        {
            return new float[,]
            {
                { 1, 0, 0, 0 },
                { 0, Cos(rotX), Sin(rotX), 0 },
                { 0, -Sin(rotX), Cos(rotX), 0 },
                { 0, 0, 0, 1 }
            };
        }
        internal static float[,] MatrixMultiplication(float[,] m1, float[,] m2)
        {
            float[,] res = new float[m1.GetLength(0), m2.GetLength(1)];

            for (int i = 0; i != res.GetLength(0); ++i)
                for (int j = 0; j != res.GetLength(1); ++j)
                    for (int k = 0; k != m2.GetLength(0); ++k)
                        res[i, j] += m1[i, k] * m2[k, j];

            return res;
        }

        internal static void ToDecart(ref float[,] M)
        {
            for (int i = 0; i != M.GetLength(0); ++i)
                for (int j = 0; j != M.GetLength(1); ++j)
                {
                    if (M[i, 3] == 0) M[i, 3] = 0.01f;
                    M[i, j] = M[i, j] / M[i, 3];
                }
        }

        internal static int[,] DisplayCoordinates(float[,] CartMatrix, int width, int height, int widthStep, int heightStep)
        {
            int[,] DispMatrix = new int[CartMatrix.GetLength(0), CartMatrix.GetLength(1)];

            for (int i = 0; i != CartMatrix.GetLength(0); ++i)
                for (int j = 0; j != CartMatrix.GetLength(1) - 1; ++j)
                {
                    if (j == 0)
                        DispMatrix[i, 0] = (int)(width / 2 + (widthStep * CartMatrix[i, j]));
                    if (j == 1)
                        DispMatrix[i, 1] = (int)(height / 2 + (heightStep * CartMatrix[i, j]));
                }

            return DispMatrix;
        }

        internal static float[,] CreateTransformationMatrix(float[,] MRZ, float[,] MRY, float[,] MRX, float[,] MOrtZ)
        {
            float[,] M = MatrixMultiplication(MRZ, MRY);
            M = MatrixMultiplication(M, MRX);
            return MatrixMultiplication(M, MOrtZ);
        }

        internal static float[,] MatrixTransformation(float[,] MatrixAxesBeforeTransf, float[,] MatrixGeneralTransform)
        {
            return MatrixMultiplication(MatrixAxesBeforeTransf, MatrixGeneralTransform);
        }

        internal static float[,] MatrixFigureTransform(float[,] MTransform, float[,] MScaleFig,
                                                        float[,] MGenTransform, float[,] MStartCords, float[,] MRotation)
        {
            float[,] M = MatrixMultiplication(MRotation, MTransform);
            M = MatrixMultiplication(M, MScaleFig);
            M = MatrixMultiplication(M, MGenTransform);
            M = MatrixMultiplication(MStartCords, M);

            return M;
        }

        internal static float[,] RotateFigure(float[,] MX, float[,] MY, float[,] MZ)
        {
            return MatrixMultiplication(MatrixMultiplication(MX, MY), MZ);
        }
    }
}
