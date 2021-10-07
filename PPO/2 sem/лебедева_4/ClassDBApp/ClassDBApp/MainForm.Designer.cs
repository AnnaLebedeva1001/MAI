namespace ClassDBApp
{
    partial class MainForm
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.tC_Main = new System.Windows.Forms.TabControl();
            this.tP_Main = new System.Windows.Forms.TabPage();
            this.p_StudentsControlData = new System.Windows.Forms.Panel();
            this.b_AddStudent = new System.Windows.Forms.Button();
            this.l_O = new System.Windows.Forms.Label();
            this.tB_O = new System.Windows.Forms.TextBox();
            this.l_I = new System.Windows.Forms.Label();
            this.tB_I = new System.Windows.Forms.TextBox();
            this.l_F = new System.Windows.Forms.Label();
            this.tB_F = new System.Windows.Forms.TextBox();
            this.l_Gender = new System.Windows.Forms.Label();
            this.cB_Gender = new System.Windows.Forms.ComboBox();
            this.l_IdStudent = new System.Windows.Forms.Label();
            this.tB_IdStudent = new System.Windows.Forms.TextBox();
            this.p_tabelStudents = new System.Windows.Forms.Panel();
            this.cB_removeStudent = new System.Windows.Forms.ComboBox();
            this.l_removeStudent = new System.Windows.Forms.Label();
            this.b_DeleteStudent = new System.Windows.Forms.Button();
            this.dGV_Students = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.p_itemsController = new System.Windows.Forms.Panel();
            this.b_addItem = new System.Windows.Forms.Button();
            this.l_addItem = new System.Windows.Forms.Label();
            this.tB_nameItem = new System.Windows.Forms.TextBox();
            this.l_idItem = new System.Windows.Forms.Label();
            this.tB_idItem = new System.Windows.Forms.TextBox();
            this.p_ViewItems = new System.Windows.Forms.Panel();
            this.l_removeItem = new System.Windows.Forms.Label();
            this.cB_removeItems = new System.Windows.Forms.ComboBox();
            this.b_removeItems = new System.Windows.Forms.Button();
            this.dGV_Items = new System.Windows.Forms.DataGridView();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.panel1 = new System.Windows.Forms.Panel();
            this.b_AddMark = new System.Windows.Forms.Button();
            this.l_Mark = new System.Windows.Forms.Label();
            this.cB_Mark = new System.Windows.Forms.ComboBox();
            this.l_description = new System.Windows.Forms.Label();
            this.cB_description = new System.Windows.Forms.ComboBox();
            this.l_date = new System.Windows.Forms.Label();
            this.dtP_date = new System.Windows.Forms.DateTimePicker();
            this.l_item = new System.Windows.Forms.Label();
            this.cB_Item = new System.Windows.Forms.ComboBox();
            this.l_student = new System.Windows.Forms.Label();
            this.cB_student = new System.Windows.Forms.ComboBox();
            this.p_viewMarks = new System.Windows.Forms.Panel();
            this.dgV_Marks = new System.Windows.Forms.DataGridView();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.p_requests = new System.Windows.Forms.Panel();
            this.b_request2 = new System.Windows.Forms.Button();
            this.l_findItem = new System.Windows.Forms.Label();
            this.cB_findItem = new System.Windows.Forms.ComboBox();
            this.dGV_request2 = new System.Windows.Forms.DataGridView();
            this.b_request1 = new System.Windows.Forms.Button();
            this.dTP_from = new System.Windows.Forms.DateTimePicker();
            this.dTP_End = new System.Windows.Forms.DateTimePicker();
            this.l_end = new System.Windows.Forms.Label();
            this.l_from = new System.Windows.Forms.Label();
            this.cB_findStudent = new System.Windows.Forms.ComboBox();
            this.l_findStudent = new System.Windows.Forms.Label();
            this.dGV_request1 = new System.Windows.Forms.DataGridView();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.dGV_Request3 = new System.Windows.Forms.DataGridView();
            this.dGV_Request4 = new System.Windows.Forms.DataGridView();
            this.b_Request3 = new System.Windows.Forms.Button();
            this.b_Request4 = new System.Windows.Forms.Button();
            this.cB_object = new System.Windows.Forms.ComboBox();
            this.l_object = new System.Windows.Forms.Label();
            this.dTP_Start = new System.Windows.Forms.DateTimePicker();
            this.dTP_Finish = new System.Windows.Forms.DateTimePicker();
            this.l_Start = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.b_RemoveMarks = new System.Windows.Forms.Button();
            this.tC_Main.SuspendLayout();
            this.tP_Main.SuspendLayout();
            this.p_StudentsControlData.SuspendLayout();
            this.p_tabelStudents.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Students)).BeginInit();
            this.tabPage2.SuspendLayout();
            this.p_itemsController.SuspendLayout();
            this.p_ViewItems.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Items)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.panel1.SuspendLayout();
            this.p_viewMarks.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgV_Marks)).BeginInit();
            this.tabPage1.SuspendLayout();
            this.p_requests.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_request2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_request1)).BeginInit();
            this.tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Request3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Request4)).BeginInit();
            this.SuspendLayout();
            // 
            // tC_Main
            // 
            this.tC_Main.Controls.Add(this.tP_Main);
            this.tC_Main.Controls.Add(this.tabPage2);
            this.tC_Main.Controls.Add(this.tabPage3);
            this.tC_Main.Controls.Add(this.tabPage1);
            this.tC_Main.Controls.Add(this.tabPage4);
            this.tC_Main.Location = new System.Drawing.Point(12, 12);
            this.tC_Main.Name = "tC_Main";
            this.tC_Main.SelectedIndex = 0;
            this.tC_Main.Size = new System.Drawing.Size(761, 352);
            this.tC_Main.TabIndex = 0;
            this.tC_Main.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tP_Main
            // 
            this.tP_Main.Controls.Add(this.p_StudentsControlData);
            this.tP_Main.Controls.Add(this.p_tabelStudents);
            this.tP_Main.Location = new System.Drawing.Point(4, 22);
            this.tP_Main.Name = "tP_Main";
            this.tP_Main.Padding = new System.Windows.Forms.Padding(3);
            this.tP_Main.Size = new System.Drawing.Size(753, 326);
            this.tP_Main.TabIndex = 0;
            this.tP_Main.Text = "Ученики";
            this.tP_Main.UseVisualStyleBackColor = true;
            // 
            // p_StudentsControlData
            // 
            this.p_StudentsControlData.Controls.Add(this.b_AddStudent);
            this.p_StudentsControlData.Controls.Add(this.l_O);
            this.p_StudentsControlData.Controls.Add(this.tB_O);
            this.p_StudentsControlData.Controls.Add(this.l_I);
            this.p_StudentsControlData.Controls.Add(this.tB_I);
            this.p_StudentsControlData.Controls.Add(this.l_F);
            this.p_StudentsControlData.Controls.Add(this.tB_F);
            this.p_StudentsControlData.Controls.Add(this.l_Gender);
            this.p_StudentsControlData.Controls.Add(this.cB_Gender);
            this.p_StudentsControlData.Controls.Add(this.l_IdStudent);
            this.p_StudentsControlData.Controls.Add(this.tB_IdStudent);
            this.p_StudentsControlData.Location = new System.Drawing.Point(564, 19);
            this.p_StudentsControlData.Name = "p_StudentsControlData";
            this.p_StudentsControlData.Size = new System.Drawing.Size(183, 272);
            this.p_StudentsControlData.TabIndex = 1;
            // 
            // b_AddStudent
            // 
            this.b_AddStudent.Location = new System.Drawing.Point(11, 230);
            this.b_AddStudent.Name = "b_AddStudent";
            this.b_AddStudent.Size = new System.Drawing.Size(160, 32);
            this.b_AddStudent.TabIndex = 10;
            this.b_AddStudent.Text = "Добавить запись";
            this.b_AddStudent.UseVisualStyleBackColor = true;
            this.b_AddStudent.Click += new System.EventHandler(this.b_AddStudent_Click);
            // 
            // l_O
            // 
            this.l_O.AutoSize = true;
            this.l_O.Location = new System.Drawing.Point(8, 181);
            this.l_O.Name = "l_O";
            this.l_O.Size = new System.Drawing.Size(54, 13);
            this.l_O.TabIndex = 9;
            this.l_O.Text = "Отчество";
            // 
            // tB_O
            // 
            this.tB_O.Location = new System.Drawing.Point(11, 197);
            this.tB_O.Name = "tB_O";
            this.tB_O.Size = new System.Drawing.Size(160, 20);
            this.tB_O.TabIndex = 8;
            // 
            // l_I
            // 
            this.l_I.AutoSize = true;
            this.l_I.Location = new System.Drawing.Point(8, 138);
            this.l_I.Name = "l_I";
            this.l_I.Size = new System.Drawing.Size(29, 13);
            this.l_I.TabIndex = 7;
            this.l_I.Text = "Имя";
            // 
            // tB_I
            // 
            this.tB_I.Location = new System.Drawing.Point(11, 154);
            this.tB_I.Name = "tB_I";
            this.tB_I.Size = new System.Drawing.Size(160, 20);
            this.tB_I.TabIndex = 6;
            // 
            // l_F
            // 
            this.l_F.AutoSize = true;
            this.l_F.Location = new System.Drawing.Point(8, 99);
            this.l_F.Name = "l_F";
            this.l_F.Size = new System.Drawing.Size(56, 13);
            this.l_F.TabIndex = 5;
            this.l_F.Text = "Фамилия";
            // 
            // tB_F
            // 
            this.tB_F.Location = new System.Drawing.Point(11, 115);
            this.tB_F.Name = "tB_F";
            this.tB_F.Size = new System.Drawing.Size(160, 20);
            this.tB_F.TabIndex = 4;
            // 
            // l_Gender
            // 
            this.l_Gender.AutoSize = true;
            this.l_Gender.Location = new System.Drawing.Point(92, 58);
            this.l_Gender.Name = "l_Gender";
            this.l_Gender.Size = new System.Drawing.Size(27, 13);
            this.l_Gender.TabIndex = 3;
            this.l_Gender.Text = "Пол";
            // 
            // cB_Gender
            // 
            this.cB_Gender.FormattingEnabled = true;
            this.cB_Gender.Items.AddRange(new object[] {
            "М",
            "Ж"});
            this.cB_Gender.Location = new System.Drawing.Point(95, 74);
            this.cB_Gender.Name = "cB_Gender";
            this.cB_Gender.Size = new System.Drawing.Size(76, 21);
            this.cB_Gender.TabIndex = 2;
            // 
            // l_IdStudent
            // 
            this.l_IdStudent.AutoSize = true;
            this.l_IdStudent.Location = new System.Drawing.Point(8, 9);
            this.l_IdStudent.Name = "l_IdStudent";
            this.l_IdStudent.Size = new System.Drawing.Size(135, 13);
            this.l_IdStudent.TabIndex = 1;
            this.l_IdStudent.Text = "Идентификатор студента";
            // 
            // tB_IdStudent
            // 
            this.tB_IdStudent.Location = new System.Drawing.Point(11, 25);
            this.tB_IdStudent.Name = "tB_IdStudent";
            this.tB_IdStudent.Size = new System.Drawing.Size(160, 20);
            this.tB_IdStudent.TabIndex = 0;
            // 
            // p_tabelStudents
            // 
            this.p_tabelStudents.Controls.Add(this.cB_removeStudent);
            this.p_tabelStudents.Controls.Add(this.l_removeStudent);
            this.p_tabelStudents.Controls.Add(this.b_DeleteStudent);
            this.p_tabelStudents.Controls.Add(this.dGV_Students);
            this.p_tabelStudents.Location = new System.Drawing.Point(6, 19);
            this.p_tabelStudents.Name = "p_tabelStudents";
            this.p_tabelStudents.Size = new System.Drawing.Size(552, 291);
            this.p_tabelStudents.TabIndex = 0;
            // 
            // cB_removeStudent
            // 
            this.cB_removeStudent.FormattingEnabled = true;
            this.cB_removeStudent.Location = new System.Drawing.Point(300, 258);
            this.cB_removeStudent.Name = "cB_removeStudent";
            this.cB_removeStudent.Size = new System.Drawing.Size(81, 21);
            this.cB_removeStudent.TabIndex = 4;
            // 
            // l_removeStudent
            // 
            this.l_removeStudent.AutoSize = true;
            this.l_removeStudent.Location = new System.Drawing.Point(223, 262);
            this.l_removeStudent.Name = "l_removeStudent";
            this.l_removeStudent.Size = new System.Drawing.Size(72, 13);
            this.l_removeStudent.TabIndex = 3;
            this.l_removeStudent.Text = "ID студента:";
            // 
            // b_DeleteStudent
            // 
            this.b_DeleteStudent.Location = new System.Drawing.Point(387, 255);
            this.b_DeleteStudent.Name = "b_DeleteStudent";
            this.b_DeleteStudent.Size = new System.Drawing.Size(156, 26);
            this.b_DeleteStudent.TabIndex = 1;
            this.b_DeleteStudent.Text = "Удалить запись";
            this.b_DeleteStudent.UseVisualStyleBackColor = true;
            this.b_DeleteStudent.Click += new System.EventHandler(this.b_DeleteStudent_Click);
            // 
            // dGV_Students
            // 
            this.dGV_Students.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Students.Location = new System.Drawing.Point(5, 9);
            this.dGV_Students.Name = "dGV_Students";
            this.dGV_Students.Size = new System.Drawing.Size(544, 237);
            this.dGV_Students.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.p_itemsController);
            this.tabPage2.Controls.Add(this.p_ViewItems);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(753, 326);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Предметы";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // p_itemsController
            // 
            this.p_itemsController.Controls.Add(this.b_addItem);
            this.p_itemsController.Controls.Add(this.l_addItem);
            this.p_itemsController.Controls.Add(this.tB_nameItem);
            this.p_itemsController.Controls.Add(this.l_idItem);
            this.p_itemsController.Controls.Add(this.tB_idItem);
            this.p_itemsController.Location = new System.Drawing.Point(537, 18);
            this.p_itemsController.Name = "p_itemsController";
            this.p_itemsController.Size = new System.Drawing.Size(192, 173);
            this.p_itemsController.TabIndex = 1;
            // 
            // b_addItem
            // 
            this.b_addItem.Location = new System.Drawing.Point(14, 118);
            this.b_addItem.Name = "b_addItem";
            this.b_addItem.Size = new System.Drawing.Size(163, 40);
            this.b_addItem.TabIndex = 4;
            this.b_addItem.Text = "Добавить запись";
            this.b_addItem.UseVisualStyleBackColor = true;
            this.b_addItem.Click += new System.EventHandler(this.b_addItem_Click);
            // 
            // l_addItem
            // 
            this.l_addItem.AutoSize = true;
            this.l_addItem.Location = new System.Drawing.Point(11, 65);
            this.l_addItem.Name = "l_addItem";
            this.l_addItem.Size = new System.Drawing.Size(111, 13);
            this.l_addItem.TabIndex = 3;
            this.l_addItem.Text = "Название предметы";
            // 
            // tB_nameItem
            // 
            this.tB_nameItem.Location = new System.Drawing.Point(14, 81);
            this.tB_nameItem.Name = "tB_nameItem";
            this.tB_nameItem.Size = new System.Drawing.Size(163, 20);
            this.tB_nameItem.TabIndex = 2;
            // 
            // l_idItem
            // 
            this.l_idItem.AutoSize = true;
            this.l_idItem.Location = new System.Drawing.Point(11, 12);
            this.l_idItem.Name = "l_idItem";
            this.l_idItem.Size = new System.Drawing.Size(139, 13);
            this.l_idItem.TabIndex = 1;
            this.l_idItem.Text = "Идентификатор предмета";
            // 
            // tB_idItem
            // 
            this.tB_idItem.Location = new System.Drawing.Point(14, 28);
            this.tB_idItem.Name = "tB_idItem";
            this.tB_idItem.Size = new System.Drawing.Size(163, 20);
            this.tB_idItem.TabIndex = 0;
            // 
            // p_ViewItems
            // 
            this.p_ViewItems.Controls.Add(this.l_removeItem);
            this.p_ViewItems.Controls.Add(this.cB_removeItems);
            this.p_ViewItems.Controls.Add(this.b_removeItems);
            this.p_ViewItems.Controls.Add(this.dGV_Items);
            this.p_ViewItems.Location = new System.Drawing.Point(16, 18);
            this.p_ViewItems.Name = "p_ViewItems";
            this.p_ViewItems.Size = new System.Drawing.Size(474, 288);
            this.p_ViewItems.TabIndex = 0;
            // 
            // l_removeItem
            // 
            this.l_removeItem.AutoSize = true;
            this.l_removeItem.Location = new System.Drawing.Point(180, 259);
            this.l_removeItem.Name = "l_removeItem";
            this.l_removeItem.Size = new System.Drawing.Size(76, 13);
            this.l_removeItem.TabIndex = 3;
            this.l_removeItem.Text = "ID предмета:";
            // 
            // cB_removeItems
            // 
            this.cB_removeItems.FormattingEnabled = true;
            this.cB_removeItems.Location = new System.Drawing.Point(262, 256);
            this.cB_removeItems.Name = "cB_removeItems";
            this.cB_removeItems.Size = new System.Drawing.Size(69, 21);
            this.cB_removeItems.TabIndex = 2;
            // 
            // b_removeItems
            // 
            this.b_removeItems.Location = new System.Drawing.Point(337, 254);
            this.b_removeItems.Name = "b_removeItems";
            this.b_removeItems.Size = new System.Drawing.Size(117, 23);
            this.b_removeItems.TabIndex = 1;
            this.b_removeItems.Text = "Удалить запись";
            this.b_removeItems.UseVisualStyleBackColor = true;
            this.b_removeItems.Click += new System.EventHandler(this.b_removeItems_Click);
            // 
            // dGV_Items
            // 
            this.dGV_Items.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Items.Location = new System.Drawing.Point(16, 13);
            this.dGV_Items.Name = "dGV_Items";
            this.dGV_Items.Size = new System.Drawing.Size(438, 235);
            this.dGV_Items.TabIndex = 0;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.panel1);
            this.tabPage3.Controls.Add(this.p_viewMarks);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(753, 326);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Оценки";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.b_RemoveMarks);
            this.panel1.Controls.Add(this.b_AddMark);
            this.panel1.Controls.Add(this.l_Mark);
            this.panel1.Controls.Add(this.cB_Mark);
            this.panel1.Controls.Add(this.l_description);
            this.panel1.Controls.Add(this.cB_description);
            this.panel1.Controls.Add(this.l_date);
            this.panel1.Controls.Add(this.dtP_date);
            this.panel1.Controls.Add(this.l_item);
            this.panel1.Controls.Add(this.cB_Item);
            this.panel1.Controls.Add(this.l_student);
            this.panel1.Controls.Add(this.cB_student);
            this.panel1.Location = new System.Drawing.Point(566, 15);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(173, 298);
            this.panel1.TabIndex = 1;
            // 
            // b_AddMark
            // 
            this.b_AddMark.Location = new System.Drawing.Point(17, 264);
            this.b_AddMark.Name = "b_AddMark";
            this.b_AddMark.Size = new System.Drawing.Size(121, 24);
            this.b_AddMark.TabIndex = 10;
            this.b_AddMark.Text = "Добавить запись";
            this.b_AddMark.UseVisualStyleBackColor = true;
            this.b_AddMark.Click += new System.EventHandler(this.b_AddMark_Click);
            // 
            // l_Mark
            // 
            this.l_Mark.AutoSize = true;
            this.l_Mark.Location = new System.Drawing.Point(14, 221);
            this.l_Mark.Name = "l_Mark";
            this.l_Mark.Size = new System.Drawing.Size(45, 13);
            this.l_Mark.TabIndex = 9;
            this.l_Mark.Text = "Оценка";
            // 
            // cB_Mark
            // 
            this.cB_Mark.AutoCompleteCustomSource.AddRange(new string[] {
            "2",
            "3",
            "4",
            "5"});
            this.cB_Mark.FormattingEnabled = true;
            this.cB_Mark.Items.AddRange(new object[] {
            "2",
            "3",
            "4",
            "5"});
            this.cB_Mark.Location = new System.Drawing.Point(17, 237);
            this.cB_Mark.Name = "cB_Mark";
            this.cB_Mark.Size = new System.Drawing.Size(61, 21);
            this.cB_Mark.TabIndex = 8;
            // 
            // l_description
            // 
            this.l_description.AutoSize = true;
            this.l_description.Location = new System.Drawing.Point(14, 181);
            this.l_description.Name = "l_description";
            this.l_description.Size = new System.Drawing.Size(57, 13);
            this.l_description.TabIndex = 7;
            this.l_description.Text = "Описание";
            // 
            // cB_description
            // 
            this.cB_description.FormattingEnabled = true;
            this.cB_description.Items.AddRange(new object[] {
            "За домашнее задание",
            "За контрольную работу",
            "За работу у доски",
            "За устный ответ",
            "За доклад",
            "За самостоятельную работу"});
            this.cB_description.Location = new System.Drawing.Point(17, 197);
            this.cB_description.Name = "cB_description";
            this.cB_description.Size = new System.Drawing.Size(152, 21);
            this.cB_description.TabIndex = 6;
            // 
            // l_date
            // 
            this.l_date.AutoSize = true;
            this.l_date.Location = new System.Drawing.Point(14, 141);
            this.l_date.Name = "l_date";
            this.l_date.Size = new System.Drawing.Size(33, 13);
            this.l_date.TabIndex = 5;
            this.l_date.Text = "Дата";
            // 
            // dtP_date
            // 
            this.dtP_date.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dtP_date.Location = new System.Drawing.Point(17, 157);
            this.dtP_date.Name = "dtP_date";
            this.dtP_date.Size = new System.Drawing.Size(121, 20);
            this.dtP_date.TabIndex = 4;
            // 
            // l_item
            // 
            this.l_item.AutoSize = true;
            this.l_item.Location = new System.Drawing.Point(14, 58);
            this.l_item.Name = "l_item";
            this.l_item.Size = new System.Drawing.Size(73, 13);
            this.l_item.TabIndex = 3;
            this.l_item.Text = "ID предмета";
            // 
            // cB_Item
            // 
            this.cB_Item.FormattingEnabled = true;
            this.cB_Item.Location = new System.Drawing.Point(17, 74);
            this.cB_Item.Name = "cB_Item";
            this.cB_Item.Size = new System.Drawing.Size(121, 21);
            this.cB_Item.TabIndex = 2;
            // 
            // l_student
            // 
            this.l_student.AutoSize = true;
            this.l_student.Location = new System.Drawing.Point(14, 12);
            this.l_student.Name = "l_student";
            this.l_student.Size = new System.Drawing.Size(64, 13);
            this.l_student.TabIndex = 1;
            this.l_student.Text = "ID ученика";
            // 
            // cB_student
            // 
            this.cB_student.FormattingEnabled = true;
            this.cB_student.Location = new System.Drawing.Point(17, 32);
            this.cB_student.Name = "cB_student";
            this.cB_student.Size = new System.Drawing.Size(121, 21);
            this.cB_student.TabIndex = 0;
            // 
            // p_viewMarks
            // 
            this.p_viewMarks.Controls.Add(this.dgV_Marks);
            this.p_viewMarks.Location = new System.Drawing.Point(18, 15);
            this.p_viewMarks.Name = "p_viewMarks";
            this.p_viewMarks.Size = new System.Drawing.Size(541, 298);
            this.p_viewMarks.TabIndex = 0;
            // 
            // dgV_Marks
            // 
            this.dgV_Marks.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgV_Marks.Location = new System.Drawing.Point(14, 12);
            this.dgV_Marks.Name = "dgV_Marks";
            this.dgV_Marks.Size = new System.Drawing.Size(509, 247);
            this.dgV_Marks.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.AutoScroll = true;
            this.tabPage1.Controls.Add(this.p_requests);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Size = new System.Drawing.Size(753, 326);
            this.tabPage1.TabIndex = 3;
            this.tabPage1.Text = "Запросы №1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // p_requests
            // 
            this.p_requests.Controls.Add(this.b_request2);
            this.p_requests.Controls.Add(this.l_findItem);
            this.p_requests.Controls.Add(this.cB_findItem);
            this.p_requests.Controls.Add(this.dGV_request2);
            this.p_requests.Controls.Add(this.b_request1);
            this.p_requests.Controls.Add(this.dTP_from);
            this.p_requests.Controls.Add(this.dTP_End);
            this.p_requests.Controls.Add(this.l_end);
            this.p_requests.Controls.Add(this.l_from);
            this.p_requests.Controls.Add(this.cB_findStudent);
            this.p_requests.Controls.Add(this.l_findStudent);
            this.p_requests.Controls.Add(this.dGV_request1);
            this.p_requests.Location = new System.Drawing.Point(18, 13);
            this.p_requests.Name = "p_requests";
            this.p_requests.Size = new System.Drawing.Size(722, 298);
            this.p_requests.TabIndex = 0;
            // 
            // b_request2
            // 
            this.b_request2.Location = new System.Drawing.Point(510, 264);
            this.b_request2.Name = "b_request2";
            this.b_request2.Size = new System.Drawing.Size(75, 23);
            this.b_request2.TabIndex = 12;
            this.b_request2.Text = "Найти";
            this.b_request2.UseVisualStyleBackColor = true;
            this.b_request2.Click += new System.EventHandler(this.b_request2_Click);
            // 
            // l_findItem
            // 
            this.l_findItem.AutoSize = true;
            this.l_findItem.Location = new System.Drawing.Point(249, 73);
            this.l_findItem.Name = "l_findItem";
            this.l_findItem.Size = new System.Drawing.Size(73, 13);
            this.l_findItem.TabIndex = 11;
            this.l_findItem.Text = "ID предмета";
            // 
            // cB_findItem
            // 
            this.cB_findItem.FormattingEnabled = true;
            this.cB_findItem.Location = new System.Drawing.Point(249, 89);
            this.cB_findItem.Name = "cB_findItem";
            this.cB_findItem.Size = new System.Drawing.Size(80, 21);
            this.cB_findItem.TabIndex = 10;
            // 
            // dGV_request2
            // 
            this.dGV_request2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_request2.Location = new System.Drawing.Point(371, 17);
            this.dGV_request2.Name = "dGV_request2";
            this.dGV_request2.Size = new System.Drawing.Size(338, 241);
            this.dGV_request2.TabIndex = 9;
            // 
            // b_request1
            // 
            this.b_request1.Location = new System.Drawing.Point(86, 264);
            this.b_request1.Name = "b_request1";
            this.b_request1.Size = new System.Drawing.Size(75, 23);
            this.b_request1.TabIndex = 8;
            this.b_request1.Text = "Найти";
            this.b_request1.UseVisualStyleBackColor = true;
            this.b_request1.Click += new System.EventHandler(this.b_request1_Click);
            // 
            // dTP_from
            // 
            this.dTP_from.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dTP_from.Location = new System.Drawing.Point(249, 135);
            this.dTP_from.Name = "dTP_from";
            this.dTP_from.Size = new System.Drawing.Size(116, 20);
            this.dTP_from.TabIndex = 5;
            // 
            // dTP_End
            // 
            this.dTP_End.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dTP_End.Location = new System.Drawing.Point(249, 174);
            this.dTP_End.Name = "dTP_End";
            this.dTP_End.Size = new System.Drawing.Size(116, 20);
            this.dTP_End.TabIndex = 7;
            // 
            // l_end
            // 
            this.l_end.AutoSize = true;
            this.l_end.Location = new System.Drawing.Point(246, 158);
            this.l_end.Name = "l_end";
            this.l_end.Size = new System.Drawing.Size(21, 13);
            this.l_end.TabIndex = 6;
            this.l_end.Text = "По";
            // 
            // l_from
            // 
            this.l_from.AutoSize = true;
            this.l_from.Location = new System.Drawing.Point(249, 119);
            this.l_from.Name = "l_from";
            this.l_from.Size = new System.Drawing.Size(14, 13);
            this.l_from.TabIndex = 4;
            this.l_from.Text = "C";
            // 
            // cB_findStudent
            // 
            this.cB_findStudent.FormattingEnabled = true;
            this.cB_findStudent.Location = new System.Drawing.Point(249, 49);
            this.cB_findStudent.Name = "cB_findStudent";
            this.cB_findStudent.Size = new System.Drawing.Size(80, 21);
            this.cB_findStudent.TabIndex = 3;
            // 
            // l_findStudent
            // 
            this.l_findStudent.AutoSize = true;
            this.l_findStudent.Location = new System.Drawing.Point(249, 33);
            this.l_findStudent.Name = "l_findStudent";
            this.l_findStudent.Size = new System.Drawing.Size(64, 13);
            this.l_findStudent.TabIndex = 2;
            this.l_findStudent.Text = "ID ученика";
            // 
            // dGV_request1
            // 
            this.dGV_request1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_request1.Location = new System.Drawing.Point(17, 17);
            this.dGV_request1.Name = "dGV_request1";
            this.dGV_request1.Size = new System.Drawing.Size(226, 241);
            this.dGV_request1.TabIndex = 0;
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.label1);
            this.tabPage4.Controls.Add(this.l_Start);
            this.tabPage4.Controls.Add(this.dTP_Finish);
            this.tabPage4.Controls.Add(this.dTP_Start);
            this.tabPage4.Controls.Add(this.l_object);
            this.tabPage4.Controls.Add(this.cB_object);
            this.tabPage4.Controls.Add(this.b_Request4);
            this.tabPage4.Controls.Add(this.b_Request3);
            this.tabPage4.Controls.Add(this.dGV_Request4);
            this.tabPage4.Controls.Add(this.dGV_Request3);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(753, 326);
            this.tabPage4.TabIndex = 4;
            this.tabPage4.Text = "Запросы №2";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // dGV_Request3
            // 
            this.dGV_Request3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Request3.Location = new System.Drawing.Point(15, 14);
            this.dGV_Request3.Name = "dGV_Request3";
            this.dGV_Request3.Size = new System.Drawing.Size(246, 273);
            this.dGV_Request3.TabIndex = 0;
            // 
            // dGV_Request4
            // 
            this.dGV_Request4.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Request4.Location = new System.Drawing.Point(372, 14);
            this.dGV_Request4.Name = "dGV_Request4";
            this.dGV_Request4.Size = new System.Drawing.Size(367, 273);
            this.dGV_Request4.TabIndex = 1;
            // 
            // b_Request3
            // 
            this.b_Request3.Location = new System.Drawing.Point(93, 293);
            this.b_Request3.Name = "b_Request3";
            this.b_Request3.Size = new System.Drawing.Size(75, 23);
            this.b_Request3.TabIndex = 2;
            this.b_Request3.Text = "Найти";
            this.b_Request3.UseVisualStyleBackColor = true;
            this.b_Request3.Click += new System.EventHandler(this.b_Request3_Click);
            // 
            // b_Request4
            // 
            this.b_Request4.Location = new System.Drawing.Point(524, 293);
            this.b_Request4.Name = "b_Request4";
            this.b_Request4.Size = new System.Drawing.Size(75, 24);
            this.b_Request4.TabIndex = 3;
            this.b_Request4.Text = "Найти";
            this.b_Request4.UseVisualStyleBackColor = true;
            this.b_Request4.Click += new System.EventHandler(this.b_Request4_Click);
            // 
            // cB_object
            // 
            this.cB_object.FormattingEnabled = true;
            this.cB_object.Location = new System.Drawing.Point(270, 74);
            this.cB_object.Name = "cB_object";
            this.cB_object.Size = new System.Drawing.Size(96, 21);
            this.cB_object.TabIndex = 4;
            // 
            // l_object
            // 
            this.l_object.AutoSize = true;
            this.l_object.Location = new System.Drawing.Point(267, 58);
            this.l_object.Name = "l_object";
            this.l_object.Size = new System.Drawing.Size(73, 13);
            this.l_object.TabIndex = 5;
            this.l_object.Text = "ID предмета";
            // 
            // dTP_Start
            // 
            this.dTP_Start.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dTP_Start.Location = new System.Drawing.Point(270, 143);
            this.dTP_Start.Name = "dTP_Start";
            this.dTP_Start.Size = new System.Drawing.Size(96, 20);
            this.dTP_Start.TabIndex = 8;
            // 
            // dTP_Finish
            // 
            this.dTP_Finish.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dTP_Finish.Location = new System.Drawing.Point(270, 182);
            this.dTP_Finish.Name = "dTP_Finish";
            this.dTP_Finish.Size = new System.Drawing.Size(96, 20);
            this.dTP_Finish.TabIndex = 9;
            // 
            // l_Start
            // 
            this.l_Start.AutoSize = true;
            this.l_Start.Location = new System.Drawing.Point(267, 127);
            this.l_Start.Name = "l_Start";
            this.l_Start.Size = new System.Drawing.Size(14, 13);
            this.l_Start.TabIndex = 10;
            this.l_Start.Text = "С";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(267, 166);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(21, 13);
            this.label1.TabIndex = 11;
            this.label1.Text = "По";
            // 
            // b_RemoveMarks
            // 
            this.b_RemoveMarks.Location = new System.Drawing.Point(17, 105);
            this.b_RemoveMarks.Name = "b_RemoveMarks";
            this.b_RemoveMarks.Size = new System.Drawing.Size(121, 23);
            this.b_RemoveMarks.TabIndex = 11;
            this.b_RemoveMarks.Text = "Удалить записи";
            this.b_RemoveMarks.UseVisualStyleBackColor = true;
            this.b_RemoveMarks.Click += new System.EventHandler(this.b_RemoveMarks_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 370);
            this.Controls.Add(this.tC_Main);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Успеваемость учеников";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.tC_Main.ResumeLayout(false);
            this.tP_Main.ResumeLayout(false);
            this.p_StudentsControlData.ResumeLayout(false);
            this.p_StudentsControlData.PerformLayout();
            this.p_tabelStudents.ResumeLayout(false);
            this.p_tabelStudents.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Students)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.p_itemsController.ResumeLayout(false);
            this.p_itemsController.PerformLayout();
            this.p_ViewItems.ResumeLayout(false);
            this.p_ViewItems.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Items)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.p_viewMarks.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgV_Marks)).EndInit();
            this.tabPage1.ResumeLayout(false);
            this.p_requests.ResumeLayout(false);
            this.p_requests.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_request2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_request1)).EndInit();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Request3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Request4)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tC_Main;
        private System.Windows.Forms.TabPage tP_Main;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Panel p_tabelStudents;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.DataGridView dGV_Students;
        private System.Windows.Forms.Panel p_StudentsControlData;
        private System.Windows.Forms.TextBox tB_IdStudent;
        private System.Windows.Forms.Label l_IdStudent;
        private System.Windows.Forms.Label l_Gender;
        private System.Windows.Forms.ComboBox cB_Gender;
        private System.Windows.Forms.Label l_F;
        private System.Windows.Forms.TextBox tB_F;
        private System.Windows.Forms.Label l_I;
        private System.Windows.Forms.TextBox tB_I;
        private System.Windows.Forms.Button b_AddStudent;
        private System.Windows.Forms.Label l_O;
        private System.Windows.Forms.TextBox tB_O;
        private System.Windows.Forms.Button b_DeleteStudent;
        private System.Windows.Forms.Label l_removeStudent;
        private System.Windows.Forms.ComboBox cB_removeStudent;
        private System.Windows.Forms.Panel p_ViewItems;
        private System.Windows.Forms.ComboBox cB_removeItems;
        private System.Windows.Forms.Button b_removeItems;
        private System.Windows.Forms.DataGridView dGV_Items;
        private System.Windows.Forms.Label l_removeItem;
        private System.Windows.Forms.Panel p_itemsController;
        private System.Windows.Forms.Button b_addItem;
        private System.Windows.Forms.Label l_addItem;
        private System.Windows.Forms.TextBox tB_nameItem;
        private System.Windows.Forms.Label l_idItem;
        private System.Windows.Forms.TextBox tB_idItem;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel p_viewMarks;
        private System.Windows.Forms.DataGridView dgV_Marks;
        private System.Windows.Forms.ComboBox cB_student;
        private System.Windows.Forms.DateTimePicker dtP_date;
        private System.Windows.Forms.Label l_item;
        private System.Windows.Forms.ComboBox cB_Item;
        private System.Windows.Forms.Label l_student;
        private System.Windows.Forms.Label l_date;
        private System.Windows.Forms.Button b_AddMark;
        private System.Windows.Forms.Label l_Mark;
        private System.Windows.Forms.ComboBox cB_Mark;
        private System.Windows.Forms.Label l_description;
        private System.Windows.Forms.ComboBox cB_description;
        private System.Windows.Forms.Panel p_requests;
        private System.Windows.Forms.Button b_request1;
        private System.Windows.Forms.DateTimePicker dTP_End;
        private System.Windows.Forms.Label l_end;
        private System.Windows.Forms.DateTimePicker dTP_from;
        private System.Windows.Forms.Label l_from;
        private System.Windows.Forms.ComboBox cB_findStudent;
        private System.Windows.Forms.Label l_findStudent;
        private System.Windows.Forms.DataGridView dGV_request1;
        private System.Windows.Forms.Button b_request2;
        private System.Windows.Forms.Label l_findItem;
        private System.Windows.Forms.ComboBox cB_findItem;
        private System.Windows.Forms.DataGridView dGV_request2;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.DataGridView dGV_Request4;
        private System.Windows.Forms.DataGridView dGV_Request3;
        private System.Windows.Forms.Button b_Request4;
        private System.Windows.Forms.Button b_Request3;
        private System.Windows.Forms.Label l_object;
        private System.Windows.Forms.ComboBox cB_object;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label l_Start;
        private System.Windows.Forms.DateTimePicker dTP_Finish;
        private System.Windows.Forms.DateTimePicker dTP_Start;
        private System.Windows.Forms.Button b_RemoveMarks;
    }
}

