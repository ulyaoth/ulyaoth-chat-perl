#!/usr/bin/perl

use CGI;
use Fcntl;
use DB_File;

$loc = "nchange.cgi";

$title = "Ulyaoth Chat;

$sendmail = "/usr/lib/sendmail";

$root = '/opt/ulyaoth/chat';


&data();

if(!$form_info){

require "$root/signup/nickchangefirst.inc";

exit;

}

if($DATA{'bypass'}){

print "Content-type: text/html\n\n";

require "$root/signup/nickchangeform.inc";

exit;

}


if(!$DATA{'nick'} or !$DATA{'nick2'} or !$DATA{'password'}){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, you left one or more fields blank.</i><p>";

require "$root/signup/nickchangeform.inc";

exit;

}

if(!-e "$root/ops/ops/$DATA{'nick'}.db"){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, nickname <b>$DATA{'nick'}</b> does not exist in our database.</i><p>";

require "$root/signup/nickchangeform.inc";

exit;

}


##### IN USE



opendir(RD, "$root/ops/ops/");

@files = readdir (RD);

      closedir(RD);

    foreach $entry (sort @files) {


        if ($entry ne '.' && $entry ne '..') {

                $entry =~ s/.db//;

               
if ($DATA{'nick2'} =~ /$entry/i && length($DATA{'nick2'}) == length($entry)){

$error = "<p> <b>Error, nickname <tt>$DATA{'nick2'}</tt> is already in use by another Operator.</b><p>";

print "Content-type: text/html\n\n";

require "$root/signup/nickchangeform.inc";

exit;

} 

}
}


@bad = ("fuhck","fhuk","f`?.?u`?.?c`?.?k","b`?.?i`?.?t`?.?c`?.?h","c`?.?u`?.?n`?.?t","penis","pussy","asshole","dick","cock","moron","skank","s`?.?l`?.?u`?.?t","shit","alamak","aavaria");


foreach $e(@bad){

if($DATA{'nick2'} =~ /$e/i){

$error = "<p> Invalid nickname.</b><p>";

print "Content-type: text/html\n\n";

require "$root/signup/nickchangeform.inc";

exit;
      }
}

################################


dbmopen(%USER,"$root/ops/ops/$DATA{'nick'}",0777);

$pass = crypt($DATA{'password'}, "Cd");

if($USER{'password'} ne $pass){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, incorrect password.</i><p>";

require "$root/signup/nickchangeform.inc";

dbmclose(%USER);

exit;
}

for (0..11) { $ref .= pack("C",48+int(rand(9.999))); }

    open(MAIL,"|$sendmail -t");

    print MAIL "To: $USER{'email'}\n";
    print MAIL "From: webmaster\@$title (Chat Admin)\n";
    print MAIL "Subject: $title membership!\n";
    print MAIL "This is a notice that your new nickname change application has been received.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $DATA{'nick'}\n";
    print MAIL "New Nick: $DATA{'nick2'}\n";
    print MAIL "Email: $DATA{'email'}\n";
    print MAIL "Activation Code: $ref\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Chat Admin\n http:\/\/$title\n";
    close(MAIL);


dbmclose(%USER);


dbmopen(%A,"$root/appchange/$ref",0777);

$A{'new_nick'} = $DATA{'nick2'};

$A{'old_nick'} = $DATA{'nick'};


dbmclose(%A);


print "Content-type: text/html\n\n";

print "<HEAD><title>$title Chat Ops Application!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title chat / Nickname Change'\">\n";

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