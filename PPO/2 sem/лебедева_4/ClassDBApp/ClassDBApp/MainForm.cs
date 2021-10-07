using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;

namespace ClassDBApp
{
    public partial class MainForm : Form
    {
        // var
        SQLiteConnection db;
        int countStudents = 0; // Кол-во студентов

        public MainForm()
        {
            InitializeComponent();

            // Выбираем в ComboBox'ах элемент по умолчанию
            // Так же запрещаем вводить свои значения в поле
            cB_Gender.SelectedIndex = 0;
            cB_Gender.KeyPress += (sender, e) => e.Handled = true;
            cB_removeStudent.KeyPress += (sender, e) => e.Handled = true;
            cB_Mark.SelectedIndex = 3;
            cB_Mark.KeyPress += (sender, e) => e.Handled = true;
            cB_description.SelectedIndex = 0;
            cB_Mark.KeyPress += (sender, e) => e.Handled = true;
            cB_student.KeyPress += (sender, e) => e.Handled = true;
            cB_Item.KeyPress += (sender, e) => e.Handled = true;
            cB_findItem.KeyPress += (sender, e) => e.Handled = true;
            cB_findStudent.KeyPress += (sender, e) => e.Handled = true;
            cB_object.KeyPress += (sender, e) => e.Handled = true;

            CreateDGVColumnForStudents();
            CreateDGVColumnForItems();
            CreateDGVColumnForMarks();
            CreateDGVColumnForRequests1And2();
            CreateDGVColumnForRequests3And4();
        }

        // Загрузка формы
        private void MainForm_Load(object sender, EventArgs e)
        {
            // Настраиваем и открываем соединение с БД
            db = new SQLiteConnection("Data Source=MyClass.db; Version=3");
            db.Open();

            UpdateDGVForStudents();
        }

        /// <summary>
        /// Обновляем отображение записей таблицы с учениками в dataGridView
        /// </summary>
        private void UpdateDGVForStudents()
        {
            countStudents = 0;
            dGV_Students.Rows.Clear();
            cB_removeStudent.Items.Clear();

            // Выполняем команды SQL-запроса
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "select * from Students order by Id_student";
            SQLiteDataReader sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в dataGridView
            {
                while (sql.Read())
                {
                    dGV_Students.Rows.Add(sql["Id_student"], sql["Gender"], sql["F"], sql["I"], sql["O"]);
                    cB_removeStudent.Items.Add(sql["Id_student"]);
                    countStudents++;
                }

                cB_removeStudent.SelectedIndex = 0;
            }
        }

        /// <summary>
        /// Обновляем отображение записей таблицы с предметами в dataGridView
        /// </summary>
        private void UpdateDGVForItems()
        {
            dGV_Items.Rows.Clear();
            cB_removeItems.Items.Clear();

            // Выполняем команды SQL-запроса
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "select * from Items order by Id_item";
            SQLiteDataReader sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в dataGridView
            {
                while (sql.Read())
                {
                    dGV_Items.Rows.Add(sql["Id_item"], sql["Name_item"]);
                    cB_removeItems.Items.Add(sql["Id_item"]);
                }

                cB_removeItems.SelectedIndex = 0;
            }
        }

        /// <summary>
        /// Обновляем отображение записей для таблицы с оценками в dataGridView
        /// </summary>
        private void UpdateDGVForMarks()
        {
            dgV_Marks.Rows.Clear();
            cB_student.Items.Clear();
            cB_Item.Items.Clear();

            // Выполняем команды SQL-запроса
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "select * from Marks order by Date_mark";
            SQLiteDataReader sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в dataGridView
            {
                while (sql.Read())
                {

                    dgV_Marks.Rows.Add(sql["id_Student"], sql["id_Item"], sql["Mark"], sql["Description"], sql["Date_mark"]);
                }

            }

            sql.Dispose(); // Очищаем sql-запрос

            // Выводим список идентификатор студентов из соответствующей таблицы в ComboBox
            cmd.CommandText = "select Id_student from Students order by Id_student";
            sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в dataGridView
            {
                while (sql.Read())
                {
                    cB_student.Items.Add(sql["Id_Student"]);
                }

                cB_student.SelectedIndex = 0;
            }

            sql.Dispose();

            // Выводим список идентификатор предметов из соответствующей таблицы в ComboBox
            cmd.CommandText = "select Id_item from Items order by Id_item";
            sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в dataGridView
            {
                while (sql.Read())
                {
                    cB_Item.Items.Add(sql["Id_item"]);
                }

                cB_Item.SelectedIndex = 0;
            }

        }

