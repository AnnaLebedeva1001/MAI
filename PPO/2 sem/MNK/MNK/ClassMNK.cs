using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MNK
{
    class ClassMNK
    {
        public delegate double Function(double x);
        public Function[] Phi = null;
        public double[] DataX = null;
        public double[] DataY = null;

        int LEN;
        double[,] MA;
        double[,] MB;

        void PrepareAandB()
        
        {
            if (Phi == null) throw new Exception("Не задан базис");
            if (DataX == null || DataY==null) throw new Exception("Нет исходных данных"); ;
            LEN = Phi.Length;
            int NN = DataX.Length;
            MA = new double[LEN,LEN];
            MB = new double[LEN,LEN];
            for (int k = 0; k < LEN; k++)
                for (int l = 0; l < LEN; l++)
                {
                    MA[k, l] = 0;
                    for (int i = 0; i < NN; i++)
                        MA[k, l] +=
                         Phi[l](DataX[i]) *
                         Phi[k](DataX[i]);
                }
            for (int k = 0; k < LEN; k++)
            {
                MB[k, 0] = 0;
                for (int i = 0; i < NN; i++)
                    MB[k, 0] += DataY[i] * Phi[k](DataX[i]);
            }
        }

        public void Approximate(out double[] Result)
        {
            PrepareAandB();

            double[,] A1; //Обратная матрица
            double[,] C; //Результат умножения, ответ, коэффициенты
            ClassMatrix.Inverse(MA, out A1);

            double[,] E;
            ClassMatrix.MulMatrix(A1, MA, out E); //Проверка умножением
            for (int r = 0; r < LEN; r++)
                for (int c = 0; c < LEN; c++)
                {
                    if ( r == c && Math.Abs(E[r, c] - 1) > 1e-3
                         ||
                         r != c && Math.Abs(E[r, c] - 0) > 1e-3
                        )
                        throw new Exception("Неверна обратная матрица");
                }

            ClassMatrix.MulMatrix(A1, MB, out C);
            Result = new double[LEN];
            for (int i = 0; i < LEN; i++) Result[i] = C[i, 0];
        }

    }
}
