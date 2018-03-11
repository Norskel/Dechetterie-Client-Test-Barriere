#include "MyForm.h"
#include "Client.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;


[STAThread]
void Main(array<String^>^ args)
{


	Client^ cl = gcnew Client();



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm form(cl);
	Application::Run(%form);
}