        /// <summary>
        /// Обновляем вкладку "Запросы №1"
        /// </summary>
        private void UpdateTabForRequests1And2()
        {
            cB_findStudent.Items.Clear();
            cB_findItem.Items.Clear();
            dGV_request1.Rows.Clear();
            dGV_request2.Rows.Clear();

            // Выполняем команды SQL-запроса
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "select Id_student from Students order by Id_student";
            SQLiteDataReader sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в ComboBox "Ид студента"
            {
                while (sql.Read())
                {
                    cB_findStudent.Items.Add(sql["Id_student"]);
                }

                cB_findStudent.SelectedIndex = 0;
            }

            sql.Dispose();
            cmd.CommandText = "select Id_item from Items order by Id_item";
            sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в ComboBox "Ид предмета"
            {
                while (sql.Read())
                {
                    cB_findItem.Items.Add(sql["Id_item"]);
                }

                cB_findItem.SelectedIndex = 0;
            }

        }

        /// <summary>
        /// Обновляем вкладку "Запросы №2"
        /// </summary>
        private void UpdateTabForRequests3And4()
        {
            cB_object.Items.Clear();
            dGV_Request3.Rows.Clear();
            dGV_Request4.Rows.Clear();

            // Выполняем команды SQL-запроса
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "select id_Item from Items order by id_Item";
            SQLiteDataReader sql = cmd.ExecuteReader();

            if (sql.HasRows) // Выводим результат в ComboBox "Ид студента"
            {
                while (sql.Read())
                {

                    cB_object.Items.Add(sql["id_Item"]);
                }

                cB_object.SelectedIndex = 0;
            }
        }

        /// <summary>
        /// Создание колонок для таблицы отображения учеников
        /// </summary>
        private void CreateDGVColumnForStudents()
        {
            var c_id = new DataGridViewColumn();
            c_id.HeaderText = "Ид";
            c_id.Width = 100;
            c_id.ReadOnly = true;
            c_id.Name = "Id";
            c_id.Frozen = true;
            c_id.CellTemplate = new DataGridViewTextBoxCell();


            var c_Gender = new DataGridViewColumn();
            c_Gender.HeaderText = "Пол";
            c_Gender.Width = 100;
            c_Gender.ReadOnly = true;
            c_Gender.Name = "Gender";
            c_Gender.Frozen = true;
            c_Gender.CellTemplate = new DataGridViewTextBoxCell();

            var c_F = new DataGridViewColumn();
            c_F.HeaderText = "Фамилия";
            c_F.Width = 100;
            c_F.ReadOnly = true;
            c_F.Name = "F";
            c_F.Frozen = true;
            c_F.CellTemplate = new DataGridViewTextBoxCell();

            var c_I = new DataGridViewColumn();
            c_I.HeaderText = "Имя";
            c_I.Width = 100;
            c_I.ReadOnly = true;
            c_I.Name = "I";
            c_I.Frozen = true;
            c_I.CellTemplate = new DataGridViewTextBoxCell();

            var c_O = new DataGridViewColumn();
            c_O.HeaderText = "Отчество";
            c_O.Width = 100;
            c_O.ReadOnly = true;
            c_O.Name = "O";
            c_O.Frozen = true;
            c_O.CellTemplate = new DataGridViewTextBoxCell();

            dGV_Students.Columns.Add(c_id);
            dGV_Students.Columns.Add(c_Gender);
            dGV_Students.Columns.Add(c_F);
            dGV_Students.Columns.Add(c_I);
            dGV_Students.Columns.Add(c_O);

            dGV_Students.AllowUserToAddRows = false;
            dGV_Students.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
        }

