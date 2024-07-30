import smtplib
import sys
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

def send_email(to_address, subject, body):
    gmail_user = 'rashs81199@gmail.com'
    gmail_password = 'Rasha123&'
    
    # Create a multipart message and set headers
    message = MIMEMultipart()
    message['From'] = gmail_user
    message['To'] = to_address
    message['Subject'] = subject
    
    # Add body to email
    message.attach(MIMEText(body, 'plain'))
    
    try:
        # Set up the SMTP server
        smtp_server = 'smtp.gmail.com'
        smtp_port = 587  # TLS port (SSL is deprecated)
        
        # Create SMTP session for sending the mail
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()  # Secure the connection
        server.login(gmail_user, gmail_password)  # Login with credentials
        
        # Send email
        server.sendmail(gmail_user, to_address, message.as_string())
        print('Email sent successfully!')
    except Exception as e:
        print(f'SMTP error occurred: {e}')
    finally:
        server.quit()  # Terminate the SMTP session

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print('Usage: python send_email.py <to_email> <subject> <body>')
        sys.exit(1)
    
    to_email = sys.argv[1]
    subject = sys.argv[2]
    body = sys.argv[3]
    
    send_email(to_email, subject, body)
