#!/usr/bin/perl

use DB_File;

$basedir = "/srv/ulyaoth/chat/public";

$root = '/opt/ulyaoth/chat';

$location = "https:\/\/chat.ulyaoth.com\/cgi-bin\/c\/bin.cgi";

$site = "https:\/\/chat.ulyaoth.com\/";


use CGI; 

my $qq = new CGI; 

my $nickname = $qq->param("n");

my $id_session = $qq->param("id");

my $room = $qq->param("room");

my $send_to = $qq->param("send_to");

my $to_file = $qq->param("FILE1"); 

$to_file =~ s!^.*(\\|\/)!!; 

$to_file =~ s/\</_/g;
$to_file =~ s/\>/_/g;
$to_file =~ s/\s+/_/g;
$to_file =~ s/\n+/_/g;
$to_file =~ s/\&/_/g;
$to_file =~ s/\!/_/g;
$to_file =~ s/\@/_/g;
$to_file =~ s/\?/_/g;
$to_file =~ s/\//_/g;
$to_file =~ s/\\/_/g;
$to_file =~ s/\#/_/g;
$to_file =~ s/\%/_/g;
$to_file =~ s/\$/_/g;
$to_file =~ s/\"/_/g;
$to_file =~ s/\'/_/g;
$to_file =~ s/\*/_/g;
$to_file =~ s/\§/_/g;
$to_file =~ s/\{/_/g;
$to_file =~ s/\}/_/g;
$to_file =~ s/\)/_/g;
$to_file =~ s/\(/_/g;
$to_file =~ s/\]/_/g;
$to_file =~ s/\[/_/g;
$to_file =~ s/\,/_/g;

if(!-e "$root/online/users/$nickname.db"){

print "Content-type: text/html\n";

print "Location:$site\n\n";

exit;

}

dbmopen(%UP,"$root/online/users/$nickname.db",0777);

if($UP{'id'} ne $id_session){

dbmclose(%UP);

print "Content-type: text/html\n";

print "Location:$site\n\n";

exit;

}

dbmclose(%UP);


&upload();



print "Content-type: text/html\n";

print "Location:$location?n=$nickname&id=$id_session&room=$room&msg=/send2+$send_to+$to_file\n\n";

exit;



sub upload{


use CGI; 

my $req = new CGI; 
my $file = $req->param("FILE1"); 

if ($file ne "") {
my $fileName = $file; 
$fileName =~ s!^.*(\\|\/)!!; 
$fileName =~ s/\</_/g;
$fileName =~ s/\>/_/g;
$fileName =~ s/\s+/_/g;
$fileName =~ s/\n+/_/g;
$fileName =~ s/\&/_/g;
$fileName =~ s/\!/_/g;
$fileName =~ s/\@/_/g;
$fileName =~ s/\?/_/g;
$fileName =~ s/\//_/g;
$fileName =~ s/\\/_/g;
$fileName =~ s/\#/_/g;
$fileName =~ s/\%/_/g;
$fileName =~ s/\$/_/g;
$fileName =~ s/\"/_/g;
$fileName =~ s/\'/_/g;
$fileName =~ s/\*/_/g;
$fileName =~ s/\§/_/g;
$fileName =~ s/\{/_/g;
$fileName =~ s/\}/_/g;
$fileName =~ s/\)/_/g;
$fileName =~ s/\(/_/g;
$fileName =~ s/\]/_/g;
$fileName =~ s/\[/_/g;
$fileName =~ s/\,/_/g;
$newmain = $fileName;


open (OUTFILE, ">$basedir/$fileName"); 
print "$basedir/$fileName<br>";
while (my $bytesread = read($file, my $buffer, 1024)) { 
print OUTFILE $buffer; 
			} 
close (OUTFILE); 

   }

}