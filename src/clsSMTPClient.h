#ifndef EMAILSENDER_H
#define EMAILSENDER_H
#include <stdio.h>
#include <string.h>
#include <string>

/*
 * Sending limits: 2,000 messages per day.
 * smtp.gmail.com
 * Port 465 (SSL required)
 * Port 587 (TLS required)
 * Dynamic IPs allowed
 * Authentication requirements: Your full Gmail or Google Workspace email address
 *
 */

using namespace std;
class SMTPClient
{
private:
    struct smtp *m_pSMTP;
    string m_mailServer;
    string m_mailServerPort;
    string m_UserName;
    string m_Password;
    string m_Subject;
    string m_ContentType;
    string m_ReplayTo;
    string m_Message;

public:
    SMTPClient();

    void SetServer(const char* mailServer, const char* mailServerPort);
    void SetAccount(const char* UserName, const char* Password);
    void SetContentType(const char* ContentType);
    void SetReplayTo(const char* EmailAddress);
    void Add_BCCEmailAddress(const char* EmailAddress);
    void Add_Header(const char* Key, const char* Value);

    void initEmail(const char* To, const char* FromName, const char* Subject, const char* Message);
    int Send();
};

#endif // EMAILSENDER_H
