#include "MyForm.h"
#include "modul.h"

using namespace System;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	lab2z2::MyForm form;
	Application::Run(% form);
}

int** arr1;
int n, m;
inline System::Void lab2z2::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	n = Convert::ToInt32(numericUpDown1->Value);
	m = Convert::ToInt32(numericUpDown2->Value);
	arr1 = matrix_init(n, m);

	zero_matrix(arr1, n, m);

	dataGridView1->RowCount = n;
	dataGridView1->ColumnCount = m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			dataGridView1->Rows[i]->Cells[j]->Value = arr1[i][j];
		}
}

inline System::Void lab2z2::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			arr1[i][j] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[j]->Value);
		}
	}

	if (group_average_score(arr1, n, m)
		== check_for_2(arr1, n, m)
		== check_for_3(arr1, n, m) == 1)
	{
		label5->Text = "Ура!!! Группа попадает\n на конкурс лучших групп!!!";
	}
	else
	{
		label5->Text = "Увы, не все условия\n соблюдены!! Группа\n не попадает на конкурс";
	}

	for (int i = 0; i < n; ++i)
		delete[] arr1[i];
	delete[] arr1;
	return System::Void();
}
