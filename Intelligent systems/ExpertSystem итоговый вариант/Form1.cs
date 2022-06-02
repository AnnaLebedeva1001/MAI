using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.Data.SqlClient;

namespace ExpertSystem
{
    public partial class Form1 : Form
    {
        int current;
        List<Node> nodes;
        string key;
        public class Answer
        {
            public string answer;
            public int nextNode;
        }

        public class Node
        {
            public string title;
            public int prevNode;
            public List<Answer> answers;
            public string help;
        }

        public Form1()
        {
            InitializeComponent();
            using (StreamReader r = new StreamReader(new MemoryStream(Properties.Resources.nodes)))
            {
                string json = r.ReadToEnd();
                nodes = JsonConvert.DeserializeObject<List<Node>>(json);
            }
            current = 1;
            key = null;
            Show_node(current);
        }

        private void next_b_Click(object sender, EventArgs e)
        {
            if ((nodes[current].title != "ans")&&(checkedListBox1.CheckedIndices.Count != 0))
            {
                int i = Convert.ToInt32(checkedListBox1.CheckedIndices[0]);
                int next = nodes[current].answers[i].nextNode;
                key += Convert.ToString(i);
                if (next != 0)
                {
                    Show_node(next);
                    current = next;
                }
                else
                {
                    Show_ans(key);
                    current = next;
                    back_b.Visible = false;
                }
            }
            
        }
        private void back_b_Click(object sender, EventArgs e)
        {
            key = key.Remove(key.Length - 1);
            int prev = nodes[current].prevNode;
            if (prev != 0)
            {
                Show_node(prev);
                current = prev;
            }
        }

        private void start_b_Click(object sender, EventArgs e)
        {
            key = null;
            Show_node(1);
            current = 1;
        }

        void Show_node(int cur)
        {
            button2.Visible = false;
            checkedListBox1.Visible = true;
            Qtext.Text = nodes[cur].title;
            checkedListBox1.Items.Clear();
            List<Answer> anses = nodes[cur].answers;
            for(int i = 0; i<anses.Count; i++)
            {
                checkedListBox1.Items.Add(anses[i].answer, false);
            }
        }

        void Show_ans(string key)
        {
            string prog_lang;
            string connection_string = @"Data Source=(LocalDB)\MSSQLLocalDB;
            AttachDbFilename=C:\Users\lebed\Expert_system.mdf;
             Integrated Security=True;Connect Timeout=30";
            // Создание подключения

            using (SqlConnection connection = new SqlConnection(connection_string))
            {
                connection.Open();
                SqlDataReader reader = null;
                SqlCommand command = new SqlCommand("SELECT * FROM programming_languages", connection);

                reader = command.ExecuteReader();
                for (int i = 0; i < 28; i++)
                {
                    reader.Read();
                    if (Convert.ToString(reader[0]) == key)
                    {
                        prog_lang = Convert.ToString(reader[1]);
                        Qtext.Text = "Ответ :  " + prog_lang;
                    }
                }

                if (reader != null)
                    reader.Close();
            }

            checkedListBox1.Visible = false;
            button2.Visible = true;
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (checkedListBox1.CheckedItems.Count > 1)
            {
                for (int i = 0; i < checkedListBox1.Items.Count; i++)
                    checkedListBox1.SetItemChecked(i, false);
                checkedListBox1.SetItemChecked(checkedListBox1.SelectedIndex, true);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (current != 0)
            {
                MessageBox.Show(nodes[current].help, "Помощь", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                string help;
                string connection_string = @"Data Source=(LocalDB)\MSSQLLocalDB;
            AttachDbFilename=C:\Users\lebed\Expert_system.mdf;
             Integrated Security=True;Connect Timeout=30";
                // Создание подключения

                using (SqlConnection connection = new SqlConnection(connection_string))
                {
                    connection.Open();
                    SqlDataReader reader = null;
                    SqlCommand command = new SqlCommand("SELECT * FROM programming_languages", connection);

                    reader = command.ExecuteReader();
                    for (int i = 0; i < 28; i++)
                    {
                        reader.Read();
                        if (Convert.ToString(reader[0]) == key)
                        {
                            help = Convert.ToString(reader[2]);
                            MessageBox.Show(help, "Помощь", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        }
                    }

                    if (reader != null)
                        reader.Close();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string url = "https://yandex.ru/search/?text=" + Qtext.Text;
            System.Diagnostics.Process.Start(url);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