        /// <summary>
        /// Создание колонок для таблицы отображения предметов
        /// </summary>
        private void CreateDGVColumnForItems()
        {
            var c_id = new DataGridViewColumn();
            c_id.HeaderText = "Ид";
            c_id.Width = 100;
            c_id.ReadOnly = true;
            c_id.Name = "Id";
            c_id.Frozen = true;
            c_id.CellTemplate = new DataGridViewTextBoxCell();

            var c_name = new DataGridViewColumn();
            c_name.HeaderText = "Название";
            c_name.Width = 100;
            c_name.ReadOnly = true;
            c_name.Name = "Name";
            c_name.Frozen = true;
            c_name.CellTemplate = new DataGridViewTextBoxCell();

            dGV_Items.Columns.Add(c_id);
            dGV_Items.Columns.Add(c_name);

            dGV_Items.AllowUserToAddRows = false;
            dGV_Items.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
        }

        /// <summary>
        /// Создание колонок для 2-х таблиц DataGridView на вкладке "Запросы №1"
        /// </summary>
        private void CreateDGVColumnForRequests1And2()
        {
            var c_mark = new DataGridViewColumn();
            c_mark.HeaderText = "Оценка";
            c_mark.Width = 100;
            c_mark.ReadOnly = true;
            c_mark.Name = "Mark";
            c_mark.Frozen = true;
            c_mark.CellTemplate = new DataGridViewTextBoxCell();

            var c_object = new DataGridViewColumn();
            c_object.HeaderText = "Ид предмета";
            c_object.Width = 100;
            c_object.ReadOnly = true;
            c_object.Name = "Object";
            c_object.Frozen = true;
            c_object.CellTemplate = new DataGridViewTextBoxCell();

            dGV_request1.Columns.Add(c_mark);
            dGV_request1.Columns.Add(c_object);

            dGV_request1.AllowUserToAddRows = false;
            dGV_request1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;

            var c_mark_ = new DataGridViewColumn();
            c_mark_.HeaderText = "Оценка";
            c_mark_.Width = 100;
            c_mark_.ReadOnly = true;
            c_mark_.Name = "Mark";
            c_mark_.Frozen = true;
            c_mark_.CellTemplate = new DataGridViewTextBoxCell();

            var c_object_ = new DataGridViewColumn();
            c_object_.HeaderText = "Ид предмета";
            c_object_.Width = 100;
            c_object_.ReadOnly = true;
            c_object_.Name = "Object";
            c_object_.Frozen = true;
            c_object_.CellTemplate = new DataGridViewTextBoxCell();

            var c_idStudent = new DataGridViewColumn();
            c_idStudent.HeaderText = "Ид ученика";
            c_idStudent.Width = 100;
            c_idStudent.ReadOnly = true;
            c_idStudent.Name = "id_Student";
            c_idStudent.Frozen = true;
            c_idStudent.CellTemplate = new DataGridViewTextBoxCell();

            dGV_request2.Columns.Add(c_mark_);
            dGV_request2.Columns.Add(c_object_);
            dGV_request2.Columns.Add(c_idStudent);

            dGV_request2.AllowUserToAddRows = false;
            dGV_request2.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            dGV_request2.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
        }

