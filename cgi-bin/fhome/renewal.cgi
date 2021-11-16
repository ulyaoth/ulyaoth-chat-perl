#!/usr/bin/perl

use CGI;
use Fcntl;
use DB_File;


$loc = "renewal.cgi";

$title = "Ulyaoth Chat";

$sendmail = "/usr/lib/sendmail";

$root = '/srv/ulyaoth/chat';


&data();

if(!$form_info){

require "$root/signup/renewfirst.inc";

exit;

}

if($DATA{'bypass'}){

print "Content-type: text/html\n\n";

require "$root/signup/renewform.inc";

exit;

}


if(!$DATA{'nick'} or !$DATA{'password'}){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, you left one or more fields blank.</i><p>";

require "$root/signup/renewform.inc";

exit;

}

if(!-e "$root/ops/ops/$DATA{'nick'}.db"){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, nickname <b>$DATA{'nick'}</b> does not exist in our database.</i><p>";

require "$root/signup/renewform.inc";

exit;

}


dbmopen(%USER,"$root/ops/ops/$DATA{'nick'}",0777);

$pass = crypt($DATA{'password'}, "Cd");


if($USER{'password'} ne $pass){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, incorrect password.</i><p>";

require "$root/signup/renewform.inc";

dbmclose(%USER);

exit;
}

for (0..11) { $ref .= pack("C",48+int(rand(9.999))); }


#open (MAIL,"|$sendmail -t") || print "Can't start mail program";
#print MAIL "To: nicks\@$title (Admin)\n";
#print MAIL "From: webmaster\@$title (Admin)\n";
#print MAIL "Subject: renewal account Received!\n\n";
#print MAIL "This is a notice that your new membership renewal application has been received.\n\n";
#print MAIL "Nick: $DATA{'nick'}\n";
#print MAIL "Email: $DATA{'email'}\n";
#print MAIL "Length: $DATA{'length'}\n";
#print MAIL "Activation Code: $ref\n";
#print MAIl "Length: $DATA{'length'} month(s)\n";
#print MAIL "Sincerely!\n";
#print MAIL "Admin\n http:\/\/w$title\n";
#close (MAIL);

 
    open(MAIL,"|$sendmail -t");

    print MAIL "To: $USER{'email'}\n";
    print MAIL "From: webmaster\@$title (admin)\n";
    print MAIL "Subject: Ulyaoth Chat Membership!\n";
    print MAIL "This is a notice that your new membership renewal application has been received.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $DATA{'nick'}\n";
    print MAIL "Email: $DATA{'email'}\n";
    print MAIL "Activation Code: $ref\n";
    print MAIl "Length: $DATA{'length'} month(s)\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Admin\n http:\/\/$title\n";
    close(MAIL);

dbmclose(%USER);

dbmopen(%A,"$root/apprenew/$ref",0777);

$A{'renew_length'} = $DATA{'length'};

$A{'nickname'} = $DATA{'nick'};

dbmclose(%A);


if($DATA{'length'} == 1){

$money = "1 month. Free Trial Ops account.";

}elsif($DATA{'length'} == 3){

$money = "3 months. 15 US Dollars.";

}elsif($DATA{'length'} == 6){

$money = "6 months. 30 US Dollars.";

}elsif($DATA{'length'} == 9){

$money = "9 months. 45 US Dollars.";

}elsif($DATA{'length'} == 12){

$money = "12 months. 55 US Dollars.";

}elsif($DATA{'length'} == 24){

$money = "24 months. 100 US Dollars.";

}

#


print "Content-type: text/html\n\n";

print "<HEAD><title>$title Chat Ops Application!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title chat / RENEWAL'\">\n";

print "<b><center>$title Chat / Renewal</b><p>\n";

print "<b>THANK YOU!</b><p>\n";


print "Your application code is: <font color=\"red\"><b>$ref</b></font>.<br>\nTOTAL: $money\n<br>Please click <a href=\"https:\/\/chat.ulyaoth.com\/staff.html\">HERE</a> to find office closest to you and send us payment.</center>\n";



print "</body></html>\n";


exit;



sub data {

$request_method = $ENV{'REQUEST_METHOD'};
if ($request_method eq "GET") {
        $form_info = $ENV{'QUERY_STRING'};
} else {
        $size_of_form_information = $ENV{'CONTENT_LENGTH'};
        read (STDIN, $form_info, $size_of_form_information);

}
@key_value_pairs = split (/&/, $form_info);
foreach $key_value (@key_value_pairs) {
        ($key, $value) = split (/=/, $key_value);
        $value =~ tr/+/ /;
        $value =~ s/%([\dA-Fa-f][\dA-Fa-f])/pack ("C", hex ($1))/eg;
        if (defined($DATA{$key})) {
                $DATA{$key} = join (", ", $DATA{$key}, $value);
        } else {
                $DATA{$key} = $value;
        }
}
}