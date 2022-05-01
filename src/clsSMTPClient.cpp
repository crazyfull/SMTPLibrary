#include "clsSMTPClient.h"
#include <Wrench/log.h>
#include "smtp.h"

SMTPClient::SMTPClient()
{
    m_pSMTP = NULL;
}

void SMTPClient::SetServer(const char *mailServer, const char *mailServerPort)
{
    m_mailServer = mailServer;
    m_mailServerPort = mailServerPort;
}

void SMTPClient::SetAccount(const char *UserName, const char *Password)
{
    m_UserName = UserName;
    m_Password = Password;
}

void SMTPClient::SetContentType(const char *ContentType)
{
    m_ContentType = ContentType;

}

void SMTPClient::SetReplayTo(const char *EmailAddress)
{
    m_ReplayTo = EmailAddress;
}

void SMTPClient::Add_BCCEmailAddress(const char *EmailAddress)
{
    smtp_address_add(m_pSMTP, SMTP_ADDRESS_BCC, EmailAddress, NULL);
}

void SMTPClient::Add_Header(const char *Key, const char *Value)
{
    smtp_header_add(m_pSMTP, Key, Value);
}

void SMTPClient::initEmail(const char *To, const char *FromName, const char *Subject, const char *Message)
{
    smtp_open(m_mailServer.c_str(), m_mailServerPort.c_str(), SMTP_SECURITY_STARTTLS, (smtp_flag)0, NULL, &m_pSMTP);
    smtp_auth(m_pSMTP, SMTP_AUTH_PLAIN, m_UserName.c_str(), m_Password.c_str());
    smtp_header_add(m_pSMTP, "Content-Type", m_ContentType.c_str());
    smtp_header_add(m_pSMTP, "Reply-To", m_ReplayTo.c_str());
    smtp_header_add(m_pSMTP, "Subject", Subject);
    smtp_address_add(m_pSMTP, SMTP_ADDRESS_FROM, m_UserName.c_str(), FromName);
    smtp_address_add(m_pSMTP, SMTP_ADDRESS_TO, To, NULL);
    m_Message = Message;
}

int SMTPClient::Send()
{
    smtp_status_code ret = smtp_mail(m_pSMTP, m_Message.c_str());
    //LOG("smtp_mail: %d", ret);

    smtp_close(m_pSMTP);

    return ret;
}


