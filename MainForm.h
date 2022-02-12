#pragma once

namespace LyreConverter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ convertButton;
	protected:

	private: System::Windows::Forms::TextBox^ notesTextBox;


	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->convertButton = (gcnew System::Windows::Forms::Button());
			this->notesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// convertButton
			// 
			this->convertButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->convertButton->Location = System::Drawing::Point(397, 226);
			this->convertButton->Name = L"convertButton";
			this->convertButton->Size = System::Drawing::Size(75, 23);
			this->convertButton->TabIndex = 0;
			this->convertButton->Text = L"Convert";
			this->convertButton->UseVisualStyleBackColor = true;
			this->convertButton->Click += gcnew System::EventHandler(this, &MainForm::convertButton_Click);
			// 
			// notesTextBox
			// 
			this->notesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->notesTextBox->Location = System::Drawing::Point(12, 12);
			this->notesTextBox->Multiline = true;
			this->notesTextBox->Name = L"notesTextBox";
			this->notesTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->notesTextBox->Size = System::Drawing::Size(460, 208);
			this->notesTextBox->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->notesTextBox);
			this->Controls->Add(this->convertButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(300, 200);
			this->Name = L"MainForm";
			this->Text = L"Lyre Converter";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void convertButton_Click(System::Object^ sender, System::EventArgs^ e) {
		array<wchar_t>^ strArray = notesTextBox->Text->ToUpper()->ToCharArray();

		for (int i = 0; i < strArray->Length; i++)
		{
			switch (strArray[i])
			{
			case 'A':
				strArray[i] = wchar_t('Q');
				break;
			case 'Q':
				strArray[i] = wchar_t('A');
				break;
			case 'Z':
				strArray[i] = wchar_t('W');
				break;
			case 'W':
				strArray[i] = wchar_t('Z');
				break;
			case 'M':
				strArray[i] = wchar_t('?');
				break;
			case '?':
				strArray[i] = wchar_t('M');
				break;
			default:
				break;
			}
		}
		String ^convertedText = gcnew String(strArray);
		notesTextBox->Text = convertedText;
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
