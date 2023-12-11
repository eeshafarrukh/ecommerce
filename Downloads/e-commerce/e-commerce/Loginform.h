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
	/// Summary for MyForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ emailtb;
	private: System::Windows::Forms::TextBox^ passtb;
	private: System::Windows::Forms::Button^ loginb;
	private: System::Windows::Forms::Button^ cancelb;
	private: System::Windows::Forms::Label^ logolb;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->emailtb = (gcnew System::Windows::Forms::TextBox());
			this->passtb = (gcnew System::Windows::Forms::TextBox());
			this->loginb = (gcnew System::Windows::Forms::Button());
			this->cancelb = (gcnew System::Windows::Forms::Button());
			this->logolb = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(548, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 61);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			this->label1->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(182, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 37);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(146, 249);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(158, 37);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// emailtb
			// 
			this->emailtb->Location = System::Drawing::Point(323, 160);
			this->emailtb->Name = L"emailtb";
			this->emailtb->Size = System::Drawing::Size(588, 44);
			this->emailtb->TabIndex = 3;
			this->emailtb->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox1_TextChanged);
			// 
			// passtb
			// 
			this->passtb->Location = System::Drawing::Point(323, 246);
			this->passtb->Name = L"passtb";
			this->passtb->PasswordChar = '*';
			this->passtb->Size = System::Drawing::Size(588, 44);
			this->passtb->TabIndex = 4;
			// 
			// loginb
			// 
			this->loginb->Location = System::Drawing::Point(464, 350);
			this->loginb->Name = L"loginb";
			this->loginb->Size = System::Drawing::Size(151, 51);
			this->loginb->TabIndex = 5;
			this->loginb->Text = L"Login";
			this->loginb->UseVisualStyleBackColor = true;
			this->loginb->Click += gcnew System::EventHandler(this, &LoginForm::loginb_Click);
			// 
			// cancelb
			// 
			this->cancelb->Location = System::Drawing::Point(651, 350);
			this->cancelb->Name = L"cancelb";
			this->cancelb->Size = System::Drawing::Size(151, 51);
			this->cancelb->TabIndex = 6;
			this->cancelb->Text = L"Cancel";
			this->cancelb->UseVisualStyleBackColor = true;
			this->cancelb->Click += gcnew System::EventHandler(this, &LoginForm::cancelb_Click);
			// 
			// logolb
			// 
			this->logolb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logolb->Location = System::Drawing::Point(529, 32);
			this->logolb->Name = L"logolb";
			this->logolb->Size = System::Drawing::Size(224, 26);
			this->logolb->TabIndex = 7;
			this->logolb->Text = L" S&&J BOUTIQUE";
			this->logolb->Click += gcnew System::EventHandler(this, &LoginForm::label4_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(19, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(1216, 424);
			this->Controls->Add(this->logolb);
			this->Controls->Add(this->cancelb);
			this->Controls->Add(this->loginb);
			this->Controls->Add(this->passtb);
			this->Controls->Add(this->emailtb);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"LoginForm";
			this->Text = L"Loginform";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			Customer^ user = nullptr;
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cancelb_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
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

			String^ sqlQuery = "SELECT * FROM users WHERE email=@email AND password=@pwd;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@pwd", password);
			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				user = gcnew Customer;
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
	};
}
