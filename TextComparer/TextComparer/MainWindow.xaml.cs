using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;

namespace TextComparer
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private bool compareText(string text1, string text2)
        {
            string[] texts1 = text1.Split('\n');
            string[] texts2 = text2.Split('\n');

            for (int i = 0; i < texts1.Length; i++)
                if (texts1[i] != texts2[i])
                {
                    MessageBox.Show("targetText의" + texts1[i] + "와" + "\n" + "originalText의 " + texts2[i] + "가 다릅니다.");
                    return false;
                }
            return true;
        }

        string readFile(string filePath)
        {
            string text = "";
            try
            {
                FileStream fs = new FileStream(filePath, FileMode.Open, FileAccess.Read);
                StreamReader br = new StreamReader(fs);

                text = br.ReadToEnd();

                br.Close();
                fs.Close();
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message);
            }
            return text;
        }

        void setDropedPaths(string[] paths, TextBox targetTextBox)
        {
            if (paths != null && paths.Length != 0)
            {
                if (targetTextBox.Text.Length > 0)
                {
                    if (targetTextBox.Text[targetTextBox.Text.Length - 1] != '\n')
                    {
                        targetTextBox.Text += "\n";
                    }
                }
                foreach (string fileName in paths)
                    targetTextBox.Text += fileName + "\n";
            }
        }

        void compareEachFiles()
        {
            string absolutePath = "";
            if (UserPathCheckBox.IsChecked == true)
            {
                absolutePath = PathTextBox.Text;
            }
            string originalFileName = mw_mg_original_textbox.Text;
            string[] targetPaths = mw_mg_target_textbox.Text.Split('\n');

            string originalText = readFile(absolutePath + originalFileName.Trim());

            bool isAllEqual = true;
            foreach (string targetFileName in targetPaths)
            {
                if (string.IsNullOrWhiteSpace(targetFileName))
                    continue;
                string targetText = readFile(absolutePath + targetFileName);
                if (!compareText(targetText, originalText))
                {
                    MessageBox.Show(targetFileName + "불일치");
                    isAllEqual = false;
                }
            }
            if (isAllEqual)
            {
                MessageBox.Show("모든 파일이 원본에 대해 일치합니다.");
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string text1 = mw_mg_target_textbox.Text;
            string text2 = mw_mg_original_textbox.Text;
            if(compareText(text1, text2))
            {
                MessageBox.Show("양 텍스트가 일치합니다.");
            }
            else
            {
                MessageBox.Show("양 텍스트가 불일치합니다.");
            }
        }

        private void CompareFileBtn_Click(object sender, RoutedEventArgs e)
        {
            mw_mg_target_textbox.Text = mw_mg_target_textbox.Text.Trim();
            mw_mg_original_textbox.Text = mw_mg_original_textbox.Text.Trim();
            compareEachFiles();
        }

        private void Mw_mg_target_textblock_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop)) e.Effects = DragDropEffects.Copy;
        }

        private void Mw_mg_target_textblock_Drop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            setDropedPaths(files, mw_mg_target_textbox);
            mw_mg_target_textbox.Text = mw_mg_target_textbox.Text.Trim();
        }

        private void Mw_mg_original_textblock_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop)) e.Effects = DragDropEffects.Copy;
        }

        private void Mw_mg_original_textblock_Drop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            mw_mg_original_textbox.Text = "";
            setDropedPaths(files, mw_mg_original_textbox);
            mw_mg_original_textbox.Text = mw_mg_original_textbox.Text.Trim();
        }
    }
}
