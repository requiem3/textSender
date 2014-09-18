//ATT txt.att.net
//Verizon vtext.com

#include "stdafx.h"
#include <iostream>
#using <System.dll>

using namespace std;
using namespace System::Net::Mail;
using namespace System::Threading;

public ref class ThreadWork
{
public:
   static void sendMessage()
   {
		SmtpClient^ client = gcnew SmtpClient( "smtp.gmail.com", 587 ); //Server, Port for gmail
		MailMessage^ message = gcnew MailMessage("sending_email", "receiving_number@gateway"); //From, To

		message->Subject = "subject";
		message->Body = "Body";

		client->UseDefaultCredentials = true;
		client->UseDefaultCredentials = false;
		client->EnableSsl = true;
		client->Credentials = gcnew System::Net::NetworkCredential("your_email@gmail.com", "your_pass"); //Email, Pass

		client->Send(message);
   }

};

int main()
{ 
	Thread^ t1 = gcnew Thread( gcnew ThreadStart(&ThreadWork::sendMessage));

	t1->Start();


	return 0;

}

