#!/usr/bin/perl



if ($command eq '/callcomm' && $level < 1){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;



exit;



}







opendir(ALLMAIL,"$root/online/users/");

 @allmail = readdir(ALLMAIL);

 closedir(ALLMAIL);



foreach $s(@allmail){



if ($s ne "." && $s ne ".."){

$s =~ s/.db//;

dbmopen(%OPS,"$root/online/users/$s",0777);

if($OPS{'level'} >= $comm_rank){

$n++;

&send_mail($s);


dbmclose(%OPS);

}

dbmclose(%OPS);

}
}




sub send_mail{

my($mailops) = @_;



open(PRIVE,">>$root/online/pm/$mailops.txt");


flock(PRIVE,2);

print PRIVE "<!-- $time --> <b>*** Operator <A HREF=\"javascript:m('$DATA{'n'}')\">\*$DATA{'n'}\*</a><font size=\"1\" color=\"$iback\">i</font> is requesting help in room $room.</b><br>\n";


close(PRIVE);



}



$errors = " Help requested from <b>$n</b> Committee Operators currently online.";



return $errors;



exit;