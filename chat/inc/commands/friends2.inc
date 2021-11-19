#!/usr/bin/perl

if (!$DATA{'for'} or !$DATA{'mature'}){

$errors = " Error, you left one or more options unselected. Please click <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$DATA{'room'}&msg=\/friends\">here</a> to try again.";

return $errors;

exit;

}


if($DATA{'for'} != 1 && $DATA{'for'} != 2 && $DATA{'for'} != 3 && $DATA{'for'} != 4 && $DATA{'for'} != 5 && $DATA{'for'} != 6 && $DATA{'mature'} != 0 && $DATA{'mature'} != 1){ 


$errors = " Error, you left one or more options unselected. Please click <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$DATA{'room'}&msg=\/friends\">here</a> to try again.";

return $errors;

exit;

}


if($DATA{'for'} == 1){

$me = "female";

$looking_for = "male";

}elsif($DATA{'for'} == 2){

$me = "female";

$looking_for = "female";

}elsif($DATA{'for'} == 3){

$me = "female";

$looking_for = "any";

}elsif($DATA{'for'} == 4){

$me = "male";

$looking_for = "female";

}elsif($DATA{'for'} == 5){

$me = "male";

$looking_for = "male";

}elsif($DATA{'for'} == 2){

$me = "male";

$looking_for = "any";

}


if($DATA{'mature'} == 0){

$mature = "young";

}elsif($DATA{'mature'} == 1){

$mature = "old";

}


dbmopen(%F,"$root/online/users/$DATA{'n'}.db",0777);

$F{'friends_mature'} = $mature;

$F{'friends_for'} = $looking_for;

$F{'friends_me'} = $me;

dbmclose(%F);


print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";


opendir(DIR,"$root/online/users/");

flock(DIR,2);

@array = readdir(DIR);

closedir(DIR);

$count = 0;

foreach $e(@array){


if($e ne '.' && $e ne '..'){


$e =~ s/.db//ig;

dbmopen(%E,"$root/online/users/$e",0777);


if($me eq $E{'friends_for'} && $looking_for eq $E{'friends_me'} && $mature eq $E{'friends_mature'}){

$count++;

print "*** Chatter <b><A HREF=\"javascript:m(\'$e\')\">$e</a></b> ($E{'ip'}) is looking for new friends.<br>\n";

open(PR,">>$root/online/pm/$e.txt");

flock(PR,2);

print PR "<!-- $time --> *** Chatter <A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\*</b></a> ($ip) is looking for new friends.<br>\n";

close(PR);



			}

dbmclose(%E);

	}

}

print "TOTAL MATCHES: <b>$count</b><br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;