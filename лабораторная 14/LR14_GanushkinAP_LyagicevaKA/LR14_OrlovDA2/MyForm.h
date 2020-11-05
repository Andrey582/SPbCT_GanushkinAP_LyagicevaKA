#pragma once
#include <ctime>
#include <iostream>
#include <fstream>
#include "Visualisation.h"
using namespace std;
ifstream fin2;

namespace LR14OrlovDA2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int getN()
		{
			int n;
			int counter = 0;
			char* buffer3 = new char[8];

			fin2.open("forTable.txt");
			fin2.seekg(5, ios_base::beg);
			while (!fin2.eof())
			{
				fin2.getline(buffer3, 8, '\n');
				counter++;
			}
			n = counter;
			fin2.close();
			delete[] buffer3;
			return n - 1;
		};
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->X, this->Y });
			this->dataGridView1->Location = System::Drawing::Point(9, 27);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(107, 122);
			this->dataGridView1->TabIndex = 0;
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->MinimumWidth = 6;
			this->X->Name = L"X";
			this->X->Width = 50;
			// 
			// Y
			// 
			this->Y->HeaderText = L"Y";
			this->Y->MinimumWidth = 6;
			this->Y->Name = L"Y";
			this->Y->Width = 50;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Таблица";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 154);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Кол-во пар:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 171);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(108, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 195);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Заполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 222);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 37);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Заполнить из файла fortabel.txt";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(148, 11);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(230, 248);
			this->chart1->TabIndex = 8;
			this->chart1->Text = L"chart1";
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(407, 11);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"X";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->Name = L"Y";
			this->chart2->Series->Add(series2);
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(274, 248);
			this->chart2->TabIndex = 9;
			this->chart2->Text = L"chart2";
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(705, 11);
			this->chart3->Name = L"chart3";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"X";
			series5->ChartArea = L"ChartArea1";
			series5->Legend = L"Legend1";
			series5->Name = L"Y";
			this->chart3->Series->Add(series4);
			this->chart3->Series->Add(series5);
			this->chart3->Size = System::Drawing::Size(276, 250);
			this->chart3->TabIndex = 10;
			this->chart3->Text = L"chart3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1007, 273);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			srand(time(NULL));
			int n;

			n = Convert::ToInt32(textBox1->Text);

			int** tab = new int* [n];
			for (int i = 0; i < n; i++)
				tab[i] = new int[n];
			Visualisation t1(tab, n, 2);
			tab[n - 1][2] = t1.fillTable(&tab[0]);
			dataGridView1->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 2; j++) {
					dataGridView1->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
				}
			t1.putIntoFile(tab);
			/////////////////////////
			chart1->Series["Series1"]->Points->Clear();
			int sumX = 0, sumY = 0;
			for (int i = 0; i < n; i++) {
				sumX += tab[i][0];
				sumY += tab[i][1];
			}
			chart1->Series["Series1"]->Points->AddXY("X", sumX);
			chart1->Series["Series1"]->Points->AddXY("Y", sumY);
			/////////////////////////
			chart2->Series["X"]->Points->Clear();
			chart2->Series["Y"]->Points->Clear();
			for (int i = 0; i < n; i++) {
				chart2->Series["X"]->Points->AddXY(i, tab[i][0]);
				chart2->Series["Y"]->Points->AddXY(i, tab[i][1]);
			}
			/////////////////////////
			chart3->Series["X"]->Points->Clear();
			chart3->Series["Y"]->Points->Clear();
			for (int i = 0; i < n; i++) {
				chart3->Series["X"]->Points->AddXY(i, tab[i][0]);
				chart3->Series["Y"]->Points->AddXY(i, tab[i][1]);
			}
		}
		catch (System::FormatException^ ex) {
			MessageBox::Show("Заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		int n = getN();
		int** tab = new int* [n];
		Visualisation t1(tab, n, 2);
		dataGridView1->RowCount = n;
		t1.outOfFile(tab);
		for(int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
			}
		/////////////////////////
		chart1->Series["Series1"]->Points->Clear();
		int sumX = 0, sumY = 0;
		for (int i = 0; i < n; i++) {
			sumX += tab[i][0];
			sumY += tab[i][1];
		}
		chart1->Series["Series1"]->Points->AddXY("X", sumX);
		chart1->Series["Series1"]->Points->AddXY("Y", sumY);
		/////////////////////////
		chart2->Series["X"]->Points->Clear();
		chart2->Series["Y"]->Points->Clear();
		for (int i = 0; i < n; i++) {
			chart2->Series["X"]->Points->AddXY(i, tab[i][0]);
			chart2->Series["Y"]->Points->AddXY(i, tab[i][1]);
		}
		/////////////////////////
		chart3->Series["X"]->Points->Clear();
		chart3->Series["Y"]->Points->Clear();
		for (int i = 0; i < n; i++) {
			chart3->Series["X"]->Points->AddXY(i, tab[i][0]);
			chart3->Series["Y"]->Points->AddXY(i, tab[i][1]);
		}
	}
	catch (System::FormatException^ ex) {
		MessageBox::Show("Заполните все поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
};
}
