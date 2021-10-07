using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MNK
{
    class ClassMatrix
    {
        public static void Trans(double[,] Src, ref double[,] Dst)
        {
            double Temp;
            int N = Src.GetLength(0);
            if ((Dst == null) || (Src == Dst))
            {
                for (int Row = 0; Row < N; Row++)
                    for (int Col = Row + 1; Col < N; Col++)
                    {
                        Temp = Src[Row, Col];
                        Src[Row, Col] = Src[Row, Col];
                        Src[Col, Row] = Temp;
                    }

            }
            else { 
                for (int Row = 0; Row < N; Row++)
                    for (int Col = 0; Col < N; Col++)
                        Dst[Col, Row] = Src[Row, Col];
            };
        }

        public static void MulMatrix(double[,] M1, double[,] M2, out double[,] Result)
        {
            int M1Rows = M1.GetLength(0);
            int M1Cols = M1.GetLength(1);
            int M2Cols = M2.GetLength(1);
            Result = new double[M1Rows, M2Cols];

            for (int Row = 0; Row < M1Rows; Row++)
                for (int Col = 0; Col < M2Cols; Col++)
                {
                    double S = 0;
                    for (int k = 0; k < M1Cols; k++) S += M1[Row, k] * M2[k, Col];
                    Result[Row, Col] = S;
                }
        }

        static void Minor(double[,] Src, int Row, int Col, out double[,] Result)
        {
            int Size = Src.GetLength(0);
            double[,] Temp = new double[Size, Size];
            Result = new double[Size-1, Size-1];
            for (int r = 0; r < Size; r++)
                for (int c = 0; c < Size; c++)
                    Temp[r, c] = Src[r, c];
            for (int r = Row; r < Size - 1; r++) for (int c = 0; c < Size; c++)
                    Temp[r, c] = Temp[r + 1, c];
            for (int r = 0; r < Size; r++) for (int c = Col; c < Size - 1; c++)
                    Temp[r, c] = Temp[r, c + 1];
            for (int r = 0; r < Size-1; r++)
                for (int c = 0; c < Size-1; c++)
                    Result[r, c] = Temp[r, c];
        }

        public static double Det(double[,] M)
        {
            int Size = M.GetLength(0);
            double Result = 0;
            if (Size == 1)
                return M[0,0]; 
            double[,] T = null;
            for (int c = 0; c < Size; c++)
            {
                Minor(M, 0, c, out T); 
                double D = Det(T);
                if ((c & 0x01) != 0)
                    Result -=  M[0, c] * D;
                else
                    Result += M[0, c] * D;
            };
            return Result;
        }


        public static void Inverse(double[,] Src, out double[,] Result)
        {
            int Size = Src.GetLength(0);
            Result = new double[Size, Size];
            if (Size == 1)
            {
                Result[0,0] = 1.0 / Src[0,0];
                return;
            }
            double[,] T;
            
            double D = Det(Src);
            for (int r = 0; r < Size; r++) for (int c = 0; c < Size; c++)
                {
                    Minor(Src, r, c, out T);
                    Result[c, r] = Det(T);
                };
            for (int r = 0; r < Size; r++)
                for (int c = 0; c < Size; c++)
                    if (((r + c) & 0x1) != 0)
                        Result[r, c] = -Result[r, c];
            if (D != 0)
                for (int r = 0; r < Size; r++)
                    for (int c = 0; c < Size; c++)
                        Result[r, c] /= D;
        }
    }
}