        /// <summary>
        /// Создание колонок для 2-х таблиц DataGridView на вкладке "Запросы №2"
        /// </summary>
        private void CreateDGVColumnForRequests3And4()
        {
            var c_mark = new DataGridViewColumn();
            c_mark.HeaderText = "Средняя оценка";
            c_mark.Width = 100;
            c_mark.ReadOnly = true;
            c_mark.Name = "Mark";
            c_mark.Frozen = true;
            c_mark.CellTemplate = new DataGridViewTextBoxCell();

            var c_object = new DataGridViewColumn();
            c_object.HeaderText = "Ид предмета";
            c_object.Width = 100;
            c_object.ReadOnly = true;
            c_object.Name = "Object";
            c_object.Frozen = true;
            c_object.CellTemplate = new DataGridViewTextBoxCell();

            var c_student = new DataGridViewColumn();
            c_student.HeaderText = "Ид ученика";
            c_student.Width = 100;
            c_student.ReadOnly = true;
            c_student.Name = "Student";
            c_student.Frozen = true;
            c_student.CellTemplate = new DataGridViewTextBoxCell();

            dGV_Request3.Columns.Add(c_mark);
            dGV_Request3.Columns.Add(c_object);
            dGV_Request3.Columns.Add(c_student);

            dGV_Request3.AllowUserToAddRows = false;
            dGV_Request3.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            dGV_Request3.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;

            var c_mark_ = new DataGridViewColumn();
            c_mark_.HeaderText = "Средняя оценка";
            c_mark_.Width = 100;
            c_mark_.ReadOnly = true;
            c_mark_.Name = "Mark";
            c_mark_.Frozen = true;
            c_mark_.CellTemplate = new DataGridViewTextBoxCell();

            var c_object_ = new DataGridViewColumn();
            c_object_.HeaderText = "Ид предмета";
            c_object_.Width = 100;
            c_object_.ReadOnly = true;
            c_object_.Name = "Object";
            c_object_.Frozen = true;
            c_object_.CellTemplate = new DataGridViewTextBoxCell();

            var c_student_ = new DataGridViewColumn();
            c_student_.HeaderText = "Ид ученика";
            c_student_.Width = 100;
            c_student_.ReadOnly = true;
            c_student_.Name = "Student";
            c_student_.Frozen = true;
            c_student_.CellTemplate = new DataGridViewTextBoxCell();

            var c_description_ = new DataGridViewColumn();
            c_description_.HeaderText = "Вид работы";
            c_description_.Width = 100;
            c_description_.ReadOnly = true;
            c_description_.Name = "Description";
            c_description_.Frozen = true;
            c_description_.CellTemplate = new DataGridViewTextBoxCell();

            dGV_Request4.Columns.Add(c_mark_);
            dGV_Request4.Columns.Add(c_object_);
            dGV_Request4.Columns.Add(c_student_);
            dGV_Request4.Columns.Add(c_description_);

            dGV_Request4.AllowUserToAddRows = false;
            dGV_Request4.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            dGV_Request4.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
        }

        /// <summary>
        /// Создание колонок для таблицы отображения оценок
        /// </summary>
        private void CreateDGVColumnForMarks()
        {
            var c_idStudent = new DataGridViewColumn();
            c_idStudent.HeaderText = "Ид студента";
            c_idStudent.Width = 100;
            c_idStudent.ReadOnly = true;
            c_idStudent.Name = "Id_student";
            c_idStudent.Frozen = true;
            c_idStudent.CellTemplate = new DataGridViewTextBoxCell();

            var c_idItem = new DataGridViewColumn();
            c_idItem.HeaderText = "Ид предмета";
            c_idItem.Width = 100;
            c_idItem.ReadOnly = true;
            c_idItem.Name = "Id_item";
            c_idItem.Frozen = true;
            c_idItem.CellTemplate = new DataGridViewTextBoxCell();

            var c_mark = new DataGridViewColumn();
            c_mark.HeaderText = "Оценка";
            c_mark.Width = 100;
            c_mark.ReadOnly = true;
            c_mark.Name = "Mark";
            c_mark.Frozen = true;
            c_mark.CellTemplate = new DataGridViewTextBoxCell();

            var c_description = new DataGridViewColumn();
            c_description.HeaderText = "Описание";
            c_description.Width = 100;
            c_description.ReadOnly = true;
            c_description.Name = "Description";
            c_description.Frozen = true;
            c_description.CellTemplate = new DataGridViewTextBoxCell();

            var c_date = new DataGridViewColumn();
            c_date.HeaderText = "Дата";
            c_date.Width = 100;
            c_date.ReadOnly = true;
            c_date.Name = "Date";
            c_date.Frozen = true;
            c_date.CellTemplate = new DataGridViewTextBoxCell();

            dgV_Marks.Columns.Add(c_idStudent);
            dgV_Marks.Columns.Add(c_idItem);
            dgV_Marks.Columns.Add(c_mark);
            dgV_Marks.Columns.Add(c_description);
            dgV_Marks.Columns.Add(c_date);

            dgV_Marks.AllowUserToAddRows = false;
            dgV_Marks.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
        }

