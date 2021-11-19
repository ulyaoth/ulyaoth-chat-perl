#!/usr/bin/perl

use CGI;
use Fcntl;
use DB_File;

$loc = "ops.cgi";

$sendmail = "/usr/lib/sendmail";

$title = "ulyaoth.com";

$root = '/opt/ulyaoth/chat/signup';

$root2 = '/opt/ulyaoth/chat';



&data();

if(!$form_info){

require "$root/first.inc";

exit;

}

if($DATA{'bypass'}){

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;

}


if(!$DATA{'opsnickname'} or !$DATA{'password'} or !$DATA{'2password'} or !$DATA{'email'} or !$DATA{'nameofowner'}){

print "Content-type: text/html\n\n";

$error = "<p><i> Error, you have left one or more fields blank.</i><p>";

require "$root/form.inc";

exit;

}

if($DATA{'opsnickname'} =~ /[\W]/ or length($DATA{'opsnickname'}) > 14){

$error = "<p><i> Error, nickname must ONLY contain alphanumercial characters and nickname length must be less than 14 characters.</i><p>";

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;

}

if($DATA{'password'} =~ /[\W]/ or length($DATA{'password'}) > 14){

$error = "<p><i> Error, password must ONLY contain alphanumercial characters and password length must be less than 14 characters.</i><p>";

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;

}




if($DATA{'password'} ne $DATA{'2password'}){

$error = "<p><i> Error, passwords you entered do not match.</i><p>";

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;

}


###### check if nickname is in use

opendir(RD, "$root2/ops/ops/");

@files = readdir (RD);

      closedir(RD);

    foreach $entry (sort @files) {


        if ($entry ne '.' && $entry ne '..') {

                $entry =~ s/.db//;

               
if ($DATA{'opsnickname'} =~ /$entry/i && length($DATA{'opsnickname'}) == length($entry)){

$error = "<p> <b>Error, nickname <tt>$DATA{'opsnickname'}</tt> is already in use by another Operator.</b><p>";

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;

} 

}
}


@bad = ("fuhck","fhuk","f`?.?u`?.?c`?.?k","b`?.?i`?.?t`?.?c`?.?h","c`?.?u`?.?n`?.?t","penis","pussy","asshole","dick","cock","moron","skank","s`?.?l`?.?u`?.?t","shit","aavaria");


foreach $e(@bad){

if($DATA{'opsnickname'} =~ /$e/i){

$error = "<p> Invalid nickname.</b><p>";

print "Content-type: text/html\n\n";

require "$root/form.inc";

exit;
      }
}


###################################



# make Ops account


#get time

($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  

if ($sec < 10) { $sec = "0$sec"; }  

if ($min < 10) { $min = "0$min"; }  

if ($hour < 10) { $hour = "0$hour"; }  

if ($day < 10) { $day = "0$day"; }  

$year += "1900";  $weekday = $days[$day2];              

$emonth = $month + 1; 

$cmonth = $emonth + $DATA{'length'};

$start = "$day\/$emonth\/$year";    



if($cmonth > 24){

$cmonth = $cmonth - 24;

$year = $year + 2;

}


if($cmonth > 12){

$cmonth = $cmonth - 12;

$year = $year + 1;

}

$end = "$day\/$cmonth\/$year";    


$password = crypt($DATA{'password'}, "Cd");

for (0..2) { $id .= pack("C",97+int(rand(25.9999))); }


for (0..11) { $ref .= pack("C",48+int(rand(9.999))); }



open(LAST,"$root/id.txt");

$ind = <LAST>;

close(LAST);

@i = split(/\|\"\'\|/, $ind);

$id = "v@i[1]$id";

$z = @i[1] + 1;

open(LASTNICK,">$root/id.txt");

print LASTNICK "yes\|\"\'\|$z";

close(LASTNICK);


dbmopen(%O,"/opt/ulyaoth/chat/app/$ref.db",0777);

$O{'application'} = $DATA{'opsnickname'};

$O{'level'} = 1;

$O{'id'} = $id;

$O{'ops_began'} = $start;

$O{'ops_months'} = $DATA{'length'};

$O{'ops_end'} = $end;

$O{'password'} = $password;

$O{'realpassword'} = $DATA{'password'};

$O{'name'} = $DATA{'nameofowner'};

$O{'surname'} = $DATA{'surnameofowner'};

$O{'zipcode'} = $DATA{'zipcode'};

$O{'country'} = $DATA{'country'};

$O{'street'} = $DATA{'street'};

$O{'phone'} = $DATA{'phone'};

$O{'email'} = $DATA{'email'};


$O{'length'} = $DATA{'length'};


dbmclose(%O);


#open (MAIL,"|$sendmail -t") || print "Can't start mail program";
#print MAIL "To: nicks\@$title (Ulyaoth Chat Admin)\n";
#print MAIL "From: webmaster\@$title (Ulyaoth Chat Admin)\n";
#print MAIL "Subject: New Account Application Received!\n\n";
#print MAIL "This is a notice that a new membership application has been received.\n";
#print MAIL "Nick: $DATA{'opsnickname'}\n";
#print MAIL "Password: $DATA{'password'}\n";
#print MAIL "Length: $DATA{'length'}\n";
#print MAIL "Email: $DATA{'email'}\n";
#print MAIL "Activation Code: $ref\n";
#print MAIl "Length: $DATA{'length'} motnh(s)\n";
#print MAIL "Name: $DATA{'nameofowner'} $DATA{'surnameofowner'}\n";
#print MAIL "Street: $DATA{'street'}\n";
#print MAIL "Country: $DATA{'country'}\n";
#print MAIL "Phone: $DATA{'phone'}\n";
#print MAIL "Sincerely!\n";
#print MAIL "Ulyaoth Chat!\n";
#print MAIL "Ulyaoth Chat! Admin\n http:\/\/$title\n";
#close (MAIL);


    open(MAIL,"|$sendmail -t");

    print MAIL "To: $DATA{'email'}\n";
    print MAIL "From: webmaster\@$title (chat admin)\n";
    print MAIL "Subject: $title membership!\n";
    print MAIL "This is a notice that your new membership application has been received.\n\n";
    print MAIL "-" x 75 . "\n";
    print MAIL "Nick: $DATA{'opsnickname'}\n";
    print MAIL "Password: $DATA{'password'}\n";
    print MAIL "Email: $DATA{'email'}\n";
    print MAIL "Activation Code: $ref\n";
    print MAIl "Length: $DATA{'length'} motnh(s)\n";
    print MAIL "-" x 75 . "\n\n";
    print MAIL "Chat Admin\n http:\/\/$title\n";
    close(MAIL);


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




print "Content-type: text/html\n\n";

print "<HEAD><title>$title Chat Ops Application!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='Ulyaoth Chat Trial Operator Application'\">\n";

print "<b><center>Ulyaoth Chat Trial Membership</b><p>\n";

print "<b>THANK YOU!</b><p>\n";

if($DATA{'length'} == 1){

print "Your application code is: <font color=\"red\"><b>$ref</b></font>. You will have to get one of admins to activate your account. Please do NOT forget this code.</center>\n";

}else{

print "Your application code is: <font color=\"red\"><b>$ref</b></font>.<br>\nTOTAL: $money\n<br>Please click <a href=\"https:\/\/chat.ulyaoth.com\/staff.html\">HERE</a> to find office closest to you and send us payment.</center>\n";

}



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