//example for email
#include "clsSMTPClient.h"

int main(){
    SMTPClient Email;
    printf("sending...\n");
    Email.SetServer("smtp.gmail.com", "587");
    Email.SetAccount("myemail@gmail.com", "myPassword");
    Email.SetContentType("text/html");

    Email.initEmail("mojtaba.kahvand@gmail.com", "SMTPLibrary", "Hi", "hi from <b>SMTPLibrary</b>");
    Email.Add_BCCEmailAddress("mojtaba.kahvand@gmail.com");     //must adding after initEmail()

    printf("    %s\n\n", Email.Send() ? "failed": "successfully send");
}