        // Закрытие формы
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            db.Close(); // Закрываем соединение
        }

        /// <summary>
        /// Выводит окно с уведомлением
        /// </summary>
        /// <param name="message"></param>
        private void ShowMessageBox(string message)
        {
            MessageBox.Show(
                message,
                "Внимание!",
                MessageBoxButtons.OK,
                MessageBoxIcon.Warning,
                MessageBoxDefaultButton.Button1,
                MessageBoxOptions.DefaultDesktopOnly);
        }

        // Кнопка "Добавить запись" на вкладке "Ученики"
        private void b_AddStudent_Click(object sender, EventArgs e)
        {
            if (tB_IdStudent.Text != "" & tB_I.Text != "" & tB_F.Text != "" & tB_O.Text != "") // Проверяем, что поля пустые
            {
                try
                {
                    Convert.ToInt32(tB_IdStudent.Text);

                    // Добавляем новую запись sql-запросом
                    SQLiteCommand cmd = db.CreateCommand();
                    cmd.CommandText = "insert into Students(Id_student, Gender, F, I, O) values ( @id, @gender, @f, @i, @o)";
                    cmd.Parameters.Add("@id", System.Data.DbType.Int32).Value = Math.Abs(Convert.ToInt32(tB_IdStudent.Text));
                    cmd.Parameters.Add("@gender", System.Data.DbType.String).Value = cB_Gender.SelectedItem;
                    cmd.Parameters.Add("@f", System.Data.DbType.String).Value = tB_F.Text;
                    cmd.Parameters.Add("@I", System.Data.DbType.String).Value = tB_I.Text;
                    cmd.Parameters.Add("@O", System.Data.DbType.String).Value = tB_O.Text;
                    cmd.ExecuteNonQuery();

                    UpdateDGVForStudents();
                }
                catch (FormatException) // Проверяем, что ИД это целочисленное значение
                {
                    ShowMessageBox("Идентификатор должен быть целочисленным значением!");
                }
                catch (SQLiteException) // Проверяем, что идентификатор ученика уникален в таблице
                {
                    ShowMessageBox("Ученик с таким идентификатором уже существует!");
                }
            }
            else
            {
                ShowMessageBox("Не все поля заполнены!");
            }
        }

        // Кнопка "Удалить запись" на вкладке "Ученик"
        private void b_DeleteStudent_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(cB_removeStudent.SelectedItem); // Считываем значение

            // Выполнение команд
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "DELETE FROM Students WHERE Id_student = " + id;
            cmd.ExecuteNonQuery();

