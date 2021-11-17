#!/usr/bin/perl

print "Content-type: text/html\n";

require "/opt/ulyaoth/chat/cookies/cookie.lib";

&GetCookies('ulyaoth');

&GetCookies('realip');


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

if($Cookies{'realip'}){

$USER{'realip'} = $Cookies{'realip'};

}else{

&SetCookies('realip',$ENV{'REMOTE_ADDR'});

$USER{'realip'} = $ENV{'REMOTE_ADDR'};

}


if($ENV{'HTTP_VIA'}){

$USER{'proxy'} = "<font color=red>active</font>";

}else{


$USER{'proxy'} = "none";

}


dbmclose(%USER);


open(WRNICKS,">$root/usednicks/$DATA{'n'}.txt");

if($Cookies{'ulyaoth'} =~ /$DATA{'n'}/){

print WRNICKS "$Cookies{'ulyaoth'}";

$crap = "$Cookies{'ulyaoth'}";

}else{

if(-e "$root/ops/$DATA{'n'}.txt"){

print WRNICKS "$Cookies{'ulyaoth'}\!\#$DATA{'n'}\#";

$crap = "$Cookies{'ulyaoth'}\!\#$DATA{'n'}\#";

}else{

print WRNICKS "$Cookies{'ulyaoth'}\!$DATA{'n'}";

$crap = "$Cookies{'ulyaoth'}\!$DATA{'n'}";

}}

close(WRNICKS);


&SetCookies('ulyaoth',$crap);


print "\n";

$DATA{'id'} = $id;


require "$root/inc/print_header.inc";


require "$root/inc/print_room.inc";



if($frames eq "yes"){


print "</body>\n";


}else{


require "$root/inc/print_footer.inc";



}




return true;
