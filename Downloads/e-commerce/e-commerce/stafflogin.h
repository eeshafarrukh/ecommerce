#pragma once
#include "sj.h"
namespace sdaproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for stafflogin
	/// </summary>
	public ref class stafflogin : public System::Windows::Forms::Form
	{
	public:
		stafflogin(void)
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
		~stafflogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ logolb;
	protected:
	private: System::Windows::Forms::Button^ cancelb;
	private: System::Windows::Forms::Button^ loginb;
	private: System::Windows::Forms::TextBox^ passtb;
	private: System::Windows::Forms::TextBox^ emailtb;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->logolb = (gcnew System::Windows::Forms::Label());
			this->cancelb = (gcnew System::Windows::Forms::Button());
			this->loginb = (gcnew System::Windows::Forms::Button());
			this->passtb = (gcnew System::Windows::Forms::TextBox());
			this->emailtb = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->SuspendLayout();
			// 
			// logolb
			// 
			this->logolb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logolb->Location = System::Drawing::Point(480, 41);
			this->logolb->Name = L"logolb";
			this->logolb->Size = System::Drawing::Size(224, 26);
			this->logolb->TabIndex = 15;
			this->logolb->Text = L" S&&J BOUTIQUE";
			// 
			// cancelb
			// 
			this->cancelb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelb->Location = System::Drawing::Point(605, 350);
			this->cancelb->Name = L"cancelb";
			this->cancelb->Size = System::Drawing::Size(201, 60);
			this->cancelb->TabIndex = 14;
			this->cancelb->Text = L"Cancel";
			this->cancelb->UseVisualStyleBackColor = true;
			this->cancelb->Click += gcnew System::EventHandler(this, &stafflogin::cancelb_Click);
			// 
			// loginb
			// 
			this->loginb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginb->Location = System::Drawing::Point(375, 350);
			this->loginb->Name = L"loginb";
			this->loginb->Size = System::Drawing::Size(201, 60);
			this->loginb->TabIndex = 13;
			this->loginb->Text = L"Login";
			this->loginb->UseVisualStyleBackColor = true;
			this->loginb->Click += gcnew System::EventHandler(this, &stafflogin::loginb_Click);
			// 
			// passtb
			// 
			this->passtb->Location = System::Drawing::Point(284, 255);
			this->passtb->Name = L"passtb";
			this->passtb->PasswordChar = '*';
			this->passtb->Size = System::Drawing::Size(588, 26);
			this->passtb->TabIndex = 12;
			// 
			// emailtb
			// 
			this->emailtb->Location = System::Drawing::Point(284, 169);
			this->emailtb->Name = L"emailtb";
			this->emailtb->Size = System::Drawing::Size(588, 26);
			this->emailtb->TabIndex = 11;
			this->emailtb->TextChanged += gcnew System::EventHandler(this, &stafflogin::emailtb_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(107, 255);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 37);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(154, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 37);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Email";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(396, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(476, 61);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Employee Login";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// stafflogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1087, 441);
			this->Controls->Add(this->logolb);
			this->Controls->Add(this->cancelb);
			this->Controls->Add(this->loginb);
			this->Controls->Add(this->passtb);
			this->Controls->Add(this->emailtb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"stafflogin";
			this->Text = L"stafflogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			Staff^ user = nullptr;
	private: System::Void emailtb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void loginb_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = this->emailtb->Text;
	String^ password = this->passtb->Text;
	if (email->Length == 0 || password->Length == 0) {
		MessageBox::Show("Please enter email and password",
			"Email or Password Empty", MessageBoxButtons::OK);
		return;
	}
	try {
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\hp\\OneDrive\\Documents\\loginInfo.mdf;Integrated Security=True;Connect Timeout=30";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "SELECT * FROM employee WHERE email=@email AND password=@pwd;";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@email", email);
		command.Parameters->AddWithValue("@pwd", password);
		SqlDataReader^ reader = command.ExecuteReader();
		if (reader->Read()) {
			user = gcnew Staff;
			user->id = reader->GetInt32(0);
			user->name = reader->GetString(1);
			user->email = reader->GetString(2);
			user->phone = reader->GetString(3);
			user->address = reader->GetString(4);
			user->password = reader->GetString(5);

			this->Close();
		}
		else {
			MessageBox::Show("Email or password is incorrect",
				"Email or Password Error", MessageBoxButtons::OK);
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to database",
			"Database Connection Error", MessageBoxButtons::OK);
	}
}
private: System::Void cancelb_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
