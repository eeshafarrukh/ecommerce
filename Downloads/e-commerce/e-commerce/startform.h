#pragma once
#include "Loginform.h"
#include "stafflogin.h"
extern bool usertype;
namespace sdaproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for startform
	/// </summary>
	public ref class startform : public System::Windows::Forms::Form
	{
	public:
		startform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~startform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(361, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(385, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"S&&J BOUTIQUE";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(370, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(316, 70);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Employee";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &startform::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(370, 296);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(316, 70);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Customer";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &startform::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(844, 428);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(213, 56);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &startform::button3_Click);
			// 
			// startform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(1085, 496);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"startform";
			this->Text = L" ";
			this->Load += gcnew System::EventHandler(this, &startform::startform_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void startform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		sdaproject::LoginForm loginForm;
		loginForm.ShowDialog();
		Customer^ user = loginForm.user;
		if (user != nullptr)
		{
			usertype = 1;

			MessageBox::Show("Successfull Authentication of user: " + user->name, "main.cpp", MessageBoxButtons::OK);
			this->Close();
			
		}
		else {
			MessageBox::Show("Authentication cancelled", "main.cpp", MessageBoxButtons::OK);

		}
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		sdaproject::stafflogin loginForm;
		loginForm.ShowDialog();
		Staff^ user = loginForm.user;
		if (user != nullptr)
		{
			usertype = 0;
			MessageBox::Show("Successfull Authentication of staff: " + user->name, "main.cpp", MessageBoxButtons::OK);
			this->Close();
		}
		else {
			MessageBox::Show("Authentication cancelled", "main.cpp", MessageBoxButtons::OK);

		}
		
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