            UpdateDGVForStudents(); // Обновление отображения записей из БД
        }

        // Переключение вкладок элемента TabControl
        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Проверяем на какую вкладку переключились и обновляем содержимое отображения записей
            if (tC_Main.SelectedIndex == 0) // Студенты
            {
                UpdateDGVForStudents();
            }
            else if (tC_Main.SelectedIndex == 1) // Предметы
            {
                UpdateDGVForItems();
            }
            else if (tC_Main.SelectedIndex == 2) // Оценки
            {
                UpdateDGVForMarks();
            }
            else if (tC_Main.SelectedIndex == 3) // Запросы №1
            {
                UpdateTabForRequests1And2();
            }
            else if (tC_Main.SelectedIndex == 4) // Запросы №2
            {
                UpdateTabForRequests3And4();
            }
        }

        // Кнопка "Удалить запись" на вкладке "Предметы"
        private void b_removeItems_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(cB_removeItems.SelectedItem); // Считываем значение

            // Выполнение команд
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "DELETE FROM Items WHERE Id_item = " + id;
            cmd.ExecuteNonQuery();

            UpdateDGVForItems(); // Обновление отображения записей из БД
        }

        // Кнопка "Добавить запись" на вкладке "Предметы"
        private void b_addItem_Click(object sender, EventArgs e)
        {
            if (tB_idItem.Text != "" & tB_nameItem.Text != "")
            {
                try
                {
                    Convert.ToInt32(tB_idItem.Text);

                    // Добавляем новую запись sql-запросом
                    SQLiteCommand cmd = db.CreateCommand();
                    cmd.CommandText = "insert into Items(Id_item, Name_item) values ( @id, @name)";
                    cmd.Parameters.Add("@id", System.Data.DbType.Int32).Value = Math.Abs(Convert.ToInt32(tB_idItem.Text));
                    cmd.Parameters.Add("@name", System.Data.DbType.String).Value = tB_nameItem.Text;
                    cmd.ExecuteNonQuery();

                    UpdateDGVForItems();
                }
                catch (FormatException) // Проверяем, что ИД это целочисленное значение
                {
                    ShowMessageBox("Идентификатор должен быть целочисленным значением!");
                }
                catch (SQLiteException) // Проверяем, что идентификатор и название предмета уникальны
                {
                    ShowMessageBox("Такой идентификатор или название предмета уже существуют в таблице!");
                }
            }
            else
            {
                ShowMessageBox("Не все поля заполнены!");
            }
        }

        // Кнопка "Добавить запись" на вкладке "Оценки"
        private void b_AddMark_Click(object sender, EventArgs e)
        {
            try
            {
                // Добавляем новую запись sql-запросом
                SQLiteCommand cmd = db.CreateCommand();
                cmd.CommandText = "insert into Marks(id_Student, id_Item, Date_mark, Mark, Description) values (@id_s, @id_i, @date, @mark, @descr)";
                cmd.Parameters.Add("@id_s", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_student.SelectedItem);
                cmd.Parameters.Add("@id_i", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_Item.SelectedItem);
                cmd.Parameters.Add("@date", System.Data.DbType.DateTime).Value = dtP_date.Value;
                cmd.Parameters.Add("@mark", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_Mark.SelectedItem);
                cmd.Parameters.Add("@descr", System.Data.DbType.String).Value = cB_description.Text;
                cmd.ExecuteNonQuery();

                UpdateDGVForMarks();
            }
            catch (SQLiteException) // Проверяем, что дата выставления оценки уникальная
            {
                ShowMessageBox("На эту дату уже существует запись!");
            }
        }

        /// <summary>
        /// Находим оценки выбранного ученика по заданному предмету за указанный период времени
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void b_request1_Click(object sender, EventArgs e)
        {
            dGV_request1.Rows.Clear(); // Очищаем таблицу

            if (dTP_from.Value < dTP_End.Value)
            {
                // Выполняем команды SQL-запроса
                SQLiteCommand cmd = db.CreateCommand();
                cmd.CommandText = "select * from Marks WHERE Date_mark >= @BeginDate and Date_mark <= @EndDate and id_Student = @idStudent and id_Item = @idItem";
                cmd.Parameters.Add("BeginDate", System.Data.DbType.DateTime).Value = dTP_from.Value;
                cmd.Parameters.Add("EndDate", System.Data.DbType.DateTime).Value = dTP_End.Value;
                cmd.Parameters.Add("idStudent", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_findStudent.SelectedItem);
                cmd.Parameters.Add("idItem", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_findItem.SelectedItem);
                SQLiteDataReader sql = cmd.ExecuteReader();

                if (sql.HasRows) // Выводим результат в DataGridView
                {
                    while (sql.Read())
                    {
                        dGV_request1.Rows.Add(sql["Mark"], sql["id_Item"]);
                    }
                }
                else
                {
                    ShowMessageBox("Результат не найден!");
                }
            }
            else
            {
                ShowMessageBox("Некорректно введен временной период!");
            }

        }

        /// <summary>
        /// Находим все оценки всех учеников по заданному предмету за указанный период времени
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void b_request2_Click(object sender, EventArgs e)
        {
            dGV_request2.Rows.Clear(); // Очищаем таблицу

            if (dTP_from.Value < dTP_End.Value)
            {
                // Выполняем команды SQL-запроса
                SQLiteCommand cmd = db.CreateCommand();
                cmd.CommandText = "select * from Marks WHERE Date_mark >= @BeginDate and Date_mark <= @EndDate and id_Item = @idItem";
                cmd.Parameters.Add("BeginDate", System.Data.DbType.DateTime).Value = dTP_from.Value;
                cmd.Parameters.Add("EndDate", System.Data.DbType.DateTime).Value = dTP_End.Value;
                cmd.Parameters.Add("idItem", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_findItem.SelectedItem);
                SQLiteDataReader sql = cmd.ExecuteReader();

                if (sql.HasRows) // Выводим результат в DataGridView
                {
                    while (sql.Read())
                    {
                        dGV_request2.Rows.Add(sql["Mark"], sql["id_Item"], sql["id_Student"]);
                    }
                }
                else
                {
                    ShowMessageBox("Результат не найден!");
                }
            }
            else
            {
                ShowMessageBox("Некорректно введен временной период!");
            }
        }

        /// <summary>
        /// Находим средние оценки каждого ученика за указанный период времени
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void b_Request3_Click(object sender, EventArgs e)
        {
            dGV_Request3.Rows.Clear();
            List<int> listOfIdStudents = new List<int>(); // Список учеников, их ид
            List<int> listOfIdItems = new List<int>(); // Список предметов, их ид
            int two = 0; // 2
            int three = 0; // 3
            int foor = 0; // 4
            int five = 0; // 5
            float average_mark = 0; // Средняя оценка

            if (dTP_Start.Value < dTP_Finish.Value)
            {
                // Выполняем команды SQL-запроса
                SQLiteCommand cmd = db.CreateCommand();
                cmd.CommandText = "select Id_student from Students order by Id_student";
                SQLiteDataReader sql = cmd.ExecuteReader();

                if (sql.HasRows) // Заносим результаты в соответствующий список
                {
                    while (sql.Read())
                    {
                        listOfIdStudents.Add(Convert.ToInt32(sql["Id_student"]));
                    }
                }

                cmd.Dispose();
                sql.Dispose();

                // Выполняем команды SQL-запроса
                cmd = db.CreateCommand();
                cmd.CommandText = "select Id_item from Items order by id_Item";
                sql = cmd.ExecuteReader();

                if (sql.HasRows) // Заносим результаты в соответствующий список
                {
                    while (sql.Read())
                    {
                        listOfIdItems.Add(Convert.ToInt32(sql["Id_item"]));
                    }
                }

                cmd.Dispose();
                sql.Dispose();

                foreach (int id_student in listOfIdStudents) // Ученик
                {
                    two = 0; three = 0; foor = 0; five = 0;

                    foreach (int id_item in listOfIdItems) // Предмет
                    {

                        // Выполняем команды SQL-запроса
                        cmd = db.CreateCommand();
                        cmd.CommandText = "select * from Marks WHERE Date_mark >= @BeginDate and Date_mark <= @EndDate and id_Item = @idItem and id_Student = @id_Student";
                        cmd.Parameters.Add("BeginDate", System.Data.DbType.DateTime).Value = dTP_Start.Value;
                        cmd.Parameters.Add("EndDate", System.Data.DbType.DateTime).Value = dTP_Finish.Value;
                        cmd.Parameters.Add("idItem", System.Data.DbType.Int32).Value = id_item;
                        cmd.Parameters.Add("id_Student", System.Data.DbType.Int32).Value = id_student;
                        sql = cmd.ExecuteReader();

                        if (sql.HasRows) // Заносим результаты в соответствующий список
                        {
                            while (sql.Read())
                            {
                                if (Convert.ToInt32(sql["Mark"]) == 2)
                                {
                                    two++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 3)
                                {
                                    three++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 4)
                                {
                                    foor++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 5)
                                {
                                    five++;
                                }
                            }

                            // Находим средную оценку и выводим в DataGridView
                            average_mark = (2 * two + 3 * three + 4 * foor + 5 * five) / (two + three + foor + five);
                            dGV_Request3.Rows.Add(average_mark, id_item, id_student);
                        }
                    }
                }
            }
            else
            {
                ShowMessageBox("Некорректно введен временной период!");
            }
        }

        /// <summary>
        /// Находим средние оценки по отдельным видам работ среди всех учеников для заданного предмета
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void b_Request4_Click(object sender, EventArgs e)
        {
            dGV_Request4.Rows.Clear();
            List<int> listOfIdStudents = new List<int>(); // Список учеников, их ид
            int two = 0; // 2
            int three = 0; // 3
            int foor = 0; // 4
            int five = 0; // 5
            float average_mark = 0; // Средняя оценка

            if (dTP_Start.Value < dTP_Finish.Value)
            {
                // Выполняем команды SQL-запроса
                SQLiteCommand cmd = db.CreateCommand();
                cmd.CommandText = "select Id_student from Students order by Id_student";
                SQLiteDataReader sql = cmd.ExecuteReader();

                if (sql.HasRows) // Заносим результаты в соответствующий список
                {
                    while (sql.Read())
                    {
                        listOfIdStudents.Add(Convert.ToInt32(sql["Id_student"]));
                    }
                }

                foreach (int id_student in listOfIdStudents) // Ученик
                {
                    two = 0; three = 0; foor = 0; five = 0;

                    for (int i = 0; i < cB_description.Items.Count; i++) // Виды работ
                    {
                        // Выполняем команды SQL-запроса
                        cmd = db.CreateCommand();
                        cmd.CommandText = "select * from Marks WHERE Date_mark >= @BeginDate and Date_mark <= @EndDate and id_Item = @idItem and id_Student = @id_Student and Description = @descr";
                        cmd.Parameters.Add("BeginDate", System.Data.DbType.DateTime).Value = dTP_Start.Value;
                        cmd.Parameters.Add("EndDate", System.Data.DbType.DateTime).Value = dTP_Finish.Value;
                        cmd.Parameters.Add("idItem", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_object.SelectedItem);
                        cmd.Parameters.Add("id_Student", System.Data.DbType.Int32).Value = id_student;
                        cmd.Parameters.Add("descr", System.Data.DbType.String).Value = cB_description.Items[i].ToString();
                        sql = cmd.ExecuteReader();

                        if (sql.HasRows) // Заносим результаты в соответствующий список
                        {
                            while (sql.Read())
                            {
                                if (Convert.ToInt32(sql["Mark"]) == 2)
                                {
                                    two++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 3)
                                {
                                    three++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 4)
                                {
                                    foor++;
                                }
                                else if (Convert.ToInt32(sql["Mark"]) == 5)
                                {
                                    five++;
                                }
                            }

                            // Находим средную оценку и выводим в DataGridView
                            average_mark = (2 * two + 3 * three + 4 * foor + 5 * five) / (two + three + foor + five);
                            dGV_Request4.Rows.Add(average_mark, Convert.ToInt32(cB_object.SelectedItem), id_student, cB_description.Items[i].ToString());
                        }
                    }

                    cmd.Dispose();
                    sql.Dispose();
                }

            }
            else
            {
                ShowMessageBox("Некорректно введен временной период!");
            }      

        }

        // Кнопка "Удалить записи" на вкладке "Оценки"
        private void b_RemoveMarks_Click(object sender, EventArgs e)
        {

            // Выполнение команд
            SQLiteCommand cmd = db.CreateCommand();
            cmd.CommandText = "DELETE FROM Marks WHERE id_Student = @idStudent and id_Item = @idItem";
            cmd.Parameters.Add("idItem", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_Item.SelectedItem);
            cmd.Parameters.Add("idStudent", System.Data.DbType.Int32).Value = Convert.ToInt32(cB_student.SelectedItem);
            cmd.ExecuteNonQuery();

            UpdateDGVForMarks(); // Обновление отображения записей из БД
        }
    }
}
