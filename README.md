# Ulyaoth Chat (perl)

A very poor installation guide:

This assumes a Fedora 35 installation for example on digitalOcean.<br />
Get 100$ credit on DigitalOcean: https://m.do.co/c/f47e4bda6385

Please use the below instructions on your own risk, this script is very old and probably many security issues ...<br />
It took me a while to get it to work on a more newer linux, feel free to update this if you can find out a better and easier way.

## Installation (non functional bash script)
```bash
#install webserver:
dnf install perl perl-CGI cmake libxslt-devel git sendmail
wget https://www.hiawatha-webserver.org/files/hiawatha-11.0.tar.gz
tar xvzf hiawatha-11.0.tar.gz
cd hiawatha-11.0
mkdir build
cmake ..
make
make install/strip
cd /root
rm -rf hiawatha*


#install chat:
git clone https://github.com/ulyaoth/ulyaoth-chat-perl.git
mkdir -p /opt/ulyaoth/
mv /root/ulyaoth-chat-perl/chat /opt/ulyaoth/
mkdir -p /srv/ulyaoth/chat/public
mv /root/ulyaoth-chat-perl/cgi-bin /srv/ulyaoth/chat/public/


#copy webserver config:
mv /root/ulyaoth-chat-perl/hiawatha/hiawatha.conf /usr/local/etc/hiawatha/hiawatha.conf

#clean
rm -rf /root/ulyaoth-chat-perl

#create required directories:
mkdir -p /opt/ulyaoth/chat/abuse/reports
mkdir -p /opt/ulyaoth/chat/app
mkdir -p /opt/ulyaoth/chat/appchange
mkdir -p /opt/ulyaoth/chat/apprenew
mkdir -p /opt/ulyaoth/chat/boards
mkdir -p /opt/ulyaoth/chat/clearlog
mkdir -p /opt/ulyaoth/chat/cp
mkdir -p /opt/ulyaoth/chat/deopped
mkdir -p /opt/ulyaoth/chat/mail/igmail
mkdir -p /opt/ulyaoth/chat/online/action
mkdir -p /opt/ulyaoth/chat/online/banned
mkdir -p /opt/ulyaoth/chat/online/ig
mkdir -p /opt/ulyaoth/chat/online/kicked
mkdir -p /opt/ulyaoth/chat/online/lastnick
mkdir -p /opt/ulyaoth/chat/online/lastpm
mkdir -p /opt/ulyaoth/chat/online/locked
mkdir -p /opt/ulyaoth/chat/online/noproxy
mkdir -p /opt/ulyaoth/chat/online/pm
mkdir -p /opt/ulyaoth/chat/online/rooms
mkdir -p /opt/ulyaoth/chat/online/users
mkdir -p /opt/ulyaoth/chat/ops/ops
mkdir -p /opt/ulyaoth/chat/opspreferences
mkdir -p /opt/ulyaoth/chat/signup/renewal
mkdir -p /opt/ulyaoth/chat/suspend
mkdir -p /opt/ulyaoth/chat/time
mkdir -p /opt/ulyaoth/chat/trial
mkdir -p /opt/ulyaoth/chat/vote
mkdir -p /opt/ulyaoth/chat/wait
mkdir -p /srv/ulyaoth/chat/public/banlogs
mkdir -p /srv/ulyaoth/chat/public/upload

#fix permissions
setsebool -P httpd_enable_cgi 1

chcon -R -t httpd_sys_content_t /srv/ulyaoth/chat/public
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/chat/public/banlogs
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/chat/public/upload
chcon -R -t httpd_sys_rw_content_t /opt/ulyaoth/chat

find /srv/ulyaoth/chat -type f \( -name "*.cgi" \) -exec chmod 755 {} \;
find /opt/ulyaoth/chat -type f \( -name "*.cgi" \) -exec chmod 755 {} \;
find /opt/ulyaoth/chat -type f \( -name "*.inc" \) -exec chmod 644 {} \;
find /opt/ulyaoth/chat -type d -exec chmod 777 {} \;
```

please make sure you edit the domain "chat.ulyaoth.com" within the Hiawatha config file to your domain.<br />
config location: /usr/local/etc/hiawatha/hiawatha.conf<br />

Test if config works:<br />
Hiawatha -k<br />

Start webserver:<br />
/usr/local/sbin/hiawatha<br />

Stop webserver:<br />
cat /usr/local/var/run/hiawatha.pid<br />
kill -15 (number that command gives above)<br />

You also have to update the below file and name the chat to your liking:<br />
/opt/ulyaoth/chat/inc/variables.inc<br />

Change:<br />
```perl
$entrytitle = "Ulyaoth Chat - please login";  
$title = "chat.ulyaoth.com";
$webmaster = "webmaster\@ulyaoth.com";
$version = ".:: Ulyaoth chat server 1.0 ::.";  
```

Your chat should now run at:<br />
http://"your domain"/cgi-bin/c/bin.cgi<br />

Admin Login:<br />
username: admin<br />
password: admin1234<br />